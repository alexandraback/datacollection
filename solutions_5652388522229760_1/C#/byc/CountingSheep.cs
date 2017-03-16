using System.Collections.Generic;
using System.IO;

namespace CJ2016QualRound {
	internal class CountingSheep {
		private readonly int _numTests;
		private readonly List<long> _testCases = new List<long>();

		public CountingSheep(TextReader reader) {
			_numTests = int.Parse(reader.ReadLine());
			for (int i = 0; i < _numTests; i++) {
				_testCases.Add(long.Parse(reader.ReadLine()));
			}
		}

		public void Solve(TextWriter writer) {
			for (int i = 0; i < _numTests; i++) {
				long val = _testCases[i];
				string answer = null;

				if (val > 0) {
					HashSet<char> unseenDigits = new HashSet<char>("0123456789");
					for (int j = 1; j < 10000; j++) {
						long nextVal = val * j;

						foreach (char c in nextVal.ToString()) {
							unseenDigits.Remove(c);
						}

						if (unseenDigits.Count == 0) {
							answer = nextVal.ToString();
							break;
						}
					}
				}
				writer.WriteLine($"Case #{i + 1}: {answer ?? "INSOMNIA"}");
			}
		}
	}
}