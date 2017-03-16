using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;

namespace CJ2016QualRound {
	public class Fractiles {
		public static void Main(string[] args) {
			new Fractiles().Solve(Console.In, Console.Out);
		}

		public void Solve(TextReader reader, TextWriter writer) {

			int numTests = int.Parse(reader.ReadLine());
			for (int i = 0; i < numTests; i++) {
				string[] line = reader.ReadLine().Split();
				int seqLen = int.Parse(line[0]);
				int depth = int.Parse(line[1]);
				int checksAvailable = int.Parse(line[2]);

				List<BigInteger> checksRequired = new List<BigInteger>();
				for (int cellChecked = 0; cellChecked < seqLen;) {
					BigInteger finalPos = 0;
					for (int j = 0; j < depth; j++) {
						finalPos *= seqLen;
						finalPos += cellChecked % seqLen;
						cellChecked += 1;
					}
					checksRequired.Add(finalPos + 1);
				}

				string answer = null;
				if (checksRequired.Count <= checksAvailable) {
					answer = string.Join(" ", checksRequired);
				}
				
				writer.WriteLine($"Case #{i + 1}: {answer ?? "IMPOSSIBLE"}");
			}
		}
	}
}