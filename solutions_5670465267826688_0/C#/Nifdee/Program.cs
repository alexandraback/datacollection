using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Dijkstra {
	class Program {
		static void Main(string[] args) {
			var input = System.IO.File.ReadAllLines("input.txt");

			System.IO.File.WriteAllLines("output.txt", testInputs(input));
		}

		private static IEnumerable<string> testInputs(string[] testCases) {
			for (int i = 1; i < testCases.Length; i += 2) {
				yield return string.Format("Case #{0}: {1}", (i+1)/2, testInput(testCases[i], testCases[i+1]) ? "YES" : "NO");
			}
		}

		private static bool testInput(string testCaseSize, string testCaseLetters) {
			var testSize = testCaseSize.Split(' ');
			int repetitions = int.Parse(testSize[1]);

			var chars = getCompleteString(testCaseLetters, repetitions);
			int stage = 1;
			var currentProduct = new Quaternion(true, Quaternion.QSymbol.One);
			foreach (var symbol in chars.Select(c => wrap(c))) {
				currentProduct = new Quaternion(currentProduct, symbol);
				if (wantedSymbol(currentProduct, stage)) {
					if (stage < 4) {
						stage++;
						currentProduct = new Quaternion(true, Quaternion.QSymbol.One);
					}
				}
			}

			if (stage == 4 && wantedSymbol(currentProduct, 4)) {
				return true;
			} else {
				return false;
			}
		}

		private static bool wantedSymbol(Quaternion current, int stage) {
			if (stage > 4) {
				throw new ArgumentException("There are only four stages!");
			}
			if (stage == 4) {
				return current.Positive && current.Symbol == Quaternion.QSymbol.One;
			} else {
				return current.Positive && (int) current.Symbol == stage;
			}
		}

		private static Quaternion.QSymbol wrap(char c) {
			if (c == 'i') {
				return Quaternion.QSymbol.I;
			} else if (c == 'j') {
				return Quaternion.QSymbol.J;
			} else if (c == 'k') {
				return Quaternion.QSymbol.K;
			}
			throw new NotImplementedException("This won't happen");
		}

		private static IEnumerable<char> getCompleteString(string letters, int repetitions) {
			return Enumerable.Repeat(letters, repetitions).SelectMany(part => part.ToCharArray());
		}		

		private struct Quaternion {
			public enum QSymbol {
				One,
				I,
				J,
				K
			}

			public readonly bool Positive;
			public readonly QSymbol Symbol;

			public Quaternion(bool positive, QSymbol symbol) {
				this.Positive = positive;
				this.Symbol = symbol;
			}

			public Quaternion(Quaternion left, QSymbol right) {
				var product = multiply(left.Symbol, right);
				this.Positive = left.Positive == product.Positive;
				this.Symbol = product.Symbol;
			}

			private static Quaternion multiply(QSymbol left, QSymbol right) {
				if (left == QSymbol.One) {
					return new Quaternion(true, right);
				} else if (right == QSymbol.One) {
					return new Quaternion(true, left);
				} else if (left == right) {
					return new Quaternion(false, QSymbol.One);
				} else if (left == QSymbol.I) {
					if (right == QSymbol.J) {
						return new Quaternion(true, QSymbol.K);
					} else if (right == QSymbol.K) {
						return new Quaternion(false, QSymbol.J);
					}
				} else if (left == QSymbol.J) {
					if (right == QSymbol.I) {
						return new Quaternion(false, QSymbol.K);
					} else if (right == QSymbol.K) {
						return new Quaternion(true, QSymbol.I);
					}
				} else if (left == QSymbol.K) {
					if (right == QSymbol.I) {
						return new Quaternion(true, QSymbol.J);
					} else if (right == QSymbol.J) {
						return new Quaternion(false, QSymbol.I);
					}
				}
				throw new NotImplementedException("This should not happen!");
			}
		}
	}
}
