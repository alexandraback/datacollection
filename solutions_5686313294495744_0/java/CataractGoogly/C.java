package round1b;
import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;
import java.util.StringTokenizer;


public class C {

	int solve(String[] s) {
		int N = s.length;
		String[] first = new String[N];
		String[] second = new String[N];
		for (int i=0; i<N; i++) {
			StringTokenizer st = new StringTokenizer(s[i]);
			first[i] = st.nextToken();
			second[i] = st.nextToken();
		}
		int best = 0;
		for( int i=0; i<(1<<N); i++) {
			boolean ok = true;

			for (int j=0; j<N; j++) if (((1<<j)&i)!=0) {
				boolean canBeFake = false;

				for (int k=0; k<N; k++) if (((1<<k)&i)==0) {
					for (int w=0; w<N; w++) if (((1<<w)&i)==0 ) {
						if( first[j].equals(first[k]) && second[j].equals(second[w])) {
							canBeFake = true;
							break;
						}
					}
					if (canBeFake) break;
				}

				if (!canBeFake) { ok = false; break; }
			}

			if (ok ) {
				if( Integer.bitCount(i) > best ) {
					best = Integer.bitCount(i);
				}
			}
		}
		return best;
	}

	public static void main(String[] args) {
		try {
			File fin = new File("C-small-attempt0.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("cout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			sc.nextLine();
			for (int cn=1; cn<=T; cn++) {
				int N = sc.nextInt();
				sc.nextLine();
				String[] topics = new String[N];
				for (int i=0; i<N; i++) {
					topics[i] = sc.nextLine();
				}
				C c = new C();
				pw.write("Case #" + cn + ": " + c.solve(topics) + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
