import java.io.*;
import java.util.*;

public class PartElf {
	static int isPowerTwo(int Q) {
		if(Q == 1)
			return 0;
		if(Q%2 == 1)
			return -1;
		int a = isPowerTwo(Q/2);
		if(a == -1)
			return -1;
		return a+1;
	}
	public static void main(String[] args) throws IOException {
		Scanner scan = new Scanner(new File("A-small-attempt0.in"));
		
		int T = Integer.parseInt(scan.next());
		for(int c = 1; c <= T; c++){
			StringTokenizer st = new StringTokenizer(scan.next(), "/");
			int P = Integer.parseInt(st.nextToken());
			int Q = Integer.parseInt(st.nextToken());
			int min = (int)Math.sqrt(Math.min(P, Q));
			for(int i = 2; i <= min; i++) {
				if(P%i == 0 && Q%i == 0) {
					P /= i;
					Q /= i;
					min = (int)Math.sqrt(Math.min(P, Q));
					i--;
				}
			}
			int power = isPowerTwo(Q);
			if(power == -1 || power > 40)			
				System.out.println("Case #" + c + ": impossible");
			else {
				int x = 0;
				while(P < Q) {
					P *= 2;
					x++;
				}
				System.out.println("Case #" + c + ": " + x);
			}
		}
	}
}
