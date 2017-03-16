import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.StringTokenizer;
import java.util.TreeSet;



public class solver {
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok;
    
    String readString() throws IOException{
        while (tok==null || !tok.hasMoreTokens()){
            try{
                tok=new StringTokenizer(in.readLine());             
            }
            catch(Exception e){
                return null;
            }            
        }
        return tok.nextToken();
    }
    int readInt() throws NumberFormatException, IOException{
        return Integer.parseInt(readString());
    }
    long readLong() throws NumberFormatException, IOException{
        return Long.parseLong(readString());
    }
    double readDouble() throws NumberFormatException, IOException{
        return Double.parseDouble(readString());
    }
    
    final static boolean OJ=System.getProperty("ONLINE_JUDGE")!=null;
    
    
    void init() throws FileNotFoundException{        
        if (OJ){
            in=new BufferedReader(new InputStreamReader(System.in));
            out=new PrintWriter(System.out);  
        }else{
        	in=new BufferedReader(new FileReader("B-large.in"));            
            out=new PrintWriter("output.txt");  
        }
    }    
    int[] iMas(int n) throws NumberFormatException, IOException{
        int[] a=new int[n];
        for (int i=0;i<n;i++){
            a[i]=readInt();
        }
        return a;
    }
    
    
    int gcd (int a, int b) {
    	if (b == 0)
    		return a;
    	else
    		return gcd (b, a % b);
    }   
    
    
    
    class Pair implements Comparable<Pair>{
    	int b;
    	int d;
    	int num;
    	Pair(int x,int y,int i){
    		b=x;
    		d=y;
    		num=i;
    	}
    	    	
    	@Override
    	public int compareTo(Pair o) {    		
    		return b-o.b;
    	}   	    	    	
    }
    
    
    
    
        
    void solve() throws IOException{
    	int t=readInt();
    	for (int test=1;test<=t;test++){
    		double c=readDouble();
    		double f=readDouble();
    		double x=readDouble();
    		int n_n=100000;
    		double[] costs=new double[(int)n_n];
    		costs[0]=0;    		
    		double answer=x/2.0;
    		
    		int num=0;
    		
    		for (int i=1;i<n_n;i++){
    			double v=2+f*(i-1);
    			costs[i]=costs[i-1]+c/v;
    			double nv=2+(double)f*i;
    			double na=costs[i]+x/nv;
    			if (na<answer){
    				answer=na;
    				num=i;
    			}
    		}
    		out.println("Case #"+test+": "+answer);
    		
    		
    		
    		
    	}
    	
    	
    }
    
    
    void run() throws NumberFormatException, IOException{
        init();
         long h=System.currentTimeMillis();        
        solve();
         System.err.println(System.currentTimeMillis()-h);
        out.close();
    }
    
    
    

    
    public static void main(String[] args) throws NumberFormatException, IOException {
        new solver().run();
    }

}