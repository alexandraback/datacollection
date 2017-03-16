using System;
using System.Linq;
using System.Collections.Generic;

public class fractiles
{
	static public void Main(){
	int t = Int32.Parse(Console.ReadLine());
	for(int l = 0; l < t; l++){
		string[] input = Console.ReadLine().Split();
		int k = Int32.Parse(input[0]);
		int c = Int32.Parse(input[1]);
		int s = Int32.Parse(input[2]);
		Console.WriteLine("Case #" + (l+1).ToString() +": " + String.Join(" ", Array.ConvertAll<int, string>(Enumerable.Range(1, k).ToArray(), i => i.ToString())));
	}
	}
}
