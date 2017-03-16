import java.io.File;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class P3 {

	public static class Quaternion {
		public String v;
		public int mul;
		public Quaternion(String value, int mul) {
			this.v = value;
			this.mul = mul;
		}
		@Override
		public String toString() {
			return (mul < 0) ? "-" + v : v;
		}
		@Override
		public boolean equals(Object obj) {
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			Quaternion other = (Quaternion) obj;
			if (mul != other.mul)
				return false;
			if (v == null) {
				if (other.v != null)
					return false;
			} else if (!v.equals(other.v))
				return false;
			return true;
		}
	}

	private static final String FILE_PREFIX = "C-large";

	private static final Quaternion Q_I = new Quaternion("i", 1);
	private static final Quaternion Q_K = new Quaternion("k", 1);
	private static final Quaternion Q_MINUS_1 = new Quaternion("1", -1);
	
	public static Map<String, Quaternion> t = new HashMap<String, Quaternion>();
	
	static {
		t.put("i1", new Quaternion("i", 1));
		t.put("ii", new Quaternion("1", -1));
		t.put("ij", new Quaternion("k", 1));
		t.put("ik", new Quaternion("j", -1));

		t.put("j1", new Quaternion("j", 1));
		t.put("ji", new Quaternion("k", -1));
		t.put("jj", new Quaternion("1", -1));
		t.put("jk", new Quaternion("i", 1));

		t.put("k1", new Quaternion("k", 1));
		t.put("ki", new Quaternion("j", 1));
		t.put("kj", new Quaternion("i", -1));
		t.put("kk", new Quaternion("1", -1));
		
		t.put("11", new Quaternion("1", 1));
		t.put("1i", new Quaternion("i", 1));
		t.put("1j", new Quaternion("j", 1));
		t.put("1k", new Quaternion("k", 1));
	}
	
	public static Quaternion multiply(Quaternion first, Quaternion second) {
		String c = first.v + second.v;
		int mul = first.mul * second.mul;
		
		Quaternion result = t.get(c);
		mul *= result.mul;
		
		return new Quaternion(result.v, mul);
	}
	
	public static void main(String[] args) throws Exception {

		Scanner scanner = new Scanner(new File(FILE_PREFIX + ".in"));
		PrintWriter writer = new PrintWriter(new File(FILE_PREFIX + ".out"));
		int T = scanner.nextInt();
		for (int m=0; m<T; m++) {
			long L = scanner.nextLong();
			long X = scanner.nextLong();
			
			boolean R = false;
			
			String s = scanner.next();
			StringBuilder sb = new StringBuilder();
			
			for (int j=0; j<X%4; j++)
				sb.append(s);
			
			String F = sb.toString();

			Quaternion val = new Quaternion("1", 1);
			
			for (int i=0; i<F.length(); i++)
				val = multiply(val, new Quaternion(String.valueOf(F.charAt(i)), 1));
			
			if (val.equals(Q_MINUS_1)) {

				if (X >= 4)
					for (int i=0; i<4; i++)
						sb.append(s);

				F = sb.toString();
				
				long C = X * L - F.length();

				int r_i = -1, r_k = -1;

				Quaternion q_1 = new Quaternion("1", 1);
				for (int i=0; i<F.length(); i++) {
					q_1 = multiply(q_1, new Quaternion(String.valueOf(F.charAt(i)), 1));
					if (q_1.equals(Q_I)) {
						r_i = i;
						break;
					}
				}
				
				Quaternion q_2 = new Quaternion("1", 1);
				for (int i=F.length()-1; i>=0; i--) {
					q_2 = multiply(new Quaternion(String.valueOf(F.charAt(i)), 1), q_2);
					if (q_2.equals(Q_K)) {
						r_k = i;
						break;
					}
				}

				R = (r_i > -1 && r_k > -1 && r_i < r_k + C);
			}
			
			System.out.println("Case #" + (m+1) + ": " + (R?"YES":"NO"));
			writer.println("Case #" + (m+1) + ": " + (R?"YES":"NO"));
		}
		scanner.close();
		writer.close();
	}
}
