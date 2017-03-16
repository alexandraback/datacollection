import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.Reader;
import java.io.StreamTokenizer;

public class Solution {
	  public static void main(String[] a) throws IOException {
	      sumfile("A-large.in");
	  }


	  static void sumfile(String filename) throws IOException {
	    Reader r = new BufferedReader(new FileReader(filename));
	    StreamTokenizer stok = new StreamTokenizer(r);
	    stok.parseNumbers();
	    
	    stok.nextToken();
	    int T = (int)stok.nval;
	    for(int i=0;i<T;i++){
	    	double sum = 0;
	    	double sum2=0;
	    	stok.nextToken();
	    	int N=(int)stok.nval;
	    	int M=N;
	    	int[] alln = new int[N];
	    	for(int j=0;j<N;j++){
	    		stok.nextToken();
	    		int mi=(int)stok.nval;
	    		alln[j]=mi;
	    		sum=sum+mi;
	    	}
	    	System.out.print("Case #"+(i+1)+":");
	    	for(int j=0;j<N;j++){
	    		if(sum*2/N-alln[j]<=0){
	    			M--;
	    			//System.out.println("ddddd");
	    		}
	    		else{
	    			sum2+=alln[j];
	    		}
	    	}
	    	for(int j=0;j<N;j++){
	    		System.out.print(" ");
	    		if(sum*2/N-alln[j]<=0){
	    			System.out.printf("%.6f", 0.000000);
	    		}
	    		else{
	    			System.out.printf("%.6f", ((sum+sum2)/M-alln[j])/sum*100);
	    		}
	    		
	    	}
	    	System.out.println();
	    }
	  }
}
