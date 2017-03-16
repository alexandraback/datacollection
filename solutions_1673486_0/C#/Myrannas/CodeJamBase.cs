using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace CodeJamTools {
    public abstract class CodeJamBase : CodeJamProgram {
        protected string[] Lines;
        protected int Tests;
        protected List<string> Outputs;

        protected override void Output() {
            File.WriteAllLines("Out.txt",Outputs);
        }

        protected abstract string RunTest(int index);
        protected override void RunProgram() {
            for (var i = 0; i < Tests; i++) {
                Outputs.Add(string.Format("Case #{0}: {1}",i+1,RunTest(i)));
            }
        }

        protected override void Prepare(string[] file) {
            Lines = file.Skip(1).ToArray();
            Tests = int.Parse(file[0]);
            Outputs = new List<string>(Tests);
        }
    }
}