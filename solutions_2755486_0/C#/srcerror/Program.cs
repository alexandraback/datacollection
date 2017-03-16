using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;

namespace BaseApp
{
    class Program
    {
        static void Main(string[] args)
        {
            string input = @"d:\Work\Current\CodeJam\3\C-small-attempt0.in";
            string output = @"d:\Work\Current\CodeJam\3\C-small-attempt0.out";

            using (var sin = new StreamReader(input))
            {
                using (var sout = new StreamWriter(output, false))
                {
                    var s = sin.ReadLine();
                    var N = long.Parse(s);
                    for (long i = 1; i <= N; i++)
                    {
                        string result = Task3(sin);
                        sout.WriteLine("Case #{0}: {1}", i, result);
                        Console.WriteLine("Case #{0}: {1}", i, result);
                    }
                }
            }
        }

//di – the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
//ni – the number of attacks from this tribe
//wi, ei – the westmost and eastmost points respectively of the Wall attacked on the first attack
//si – the strength of the first attack
//delta_di – the number of days between subsequent attacks by this tribe
//delta_pi – the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
//delta_si – the change in strength between subsequent attacks
        // di, ni, wi, ei, si, delta_di, delta_pi and delta_si
        class Tribe
        {
            public long di;
            public long ni;
            public long wi;
            public long ei;
            public long si;
            public long ddi;
            public long dpi;
            public long dsi;
        }

        private static string Task3(StreamReader sin)
        {
            var n = long.Parse(sin.ReadLine());
            var tribes = new List<Tribe>();
            for (int i = 0; i < n; i++)
            {
                var s = sin.ReadLine().Split(' ').Select(t => long.Parse(t)).ToList();
                var tr = new Tribe()
                    {
                        di = s[0],
                        ni = s[1],
                        wi = s[2],
                        ei = s[3],
                        si = s[4],
                        ddi = s[5],
                        dpi = s[6],
                        dsi = s[7],
                    };
                tribes.Add(tr);
            }

            long day = 0;
            long count = 0; 
            var wall = new Dictionary<long, long>();
            var builds = new Dictionary<long, long>(); 
            while (tribes.Count > 0)
            {
                
                // process day
                foreach (var tribe in tribes)
                {
                    
                    if (tribe.di == day)
                    {
                        // process attack
                        bool success = false;

                        for (long i = tribe.wi; i <= tribe.ei ; i++)
                        {
                            if (wall.ContainsKey(i))
                            {
                                var h = wall[i];
                                if (h < tribe.si)
                                {
                                    success = true;
                                    AddBuild(i, builds, tribe.si);
                                }
                            }
                            else
                            {
                                success = true;
                                AddBuild(i, builds, tribe.si);
                            }
                        }
                        // next
                        tribe.ni -= 1;
                        tribe.di += tribe.ddi;
                        tribe.si += tribe.dsi;
                        tribe.ei += tribe.dpi;
                        tribe.wi += tribe.dpi;
                        if (success) count++;
                    }

                }
                // apply daily builds
                foreach (var build in builds)
                {
                    if (wall.ContainsKey(build.Key))
                    {
                        if (wall[build.Key] < build.Value)
                        {
                            wall[build.Key] = build.Value;
                        }
                    }
                    else
                    {
                        wall[build.Key] = build.Value;
                    }
                }
                builds.Clear();
                day++;
                tribes = tribes.Where(t => t.ni > 0).ToList();
            }

            return count.ToString();
        }

        private static void AddBuild(long i, Dictionary<long, long> builds, long height)
        {
            if (builds.ContainsKey(i) && builds[i] < height)
            {
                builds[i] = height;
            }
            else
            {
                builds[i] = height;
            }
        }



        static BigInteger ABS(BigInteger b)
        {
            return b >= 0 ? b : -b;
        }

        private static string Task2(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ').Select(t => Int64.Parse(t)).ToArray();
            var X = s[0];
            var Y = s[1];
            // WNES
            int i = 1;
            var T1 = Math.Abs(X);
            var T2 = Math.Abs(Y);
            var sum = T1 + T2;

            long nsum = 0;
            long idx = 0;
            while (nsum < sum)
            {
                idx++;
                nsum += idx;
            }

            var sb = new StringBuilder();
            long step = idx;
            while (step > 0)
            {
                if (Math.Abs(X) > Math.Abs(Y))
                {
                    if (X > 0)
                    {
                        // east
                        sb.Append('E');
                        X -= step;
                        step--;
                    }
                    else if (X < 0)
                    {
                        // west
                        sb.Append('W');
                        X += step;
                        step--;
                    }
                    else
                    {
                        // X == 0
                        if (Y > 0)
                        {
                            // south
                            sb.Append('N');
                            Y -= step;
                            step--;
                        }
                        else if (Y <= 0)
                        {
                            // noeth
                            sb.Append('S');
                            Y += step;
                            step--;
                        }
                    }
                    
                }
                else
                {
                    // |Y| >= |X|
                    if (Y > 0)
                    {
                        // south
                        sb.Append('N');
                        Y -= step;
                        step--;
                    }
                    else if (Y < 0)
                    {
                        // noeth
                        sb.Append('S');
                        Y += step;
                        step--;
                    }
                    else
                    {
                         // Y == 0
                        if (X > 0)
                        {
                            // east
                            sb.Append('E');
                            X -= step;
                            step--;
                        }
                        else if (X <= 0)
                        {
                            // west
                            sb.Append('W');
                            X += step;
                            step--;
                        }
                    }
                }
            }
            var result = new StringBuilder(new string(sb.ToString().Reverse().ToArray()));
            if (Math.Abs(X) > 0)
            {
                string pair;
                if (X > 0)
                {
                    pair = "WE";
                }
                else
                {
                    pair = "EW";
                }
                for (long j = 0; j < Math.Abs(X); j++)
                {
                    result.Append(pair);
                }
            }
            if (Math.Abs(Y) > 0)
            {
                string pair;
                if (Y > 0)
                {
                    pair = "SN";
                }
                else
                {
                    pair = "NS";
                }
                for (long j = 0; j < Math.Abs(Y); j++)
                {
                    result.Append(pair);
                }
            }
            return result.ToString();
        }

        static char [] vv = new char[]{'a', 'e', 'o', 'i', 'u'};
        static Dictionary<char, bool> vowels = new Dictionary<char, bool> { { 'a', true}, {'e', true}, { 'o', true}, { 'i', true}
            ,{'u', true} };

        struct Pair
        {
            public bool IsVowel;
            public long Number;
        }
        private static string Task1(StreamReader sin)
        {
            var s = sin.ReadLine().Split(' ');
            var word = s[0];
            var n = int.Parse(s[1]);

            bool isVowel = false;
            if (vowels.ContainsKey(word[0]))
                isVowel = true;
            long idx = 0;
            long count = 0;
            List<Pair> input = new List<Pair>();
            for (int i = 0; i < word.Length; i++)
            {
                bool iv = CharIsVowel(word[i]);
                if (iv == isVowel)
                {
                    count++;
                }
                else
                {
                    input.Add(new Pair() {IsVowel = isVowel, Number = count});
                    count = 1;
                    isVowel = iv;
                }
            }
            if (count > 0) input.Add(new Pair() { IsVowel = isVowel, Number = count });

            // calculate
            BigInteger sum = 0;
            long lastVowels = 0;
            bool isFirst = true;
            idx = -1;
            //foreach (var pair in input)
            //{
            //    if (!pair.IsVowel)
            //    {
                     
            //    }
            //}
            count = 0;
            idx = 0;
            for (long i = 0; i < word.Length; i++)
            {
                if (!CharIsVowel(word[(int)i]))
                {
                    count++;

                    if (count == n)
                    {
                        // calc
                        long A = i + 1 - n - idx + 1;
                        var B = word.Length - i;
                        sum += A*B;
                        //shift
                        idx = i + 2 - n;
                        count--;
                    }

                    
                }
                else
                {
                    count = 0;
                }
            }

            

            return sum.ToString();
        }

        private static bool CharIsVowel(char c)
        {
            return vowels.ContainsKey(c);
        }
    }
}
