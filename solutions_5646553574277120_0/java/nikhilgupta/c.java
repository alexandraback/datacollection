import java.util.*;
import java.io.PrintWriter;
import java.io.File;
public class c {
	public static void main(String[] args) {


		File fileout=new File("C:/Users/Nikhil Gupta/Desktop/C-ans.out");
		File file=null;
		PrintWriter writer=null;
		Scanner in=null;
		int c,d,v,ar[],te,ans=0,p;
		try{
		 file = new File("C:/Users/Nikhil Gupta/Desktop/C-small.in");
		 in = new Scanner(file);
		 writer = new PrintWriter(fileout, "UTF-8");
		}
		catch(Exception e){}
		int T=in.nextInt();
		for(int j=1;j<=T;j++)
			{c=in.nextInt();
			d=in.nextInt();
			v=in.nextInt();
			ar=new int[d];
			for( p=0;p<d;p++)
			  ar[p]=in.nextInt();
			ans=0;
			if(v==1)
			 te=1;
			else if(v<=3)
			  te=2;
				else if(v<=7)
				te=3;
				else if(v<=15)
				te=4;
				else
				te=5;
				if(te>=1)
				{
					for( p=0;p<d;p++)
					  if(ar[p]==1)
						 break;
					if(p==d)
					  ans++;
				}
				if(te>=2)
				{
					for( p=0;p<d;p++)
						if(ar[p]==2)
						break;
					if(p==d)
						ans++;
				}
				if(te>=3)
				{
					for( p=0;p<d;p++)
						if(ar[p]==4)
						break;
					if(p==d)
						ans++;
				}
				if(te>=4)
				{
					for( p=0;p<d;p++)
						if(ar[p]==8)
						break;
					if(p==d)
						ans++;
				}
				if(te>=5)
				{
					for( p=0;p<d;p++)
						if(ar[p]==16)
						break;
					if(p==d)
						ans++;
				}
				writer.println("Case #"+j+": "+(ans));
			}
		writer.close();
	}
}
