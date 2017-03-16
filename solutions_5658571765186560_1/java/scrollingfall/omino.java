import java.io.*;
import java.util.*;
public class omino {
	public static void main(String[]args) throws Exception
	{
		PrintWriter o=new PrintWriter("ominoout4.txt");
		Scanner scan=new Scanner(new File("D-large.in"));
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
			else if(x>6)
				gabrielwins=false;
			else if(((r*c)-x==0)&&(x!=1&&x!=2))
				gabrielwins=false;
			else if((x==3||x==4||x==5||x==6)&&(r==1||c==1))
				gabrielwins=false;
			else if((x==4||x==5||x==6)&&(r==2||c==2))
				gabrielwins=false;
			else if(x==5&&(r*c==15))
				gabrielwins=false;
			else if((x==6)&&(r==3||c==3))
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