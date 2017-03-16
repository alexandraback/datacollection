import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;


public class googler {

	
	public static void main(String args[]) throws FileNotFoundException
	{
		
		Scanner in=new Scanner(new FileReader("input.in"));
		PrintWriter pw=new PrintWriter("ans.txt");
		
		
		int cases=in.nextInt();
		in.nextLine();
		for(int counter=1;counter<=cases;counter++)
		{
			int n=in.nextInt();
			int s=in.nextInt();
			int p=in.nextInt();
			
			System.out.println(n+" "+s+" "+p);
			int req;
			if(p==0)
			{
				pw.println("Case #"+(counter)+": "+n);
				in.nextLine();
				continue;
			}
			else
				req=p*3-2;
			
			int min=req-2>0?req-2:1;
			
			int answer=0;
			
			for(int j=0;j<n;j++)
			{
				int score=in.nextInt();
				
				if(score>=req)
				{
					answer++;
					continue;
				}
				else if(score>=min&&s>0)
				{
					answer++;
					s--;
				}					
			}
			
			pw.println("Case #"+(counter)+": "+answer);
		}
		pw.close();
	}
}
