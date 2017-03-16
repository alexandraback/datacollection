import java.io.FileNotFoundException;
import java.util.Scanner;


public class ProblemA {
	static Scanner in=new Scanner(System.in);
	public static void main(String[] args) throws FileNotFoundException {
		java.io.PrintStream out=new java.io.PrintStream("C:/users/Josh/documents/output.txt");
		int run=Integer.parseInt(in.nextLine());
		for(int p=0;p<run;p++)
		{
			String start=in.nextLine();
			char temp=start.charAt(0);
			String cur="";
			cur+=temp;
			start=start.substring(1);
			int o=start.length();
			for(int c=0;c<o;c++)
			{
				if(cur.charAt(0)<=start.charAt(0))
				{
					cur=start.charAt(0)+cur;
				}
				else
				{
					cur+=start.charAt(0);
				}
				if(start.length()>1)
					start=start.substring(1);
			}
			out.println("Case #"+(p+1)+": "+cur);
			
		}

	}

}
