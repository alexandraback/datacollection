using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Repeater
{
    class Program
    {
        const string INPUT_PATH = "A-small-attempt0.in";
        const string OUTPUT_PATH = "output.dat";


        static void Out(string s)
        {
            Console.WriteLine(s);
            using (var sw = new StreamWriter(OUTPUT_PATH, true))
            {
                sw.WriteLine(s);
            }
        }

        static void ReadCase(StreamReader s, ref int N,  ref List<string> x)
        {
            N = int.Parse(s.ReadLine());
            
           
            for (int i = 0; i < N; i++)
            {
                x.Add( s.ReadLine());
            }

        }

        static void Main(string[] args)
        {

            if (File.Exists(OUTPUT_PATH))
            {
                File.Delete(OUTPUT_PATH);
            }

            var s = new StreamReader(INPUT_PATH);

            int T = int.Parse(s.ReadLine());

            for (int currentCase = 0; currentCase < T; currentCase++)
            {
                int N = 0;
                var strings = new List<string>();

                var stringFootprints = new  List<List<Tuple<string, int>>>();
                var standardString = new List<Tuple<string, int>>();

                ReadCase(s, ref N, ref strings);

                foreach (var item in strings)
                {

                    var current = new List<Tuple<string, int>>();
                    for( int i = 0; i< item.Length; i++ )
                    {
                        if(  (i > 0) &&(item[i] == item[i-1]))
                        {
                            var tmp = current[current.Count - 1];
                            
                            current[current.Count - 1 ] = new Tuple<string, int>(tmp.Item1, tmp.Item2 + 1);
                        }
                        else
                        {
                            current.Add(new Tuple<string, int>(item[i].ToString(), 1));
                        }

                    }

                    stringFootprints.Add(current);

                }

                //check if it`s possible to solve

                bool flag = true;
                    
                int charLength = stringFootprints[0].Count;
               
                for( int y = 0; y < stringFootprints.Count; y++)
                {
                    if (stringFootprints[y].Count != charLength) flag = false;
                }


                if (flag)
                {
                    for (int x = 0; x < charLength; x++)
                    {
                        string currChar = stringFootprints[0][x].Item1;

                        standardString.Add( new Tuple<string,int>( currChar, 1 ));
                        
                        for (int y = 0; y < stringFootprints.Count; y++)
                        {
                            if (stringFootprints[y][x].Item1 != currChar) flag = false;
                        }
                    }
                }
                
                if( flag )
                {
                   int resultSum = 0;

                   for( int y = 0 ; y< charLength; y++)
                   {
                        int [] counts = new int[stringFootprints.Count];
                    
                        for( int x = 0 ; x < counts.Length; x++ )
                        {
                            counts[x] = stringFootprints[x][y].Item2;
                        }

                       //find median
                       counts = counts.OrderBy( x =>  x ).ToArray();

                       int median = counts[counts.Length / 2];
                       
                       for( int x = 0 ; x<counts.Length; x++)
                       {
                           resultSum += Math.Abs(counts[x] - median);

                       }
                   }

                     Out( String.Format( "Case #{0}: {1}", currentCase+1,resultSum));

                }
                else
                {
                    Out( String.Format( "Case #{0}: Fegla Won", currentCase+1));

                }
            }

            s.Close();
        }
    }
}
