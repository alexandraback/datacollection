using System;
using System.Collections;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;

namespace GoogleCodeJam
{
	internal class Template
	{
		private static readonly Scanner cin = new Scanner();
		private const string fileName = "D-small-attempt2";

		private static void Main()
		{
			Console.SetIn(new StreamReader(string.Format(@"C:\GoogleCodeJam\{0}.in", fileName)));
			Console.SetOut(new StreamWriter(string.Format(@"C:\GoogleCodeJam\{0}.out", fileName)) { AutoFlush = true });
			var t = cin.NextInt();
			for (var c = 1; c <= t; c++)
			{
				Console.Write("Case #{0}: ", c);
				Debug.WriteLine(c);
				Solve();
			}
		}

		private static Chest[] chests;

		private static void Solve()
		{
			var k = cin.NextInt();
			var n = cin.NextInt();
			var keys = new int[k];
			for (var i = 0; i < k; i++)
			{
				keys[i] = cin.NextInt();
			}
			chests = new Chest[n];
			for (var i = 0; i < n; i++)
			{
				chests[i] = new Chest {Key = cin.NextInt()};
				var kn = cin.NextInt();
				for (var j = 0; j < kn; j++)
				{
					chests[i].Treasure.Add(cin.NextInt());
				}
			}

			var totalKeys = new int[210];
			foreach (var chest in chests)
			{
				foreach (var key in chest.Treasure)
				{
					totalKeys[key]++;
				}
				totalKeys[chest.Key]--;
			}
			foreach (var key in keys)
			{
				totalKeys[key]++;
			}

			if (totalKeys.Any(x => x < 0))
			{
				Console.WriteLine("IMPOSSIBLE");
				return;
			}

			var sw = Stopwatch.StartNew();

			var startState = new State();
			foreach (var key in keys)
			{
				startState.Keys[key]++;
			}
			startState.ChestsUnlocked = new bool[chests.Count()];
			var visited = new List<State> {startState};
			var stack = new Stack<State>();
			stack.Push(startState);
			while (stack.Any())
			{
				var top = stack.Pop();
				if (top.ChestsUnlocked.All(x => x))
				{
					for (var i = 0; i < top.UnlockOrder.Count; i++)
					{
						if (i > 0)
						{
							Console.Write(' ');
						}
						Console.Write(top.UnlockOrder[i]);
					}
					Console.WriteLine("");
					return;
				}
				if (sw.Elapsed > TimeSpan.FromSeconds(30))
				{
					goto Timeout;
				}
				for (var i = top.ChestsUnlocked.Length - 1; i >= 0; i--)
				{
					var removeKey = chests[i].Key;
					if (top.ChestsUnlocked[i] == false && top.Keys[removeKey] > 0)
					{
						var countKey = top.Keys[removeKey];
						countKey += chests[i].Treasure.Count(x => x == removeKey);
						if (countKey == 1)
						{
							var countRequiredAtleast = 0;
							for (var j = 0; j < top.ChestsUnlocked.Length; j++)
							{
								if (top.ChestsUnlocked[j] == false && i != j)
								{
									if (chests[j].Key == removeKey)
									{
										countRequiredAtleast++;
									}
									foreach (var tr in chests[j].Treasure)
									{
										if (tr == removeKey)
										{
											countRequiredAtleast--;
										}
									}
								}
							}
							if (countRequiredAtleast > 0)
							{
								continue;
							}
						}

						var state = new State();
						for (var j = 0; j < state.Keys.Length; j++)
						{
							state.Keys[j] = top.Keys[j];
						}
						state.Keys[chests[i].Key]--;
						for (var j = 0; j < chests[i].Treasure.Count; j++)
						{
							state.Keys[chests[i].Treasure[j]]++;
						}

						state.ChestsUnlocked = new bool[chests.Count()];
						for (var j = 0; j < state.ChestsUnlocked.Length; j++)
						{
							state.ChestsUnlocked[j] = top.ChestsUnlocked[j];
						}
						state.ChestsUnlocked[i] = true;

						//Debug.WriteLine("{0} {1}", stack.Count, visited.Count);
						if (!visited.Any(x => x.AreEqual(state)))
						{
							state.UnlockOrder = top.UnlockOrder.ToList();
							state.UnlockOrder.Add(i + 1);
							visited.Add(state);
							stack.Push(state);
						}
					}
				}
			}
			Console.WriteLine("IMPOSSIBLE");
			return;

			Timeout:
			Debug.WriteLine("Timeout");

			totalKeys = new int[210];
			foreach (var chest in chests)
			{
				foreach (var key in chest.Treasure)
				{
					totalKeys[key]++;
				}
				totalKeys[chest.Key]--;
			}
			foreach (var key in keys)
			{
				totalKeys[key]++;
			}

			if (totalKeys.Any(x => x < 0))
			{
				Console.WriteLine("IMPOSSIBLE");
				return;
			}

			startState = new State();
			foreach (var key in keys)
			{
				startState.Keys[key]++;
			}
			startState.ChestsUnlocked = new bool[chests.Count()];
			visited = new List<State> { startState };
			stack = new Stack<State>();
			stack.Push(startState);
			while (stack.Any())
			{
				var top = stack.Pop();
				if (top.ChestsUnlocked.All(x => x))
				{
					for (var i = 0; i < top.UnlockOrder.Count; i++)
					{
						if (i > 0)
						{
							Console.Write(' ');
						}
						Console.Write(top.UnlockOrder[i]);
					}
					Console.WriteLine("");
					return;
				}
				for (var i = top.ChestsUnlocked.Length - 1; i >= 0; i--)
				{
					var removeKey = chests[i].Key;
					if (top.ChestsUnlocked[i] == false && top.Keys[removeKey] > 0)
					{
						var countKey = top.Keys[removeKey];
						countKey += chests[i].Treasure.Count(x => x == removeKey);
						if (countKey == 1)
						{
							var countRequiredAtleast = 0;
							for (var j = 0; j < top.ChestsUnlocked.Length; j++)
							{
								if (top.ChestsUnlocked[j] == false && i != j)
								{
									if (chests[j].Key == removeKey)
									{
										countRequiredAtleast++;
									}
								}
							}
							if (countRequiredAtleast > 0)
							{
								continue;
							}
						}

						var state = new State();
						for (var j = 0; j < state.Keys.Length; j++)
						{
							state.Keys[j] = top.Keys[j];
						}
						state.Keys[chests[i].Key]--;
						for (var j = 0; j < chests[i].Treasure.Count; j++)
						{
							state.Keys[chests[i].Treasure[j]]++;
						}

						state.ChestsUnlocked = new bool[chests.Count()];
						for (var j = 0; j < state.ChestsUnlocked.Length; j++)
						{
							state.ChestsUnlocked[j] = top.ChestsUnlocked[j];
						}
						state.ChestsUnlocked[i] = true;

						//Debug.WriteLine("{0} {1}", stack.Count, visited.Count);
						if (!visited.Any(x => x.AreEqual(state)))
						{
							state.UnlockOrder = top.UnlockOrder.ToList();
							state.UnlockOrder.Add(i + 1);
							visited.Add(state);
							stack.Push(state);
						}
					}
				}
			}
			Console.WriteLine("IMPOSSIBLE");
		}
	}

	public class State
	{
		public int[] Keys = new int[210];
		public bool[] ChestsUnlocked;
		public List<int> UnlockOrder = new List<int>();

		public bool AreEqual(State another)
		{
			/*for (var i = 0; i < Keys.Length; i++)
			{
				if (Keys[i] != another.Keys[i])
				{
					return false;
				}
			}*/
			for (var i = 0; i < ChestsUnlocked.Length; i++)
			{
				if (ChestsUnlocked[i] != another.ChestsUnlocked[i])
				{
					return false;
				}
			}
			return true;
		}
	}

	public class Chest
	{
		public int Key { get; set; }
		public List<int> Treasure = new List<int>();
	}

	internal class Scanner
	{
		private string[] s = new string[0];
		private int i;
		private readonly char[] cs = new[] { ' ' };

		public string Next()
		{
			if (i < s.Length) return s[i++];
			var line = Console.ReadLine() ?? string.Empty;
			s = line.Split(cs, StringSplitOptions.RemoveEmptyEntries);
			i = 1;
			return s.First();
		}

		public double NextDouble()
		{
			return double.Parse(Next());
		}

		public int NextInt()
		{
			return int.Parse(Next());
		}

		public long NextLong()
		{
			return long.Parse(Next());
		}
	}
}