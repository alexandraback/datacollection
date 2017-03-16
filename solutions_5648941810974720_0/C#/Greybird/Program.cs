using System.Collections.Generic;
using System.IO;
using System.Linq;

namespace Round1_2
{
    class Program
    {
        static void Main(string[] args)
        {
            var lines = File.ReadAllLines(@"..\..\input.txt");
            var count = int.Parse(lines[0]);
            var results = new List<string>();
            var numbers = new List<KeyValuePair<int, string>>();
            numbers.Add(new KeyValuePair<int, string>(0, "ZERO"));
            numbers.Add(new KeyValuePair<int, string>(6, "SIX"));
            numbers.Add(new KeyValuePair<int, string>(2, "TWO"));
            numbers.Add(new KeyValuePair<int, string>(8, "EIGHT"));
            numbers.Add(new KeyValuePair<int, string>(3, "THREE"));
            numbers.Add(new KeyValuePair<int, string>(4, "FOUR"));
            numbers.Add(new KeyValuePair<int, string>(5, "FIVE"));
            numbers.Add(new KeyValuePair<int, string>(7, "SEVEN"));
            numbers.Add(new KeyValuePair<int, string>(1, "ONE"));
            numbers.Add(new KeyValuePair<int, string>(9, "NINE"));

            for (var i = 0; i < count; i++)
            {
                var val = lines[i + 1];
                var res = new List<int>();
                var n = 0;
                while (val.Length > 0)
                {
                    var val2 = val;
                    var found = true;
                    foreach (var c in numbers[n].Value)
                    {
                        var p = val2.IndexOf(c);
                        if (p >= 0)
                        {
                            val2 = val2.Remove(p, 1);
                        }
                        else
                        {
                            n++;
                            found = false;
                            break;
                        }
                    }
                    if (found)
                    {
                        val = val2;
                        res.Add(numbers[n].Key);
                    }
                }
                res.Sort();
                var jjj = res.Select(k => k.ToString()).Aggregate(string.Empty, (s, k) => s + k);
                results.Add($"Case #{i + 1}: {jjj}");
            }
            File.WriteAllLines(@"..\..\output.txt", results);
        }
    }
}