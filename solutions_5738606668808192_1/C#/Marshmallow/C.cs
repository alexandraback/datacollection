

using System;
using System.Collections.Generic;
using System.IO;
using System.Numerics;

class C
{
    // Things that get used a lot
    int N;
    int J;
    BigInteger limit;
    List<int> primes;
    int primesToTry = 10;

    public void Solve()
    {
        StreamReader reader = new StreamReader("C_in.txt");
        StreamWriter writer = new StreamWriter("C_out.txt");

        int T = Int32.Parse(reader.ReadLine());
        LoadPrimes();

        for (int t = 0; t < T; t++)
        {
            writer.WriteLine("Case #{0}:", (t + 1));
            Console.WriteLine("Case #{0}:", (t + 1));

            string[] line = reader.ReadLine().Split();
            N = Int32.Parse(line[0]);
            J = Int32.Parse(line[1]);
            limit = Pow(2, N - 2);

            for (BigInteger middle = 0; middle < limit; middle++)
            {
                string jam = GetJamString(middle);
                //Console.WriteLine(jam);

                List<int> divisors = new List<int>();
                int divisor;
                bool possibleJamcoin = true;

                for (int b = 2; b <= 10; b++)
                {
                    BigInteger rep = GetRepresentation(jam, b);
                    //Console.WriteLine("\t" + rep);
                    if (isPrime(rep, out divisor))
                    {
                        possibleJamcoin = false;
                        break;
                    }
                    else divisors.Add(divisor);
                }

                if (possibleJamcoin)
                {
                    // Write it down...
                    string s = jam;
                    foreach (int div in divisors) s += " " + div;
                    writer.WriteLine(s);
                    Console.WriteLine(s);

                    J -= 1;
                    if (J == 0) break;
                }
            }
        }

        reader.Close();
        writer.Close();
    }

    bool isPrime(BigInteger rep, out int divisor)
    {
        for (int i = 0; i < primesToTry; i++)
        {
            if (rep % primes[i] == 0)
            {
                divisor = primes[i];
                return false;
            }
        }

        divisor = 0;
        return true;
    }

    BigInteger GetRepresentation(string jamcoin, int baseUsed)
    {
        BigInteger multiplier = 1;
        BigInteger number = 0;
        for (int i = jamcoin.Length - 1; i >= 0; i--)
        {
            if (jamcoin[i] == '1') number += multiplier;
            multiplier *= (BigInteger)baseUsed;
        }
        return number;
    }

    BigInteger Pow(int n, int index)
    {
        BigInteger power = 1;
        for (int i = 0; i < n; i++)
        {
            power *= index;
        }
        return power;
    }

    string GetJamString(BigInteger middle)
    {
        char[] jam = new char[N];

        // First and last
        jam[0] = '1';
        jam[N-1] = '1';

        // Then middle
        for (int i = N - 2; i >= 1; i--)
        {
            if (middle % 2 == 1) jam[i] = '1';
            else jam[i] = '0';

            middle /= 2;
        }

        return new string(jam);
    }

    void LoadPrimes()
    {
        primes = new List<int>();
        string[] fileContents = File.ReadAllLines("primes.txt");
        foreach (string line in fileContents)
        {
            string[] split = line.Split();
            foreach (string s in split)
            {
                if (s != "") primes.Add(Int32.Parse(s));
            }
        }
    }




}