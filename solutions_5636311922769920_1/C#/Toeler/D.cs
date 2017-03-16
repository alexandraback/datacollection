using System;
using System.Collections;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Runtime;
using System.Runtime.CompilerServices;

namespace CodeJam {
	class D : CodeJamProblem {
		protected override string InputFile { get; } = "D-large.in";
		protected override string OutputFile { get; } = "D-large.out";

		private D(Func<TestCase, IDictionary<object, object>, string> solverFunc) : base(solverFunc) {
		}

		static void Main(string[] args) {
			CodeJamProblem d = new D((testCase, cache) => {
				var input = testCase.Input.Split(' ');
				var k = int.Parse(input[0]);
				var c = int.Parse(input[1]);
				var s = int.Parse(input[2]);

				if(s == k) {
					return string.Join(" ", Enumerable.Range(0, s).Select(n => n + 1));
				}

				if(s == k - 1 && c > 1) {
					return string.Join(" ", Enumerable.Range(0, s).Select(n => n + 2));
				}

				return "IMPOSSIBLE";
			});
		}
	}
}
