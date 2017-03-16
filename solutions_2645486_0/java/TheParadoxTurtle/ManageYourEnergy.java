import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;


public class ManageYourEnergy {
	static int[] v;
	static int limit;
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new FileReader("B-small-attempt0.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("B-small-attempt0.out.txt")));
		int T = Integer.parseInt(read.readLine());
		for(int c = 1; c <= T; c++){
			StringTokenizer st1 = new StringTokenizer(read.readLine());
			int E = Integer.parseInt(st1.nextToken());
			int R = Integer.parseInt(st1.nextToken());
			int N = Integer.parseInt(st1.nextToken());
			v = new int[N];
			limit = E;
			StringTokenizer st2 = new StringTokenizer(read.readLine());
			for(int i = 0; i < N; i++)
				v[i] = Integer.parseInt(st2.nextToken());
			pw.println("Case #" + c + ": " + bruteForce(E, R, 0));
		}
		pw.close();
	}
	public static int bruteForce(int E, int R, int N) {
		if(N == v.length-1)
			return v[N]*E;
		int max = 0;
		for(int i = 0; i <= E; i++) {
			int temp = v[N]*i + bruteForce(Math.min(E-i+R, limit), R, N+1);
			if(max < temp)
				max = temp;
		}
		return max;
	}
}
