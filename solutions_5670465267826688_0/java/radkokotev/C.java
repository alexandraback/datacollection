import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;


public class C {
	
	public static enum Val {One,I,J,K}
	
	static final V[][] mul = {
		{new V(Val.One, false), new V(Val.I, false), new V(Val.J, false), new V(Val.K, false) },
		{new V(Val.I, false),   new V(Val.One, true), new V(Val.K, false), new V(Val.J, true) },
		{new V(Val.J, false), new V(Val.K, true), new V(Val.One, true), new V(Val.I, false) },
		{new V(Val.K, false), new V(Val.J, false), new V(Val.I, true), new V(Val.One, true) },
		}; 
	
	static class V {
		public Val val;
		public boolean neg;
		public V(Val val, boolean neg) {this.val = val; this.neg = neg;}
		public void mul(V other) {
			V res = mul[this.val.ordinal()][other.val.ordinal()];
			this.val = res.val;
			this.neg = (this.neg ^ other.neg ^ res.neg);
		}
		
		public void mul(Val other) {
			V res = mul[this.val.ordinal()][other.ordinal()];
			this.val = res.val;
			this.neg = (this.neg ^ res.neg);
		}
		
		public void leftMul(Val other) {
			V res = mul[other.ordinal()][this.val.ordinal()];
			this.val = res.val;
			this.neg = (this.neg ^ res.neg);
		}
	}
	
	public static Val getVal(char c) {
		switch (c) {
		case 'i':
			return Val.I;
		case 'j':
			return Val.J;
		case 'k':
			return Val.K;
		}
		return Val.One;
	}

	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt1.in"));
//		BufferedReader in = new BufferedReader(new FileReader("c_test.in"));
		PrintWriter pw = new PrintWriter(System.out);
		
		int T = Integer.parseInt(in.readLine());
		for (int t = 1; t <= T; t++) {
			String[] pls = in.readLine().split(" ");
			int x = Integer.parseInt(pls[1]);
			String s = in.readLine();
			StringBuilder b = new StringBuilder();
			for (int i = 0; i < x; i++) b.append(s);
			char seq[] = b.toString().toCharArray();
			
			ArrayList<Integer> i_candidates  = new ArrayList<>();
			ArrayList<Integer> k_candidates  = new ArrayList<>();
			
			V cur = new V(Val.One, false);
			for (int i = 0; i < seq.length; i++) {
				cur.mul(getVal(seq[i]));
				if (cur.val == Val.I && !cur.neg) {
					i_candidates.add(i);
				}
			}
			
			if (cur.val != Val.One || !cur.neg) {
				pw.format("Case #%d: NO\n", t);
				continue;
			}
			
			cur = new V(Val.One, false);
			for (int i = seq.length - 1; i >= 0; i--) {
				cur.leftMul(getVal(seq[i]));
				if (cur.val == Val.K && !cur.neg) {
					k_candidates.add(i);
				}
			}
			
//			System.out.println(i_candidates.size() +  " x " + k_candidates.size());
			
			boolean found = false;
			for (int i : i_candidates) {
				if (found) break;
				for (int k : k_candidates) {
					if (i + 1 >= k) break;
					found = true;
					break;
//					cur = new V(Val.One, false);
//					for (int j = i + 1; j < k; j++) {
//						cur.mul(getVal(seq[j]));
//					}
//					if (!cur.neg && cur.val == Val.J) {
//						found = true;
//						break;
//					}
				}
			}
			
			if (found) {
				pw.format("Case #%d: YES\n", t);
			} else {
				pw.format("Case #%d: NO\n", t);
			}
			pw.flush();
		}
		
		
		
		
		pw.close();
		in.close();
	}
}