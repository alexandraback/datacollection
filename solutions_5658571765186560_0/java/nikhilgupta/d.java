import java.util.*;
import java.io.PrintWriter;
import java.io.File;
public class d {
	public static void main(String[] args) {


		File fileout=new File("C:/Users/Nikhil Gupta/Desktop/D-ans.out");
		File file=null;
		PrintWriter writer=null;
		Scanner in=null;
		int x,r,c,a,b;
		boolean j,k;
		try{
		 file = new File("C:/Users/Nikhil Gupta/Desktop/D-small.in");
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
			 j=false;
			 k=false;
			if((r*c)%x==0)
			 {if(x==1)
		  	writer.println("Case #"+jo+": GABRIEL");
				else if(x==4 && ((r==4 && c==2)||(r==2 && c==4)))
				writer.println("Case #"+jo+": RICHARD");
			 else
				{
				 a=(x/2)+1;
				 if(x%2==0)b=a-1;
				 else b=a;
				 if(a<=r)
				   j=true;
				 else if(a<=c)
				   k=true;
				 if(j==false && k==false)
					writer.println("Case #"+jo+": RICHARD");
				 else if(j==true)
				  {if(b<=c)
						writer.println("Case #"+jo+": GABRIEL");
					 else
				  	writer.println("Case #"+jo+": RICHARD");
					}
					else
					{if(b<=r)
						writer.println("Case #"+jo+": GABRIEL");
					 else
				  	writer.println("Case #"+jo+": RICHARD");
					}

				}
			}
			else
			writer.println("Case #"+jo+": RICHARD");
			}
		writer.close();
	}
}
