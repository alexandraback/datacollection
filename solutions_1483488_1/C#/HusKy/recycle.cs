using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Collections;

namespace ConsoleApplication1 {
	class Program {
		static void Main(string[] args) {
			String line;
			List<int> tempList = new List<int>(); // ochrana proti duplikatom
			int lines, f, l, count = 0;

			line = Console.ReadLine();
			lines = Int32.Parse(line);

			for (int i = 0; i < lines; i++) {
				line = Console.ReadLine();

				f = Int32.Parse(line.Split(' ')[0]);
				l = Int32.Parse(line.Split(' ')[1]);

				if (l > 10) {
					for (int j = f; j <= l; j++) {
						string temp = j.ToString();

						// generuj recyklaty
						for (int k = 1; k < temp.Length; k++) {
							int num = Int32.Parse(temp.Substring(k) + temp.Substring(0, k));

							if (num > j && num <= l && !tempList.Contains(num)) {
								count++;
								tempList.Add(num);
							}
						}
						tempList.Clear(); // neefiktivne asi, ale co uz
					}

					Console.WriteLine("Case #{0}: {1}", i + 1, count);
					count = 0;
				} else {
					Console.WriteLine("Case #{0}: 0", i + 1);
				}
			}
		}
	}
}
