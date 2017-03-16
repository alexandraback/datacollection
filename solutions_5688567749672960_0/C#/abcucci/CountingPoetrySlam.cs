using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Round1B
{
    public class CountingPoetrySlam
    {
        public string Run(string input)
        {
            string[] lines = input.Split(new char[] { '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries);

            string output = "";

            int T = int.Parse(lines[0]);
            this.init();
            for (int i = 1; i <= T; ++i)
            {
                string value1 = lines[i];

                long answer = this.solve(long.Parse(value1));

                output += string.Format("Case #{0}: {1}", i, answer);
                output += Environment.NewLine;
            }

            return output;
        }

        long[] swapNumbers = new long[1000001];

        private void init()
        {
            for (long i = 0; i < swapNumbers.Length; ++i)
            {
                this.swapNumbers[i] = this.swap(i);
            }
            return;
        }

        private long solve(long N)
        {
            bool[] used = new bool[1000001];

            List<long> numbers = new List<long>();
            numbers.Add(0);
            used[0] = true;
            //
            for (long answer = 0; answer <= N; ++answer)
            {
                int z = numbers.Count;
                for (int i = 0; i < z; ++i)
                {
                    long number = numbers[i];
                    if (number == N)
                    {
                        return answer;
                    }

                    long n1 = number + 1;
                    if (used[n1] == false)
                    {
                        numbers.Add(n1);
                        used[n1] = true;
                    }

                    long n2 = this.swapNumbers[number];
                    if ((used[n2] == false) && (n2 > number) && (n2 <= N))
                    {
                        numbers.Add(n2);
                        used[n2] = true;
                    }
                }
                numbers.RemoveRange(0, z);
            }

            return -1;
        }

        private long swap(long number)
        {
            long answer = 0;
            while (number > 0)
            {
                answer *= 10L;
                answer += (number % 10L);
                number /= 10L;
            }
            return answer;
        }

    }
}
