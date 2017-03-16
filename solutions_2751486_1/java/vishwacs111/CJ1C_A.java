import java.io.*;


public class CJ1C_A {
	static long sum (int n) {
		return (long)((long)n * (long) (n + 1) / 2);
	}
	static boolean isVowel (char c) {
		switch (c) {
		case 'a':
		case 'e':
		case 'i':
		case 'o':
		case 'u': return true;
		default: return false;
		}
	}
	public static void main (String[] args) {
		String fName = "A-large";
		try {
			BufferedReader inp = new BufferedReader(new FileReader(fName + ".in"));
			PrintWriter out = new PrintWriter(new FileWriter(fName + ".out"));
			PrintStream scr = System.out;
			String l = inp.readLine();
			String[] lArr;
			int T = Integer.parseInt(l);
			for (int ii = 1; ii <= T; ii++) {
				l = inp.readLine();
				lArr = l.split (" ");
				String name = lArr[0];
				int n = Integer.parseInt(lArr[1]);
				int L = name.length();
				int loc = -1;
				int count = 0, nCount = 0;
				int[] locs = new int [L];
				for (int i = 0; i < L; i++) {
					char c = name.charAt(i);
					if (isVowel(c)) {
						loc = -1;
						count  = 0;
					}
					else {
						if (count == 0)
							loc = i;
						count++;
						if (count >= n) {
							locs[nCount++] = loc++;
						}
					}
				}
				long ret = 0;
				if (nCount != 0) {
					ret = (long)(locs[0] + 1) * (long)(L - locs[0] - n + 1);
					int prevLoc = locs[0];
					for (int i = 0; i < nCount; i++) {
						int trav = locs[i] - prevLoc;
						ret += (long)trav * (long)(L - locs[i] - n + 1);
						prevLoc = locs[i];
					}
				}
				String toPrint = String.valueOf(ret);
				out.println("Case #" + ii + ": " + toPrint);
				scr.println("Case #" + ii + ": " + toPrint);
			}
			out.close();
			inp.close();
		}catch (Exception e) {
			e.printStackTrace();
		}
	}
}