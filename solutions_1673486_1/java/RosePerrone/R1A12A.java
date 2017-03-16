import java.io.*;
import java.util.*;

public class R1A12A {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter(new FileWriter("Asmall.out"));

		int ntest = sc.nextInt();

		for(int test=1;test<=ntest;++test) {

			int typed = sc.nextInt();
			int total = sc.nextInt();

			float min = total + 2; // cost of retrying 
			float mistakeCost = total + 1;

			float[] probMistake = new float[typed + 1];
			float prob = 1;
			for (int i = 0; i < typed; i++) {
				prob *= sc.nextFloat(); 
				probMistake[i] = 1 - prob;
			}

			for (int backup = 0; backup < typed; backup++) {
				float probM = probMistake[typed - 1 - backup]; 
				float expected = probM * mistakeCost + 2*backup + (total - typed) + 1; 
				min = expected < min ? expected : min;
			}

			pw.print("Case #" + test + ": ");
			pw.println(min);
		}
		pw.close();
		sc.close();
	}
}
