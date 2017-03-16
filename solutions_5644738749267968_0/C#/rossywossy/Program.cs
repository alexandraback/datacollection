using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Deceitful_War
{
    class Program
    {
        static void Main(string[] args)
        {
            int T, numWeights;
            int regularWar, deceitfulWar;
            List<float> naomiWeights = new List<float>();
            List<float> kenWeights = new List<float>();

            int.TryParse(Console.ReadLine(), out T);

            for (int i = 0; i < T; i++)
            {
                // Input & Setup
                naomiWeights.Clear();
                kenWeights.Clear();
                regularWar = 0;
                deceitfulWar = 0;
                
                int.TryParse(Console.ReadLine(), out numWeights);

                // Naomi's weights
                string[] tokens = Console.ReadLine().Split();

                for (int j = 0; j < tokens.Length; j++)
                {
                    float temp;
                    float.TryParse(tokens[j], out temp);
                    naomiWeights.Add(temp);
                }
                    

                // Ken's weights
                tokens = Console.ReadLine().Split();

                for (int j = 0; j < tokens.Length; j++)
                {
                    float temp;
                    float.TryParse(tokens[j], out temp);
                    kenWeights.Add(temp);
                }

                List<float> naomiCopy = new List<float>(naomiWeights);
                List<float> kenCopy = new List<float>(kenWeights);

                // Find war victories
                regularWar = War(naomiCopy, kenCopy);

                // Find deceitful war victories
                deceitfulWar = DeceitfulWar(naomiWeights, kenWeights);

                Console.WriteLine("Case #" + (i + 1) + ": " + deceitfulWar + " " + regularWar);

            }
        }

        static int War(List<float> p1, List<float> p2)
        {
            int victories = 0;
            float p1Move = -1, p2Move = -1;

            // Sort p1 & p2 from lowest to highest
            p1.Sort();
            p2.Sort();

            for (int i = p1.Count(); i > 0; i--)
            {
                // Player 1 will always play the highest number
                p1Move = p1[p1.Count() - 1];
                p1.Remove(p1Move);

                bool canWin = false;

                for (int j = 0; j < p2.Count(); j++)
                {
                    // If player 2 can beat player 1's number, he will win with the lowest number possible
                    if (p2[j] > p1Move)
                    {
                        p2Move = p2[j];
                        p2.Remove(p2Move);
                        canWin = true;
                        break;
                    }
                }

                // If player 2 is going to lose, he will lose with the lowest number possible
                if (!canWin)
                {
                    p2Move = p2[0];
                    p2.Remove(p2Move);
                    victories++;
                }
            }

            return victories;
        }

        static int DeceitfulWar(List<float> p1, List<float> p2)
        {
            int victories = 0;
            float p1Move = -1, p2Move = -1;

            p1.Sort();
            p2.Sort();

            for (int i = p1.Count(); i > 0; i--)
            {
                // Go through your nums from lowest to highest
                p1Move = p1[0];
                p1.Remove(p1Move);

                // If your lowest is lower than all of your opponents,
                bool isLowerThanAllOfOpponents = true;

                for (int k = 0; k < p2.Count(); k++)
                {
                    if (p2[k] < p1Move)
                        isLowerThanAllOfOpponents = false;
                }

                if (isLowerThanAllOfOpponents)
                {   // Then use it to eliminate your opponents highest.
                    p2Move = p2[p2.Count - 1];
                    p2.Remove(p2Move);
                    continue;
                }

                // Else, use your lowest to eliminate the highest of your opponents that it can
                for (int k = p2.Count() - 1; k >= 0; k--)
                {
                    if (p2[k] < p1Move)
                    {
                        p2Move = p2[k];
                        p2.Remove(p2Move);
                        victories++;
                        break;
                    }
                }
            }

            return victories;
        }
    }
}
