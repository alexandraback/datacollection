using System;
using System.IO;

namespace GoogleCodeJam
{
    internal class A : CodeJamBase
    {
        private static readonly uint Const1 = Convert.ToUInt32("033333333333", 8);
        private static readonly uint Const2 = Convert.ToUInt32("011111111111", 8);
        private static readonly uint Const3 = Convert.ToUInt32("030707070707", 8);
        private long den;
        private long num;

        public override bool ExecuteAsynchronus
        {
            get { return false; }
        }

        public override void LoadInput(StreamReader input)
        {
            var list = input.ReadLine().Split('/');
            num = Convert.ToInt64(list[0]);
            den = Convert.ToInt64(list[1]);
        }

        public override string Process()
        {
            if (num == 0)
            {
                throw new NotImplementedException();
            }
            if (BitCount(den) != 1)
            {
                var d1 = den;
                while ((d1 & 1) == 0)
                {
                    d1 >>= 1;
                }
                var a = ((decimal) num) / d1;
                if (a != (int) a)
                {
                    return "impossible";
                }
                num = (int) a;
                den /= d1;
            }
            while (num > 1)
            {
                num >>= 1;
                den >>= 1;
            }
            var res = 0;
            while (den > 1)
            {
                den >>= 1;
                res += 1;
            }
            return res.ToString();
        }

        private static int BitCount(long n)
        {
            var u = (ulong) n;
            var uCount = u - ((u >> 1) & Const1) - ((u >> 2) & Const2);
            return (int) (((uCount + (uCount >> 3)) & Const3) % 63);
        }
    }
}