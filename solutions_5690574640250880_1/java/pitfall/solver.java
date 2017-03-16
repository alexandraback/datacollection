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
        	in=new BufferedReader(new FileReader("C-large.in"));  
        	//in=new BufferedReader(new FileReader("input.txt"));  
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
    
    
    boolean valid (int x,int y,int n,int m){
    	if (x<0) return false;
    	if (y<0) return false;
    	if (x>=n) return false;
    	if (y>=m) return false;
    	return true;
    }
    
    
    int kAdd(boolean[][] matr,int i,int j){
    	int n=matr.length;
    	int m=matr[0].length;
    	int k=0;
    	if (valid(i+1,j,n,m) && !matr[i+1][j]) k++;
    	if (valid(i+1,j+1,n,m) && !matr[i+1][j+1]) k++;
    	if (valid(i+1,j-1,n,m) && !matr[i+1][j-1]) k++;
    	if (valid(i-1,j,n,m) && !matr[i-1][j]) k++;
    	if (valid(i-1,j+1,n,m) && !matr[i-1][j+1]) k++;
    	if (valid(i-1,j-1,n,m) && !matr[i-1][j-1]) k++;
    	if (valid(i,j+1,n,m) && !matr[i][j+1]) k++;
    	if (valid(i,j-1,n,m) && !matr[i][j-1]) k++; 
    	return k;
    }    
    void add(boolean[][] matr,int i,int j){
    	int n=matr.length;
    	int m=matr[0].length;
    	if (valid(i+1,j,n,m) && !matr[i+1][j]) matr[i+1][j]=true;
    	if (valid(i+1,j+1,n,m) && !matr[i+1][j+1]) matr[i+1][j+1]=true;
    	if (valid(i+1,j-1,n,m) && !matr[i+1][j-1]) matr[i+1][j-1]=true;
    	if (valid(i-1,j,n,m) && !matr[i-1][j]) matr[i-1][j]=true;
    	if (valid(i-1,j+1,n,m) && !matr[i-1][j+1]) matr[i-1][j+1]=true;
    	if (valid(i-1,j-1,n,m) && !matr[i-1][j-1]) matr[i-1][j-1]=true;
    	if (valid(i,j+1,n,m) && !matr[i][j+1]) matr[i][j+1]=true;
    	if (valid(i,j-1,n,m) && !matr[i][j-1]) matr[i][j-1]=true;     	
    }
    
    int izm(boolean[][] a,int param,int need){
    	int n=a.length;
    	int m=a[0].length;
    	
    	
    	
    	int j=0;
    	int i=0;
    	if (param==0){
    		i=i1;
    		j=j1;
    	}else{
    		i=i2;
    		j=j2;
    	}
    	
    	if (!a[i][j]) return need;
    	
    	int l=kAdd(a, i, j);
    	if (l<=need) {
    		need-=l;
    		add(a,i,j);
    	}
    	if (param==0){
    		j1++;
    		if (j1==m) {
    			j1=0;
    			i1++;
    		}
    	}else{
    		i2++;
    		if (i2==n){
    			i2=0;
    			j2++;
    		}    			
    	}
    	return need;
    }
    
    int i1;
	int j1;
	int i2;
	int j2;
        
    void solve() throws IOException{
    	int t=readInt();
    	for (int test=1;test<=t;test++){
    		out.println("Case #"+test+":");
    		int r=readInt();
    		int c=readInt();
    		int m=readInt();
    		int need=r*c-m;
    		
    		if (test==38){
    			System.err.println(test);
    		}
    		
    		
    		if (need==1){    			
    			for (int i=0;i<r;i++){
    				for (int j=0;j<c;j++){
    					if (i+j==0) out.print("c");else out.print("*");
    				}
    				out.println();
    			}
    			continue;
    		}
    		///////////    		
    		boolean[][] a=new boolean[r][c];
    		need-=kAdd(a,0,0)+1;
    		if (need<0){    			
    			out.println("Impossible");
    			continue;
    		}
    		add(a,0,0);
    		a[0][0]=true;
    		
    		int param=0;
    		
    		i1=0;
    	    j1=0;
    		i2=0;
    		j2=0;
    		   	
    		int it=0;
    		while (need>0){
    			it++;
			   	if (it>100000) break;
			   	
			   	if (param==0){
			   		need=izm(a,param,need);			   		
			   	}else{
			   		need=izm(a,param,need);
			   	}
			   	boolean finish=false;
			   	if (need==1){
			   		for (int i=0;i<r;i++){
			   			if (finish)break;
			   			for (int j=0;j<c;j++){
			   				if (a[i][j] && kAdd(a,i,j)==1) {
			   					need=0;
			   					add(a,i,j);
			   					finish=true;
			   					break;
			   				}
			   			}
			   		}
			   	}
			   	if (finish) break;
			   	param=1-param;
    		}
    		
    		if (need==0){
    			for (int i=0;i<r;i++){
    				for (int j=0;j<c;j++){
    					if (i+j==0)out.print("c");else {
    						if (a[i][j]) out.print(".");else out.print("*");
    					}
    				}
    				out.println();
    			}
    		}else{
    			out.println("Impossible");
    		}
    		
    		
    		
    		    		
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