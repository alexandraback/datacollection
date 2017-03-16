namespace GCJ15.Quals
{
    using System;
    using System.Globalization;
    using System.Linq;

    public class A
    {
        public string[] Solve(string[] lines)
        {
            int cases = int.Parse(lines[0]);
            string[] res = new string[cases];
            for (int test = 0; test < cases; test++)
            {
                string[] ss = lines[test+1].Split(new char[] { ' ' }, StringSplitOptions.RemoveEmptyEntries);
                string v = ss[1];
                int cur = 0;
                int need = 0;
                for (int i = 0; i < v.Length; i++)
                {
                    int q = v[i] - '0';
                    if (cur < i)
                    {
                        need += i - cur;
                        cur = i;
                    }
                    cur += q;
                }

                res[test] = string.Format(
                    "Case #{0}: {1}",
                    (test + 1).ToString(CultureInfo.InvariantCulture),
                    need.ToString(CultureInfo.InvariantCulture));

            }
            return res;
        }
    }
}
