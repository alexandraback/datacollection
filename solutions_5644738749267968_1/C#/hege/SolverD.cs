using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace D
{
    class SolverD
    {
        private int _numBlocks;
        private List<double> _naomisBlocks;
        private List<double> _kensBlocks;

        public string SolveOne(TextReader input)
        {
            _numBlocks = int.Parse(input.ReadLine());
            _naomisBlocks = input.ReadLine().Split(' ').Select(double.Parse).ToList();
            _kensBlocks = input.ReadLine().Split(' ').Select(double.Parse).ToList();

            return string.Format("{0} {1}", GetDiceitfulWins(), GetFairWins());
        }

        private int GetFairWins()
        {
            int wins = 0;
            var nbs = _naomisBlocks.Select(d => d).ToList();
            var kbs = _kensBlocks.Select(d => d).ToList();
            for (int i = 0; i < _numBlocks; ++i)
            {
                double nb = nbs.Min();
                var cands = kbs.Where(d => d > nb).ToList();
                if (!cands.Any())
                {
                    ++wins;
                    nbs.Remove(nb);
                    kbs.Remove(kbs.Min());
                }
                else
                {
                    nbs.Remove(nb);
                    kbs.Remove(cands.Min());
                }
            }
            return wins;
        }

        private int GetDiceitfulWins()
        {
            int wins = 0;
            var nbs = _naomisBlocks.Select(d => d).ToList();
            var kbs = _kensBlocks.Select(d => d).ToList();
            for (int i = 0; i < _numBlocks; ++i)
            {
                double nb = nbs.Min();
                var cands = kbs.Where(d => d > nb).ToList();
                if (!cands.Any() || nb > kbs.Min())
                {
                    ++wins;
                    nbs.Remove(nb);
                    kbs.Remove(kbs.Min());
                }
                else
                {
                    nbs.Remove(nb);
                    kbs.Remove(cands.Max());
                }
            }
            return wins;
        }
    }
}