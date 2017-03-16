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
        public int[] divisors;

        public JamCoins(bool[] BINARY)
        {
            binary_represenatation = new bool[BINARY.Length];
            BINARY.CopyTo(binary_represenatation, 0);
            this.divisors = new int[9];
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            int N = 32;
            int J = 500;

            int number_of_divisors_to_check = 100000;

            List<JamCoins> coins = new List<JamCoins>();

            //Create Jam Coins
            
            bool[] new_coin = new bool[N];

            new_coin[0] = true;
            new_coin[N - 1] = true;

           
            while (coins.Count < J)
            {
                Console.WriteLine(coins.Count);
                int index = 1;
                
                while (new_coin[index])
                {
                    new_coin[index] = false;
                    index++;
                }

                new_coin[index] = true;

                JamCoins new_jam_coin = new JamCoins(new_coin);

                bool is_jam_coin = true;

                int[] D_list = new int[9];

                for (int b = 2; b <= 10; b++)
                {
                    bool divisor_found = false;
                    int divisor = 0;

                    for (int z = 2; z <= number_of_divisors_to_check; z++)
                    {
                        int[] rest = new int[32];

                        for (int r_counter = 0; r_counter < 32; r_counter++)
                        {
                            if (new_coin[r_counter])
                            {
                                int mod_val = 1;

                                for (int pot = 0; pot < r_counter; pot++)
                                {
                                    mod_val = (mod_val * b) % z;
                                }

                                rest[r_counter] = mod_val % z;
                            }
                        }


                        if (rest.Sum() % z == 0)
                        {
                            divisor = z;
                            divisor_found = true;
                            break;
                        }
                    }

                    if (divisor_found)
                    {
                        D_list[b - 2] = divisor;
                    }
                    else
                    {
                        is_jam_coin = false;
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
    }
}
