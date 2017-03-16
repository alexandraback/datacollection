import java.util.*;
import java.io.*;

public class Main {
	static PrintWriter pw;
	public static void main(String args[]) throws Exception{
		BufferedReader input = new BufferedReader(new FileReader("../GoogleCodeJam2014R1A/io/C-small-attempt5.in"));
		pw = new PrintWriter(new FileWriter("../GoogleCodeJam2014R1A/io/output.txt"));
		int T = Integer.parseInt(input.readLine());
		for(int k = 0 ; k < T ; k++){
			String[] s = input.readLine().split(" ");
			int N = Integer.parseInt(s[0]);
			int M = Integer.parseInt(s[1]);
			int K = Integer.parseInt(s[2]);
			if(Math.min(N, M) <= 2){
				pw.println("Case #"+(k+1)+": "+K);
			}else{
				int min = Math.min(N, M);
				int max = Math.max(M, N);
				N = min;
				M = max;
				if(N == 3){
					if(M == 3){
						int[] pwd = {1,2,3,4,4,5,6,7,8};
						pw.println("Case #"+(k+1)+": "+pwd[K-1]);
					}else if(M == 4){
						int[] pwd = {1,2,3,4,4,5,6,6,7,8,9,10};
						pw.println("Case #"+(k+1)+": "+pwd[K-1]);
					}else if(M == 5){
						int[] pwd = {1,2,3,4,4,5,6,6,7,8,8,9,10,11,12};
						pw.println("Case #"+(k+1)+": "+pwd[K-1]);
					}else if(M == 6){
						int[] pwd = {1,2,3,4,4,5,6,6,7,8,8,9,10,10,11,12,13,14};
						pw.println("Case #"+(k+1)+": "+pwd[K-1]);
					}
				}else if(N == 4){
					if(M == 4){
						int[] pwd = {1,2,3,4,4,5,6,6,7,8,8,8,9,10,11,12};
						pw.println("Case #"+(k+1)+": "+pwd[K-1]);
					}else if(M == 5){
						int[] pwd = {1,2,3,4,4,5,6,6,7,8,8,8,9,10,10,10,11,12,13,14};
						pw.println("Case #"+(k+1)+": "+pwd[K-1]);
					}
				}
			}
			
			pw.flush();
		}
		input.close();
		pw.close();
	}
	
	public static long euclid(long a, long b) {
		long r = a % b;
		while (r > 0) {
			a = b;
			b = r;
			r = a % b;
			}
		return b;
		}
}