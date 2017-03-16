import java.util.*;
import java.io.*;

class B1small
{
	public static void main(String[] args) throws Exception 
	{
		FileInputStream fis = new FileInputStream("B-large.in");
		Scanner scan = new Scanner(fis);
		FileWriter fw = new FileWriter("output.txt");
		int T = scan.nextInt();
		for(int i=1;i<=T;i++)
		{
			int count=0;
			int sur =0;
			int N = scan.nextInt();//number of dancers
			int S = scan.nextInt();//number of surprises
			int P = scan.nextInt();//best result
			for(int j=0;j<N;j++)
			{
				int t = scan.nextInt();
				if(t == 0 && P !=0)
					continue;
				if(t%3==2 || t%3==1)
				{	if(t/3+1>=P)
					{
						count++;
						continue;
					}
				}
				else
				{
					if(t/3>=P)
					{
						count++;
						continue;
					}
				}
				if(t%3==2 && sur<S)
				{
					if(t/3+2 >=P)
					{
						sur++;
						count++;
						continue;
					}
				}
				else if(t%3 == 0 && sur<S)
				{
					if(t/3+1>=P)
					{
						sur++;
						count++;
						continue;
					}
				}
			}
			fw.write("Case #" +i +": "+ count +"\n");
		}
		fw.close();
	}
}