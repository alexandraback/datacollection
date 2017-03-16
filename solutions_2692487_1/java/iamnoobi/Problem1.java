import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;


public class Problem1 {
	public static int times(int a, int b){
		int result = 0;
		while(a <= b){
			a = 2 * a -1;
			result++;
		}
		return result;
	}
	
	public static int kaboom(int a, int b){
		int result = 0;
		while(a <= b){
			a = 2 * a -1;
			result++;
		}
		return a;
	}
	
	public static void main(String[] args) {
		FileReader input;
		try {
			input = new FileReader("A-large.in.txt");
			BufferedReader reader = new BufferedReader(input);
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			int test = Integer.parseInt(reader.readLine());
			for (int k = 1; k <= test; k++) {
				// Solution here
				Scanner scanner = new Scanner(reader.readLine());
				int A = scanner.nextInt();
				int N = scanner.nextInt();
				scanner = new Scanner(reader.readLine());
				int[] mote = new int[N];
				for (int i = 0; i < N; i++){
					mote[i] = scanner.nextInt();
				}
				Arrays.sort(mote);
				int result = 0;
				if(A == 1){
					result = N;
				} else {
				for(int i = 0; i < N; i++){
					if(A > mote[i]){
						A = A + mote[i];
					} else {
						int x = times(A, mote[i]);
						if(result + x < result + N - i){
							result = result + x;
							A = kaboom(A, mote[i]) + mote[i];
						} else {
							result = result + N - i;
							break;
						}
					}
				}
				}
				out.println("Case #" + k + ": "+result);
			}
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
