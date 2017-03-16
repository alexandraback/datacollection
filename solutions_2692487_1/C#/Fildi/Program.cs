using System;
using System.Collections.Generic;
using System.Globalization;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ProblemA {
    class Program {
        static void Main(string[] args) {
            using (TaskReader reader = new TaskReader(args[0])) {
                int testCount = reader.ReadInt();
                for (int i = 0; i < testCount; i++) {
                    ProblemSolver solver = new ProblemSolver(reader);
                    var result = solver.Solve();
                    Console.WriteLine(String.Format(CultureInfo.InvariantCulture, "Case #{0}: {1}", i + 1, result));
                    
                }
            }
        }
    }
    public class ProblemSolver {
        TaskReader reader;
        public ProblemSolver(TaskReader reader) {
            this.reader = reader;
        }
       
        public int Solve() {
            int a = reader.ReadInt();
            int n = reader.ReadInt();
            int[] sizes = new int[n];
            for (int i = 0; i < n; i++) {
                sizes[i] = reader.ReadInt();
            }
            Array.Sort(sizes);
            int currentSize = a;
            int totalAdded = 0;
            int minOperation = Int32.MaxValue;
            int currentIndex = 0;
            while (true) {
                while (currentIndex < n && currentSize > sizes[currentIndex]) {
                    currentSize += sizes[currentIndex];
                    currentIndex++;
                }
                int operCount = totalAdded + n - currentIndex;
                if (operCount < minOperation)
                    minOperation = operCount;
                if (currentIndex == n)
                    break;
                if (currentSize == 1)
                    break;
                currentSize += currentSize - 1;
                totalAdded++;
            }
            return minOperation;

        }
        
    }
    public class TaskReader : IDisposable {
        StreamReader reader;
        StringBuilder word;
        public TaskReader(string fileName) {
            reader = new StreamReader(fileName);
            word = new StringBuilder();
        }
        public string ReadLine() {
            return reader.ReadLine();
        }
        public Int32 ReadInt() {
            return Int32.Parse(ReadWord());
        }
        public Int64 ReadLongInt() {
            return Int64.Parse(ReadWord());
        }
        public UInt64 ReadULongInt() {
            return UInt64.Parse(ReadWord());
        }
        
        public string ReadWord() {
            word.Clear();
            while (!reader.EndOfStream) {                
                char ch = (char)reader.Read();
                if (IsSeparator(ch))
                    break;
                word.Append(ch);
            }
            while (!reader.EndOfStream && IsSeparator((char)reader.Peek()))
                reader.Read();
            return word.ToString();
        }

        bool IsSeparator(char ch) {
            return Char.IsSeparator(ch) || ch == '\n' || ch == '\r';
        }

        public void Dispose() {
            Dispose(true);
        }
        protected virtual void Dispose(bool disposing) {
            if (disposing) {
                if (reader != null) {
                    reader.Dispose();
                    reader = null;
                }
                GC.SuppressFinalize(this);
            }
        }
        ~TaskReader() {
            Dispose(false);
        }
    }
}
