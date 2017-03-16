import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class GoodLuck {
	static int[] primes = {2, 3, 5};
	public static void main(String[] args) throws IOException {
		BufferedReader read = new BufferedReader(new FileReader("C-small-1-attempt0.in"));
		PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter("C-small.out.txt")));
		read.readLine();
		read.readLine();
		pw.println("Case #1:");
		for(int i = 0; i < 100; i++) {
			StringTokenizer st = new StringTokenizer(read.readLine());
			int[] max = new int[3];
			for(int j = 0; j < 7; j++) {
				int temp = Integer.parseInt(st.nextToken());
				max = lcm(max, primeFactorize(temp));
			}
			int count = 0;
			for(int j = 2; j > 0; j--) {
				while(max[j] > 0) {
					pw.print(primes[j]);
					max[j]--;
					count++;
				}
			}
			while(max[0] > 0) {
				if(max[0] > 3-count) {
					pw.print(4);
					max[0] -= 2;
				}
				else {
					pw.print(2);
					max[0]--;
				}
				count++;
			}

			while(count < 3) {
				pw.print(2);
				count++;
			}
			pw.println();
		}
		pw.close();
	}
	public static int[] primeFactorize(int N) {
		int[] output = new int[3];
		for(int i = 0; i < 3; i++) {
			while(N%primes[i] == 0) {
				output[i]++;
				N /= primes[i];
			}
		}
		return output;
	}
	public static int[] lcm(int[] A, int[] B) {
		int[] output = new int[3];
		for(int i = 0; i < 3; i++)
			output[i] = Math.max(A[i], B[i]);
		return output;
	}
	
	
	public static int value(int[] N) {
		return (int)(Math.pow(2, N[0])*Math.pow(3, N[1])*Math.pow(5, N[2]));
	}
}
