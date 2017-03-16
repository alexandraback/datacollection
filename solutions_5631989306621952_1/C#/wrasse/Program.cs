using System;

namespace _2016_1A_A
{
    class Program
    {
        static void Main()
        {
            var input = Console.ReadLine();
            var caseCount = int.Parse(input);

            for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++)
            {
                input = Console.ReadLine();

                string output = "";
                char highest = ' ';
                foreach (char c in input)
                {
                    if (output == "")
                    {
                        output = output + c;
                        highest = c;
                    }
                    else
                    {
                        char firstChar = Convert.ToChar(output.Substring(0, 1));
                        if (Convert.ToInt32(c) >= Convert.ToInt32(highest))
                        {
                            output = c + output;
                            highest = c;
                        }
                        else
                        {
                            output = output + c;
                        }
                    }
                }

                Console.WriteLine($"Case #{caseNumber}: {output}");
            }
        }
    }
}
