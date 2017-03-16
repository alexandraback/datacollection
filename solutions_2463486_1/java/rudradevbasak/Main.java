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
	
	BigInteger[] arr;
	int top;
	
	String reverse(String s) {
		return ((new StringBuffer(s)).reverse()).toString();
	}
	
	void generate(String s, int sum) {
		if(s.length()>25) return;
		
		if(s.length()>0) {
			BigInteger b = new BigInteger(s + reverse(s));
			//debug(b);
			arr[top++]=b.multiply(b);
		}
		
		for(int i=0;i<=3;i++) {
			if(s.length()==0 && i==0) continue;
			if(sum + i*i < 10) {
				BigInteger b = new BigInteger(s + String.valueOf(i) + reverse(s));
				//debug(b);
				arr[top++]=b.multiply(b);
			}
		}
		
		for(int i=0;i<=2;i++) {
			if(s.length()==0 && i==0) continue;
			int nsum = sum + 2*i*i;
			if(nsum < 10) {
				generate(s + String.valueOf(i), nsum);
			}
		}
	}

	void execute() throws IOException
	{
		arr=new BigInteger[1000000];
		top=0;
		generate("",0);
		
		//debug(top);
				
		totalCases = ni();
		for(testnum = 1; testnum <= totalCases; testnum++)
		{
			if(!input())
				break;
			solve();
		}
	}
	
	BigInteger A,B;

	void solve() throws IOException
	{
		int cnt=0;
		for(int i=0; i<top; i++) {
			if(arr[i].compareTo(A) >=0 && arr[i].compareTo(B) <= 0) {
				cnt++;
			}
		}
		
		System.out.printf("Case #%d: %d\n", testnum, cnt);
	}

	boolean input() throws IOException
	{
		A = new BigInteger(ns());
		B = new BigInteger(ns());
		return true;
	}
}