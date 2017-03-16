using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Google_Code_Jam
{
    public static class Problem_C
    {
        private class Quaternion
        {
            private bool m_isNegative;
            private char m_value;

            private static readonly IDictionary<char, IDictionary<char, Quaternion>> s_mapping = new Dictionary<char, IDictionary<char, Quaternion>>
            {
                { '1', 
                    new Dictionary<char, Quaternion> 
                    {
                        {'1', new Quaternion('1')},
                        {'i', new Quaternion('i')},
                        {'j', new Quaternion('j')},
                        {'k', new Quaternion('k')},
                    }
                },
                { 'i', 
                    new Dictionary<char, Quaternion> 
                    {
                        {'1', new Quaternion('i')},
                        {'i', new Quaternion('1', true)},
                        {'j', new Quaternion('k')},
                        {'k', new Quaternion('j', true)},
                    }
                },
                { 'j', 
                    new Dictionary<char, Quaternion> 
                    {
                        {'1', new Quaternion('j')},
                        {'i', new Quaternion('k', true)},
                        {'j', new Quaternion('1', true)},
                        {'k', new Quaternion('i')},
                    }
                },
                { 'k', 
                    new Dictionary<char, Quaternion> 
                    {
                        {'1', new Quaternion('k')},
                        {'i', new Quaternion('j')},
                        {'j', new Quaternion('i', true)},
                        {'k', new Quaternion('1', true)},
                    }
                }
            };

            public Quaternion(char value)
            {
                m_isNegative = false;
                m_value = value;
            }

            public Quaternion(char value, bool isNegative)
            {
                m_isNegative = isNegative;
                m_value = value;
            }

            public Quaternion(Quaternion other)
            {
                m_value = other.Value;
                m_isNegative = other.IsNegative;
            }

            public static Quaternion operator *(Quaternion left, Quaternion right)
            {
                Quaternion retVal = new Quaternion(s_mapping[left.Value][right.Value]);
                retVal.IsNegative = (left.IsNegative != right.IsNegative) != retVal.IsNegative;
                return retVal;
            }

            public bool IsNegative
            {
                get { return m_isNegative; }
                set { m_isNegative = value; }
            }

            public char Value
            {
                get { return m_value; }
                set { m_value = value; }
            }

            public bool IsI
            {
                get { return !m_isNegative && m_value == 'i'; }
            }

            public bool IsJ
            {
                get { return !m_isNegative && m_value == 'j'; }
            }

            public bool IsK
            {
                get { return !m_isNegative && m_value == 'k'; }
            }

            public static Quaternion One
            {
                get { return new Quaternion('1'); }
            }

            public override string ToString()
            {
                return m_isNegative ? "-" + m_value.ToString() : m_value.ToString();
            }
        }

        public static void Run()
        {
            List<string> output = new List<string>();

            using (StreamReader sr = File.OpenText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\C-small-attempt0.in"))
            {
                int testCases = int.Parse(sr.ReadLine());
                for (int caseNum = 1; caseNum <= testCases; caseNum++)
                {
                    HashSet<int> iIndexes = new HashSet<int>();
                    HashSet<int> kIndexes = new HashSet<int>();

                    string [] firstLine = sr.ReadLine().Split(' ');
                    int stringLength = int.Parse(firstLine[0]);
                    int stringRepeat = int.Parse(firstLine[1]);

                    bool canBeDone = false;

                    string str = sr.ReadLine();
                    StringBuilder sb = new StringBuilder(stringLength * stringRepeat);
                    for (int s = 0; s < stringRepeat; s++)
                    {
                        sb.Append(str);
                    }
                    str = sb.ToString();

                    Quaternion currentQ = new Quaternion('1');
                    for (int i = 0; i < str.Length - 2; i++)
                    {
                        currentQ *= new Quaternion(str[i]);
                        if (currentQ.IsI)
                        {
                            iIndexes.Add(i);
                        }
                    }

                    currentQ = new Quaternion('1');
                    for (int i = str.Length - 1; i >= 2; i--)
                    {
                        currentQ = new Quaternion(str[i]) * currentQ;
                        if (currentQ.IsK)
                        {
                            kIndexes.Add(i);
                        }
                    }

                    

                    if (iIndexes.Count > 0 && kIndexes.Count > 0)
                    {
                        int firstI = iIndexes.Min();
                        int lastK = kIndexes.Max();

                        currentQ = Quaternion.One;
                        for (int i = firstI + 1; i < lastK; i++)
                        {
                            currentQ *= new Quaternion(str[i]);
                            if (currentQ.IsJ && kIndexes.Contains(i + 1))
                            {
                                canBeDone = true;
                                break;
                            }
                        }
                    }

                    output.Add(String.Format("Case #{0}: {1}", caseNum, canBeDone ? "YES" : "NO"));
                }
            }


            using (StreamWriter sw = File.CreateText(@"E:\My Documents\Google Drive\Coding\Google Code Jam\Google Code Jam\C-small-attempt0.out"))
            {
                foreach (var line in output)
                {
                    sw.WriteLine(line);
                }
            }
        }

        //private static bool CanMakeJ(string s, int start, int end)
        //{
        //    if (end - start < 2)
        //    {
        //        return false;
        //    }
        //    return ComputeQ(s.Substring(start, end - start)).IsJ;
        //}

        //private static Quaternion ComputeQ(string s)
        //{
        //    Quaternion currentQ = new Quaternion('1');
        //    foreach (var c in s)
        //    {
        //        currentQ *= new Quaternion(c);
        //    }
        //    return currentQ;
        //}

        private static void Test()
        {
            char[] values = {'1', 'i', 'j', 'k'};

            // Write Header
            Console.WriteLine("Print Grid");
            Console.WriteLine("\t1\ti\tj\tk");

            // Write grid
            for (int i = 0; i < 4; i++)
            {
                // Write row label
                Console.Write(values[i] + "\t");

                Quaternion left = new Quaternion(values[i]);
                for (int j = 0; j < 4; j++)
                {
                    Quaternion right = new Quaternion(values[j]);
                    Console.Write(left*right + "\t");
                }
                Console.WriteLine();
            }

            Console.WriteLine("Print Grid times negative");
            Console.WriteLine("\t1\ti\tj\tk");

            // Write grid
            Quaternion negative = new Quaternion('1', true);
            for (int i = 0; i < 4; i++)
            {
                // Write row label
                Console.Write(values[i] + "\t");

                Quaternion left = new Quaternion(values[i]);
                for (int j = 0; j < 4; j++)
                {
                    Quaternion right = new Quaternion(values[j]);
                    Console.Write(negative * left * right + "\t");
                }
                Console.WriteLine();
            }

            Console.ReadLine();
        }
    }
}
