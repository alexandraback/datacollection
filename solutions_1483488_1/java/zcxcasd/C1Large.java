import java.util.*;
import java.io.*;

class C1Large
{
	public static void main(String[] args) throws Exception 
	{
		FileInputStream fis = new FileInputStream("C-large.in");
		Scanner scan = new Scanner(fis);
		FileWriter fw = new FileWriter("output.txt");
		int T = scan.nextInt();
		for(int c = 1; c<=T;c++)
		{
			long A = scan.nextInt();
			long B = scan.nextInt();
			int digit = String.valueOf(A).length();
			int count=0;
			
			for(long i=A;i<=B;i++)
			{
				String mut = String.valueOf(i);
				long tmp =0;
				long[] mem = new long[digit];
				boolean counted = false;
				for(int j=1;j<digit;j++)
				{
					tmp = Long.parseLong(mut.substring(j,digit) + (mut.substring(0,j)));
					mem[j-1] = tmp;
					counted = false;
					if(tmp > Long.parseLong(mut) && tmp >=A && tmp <=B)
					{
						for(int k=0;k<j-1;k++)
						{
							if(mem[k] == tmp)
							{	
								counted = true;
								break;
							}
						}
						if(!counted)
						{
//							System.out.println("counted :"+ A + "<=" +mut +"<"+ tmp +"<=" +B);
							count++;
						}
					}
				}
			}
			if(digit > 1 )
				fw.write("Case #" +c +": "+ count +"\n");
			else
				fw.write("Case #" +c +": "+ 0 +"\n");
		}
		fw.close();
	}
}