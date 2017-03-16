import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class KingdomRush {
	final static String FILENAME = "B-small-attempt1";

	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new FileReader("/home/workshop/Documents/"
				+ FILENAME + ".in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(
				"/home/workshop/Documents/" + FILENAME + ".out"));
		int T = sc.nextInt();
		for (int ttt = 0; ttt < T; ttt++) {
			int N = sc.nextInt();
			int[] a = new int[N], b = new int[N];
			Set<Integer> notplayed1S = new HashSet<Integer>(), notplayed2S = new HashSet<Integer>();
			for (int n = 0; n < N; n++) {
				a[n] = sc.nextInt();
				b[n] = sc.nextInt();
				notplayed1S.add(n);
				notplayed2S.add(n);
			}
			int currentstar = 0, playcount = 0;

			while (notplayed2S.size() > 0) {
				// check the 2star levels
				boolean playsth = false;
				for (int twostarlevel : notplayed2S) {
					if (b[twostarlevel] <= currentstar) {
						// play it!
						playcount++;
						if (notplayed1S.contains(twostarlevel)) {
							currentstar += 2;
							notplayed1S.remove(twostarlevel);
						} else {
							// already played 1star
							currentstar += 1;
						}
						notplayed2S.remove(twostarlevel);
						playsth = true;
						break;
					}
				}
				if (!playsth) {
					// have to play 1star levels
					// first find candidates
					int max2srequire = -1, maxlevel = 0;
					for (int onestarlevel : notplayed1S) {
						if (a[onestarlevel] <= currentstar) {
							// can play it
							if (b[onestarlevel] > max2srequire) {
								max2srequire = b[onestarlevel];
								maxlevel = onestarlevel;
							}
						}
					}
					// play that max level
					if (max2srequire >= 0) {
						playcount++;
						currentstar += 1;
						notplayed1S.remove(maxlevel);
						playsth = true;
					}
				}
				if (!playsth) // haven't any level to play
					break;
			}

			bw.write("Case #" + (ttt + 1) + ": ");
			if (notplayed2S.size() == 0) {
				bw.write("" + playcount);
			} else {
				bw.write("Too Bad");
			}
			bw.newLine();
		}
		bw.close();
		sc.close();
	}
}
