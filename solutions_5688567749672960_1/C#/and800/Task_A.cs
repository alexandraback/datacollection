using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.IO;

namespace Task_A
{
    class Solution
    {
        static void Main()
        {
            StreamReader input = new StreamReader("input");
            StreamWriter output = new StreamWriter("output");

            int TestsAmount = int.Parse(input.ReadLine());
            for (int currentTest = 1; currentTest <= TestsAmount; currentTest++)
            {
                long N = long.Parse(input.ReadLine());

                output.WriteLine("Case #{0}: {1}", currentTest, Solve(N));
            }

            input.Close();
            output.Close();
        }

        static long Solve(long target)
        {
            if (target < 21) return target;
            long count = 1;
            long current = 1;
            //for (; current != target; count++)
            //{
            //    if (Reverse(current) > current && Reverse(current) <= target) current = Reverse(current);
            //    else current++;
            //}
            //return count;

            long targetDigitsNum=DigitsNum(target);

            while (DigitsNum(current) < targetDigitsNum)
            {
                if (current == 1) current = count = 10;
                else
                {
                    long requiredDigits = DigitsNum(current) / 2;
                    long tmp = Pow(10, requiredDigits) - 1;
                    current += tmp;
                    count += tmp;
                    current = Reverse(current);
                    count++;
                    tmp = Pow(10, DigitsNum(current));
                    count += (tmp - current);
                    current = tmp;
                }
            }

            if (current == target) return count;
            if (target % 10 == 0)
            {
                target--;
                count++;
            }

            long PartReversed = Reverse(target);
            long tmp2 = targetDigitsNum % 2 == 0 ? targetDigitsNum / 2 : targetDigitsNum / 2 + 1;
            PartReversed = PartReversed % (Pow(10, tmp2));
            count += PartReversed;
            current += PartReversed;
            if (Reverse(current) > current)
            {
                current = Reverse(current);
                count++;
            }
            count += target - current;
            return count;
        }

        static long Reverse(long value)
        {
            if (value < 10) return value;
            long answer=0;
            while (value>0)
            {
                long digit = (long) value % 10;
                answer *= 10;
                answer += digit;
                value /= 10;
            }
            return answer;
        }
        static long DigitsNum(long value)
        {
            long digitsNum = 0;
            while (value > 0)
            {
                value /= 10;
                digitsNum++;
            }
            return digitsNum;
        }
        static long Pow(long a, long b)
        {
            long ans = 1;
            for (long i = 0; i < b; i++)
            {
                ans *= a;
            }
            return ans;
        }
    }
}
