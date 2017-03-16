using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace JamCoin
{
    class JamCoins
    {
        public bool[] binary_represenatation;
        public List<ulong> divisors;


        public JamCoins(bool[] BINARY)
        {
            binary_represenatation = new bool[BINARY.Length];
            BINARY.CopyTo(binary_represenatation, 0);
            this.divisors = new List<ulong>();
        }

        public ulong return_in_basis(int basis)
        {
            ulong result = 0;

            for(int i=0; i < binary_represenatation.Length;i++)
            {
                if (binary_represenatation[i])
                {
                    ulong potenz = 1;

                    for (int j = 0; j < i; j++)
                    {
                        potenz = potenz * Convert.ToUInt64(basis);
                    }

                    result += potenz;
                }

            }
            return result;

        }

    }

    class Program
    {
        static void Main(string[] args)
        {
            int N = 16;
            int J = 50;

            List<JamCoins> coins = new List<JamCoins>();

            //Create Jam Coins
            
            bool[] new_coin = new bool[N];

            new_coin[0] = true;
            new_coin[N - 1] = true;

            bool first_run = true;

            while (coins.Count < J)
            {
                int index = 1;

                if (!first_run)
                {
                    while (new_coin[index])
                    {
                        new_coin[index] = false;
                        index++;
                    }

                    new_coin[index] = true;
                }

                first_run = false;

                JamCoins new_jam_coin = new JamCoins(new_coin);

                bool is_jam_coin = true;

                List<ulong> D_list = new List<ulong>();

                for (int b = 2; b <= 10; b++)
                {
                    ulong D = 0;

                    Console.WriteLine(new_jam_coin.return_in_basis(b));
                    if (is_prime(new_jam_coin.return_in_basis(b), out D))
                    {
                        is_jam_coin = false;
                        break;
                    }
                    else
                    {
                        D_list.Add(D);
                    }
                }

                if (is_jam_coin)
                {
                    new_jam_coin.divisors = D_list;
                    coins.Add(new_jam_coin);
                }

                
            }

            StreamWriter output_writer = File.CreateText("output.txt");

            output_writer.WriteLine("Case #1:");

            foreach (JamCoins coin in coins)
            {
                string output_string = "";

                for (int i = N-1; i >= 0; i--)
                {
                    output_string += Convert.ToInt16(coin.binary_represenatation[i]).ToString();
                }

                for (int i = 0; i < 9; i++)
                {
                    output_string += " ";
                    output_string += coin.divisors[i].ToString();
                }
                output_writer.WriteLine(output_string);
            }

            output_writer.Close();

            Console.WriteLine("DONE");
            Console.ReadKey();


        }


        static bool is_prime(ulong number, out ulong divisor)
        {
            bool prime = true;

            divisor = 0;

            for (ulong i = 2; i < Math.Sqrt(number); i++)
            {
                if (number % i == 0)
                {
                    prime = false;
                    divisor = i;
                    break;
                }

            }

            return prime;
        }

    }
}
