using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.IO;

namespace FacebookHackerCup2012
{
    class KingdomRush
    {
        public KingdomRush()
        {
            int cases;
            string line;
            string[] lineparts;

            // Read the file and display it line by line.
            StreamReader file = new StreamReader("kingdomrush.txt");
            StreamWriter output = new StreamWriter("kingdomrushoutput.txt");
            cases = Convert.ToInt32(file.ReadLine());
            for (int i = 0; i < cases; i++)
            {
                line = file.ReadLine();
                int levels = Convert.ToInt32(line);
                int []oneStars = new int[levels];
                int []twoStars = new int[levels];
                List<KeyValuePair<int, int>> oneStar = new List<KeyValuePair<int, int>>();
                List<KeyValuePair<int, int>> twoStar = new List<KeyValuePair<int, int>>();
                bool[] oneComplete = new bool[levels];
                bool[] twoComplete = new bool[levels];
                for (int j = 0; j < levels; j++)
                {
                    line = file.ReadLine();
                    lineparts = line.Split(' ');
                    oneStar.Add(new KeyValuePair<int,int>(j,Convert.ToInt32(lineparts[0])));
                    twoStar.Add(new KeyValuePair<int,int>(j,Convert.ToInt32(lineparts[1])));
                    oneStars[j] = Convert.ToInt32(lineparts[0]);
                    twoStars[j] = Convert.ToInt32(lineparts[1]);
                }
                oneStar.Sort(delegate(KeyValuePair<int, int> x, KeyValuePair<int, int> y) { return x.Value.CompareTo(y.Value); });
                twoStar.Sort(delegate(KeyValuePair<int, int> x, KeyValuePair<int, int> y) { return x.Value.CompareTo(y.Value); });
                int stars = 0;
                bool continu = true;
                bool completedLevel = false;
                int levelscompleted = 0;
                KeyValuePair<int, int> kp;
                int lastvalue;
                int pairvalue;
                KeyValuePair<int,int> kpToUse;
                while(stars < (levels*2) && continu)
                {
                    lastvalue = -1;
                    pairvalue = -1;
                    continu = false;
                    completedLevel = false;
                    for (int j = 0; j < twoStar.Count;j++)
                    {
                        kp = twoStar[j];
                        if (!twoComplete[kp.Key] && stars >= kp.Value)
                        {
                            if(!oneComplete[kp.Key]){
                                stars++;
                                oneComplete[kp.Key] = true;
                            }
                            stars++;
                            twoComplete[kp.Key] = true;
                            completedLevel = true;
                            continu = true;
                            levelscompleted++;
                            break;
                        }
                    }
                    if (!completedLevel)
                    {
                        for (int j = 0; j < oneStar.Count; j++)
                        {
                            kp = oneStar[j];
                            if (!oneComplete[kp.Key] && stars >= kp.Value)
                            {
                                while ((j != oneStar.Count - 1) && kp.Value == oneStar[j + 1].Value)
                                {
                                    if (twoStars[kp.Key] < twoStars[oneStar[j + 1].Key])
                                        kp = oneStar[j + 1];

                                    j++;
                                }
                                stars++;
                                oneComplete[kp.Key] = true;
                                completedLevel = true;
                                levelscompleted++;
                                continu = true;
                                oneStar.RemoveAt(j);
                                break;
                            }
                        }
                    }
                }
                if (stars != levels * 2) output.WriteLine("Case #" + (i + 1) + ": Too Bad");
                else output.WriteLine("Case #" + (i + 1) + ": "+levelscompleted);
            }

            file.Close();
            output.Close();
        }

        public static void Main(string[] args)
        {
            KingdomRush k = new KingdomRush();
        }
    }
}
