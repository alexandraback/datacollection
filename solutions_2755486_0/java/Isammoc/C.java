import java.io.File;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import java.util.Scanner;

public class C {

	public static void main(String[] args) throws Exception {
//		String inFile = "C-example.in";
//		String outFile = "C-example.out";
		 String inFile = "C-small-attempt0.in";
		 String outFile = "C-small-attempt0.out";
		// String inFile = "C-large.in";
		// String outFile = "C-large.out";
		Scanner in = new Scanner(new File(inFile));
		try {
			int T = in.nextInt();
			PrintStream out = new PrintStream(outFile);
			try {
				for (int t = 1; t <= T; t++) {
					out.printf("Case #%d: %s\n", t, turn(in));
				}
			} finally {
				out.close();
			}
		} finally {
			in.close();
		}
	}

	private static class Tribe {
		long n;
		long d;
		int w;
		int e;
		long s;
		long deltaD;
		long deltaP;
		long deltaS;
		
		static Tribe createFromIn(Scanner in) {
			Tribe tribe = new Tribe();
			tribe.d = in.nextLong();
			tribe.n = in.nextLong();
			tribe.w = in.nextInt()*2 + 2000;
			tribe.e = in.nextInt()*2 + 2000;
			tribe.s = in.nextLong();
			tribe.deltaD = in.nextLong();
			tribe.deltaP = in.nextLong()*2;
			tribe.deltaS = in.nextLong();
			return tribe;
		}
	}

	private static String turn(Scanner in) {
		int N = in.nextInt();
		List<Tribe> tribes = new ArrayList<Tribe>();
		for(int i = 0; i < N; i++) {
			tribes.add(Tribe.createFromIn(in));
		}
		long[] wall = new long[4000];
		long succeedAttacks = 0;
		while(!tribes.isEmpty()) {
			long day = Long.MAX_VALUE;
			for(Tribe tribe:tribes) {
				if(tribe.d < day) {
					day = tribe.d;
				}
			}
			// count attacks
			for(Tribe tribe:tribes) {
				if(tribe.d == day) {
					for(int p = tribe.w; p <= tribe.e; p++) {
						if(wall[p] < tribe.s) {
							succeedAttacks += 1;
							break;
						}
					}
				}
			}
			// build wall
			for(Tribe tribe:tribes) {
				if(tribe.d == day) {
					for(int p = tribe.w; p <= tribe.e; p++) {
						if(wall[p] < tribe.s) {
							wall[p] = tribe.s;
						}
					}
				}
			}
			// update tribes
			Iterator<Tribe> iter = tribes.iterator();
			while(iter.hasNext()) {
				Tribe tribe = iter.next();
				if(tribe.d == day) {
					if(tribe.n == 1) {
						iter.remove();
					} else {
						tribe.n--;
						tribe.d += tribe.deltaD;
						tribe.e += tribe.deltaP;
						tribe.w += tribe.deltaP;
						tribe.s += tribe.deltaS;
					}
				}
			}
		}
		return ""+succeedAttacks;
	}

}
