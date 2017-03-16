import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.ArrayDeque;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Queue;

import org.omg.Messaging.SyncScopeHelper;

public class Main {
	public static void main(String[] args) throws NumberFormatException,
	IOException {Solve solve = new Solve();solve.solve();}
}
class Solve{
	void dump(int[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");System.out.println();}
	void dump(int[]a,int n){for(int i=0;i<a.length;i++)System.out.printf("%"+n+"d",a[i]);System.out.println();}
	void dump(long[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]+" ");System.out.println();}
	void dump(char[]a){for(int i=0;i<a.length;i++)System.out.print(a[i]);System.out.println();}
	String itob(int a,int l){return String.format("%"+l+"s",Integer.toBinaryString(a)).replace(' ','0');}
	void solve() throws NumberFormatException, IOException{
		final ContestScanner in = new ContestScanner("in.txt");
		Writer out = new Writer("out.txt");
		int test = in.nextInt();
		for(int T=1; T<=test; T++){
			final int n = in.nextInt()-2;
			final int lim = in.nextInt();
			char[] jam = new char[n+2];
			jam[0] = jam[n+1] = '1';
			int s = 0;
			long t = (1L<<n)-1;
			int count = 0;
			out.format("Case #%d:\n", T);
			BigInteger[] prime = new BigInteger[10];
			int[] smallPrime = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
			for(int i=0; i<10; i++){
				prime[i] = BigInteger.valueOf(smallPrime[i]);
			}
			int[] list = new int[9];
			out:for(long i=s; i<=t; i++){
				for(int j=0; j<n; j++){
					jam[j+1] = (i&1L<<j)==0?'0':'1';
				}
				String str = String.valueOf(jam);
				for(int j=2; j<=10; j++){
					BigInteger bi = new BigInteger(str, j);
					int div = -1;
					for(int k=0; k<10; k++){
						if(bi.mod(prime[k]).equals(BigInteger.ZERO)){
							div = k;
							break;
						}
					}
					if(div==-1) continue out;
					list[j-2] = smallPrime[div];
				}
				count++;
				String res = str+" ";
				for(int j=0; j<list.length; j++){
					res += " "+list[j];
				}
				out.println(res);
				if(count>=lim) break;
			}
		}
		out.close();
	}
}

class MultiSet<T> extends HashMap<T, Integer>{
	@Override
	public Integer get(Object key){return containsKey(key)?super.get(key):0;}
	public void add(T key,int v){put(key,get(key)+v);}
	public void add(T key){put(key,get(key)+1);}
	public void sub(T key)
	{final int v=get(key);if(v==1)remove(key);else put(key,v-1);}
}
class Timer{
	long time;
	public void set(){time=System.currentTimeMillis();}
	public long stop(){return time=System.currentTimeMillis()-time;}
	public void print()
	{System.out.println("Time: "+(System.currentTimeMillis()-time)+"ms");}
	@Override public String toString(){return"Time: "+time+"ms";}
}
class Writer extends PrintWriter{
	public Writer(String filename)throws IOException
	{super(new BufferedWriter(new FileWriter(filename)));}
	public Writer()throws IOException{super(System.out);}
}
class ContestScanner {
	private InputStreamReader in;private int c=-2;
	public ContestScanner()throws IOException 
	{in=new InputStreamReader(System.in);}
	public ContestScanner(String filename)throws IOException
	{in=new InputStreamReader(new FileInputStream(filename));}
	public String nextToken()throws IOException {
		StringBuilder sb=new StringBuilder();
		while((c=in.read())!=-1&&Character.isWhitespace(c));
		while(c!=-1&&!Character.isWhitespace(c)){sb.append((char)c);c=in.read();}
		return sb.toString();
	}
	public String readLine()throws IOException{
		StringBuilder sb=new StringBuilder();if(c==-2)c=in.read();
		while(c!=-1&&c!='\n'&&c!='\r'){sb.append((char)c);c=in.read();}
		return sb.toString();
	}
	public long nextLong()throws IOException,NumberFormatException
	{return Long.parseLong(nextToken());}
	public int nextInt()throws NumberFormatException,IOException
	{return(int)nextLong();}
	public double nextDouble()throws NumberFormatException,IOException 
	{return Double.parseDouble(nextToken());}
}