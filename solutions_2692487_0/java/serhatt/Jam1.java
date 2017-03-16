import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;


public class Jam1 {

	
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(System.in);
		FileWriter fstream = new FileWriter("jam1.txt");
		BufferedWriter out = new BufferedWriter(fstream);
		int T = scan.nextInt();
		
		for (int k = 0; k < T; k++) {
			int a = scan.nextInt();
			int N = scan.nextInt();
			int[] m = new int[N];
			for (int i = 0; i < N; i++) {
				m[i] = scan.nextInt();
			}
			Arrays.sort(m);
			int index = 0;

			int max = N - index;
			if(a != 1) {
				max = Math.min(max, find(m, index, N, a));
			}

			out.write("Case #" + (k+1) + ": " + max);
			out.write("\n");
			System.out.println(k);
		}

		out.close();
	}


	private static int find(int[] m, int index, int N, int a) {
		while(index < N) {
			if(m[index] >= a) {
				break;
			}
			a += m[index];
			index++;
		}
		if(index == N) {
			return 0;
		}
		int times = time(m[index], a);
		int result = N - index;
		a = (int) (a*Math.pow(2, times) - Math.pow(2, times) + 1);
		
		return Math.min(result, find(m, index, N, a) + times);
	}



	private static int time(int value, int a) {
		double d = value;
		d = d / a;
		d = Math.log(d) / Math.log(2);
		int times = (int) d;
		for (int i = times - 4; i < times + 3; i++) {
			if(i > 0) {
				if( (a*Math.pow(2, i) - Math.pow(2, i) + 1) > value) {
					return i;
				}
			}
		}
		
		return 0;
	}

}
