import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File("input.txt")));
		int T=Integer.parseInt(in.readLine());
		for(int t=0;t<T;t++)
			{
			String S[]=in.readLine().split(" ");
			int X=Integer.parseInt(S[0]);
			int Y=Integer.parseInt(S[1]);
			String ans="";
			if(X>0)
				{
				for(int i=0;i<X;i++)
					{
					ans+="W";
					ans+="E";
					}
				}
			if(X<0)
				{
				for(int i=0;i<-X;i++)
					{
					ans+="E";
					ans+="W";
					}
				}
			
			if(Y>0)
				{
				for(int i=0;i<Y;i++)
					{
					ans+="S";
					ans+="N";
					}
				}
			if(Y<0)
				{
				for(int i=0;i<-Y;i++)
					{
					ans+="N";
					ans+="S";
					}
				}
			out.println("Case #"+(t+1)+": "+ans);
			}
		out.close();
		}
	}

//must declare new classes here