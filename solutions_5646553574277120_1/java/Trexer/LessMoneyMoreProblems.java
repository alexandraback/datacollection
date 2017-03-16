package uk.ac.cam.spt37.codeJam2015;

import java.util.ArrayList;
import java.util.Scanner;

public class LessMoneyMoreProblems
{

	public static void main(String[] args)
	{
		Scanner data = new Scanner(System.in);
		int cases = data.nextInt();
		for(int i=1; i<=cases; i++)
		{
			int c = data.nextInt();
			int d = data.nextInt();
			int v = data.nextInt();
			int sum = 0;
			ArrayList<Integer> ds = new ArrayList<Integer>();
			int result = 0;
			for(int j=0; j<d; j++) ds.add(data.nextInt());
			for(int j=0; j<d; j++)
			{
				sum = 0;
				for(int k=0; k<ds.size(); k++)
				{
					if (ds.get(k) < ds.get(j)) sum += ds.get(k) * c;
				}
				if (sum >= v) break;
				if (sum < ds.get(j)-1)
				{
					ds.add(sum+1);
					j--;
					result++;
				}
			}
			while(sum<v)
			{
				sum = 0;
				for(int k=0; k<ds.size(); k++)
					sum += ds.get(k) * c;
				if (sum < v)
				{
					ds.add(sum+1);
					result++;
				}
			}
			
			System.out.println("Case #"+i+": "+result);
		}
		data.close();
	}
	
}