import java.io.*;
import java.util.*;

public class B {
	BufferedReader in;
	BufferedWriter out;
	static String inputFile = "B8.in";
	static String outputFile = "B8.out";
	
	private String readWord() throws Exception {
		int c = in.read();
		while (c>=0 && c<=' ') c = in.read();
		if (c < 0) return "";
		StringBuilder builder = new StringBuilder();
		while (c > ' ') {
			builder.append((char)c);
			c = in.read();
		}
		return builder.toString();
	}
	
	
	
	private int readInt() throws Exception {
		return Integer.parseInt(readWord());
	}
	
	
	private void solve() throws Exception {
		int cases = readInt();
		for (int i = 0; i<cases; i++) {
			StringBuilder bld = new StringBuilder();
			bld.append("Case #" + (i+1) + ": ");
			int levels = readInt();
			int result = 0;
			int stars = 0;
			int[] req1S = new int[levels];
			int[] req2S = new int[levels];
			for (int j = 0; j<levels; j++) {
				req1S[j] = readInt();
				req2S[j] = readInt();
			}
			boolean finished = false;
			boolean win = false;
			while(!finished) {
				boolean someFound = true;
				while (someFound) {
					for (int k = 0; k<levels; k++) {
						if ((req2S[k] <= stars) && (req2S[k] != -1)) {
							if (req1S[k] == -1) stars += 1;
							else stars += 2;
							req2S[k] = -1;
							req1S[k] = -1;
							result++;
							someFound = true;
							if (stars >= levels*2) {
								finished = true;
								win = true;
							}
							break;
						}
						someFound = false;
					}
				}
				boolean found2 = false;
				if (!finished) {
					for (int k = 0; k<levels; k++) {
						if ((req1S[k] <= stars) && (req1S[k] != -1)) {
							//boolean skip = false;
							for (int x = k; x<levels; x++) {
								if ((req1S[x] <= stars) && (req2S[x] > req2S[k])&& (req1S[x] != -1)) {
									k = x;
								}
							}
							stars += 1;
							req1S[k] = -1;
							result++;
							found2 = true;
							if (stars >= levels*2) {
								finished = true;
								win = true;
							}
							break;
						}
						
					}
					if (!someFound && !found2) finished = true;
				}
			}
			if (stars >= levels*2) win = true;
			/*System.out.println(Arrays.toString(req1S));
			System.out.println(Arrays.toString(req2S));
			System.out.println(result);*/
			if (win) bld.append("" + result);
			else bld.append("Too Bad");
			if (i < cases - 1) bld.append("\n");
			System.out.print(bld);
			out.write(bld.toString());
		}
	}
	
	public static void main(String[] args) {
		new B().run();
	}

	private void run() {
		try {
			in = new BufferedReader(new FileReader(inputFile));
			out = new BufferedWriter(new FileWriter(outputFile));
			solve();
			int[] a = {1,2,3,4};
			out.flush();
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
}
