import java.io.*;
import java.util.*;

public class C {
	static BufferedReader in;
	static StringTokenizer st;
	static PrintWriter out;
	
	static String nextToken() throws IOException {
		while (st==null || !st.hasMoreTokens())
			st = new StringTokenizer(in.readLine());
		return st.nextToken();
	}
	
	static int nextInt() throws IOException {
		return Integer.parseInt(nextToken());
	}
	
	static long nextLong() throws IOException {
		return Long.parseLong(nextToken());
	}
	
	public static void main(String[] args) throws IOException {
		in = new BufferedReader(new FileReader("C.in"));
		out = new PrintWriter(new FileWriter("C.out"));
		
		int qq = nextInt();
		for (int q=1; q<=qq; q++) {
			out.printf("Case #%d: ", q);
			int len = nextInt(); long times = nextInt();
			
			char[] s = nextToken().toCharArray();
			Quat[] arr = new Quat[len];
			Quat prod = new Quat(1);
			for (int i=0; i<len; i++) {
				arr[i] = new Quat(s[i]);
				prod = Quat.times(prod, arr[i]);
			}
			
			long leftI = findI(arr, prod, len, times);
			long rightK = findK(arr, prod, len, times);
			
			Quat total = null;
			switch((int)(times%4)) {
			case 0: total = new Quat(1); break;
			case 1: total = prod; break;
			case 2: total = new Quat(prod.value==1||prod.value==-1?1:-1); break;
			case 3: total = new Quat(prod.value==1||prod.value==-1?prod.value:-prod.value); break;
			}
			
			boolean ans = (leftI+1 <= rightK-1) && total.value == -1;					
			out.println(ans?"YES":"NO");
		}
		out.close();
	}

	private static long findI(Quat[] arr, Quat prod, long len, long times) {
		long leftI = len*times;
		Quat help = new Quat(1);
		for (int i=0; i<len; i++) {
			help = Quat.times(help, arr[i]);
			if (help.value==2) {
				leftI = i; break;
			} else if (help.value==-2 && prod.value!=1 && prod.value!=-1) {
				long poss = i+len*2;
				if (poss<leftI) leftI = poss;
			}
			
			Quat t = Quat.times(prod, help);
			if(t.value==2) {
				long poss = i+len;
				if (poss<leftI) leftI = poss;
			} else if (t.value==-2 && prod.value!=1 && prod.value!=-1) {
				long poss = i+len*3;
				if (poss<leftI) leftI = poss;
			}
		}
		return leftI;
	}
	
	private static long findK(Quat[] arr, Quat prod, long len, long times) {
		long rightK = -1;
		Quat help = new Quat(1);
		for (long i=times*len-1; i>=times*len-len; i--) {
			help = Quat.times(arr[(int)(i%len)], help);
			if (help.value==4) {
				rightK = i; break;
			} else if (help.value == -4 && prod.value!=1 && prod.value!=-1) {
				long poss = i - 2*len;
				if (poss>rightK) rightK = poss;
			}
			
			Quat t = Quat.times(help, prod);
			if (t.value == 4) {
				long poss = i  - len;
				if (poss>rightK) rightK = poss;
			} else if (t.value == -4 && prod.value!=1 && prod.value!=-1) {
				long poss = i - 3*len;
				if (poss>rightK) rightK = poss;
			}
		}
		return rightK;
	}
	
	static private class Quat {
		static int[][] table = {{1, 2, 3, 4}, {2, -1, 4, -3}, {3, -4, -1, 2}, {4, 3, -2, -1}};
		
		int value;
		
		public Quat(char c) {
			this(c, false);
		}
		
		public Quat(char c, boolean neg) {
			switch(c) {
			case '1': value = 1; break;
			case 'i': value = 2; break;
			case 'j': value = 3; break;
			case 'k': value = 4; break;
			}
			if (neg) value = -value;
		}
		
		public Quat(int v) {
			value = v;
		}
		
		static Quat times(Quat a, Quat b) {
			int aval = a.value, bval = b.value;
			int mult = 1;
			if (aval < 0) {
				aval = -aval; mult*=-1;
			}
			if (bval < 0) {
				bval = -bval; mult*=-1;
			}
			return new Quat(mult * table[aval-1][bval-1]);
		}
	}
}
