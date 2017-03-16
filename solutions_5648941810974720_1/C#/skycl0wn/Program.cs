using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace JamOne
{
    class DigitParseInfo
    {
        char Marker { get; set; }

        string Name { get; set; }

        char Value { get; set; }

        public DigitParseInfo(char marker, string name, char value)
        {
            Marker = marker;
            Name = name;
            Value = value;
        }
    }

    struct TestCaseInput
    {
        public string Data { get; }

        public TestCaseInput(string s)
        {
            Data = s;

            Parse();
        }

        private void Parse()
        {
        }
    }

    class Program
    {
        public static void WriteOutput(string fileName, List<TestCaseInput> testCases)
        {
            List<string> output = new List<string>();

            int i = 1;
            foreach (var testCaseInput in testCases)
            {
                StringBuilder line = new StringBuilder();
                line.Append($"Case #{i}: ");

                StringBuilder value = new StringBuilder();

                int[] nums = new int[10];
                nums[0] = testCaseInput.Data.Count(c => c == 'Z');
                nums[2] = testCaseInput.Data.Count(c => c == 'W');
                nums[4] = testCaseInput.Data.Count(c => c == 'U');
                nums[6] = testCaseInput.Data.Count(c => c == 'X');
                nums[8] = testCaseInput.Data.Count(c => c == 'G');

                nums[1] = testCaseInput.Data.Count(c => c == 'O') - nums[0] - nums[2] - nums[4];
                nums[3] = testCaseInput.Data.Count(c => c == 'T') - nums[2] - nums[8];
                nums[5] = testCaseInput.Data.Count(c => c == 'F') - nums[4];
                nums[7] = testCaseInput.Data.Count(c => c == 'V') - nums[5];
                nums[9] = testCaseInput.Data.Count(c => c == 'I') - nums[8] - nums[6] - nums[5];

                for (int n=0; n < nums.Length; n++)
                {
                    value.Append(n.ToString()[0], nums[n]);
                }

                line.Append(value);    

                i++;
                output.Add(line.ToString());
            }

            File.WriteAllLines(fileName, output);
        }

        public static List<TestCaseInput> ReadInput(string fileName)
        {
            var inputLines = File.ReadAllLines(fileName).Skip(1);

            List<TestCaseInput> testCaseInputs = new List<TestCaseInput>();

            foreach (var line in inputLines)
                testCaseInputs.Add(new TestCaseInput(line));

            return testCaseInputs;
        }

        static void Main(string[] args)
        {
            var testCases = ReadInput(args[0]);
            WriteOutput(args[1], testCases);
        }
    }
}
