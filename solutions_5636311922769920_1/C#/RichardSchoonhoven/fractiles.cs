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
		int querys = (k+c-1)/c;
		if(s < querys){
			Console.WriteLine("Case #" + (l+1).ToString() +": IMPOSSIBLE");
			continue; 
		}
		long[] querylist = new long[querys];
		long mult = 0;
		for(int i = 0; i < querys; i++){
			double index = 0;
			for(int j = 0; j < c; j++){
				if(mult >= k)
					break;
				index += mult*Math.Pow(k,j);
				mult++;
			}
			querylist[i] = (long) index;
		}
		Console.WriteLine("Case #" + (l+1).ToString() +": " + String.Join(" ", Array.ConvertAll<long, string>(querylist, i => i.ToString())));
	}
	}
}
