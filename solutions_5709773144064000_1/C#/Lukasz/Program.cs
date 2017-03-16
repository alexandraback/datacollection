using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Globalization;

namespace Round_Q_Task_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int numberOfCases = int.Parse(Console.ReadLine());

            for (int i = 1; i <= numberOfCases; ++i)
            {
                string line = Console.ReadLine();
                string[] valuesStrings = line.Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);

                if (valuesStrings.Length != 3)
                {
                    throw new FormatException("Invalid input format.");
                }

                decimal C = decimal.Parse(valuesStrings[0], CultureInfo.InvariantCulture);
                decimal F = decimal.Parse(valuesStrings[1], CultureInfo.InvariantCulture);
                decimal X = decimal.Parse(valuesStrings[2], CultureInfo.InvariantCulture);

                string caseOutput = string.Format("Case #{0}: {1}", i, SolveCase(C, F, X).ToString("N7", CultureInfo.InvariantCulture).Replace(",",""));
                Console.WriteLine(caseOutput);
            }
        }

        private static decimal SolveCase(decimal farmCost, decimal farmExtraSpeed, decimal totalCookiesToWin)
        {
            decimal currentSpeed = 2.0m;
            decimal farmWaitingTime = 0.0m;

            while (ShouldBuyFarm(farmCost, farmExtraSpeed, totalCookiesToWin, currentSpeed))
            {
                farmWaitingTime += farmCost / currentSpeed;

                currentSpeed += farmExtraSpeed;
            }

            return farmWaitingTime + (totalCookiesToWin/currentSpeed);
        }

        private static bool ShouldBuyFarm(decimal farmCost, decimal farmExtraSpeed, decimal totalCookiesToWin, decimal currentSpeed)
        {
            decimal timeLeft = totalCookiesToWin / currentSpeed;

            decimal timeWithFarmBought = (farmCost / currentSpeed) + (totalCookiesToWin / (currentSpeed + farmExtraSpeed));

            return timeWithFarmBought < timeLeft;
        }
    }
}
