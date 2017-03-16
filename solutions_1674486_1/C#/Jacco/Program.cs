using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Diagnostics;

namespace ProblemA
{
	class Program
	{
		static string Solve(List<ClassObject> classes)
		{
			return "Test";
		}

		public class MyClass
		{
			public int ID;
			public List<int> Descendants;

		}

		public class ClassObject
		{
			public int ID;
			public List<int> InheritsFrom;
		}

		public static bool RecAdd(HashSet<string> already, MyClass top, List<MyClass> diagram)
		{
			if (!already.Add(top.ID.ToString()))
			{
				return true;
			}
			foreach(var desc in top.Descendants)
				if (RecAdd(already, diagram[desc-1], diagram))
					return true;
			return false;
		}

		static void Main(string[] args)
		{
			var result = new List<string>();
			var lines = File.ReadAllLines("A-small.in").ToList();
			var T = int.Parse(lines[0]);
			lines.RemoveAt(0);
			for(int c=1; c<=T; c++)
			{
				var N = int.Parse(lines[0]);
				lines.RemoveAt(0);
				var classes = new List<ClassObject>();
				var myclasses = new List<MyClass>();
				var tops = new List<MyClass>();
				for(int i=1; i<=N; i++)
				{
					myclasses.Add(new MyClass { ID = i, Descendants = new List<int>() });
				}
				for(int i=1; i<=N; i++)
				{
					var nums = lines[0].Split(' ').Select(int.Parse).ToList();
					lines.RemoveAt(0);

					var M = nums[0];
					nums.RemoveAt(0);

					var classobj = new ClassObject { ID = i, InheritsFrom = nums };
					foreach(var from in classobj.InheritsFrom)
					{
						myclasses[from-1].Descendants.Add(i);
					}
					classes.Add(classobj);		
					
					if (nums.Count == 0)
						tops.Add(myclasses[i-1]);
				}

				bool res = false;
				foreach(var top in tops)
				{
					var already = new HashSet<string>();
					res = RecAdd(already, top, myclasses);
					if (res)
						break;
				}
				result.Add("Case #" + c.ToString() + ": " + (res ? "Yes" : "No"));
			}
			File.WriteAllLines("A-small.out", result);
			Debug.WriteLine("");
		}
	}
}
