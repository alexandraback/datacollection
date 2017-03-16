using System.Globalization;

namespace FairAndSquare
{
    using System;
    using System.IO;
    using System.Linq;

    class Program
    {
        static void Main(string[] args)
        {
            using (var reader = new StreamReader(args[0] + ".in"))
            using (var writer = new StreamWriter(args[0] + ".out"))
            {
                int T = Int32.Parse(reader.ReadLine());
                for (int x = 1; x <= T; ++x)
                {
                    int y = 0;

                    var range = reader.ReadLine().Split(' ').Select(Int32.Parse).ToArray();

                    int start = (int)Math.Ceiling(Math.Sqrt(range[0]));
                    int end = (int)Math.Floor(Math.Sqrt(range[1]));

                    for (var i = start; i <= end; ++i)
                    {
                        if (IsPalidrome(i) && IsPalidrome(i * i))
                        {
                            ++y;
                        }
                    }

                    Console.WriteLine("Case #{0}: {1}", x, y);
                    writer.WriteLine("Case #{0}: {1}", x, y);
                }

                writer.Close();
            }
        }

        static bool IsPalidrome(int n)
        {
            string number = n.ToString(CultureInfo.InvariantCulture);
            for (int i = 0; i <= number.Length / 2; ++i)
            {
                if (number[i] != number[number.Length - i - 1])
                    return false;
            }

            return true;
        }
    }
}
