using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Codejam2014.R1B
{
    class Program
    {
        static void Main(string[] args)
        {
            string sampleName = "small2";
            string sampleDir = Path.GetDirectoryName(Path.GetDirectoryName(Path.GetDirectoryName(AppDomain.CurrentDomain.BaseDirectory))) + "\\";
            string iFilePath = sampleDir + sampleName + ".i.txt";
            string oFilePath = sampleDir + sampleName + ".o.txt";
            string cFilePath = sampleDir + sampleName + ".c.txt";

            string[] iLines = File.ReadAllLines(iFilePath);
            List<string> oLines = new List<string>();

            int lineCnt = 0;
            int sampleCnt = int.Parse(iLines[lineCnt++]);

            List<string> sampleList = new List<string>();
            for (int sampleIdx = 0; sampleIdx < sampleCnt; sampleIdx++)
            {
                lineCnt++;
                string s = iLines[lineCnt++];
                sampleList.Add(s);
            }

            for (int sampleIdx = 0; sampleIdx < sampleCnt; sampleIdx++)
            {
                String sample = sampleList[sampleIdx];

                bool pass = true;

                Dictionary<char, int> item1List = new Dictionary<char, int>();
                Dictionary<string, int> item2List = new Dictionary<string, int>();
                List<char> usedCharList = new List<char>();
                foreach (string item in sample.Split(new char[] { ' ' }))
                {
                    char[] charItem = item.ToCharArray();

                    List<char> addCharList = new List<char>();
                    char prev = ' ';
                    foreach (char c in charItem)
                    {
                        if ( c != prev ) addCharList.Add(c);
                        prev = c;
                    }
                    
                    List<char> charList = charItem.Distinct().ToList();
                    if (charList.Count != charList.Count)
                    {
                        pass = false;
                    }

                    if (charList.Count == 1)
                    {
                        if (!item1List.ContainsKey(charList[0])) item1List[charList[0]] = 1;
                        else item1List[charList[0]]++;

                        usedCharList.Add(charList[0]);
                    }
                    else if (charList.Count >= 2)
                    {
                        char first = charList.First();
                        char last = charList.Last();
                        List<char> newInChar = new List<char>();


                        foreach (char c in charList)
                        {
                            if (c == first) continue;
                            if (c == last) continue;
                            newInChar.Add(c);
                        }
                        newInChar = newInChar.ToList();

                        if (usedCharList.Intersect(newInChar).Count() > 0)
                        {
                            pass = false;
                        }
                        else
                        {
                            usedCharList.AddRange(charList);
                        }
                        string uStr = string.Join("", charList);
                        if (!item2List.ContainsKey(uStr)) item2List[uStr] = 1;
                        else item2List[uStr]++;
                    }
                }

                if (pass)
                {
                    char[] cList = item1List.Keys.ToArray();
                    string[] sList = item2List.Keys.ToArray();
                    foreach (char c in cList)
                    {
                        foreach (string s in sList)
                        {
                            //
                            if (!item1List.ContainsKey(c)) continue;
                            char c1 = s.First();
                            char c2 = s.Last();

                            if (c1 == c || c2 == c)
                            {
                                int cCnt = item1List[c];
                                int sCnt = item2List[s];
                                item1List.Remove(c);
                                item2List[s] = cCnt * sCnt;
                                continue;
                            }
                        }
                    }
                }

                int nTotal = 1;
                while (true)
                {
                    string[] s1List = item2List.Keys.ToArray();
                    string[] s2List = item2List.Keys.ToArray();

                    bool found = false;
                    foreach (string s1 in s1List)
                    {
                        foreach (string s2 in s2List)
                        {
                            if (s1 == s2) continue;
                            char c1 = s1.First();
                            char c2 = s1.Last();
                            char c3 = s2.First();
                            char c4 = s2.Last();
                            if (c1 == c3 && c3 != c4)
                            {
                                pass = false;
                                found = true;
                                break;
                            }
                            else if (c1 != c3 && c3 == c4)
                            {
                                pass = false;
                                found = true;
                                break;
                            }
                            else if (c2 == c3 && c1 == c4)
                            {
                                pass = false;
                                found = true;
                                break;
                            }
                            else if (c2 == c3)
                            {
                                int s1Cnt = item2List[s1];
                                int s2Cnt = item2List[s2];
                                item2List.Remove(s1);
                                item2List.Remove(s2);
                                item2List[s1 + s2] = s1Cnt * s2Cnt;
                                found = true;
                                break;
                            }
                        }
                        if (found) break;
                    }

                    if (!found)
                    {
                        foreach (int cnt in item2List.Values) {
                            nTotal *= cnt;
                        }
                        break;
                    }
                    if (!pass) break;
                }
                if ( !pass ) nTotal = 0;

                foreach (int cnt in item1List.Values)
                {
                    nTotal *= cnt;
                }
                int factorial = 1;
                for (int i = item2List.Count + item1List.Count; i > 0; i--)
                {
                    factorial *= i;
                }
                nTotal *= factorial;
                 

                oLines.Add(string.Format("Case #{0}: {1}", sampleIdx + 1, nTotal));
            }
            File.WriteAllLines(oFilePath, oLines);

            if (File.Exists(cFilePath))
            {
                string[] cLines = File.ReadAllLines(cFilePath);
                for (int sampleIdx = 0; sampleIdx < sampleCnt; sampleIdx++)
                {
                    string oLine = oLines[sampleIdx];
                    string cLine = cLines[sampleIdx];

                    if (oLine != cLine)
                    {
                        throw new Exception("not match");
                    }
                }
            }
        }
    }
}
