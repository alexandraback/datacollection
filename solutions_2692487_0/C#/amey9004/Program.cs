using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace codejam
{
    using System.Numerics;

    class Program
    {
        static void Main(string[] args)
        {
            Execute3();
            //var ret = sizeKPalindromes(new List<char>() { '0', '1', '2' }, 2);
            // ret.ForEach(t => Console.WriteLine(t));
        }

        private static void Execute3()
        {
            int t = int.Parse(Console.ReadLine());
            int count = t;
            while (t > 0)
            {
                t--;
                var lim = Console.ReadLine().Split().ToList();
                long A = long.Parse(lim[0]);
                long N = long.Parse(lim[1]);
                long op = 0;
                bool ret = false;
                var input = Console.ReadLine().Split().ToList();
                var step = new List<int>();
                var array = new List<int>();
                input.ForEach(r => array.Add(int.Parse(r)));
                array.Sort();
                while (array.Any() && op < N)
                {
                    int temp = 0;
                    if (A > array[0])
                    {
                        A += array[0];
                        step.Add(temp);
                    }
                    else
                    {
                        while (A <= array[0] && temp < array.Count)
                        {
                            A += A - 1;
                            temp++;
                        }

                        if (temp < array.Count)
                        {
                            A += array[0];
                            op += temp;
                            step.Add(temp);
                        }
                        else
                        {
                            step.Reverse();
                            int c = 0;
                            for(int i = 0; i < step.Count; i++)
                            {
                                c += step[i];
                                if (c > i)
                                {
                                    c = 0;
                                    for (int j = 0; j <= i; j++) step[j] = 1;
                                }
                            }

                            op = array.Count;
                            step.ForEach(ti => op+=ti);
                        }
                    }

                    array.RemoveAt(0);
                }

                if (op < N)
                {
                    Console.WriteLine("Case #" + (count - t) + ": " + op);
                }
                else
                {
                    Console.WriteLine("Case #" + (count - t) + ": " + N);
                }
            }
        }

        public static List<String> sizeKPalindromes(List<Char> charSet, int size)
        {
            bool odd = (size % 2 > 0) ? true : false;
		    return sizeKPalindromes("", charSet, size,odd);		
	    }

	    private static List<String> sizeKPalindromes(string s, List<char> charSet, int size, bool odd) 
        {
		    if (s == null) {
			    return null;
		    }
		
		    if (s.Length == size)
		    {
		        var currPalindrome = new List<string>();
			    currPalindrome.Add(s);
			    return currPalindrome;
		    }
		
		    List<String> allPalindromeStrings = new List<String>();		
		    for (int i = 0; i < charSet.Count; i++) {
			
			    string tempString;			
			    if (odd && string.IsNullOrEmpty(s)) {
				    tempString = s + charSet.ElementAt(i);
			    }			
			    else {
				    tempString = charSet.ElementAt(i) + s + charSet.ElementAt(i);
			    }
			
			    var tempPalindromes = sizeKPalindromes(tempString, charSet, size, odd);
			    allPalindromeStrings = allPalindromeStrings.Union(tempPalindromes).ToList();
		    }
		
		    return allPalindromeStrings;
	    }

        private static void Execute2()
        {
            int t = int.Parse(Console.ReadLine());
            bool xWon, yWon;
            int count = t;
            while(t > 0)
            {
                t--;
                string[] tic = new string[4];
                for (int i = 0; i < 4; i++)
                {
                    tic[i] = Console.ReadLine();
                }

                xWon = tic.ToList().Any(x => x.All(c => c == 'X' || c == 'T'));
                yWon = tic.ToList().Any(x => x.All(c => c == 'O' || c == 'T'));
                if (xWon || yWon)
                {
                    if (xWon)
                    {
                        Console.WriteLine("Case #" + (count - t) + ": " + "X won");
                        Console.ReadLine();
                        continue;
                    }

                    Console.WriteLine("Case #" + (count - t) + ": " + "O won");
                    Console.ReadLine();
                    continue;
                }

                string[]vert = new string[4];
                for (int i = 0; i < 4; i++)
                {
                    vert[i] = tic[0].ElementAt(i).ToString() + tic[1].ElementAt(i).ToString()
                              + tic[2].ElementAt(i).ToString() + tic[3].ElementAt(i).ToString();
                }

                xWon = vert.ToList().Any(x => x.All(c => c == 'X' || c == 'T'));
                yWon = vert.ToList().Any(x => x.All(c => c == 'O' || c == 'T'));
                if (xWon || yWon)
                {
                    if (xWon)
                    {
                        Console.WriteLine("Case #" + (count - t) + ": " + "X won");
                        Console.ReadLine();
                        continue;
                    }

                    Console.WriteLine("Case #" + (count - t) + ": " + "O won");
                    Console.ReadLine();
                    continue;
                }

                string leftD = tic[0].ElementAt(0).ToString() + tic[1].ElementAt(1).ToString()
                            + tic[2].ElementAt(2).ToString() + tic[3].ElementAt(3).ToString();
                string rightD = tic[0].ElementAt(3).ToString() + tic[1].ElementAt(2).ToString()
                             + tic[2].ElementAt(1).ToString() + tic[3].ElementAt(0).ToString();
                xWon = leftD.All(x => x == 'X' || x == 'T') || rightD.All(x => x == 'X' || x == 'T');
                yWon = leftD.All(x => x == 'O' || x == 'T') || rightD.All(x => x == 'O' || x == 'T');
                if (xWon || yWon)
                {
                    if (xWon)
                    {
                        Console.WriteLine("Case #" + (count - t) + ": " + "X won");
                        Console.ReadLine();
                        continue;
                    }

                    Console.WriteLine("Case #" + (count - t) + ": " + "O won");
                    Console.ReadLine();
                    continue;
                }

                if (tic.ToList().Any(x => x.Any(y => y == '.')))
                {
                    Console.WriteLine("Case #" + (count - t) + ": " + "Game has not completed");
                }
                else
                {
                    Console.WriteLine("Case #" + (count - t) + ": " + "Draw");
                }
                Console.ReadLine();
            }
        }

        private static void Execute1()
        {
            string positiveString = "91389681247993671255432112000000";
            var posBigInt = BigInteger.Parse(positiveString);
            var answer = GetList(10000000);
            int t = int.Parse(Console.ReadLine());
            int count = t;
            while (t > 0)
            {
                t--;
                var lim = Console.ReadLine().Split().ToList();
                long l = long.Parse(lim[0]);
                long r = long.Parse(lim[1]);
                int ans = answer.FindAll(n => n >= l && n <= r).Count;
                Console.WriteLine("Case #" + (count - t).ToString() + ": " + ans);
            }
        }

        private static List<Int64> GetList(Int64 n)
        {
            List<Int64> ret = new List<Int64>();
            for (Int64 i = 1; i <= n; i++)
            {
                Int64 c = i * i;
                if (IsPalindrome(c.ToString()) && IsPalindrome(i.ToString()))
                {
                    ret.Add(c);
                    Console.WriteLine(i);
                }
            }

            return ret;
        }

        public static bool IsPalindrome(string value)
        {
            int min = 0;
            int max = value.Length - 1;
            while (true)
            {
                if (min > max)
                {
                    return true;
                }
                char a = value[min];
                char b = value[max];
                if (char.ToLower(a) != char.ToLower(b))
                {
                    return false;
                }
                min++;
                max--;
            }
        }
    }
}
