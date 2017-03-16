import java.io.File;
import java.io.PrintWriter;
import java.util.Scanner;


public class C {

	// 0 = 1
	// 1 = -1
	// 2 = i
	// 3 = -i
	// 4 = j
	// 5 = -j
	// 6 = k
	// 7 = -k

	int multiply(int q1, int q2) {
		switch (q1) {
		case 0: return q2;
		case 1: return (q2 ^ 1);
		case 2: {
			switch (q2) {
			case 0: return 2;
			case 1: return 3;
			case 2: return 1;
			case 3: return 0;
			case 4: return 6;
			case 5: return 7;
			case 6: return 5;
			case 7: return 4;
			}
		}
		case 3: return multiply(2,q2)^1;
		case 4: {
			switch (q2) {
			case 0: return 4;
			case 1: return 5;
			case 2: return 7;
			case 3: return 6;
			case 4: return 1;
			case 5: return 0;
			case 6: return 2;
			case 7: return 3;
			}
		}
		case 5: return multiply(4,q2)^1;
		case 6: {
			switch (q2) {
			case 0: return 6;
			case 1: return 7;
			case 2: return 4;
			case 3: return 5;
			case 4: return 3;
			case 5: return 2;
			case 6: return 1;
			case 7: return 0;
			}
		}
		case 7: return multiply(6,q2)^1;
		default: throw new AssertionError();
		}
	}

	String format(int q) {
		switch(q){
		case 0: return "1";
		case 1: return "-1";
		case 2: return "i";
		case 3: return "-i";
		case 4: return "j";
		case 5: return "-j";
		case 6: return "k";
		case 7: return "-k";
		default:
		throw new AssertionError();
		}
	}

	boolean solve(String s, long X) {
		// Evaluate i*j*k == -1
		// Evaluate s
		int sVal = 0; // 1
		for (int i=0; i<s.length(); i++) {
			int ch = 0;
			switch (s.charAt(i)) {
			case 'i': ch = 2; break;
			case 'j': ch = 4; break;
			case 'k': ch = 6; break;
			default: throw new AssertionError();
			}
			sVal = multiply(sVal, ch);
		}
		int temp = sVal; //
		int sValPow = 0; // 1
		long x = X;
		// fast exponentiation
		while (x > 0) {
			if (x%2==1) {
				sValPow = multiply(sValPow, temp);
			}
			x /= 2;
			temp = multiply(temp,temp);
		}

		if (sValPow != 1) return false;

		// Find the shortest prefix that evaluates to i
		int state = 0; // 0 = looking for i,  1 = looking for j
		int timer = s.length() * 8 + 2; // after this, there should be a cycle
		int curr = 0; // 1
		for (long t = 0; t < X; t++) {
			for (int i=0; i<s.length(); i++) {
				int ch = 0;
				switch (s.charAt(i)) {
				case 'i': ch = 2; break;
				case 'j': ch = 4; break;
				case 'k': ch = 6; break;
				default: throw new AssertionError();
				}
				curr = multiply(curr, ch);
				if (state==0) {
					if (curr == 2) {
						// found i
						state = 1;
						timer = s.length() * 8 + 2; // reset timer
						curr = 0;
					} else {
						timer--;
						if (timer < 0) return false;
					}
				} else if (state == 1) {
					if (curr == 4 ) {
						// found j, the remaining must be k
						return true;
					} else{
						timer--;
						if (timer < 0) return false;
					}
				}
			}
		}
		return false;
	}


	public static void main(String[] args) {
		try {
			File fin = new File("C-large.in");
			Scanner sc = new Scanner(fin);
			File fout = new File("cout.txt");
			PrintWriter pw = new PrintWriter(fout);
			//PrintWriter pw = new PrintWriter(System.out);
			int T = sc.nextInt();
			for (int cn=1; cn<=T; cn++) {
				int L = sc.nextInt();
				long X = sc.nextLong();
				String s = sc.next();
				C c = new C();
				pw.write("Case #" + cn + ": " + (c.solve(s, X) ? "YES":"NO") + "\n");
			}
			pw.flush();
			pw.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
}
