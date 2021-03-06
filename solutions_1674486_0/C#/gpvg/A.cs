using System;
using System.IO;

class Solution
{
    //put any globals here#
    //static string inputFilename = "test.in";
    //static string outputFilename = "test.out";
    static string inputFilename = "small.in";
    static string outputFilename = "small.out";
    static string workingDirectoryPath = "C:\\codejam\\2012\\R1C\\A\\";

    static string inputFile = workingDirectoryPath + inputFilename;
    static string outputFile = workingDirectoryPath + outputFilename;
    static StreamReader sr = new StreamReader(inputFile);

    public static void Main()
    {
        //call testHarness if required
        //testHarness();
        //reads one-time information from input file, especially number of test cases
        string line;
        line = sr.ReadLine();
        string[] values = line.Split(' ');
        int cases = int.Parse(values[0]);
        for (int c = 0; c < cases; c++)
        {
            //loop over all the cases
            runCase(c);
        }
    }

    private static void runCase(int c)
    {
        string answer = "Case #" + (c + 1).ToString() + ": ";

        //read input for this particular case
        string line;
        line = sr.ReadLine();
        string[] values = line.Split(' ');
        int N = int.Parse(values[0]);
        int[,] inheritance = new int[N, N];
        string[,] path = new string[N,N];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                inheritance[i, j] = 0;
                path[i,j] = "";
            }
        }
        for (int i = 0; i < N; i++)
        {
            line = sr.ReadLine();
            values = line.Split(' ');
            for (int j = 0; j < int.Parse(values[0]); j++)
            {
               inheritance[i, int.Parse(values[j+1]) - 1] = 1;
                path[i, int.Parse(values[j+1]) - 1] = ";"+j.ToString() + ";";
            }
        }
           
        int changing = 1;
        while (changing ==1)
        {
            changing = 0;
            for (int i = 0; i < N; i++)
            {
                for(int j = 0; j < N; j++)
                {
                    if (inheritance[i,j] == 1)
                    {
                        for (int k = 0; k < N; k++)
                        {
                            if (inheritance[j,k] ==1) 
                            {
                                if (inheritance[i, k] == 0)
                                {
                                    changing = 1;
                                    path[i, k] = path[i, j] + path[j, k];
                                    inheritance[i, k] = 1;
                                }
                                if (inheritance[i, k] == 1 && path[i, k] != path[i, j] + path[j, k]) changing = -1;
                               
                            }
                        }
                    }
                }
            }
        }
        if (changing == 0) answer = answer + "No";
        if (changing == -1) answer = answer + "Yes";
        //do some stuff to solve the problem


        //write the answer to the output file
        using (StreamWriter sw = new StreamWriter(outputFile, (c != 0)))
        {
            sw.WriteLine(answer);
        }
    }

    private static void testHarness()
    {
        //do whatever's needed to test things
        arbInt x = new arbInt("18000000");
        arbInt y = new arbInt("46");
        arbInt z = x.add(y);
        arbInt z3 = y.add(x);
        arbInt z2 = y.times(x);

        functions ab = new functions();
        Int64 [] prime1 = ab.findPrimes(0, 100);
        Int64 gcd = ab.lcm(18, 48);
        string a = z.OverToString();
        string b = z2.OverToString();
        string c = z3.OverToString();

    }
}
class functions
    {
        public Int64[] findPrimes(Int64 number, Int64 limit)
        {

            Int64[] primes = new Int64[Math.Max(number, limit / 2)];

            primes[0] = 2;
            Int64 count = 1;
            if (limit > 0)
            {
                int isprime = 1;
                for (Int64 i = 3; i < limit; i++)
                {
                    isprime = 1;
                    for (Int64 j = 0; j < count && primes[j] < Math.Sqrt(i)+1; j++)
                    {
                        if (i % primes[j] == 0) isprime = 0;
                    }
                    if (isprime == 1)
                    {
                        primes[count] = i;
                        count++;
                    }

                }
            }
            if (number > 0)
            {
                Int64 j = 2;
                int isprime = 1;
                while (count < number)
                {
                    j++;
                    isprime = 1;
                    for (Int64 i = 0; i < count && primes[i] < Math.Sqrt(j)+1; i++)
                    {
                        if (j % primes[i] == 0) isprime = 0;
                    }
                    if (isprime == 1)
                    {
                        primes[count] = j;
                        count++;
                    }
                }
            }
            return primes;
        }

        public Int64 gcd(Int64 a, Int64 b)
        {
            if (b > a)
            {
                Int64 c = b;
                b = a;
                a = c;
            }
            Int64 remainder = 100;
            while (remainder > 0)
            {
                remainder = a % b;
                a = b;
                b = remainder;

            }
            return a;
        }

        public Int64 lcm(Int64 a, Int64 b)
        {
            return (a * b) / gcd(a, b);
        }
    }
class arbInt
{
    static int size = 1000;
    static int scope = size * 2;
    private int[] components = new int[scope];
    public arbInt(string a)
    {
        char[] digits = a.ToCharArray();
        for (int i = 0; i < a.Length; i++)
        {
            this.components[a.Length - 1 - i] = int.Parse(digits[i].ToString());
        }
        for (int i = a.Length; i < scope; i++)
        {
            this.components[i] = 0;
        }
    }
    public arbInt(int[] comps)
    {
        for (int i = 0; i < comps.GetLength(0); i++)
        {
            this.components[i] = comps[i];
        }
        for (int i = comps.GetLength(0); i < scope; i++)
        {
            this.components[i] = 0;
        }
    }

    public arbInt add(arbInt b)
    {
        int[] comps = new int[scope];
        int med = 0;
        int carryover = 0;
        for (int i = 0; i < scope; i++)
        {
            med = components[i] + b.components[i] + carryover;
            comps[i] = med % 10;
            carryover = (med - comps[i])/10;
        }

        arbInt c = new arbInt(comps);
        return c;
    }

    public string OverToString()
{
    string a = "";
        for (int i = scope - 1; i > -1; i--)
        {
            a = a+ this.components[i].ToString();
        }
        while (a.StartsWith("0") && a.Length > 1)
        {
            a = a.Substring(1);
        }
        return a;
}

    public arbInt times(arbInt b)
    {
        int[] comps = new int[scope];
        for (int i = 0; i < scope; i++)
        {
            comps[i] = 0;
        }

        for (int j = 0; j < size; j++)
        {
            int med = 0;
            int carryover = 0;
            for (int i = 0; i < size; i++)
            {
                med = components[i] * b.components[j] + carryover + comps[i+j];
                comps[i+j] = med % 10;
                carryover = (med - comps[i+j]) / 10;
            }
        }

        arbInt c = new arbInt(comps);
        return c;
    }


}





