import java.util.*;
import java.io.PrintWriter;
import java.io.File;
public class b {
	public static void main(String[] args) {


		File fileout=new File("C:/Users/Nikhil Gupta/Desktop/C-ans.out");
		File file=null;
		PrintWriter writer=null;
		Scanner pin=null;
		int x,q,counter,in,record[],history[];
		String qo[],s,a,p;

		try{
		 file = new File("C:/Users/Nikhil Gupta/Desktop/C-small.in");
		 pin = new Scanner(file);
		 writer = new PrintWriter(fileout, "UTF-8");
		}
		catch(Exception e){}
		int T=pin.nextInt();
		for(int j=1;j<=T;j++)
			{q=pin.nextInt();
                         qo=new String[q];
                         x=pin.nextInt();
			 s=pin.next();
			p="i";counter=0;
		//	record=new int[2];
		//	history=new int[2];
			for(int l=0;l<q;l++)
				{qo[l]=s.charAt(l)+"";}
			a="1";in=0;
		//	while(true)
			//{
			for(;in<q*x;in++)
					{
           a=mul(a,qo[in%(q)]);
					if(a.equals(p) && counter<2 /*&& bo==false*/)
						{counter++;
						 if(counter==1)
							{p="j";//record[0]=in+1;
							}
						 else if(counter==2)
							{p="k";//record[1]=in+1;
							}
							a="1";
						}
						if(in==((q*x)-1) && counter==2 && a.equals(p))
							counter=3;

					// else if(bo==true) {bo=false;}
					}
		//	if(counter==3)break;
			//else if(counter==0)break;
			//else if(counter==2 && history[1]!=record[1]){in=record[1];history[1]=record[1];a="j";p="j";/*bo=true;*/counter=1;}
			//else if(counter==1 && history[0]!=record[0]){in=record[0];history[0]=record[0];a="i";p="i";/*bo=true;*/counter=0;}
		//	else if( history[1]==record[1])
			//else
			// break;
		//	}
			if(counter==3)
				writer.println("Case #"+j+": YES");
			else
				{writer.println("Case #"+j+": NO");}
			}
		writer.close();
	}

static String mul(String a,String b)
{String f;
	if((a.charAt(0)=='-' && b.charAt(0)!='-'))
	{f="-"; a=a.charAt(1)+"";}
	else if ((a.charAt(0)!='-' && b.charAt(0)=='-'))
	{f="-"; b=b.charAt(1)+"";}
	else
	f="";

if(a.equals("1") && b.equals("1"))
  f=f+"1";
else if(a.equals("1") && b.equals("i"))
  f=f+"i";
else if(a.equals("1") && b.equals("j"))
  f=f+"j";
else if(a.equals("1") && b.equals("k"))
f=f+"k";
else if(a.equals("i") && b.equals("1"))
f=f+"i";
else if(a.equals("i") && b.equals("i"))
 if(f=="-")f="1"; else f="-1";
else if(a.equals("i") && b.equals("j"))
f=f+"k";
else if(a.equals("i") && b.equals("k"))
if(f=="-")f="j"; else f="-j";
else if(a.equals("j") && b.equals("1"))
f=f+"j";
else if(a.equals("j") && b.equals("i"))
if(f=="-")f="k"; else f="-k";
else if(a.equals("j") && b.equals("j"))
if(f=="-")f="1"; else f="-1";
else if(a.equals("j") && b.equals("k"))
f=f+"i";
else if(a.equals("k") && b.equals("1"))
f=f+"k";
else if(a.equals("k") && b.equals("i"))
f=f+"j";
else if(a.equals("k") && b.equals("j"))
if(f=="-")f="i"; else f="-i";
else
if(f=="-")f="1"; else f="-1";
return f;
}
}
