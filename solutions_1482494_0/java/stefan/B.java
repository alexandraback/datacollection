import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class B {
	public static final String FILENAME = "B-small-0";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		for(int i = 1; i <= T; i++) {
			int N = s.nextInt();
			int[] a = new int[N];
			int[] b = new int[N];
			for(int j = 0; j < N; j++) {
				a[j] = s.nextInt();
				b[j] = s.nextInt();
			}
			out.write("Case #"+i+": "+compute(a, b)+"\n");
		}
		in.close();
		out.close();
	}
	
	public static String compute(int[] a, int[] b) {
		int N = a.length;
		
		for(int i = N-1; i > 0; i--) {
			for(int j = 0; j < i; j++) {
				if(b[i] < b[j]) {
					int tmpB = b[i];
					int tmpA = a[i];
					a[i] = a[j];
					b[i] = b[j];
					a[j] = tmpA;
					b[j] = tmpB;
				}
			}
		}
		
		int ret = 0;
		int stars = 0;
		int[] earned = new int[N];
		while(stars < 2 * N) {
			boolean restart = false;
			for(int i = 0; i < N; i++) {
				if(earned[i] == 0 && stars >= b[i]) {
					earned[i] = 2;
					stars += 2;
					ret++;
					restart = true;
				}
			}
			if(!restart) {
				for(int i = 0; i < N; i++) {
					if(earned[i] == 1 && stars >= b[i]) {
						earned[i] = 2;
						stars += 1;
						ret++;
						restart = true;
					}
				}
			}
			if(!restart) {
				for(int i = N-1; i >= 0 && !restart; i--) {
					if(earned[i] == 0 && stars >= a[i]) {
						earned[i] = 1;
						stars += 1;
						ret++;
						restart = true;
					}
				}
			}
			if(!restart) {
				return "Too Bad";
			}
		}
		return ""+ret;
	}
}
