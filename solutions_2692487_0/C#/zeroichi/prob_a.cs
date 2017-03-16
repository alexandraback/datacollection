using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;
using System.Numerics;
using bigint = System.Numerics.BigInteger;

namespace template
{
    class Input
    {
        string[] data;
        int pointer = 0;

        public Input(string[] a)
        {
            data = a;
        }
        public string getstring() { return data[pointer++]; }
        public int getint() { return int.Parse(data[pointer++]); }
        public long getlong() { return long.Parse(data[pointer++]); }
        public bigint getbit() { return bigint.Parse(data[pointer++]); }
        public int[] getintarray(int count)
        {
            var ret = data.Skip(pointer).Take(count).Select(x => int.Parse(x)).ToArray();
            pointer += count;
            return ret;
        }
        public long[] getlongarray(int count)
        {
            var ret = data.Skip(pointer).Take(count).Select(x => long.Parse(x)).ToArray();
            pointer += count;
            return ret;
        }
    }

    class template
    {
        static Input load_all(string filename)
        {
            List<string> ret = new List<string>();
            using (var sr = new StreamReader(filename))
            {
                while (true)
                {
                    string s = sr.ReadLine();
                    if (s == null) break;
                    string[] split = s.Split(' ');
                    ret.AddRange(split);
                }
            }
            return new Input(ret.ToArray());
        }

        static string Solve(Input inp)
        {
            // solve a problem here
            List<int> candidate = new List<int>();
            int armin = inp.getint();
            List<int> others = inp.getintarray(inp.getint()).ToList();
            int ops = 0;
        restart:
            others.Sort();
            List<int> sum = new List<int>();
            int now = armin;
            for (int i = 0; i < others.Count; ++i)
            {
                sum.Add(now);
                now += others[i];
            }
            int[] diff = new int[others.Count];
            diff = others.Select((x, i) => x - sum[i]).ToArray();
            for (int i = 0; i < diff.Length; ++i)
            {
                if (diff[i] >= 0)
                {
                    int erase = diff.Length - i; // 後ろの mote を消す場合のop数
                    int need = 0; // 次の点を取り込むのに必要なop数
                    List<int> add_list = new List<int>();
                    while (diff[i] >= 0)
                    {
                        if (sum[i] - 1 == 0) { need = int.MaxValue; break; }
                        // sum[i]-1 のmoteを加える
                        need++;
                        add_list.Add(sum[i] - 1);
                        sum[i] += sum[i] - 1;
                        diff[i] = others[i] - sum[i]; // recalc
                    }
                    if (erase <= need)
                    {
                        ops += erase;
                        candidate.Add(ops);
                        goto decide;
                    }
                    candidate.Add(ops + erase);
                    others.AddRange(add_list);
                    ops += need;
                    goto restart;
                }
            }
            candidate.Add(ops);
        decide:
            candidate.Sort();
        return candidate[0].ToString();
        }

        static void Main(string[] args)
        {
            Input inp;
            string fname;
            if (args.Length < 1)
            {
                Console.WriteLine("filename?");
                fname = Console.ReadLine();
                if (fname.Trim() == "") return;
                if (fname[0] == '"') fname = fname.Substring(1, fname.Length - 2);
            }
            else { fname = args[0]; }
            inp = load_all(fname);
            int cases = inp.getint();
            using (var sw = new StreamWriter(fname + ".output"))
            {
                for (int c = 0; c < cases; c++)
                {
                    sw.WriteLine(string.Format("Case #{0}: {1}", c + 1, Solve(inp)));
                }
            }
        }
    }
}
