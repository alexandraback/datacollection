
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter("C:\\Users\\Natasha\\Desktop\\outputOsmos1.txt"), true);
		
		int T = in.nextInt();
		int count = 1;

		while (count <= T) {
			long A = in.nextLong();
			int N = in.nextInt();
			long motes[] = new long[N];
			for (int i = 0; i < N; i++) {
				motes[i] = in.nextLong();
			}
			Arrays.sort(motes);
			long adds = 0;
			long cuts = N;
			int i = 0;
			long best = Integer.MAX_VALUE;
			
			while (i < motes.length){
				best = Math.min(best,adds + cuts);
				if (A > motes[i]) {
					A += motes[i++];
					cuts--;
					best = Math.min(best,adds + cuts);
				} else {
					if(A-1 == 0) break;
					A += A - 1;
					adds++;
					if (A > motes[i]) {
						A += motes[i++];
						cuts--;
					}	
					best = Math.min(best,adds + cuts);
				}
			}
			//best = adds+cuts;
			out.println("Case #" + (count++) + ": " + (best));
		}
		out.close();

	}
}
