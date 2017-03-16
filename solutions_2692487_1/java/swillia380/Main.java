import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static final BigInteger two = new BigInteger("2");
	
	public static int sss(int N, int[] motes,BigInteger A) {
		int C = 0;
		for (int i = 0; i < N; i++) {
			if (A.compareTo(BigInteger.valueOf(motes[i]))==1) {
				A = A.add(BigInteger.valueOf(motes[i]));
			} else {
				if (A.add(A.subtract(BigInteger.ONE)).compareTo(BigInteger.valueOf(motes[i]))==1) {
					C = C+1;
					A = A.add(A.subtract(BigInteger.ONE));
					A = A.add(BigInteger.valueOf(motes[i]));
				} else {
					if (A.compareTo(BigInteger.ONE)!=0) {
						C = C+1+min(
								sss(N-i, 
										Arrays.copyOfRange(motes, i, motes.length),
										A.add(A.subtract(BigInteger.ONE))),
								N-i-1);
						i = N+1;
					} else {
						C = C+N-i;
						i = N+1;
					}
				}
			}
		}
		return C;
	}
	public static int min(int A, int B) {
		if (A <= B)
			return A;
		return B;
	}
	
	public static String solve(Scanner in) {
		String ss = new String();
		BigInteger A = in.nextBigInteger();
		int N = in.nextInt();
		int[] motes = new int[N];
		for (int i = 0; i < N; i++) {
			motes[i] = in.nextInt();
		}
		Arrays.sort(motes);
		int C = 0;
		for (int i = 0; i < N; i++) {
			if (A.compareTo(BigInteger.valueOf(motes[i]))==1) {
				A = A.add(BigInteger.valueOf(motes[i]));
			} else {
				if (A.add(A.subtract(BigInteger.ONE)).compareTo(BigInteger.valueOf(motes[i]))==1) {
					C = C+1;
					A = A.add(A.subtract(BigInteger.ONE));
					A = A.add(BigInteger.valueOf(motes[i]));
				} else {
					C = C+1+min(
							sss(N-i, 
									Arrays.copyOfRange(motes, i, motes.length),
									A.add(A.subtract(BigInteger.ONE))),
							N-i-1);
					i = N+1;
				}
			}
		}
		ss = Integer.valueOf(C).toString();
		return ss;
	}
	
	public static void main(String[] args) {
		try {
		Scanner in = new Scanner(new File("/home/steven/workspace/Codejam/Ain"));
		PrintWriter out = new PrintWriter(new FileWriter("/home/steven/workspace/Codejam/Aout")); 
		int cases;
		cases = in.nextInt();
		for (int i = 0; i < cases; i++) {
			System.out.println("Trying case "+(i+1)+"...");
			out.println("Case #"+(i+1)+": "+solve(in));
			System.out.println("Success!");
		}
		in.close();
		out.close();
		} catch (IOException e) {
			System.out.println("IO Problems");
		}
		System.out.println("Done!");
	}
}

