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
        public T myget<T>(string s)
        {
            var m = typeof(T).GetMethod("Parse", new Type[] { typeof(string) });
            return (T)m.Invoke(null, new object[] { s });
        }
        public string getstring() { return data[pointer++]; }
        public int getint() { return int.Parse(data[pointer++]); }
        public long getlong() { return long.Parse(data[pointer++]); }
        public bigint getbit() { return bigint.Parse(data[pointer++]); }
        public int[] getintarray(int count)
        {
            int aaa = myget<int>("128");
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
        static void print_array(Array array)
        {
            foreach (var each in array)
                Console.Write("{0} ", each);
            Console.WriteLine();
        }
        static void print_array2d(Array array2d)
        {
            int imax = array2d.GetLength(0);
            int jmax = array2d.GetLength(1);
            for (int i = 0; i < imax; ++i)
            {
                for (int j = 0; j < jmax; ++j)
                    Console.Write("{0} ", array2d.GetValue(i, j));
                Console.WriteLine();
            }
        }
        static char[] vowels = new char[] { 'a', 'e', 'i', 'o', 'u' };
        static string Solve(Input inp)
        {
            // solve a problem here
            string L = inp.getstring();
            int l = L.Length;
            int n = inp.getint();
            //Console.WriteLine(L);
            //Console.WriteLine(n);
            List<int> lst = new List<int>();
            for (int i = 0,top=0; i < l; ++i)
            {
                if (vowels.Contains(L[i])) 
                {
                    top = i + 1;
                }
                else
                {
                    if (i - top + 1 >= n)
                    {
                        lst.Add(i - n + 1);
                    }
                }
            }
            //print_array(lst.ToArray());
            int ret = 0;
            for (int len = n; len <= l; ++len)
            {
                int min, max, tmp = 0;
                foreach (var index in lst)
                {
                    //Console.WriteLine(index);
                    min = index + n - len;
                    if (min <= tmp) min = tmp;
                    max = index;
                    if (min < 0) min = 0;
                    if (max + len >= l) max = l - len;
                    int count = max - min + 1;
                    if (count > 0) ret += count;
                    tmp = max + 1;
                    //Console.WriteLine("len={0} => {1} to {2} => {3}, tmp={4}", len,min,max,count,tmp);
                }
            }
            return ret.ToString();
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
            //Console.ReadLine();
        }
    }
}
