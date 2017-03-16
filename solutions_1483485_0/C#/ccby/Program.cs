using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace ProblemA
{
	class Program
	{
		static void Main(string[] args)
		{
			string file = "A-small-attempt3";
			StreamReader sr = new StreamReader(new FileStream(file + ".in", FileMode.Open, FileAccess.Read));
			StreamWriter sw = new StreamWriter(new FileStream(file + ".out", FileMode.OpenOrCreate, FileAccess.Write));


			//get mapping table
			var table = new Dictionary<char, char>();
			string example1 = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
			string solution1 = "our language is impossible to understand";
			string example2 = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
			string solution2 = "there are twenty six factorial possibilities";
			string example3 = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
			string solution3 = "so it is okay if you want to just give up";
			Addmapping(table, example1, solution1);
			Addmapping(table, example2, solution2);
			Addmapping(table, example3, solution3);
			table.Add('z','q');
			table.Add('q','z');
			//solve problem
			int maxCase = Convert.ToInt32(sr.ReadLine());
			for( int i = 0; i < maxCase; i++) {
				//string original = sr.ReadLine();
				//string translated = GetMappedString(original);
				string str = sr.ReadLine();
				
				StringBuilder s = new StringBuilder();
				foreach( var c in str.ToCharArray() ) {
					s.Append( table[c].ToString());
				}



				Console.WriteLine("Case #{0}: {1}", i + 1, s.ToString());
				sw.WriteLine("Case #{0}: {1}", i + 1, s.ToString());
			}



			//close
			sr.Close();
			sw.Close();

		}

		//private static string GetMappedString(string original)
		//{
		//    for( int )
		//}

		private static void Addmapping(Dictionary<char, char> table, string example1, string solution1)
		{
			var eCharList = example1.ToCharArray();
			var sCharList = solution1.ToCharArray();

			for( int i = 0; i < eCharList.Length; i++) {
				if( table.ContainsKey(eCharList[i])) {
					continue;
				}else {
					table.Add(eCharList[i],sCharList[i]);
				}


			}
		}

	}
}
