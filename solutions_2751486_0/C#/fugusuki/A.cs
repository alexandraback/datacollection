using System;
using System.Collections.Generic;
using System.Linq;

class A
{
    public int Solve(string str, int n)
    {
        return Enumerable.Range(0, str.Length).Sum(i =>  
            Enumerable.Range(1, str.Length-i).Count(j=> str.Substring(i,j).Split("aiueo".ToCharArray()).Any(s=>s.Length>=n))
        );
    }

    static IEnumerable<string> Output() {
        var line = Console.ReadLine().Split(' ');
        yield return new A().Solve(line[0],int.Parse(line[1])).ToString(); 
    }
    static void Main() { foreach (var i in Enumerable.Range(1, Convert.ToInt32(Console.ReadLine()))) Console.WriteLine("Case #{0}: {1}", i, string.Join(Environment.NewLine, Output().ToArray())); }
}

