import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class B {
	public static void main(String[] args) throws IOException {
		String filename = "B-large";
		String inname = filename + ".in";
		String outname = filename + ".out";
		Scanner sc = new Scanner(new File(inname));
		//Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		sc.nextLine();
		PrintWriter out = new PrintWriter(new FileWriter(outname)); 
		for(int n = 1; n <= N; n++) {
			int numLevels = sc.nextInt();
			long[] a1 = new long[numLevels];
			long[] a2 = new long[numLevels];
			boolean[] oneStar = new boolean[numLevels];
			long[] sa2 = new long[numLevels];
			int oned = 0;
			for(int i = 0; i < numLevels; i++) {
				a1[i] = sc.nextLong();
				//System.out.println(a1[i]);
				a2[i] = sc.nextLong()*2002*2002+(/*2001-*/a1[i])*2002+i;
				//System.out.println(a2[i]);
				sa2[i] = a2[i];
			}
			Arrays.sort(sa2);

			//System.out.println(Arrays.toString(a1));
			//System.out.println(Arrays.toString(a2));
			//System.out.println(Arrays.toString(sa2));
			int numStars = 0;
			boolean tooBad = false;
			int curIndex = 0;
			outer: while(!tooBad) {
				if(curIndex == numLevels) break outer;
				if(sa2[curIndex]/2002/2002 <= numStars) {
					//System.out.println(sa2[curIndex]);
					int origi = (int) (sa2[curIndex]%2002);
					numStars += oneStar[origi] ? 1 : 2;
					curIndex++;
					//System.out.println("2 Stars on " + origi);
					continue outer;
				}
				for(int i = numLevels-1; i >= curIndex; i--) {
					int origi = (int) (sa2[i]%2002);
					if(a1[origi] <= numStars && !oneStar[origi]) {
						oned++;
						oneStar[origi] = true;
						numStars++;
						//System.out.println("1 Star on " + origi);
						continue outer;
					}
				}
				tooBad = true;
			}
			int ans = numLevels + oned;
			if(tooBad) {
				out.println("Case #" + n + ": " + "Too Bad");
				System.out.println("Case #" + n + ": " + "Too Bad");
			} else {
				out.println("Case #" + n + ": " + ans);
				System.out.println("Case #" + n + ": " + ans);				
			}
		}
		out.close();
	}
}
