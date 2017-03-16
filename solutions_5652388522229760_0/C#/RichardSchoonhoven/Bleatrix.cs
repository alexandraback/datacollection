using System;
using System.Linq;
using System.Collections.Generic;

public class staircase
{
	static public void Main(){
	int t = Int32.Parse(Console.ReadLine());
	for(int l = 0; l < t; l++){
		bool[] digits = new bool[10];
		for (int i = 0; i < digits.Length; i++) { digits[i] = false; }
		long n = Int32.Parse(Console.ReadLine());
		long m = n;
		if(n == 0){
			Console.WriteLine("Case #" + (l+1).ToString() +": INSOMNIA");
			continue;
		}
		long count = 0;
		while(true){
			count++;
			n = count*m;
			while(count*n>0){
				long rem = n % 10;
				digits[rem] = true;
				if(digits.All(x => x))
					break;
				n = n /10;
			}
			if(digits.All(x => x)){
				Console.WriteLine("Case #" + (l+1).ToString() +": "+ (count*m).ToString());
				break;
			}
		}
	}
	}
}
