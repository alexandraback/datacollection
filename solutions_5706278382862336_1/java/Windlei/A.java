package r2;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;

public class A {
	
	public static final String INPUT = "A.in";
	public static final String OUTPUT = "output.txt";
	public static double delta = 0.000000001;
	public static void main(String[] args) throws IOException{
		BufferedReader br = new BufferedReader(new FileReader(new File(INPUT)));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File(OUTPUT)));
		int caseNum = Integer.parseInt(br.readLine());
		String line = "";
		for (int i = 0; i <caseNum; i++){
			String result = "";
			String f = br.readLine();
			String[] items = f.split("/");
			long P = Long.parseLong(items[0]);
			long Q = Long.parseLong(items[1]);
			long g = gcd(P,Q);
			P = P/g;
			Q = Q/g;
			int n = 1;
			if (!isPowered(Q)) result = "impossible";
			else{
			
				double r = P / (double)Q;
				while (!(Math.abs(r - 0.5) < delta) && r < 0.5){
					r = r *2;
					n++;
				}
				if (n > 40) result = "impossible";
				else  result = "" + n;
			}
			bw.write("Case #"+ (i+1) + ": " + result + "\n");
			System.out.println("Case #"+ (i+1) + ": " + result + "\n");
		}
		bw.close();
		br.close();
		
	}
	
	public static long gcd(long m,long n){
		if (n == 0) return m;	
		else return gcd(n, m % n);
	}
	
	public static boolean isPowered(long i){
		while (i > 1){
			if (i % 2 != 0) return false;
			i = i / 2;
		}
		return true;
	}

}
