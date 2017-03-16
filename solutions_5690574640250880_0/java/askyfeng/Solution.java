package interview;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;

public class Solution {
	
	private Solution(){}
	
	public static void main(String[] args) throws IOException{
		String file = "C:/zfeng/C-small-attempt3.in";
		String output = "C:/zfeng/C-small-attempt3.out";
		//String file = "C:/zfeng/test2.txt";
		//String output = "C:/zfeng/output.txt";
		BufferedReader content =  new BufferedReader(new FileReader(file));	
		PrintWriter outputFile = new PrintWriter(new FileWriter(output));
		
		int num_cases = Integer.parseInt( content.readLine() );
		
		for( int i = 1; i<=num_cases; i++ ){
			String dataRow = content.readLine();
			String[] dataArray = dataRow.split(" ");
			int R = Integer.parseInt( dataArray[0] );
			int C = Integer.parseInt( dataArray[1] );
			int M = Integer.parseInt( dataArray[2] );
			
			outputFile.println( "Case #"+i+":");
			int good = R*C-M;
			
			if( C==1 || R==1 || good==1){
				drawPattern1( R, C, M, outputFile);
				continue;
			}
			
			if( good>3 && ( R==2 || C==2 ) ){
				if (good%2==0)
					drawPattern2( R, C, M, outputFile);
				else
					outputFile.println( "Impossible");
				continue;
			}
			
			if( good==2 || good==3 || good == 5 || good ==7 ){
				outputFile.println( "Impossible");
				continue;
			}
			// C>2 && R>2
			if ( 2*(R+C)-4 <good ){
				drawPattern4( R, C, good, outputFile);
				continue;
			}else{
				drawPattern3( R, C, good, outputFile);
				continue;
			}
		}
		
		content.close();
		outputFile.close();		
	}
	
	public static void drawPattern3( int R, int C, int G, PrintWriter outputFile){
		outputFile.print("c");
		if( G%2==0){
			if( G > 2*C ){
				for(int i=1; i<C; i++)
					outputFile.print(".");
				outputFile.println("");
				for(int i=0; i<C; i++)
					outputFile.print(".");
				outputFile.println("");
				int cols = (G-2*C)/2;
				for(int i=0; i<cols; i++){
					outputFile.print("..");
					for( int j=2; j<C; j++)
						outputFile.print("*");
					outputFile.println("");
				}
				for(int i=2+cols; i<R; i++){
					for( int j=0; j<C; j++)
						outputFile.print("*");
					outputFile.println("");
				}
			}else{
				int cols = G/2;
				for( int i=1; i<cols; i++)
					outputFile.print(".");
				for( int i=cols; i<C; i++)
					outputFile.print("*");
				outputFile.println("");
				for( int i=0; i<cols; i++)
					outputFile.print(".");
				for( int i=cols; i<C; i++)
					outputFile.print("*");
				outputFile.println("");
				for( int i=2; i<R; i++){
					for ( int j=0; j<C; j++)
						outputFile.print("*");
					outputFile.println("");
				}
			}
		}else{
			if( G -9 > 2*( C-3) ){
				for(int i=1; i<C; i++)
					outputFile.print(".");
				outputFile.println("");
				for(int i=0; i<C; i++)
					outputFile.print(".");
				outputFile.println("");
				outputFile.print("...");
				for( int i=3; i<C; i++)
					outputFile.print("*");
				outputFile.println("");
				int cols = (G-2*C-3)/2;
				for(int i=0; i<cols; i++){
					outputFile.print("..");
					for( int j=2; j<C; j++)
						outputFile.print("*");
					outputFile.println("");
				}
				for(int i=3+cols; i<R; i++){
					for( int j=0; j<C; j++)
						outputFile.print("*");
					outputFile.println("");
				}
			}else{
				int cols = (G-3)/2;
				for( int i=1; i<cols; i++)
					outputFile.print(".");
				for( int i=cols; i<C; i++)
					outputFile.print("*");
				outputFile.println("");
				for( int i=0; i<cols; i++)
					outputFile.print(".");
				for( int i=cols; i<C; i++)
					outputFile.print("*");
				outputFile.println("");
				outputFile.print("...");
				for( int i=3; i<C; i++)
					outputFile.print("*");
				outputFile.println("");
				for( int i=3; i<R; i++){
					for ( int j=0; j<C; j++)
						outputFile.print("*");
					outputFile.println("");
				}
			}
		}
	}
	
	public static void drawPattern4( int R, int C, int G, PrintWriter outputFile){
		// first two rows
		outputFile.print("c");
		for( int i=1; i<C; i++)
			outputFile.print(".");
		outputFile.println("");
		for( int i=0; i<C; i++)
			outputFile.print(".");
		outputFile.println("");
		
		// left
		int left_G = G - (2*(R+C)-4);
		int num_G = 0;
		for( int j = 2; j<R; j++){
			for( int i=0; i<2; i++){
				outputFile.print(".");
			}
			for( int i=2; i<C; i++){
				if( num_G < left_G){
					outputFile.print(".");
					num_G++;
				}else
					outputFile.print("*");
			}
			outputFile.println("");
		}
	}
		
	public static void drawPattern1( int R, int C, int M, PrintWriter outputFile){		
		if( R==1 ){
			outputFile.print("c");
			for( int i=0; i<C-M-1; i++){
				outputFile.print(".");
			}
			for( int i=0; i<M; i++){
				outputFile.print("*");
			}
			outputFile.println("");
			return;
		}
		if( C==1 ){
			outputFile.println("c");
			for( int i=0; i<R-M-1; i++){
				outputFile.println(".");
			}
			for( int i=0; i<M; i++){
				outputFile.println("*");
			}
			return;
		}
		
		int G = R*C-M;
		if ( G==1 ){
			for( int r = 0; r<R; r++){
				for (int c = 0; c<C; c++){
					if( r==0 && c==0 ){
						outputFile.print("c");
						continue;
					}
					outputFile.print("*");
				}
				outputFile.println("");
			}
			return;
		} 
	}
	
	public static void drawPattern2( int R, int C, int M, PrintWriter outputFile){	
		int cols = (R*C-M)/2;
		if( R==2 ){
			outputFile.print("c");
			for( int i=0; i<cols-1; i++){
				outputFile.print(".");
			}
			for( int i=cols; i<C; i++){
				outputFile.print("*");
			}
			outputFile.println("");
			for( int i=0; i<cols; i++){
				outputFile.print(".");
			}
			for( int i=cols; i<C; i++){
				outputFile.print("*");
			}
			outputFile.println("");
			return;
		}
		if( C==2 ){
			outputFile.println("c.");
			for( int i=0; i<cols-1; i++){
				outputFile.println("..");
			}
			for( int i=cols; i<R; i++)
				outputFile.println("**");
			return;
		}
	}
}
