using System;
using System.CodeDom;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam {
	class A : CodeJamProblem {
		protected override string InputFile { get; } = "A-large.in";
		protected override string OutputFile { get; } = "A-large.out";

		private A(Func<TestCase, string> solverFunc):base(solverFunc) {
			
		}

		static void Main(string[] args) {
			CodeJamProblem a = new A(testCase => {
				long n = long.Parse(testCase.Input[0]);

				if(n != 0) {
					char[] digitsNotSeen = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
					long i = 1;

					string num = string.Empty;
					while(digitsNotSeen.Length > 0) {
						num = (i++*n).ToString();
						char[] digits = num.ToCharArray();
						digitsNotSeen = digitsNotSeen.Where((digit) => !digits.Contains(digit)).ToArray();
					}

					return num;
				}

				return "INSOMNIA";
			});
		}
	}
}
