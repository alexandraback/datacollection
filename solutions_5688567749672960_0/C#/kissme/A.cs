using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _2015CodeJam1B
{
    public class A
    {
        private static Dictionary<long, long> _cache = new Dictionary<long, long>(); 

        public static string Process(long last, int caseNo)
        {
            return string.Format("Case #{0}: {1}", caseNo, Min(last));
        }

        private static long Min(long last)
        {
            if (last <= 20) return last;

            if (_cache.ContainsKey(last)) return _cache[last];

            for (long i = 21; i <= last; i++)
            {
                if (!_cache.ContainsKey(i))
                {
                    var res = 0L;
                    var reverse = Reverse(i);
                    if (i%10 == 0 || reverse >= i)
                    {
                        res = Min(i - 1) + 1;
                    }
                    else
                    {
                         res = Math.Min(Min(reverse), Min(i - 1)) + 1;
                    }

                    _cache.Add(i, res);
                }
            }

            return _cache[last];
        }

        ////private static long Min2(int last)
        ////{
        ////    if (last <= 20) return last;

        ////    if (_cache.ContainsKey(last)) return _cache[last];

        ////    var res = 0L;
        ////    var reverse = Reverse(last);
        ////    if (last%10==0 || reverse > 10)
        ////    {
        ////        res = Min2(last - 1) + 1;
        ////    }
        ////    else
        ////    {
        ////        res = Math.Min(reverse, )
        ////    }
        ////}

        private static long Reverse(long num)
        {
            var strNum = (num+"").ToCharArray();
            for (int i = 0; i < strNum.Length/2; i++)
            {
                var l = strNum[i];
                strNum[i] = strNum[strNum.Length - 1];
                strNum[strNum.Length - 1] = l;
            }

            var str = string.Join("", strNum);

            return Convert.ToInt64(str);
        }
    }
}
