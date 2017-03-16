import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

public class Dijkstra {

	private static void debug(Object... args) {
		//System.out.println(Arrays.deepToString(args));
	}

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out, true);
		int T = Integer.parseInt(br.readLine());
		for (int c = 1; c <= T; c++) {
			pw.println("Case #" + c + ": " + solve(br));
		}
		pw.flush();
	}
	
	static final int I = 2;
	static final int J = 3;
	static final int K = 4;
	
	static int q[][] =   {{0, 0, 0, 0, 0}, 
						  {0, 1, I, J, K}, 
						  {0, I, -1, K, -J},
						  {0, J, -K, -1, I},
						  {0, K, J, -I, -1}};
	
	
	private static String solve(BufferedReader br) throws IOException {
		StringTokenizer st = new StringTokenizer(br.readLine());
		int L = Integer.parseInt(st.nextToken());
		long X = Long.parseLong(st.nextToken());
		String p = br.readLine();
		int[]v = new int[L + 1];
		v[0]=t(p.charAt(0));
		for (int i=1;i<p.length();i++) {
			v[i] = m(v[i-1], t(p.charAt(i)));
		}
		int[]cyc = new int[9];
		Map<Integer, Integer> seen = new HashMap<>();
		cyc[0] = v[L-1];
		int i=1;
		while(seen.get(cyc[i-1]) == null) {
			seen.put(cyc[i-1], i-1);
			cyc[i] = m(cyc[i-1], v[L-1]);
			i++;
		}
		int cycLen =  i - seen.get(cyc[i-1]) - 1;
		int res = cyc[(int) ((X-1) % cycLen)];
		if (res != -1) {
			return "NO";
		}
		
		List<P> pos = new ArrayList<>();
		for (int j=0;j<cycLen;j++) {
			if (cyc[j]==I) {
				pos.add(new P(-1,j+1));
			}
		}
		
		for (int j=0;j<L-1;j++) {
			for (int k=0;k<cycLen;k++) {
				if (m(cyc[k],v[j])==I) {
					pos.add(new P(j,k+1));
				}
			}
			if (v[j]==I) {
				pos.add(new P(j, 0));
			}
		}
		
		
		debug(pos);
		for (P state : pos) {
			
			for (int j=0;j<cycLen;j++) {
				if (cyc[j]==K && valid(state, j+1, X, -1)) {
					debug("from 1", state, j+1);
					return "YES";
				}
			}
			
			for (int j=L-1;j>0;j--) {
				int val = m(-v[j-1],v[L-1]);
				for (int k=0;k<cycLen;k++) {
					if (m(val, cyc[k])==K && valid(state, k+1, X, j)) {
						debug("from 2", state);
						return "YES";
					}
				}
				if (val==K && valid(state, 0, X, j)) {
					debug("from 3", state);
					return "YES";
				}
			}
		}
		
		
		return "NO";
	}
	
	private static boolean valid(P state, int cycle, long X, int endPos) {

		int inc = 0;
		if (state.spos != -1 && endPos != -1 && state.spos >= endPos) {
			inc = 2;
		}
		else if (state.spos != -1 || endPos != -1) {
			inc = 1;
		}
		debug("validating", cycle + state.cycpos + inc);
		if (cycle + state.cycpos + inc > X) return false;
				
		return true;
	}

	private static class P {
		int spos;
		int cycpos;
		public P(int spos, int cycpos) {
			super();
			this.spos = spos;
			this.cycpos = cycpos;
		}
		@Override
		public String toString() {
			return "P [spos=" + spos + ", cycpos=" + cycpos +  "]";
		}
	}
	
	private static int m(int a, int b) {
		int signa = (int)Math.signum(a);
		int signb = (int)Math.signum(b);
		return signa * signb * q[Math.abs(a)][Math.abs(b)];
	}

	private static int t(char c) {
		switch (c) {
		case 'i': return I;
		case 'j': return J;
		case 'k': return K;
		}
		throw new IllegalArgumentException();
	}
}
