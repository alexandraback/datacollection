using System;
using System.Collections.Generic;
using System.IO;

namespace CJ2016QualRound {
	public class Pancakes {
		private readonly int _numTests;
		private readonly List<string> _testCases = new List<string>();

		public static void Main(string[] args) {
			new Pancakes(Console.In).Solve(Console.Out);
		}

		public Pancakes(TextReader reader) {
			_numTests = int.Parse(reader.ReadLine());
			for (int i = 0; i < _numTests; i++) {
				_testCases.Add(reader.ReadLine());
			}
		}

		public void Solve(TextWriter writer) {
			for (int i = 0; i < _numTests; i++) {
				int count = 0;
				char? prevChar = null;
				foreach (char c in _testCases[i] + "+") {
					if (prevChar != null && c != prevChar) {
						count += 1;
					}
					prevChar = c;
				};

				writer.WriteLine($"Case #{i + 1}: {count}");
			}
		}
	}
}