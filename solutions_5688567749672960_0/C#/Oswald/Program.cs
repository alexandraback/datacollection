using System;
using System.IO;
using System.Collections.Generic;
class MainClass
{
	public static ulong reverse(ulong input){
		ulong left = input;
		ulong rev = 0;
		while(left>0)
		{
			ulong r = left % 10;   
			rev = rev * 10 + r;
			left = left / 10;  //left = Math.floor(left / 10); 
		}
		return rev;
	}
	public static ulong getFirst(ulong input){
		while (input > 9) {
			input /= 10;
		}
		return input;
	}
	public static ulong getDigit(ulong current, int index){
		ulong answer = (current) % ((ulong)Math.Pow (10, index + 1));
			while(answer>10){
			answer /= 10;
			};
		return answer;
	}
	public static ulong getdigits(ulong temp){
		ulong totalDigits=0;
		while (temp > 0) {
			temp /= 10;
			totalDigits++;
		}
		return totalDigits;

	}
	public static void Main (string[] args)
	{
		string[] lines = File.ReadAllLines ("test.txt");
		int total = Convert.ToInt32 (lines [0]);
		for (int i = 1; i <= total; i++) {
			ulong currentGoal = Convert.ToUInt64 (lines [i]);
			ulong current = 1;
			ulong distance = 0;
			int digits = (int) getdigits (currentGoal);
			int af = digits / 2;
			int bf = digits - af;
			for(int f=1; f<digits; f++){
				int a = f / 2;
				int b = f - a;
				distance += (ulong) Math.Pow (10, b) - 2;
				if (a != 0) {
					++distance;
					distance += (ulong) Math.Pow (10, a) - 1;
				}
				++distance;
			}
			//Console.WriteLine (distance);
			current = (ulong) Math.Pow (10, digits - 1);
			if (currentGoal % 10 == 0) {
				distance +=  (ulong) currentGoal % (ulong) Math.Pow (10, digits - 1);
			} else {
				if (reverse (currentGoal) % (ulong)10 != 1) {
					distance += (ulong)reverse (currentGoal) % (ulong)Math.Pow (10, bf);
				}
				//Console.WriteLine (distance);
				if (af != 0) {
					distance += (ulong) currentGoal % (ulong) Math.Pow (10, af);
					//Console.WriteLine (distance);
				}
				if (digits != 1) {
					++distance;
				}
			}
			Console.WriteLine ("Case #{0}: {1}", i, distance);
		}
	}
}