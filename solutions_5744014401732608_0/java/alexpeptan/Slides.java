package round1C_Problem2;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class Slides {

	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		PrintWriter writer = new PrintWriter("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1C_Problem2/1C2.out", "UTF-8");
		Scanner scanner = new Scanner(new File("/Users/alexpeptan/Desktop/Eclipse Workspace/Google Code Jam 2016/src/round1C_Problem2/1C2.in"));
		
		int t = scanner.nextInt();
		
		for(int k=0; k<t; k++){
			int n = scanner.nextInt();
			long m = scanner.nextLong();
			
			if(m > (long)Math.pow(2, n-2)){
				writer.println("Case #" + (k+1) + ": IMPOSSIBLE");
				continue;
			}
			
			int[][] a = new int[n][n];
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					a[i][j] = 0;
				}
			}
			
			for(int i=1; i<n; i++){
				for(int j=i+1; j<n; j++){
					a[i][j] = 1;
				}
			}
			
			for(int pow = n-3; pow >=0; pow--){
				long x = (long)Math.pow(2, pow);
				if(x <= m){
					m -= x;
					a[0][n-2-pow] = 1;
				}
			}
			
			if(m == 1){
				a[0][n-1] = 1;
			}
			
			writer.println("Case #" + (k+1) + ": POSSIBLE");
			
			for(int i=0; i<n; i++){
				for(int j=0; j<n; j++){
					writer.print(a[i][j]);
				}
				writer.println();
			}
		}
		writer.close();
	}

}
