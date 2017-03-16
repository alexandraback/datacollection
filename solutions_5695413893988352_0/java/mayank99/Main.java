import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Input input = new Input();
		Output output = new Output();

		int t = input.nextInt();

		for(int i=1;i<=t;i++) {
			String code = input.nextString();
			String jam = input.nextString();
			ArrayList<String> cc = populate(code);
			ArrayList<String> jj = populate(jam);
			Collections.sort(cc);
			Collections.sort(jj);

			int min = 10000;
			String cci = " ";
			String jji = " ";

			int jlen = jj.size();

			for(String c: cc) {

				Integer icode = Integer.parseInt(c);
				
				int lastMax = 100000;

				for(int k =0;k<jlen; k++) {
					String j = jj.get(k);
					Integer ijam = Integer.parseInt(j);
					int diff = abs(icode - ijam);
					if(diff<min) {
						min = diff;
						cci=c;
						jji=j;
					}
					if(diff<lastMax) {
						lastMax=diff;
					} else {
						k=jlen;
					}
				}
			}
			
			output.println("Case #"+ i +": "+cci +" "+jji);
		}

		output.flush();
	}
	public static int abs(int a) {
		if(a<0) {
			a*=-1;
		}
		return a;
	}

	public static ArrayList<String> populate(String a) {
		int len = a.length();
		int qc=0;
		for(int i=0;i<len;i++) {
			if(a.charAt(i)=='?') {
				qc++;
			}
		}
		if(qc==0) {
			ArrayList<String> res = new ArrayList<String>();
			res.add(a);
			return res;
		} else {
			int i=0;
			while(a.charAt(i)!='?') {
				i++;
			}
			ArrayList<String> res = new ArrayList<String>();
			ArrayList<String> ans;

			StringBuilder myName = new StringBuilder(a);
			myName.setCharAt(i,'0');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}
			
			myName.setCharAt(i,'1');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}

			myName.setCharAt(i,'2');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}

			myName.setCharAt(i,'3');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}

			myName.setCharAt(i,'4');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}
			
			myName.setCharAt(i,'5');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}
			
			myName.setCharAt(i,'6');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}

			myName.setCharAt(i,'7');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}
			
			myName.setCharAt(i,'8');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}
			
			myName.setCharAt(i,'9');
			ans = populate(myName.toString());
			for(String answ: ans) {
				res.add(answ);
			}
			return res;
		}
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

	public void flush() {
		pw.flush();
	}
}