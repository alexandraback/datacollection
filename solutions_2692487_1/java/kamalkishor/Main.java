import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.TreeSet;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("inputA.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("outputA.txt");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		TaskA solver = new TaskA();
		solver.solve(1, in, out);
		out.close();
	}
}

class TaskA {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t=in.nextInt();
        for(int i=0;i<t;i++){
            out.print("Case #" + (i + 1) + ": ");
            in.readLine();
            int a=in.nextInt();
            int n=in.nextInt();
            long mote[]=in.parseLong1D(n);
            Node nn=new Node(a,10000);
            TreeSet<Node> tset=new TreeSet<Node>();

            for(int j=0;j<n;j++){
                tset.add(new Node(mote[j],j));

            }
            int p=calc(nn,tset);
            out.println(p);
        }
    }

    private int calc(Node nn,TreeSet<Node> tset){
        boolean bb=false;
        int r=0;
        while (!tset.isEmpty()){
            Node n=tset.pollFirst();
            if(nn.val>n.val){
                nn.val=nn.val+n.val;
            }
            else{
                tset.add(n);
                bb=true;
                break;
            }
        }
        if(!bb){
            return r;
        }
        else{
            r=tset.size();
            tset.add(new Node(nn.val-1,nn.index+1));
            if(nn.val!=1){
                r=Math.min(r,calc(nn,tset)+1);
            }
            return r;
        }
    }

    class Node implements Comparable<Node>{
        long val;
        int index;
        public Node(long v,int m){
            val=v;
            index=m;
        }
        public int compareTo(Node v){
            if(v.val!=val){
                return Long.compare(val,v.val);
            }
            return Integer.compare(index,v.index);
        }
    }




}

class InputReader {
    private BufferedReader br;
    private StringTokenizer st;
    public InputReader(InputStream in) {
        br=new BufferedReader(new InputStreamReader(in));
        try {
            st=new StringTokenizer(br.readLine());
        } catch (IOException ignored) {

        }
    }

    public InputReader(String file)  {
        try {
            br=new BufferedReader(new InputStreamReader(new FileInputStream(file)));
        } catch (FileNotFoundException e) {

        }
        try {
            st=new StringTokenizer(br.readLine());
        } catch (IOException ignored) {

        }
    }

    public boolean readLine() {
        try {
            st=new StringTokenizer(br.readLine());

        } catch (IOException e) {
            return false;
        }
        catch (NullPointerException e){
            return false;
        }
        return true;
    }
    public int nextInt(){
        return Integer.parseInt(st.nextToken());
    }

    public long nextLong(){
        return Long.parseLong(st.nextToken());
    }

    public long[] parseLong1D(int n) {
        readLine();
        long r[]=new long[n];
        for(int i=0;i<n;i++){
            r[i]=nextLong();
        }
        return r;
    }


}

