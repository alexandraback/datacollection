import java.util.*;
import java.io.PrintWriter;
import java.io.File;

 class dCopy
{
	public static void main(String[] args) {
		File fileout=new File("C:/Users/Nikhil Gupta/Desktop/D-ans1.out");
		File file=null;
		PrintWriter writer=null;
		Scanner in=null;
		int x,r,c;
		boolean ans;
		try{
		 file = new File("C:/Users/Nikhil Gupta/Desktop/D-large.in");
		 in = new Scanner(file);
		 writer = new PrintWriter(fileout, "UTF-8");
		}
		catch(Exception e){}
		int T=in.nextInt();
		for(int jo=1;jo<=T;jo++)
			{
			 x=in.nextInt();
			 r=in.nextInt();
			 c=in.nextInt();
			ans=true;
			if (x >= 7)
        ans = false;
    else if (x > r && x > c)
        ans = false;
    else if (((r*c) % x) != 0)
        ans = false;
    else if ((x + 1) / 2 > Math.min(r,c))
        ans = false;
    else if (x==1 || x==2 || x==3)
        ans = true;
    else if (x == 4)
        ans = Math.min(r,c) > 2;
    else if (x == 5)
        ans = !(Math.min(r,c) == 3 && Math.max(r, c) == 5);
    else if (x == 6)
        ans = Math.min(r,c) > 3;
				if(ans)
				writer.println("Case #"+jo+": GABRIEL");
				else
				writer.println("Case #"+jo+": RICHARD");
			}

		writer.close();
	}
}
