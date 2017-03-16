using System;
using System.Collections.Generic;
using System.Linq;
using System.IO;

namespace GCJ {
	
	class MainClass {
		
		public static void Main (string[] args) {
			Dictionary<char,char> dict = new Dictionary<char, char>();
			List<char> ca = new List<char>();
			List<char> cb = new List<char>();
			for(int i = 0; i < 26; i++) {
				ca.Add((char) ('a'+i));
				cb.Add((char) ('a'+i));
			}
			string s = null, t;
			do {
				s = Console.ReadLine();
				if(s != null) {
					t = Console.ReadLine();
					for(int i = 0; i < s.Length; i++) {
						char c = s[i];
						if(!dict.ContainsKey(c)) {
							char d = t[i];
							dict.Add(c,d);
							ca.Remove(c);
							cb.Remove(d);
						}
					}
					Console.WriteLine("database grew to: {0}",dict.Count);
				}
			} while(s != null);
			Console.WriteLine(ca[0]);
			Console.WriteLine(cb[0]);
			for(int i = 0; i < ca.Count; i++) {
				dict.Add(ca[i],cb[i]);
			}
			Stream st = File.Open("in.in",FileMode.Open);
			Stream so = File.Open("out.out",FileMode.Create);
			StreamReader sr = new StreamReader(st);
			StreamWriter sw = new StreamWriter(so);
			int T = int.Parse(sr.ReadLine());
			for(int tt = 1; tt <= T; tt++) {
				string ins = sr.ReadLine();
				string res = new string(ins.Select(x => dict[x]).ToArray());
				sw.WriteLine("Case #{0}: {1}",tt,res);
			}
			sr.Close();
			sw.Close();
			st.Close();
			so.Close();
		}
	}
	
}