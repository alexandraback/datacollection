using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace CodeJam
{
    public class Question2 : Problem
    {
        private List<long> powersOfTwo = new List<long>() { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192 };

        protected override string SolveCase()
        {
            var parameters = this.ReadNextLineAsInt64Array();
            var b = (int)parameters[0];
            var routes = parameters[1];

            var maxPossible = this.PowerOfTwo(b - 2);
            if (routes > maxPossible)
            {
                return "IMPOSSIBLE";
            }

            this.WriteCaseOutput("POSSIBLE");

            this.WriteFirstSlides(b, routes);
            this.WriteLowerSlides(b);

            return string.Empty;
        }

        private long PowerOfTwo(int power)
        {
            while (this.powersOfTwo.Count + 1 < power)
            {
                this.powersOfTwo.Add(this.powersOfTwo.Last() * 2);
            }

            return this.powersOfTwo[power];
        }

        private void WriteFirstSlides(int b, long routes)
        {
            var slides = "0 ";
            for (int i = b - 3; i >= 0; i--)
            {
                if (routes >= this.PowerOfTwo(i))
                {
                    slides += "1 ";
                    routes -= this.PowerOfTwo(i);
                }
                else
                {
                    slides += "0 ";
                }
            }

            if (routes == 1)
            {
                slides += "1";
            }
            else
            {
                slides += "0";
            }

            this.WriteLineToFile(slides);
        }

        private void WriteLowerSlides(long b)
        {
            var slides = Enumerable.Repeat(1, (int)b).ToArray();
            slides[0] = 0;
            for (int i = 1; i < b; i++)
            {
                slides[i] = 0;
                this.WriteLineToFile(string.Join(" ", slides));
            }
        }
    }
}
