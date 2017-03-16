using System;   
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace GoogleCodeJam.Round1
{
    class Q2
    {
        static void Main(string[] args)
        {
            int numberOfInputs = Convert.ToInt32(Console.ReadLine());

            for (int index = 1; index <= numberOfInputs; index++ )
            {
                bool impossible = false;
                Int64 mul = 1;
                int N = Convert.ToInt32(Console.ReadLine());

                String[] trains = Console.ReadLine().Split(' ');
                List<char> lefts =  new List<char>();
                List<char> rights =  new List<char>();
                List<char> [] stuck = new List<char>[N];
                Dictionary<char,int> weights = new Dictionary<char,int>();

                for(int i = 0; i < N ; i++ )
                {
                    String t = trains[i];
                    t = new String(t.ToCharArray().Where((item,idx) => idx == 0 || item != t[idx-1]).ToArray());
                    
                    lefts.Add(t[0]);
                    rights.Add(t[t.Length - 1]);
                    stuck[i] = new List<char>();
                    if (t.Length > 2)
                        stuck[i].AddRange(t.Substring(1, t.Length - 2));
                    if (stuck[i].Contains(lefts[i]) || stuck[i].Contains(rights[i])) 
                    {
                        impossible = true;
                        break;
                    }
                    for (int j = 0; j < i; j ++)
                    {
                        if (stuck[j].Contains(lefts[i]) || stuck[j].Contains(rights[i])) 
                        {
                            impossible = true;
                            break;
                        }
                    }
                    if (impossible)
                        break;
                }
                if (impossible)
                {
                    Console.WriteLine("Case #" + index + ": 0");
                    continue;
                }

                int output  = N;

                for (int i = 0; i < N && mul != 0; i ++ )
                {
                    for (int j = 0; j < N ; j ++)
                    {
                        if (j == i) continue;
                        if (lefts[i] == rights[j] && lefts[j] == rights[i])
                        {
                            if (lefts[i] == rights[i])
                            {
                                output--;                                
                                lefts.RemoveAt(j); rights.RemoveAt(j); N--; if (i > j) i--;
                                if (weights.ContainsKey(lefts[i]))
                                {
                                    mul *= weights[lefts[i]]+2;
                                    weights[lefts[i]] += 1; 
                                }
                                else
                                {
                                    mul *= 2;
                                    weights.Add(lefts[i], 1);
                                }
                                
                            }
                            else
                            {
                                mul = 0;
                            }
                            i --;
                            break;
                        }
                        if (rights[i] == lefts[j])
                        {
                            output--;
                            rights[i] = rights[j];
                            lefts.RemoveAt(j); rights.RemoveAt(j); N--; if (i > j) i--;
                            i--; break;                      
                        }
                    }
                }                
                while (output> 1)
                {
                    mul *= output;
                    output--;
                }
                Console.WriteLine("Case #" + index + ": " + (mul % 1000000007));                                
            }
        }

    }
}
