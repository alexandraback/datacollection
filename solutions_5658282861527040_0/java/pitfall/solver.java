import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;
import java.util.TreeMap;
 
public class solver implements Runnable {         
        BufferedReader in;
        PrintWriter out;
        StringTokenizer tok = new StringTokenizer("");
 
        void init() throws FileNotFoundException {
        	in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);   
            
            in=new BufferedReader(new FileReader("B-small-attempt0.in"));
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
        
        
        
        
        
        
        void solve() throws IOException{
        	
        	int t=readInt();
        	for (int test=1;test<=t;test++){
        		out.print("Case #"+test+": ");
        		
        		int a=readInt();
        		int b=readInt();
        		int k=readInt();
        		int ans=0;
        		for (int i=0;i<a;i++){
        			for (int j=0;j<b;j++){
        				if ((i&j)<k) ans++;
        			}
        		}
        		out.println(ans);
        	}
        	
        	
        		    	    	
        }
}