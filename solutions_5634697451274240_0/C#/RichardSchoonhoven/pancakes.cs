using System;
using System.Linq;
using System.Collections.Generic;

public class pancakes
{
	static public void Main(){
	int t = Int32.Parse(Console.ReadLine());
	for(int l = 0; l < t; l++){
		string input = Console.ReadLine();
		int[] digs = new int[input.Length];
		for(int i = 0; i < input.Length; i++){
			if(input[i] == '+')
				digs[i] = 1;
			else
				digs[i] = 0;
		}
		int flips = 0;
		while(true){
			int check = 0;
			foreach(int dig in digs)
				check += dig;
			if(check == input.Length){
				Console.WriteLine("Case #" + (l+1).ToString() +": "+ (flips).ToString());
				break;
			}
			flips++;
			int grens = digs.Length;
			for(int i = 1; i < digs.Length; i++){
				if(digs[i] != digs[0]){
					grens = i;
					break;
				}
			}
			for(int k = 0; k < grens; k++){
				if(digs[k] == 0)
					digs[k] = 1;
				else
					digs[k] = 0;
			}
		}
	}
	}
}
