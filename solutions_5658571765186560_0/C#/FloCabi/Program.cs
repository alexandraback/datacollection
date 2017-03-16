using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Ominous_Omino
{
    class Program
    {
        static void Main(string[] args)
        {
            string path = @"./input.txt";
            Boolean first = false;
            int textCase = 1;
            using (StreamWriter sw = new StreamWriter("out.out"))
            {
                using (StreamReader sr = new StreamReader(path))
                {
                    while (sr.Peek() > 0)
                    {
                        if (!first)
                        {
                            string data = sr.ReadLine();
                            first = true;
                            continue;
                        }
                        else
                        {
                            string data = sr.ReadLine();
                            string[] splitted = data.Split(' ');
                            Console.WriteLine(data);
                            string result = getResult(int.Parse(splitted[0]), int.Parse(splitted[1]), int.Parse(splitted[2]));
                            sw.WriteLine("Case #" + textCase++ + ": " + result);
                            Console.WriteLine("Case #" + (textCase - 1) + ": " + result);
                        }
                    }
                }
                sw.Close();
            }
            Console.Read();
        }


        static string getResult(int x, int r, int c)
        {
            if (x == 1)
            {
                return "GABRIEL";
            }
            if (x == 2){
                if ((r * c )% 2 == 0)
                    return "GABRIEL";
                else
                    return "RICHARD";
            }
            if ((r * c) % x == 0){
                for (int i = 1; i < x; i++)
                {
                    if ((double)i <= (double)( (double)x / 2))
                    {
                        if (r == i || c == i)
                        {
                            return "RICHARD";
                        }
                    }
                    else
                    {
                        return "GABRIEL";
                    }
                }
            }
            

            return "RICHARD";
        }

        
    }
}
