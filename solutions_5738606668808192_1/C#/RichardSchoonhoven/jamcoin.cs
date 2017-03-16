using System;
using System.Linq;
using System.Collections.Generic;

public class pancakes
{
	static public void Main(){
	int t = Int32.Parse(Console.ReadLine());
	Console.WriteLine("Case #1: ");
	string[] input = Console.ReadLine().Split();
	int n = Int32.Parse(input[0]);
	int j = Int32.Parse(input[1]);
	string[] digits = new string[j];
	for(int i = 0; i < j; i++){
		string var = ToBin(i+1, (n-4)/2);
		string var2 = Reverse(var);
		digits[i] = "1"+var+"11"+var2+"1";
	}
	for(int i = 0; i < j; i++){
		Console.WriteLine(digits[i]+" 3"+" 4"+" 5"+" 6"+" 7"+" 8"+" 9"+" 10"+" 11");
	}
	}
	static 	long computenum(string input, int numbase){
		int[] input2 = new int[input.Length];
		for(int i = 0; i < input.Length; i++){
			input2[i] = Int32.Parse(input[i].ToString());
		}
		long output = 0;
		long num = 1;
		for(int i = 0; i < input2.Length; i++){
			if(input2[input2.Length - i -1] == 1){
				output += num;
			}
			num = num*numbase;
		}
		return output;
	}
	static string ToBin(int var, int len) {
		return (len > 1 ? ToBin(var >> 1, len - 1) : null) + "01"[var & 1];
	}
	static string Reverse( string s )
	{
	    	char[] charArray = s.ToCharArray();
	    	Array.Reverse( charArray );
	    	return new string( charArray );
	}
}
