import java.io.BufferedInputStream;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.*;



import static java.lang.Math.*; 
import static java.util.Arrays.*;
import static java.lang.Integer.*;
import static java.lang.Character.*;  


public class C {
	
	Scanner scan;
	public C(Scanner s) {
		this.scan = s;
	}
	boolean[][]M;
	int[]L;
	String res ="";
	HashSet<String>V=new HashSet<>();
	
	class nd implements Comparable<nd>{
		int idx;
		int lb;
		ArrayList<nd>ch=new ArrayList<>();
		boolean v;
		@Override
		public int compareTo(nd o) {
			return lb - o.lb;
		}
		nd first() {
			for(nd x:ch)if(!x.v)return x;
			return null;
		}
	}
	
	boolean acc(nd p, nd q,  boolean[]v) {
		if(p==q)return true;
		v[p.idx]=true;
		for(nd qq:p.ch){
			if(v[qq.idx] || qq.v)continue;
			if(acc(qq,q,v))return true;
		}
		return false;
	}
	
	boolean acc(Stack<nd> S, nd q) {
		for(nd x:S)if(acc(x,q,new boolean[n]))return true;
		return false;
	}
	
	void doit(nd p, Stack<nd>s, int slim){
		res += p.lb;
		p.v=true;
		
		while(true) {
			dom(p,s, slim);
			nd mf = p.first();
			if(mf==null)return;
			for(int i=slim;i<s.size();i++){
				nd par = s.get(i);
				nd pf = par.first();
				if(pf==null)continue;
				if(pf.compareTo(mf)<0)return;
			}
			s.add(p);
			doit(mf, s, slim);
			s.pop();
		}
	}
	int n;
	
	void dom(nd p, Stack<nd>s, int slim){
		for(nd q:p.ch) {
			if(q.v)continue;
			if(!acc(s, q) || slim==1) {
				for(nd pq:p.ch) {
					if(pq.v)continue;
					s.add(p);
					doit(pq, s, 1);
					s.pop();
					if(pq==q)break;
				}
			}
		}
	}
	
	public String solve() {
		 n = scan.nextInt();
		int m = scan.nextInt();
		L = new int[n];
		nd minn=null;
		nd[]G = new nd[n];
		for(int i=0;i<n;i++){
		
			G[i]=new nd();
			G[i].idx=i;
			G[i].lb=scan.nextInt();
			if(minn==null || G[i].compareTo(minn)<0)minn=G[i];
		}
		M=new boolean[n][n];
		
		for(int i=0;i<m;i++){
			int a = scan.nextInt()-1;int b = scan.nextInt()-1;
			G[a].ch.add(G[b]);G[b].ch.add(G[a]);
		}
		for(nd p:G)Collections.sort(p.ch);
		
		
		doit(minn, new Stack<nd>(),0);
		if(res.length()!=5*n){
			System.err.println("Error");
			System.err.println(res);
			
		}

		
		return res;
	}
	int intLine(){
		return parseInt(scan.nextLine());
	}
	static int c;
	public static void main(String[] args) throws Exception{
		Locale.setDefault(Locale.US);
		String cn = C.class.getName();
		String sampleName = cn+"-sample.in";
		String smallName = cn+"-small-attempt6.in";
		String largeName = cn+"-large.in";
		String name = smallName;
		String outName = name.substring(0, name.indexOf('.'))+".out";
		InputStream in = new BufferedInputStream(new FileInputStream(name));
		PrintStream out = new PrintStream(new File(outName));
		//PrintStream out = System.out;
		Scanner scan = new Scanner(in);
		
		int N = parseInt(scan.nextLine());
		for(c=1;c<=N;c++) {
			String res = new C(scan).solve();
			out.printf("Case #%d: %s\n",c, res);
		//	System.err.println(c + " done");
		}
		
		System.err.println("All done");
		
	}

}


