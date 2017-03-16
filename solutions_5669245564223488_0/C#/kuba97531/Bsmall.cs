using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using Solvers;
using GCJDevKit.Tools;
using System.Threading;
using System.Collections;

namespace GCJDevKit.Solvers
{
    public class Bsmall : AbstractSolver
    {
      
        protected override object Solve(System.IO.StreamReader input)
        {
            int n = NextInt();
            var words = NextWordsInLine();

            int count = 0;
            foreach (var p in permutate(words, n)){
                if (isOk(words)) count++;
            }
            return count;

        }

        bool isOk(String[] words)
        {
            char last = '0';
            HashSet<char> present = new HashSet<char>();
            foreach (var word in words)
            {
                foreach (var c in word)
                {
                    if (c != last)
                    {
                        if (present.Contains(c)) return false;
                        present.Add(c);
                    }
                    last = c;
                }
            }
            return true;
        }

        IEnumerable<int> permutate(String[] words, int n)
        {
            if (n == 1)
            {
                yield return 0;
            }
            else
            {
                for (int i = 0; i < n; i++)
                {
                    swap(words, n - 1, i);
                    foreach (var p in permutate(words, n - 1))
                    {
                        yield return p;
                    }
                    swap(words, n - 1, i);
                }
            }
            yield break;

        }

        void swap(String[] arr, int a, int b)
        {
            String c = arr[a];
            arr[a] = arr[b];
            arr[b] = c;
        }
    }
}
