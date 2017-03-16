import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class password 
{
	public static void main(String[] args) throws FileNotFoundException 
	{
		Scanner input=new Scanner(new File("A-large.in"));
		int a=0,b=0;
		input.nextLine();
		int k=1;
		while(input.hasNextLine())
		{
			String str=input.nextLine();
			String[] st=str.split(" ");
			a=Integer.parseInt(st[0]);
			b=Integer.parseInt(st[1]);
			str=input.nextLine();
			st=str.split(" ");
			double[] prob=new double[a];
			for(int i=0;i<a;i++)
			{
				prob[i]=Double.parseDouble(st[i]);
			}
			double min_key=0;
			min_key=b+2;
			for(int i=0;i<a;i++)
			{
				int right=b-a+1+2*i;
				int wrong=b-a+1+2*i+b+1;
				double correct_prob=1;
				for(int j=0;j<a-i;j++)
				{
					correct_prob=correct_prob*prob[j];
				}
				double steps=right*correct_prob+wrong*(1-correct_prob);
				if(steps<min_key)
					min_key=steps;
			}
			System.out.println("Case #" + k + ": " + min_key);
			k++;
		}
	}
}
