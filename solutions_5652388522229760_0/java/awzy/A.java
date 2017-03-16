import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
//		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter("A-out-small.txt", "UTF-8");
		while(sc.hasNext()) {
			int T = sc.nextInt();
			for(int i = 1; i <= T; i++) {
				int N = sc.nextInt();
				if(N == 0) {
					System.out.println("Case #" + i + ": INSOMNIA");
					pw.println("Case #" + i + ": INSOMNIA");
					continue;
				}
				int bits = 0b1111111111;
				for(int j = 1; true; j++) {
					long nxorig = N * j;
					long nx = N * j;
					while(nx > 0) {
						long k = nx % 10;
						nx = nx / 10;
						bits &= (-1 ^ (1<<k));
					}
					if(bits == 0) {
						System.out.println("Case #" + i + ": " + nxorig);
						pw.println("Case #" + i + ": " + nxorig);
						break;
					}
				}
			}
			pw.close();
		}
	}

}
