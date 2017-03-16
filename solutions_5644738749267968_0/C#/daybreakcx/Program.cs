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
					for (int ti = 1; ti <= tn; ++ti) {
						sw.Write("Case #" + ti.ToString() + ": ");
						int n = int.Parse(sr.ReadLine().Trim());
						List<string> naomi = sr.ReadLine().Trim().Split(' ').ToList();
						naomi.Sort();
						List<string> ken = sr.ReadLine().Trim().Split(' ').ToList();
						ken.Sort();
						List<string> tmp = new List<string>(ken);
						int res = 0;
						for (int nf = 0, nt = n - 1, kt = n - 1; nf <= nt; ) {
							if (naomi[nt].CompareTo(tmp[kt]) <= 0) {
								++nf;
								--kt;
							} else {
								++res;
								--nt;
								--kt;
							}
						}
						sw.Write(res.ToString() + " ");
						tmp = new List<string>(ken);
						res = 0;
						for (int i = 0; i < n; ++i) {
							int j;
							for (j = 0; j < tmp.Count(); ++j)
								if (naomi[i].CompareTo(tmp[j]) <= 0)
									break;
							if (j == tmp.Count()) {
								++res;
								ken.RemoveAt(0);
								continue;
							}
							tmp.RemoveAt(j);
						}
						sw.WriteLine(res.ToString());
					}
					sr.Close();
				}
				sw.Close();
			}
		}
	}
}
