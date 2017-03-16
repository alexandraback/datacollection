using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;

namespace google_cookie
{
    class Program
    {
        static void Main(string[] args)
        {
            StreamWriter writer = new StreamWriter("result.txt");
            using (StreamReader reader = new StreamReader("B-small-attempt0.in"))
            {
                int numGames = Int32.Parse(reader.ReadLine());

                for (int i = 0; i < numGames; i++)
                {
                    // read in pattern
                    Double[] cookieData = reader.ReadLine().Split(' ').Select(Double.Parse).ToArray();

                    // calculate game
                    string result = "Case #" + (i + 1).ToString() + ": " + DayIGotCookie(cookieData[0], cookieData[1], cookieData[2]);
                    writer.WriteLine(result);
                }
            }

            writer.Close();
        }

        static string DayIGotCookie(Double c, Double f, Double x)
        {
            Double result = 0;

            // cookie stuff
            Double curProd = 2; // default rate = 2 per second
            Double timeToReachCurProd = 0;
            while (true)
            {
                Double timeToBuyNewFarm = c / curProd;
                Double winTimeAtCurProd = x / curProd;
                Double winTimeWithNewFarm = (x / (curProd + f)) + timeToBuyNewFarm;

                if (winTimeAtCurProd > winTimeWithNewFarm)
                {
                    // buy a new farm
                    timeToReachCurProd += timeToBuyNewFarm;
                    curProd += f;
                }
                else
                {
                    result = timeToReachCurProd + winTimeAtCurProd;
                    break;
                }
            }

            return String.Format("{0:0.0000000}", result);
        }
    }
}
