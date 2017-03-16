using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam {
	public class TestCase {
		public string[] Input;

		public string Output;
		public int CaseNumber;

		public TestCase(int caseNumber, string line) {
			if(line == null) {
				throw new Exception("Input cannot be null");
			}
			Input = line.Split(' ');
			CaseNumber = caseNumber;
		}
	}

	public abstract class CodeJamProblem {
		protected abstract string InputFile { get; }
		protected abstract string OutputFile { get; }

		protected CodeJamProblem(Func<TestCase, string> solverFunc) {
			IEnumerable<TestCase> testCases = GetTestCases();

			foreach(TestCase testCase in testCases) {
				testCase.Output = solverFunc(testCase);
			}

			OutputTestCases(testCases);
		}

		private IEnumerable<TestCase> GetTestCases() {
			IList<TestCase> testCases;
			using(var file = File.OpenText("../../" + InputFile)) {
				int testCaseCount;
				if(!int.TryParse(file.ReadLine(), out testCaseCount)) {
					throw new Exception("Could not load input file");
				}

				testCases = new List<TestCase>(testCaseCount);

				for(int i = 1; i <= testCaseCount; i++) {
					string line = file.ReadLine();
					testCases.Add(new TestCase(i, line));
				}
			}
			return testCases;
		}

		private void OutputTestCases(IEnumerable<TestCase> testCases) {
			using(StreamWriter writer = new StreamWriter("../../" + OutputFile)) {
				foreach(TestCase testCase in testCases) {
					string text = string.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", testCase.CaseNumber, testCase.Output);
					writer.WriteLine(text);
					Console.WriteLine(text);
				}
			}
		}
	}
}
