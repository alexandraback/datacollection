using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GCJ2014 {
	class Program {
		public static List<KeyValuePair<int, int>> dir = new List<KeyValuePair<int, int>>() {
			new KeyValuePair<int, int>(-1, -1),
			new KeyValuePair<int, int>(-1, 0),
			new KeyValuePair<int, int>(-1, 1),
			new KeyValuePair<int, int>(0, -1),
			new KeyValuePair<int, int>(0, 1),
			new KeyValuePair<int, int>(1, -1),
			new KeyValuePair<int, int>(1, 0),
			new KeyValuePair<int, int>(1, 1)
		};
		public static List<List<char>> board = new List<List<char>>();
		public static bool Calculate(int r, int c, int left) {
			if (left == 0)
				return true;
			List<KeyValuePair<KeyValuePair<int, int>, int>> todo = new List<KeyValuePair<KeyValuePair<int, int>, int>>();
			for (int i = 0; i < r; ++i)
				for (int j = 0; j < c; ++j)
					if (board[i][j] != '*') {
						int cnt = dir.Count(x => i + x.Key >= 0 && i + x.Key < r && j + x.Value >= 0 && j + x.Value < c && board[i + x.Key][j + x.Value] == '*');
						todo.Add(new KeyValuePair<KeyValuePair<int, int>, int>(new KeyValuePair<int, int>(i, j), cnt));
						board[i][j] = (char)((int)'0' + cnt);
					}
			todo.Sort((x, y) => -x.Value.CompareTo(y.Value));
			List<List<char>> tmp = new List<List<char>>();
			foreach (var row in board) {
				List<char> new_row = new List<char>();
				foreach (var cell in row)
					new_row.Add(cell.ToString()[0]);
				tmp.Add(new_row);
			}
			foreach (var change in todo)
				if (change.Value > 0 && change.Value <= left) {
					board.Clear();
					foreach (var row in tmp) {
						List<char> new_row = new List<char>();
						foreach (var cell in row)
							new_row.Add(cell.ToString()[0]);
						board.Add(new_row);
					}
					foreach (var x in dir)
						if (change.Key.Key + x.Key >= 0 && change.Key.Key + x.Key < r && change.Key.Value + x.Value >= 0 && change.Key.Value + x.Value < c)
							board[change.Key.Key + x.Key][change.Key.Value + x.Value] = '.';
					if (Calculate(r, c, left - change.Value))
						return true;
				}
			return false;
		}
		static void Main(string[] args) {
			if (args.Count() != 2) {
				Console.Error.WriteLine("Usage: .exe input_file_name output_file_name");
				return;
			}
			using (StreamWriter sw = new StreamWriter(args[1])) {
				using (StreamReader sr = new StreamReader(args[0])) {
					int tn = int.Parse(sr.ReadLine());
					for (int ti = 1; ti <= tn; ++ti) {
						sw.WriteLine("Case #" + ti.ToString() + ":");
						var tmp = sr.ReadLine().Trim().Split(' ').Select(s => int.Parse(s)).ToArray();
						int r = tmp[0], c = tmp[1], m = tmp[2];
						for (int cur = 0, i = 0; i < r; ++i, cur += c) {
							board.Add(new List<char>());
							for (int j = 1; j <= c; ++j)
								board[i].Add('*');
						}
						board[0][0] = '.';
						if (!Calculate(r, c, r * c - m - 1))
							sw.WriteLine("Impossible");
						else {
							for (int i = 0; i < r; ++i)
								for (int j = 0; j < c; ++j)
									if (board[i][j] != '*') {
										int cnt = dir.Count(x => i + x.Key >= 0 && i + x.Key < r && j + x.Value >= 0 && j + x.Value < c && board[i + x.Key][j + x.Value] == '*');
										board[i][j] = (char)((int)'0' + cnt);
									}
							bool click = false;
							int left = r * c - m;
							foreach (var row in board) {
								foreach (var cell in row) {
									if (!click) {
										if (cell == '*')
											sw.Write('*');
										else {
											if (left == 1 || cell == '0') {
												sw.Write('c');
												click = true;
											} else
												sw.Write('.');
										}
									} else
										sw.Write(cell == '*' ? '*' : '.');
								}
								sw.WriteLine();
							}
						}
						board.Clear();
					}
					sr.Close();
				}
				sw.Close();
			}
		}
	}
}
