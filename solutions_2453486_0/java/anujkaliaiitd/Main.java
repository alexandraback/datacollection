import java.security.acl.Owner;
import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File(
				"input.txt")));
		int T=Integer.parseInt(in.readLine());
		for(int t=0;t<T;t++)
			{
			char A[][]=new char[4][4];
			char X[][]=new char[4][4];
			char O[][]=new char[4][4];
			boolean empty=false;
			for(int i=0;i<4;i++)
				A[i]=in.readLine().toCharArray();
			for(int i=0;i<4;i++)
				{
				for(int j=0;j<4;j++)
					{
					if(A[i][j]=='.')
						empty=true;
					if(A[i][j]=='T')
						{
						X[i][j]='X';
						O[i][j]='O';
						}
					else
						{
						X[i][j]=A[i][j];
						O[i][j]=A[i][j];
						}
					}
				}
			boolean xwin=false,owin=false;
			//check row
			for(int i=0;i<4;i++)
				{
				boolean xrow=true;
				boolean orow=true;
				for(int j=0;j<4;j++)
					{
					if(X[i][j]!='X')
						xrow=false;
					if(O[i][j]!='O')
						orow=false;
					}
				if(xrow)
					xwin=true;
				if(orow)
					owin=true;
				}
			
			//check col
			for(int j=0;j<4;j++)
				{
				boolean xcol=true;
				boolean ocol=true;
				for(int i=0;i<4;i++)
					{
					if(X[i][j]!='X')
						xcol=false;
					if(O[i][j]!='O')
						ocol=false;
					}
				if(xcol)
					xwin=true;
				if(ocol)
					owin=true;
				}
			
			//check diagonal 1
			boolean xdiag1=true,odiag1=true,xdiag2=true,odiag2=true;
			for(int i=0;i<4;i++)
				{
				if(X[i][i]!='X')
					xdiag1=false;
				if(O[i][i]!='O')
					odiag1=false;
				if(X[i][3-i]!='X')
					xdiag2=false;
				if(O[i][3-i]!='O')
					odiag2=false;
				}
			if(xdiag1||xdiag2)
				xwin=true;
			if(odiag1||odiag2)
				owin=true;
			if(xwin&&!owin)
				out.println("Case #"+(t+1)+": X won");
			if(!xwin&&owin)
				out.println("Case #"+(t+1)+": O won");
			if(xwin&&owin)
				out.println("Case #"+(t+1)+": Draw");
			if(!xwin&&!owin)
				{
				if(!empty)
					out.println("Case #"+(t+1)+": Draw");
				else
					out.println("Case #"+(t+1)+": Game has not completed");
				}
				
			in.readLine();
			}
		out.close();
		}
	
	}

//must declare new classes here