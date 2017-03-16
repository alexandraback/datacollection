using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace ConsoleApplication6
{
    class Program
    {
        //static int CountSheep(int N)
        //{
        //    HashSet<char> seen = new HashSet<char>();

        //    for (int j = 1; true; j++)
        //    {
        //        bool done = true;
        //        int num = N * j;
        //        var digits = num.ToString().ToList();
        //        for (int i = 0; i < 10; ++i)
        //        {
        //            if (digits.Contains(i.ToString()[0]))
        //            {
        //                seen.Add(i.ToString()[0]);
        //            }
        //            else if (!seen.Contains(i.ToString()[0]))
        //            {
        //                done = false;
        //            }
        //        }

        //        if (done)
        //        {
        //            N = j * N;
        //            break;
        //        }
        //    }
        //    return N;
        //}

        //static int RevengeOfPancakes(String stack)
        //{
        //    int ret = 0;
        //    stack = stack + "+";
        //    // super fast way:
        //    // count how many "changes" there are between neighbors, assuming a terminal +
        //    for (int i = 0; i < stack.Length - 1; ++i)
        //    {
        //        if (stack[i] != stack[i + 1])
        //        {
        //            ret++;
        //        }
        //    }
        //    return ret;
        //}



        // UINT64 should work, but lets be simpler
        //static string Fractiles(System.Numerics.BigInteger numTilesOriginal, System.Numerics.BigInteger complexity, System.Numerics.BigInteger numGradStudents)
        //{
        //    // for small, just sample the first S tiles (either first tile is gold, so we are done, or first tile is lead, so first N tiles is copy of original sequence)

        //    // for large, we can sample (1+2*k+3*k^2) to determine 1,2,3 simultaneously
        //    // make it zero indexed...
        //    // sample (0+k+2k^2+3k^3+4k^4+...+(c-1)k^(c-1)), then +1 to 1-index it
        //    // sample (c+(c+1)k+(c+2)k^(2)+...+(2c-1)k^(c-1))
        //    // .. etc.
        //    // can fit in 64bit int, but use bigint just to be sure
        //    System.Numerics.BigInteger numTiles = System.Numerics.BigInteger.Pow(numTilesOriginal, (int)complexity);

        //    System.Collections.Generic.HashSet<System.Numerics.BigInteger> samples = new HashSet<System.Numerics.BigInteger>();

        //    int numOriginalTilesSampled = 0;

        //    if (numTilesOriginal <= complexity * numGradStudents)
        //    {
        //        //for (System.Numerics.BigInteger s = 0; s < numGradStudents; ++s)
        //        //{
        //        //    samples.Add(s + 1);
        //        //}

        //        for (System.Numerics.BigInteger s = 0; s < numGradStudents; ++s)
        //        {
        //            System.Numerics.BigInteger sample = 0;
        //            for (System.Numerics.BigInteger i = 0; i < complexity; ++i)
        //            {
        //                System.Numerics.BigInteger originalTile = (s * complexity + i);

        //                sample = sample + originalTile * System.Numerics.BigInteger.Pow(numTilesOriginal, (int)i);
        //                numOriginalTilesSampled++;
        //                if (numOriginalTilesSampled >= numTilesOriginal)
        //                {
        //                    break;
        //                }
        //            }
        //            samples.Add(sample + 1);

        //            if (numOriginalTilesSampled == numTilesOriginal)
        //            {
        //                break;
        //            }
        //        }
        //    }
        //    else
        //    {
        //        return " IMPOSSIBLE";
        //    }

        //    String ret = "";
        //    foreach (System.Numerics.BigInteger sample in samples)
        //    {
        //        ret = ret + " " + sample.ToString();
        //    }
        //    return ret;
        //    // we can sample c elements at the same time

        //    // what S do we need?
        //    // c sampled by each tile
        //    // we can win if k <= c*s

        //}

        static String ParseBase(string num, int b)
        {
            System.Numerics.BigInteger result = 0;
            for (int i = 0; i < num.Length; ++i)
            {
                result = result * b;
                if (num[i] != '0')
                {
                    result = result + 1;
                }
            }
            return result.ToString();
        }

        static String ToBinary(int num)
        {
            String ret = "";

            while (num != 0)
            {
                ret = (num%2 == 1 ? "1" : "0") + ret;
                num = num / 2;
            }

            return ret;
        }

        static void coinjam(int length, int numjamcoins)
        {
            // jamcoin - string of 1 and 0.  string in any base (2-10) is not prime
            // output numjamcoins jamcoins, and a factor in each base

            for (int i = 1; i <= numjamcoins; ++i)
            {
                // construct our jamcoin number (only works because numjamcoins is sufficiently small to not overlap prefix with suffix)
                // {bits}100000{bits}1, which is divisible in each base by {bits}1
                string prefix = ToBinary(i) + "1";
                
                string jamcoin = prefix + new string('0', length - prefix.Length * 2) + prefix;

                Console.Write(jamcoin);
                
                // and our divisor in each base is:
                // (prefix converted to appropriate base)
                for (int b = 2; b <=10; ++b)
                {
                    Console.Write(" " + ParseBase(prefix, b));
                }
                Console.WriteLine();
            }
        }

        static void Main(string[] args)
        {
            int T = int.Parse(Console.ReadLine());
            for (int i = 1; i <= T; ++i)
            {
                string[] line = Console.ReadLine().Split(' ');
                int N = int.Parse(line[0]);
                int J = int.Parse(line[1]);
                Console.WriteLine("Case #{0}:", i);
                coinjam(N, J);
            }
        }

        //A:
        //int T = int.Parse(Console.ReadLine());
        //for (int i = 1; i <= T; ++i)
        //{
        //    int N = int.Parse(Console.ReadLine());
        //    if (N == 0)
        //    {
        //        Console.WriteLine("Case #{0}: INSOMNIA", i);
        //    }
        //    else
        //    {
        //        Console.WriteLine("Case #{0}: {1}", i, CountSheep(N));
        //    }
        //}

        //int max = 0;
        //for (int i = 1; i < 1000000; ++i)
        //{
        //    max = System.Math.Max(max, CountSheep(i) / i);
        //    //if (i == 0)
        //    //{
        //    //    Console.WriteLine("{0}: INSOMNIA");
        //    //}
        //    //else
        //    //{
        //    //    Console.WriteLine("{0}: {1}", i, CountSheep(i));
        //    //}
        //    //if (i % 20 == 19)
        //    //{
        //    //    Console.ReadKey();
        //    //}
        //}
        //Console.WriteLine("{0}", max);

        //    int T = int.Parse(Console.ReadLine());
        //        for (int i = 1; i <= T; ++i)
        //        {
        //            String S = Console.ReadLine();
        //    Console.WriteLine("Case #{0}: {1}", i, RevengeOfPancakes(S));
        //        }
        ////Console.ReadKey();

        // D:
        //int T = int.Parse(Console.ReadLine());
        //for (int i = 1; i <= T; ++i)
        //{
        //    var nums = Console.ReadLine().Split(' ');
        //    int k = int.Parse(nums[0]);
        //    int c = int.Parse(nums[1]);
        //    int s = int.Parse(nums[2]);
        //    Console.WriteLine("Case #{0}: {1}", i, Fractiles(k, c, s));
        //}
        //Console.ReadKey();
    }
}
