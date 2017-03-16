using System;
using System.Collections.Generic;
using System.Text;

namespace Google_Code_Jam_2013_R1B
{
    class A
    {
        static string solve(Queue<string> input)
        {
            string[] inputs = input.Dequeue().Split(' ');

            int a = Int32.Parse(inputs[0]);
            int n = Int32.Parse(inputs[1]);

            inputs = input.Dequeue().Split(' ');

            List<int> motes = new List<int>();

            for (int i = 0; i < n; i++)
                motes.Add(Int32.Parse(inputs[i]));

            int output = 0;
            int bestOutput = -1;

            while (motes.Count > 0)
            {
                motes.Sort();

                for (int i = 0; i < motes.Count; i++)
                {
                    int mote = motes[i];

                    if (mote < a)
                    {
                        a += mote;
                        motes.RemoveAt(i);
                        --i;
                    }
                }

                if (motes.Count == 0)
                    break;

                int numAbsorbedAfterMoteAddition = 0;
                int sizeAfterMoteAddition = a + a - 1;

                for (int i = 0; i < motes.Count; i++)
                {
                    int mote = motes[i];

                    if (mote < sizeAfterMoteAddition)
                        ++numAbsorbedAfterMoteAddition;
                }

                if (numAbsorbedAfterMoteAddition == 0)
                {
                    if (bestOutput < 0 || output + motes.Count < bestOutput)
                        bestOutput = output + motes.Count;

                    if (a == 1)
                        return bestOutput.ToString();
                }
                                
                motes.Add(a - 1);
                ++output;
            }

            if (bestOutput < output && bestOutput > 0)
                return bestOutput.ToString();
            return output.ToString();
        }

        static void Main(string[] args)
        {
            string filename = "..\\..\\io\\" + "A-small-attempt1.in";
            Queue<string> input = new Queue<string>(System.IO.File.ReadAllLines(filename));

            int numCases = Int32.Parse(input.Dequeue());

            System.IO.StreamWriter sw = new System.IO.StreamWriter(filename.Replace("in", "out"), false);

            for (int i = 1; i <= numCases; i++)
            {
                sw.WriteLine("Case #{0}: {1}", i, solve(input));
            }

            sw.Close();
        }
    }
}
