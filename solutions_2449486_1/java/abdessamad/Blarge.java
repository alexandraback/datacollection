import java.io.File;import java.io.FileOutputStream;import java.io.FileReader;
import java.io.IOException;import java.io.PrintStream;import java.io.PrintWriter;
import java.util.ArrayList;import java.util.Arrays;import java.util.Scanner;

public class Blarge {
    
	static int[][] ref,t ; static  int N , M;
    public static void main(String[] arg)throws IOException{
    	Scanner in=new Scanner(new File("B.in"));
    	PrintStream o=System.out;
    	int test=in.nextInt(); 
    	for ( int ind=1; ind<=test ; ind++){
    		N=in.nextInt(); M=in.nextInt();
    		ref=new int[N][M]; t=new int[N][M];
    		for(int i=0; i<N; i++) 	for(int j=0; j<M; j++){ 	ref[i][j]=in.nextInt();	} // init ref
    		for(int i=0; i<N; i++) 	for(int j=0; j<M; j++){ 	t[i][j]=100;	} // init t
    		treat();
    		if(t_eq_ref()) o.println("Case #"+ind+": YES");
    		else o.println("Case #"+ind+": NO");
    	}
    }
	private static boolean t_eq_ref() {
		for(int i=0; i<N; i++) 
			for(int j=0; j<M; j++)
				if(t[i][j]!=ref[i][j])
					return false;
		return true;
	}
	private static void treat() {
			for( int i=0; i<N; i++){
		    	int Max=ref[i][0];
		    	for(int j=1; j<M; j++) if(ref[i][j]>Max) Max=ref[i][j];
		    	boolean allgreater=true;
		    	for(int j=0; j<M; j++) if(t[i][j]<Max){allgreater=false; break;}
		    	 if(allgreater){
		    	    for(int j=0; j<M; j++) t[i][j]=Max; //fill line of t
		    	 }
		    }
			for( int j=0; j<M; j++){
		    	int Max=ref[0][j];
		    	for(int i=1; i<N; i++) 	      	if(ref[i][j]>Max) Max=ref[i][j];
		    	boolean allgreater=true;
		    	for(int i=0; i<N; i++) if(t[i][j]<Max){allgreater=false; break;}
		    	 if(allgreater){
		    	    for(int i=0; i<N; i++) t[i][j]=Max; //fill line of t
		    	 }
		   	}
			
	}

}