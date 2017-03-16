import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.StringTokenizer;
import java.math.BigInteger;

public class C {
    static BufferedReader stdin = new BufferedReader(new InputStreamReader(System.in));
    static StringTokenizer st = new StringTokenizer("");

    public static void main(String[] args) throws Exception {
        int T = readInt();
        int caseN = 1;
        while (T-- > 0) {
            int J = readInt();
			int P = readInt();
			int S = readInt();
			int K = readInt();
            System.out.print("Case #"+(caseN++)+": ");
			long total = 0;

            int[][] jp = new int[J+1][P+1];
            int[][] ps = new int[P+1][S+1];
            int[][] js = new int[J+1][S+1];
            StringBuilder res = new StringBuilder();
			for(int j = 1; j <= J; j++) {
                for(int p = 1; p <= P; p++) {
                    for(int s = 1; s <= S; s++) {
                        if(jp[j][p] < K && ps[p][s] < K && js[j][s] < K) {
                            total++;
                            jp[j][p]++;
                            ps[p][s]++;
                            js[j][s]++;
                            res.append(""+j+" "+p+" "+s+"\n");
                        }
                    }
                }
            }
            System.out.println(total);
            System.out.print(res.toString());
            
        }
    }

    // Read next input-token as string.
    static String readString() throws Exception {
        while (!st.hasMoreTokens()) {
            st = new StringTokenizer(stdin.readLine());
        }
        return st.nextToken();
    }

    // Read next input-token as integer.
    static int readInt() throws Exception {
        return Integer.parseInt(readString());
    }
    
    // Read next input-token as long.
    static long readLong() throws Exception {
        return Long.parseLong(readString());
    }

    // Read next input-token as double.
    static double readDouble() throws Exception {
        return Double.parseDouble(readString());
    }
	
	
	public static long divisor(long x) {
		if(x % 2 == 0) return 2;
		for(long i = 3; i <= Math.sqrt(x); i += 2) {
			if(x % i == 0) return i;
		}
		return -1;
	}
	private static BigInteger long_max = new BigInteger("9223372036854775807");
	private static BigInteger long_max_sqrt = new BigInteger("3037000499");
	
	public static String divisor(BigInteger x) {
		if(x.compareTo(long_max) < 0) return "" + divisor(x.longValue());

		BigInteger two = new BigInteger("2");
		if(x.mod(two).equals(BigInteger.ZERO)) return "2";

		BigInteger limit = x.divide(long_max_sqrt);
		for(BigInteger i = new BigInteger("3"); i.compareTo(limit) <= 0; i = i.add(two)) {
			if(x.mod(i).equals(BigInteger.ZERO)) return i.toString();
		}
		return "-1";
	}
}

