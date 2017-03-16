import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Input input = new Input();
		Output output = new Output();

		int t = input.nextInt();

		for(int i=1;i<=t;i++) {
			int[] a = new int[26];

			for(int j=0;j<26;j++) {
				a[j]=0;
			}

			String s = input.nextString();
			int len = s.length();
			for(int j=0;j<len;j++) {
				char ch = s.charAt(j);
				a[ch-'A']++;
			}

			int[] cnt = new int[10];
			for(int j=0;j<10;j++) {
				cnt[j]=0;
			}
			
			System.out.print("Case #"+i+": ");
			
			cnt[0]= a['Z'-'A'];
			a['Z'-'A']-=cnt[0];
			a['E'-'A']-=cnt[0];
			a['R'-'A']-=cnt[0];
			a['O'-'A']-=cnt[0];

			cnt[2]= a['W'-'A'];
			a['T'-'A']-=cnt[2];
			a['W'-'A']-=cnt[2];
			a['O'-'A']-=cnt[2];

			cnt[4]= a['U'-'A'];
			a['F'-'A']-=cnt[4];
			a['O'-'A']-=cnt[4];
			a['U'-'A']-=cnt[4];
			a['R'-'A']-=cnt[4];

			cnt[6]= a['X'-'A'];
			a['S'-'A']-=cnt[6];
			a['I'-'A']-=cnt[6];
			a['X'-'A']-=cnt[6];

			cnt[8]= a['G'-'A'];
			a['E'-'A']-=cnt[8];
			a['I'-'A']-=cnt[8];
			a['G'-'A']-=cnt[8];
			a['H'-'A']-=cnt[8];
			a['T'-'A']-=cnt[8];

			cnt[5]= a['F'-'A'];
			a['F'-'A']-=cnt[5];
			a['I'-'A']-=cnt[5];
			a['V'-'A']-=cnt[5];
			a['E'-'A']-=cnt[5];
			
			cnt[7]= a['S'-'A'];
			a['S'-'A']-=cnt[7];
			a['E'-'A']-=cnt[7];
			a['V'-'A']-=cnt[7];
			a['E'-'A']-=cnt[7];
			a['N'-'A']-=cnt[7];

			cnt[3]= a['T'-'A'];
			a['T'-'A']-=cnt[3];
			a['H'-'A']-=cnt[3];
			a['R'-'A']-=cnt[3];
			a['E'-'A']-=cnt[3];
			a['E'-'A']-=cnt[3];

			cnt[1]= a['O'-'A'];
			a['O'-'A']-=cnt[1];
			a['N'-'A']-=cnt[1];
			a['E'-'A']-=cnt[1];
			
			cnt[9]= a['I'-'A'];
			a['N'-'A']-=cnt[9];
			a['I'-'A']-=cnt[9];
			a['N'-'A']-=cnt[9];
			a['E'-'A']-=cnt[9];
					
			for(int j=0;j<10;j++) {
				int k = cnt[j];
				while(k!=0) {
					System.out.print(j);
					k--;
				}
			}
						
			System.out.println();
		}

	//	System..flush();
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