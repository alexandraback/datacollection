import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;

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
	final static String caseStr = "Case #%d: %s\n";
	void solve() throws NumberFormatException, IOException{
//		final ContestScanner in = new ContestScanner();
		final ContestScanner in = new ContestScanner("in.txt");
//		Writer out = new Writer();
		Writer out = new Writer("out.txt");
		int test = in.nextInt();
		for(int T=1; T<=test; T++){
			int n = in.nextInt();
			int[] bff = new int[n];
			for(int i=0; i<n; i++){
				bff[i] = in.nextInt()-1;
			}
			HashSet<Pair> pairs = new HashSet<>();
			for(int i=0; i<n; i++){
				for(int j=i+1; j<n; j++){
					if(bff[i]==j && bff[j]==i){
						pairs.add(new Pair(i, j));
					}
				}
			}
			List<Integer>[] node = new List[n];
			for(int i=0; i<n; i++) node[i] = new ArrayList<>();
			for(int i=0; i<n; i++){
				node[bff[i]].add(i);
			}
			int max = getLontgestLoop(bff, n);
			int len = 0;
			for(Pair p: pairs){
				int p1 = getLongestPath(p.a, p.b, 0, node);
				int p2 = getLongestPath(p.b, p.a, 0, node);
				len += p1+p2;
			}
			max = Math.max(len, max);
			out.format(caseStr, T, max);
			out.flush();
		}
		out.close();
	}
	
	int getLongestPath(int cur, int par, int dep, List<Integer>[] node){
		int max = 0;
		for(int i: node[cur]){
			if(i==par) continue;
			max = Math.max(max, getLongestPath(i, cur, dep+1, node));
		}
		return max+1;
	}
	
	int getLontgestLoop(int[] bff, int n){
		int[] dist = new int[n];
		int ans = 0;
		for(int i=0; i<n; i++){
			Arrays.fill(dist, -1);
			ans = Math.max(ans, dfs(bff, i, dist, 0));
		}
		return ans;
	}
	
	int dfs(int[] bff, int pos, int[] dist, int dep){
		if(dist[pos] != -1){
			return dep-dist[pos];
		}
		dist[pos] = dep;
		return dfs(bff, bff[pos], dist, dep+1);
	}
}

class Pair{
	int a, b;
	int id;
	Pair(int a, int b){
		this.a = a;
		this.b = b;
		id = Math.min(a, b)<<10 | Math.max(a, b);
	}
	@Override
	public int hashCode() {
		return id;
	}
	@Override
	public boolean equals(Object arg0) {
		return id==((Pair)arg0).id;
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