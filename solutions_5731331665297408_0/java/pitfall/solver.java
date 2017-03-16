import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.StringTokenizer;
 
public class solver implements Runnable {         
        BufferedReader in;
        PrintWriter out;
        StringTokenizer tok = new StringTokenizer("");
 
        void init() throws FileNotFoundException {
        	in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);   
            
            in=new BufferedReader(new FileReader("C-small-attempt0.in"));
            //in=new BufferedReader(new FileReader("input.txt"));
            out=new PrintWriter("output.txt");
        }
 
        String readString() throws IOException {
                while (!tok.hasMoreTokens()) {
                        try {
                                tok = new StringTokenizer(in.readLine());
                        } catch (Exception e) {
                                return null;
                        }
                }
                return tok.nextToken();
        }
 
        int readInt() throws IOException {
                return Integer.parseInt(readString());
        }
 
        long readLong() throws IOException {
                return Long.parseLong(readString());
        }
 
        double readDouble() throws IOException {
                return Double.parseDouble(readString());
        }
 
        public static void main(String[] args) {
                new Thread(null, new solver(), "", 128 * (1L << 20)).start();
        }
 
        
 
        public void run() {
                try {
                        init();
                        solve();
                        out.close();                        
                } catch (IOException e) {
                	    System.err.println(e.getMessage());
                        System.exit(-1);
                }
        }
        
        
        
        String[] s;
        int n;
        BigInteger bi;
        int[] a;
        boolean[][] dist;
        BigInteger cur;        
        boolean[] zed;
        int dfsPos;
        
        boolean dfs(){
        	int cur=dfsPos;        	
        	zed[a[cur]]=true;
        	if (cur==n-1) return true;
        	while (true){
        		if (dfsPos==n-1) return true;
        		if (dist[a[cur]][a[dfsPos+1]]) {
            		dfsPos++;
            		if (dfs()) return true;
            	}else return false;        		
        	}       	
        }
        
        void brut(int pos){
        	if (pos==n) {
        		for (int i=0;i<n;i++){
        			zed[i]=false;
        		}
        		dfsPos=0;
        		if (!dfs()) return;
        		
        		String st="";
        		for (int i=0;i<n;i++){
        			st+=s[a[i]];
        		}
        		cur=new BigInteger(st);
        		
        		if (bi==null || (bi!=null && cur.compareTo(bi)<0)){
        			bi=cur;
        		}
        		return;
        	}
        	
        	for (int i=pos;i<n;i++){
        		int t=a[i];
        		a[i]=a[pos];
        		a[pos]=t;
        		brut(pos+1);        		
        		t=a[i];
        		a[i]=a[pos];
        		a[pos]=t;
        	}        	
        }
        
        
        void solve() throws IOException{        	
        	int t=readInt();        	
        	
        	for (int test=1;test<=t;test++){
        		out.print("Case #"+test+": ");        		
        		
        		n=readInt();
        		s=new String[n];
        		a=new int[n];
        		for (int i=0;i<n;i++){
        			a[i]=i;
        		}
        		int m=readInt();
        		bi=null;
        		zed=new boolean[n];
        		
        		dist=new boolean[n][n];
        		
        		for (int i=0;i<n;i++){
        			s[i]=readString();        			
        		}
        		
        		for (int i=0;i<m;i++){
        			int x=readInt()-1;
        			int y=readInt()-1;
        			dist[x][y]=dist[y][x]=true;
        		}
        		brut(0);
        		out.println(bi.toString());        		        		
        	}        		    	    	
        }
}