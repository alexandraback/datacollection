
using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace CodeJamRound1BA

{
    class Program
    {


        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader(@"C:\Users\Trevor\Downloads\input.txt");
            StreamWriter sw = new StreamWriter(@"C:\Users\Trevor\Downloads\output.txt");



            int count = int.Parse(sr.ReadLine());

            for(int x = 0; x< count ; x++){
                sw.Write("Case #" + (x + 1) + ": ");

                Do(sr, sw);
            }
            sw.Flush();
        }


        public class NVPair : IComparable
        {
            public List<long> items;
            public long moves;
            public long size;

            public NVPair(List<long> items, long moves, long size)
            {
                this.size = size;
                this.items = new List<long>(items);
                this.moves = moves;
            }



            public int CompareTo(object obj)
            {
                return (int)(moves - ((NVPair)obj).moves);
            }
        }

        public static void Do(StreamReader sr, StreamWriter sw)
        {
            string[] s1 = sr.ReadLine().Split(' ');
            long a = long.Parse(s1[0]);
            long n = long.Parse(s1[1]);

            s1 = sr.ReadLine().Split(' ');
            List<long> initialList = new List<long>();
            for (int i = 0; i < n; i++)
            {
                initialList.Add(long.Parse(s1[i]));
            }

            initialList.Sort();

            Queue<NVPair> next = new Queue<NVPair>();

            NVPair ini = new NVPair(initialList, 0, a);


            next.Enqueue(ini);

            long min = initialList.Count();

            while(true){
                if (next.Count == 0)
                    break;
                NVPair cur = next.Dequeue();

                if(cur.moves >= min){
                    break;
                }

                long s = cur.size;
                bool comp = true;
                for(int i = 0; i< cur.items.Count; i++){
                    if(cur.items[i] < s){
                        s+=cur.items[i];
                        cur.items.RemoveAt(i);
                        i--;
                    }else{
                        comp = false;
                        NVPair tmp = new NVPair(cur.items,cur.moves+1,s);
                        if(tmp.items.Count + cur.moves < min)
                            min = tmp.items.Count + cur.moves;
                        tmp.items.Insert(0, s-1);
 

                        next.Enqueue(tmp);
                        break;
                    }
                }
                if (comp)
                {
                    if (cur.moves < min)
                        min = cur.moves;
                }
            }

            sw.WriteLine(min);

        }
    }
}

