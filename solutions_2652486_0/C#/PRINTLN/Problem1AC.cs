using System;
using System.Collections;
using System.IO;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Collections.Generic;

public class Problem1AC
{
    public static void Main(String[] args)
    {
        StreamReader reader = new StreamReader(@"D:\codejam\C-small-1-attempt2.in");
        StreamWriter writer = new StreamWriter(@"D:\codejam\C-small-1-attempt2.out");
        var inputPool = reader.ReadToEnd()
                              .Trim()
                              .Split(new[] { ' ', '\r', '\n' }, StringSplitOptions.RemoveEmptyEntries)
                              .Select(Int32.Parse)
                              .ToArray();

        Random rand = new Random((int)DateTime.Now.Ticks);

        int index = 0;
        int T = inputPool[index++];
        int R = inputPool[index++];
        int N = inputPool[index++];
        int M = inputPool[index++];
        int K = inputPool[index++];
        List<int> numbers = new List<int>(N);
        writer.WriteLine("Case #1:");
        long allProuct = 1;
        for (int _ = 0; _ < R; _++)
        {
            numbers.Clear();
            HashSet<int> products = new HashSet<int>();
            HashSet<int> sets = new HashSet<int>();
            for (int i = 0; i < K; i++)
            {
                var product = inputPool[index++];
                allProuct *= product;
                if (product == 2
                    || product == 3
                    || product == 5
                    || product == 7)
                {
                    sets.Add(product);
                }
                else if (product != 1)
                {
                    products.Add(product);
                }
            }
            if (products.Contains(27))
            {
                writer.WriteLine("333");
                continue;
            }
            if (products.Contains(36))
            {
                writer.WriteLine("334");
                continue;
            }
            if (products.Contains(45))
            {
                writer.WriteLine("335");
                continue;
            }
            if (products.Contains(48))
            {
                writer.WriteLine("344");
                continue;
            }
            if (products.Contains(60))
            {
                writer.WriteLine("345");
                continue;
            }
            if (products.Contains(64))
            {
                writer.WriteLine("444");
                continue;
            }
            if (products.Contains(80))
            {
                writer.WriteLine("445");
                continue;
            }
            if (products.Contains(125))
            {
                writer.WriteLine("555");
                continue;
            }
            Dictionary<int, int> dict = new Dictionary<int, int>() { { 2, 0 }, { 3, 0 }, { 5, 0 }, { 7, 0 } };
            foreach (var key in new int[] { 2, 3, 5, 7 })
            {
                while (allProuct % key == 0)
                {
                    allProuct /= key;
                    dict[key]++;
                }
            }
            if (dict[3] != 0)
            {
                numbers.Add(3);
            }
            if (dict[5] != 0)
            {
                numbers.Add(5);
            }
            var prop = (int)(dict[5] * 1.0 / 21 - 0.5);
            for (int i = 0; i < prop && numbers.Count < N; i++)
            {
                numbers.Add(5);
            }
            prop = (int)(dict[3] * 1.0 / 21 - 0.5);
            for (int i = 0; i < prop && numbers.Count < N; i++)
            {
                numbers.Add(3);
            }
            while (numbers.Count < N)
            {
                numbers.Add(rand.Next(2) == 1 ? 2 : 4);
            }
            writer.WriteLine(numbers.Aggregate(new StringBuilder(), (sb, n) => sb.Append(n)));
        }

        writer.Flush();
        writer.Close();
        reader.Close();
    }
}