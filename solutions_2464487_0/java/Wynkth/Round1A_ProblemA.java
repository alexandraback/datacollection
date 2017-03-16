import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;
import java.util.StringTokenizer;

/**
 * Google Code Jam 2013
 * Round 1A: Problem A. Bullseye 
 * @author Jose Toro (@Wynkth)
 */

public class Round1A_ProblemA {
	public static void main (String[] args) throws IOException {	
		FileReader fr = new FileReader("in.txt");
		Scanner sc = new Scanner(fr);
		BufferedWriter bw = new BufferedWriter(new FileWriter("out.txt"));
		int cases = Integer.parseInt(sc.nextLine());
		
		for(int i = 1; i<=cases; i++) {
			System.out.println("Processing Case #" + i);
			StringTokenizer st = new StringTokenizer(sc.nextLine());
			
			bw.write("Case #" + i + ": " + String.valueOf(solve(st.nextToken(),st.nextToken())) + "\n");
		}
		
		sc.close();
		fr.close();
		bw.close();
	}
	
	public static long solve(String r, String t) {
		long rr = Long.valueOf(r);
		long tt = Long.valueOf(t);
		long res = (rr+1)*(rr+1) - rr*rr;
		long i = rr+3;
		long count = 0;
		while(res<=tt) {
			count++;
			res = i*i - (i-1)*(i-1) + res;
			i+=2;
		}
		
 
		return count;
		
	}
}
