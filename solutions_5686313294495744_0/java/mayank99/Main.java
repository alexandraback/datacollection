import java.util.*;
import java.io.*;

public class Main {
	public static void main(String args[]) {
		Input input = new Input();
		Output output = new Output();

		int t = input.nextInt();

		for(int ii=1;ii<=t;ii++) {
			int n = input.nextInt();
			String[] a = new String[n];
			String[] b = new String[n];

			Map<String, Integer> km = new HashMap<String, Integer>();
			Map<String, Integer> vm = new HashMap<String, Integer>();
				
			int uniq_k =0;
			int uniq_v =0;
			for(int i=0;i<n;i++) {
				a[i] = input.nextString();
				b[i]= input.nextString();
				
				if(km.containsKey(a[i])) {
					int val = km.get(a[i]);
					val++;
					km.put(a[i],val);
				} else {
					km.put(a[i],1);
					uniq_k ++;
				}

				if(vm.containsKey(b[i])) {
					int val = vm.get(b[i]);
					val++;
					vm.put(b[i],val);
				} else {
					vm.put(b[i],1);
					uniq_v++;
				}

			}
/*
			for(int i=0;i<n;i++) {
				if((km.get(a[i])>=2)&&(vm.get(b[i])>=2)) {
					int val = fkm.get(a[i]);
					val++;
					fkm.put(a[i],val);
		
					val = fvm.get(b[i]);
					val++;
					fvm.put(b[i],val);
				}
			}
			int lc=0;
			int rc =0;

			for(String i: km.keySet()) {
				lc+= Math.max((km.get(i) - fkm.get(i)),1);
			}

			for(String i: vm.keySet()) {
				rc+= Math.max((vm.get(i) - fvm.get(i)),1);
			}

			lc = Math.max(lc,rc);
			lc = n-lc;
			*/
			int pos =1;
			for(int jj=0;jj<n;jj++) {
				pos*=2;
			}

			pos--;
			int lc =n;

			while(pos!=0) {

				Map<String, Integer> ktmp = new HashMap<String, Integer>();
				Map<String, Integer> vtmp = new HashMap<String, Integer>();
				int tmpk=0;
				int tmpv=0;
				int tmp = pos;
				int c=0;
				int oc=0;
				while(tmp!=0) {
					if(tmp%2==1) {
						oc++;
						if(!ktmp.containsKey(a[c])) {
							ktmp.put(a[c],1);
							tmpk++;
						}

						if(!vtmp.containsKey(b[c])) {
							vtmp.put(b[c],1);
							tmpv++;
						}
					}
					c++;
					tmp/=2;
				}

				if((tmpk==uniq_k)&&(tmpv==uniq_v)) {
					lc = Math.min(lc, oc);
				}
				pos--;
			}

			lc = n - lc;

			output.println("Case #"+ ii +": "+lc);
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

	public void flush() {
		pw.flush();
	}
}