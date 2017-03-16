import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Input input = new Input();
		Output output = new Output();

		int t = input.nextInt();

		for(int ii=1;ii<=t;ii++) {
			int b = input.nextInt();
			int m = input.nextInt();
			int[][] a = new int[b][b];
			int cnt = (b*(b-1))/2;
			int[] tot = new int[b];
			int pos =0;
			double num = Math.pow(2, cnt);
			while(num>0) {
				//fill matrix
				int tmp = (int)num;
				for(int i=0;i<b;i++) {
					for(int j=i+1;j<b;j++) {
						a[i][j]=tmp%2;
						tmp/=2;
					}
				}

				// check matrix
				for(int j=0;j<b;j++) {
					tot[j]=0;
				}
				tot[b-1]=1;
				for(int i=b-2;i>=0;i--) {
					for(int j=i+1;j<b;j++) {
						tot[i]+= tot[j]*a[i][j];
					}
				}
				if(tot[0]==m) {
					pos=1;
					num=0;
				}
				num--;
			}
			output.print("Case #"+ii+": ");
			if(pos==1) {
				output.println("POSSIBLE");
				for(int i=0;i<b;i++) {
					for(int j=0;j<b;j++){
						output.print(a[i][j]);
					}
					output.println();
				}
			} else {
				output.println("IMPOSSIBLE");
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