using System;
using System.Collections.Generic;
using System.Text;
using System.IO;
using System.Threading;

namespace CodeJ
{
	class Task
	{
		public string				Result;
		public int					TaskId;
		int							N;
		long						total;
		long						half_total;
		List<long>					points;
		List<long>					sub_left;
		List<long>					sub_right;

		public						Task				(int taskId)
		{
			TaskId					= taskId;
			points					= new List<long>();
			sub_left				= new List<long>();
			sub_right				= new List<long>();
		}

		public void					Read				(StreamReader reader)
		{
			string line				= reader.ReadLine();
			string[] args			= line.Split();
			N						= Convert.ToInt32(args[0]);
			for (int i=0; i<N; ++i) {
				points.Add			(Convert.ToInt64(args[i+1]));
			}
		}

		bool GetSubsets				(long left, long right, List<long> points)
		{
			if (left > half_total)	return false;
			if (right > half_total)	return false;
			if (points.Count == 1) {
				if (left == right && left != 0) {
					return true;
				}
				if (left + points[0] == right) {
					sub_left.Add	(points[0]);
					return true;
				}
				if (left == right + points[0]) {
					sub_right.Add	(points[0]);
					return true;
				}
				return false;
			}
			long p					= points[0];
			List<long> pts			= new List<long>(points);
			pts.RemoveAt			(0);
			if (GetSubsets(left + p, right, pts)) {
				sub_left.Add		(points[0]);
				return true;
			}
			if (GetSubsets(left, right + p, pts)) {
				sub_right.Add		(points[0]);
				return true;
			}
			if (GetSubsets(left, right, pts)) {
				return true;
			}
			return false;
		}

		public void					Execute				()
		{
			total					= 0;
			for (int i=0; i<N; ++i) {
				total				+= points[i];
			}
			half_total				= (total / 2) + 1;
			List<long> A			= new List<long>();
			List<long> B			= new List<long>();
			Result					= "Case #" + TaskId + ":\r\n";
			if (GetSubsets(0, 0, points)) {
				sub_left.Sort		();
				sub_right.Sort		();
				for (int i=0; i<sub_left.Count; ++i) {
					Result			+= string.Format(" {0}", sub_left[i]);
				}
				Result				+= "\r\n";
				for (int i=0; i<sub_right.Count; ++i) {
					Result			+= string.Format(" {0}", sub_right[i]);
				}
			} else {
				Result				+= "\"Impossible\"";
			}
		}
	}

	class Worker
	{
		public static void			Process		(object obj)
		{
			AutoResetEvent finish	= (AutoResetEvent)obj;
			while (true) {
				Task task			= null;
				lock (Program.threading_tasks) {
					if (Program.threading_tasks.Count > 0) {
						task		= Program.threading_tasks[Program.threading_tasks.Count-1];
						Program.threading_tasks.RemoveAt(Program.threading_tasks.Count-1);
					}
				}
				if (task == null) {
					finish.Set		();
					return;
				}
				task.Execute		();
			}
		}
	}

	class Program
	{
		public static List<Task>	threading_tasks		= new List<Task>();
		const int					THREAD_COUNT		= 4;

		static void Main(string[] args)
		{
			if (args.Length == 0)	return;
			int time				= Environment.TickCount;
			FileInfo fi				= new FileInfo(args[0]);
			if (!fi.Exists)			return;
			StreamReader reader		= fi.OpenText();
			string line_count		= reader.ReadLine();
			int count				= Convert.ToInt32(line_count);
			List<Task> tasks		= new List<Task>();
			for (int i=0; i<count; ++i) {
				Task task			= new Task(i+1);
				task.Read			(reader);
				tasks.Add			(task);
			}

			if (System.Diagnostics.Debugger.IsAttached) {
				for (int i=0; i<count; ++i) {
					tasks[i].Execute();
				}
			} else {
				threading_tasks.AddRange(tasks);
				List<Thread> threads			= new List<Thread>(THREAD_COUNT);
				List<AutoResetEvent> events		= new List<AutoResetEvent>(THREAD_COUNT);
				for (int t=0; t<THREAD_COUNT; ++t) {
					Thread thread				= new Thread(new ParameterizedThreadStart(Worker.Process));
					AutoResetEvent finish		= new AutoResetEvent(false);
					threads.Add					(thread);
					events.Add					(finish);
					thread.Start				(finish);
				}

				for (int t=0; t<THREAD_COUNT; ++t) {
					events[t].WaitOne();
				}
			}

			FileInfo result_file	= new FileInfo(fi.FullName + ".result");
			FileStream stream		= result_file.Open(FileMode.Create, FileAccess.Write);
			StreamWriter writer		= new StreamWriter(stream);
			for (int i=0; i<count; ++i) {
				writer.WriteLine	(tasks[i].Result);
			}
			writer.Close			();
			int elapsed				= Environment.TickCount - time;
			int mm					= elapsed / (60*1000);
			int ss					= (elapsed - mm * 60*1000) / 1000;
			int ms					= elapsed - mm * 60*1000 - ss * 1000;
			Console.WriteLine		("{0} done in {1:00}:{2:00}:{3} ms", fi.Name, mm, ss, ms);
		}
	}
}
