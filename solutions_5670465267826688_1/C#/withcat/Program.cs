using System;
using System.Linq;

class Program
{
    static void Main(string[] args)
    {
        var T = int.Parse(Console.ReadLine());
        for (var t = 0; t < T; t++)
        {
            var r1 = Console.ReadLine().Split().Select(long.Parse).ToArray();
            var L = r1[0];
            var X = r1[1];
            var str = Console.ReadLine().ToCharArray();

            var step = 0;
            var curr = ' ';
            var sign = 1;
            for (var x = 0; x < X; x++)
            {
                for (var i = 0; i < L; i++)
                {
                    if (curr == '1')
                    {
                        curr = str[i];
                    }
                    else if (curr == 'i')
                    {
                        if (str[i] == '1')
                        {
                            curr = 'i';
                        }
                        else if (str[i] == 'i')
                        {
                            curr = '1';
                            sign *= -1;
                        }
                        else if (str[i] == 'j')
                        {
                            curr = 'k';
                        }
                        else if (str[i] == 'k')
                        {
                            curr = 'j';
                            sign *= -1;
                        }
                    }
                    else if (curr == 'j')
                    {
                        if (str[i] == '1')
                        {
                            curr = 'j';
                        }
                        else if (str[i] == 'i')
                        {
                            curr = 'k';
                            sign *= -1;
                        }
                        else if (str[i] == 'j')
                        {
                            curr = '1';
                            sign *= -1;
                        }
                        else if (str[i] == 'k')
                        {
                            curr = 'i';
                        }
                    }
                    else if (curr == 'k')
                    {
                        if (str[i] == '1')
                        {
                            curr = 'k';
                        }
                        else if (str[i] == 'i')
                        {
                            curr = 'j';
                        }
                        else if (str[i] == 'j')
                        {
                            curr = 'i';
                            sign *= -1;
                        }
                        else if (str[i] == 'k')
                        {
                            curr = '1';
                            sign *= -1;
                        }
                    }
                    else
                    {
                        curr = str[i];
                    }

                    if (step == 0 && curr == 'i')
                    {
                        curr = ' ';
                        step = 1;
                    }
                    else if (step == 1 && curr == 'j')
                    {
                        curr = ' ';
                        step = 2;
                    }
                }
            }

            var ans = "NO";
            if (sign == 1 && step == 2 && curr == 'k')
            {
                ans = "YES";
            }
            Console.WriteLine("Case #{0}: {1}", t + 1, ans);
        }
    }
}
