import java.io.*;
import java.util.*;
public class omino {
	public static void main(String[]args) throws Exception
	{
		PrintWriter o=new PrintWriter("ominoout3.txt");
		Scanner scan=new Scanner(new File("D-small-attempt3.in"));
		int n=Integer.parseInt(scan.nextLine());
		for(int i=1;i<=n;i++)
		{
			String[]cond=scan.nextLine().split(" ");
			int x=Integer.parseInt(cond[0]);
			int r=Integer.parseInt(cond[1]);
			int c=Integer.parseInt(cond[2]);
			boolean gabrielwins=true;
			if((r*c)%x!=0)
				gabrielwins=false;		
			else if(x==1||x==2)
				gabrielwins=true;
			else if(((r*c)-x==0)&&(x!=1&&x!=2))
				gabrielwins=false;
			else if((x==3||x==4)&&(r==1||c==1))
				gabrielwins=false;
			else if(x==4&&(r==2||c==2))
				gabrielwins=false;
			if(gabrielwins)
				o.println("Case #"+i+": GABRIEL");
			else
				o.println("Case #"+i+": RICHARD");
		}
		o.close();
		scan.close();
	}
}