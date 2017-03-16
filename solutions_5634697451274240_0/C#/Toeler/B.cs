using System;
using System.CodeDom;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Text.RegularExpressions;
using System.Threading.Tasks;

namespace CodeJam {
	class B : CodeJamProblem {
		protected override string InputFile { get; } = "B-small-attempt0.in";
		protected override string OutputFile { get; } = "B-small-attempt0.out";

		private B(Func<TestCase, IDictionary<object, object>,  string> solverFunc) : base(solverFunc) {

		}

		static void Main(string[] args) {
			CodeJamProblem a = new B((testCase, cache) => {
				Regex r = new Regex("(.)(?<=\\1\\1)", RegexOptions.IgnoreCase | RegexOptions.CultureInvariant | RegexOptions.Compiled);
				string filtered = r.Replace(testCase.Input, string.Empty);

				if(filtered.Last() == '+') {
					return (filtered.Length - 1).ToString();
				}
				return filtered.Length.ToString();
			});
		}
	}
}
