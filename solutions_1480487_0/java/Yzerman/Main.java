import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.StringTokenizer;

public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		//BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\input_01_sample.txt")));
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\input_01.txt")));
		//BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("c:\\input_01_Large.txt")));
		int cases = Integer.parseInt(reader.readLine());
		
		int N;
		double X;
		double limit = 0;
		
		int N2;
		double X2;
		double limit2;
		
		for(int i=0; i<cases; i++){
			
			String inputString = reader.readLine();		
			StringTokenizer st = new StringTokenizer(inputString);			
						
			N = Integer.parseInt(st.nextToken());
			X = 0;
			double[] C = new double[200];
			double[] P = new double[200];
			for(int j=0; j<N; j++) {
				C[j] = Integer.parseInt(st.nextToken());
				X += C[j];				
			}
			
			//先check有沒有人超過標準的
			limit = X * 2 / N;
			N2 = N;
			X2 = X;
			for(int x=0; x<N; x++) {
				if(C[x]>limit) {
					P[x] = 0;				
					N2 = N2 -1;
					X2 = X2 - C[x];
				}
			}
			
			//case 1 沒人超過標準的
			if(N == N2) {
				for(int z=0; z<N; z++) {
					P[z] = round(100*(limit-C[z])/X, 6);
					
				}
			} else {
				
				if(X2 == 0) { //case 2 剩下來的都是零分 
					for(int y=0; y<N; y++) {
						if(C[y]>limit)
							P[y] = 0;
						else
							P[y] = round(100*1.0/N2, 6);
					}
				} else {  //剩下來有人不是零分
					
					limit2 = (X+X2) / N2;
					for(int y=0; y<N; y++) {
						
						if(C[y]>limit)
							P[y] = 0;
						else
							P[y] = round(100*(limit2-C[y])/X, 6);		
					}
				}
				
			}
			//System.out.println(X);
			
			//System.out.println(limit);
			System.out.print("Case #"+(i+1)+": ");
			for(int k=0; k<N; k++) {				
				System.out.print(P[k]);
				if(k!=N-1)
					System.out.print(" ");
			}
			System.out.println("");
			
			
			
			
		}

	}
	
    public static double round(double value, int decimalPlace)
    {
      double power_of_ten = 1;
      // floating point arithmetic can be very tricky.
      // that's why I introduce a "fudge factor"
      double fudge_factor = 0.05;
      while (decimalPlace-- > 0) {
         power_of_ten *= 10.0d;
         fudge_factor /= 10.0d;
      }
      return Math.round((value + fudge_factor)* power_of_ten)  / power_of_ten;
    }

}
