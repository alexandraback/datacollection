using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace A_Safety_In_Numbers
{
    class Program
    {
        const string Problem = "A";
        const int Attempt = 3;
        const string FilenameSnippet = "large";

        static void Main(string[] args)
        {
            System.IO.FileInfo InputFile = null;
            if (args.Length == 0)
            {
                args = new string[1];
                args[0] = "practice.txt";
                args[0] = String.Format("{0}-{1}-attempt{2}.in", Problem, FilenameSnippet, Attempt);
                if (FilenameSnippet == "large")
                    args[0] = String.Format("{0}-{1}.in", Problem, FilenameSnippet);
                //args[0] = "A-small-attempt0.in";
            }

            InputFile = new FileInfo(args[0]);
            var sr = InputFile.OpenText();

            var Lines = new List<string>();
            int LineCount = 0;
            int LinesTotal = 0;
            var DataSets = new List<DataSet>();
            DataSet CurrentDataSet = new DataSet();

            while (true)
            {
                var Line = sr.ReadLine();
                if (Line == null)
                    break;
                else
                    if (LineCount > 0)
                    {
                        var Data = Line.Split(' ');
                        CurrentDataSet = new DataSet { num = int.Parse(Data[0]), j = new List<int>(int.Parse(Data[0])) };
                        foreach (var Datum in Data.Skip(1))
                        {
                            CurrentDataSet.j.Add(int.Parse(Datum));
                        }
                        CurrentDataSet.total = CurrentDataSet.j.Sum();

                        DataSets.Add(CurrentDataSet);
                    }
                    else
                        LinesTotal = int.Parse(Line);

                LineCount++;
            }
            sr.Close();
            sr = null;

            StringBuilder Output = new StringBuilder();
            for (var i = 0; i < DataSets.Count; i++)
            {
                var DataSet = DataSets[i];

                var Result = new StringBuilder();

                var Goal = (DataSet.total * 2) / DataSet.j.Count;
                var t = DataSet.j.Where(x => x < Goal);

                Goal = (DataSet.total + (double)t.Sum()) / t.Count();
                while (DataSet.j.Where(x => x < Goal).Count() > t.Count())
                {
                    t = DataSet.j.Where(x => x < Goal);
                    Goal = (DataSet.total + (double)t.Sum()) / t.Count();
                }

                foreach (var j in DataSet.j)
                {
                    /*
                    if (t.Count() > 1)
                    {
                        var spread = t.Count() - 1;
                    }
                    */

                    double Val = (double)(Goal - j) / DataSet.total * 100;

                    if (Val < 0)
                        Val = 0.0;

                    var NumAbove0 = GetNumAbove0(Val);
                    Result.Append(String.Format("{0:###0.000000}", Val)
                        .Substring(0, 8 + NumAbove0) + " ");
                }

                Output.AppendLine(String.Format(
                    "Case #{0}: {1}",
                    i + 1, Result)
                    );
            }
            System.IO.File.WriteAllText(String.Format("{0}-{1}{2}.out", Problem, FilenameSnippet, Attempt), Output.ToString());
            Console.Write(Output);
        }

        private static int GetNumAbove0(double Min)
        {
            var r = 0;
            for (var d = 10; d <= 100000; d *= 10)
            {
                var f = Math.Floor(Min / d);
                if (f != 0)
                    r++;
                else
                    break;
            }
            return r;
        }

        public class DataSet
        {
            public int num { get; set; }
            public double total { get; set; }
            public List<int> j { get; set; }
        }
    }
}
