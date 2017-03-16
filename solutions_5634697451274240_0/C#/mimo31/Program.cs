using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace JamPancakes
{
    class Program
    {
        const string INPUT_PATH = "D:\\CodeJam\\input.in";
        const string OUTPUT_PATH = "D:\\CodeJam\\output.txt";

        static void Main(string[] args)
        {
            FileStream inputStream = new FileStream(INPUT_PATH, FileMode.Open);
            TextReader reader = new StreamReader(inputStream);
            int[] results = new int[int.Parse(reader.ReadLine())];
            for (int i = 0; i < results.Length; i++)
            {
                string readLine = reader.ReadLine();
                bool[] stack = new bool[readLine.Length];
                for (int j = 0; j < stack.Length; j++)
                {
                    stack[j] = readLine[j] == '+';
                }
                results[i] = countFlips(stack);
            }
            reader.Close();
            inputStream.Close();
            FileStream outputStream = new FileStream(OUTPUT_PATH, FileMode.Create);
            TextWriter writer = new StreamWriter(outputStream);
            for (int i = 0; i < results.Length; i++)
            {
                writer.WriteLine("Case #" + (i + 1).ToString() + ": " + results[i].ToString());
            }
            writer.Close();
            outputStream.Close();
        }

        static void flipPancakes(bool[] stack, int depth)
        {
            bool[] oldCopy = new bool[depth];
            for (int i = 0; i < depth; i++)
            {
                oldCopy[i] = stack[i];
            }
            for (int i = 0; i < depth; i++)
            {
                stack[i] = !oldCopy[depth - 1 - i];
            }
        }

        static bool isOk(bool[] stack)
        {
            for (int i = 0; i < stack.Length; i++)
            {
                if (stack[i] == false)
                {
                    return false;
                }
            }
            return true;
        }

        static int countFlips(bool[] stack)
        {
            int flips = 0;
            int pancakesResolved = 0;
            while (pancakesResolved != stack.Length)
            {
                if (!stack[stack.Length - 1 - pancakesResolved])
                {
                    if (stack[0])
                    {
                        int depth = 0;
                        while (stack[depth])
                        {
                            depth++;
                        }
                        flipPancakes(stack, depth);
                        flipPancakes(stack, stack.Length - pancakesResolved);
                        flips += 2;
                    }
                    else
                    {
                        flipPancakes(stack, stack.Length - pancakesResolved);
                        flips++;
                    }
                }
                else
                {
                    for (int i = stack.Length - 1; i >= 0; i--)
                    {
                        if (stack[i])
                        {
                            pancakesResolved = stack.Length - i;
                        }
                        else
                        {
                            break;
                        }
                    }
                }
            }
            return flips;
        }
    }
}
