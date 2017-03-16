import java.io.*;
import static java.lang.Math.*;
import java.util.*;
public class B {
    int x,y,len;
    boolean flg=true; char[] ans;
    
    public class Ret{
	int n;
	int x,y;
	char[] ch;
	public Ret(int n,int x,int y,char[] ch){
	    this.x=x;this.y=y;this.ch=ch;this.n=n;
	}
	public String toString(){
	    return "("+x+","+y+") n:"+n+", ch="+new String(ch);
	}
    }
    String solve(int x, int y){
	this.x=x;this.y=y;
	boolean[][] flg = new boolean[1000][1000];
	for(int i=0;i<abs(x)*2;i++){
	    Arrays.fill(flg[i],false);
	}
	List<Ret> que = new ArrayList<Ret>(500);
	que.add(new Ret(0,0,0,new char[500]));
	while(que.size()>0){
	    Ret q = que.remove(0);
	    if(flg[500+q.x][500+q.y]) continue;
	    flg[500+q.x][500+q.y]=true;
	    //	    System.err.println(q);
	    if(q.x==x && q.y==y) return new String(Arrays.copyOfRange(q.ch,0,q.n));
	    q.ch[q.n]='E';
	    que.add(new Ret(q.n+1,q.x+q.n+1,q.y,q.ch.clone()));
	    q.ch[q.n]='W';
	    que.add(new Ret(q.n+1,q.x-(q.n+1),q.y,q.ch.clone()));
	    q.ch[q.n]='N';
	    que.add(new Ret(q.n+1,q.x,q.y+q.n+1,q.ch.clone()));
	    q.ch[q.n]='S';
	    que.add(new Ret(q.n+1,q.x,q.y-(q.n+1),q.ch.clone()));
	}
	return "";
    }
    public void run(String[] args) {
	try{
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    int T = Integer.parseInt(br.readLine());
	    for(int t=1;t<=T;t++){
		String[] line = br.readLine().split(" ");
		int x=Integer.parseInt(line[0]);
		int y=Integer.parseInt(line[1]);
		System.out.printf("Case #%d: %s\n",t,solve(x,y));
	    }
	    
	}catch(Exception e){ e.printStackTrace(); }
    }
    public static void main(String[] args){
	Locale.setDefault(Locale.US);
	(new B()).run(args);
    }
}
