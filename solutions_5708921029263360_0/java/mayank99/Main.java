import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Input input = new Input();
		Output output = new Output();

		int t = input.nextInt();

		for(int ii=1;ii<=t;ii++) {
			int j,p,s,k;
			j = input.nextInt();
			p = input.nextInt();
			s = input.nextInt();
			k = input.nextInt();
			int[][] ab = new int[j+1][p+1];
			int[][] bc = new int[p+1][s+1];
			int[][] ac = new int[j+1][s+1];
			int res = 0;
			ArrayList<Integer> arr = new ArrayList<Integer>(); 
			for(int a=1;a<=j;a++) {
				for(int b=1;b<=p;b++) {
					for(int c=1;c<=s;c++) {
						if ((ab[a][b]+1<=k) && (bc[b][c]+1<=k) && (ac[a][c]+1<=k)) {
							res++;
							arr.add(a);
							arr.add(b);
							arr.add(c);
							ab[a][b]++;
							bc[b][c]++;
							ac[a][c]++;
						}
					}
				}
			}

			output.println("Case #"+ii+": "+res);
			int sz = arr.size();
			for(int i=0;i<sz;i+=3) {
				output.println(arr.get(i) + " "+ arr.get(i+1)+" "+arr.get(i+2));
			}
			output.flush();
		}

		output.flush();
	}
}
class Input {
	StringTokenizer st;
	BufferedReader br;

	Input() {
		InputStreamReader isr = new InputStreamReader(System.in);
		br = new BufferedReader(isr);
	}

	private String nextToken() {
		String res = "";
		try {
			while (st==null || (!st.hasMoreElements())) {
				String line = br.readLine();
				st = new StringTokenizer(line);
			}
			res = st.nextToken();
		} catch (IOException e) {
			res = null;
		}
		return res;
	}

	public long nextLong() {
		String res = nextToken();
		return Long.parseLong(res);
	}

	public int nextInt() {
		String res = nextToken();
		return Integer.parseInt(res);
	}

	public String nextString() {
		return nextToken();
	}

	public double nextDouble() {
		String res = nextToken();
		return Double.parseDouble(res);
	}
}

class Output {
	PrintWriter pw;
	Output() {
		OutputStreamWriter osw = new OutputStreamWriter(System.out);
		pw = new PrintWriter(osw);
	}

	public void print(Object a) {
		pw.print(a);
	}

	public void println(Object a) {
		pw.println(a);
	}

	public void println() {
		pw.println();
	}

	public void flush() {
		pw.flush();
	}
}