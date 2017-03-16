package r2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class C {
	
	public static final String INPUT = "A.in";
	public static final String OUTPUT = "output.txt";
	
//	public static int counts[][] = new int[2][2];
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader(new File(INPUT)));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File(OUTPUT)));
		int caseNum = Integer.parseInt(br.readLine());
		String line = "";
		
		for (int i = 0; i <caseNum; i++){
			line = br.readLine();
			String[] items = line.split(" ");
			int N = Integer.parseInt(items[0]);
			int M = Integer.parseInt(items[1]);
			int K = Integer.parseInt(items[2]);
			String result = "";
			long count = 0;
			
			int min = Math.min(N, M);
			
			if (min <= 2) count = K;
			else {
				if (K <= 4) count = K;
				else if (K == 5) count = 4;
				else if (K == 6) count = 5;
				else if (K == 7) count = 6;
				else if (M*N == 9 ) count = K-1;
				else if (M*N == 12){
					count = K - 2;
				} else if (M*N == 15){
					if (K >= 11) count = K - 3;
					else count = K -2;
				} else if (M*N == 16){
					if(K >= 12) count = K - 4;
					else if (K >= 10) count = K - 3;
					else count = K -2;
				} else if (M*N == 18){
					if (K >= 14) count = K - 4;
					else if (K >= 11) count = K -3;
					else count = K-2;	
				} else if (M*N == 20){
					if (K >= 16) count = K - 6;
					else if(K >= 14) count = K - 5;
					else if(K >= 12) count = K - 4;
					else if (K >= 10) count = K - 3;
					else count = K -2;
				}
				
			}
			
			result = "" + count;
		
			bw.write("Case #"+ (i+1) + ": " + result + "\n");
			System.out.println("Case #"+ (i+1) + ": " + result + "\n");
		}
		bw.close();
		br.close();
		
	}

}
