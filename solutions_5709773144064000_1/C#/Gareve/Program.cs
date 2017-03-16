/*
 * Created by SharpDevelop.
 * User: grea
 * Date: 4/11/2014
 * Time: 8:23 PM
 * 
 * To change this template use Tools | Options | Coding | Edit Standard Headers.
 */
using System;

namespace B{
	class Program{
		public static void Main(string[] args){
			int NC = int.Parse(Console.ReadLine());
			
			for(int i=1;i<=NC;i++){
				String[] vals = Console.ReadLine().Split(' ');
					
				
				
				double C = double.Parse(vals[0]);
				double F = double.Parse(vals[1]);
				double X = double.Parse(vals[2]);
				
				/*
				Console.WriteLine(C);
				Console.WriteLine(F);
				Console.WriteLine(X);
				*/

				double cookies_per_sec = 2.0;
				double ans = X / cookies_per_sec;
				if(X <= C){
			    	ans = X / cookies_per_sec;
				}else{					
					double time = 0.0,finalTime;
					double delta_c;
					for(int j=1;j<=100000000;j++){
						delta_c = C / cookies_per_sec;
						time = time + delta_c;
						cookies_per_sec = cookies_per_sec + F;
						
						finalTime = time + (X / cookies_per_sec);
						
						if(finalTime <= ans){
							ans = finalTime;
						}else{
							break;
						}
					}
				}
				
				//Console.WriteLine(ans);
				Console.WriteLine("Case #{0}: {1:0.0000000}",i,ans);
			}
		}
	}
}