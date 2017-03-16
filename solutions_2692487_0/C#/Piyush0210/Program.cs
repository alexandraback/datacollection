using System;
using System.Collections;
using System.Collections.Generic;
using System.IO;
using System.Text;

namespace Osmos
{
    class Program
    {

        static void Main(string[] args)
        {
            StreamReader sr = new StreamReader("A-small-attempt0.in");
            StreamWriter sw = new StreamWriter("A-small-attempt0.out");
            int T = int.Parse(sr.ReadLine());
            for (int i = 0; i < T; i++)
            {
               String[] inputs = sr.ReadLine().Split(new char[] {' ' });
                UInt64 mote = UInt64.Parse(inputs[0]);
                int N = int.Parse(inputs[1]);
                List<UInt64> list = new List<UInt64>();
                inputs = sr.ReadLine().Split(new char[] { ' ' });
                for (int j = 0; j < inputs.Length; j++)
                {
                    list.Add(UInt64.Parse(inputs[j]));
                }
                list.Sort();
                sw.WriteLine(String.Format("Case #{0}: {1}", (i+1), solution(mote, list)));                
            }
            sr.Close();
            sw.Close();
        }

        public static int solution(UInt64 mote, List<UInt64> list)
        {
            if (mote == 1)
                return list.Count;
            int best = list.Count;
            int currentOperations = 0;
            int remainingItems = list.Count;
            foreach (UInt64 m in list)
            {
                remainingItems--;
                if (mote > m)
                {
                    mote = mote + m;
                }
                else
                {
                    int count = getCountToAbsorb(ref mote, m);
                    currentOperations += count;
                    mote = mote + m;
                }
                if (best > currentOperations + remainingItems)
                {
                    best = currentOperations + remainingItems;
                }
            }
            return best;
        }

        public static int getCountToAbsorb(ref UInt64 initial, UInt64 toBeAbsorbed)
        {
            
                int count = 0;
                while (initial <= toBeAbsorbed)
                {
                    initial = 2*initial - 1;
                    count++;
                }
                return count;
        }
    }
}