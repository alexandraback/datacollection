using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014 {
	class Program {
		static void Main(string[] args) {
			if (args.Count() != 2) {
				Console.Error.WriteLine("Usage: .exe input_file_name output_file_name");
				return;
			}
			using (StreamWriter sw = new StreamWriter(args[1])) {
				using (StreamReader sr = new StreamReader(args[0])) {
					int tn = int.Parse(sr.ReadLine());
					for (int i = 1; i <= tn; ++i) {
						sw.Write("Case #" + i.ToString() + ": ");
						double[] tmp = sr.ReadLine().Trim().Split(' ').Select(s => double.Parse(s)).ToArray();
						double c = tmp[0], f = tmp[1], x = tmp[2];
						double speed = 2.0, res = 0;
						while (true) {
							if (x / speed <= c / speed + x / (speed + f)) {
								res += x / speed;
								break;
							} else {
								res += c / speed;
								speed += f;
							}
						}
						sw.WriteLine("{0:F7}", res);
					}
					sr.Close();
				}
				sw.Close();
			}
		}
	}
}
