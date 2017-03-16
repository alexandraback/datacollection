import java.io.File;import java.io.FileOutputStream;import java.io.FileReader;
import java.io.IOException;import java.io.PrintStream;import java.io.PrintWriter;
import java.util.ArrayList;import java.util.Arrays;import java.util.Scanner;

public class B {
    
	static int[][] ref,t ; static  int N , M;
    public static void main(String[] arg)throws IOException{
    	Scanner in=new Scanner(new File("B.in"));
    	PrintStream o=System.out;
    	int test=in.nextInt(); 
    	for ( int ind=1; ind<=test ; ind++){
    		N=in.nextInt(); M=in.nextInt();
    		ref=new int[N][M]; t=new int[N][M];
    		for(int i=0; i<N; i++) 	for(int j=0; j<M; j++){ 	ref[i][j]=in.nextInt();	} // init ref
    		for(int i=0; i<N; i++) 	for(int j=0; j<M; j++){ 	t[i][j]=2;	} // init t
    		treat(1);
    		if(t_eq_ref()) o.println("YES");
    		else o.println("NO");
    	}
    }
	private static boolean t_eq_ref() {
		for(int i=0; i<N; i++) 
			for(int j=0; j<M; j++)
				if(t[i][j]!=ref[i][j])
					return false;
		return true;
	}
	private static void treat(int a) {
			String sM=""; for( int i=0; i<M; i++) sM+=a;
			String sN=""; for( int i=0; i<N; i++) sN+=a;
		    //horizontal
			for( int i=0; i<N; i++){
		    	String temp="";
		    	for(int j=0; j<M; j++) 	temp+=ref[i][j];
		    	if(temp.equals(sM)){
		    		for(int k=0; k<M; k++)
		    			t[i][k]=a;
		    	}
			}
			//vertical
			for( int j=0; j<M; j++){
		    	String temp="";
		    	for(int i=0; i<N; i++) 	temp+=ref[i][j];
		    	if(temp.equals(sN)){
		    		for(int k=0; k<N; k++)
		    			t[k][j]=a;
		    	}
			}
	}
}