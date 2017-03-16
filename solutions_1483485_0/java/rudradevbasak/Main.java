import java.io.*;
import java.util.*;
import java.math.*;

public class Main
{
	BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	StringTokenizer tokenizer=null;
	
	public static void main(String[] args) throws IOException
	{
		new Main().execute();
	}
	
	void debug(Object...os)
	{
		System.out.println(Arrays.deepToString(os));
	}
	
	int ni() throws IOException
	{
		return Integer.parseInt(ns());
	}
	
	long nl() throws IOException 
	{
		return Long.parseLong(ns());
	}
	
	double nd() throws IOException 
	{
		return Double.parseDouble(ns());
	}
		
	String ns() throws IOException 
	{
		while (tokenizer == null || !tokenizer.hasMoreTokens()) 
			tokenizer = new StringTokenizer(br.readLine());
		return tokenizer.nextToken();
	}
	
	String nline() throws IOException
	{
		tokenizer=null;
		return br.readLine();
	}
	

	//Main Code starts Here
	int totalCases, testnum;	
	

	void execute() throws IOException
	{
		totalCases = ni();
		for(testnum = 1; testnum <= totalCases; testnum++)
		{
			if(!input())
				break;
			solve();
		}
	}

	String s;
	String perm="yhesocvxduiglbkrztnwjpfmaq";
	void solve() throws IOException
	{
		System.out.printf("Case #%d: ",testnum);
		for(int i=0;i<s.length();i++)
		{
			char c=s.charAt(i);
			System.out.print(c==' ' ? ' ' : perm.charAt(c-'a'));
		}
		System.out.println();
	}

	boolean input() throws IOException
	{
		s=nline();
		return true;
	}
}