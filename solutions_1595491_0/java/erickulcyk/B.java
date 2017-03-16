package b;

import java.util.Arrays;
import java.util.Scanner;

public class B {

	public B() {
		Scanner s = new Scanner (System.in);
		
		int t = s.nextInt();
		
		
		for(int i =0; i < t; i++)
		{
			int n = s.nextInt();
			int ss = s.nextInt();
			int p = s.nextInt();
			
			int[] vals = new int[n];
			
			for(int j = 0; j < n; j ++)
				vals[j]=s.nextInt();
			
			Arrays.sort(vals);
			
			int num=0, numLeft = ss;
			for(int j=vals.length-1; j >=0;j--)
			{
				//System.out.println(vals[j]);
				if(numLeft==0 || vals[j]>=29 || vals[j]<2 || (vals[j]+2)/3>=p)
				{
					//System.out.println("here "+(vals[j]+2)/3);
					if((vals[j]+2)/3>=p)
					{
						num++;
					}
				}
				else
				{
					if((vals[j]+4)/3>=p)
					{
						numLeft--;
						num++;
					}
				}
			}
			
			System.out.println("Case #"+(i+1)+": "+num);
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		new B();

	}

}
