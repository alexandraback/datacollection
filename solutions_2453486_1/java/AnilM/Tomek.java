import java.util.*;
public class Tomek{
	public static void main(String[] args){
		Scanner in=new Scanner(System.in);
		int T=in.nextInt();
		for(int c=1;c<=T;c++)
		{
			String[] s1=new String[4];
			String[] s2=new String[4];
			for(int i=0;i<4;i++)
			s2[i]="";
			for(int i=0;i<4;i++)
			s1[i]=in.next();
			int DotFound=0,OwinFound=0,XwinFound=0;
			String s3="",s4="";
			for(int i=0;i<4;i++)
			for(int j=0;j<4;j++){
				s2[i]+=s1[j].charAt(i);
				if(i==j)
				s3+=s1[i].charAt(i);
				if(i+j==3)
				s4+=s1[i].charAt(j);
			}
			for(int i=0;i<4;i++)
			{
				if(s1[i].indexOf('.')!=-1)
				DotFound=1;
				else if(s1[i].indexOf('O')==-1)
				XwinFound=1;
				else if(s1[i].indexOf('X')==-1)
				OwinFound=1;
			}
			for(int i=0;i<4;i++)
			{
				if(s2[i].indexOf('.')!=-1)
				DotFound=1;
				else if(s2[i].indexOf('O')==-1)
				XwinFound=1;
				else if(s2[i].indexOf('X')==-1)
				OwinFound=1;
			}
				if(s3.indexOf('.')!=-1)
				DotFound=1;
				else if(s3.indexOf('O')==-1)
				XwinFound=1;
				else if(s3.indexOf('X')==-1)
				OwinFound=1;
				if(s4.indexOf('.')!=-1)
				DotFound=1;
				else if(s4.indexOf('O')==-1)
				XwinFound=1;
				else if(s4.indexOf('X')==-1)
				OwinFound=1;
			if(XwinFound==1)
			System.out.println("Case #"+c+": X won");
			else if(OwinFound==1)
			System.out.println("Case #"+c+": O won");
			else if(DotFound==1)
			System.out.println("Case #"+c+": Game has not completed");
			else
			System.out.println("Case #"+c+": Draw");
		}
	}
}
