using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace bullseye
{
    class Program
    {

        public static int findMaxIndex(Int64[] arr, int start, int end)
        { 
            Int64 max = arr[start];
            int maxIndex = start;
            for (int i = start + 1; i <= end; i++)
            {
                if (arr[i] > max)
                {
                    max = arr[i];
                    maxIndex = i;
                }
            }
            return maxIndex;
        }

        public static Int64 getGain(Int64 E, Int64 R, int start, int end, Int64[] values, Int64[] cum)
        {
            Int64 energyUsed = 0;
            int maxIndex = findMaxIndex(values, start, end);
            if (cum[maxIndex] >= E)
            {
                energyUsed = E;
            }
            else
            {
                energyUsed = cum[maxIndex];
            }
            if (cum[maxIndex - 1] < cum[maxIndex] - energyUsed)
            {
                for (int k = maxIndex - 1; k >= 0; k--)
                {

                }
            }
            Int64 left = getGain(E, R, start, maxIndex - 1, values, cum);
            Int64 right = getGain(E, R, maxIndex + 1, end, values, cum);


            return left + right + energyUsed * values[maxIndex];
        }

        public static Int64 GetGain(Int64[] values, Int64 E, Int64 R, int start, int end, Int64 leftE)
        {
            if (start >= end)
                return (Int64)0;
            Int64 maxGain = 0;
            for (Int64 i = leftE; i >= 0; i--)
            { 
                Int64 newE = leftE+R-i;
                if (newE > E)
                {
                    newE = E;
                }
                Int64 gain = GetGain(values, E, R, start+1, end, newE)+i*values[start];
                if (gain > maxGain)
                    maxGain = gain;
            }

            return maxGain;
        }

        static void Main(string[] args)
        {
            StreamReader reader = new StreamReader("B-small.in");
            StreamWriter writer = new StreamWriter("output.txt");
            Int64 TTestCases = Int32.Parse(reader.ReadLine());

            for (int tIndex = 0; tIndex < TTestCases; tIndex++)
            {
                Int64 gain = 0;
                String[] ERN = (reader.ReadLine()).Split(' '); 
                Int64 E = Int64.Parse(ERN[0]);
                Int64 R = Int64.Parse(ERN[1]);
                Int32 N = Int32.Parse(ERN[2]);
                String[] Values = (reader.ReadLine()).Split(' ');
                Int64[] Vals = new Int64[N] ;
               //Int64[] CumEnergy = new Int64[N];

                for (int i = 0; i < N; i++)
                {
                    Vals[i] = Int64.Parse(Values[i]);
                  /*  if (i == 0)
                        CumEnergy[i] = E;
                    else
                        CumEnergy[i] = CumEnergy[i-1]+R;*/
                }

                if (R >= E)
                {
                    for (int i = 0; i < N; i++)
                    {
                        gain += Vals[i] * E;
                    }
                    goto print;
                }

                gain = GetGain(Vals, E, R, 0, N, E);

  //              int maxIndex = findMaxIndex(Vals, 0, N);
//                CumEnergy[maxIndex] -= E;
                
            print:
                writer.WriteLine("Case #"+(tIndex+1)+": "+gain);
            }
            reader.Close();
            writer.Close();
        }
        
    }
}
