using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace ConsoleApplication1 {
	class Program {
		static void Main(string[] args) {
			String line;
			int lines;
			StringBuilder sb = new StringBuilder();

			Dictionary<string, string> d = new Dictionary<string, string>();
			d.Add("a", "y");
			d.Add("b", "h");
			d.Add("c", "e");
			d.Add("d", "s");
			d.Add("e", "o");
			d.Add("f", "c");
			d.Add("g", "v");
			d.Add("h", "x");
			d.Add("i", "d");
			d.Add("j", "u");
			d.Add("k", "i");
			d.Add("l", "g");
			d.Add("m", "l");
			d.Add("n", "b");
			d.Add("o", "k");
			d.Add("p", "r");
			d.Add("q", "z");
			d.Add("r", "t");
			d.Add("s", "n");
			d.Add("t", "w");
			d.Add("u", "j");
			d.Add("v", "p");
			d.Add("w", "f");
			d.Add("x", "m");
			d.Add("y", "a");
			d.Add("z", "q");
			d.Add(" ", " ");

			line = Console.ReadLine();
			lines = Int32.Parse(line);

			for (int i = 0; i < lines; i++) {
				line = Console.ReadLine();

				for (int j = 0; j < line.Length; j++) {
					sb.Append(d[line[j].ToString()]);
				}

				Console.WriteLine("Case #{0}: {1}", i + 1, sb.ToString());
				sb.Clear();
			}
		}
	}
}