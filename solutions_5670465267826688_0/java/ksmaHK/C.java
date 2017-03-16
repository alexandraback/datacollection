import java.util.*;

public class C {
public static boolean POS_VE = false;
public static boolean NEG_VE = true;
public static boolean[][] SIGN = new boolean[][] {{POS_VE, POS_VE, POS_VE, POS_VE},
										{POS_VE, NEG_VE, POS_VE, NEG_VE},
										{POS_VE, NEG_VE, NEG_VE, POS_VE},
										{POS_VE, POS_VE, NEG_VE, NEG_VE}};
public static int ONE = 0;
public static int I = 1;
public static int J = 2;
public static int K = 3;

public static int[][] MULT = new int[][] {{0, I, J, K},
									{I, 0, K, J},
									{J, K, 0, I},
									{K, J, I, 0}};

	
public static void main(String [] args) {
	Scanner scanner = new Scanner(System.in);
	int nCase = scanner.nextInt();

	for (int nc = 1; nc <= nCase; nc++) {
		int L = scanner.nextInt();
		int X = scanner.nextInt();
		String str = scanner.next();
		StringBuilder oldSeq = new StringBuilder(str);
		for (int i = 0; i < oldSeq.length(); i++)
			switch(oldSeq.charAt(i)) {
				case 'i':
					oldSeq.setCharAt(i, (char) I);
					break;
				case 'j':
					oldSeq.setCharAt(i, (char) J);
					break;
				case 'k':
					oldSeq.setCharAt(i, (char) K);
					break;
			}

		StringBuilder seq = new StringBuilder(oldSeq);
		for (int i = 1; i < X; i++)
			seq.append(oldSeq);

		boolean ans = false;
		if (seq.length() >= 3) {			
			boolean s1 = POS_VE;
			int c1 = ONE;
			for (int i = 0; !ans && i < seq.length()-2; i++) {
				s1 = s1 ^ SIGN[c1][seq.charAt(i)];
				c1 = MULT[c1][seq.charAt(i)];
				if ((s1 != POS_VE) || c1 != I)
					continue;
				//System.out.println("i = "+i);
				boolean s2 = POS_VE;
				boolean s3 = POS_VE;
				int c2 = ONE;				
				int c3 = ONE;
				for (int kk = i+1; kk < seq.length(); kk++) {
						s3 = s3 ^ SIGN[c3][seq.charAt(kk)];
						c3 = MULT[c3][seq.charAt(kk)];
				}
				for (int k = i+1; !ans && k < seq.length()-1; k++) {
					s2 = s2 ^ SIGN[c2][seq.charAt(k)];
					c2 = MULT[c2][seq.charAt(k)];
					s3 = NEG_VE ^ s3 ^ SIGN[seq.charAt(k)][c3] ;
					c3 = MULT[seq.charAt(k)][c3];
					//System.out.println("k = "+k + " s2: "+ (!s2) + " c2: "+ c2 + " s3: "+ (!s3) + " c3: " + c3);
					
					if ((s2 == POS_VE) && (s3 == POS_VE) && (c2 == J) && (c3 == K))
						ans = true;					
				}
			}
		}
		System.out.println("Case #" + nc + ": " + (ans ? "YES" : "NO"));
	}
}
}