using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Cookie_Clicker_Alpha
{
    class Program
    {
        static void Main(string[] args)
        {
            int T;
            double currentCookiesPerSecond, time;
            double farmPrice, cookiesPerSecond, cookieGoal;

            int.TryParse(Console.ReadLine(), out T);

            for (int i = 0; i < T; i++)
            {
                string[] tokens = Console.ReadLine().Split();
                currentCookiesPerSecond = 2;
                time = 0;

                double.TryParse(tokens[0], out farmPrice);
                double.TryParse(tokens[1], out cookiesPerSecond);
                double.TryParse(tokens[2], out cookieGoal);

                double timeToGoalWithoutFarm = cookieGoal / currentCookiesPerSecond;
                double timeToGetFarm = farmPrice / currentCookiesPerSecond;
                double timeToGoalWithFarm = (cookieGoal / (currentCookiesPerSecond + cookiesPerSecond)) + timeToGetFarm;

                while (timeToGoalWithFarm < timeToGoalWithoutFarm)
                {
                    time += timeToGetFarm;
                    currentCookiesPerSecond += cookiesPerSecond;

                    timeToGoalWithoutFarm = cookieGoal / currentCookiesPerSecond;
                    timeToGetFarm = farmPrice / currentCookiesPerSecond;
                    timeToGoalWithFarm = (cookieGoal / (currentCookiesPerSecond + cookiesPerSecond)) + timeToGetFarm;
                }

                time += timeToGoalWithoutFarm;

                Console.WriteLine("Case #" + (i + 1) + ": " + time);
            }
        }

        static float TimeToGetToGoal (float fPrice, float cPs, float goal)
        {
            float result = 0f;

            result += cPs * TimeToGetToGoal(fPrice, cPs, fPrice);

            return result;
        }
    }
}
