using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Numerics;
using System.IO;

namespace JamCoins
{
    class Program
    {
        const string INPUT_PATH = "D:\\CodeJam\\input.in";
        const string OUTPUT_PATH = "D:\\CodeJam\\output.txt";

        static void Main(string[] args)
        {
            FileStream inputStream = new FileStream(INPUT_PATH, FileMode.Open);
            TextReader reader = new StreamReader(inputStream);
            int[,] inputs = new int[int.Parse(reader.ReadLine()), 2];
            for (int i = 0; i < inputs.GetLength(0); i++)
            {
                string readLine = reader.ReadLine();
                string[] chunks = readLine.Split(' ');
                inputs[i, 0] = int.Parse(chunks[0]);
                inputs[i, 1] = int.Parse(chunks[1]);
            }
            reader.Close();
            inputStream.Close();
            FileStream outputStream = new FileStream(OUTPUT_PATH, FileMode.Create);
            TextWriter writer = new StreamWriter(outputStream);
            for (int i = 0; i < inputs.GetLength(0); i++)
            {
                Tuple<bool[], int[]>[] jamcoins = getJamcoins(inputs[i, 0], inputs[i, 1]);
                writer.WriteLine("Case #" + (i + 1).ToString() + ":");
                for (int j = 0; j < inputs[i, 1]; j++)
                {
                    StringBuilder resultBuilder = new StringBuilder();
                    resultBuilder.Append(getJamcoinString(jamcoins[j].Item1));
                    for (int k = 0; k < 9; k++)
                    {
                        resultBuilder.Append(" ");
                        resultBuilder.Append(jamcoins[j].Item2[k].ToString());
                    }
                    writer.WriteLine(resultBuilder.ToString());
                }
            }
            writer.Close();
            outputStream.Close();
        }

        static string getJamcoinString(bool[] array)
        {
            char[] chars = new char[array.Length];
            for (int i = 0; i < chars.Length; i++)
            {
                chars[i] = array[i] ? '1' : '0';
            }
            return new string(chars);
        }

        static int getFactor(BigInteger n, int maxFactor)
        {
            if (n % 2 == 0)
            {
                return 2;
            }
            maxFactor = (n < maxFactor) ? (int)(n - 1) : maxFactor;
            for (int i = 3; i <= maxFactor; i += 2)
            {
                if (n % i == 0)
                {
                    return i;
                }
            }
            return 0;
        }

        static Tuple<bool[], int[]>[] getJamcoins(int coinLength, int coinCount)
        {
            Tuple<bool[], int[]>[] coins = new Tuple<bool[], int[]>[coinCount];
            bool[] currentCoin = new bool[coinLength];
            currentCoin[0] = true;
            currentCoin[coinLength - 1] = true;
            int coinsFound = 0;
            while (coinsFound != coinCount)
            {
                int lastZero = currentCoin.Length - 1;
                while (currentCoin[lastZero])
                {
                    lastZero--;
                }
                currentCoin[lastZero] = true;
                for (int i = lastZero + 1; i < currentCoin.Length - 1; i++)
                {
                    currentCoin[i] = false;
                }
                int[] factors = new int[9];
                for (int i = 2; i <= 10; i++)
                {
                    BigInteger currentRepresentation = 0;
                    for (int j = 0; j < currentCoin.Length; j++)
                    {
                        if (currentCoin[j])
                        {
                            currentRepresentation += BigInteger.Pow(i, currentCoin.Length - j - 1);
                        }
                    }
                    int factor = getFactor(currentRepresentation, 1000000);
                    if (factor == 0)
                    {
                        break;
                    }
                    else
                    {
                        factors[i - 2] = factor;
                    }
                }
                if (factors[factors.Length - 1] != 0)
                {
                    bool[] arrayCopy = new bool[coinLength];
                    currentCoin.CopyTo(arrayCopy, 0);
                    coins[coinsFound] = new Tuple<bool[], int[]>(arrayCopy, factors);
                    coinsFound++;
                }
            }
            return coins;
        }
    }
}
