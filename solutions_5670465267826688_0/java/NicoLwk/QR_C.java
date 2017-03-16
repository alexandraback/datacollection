import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class QR_C {

	public static void main(String[] args) throws IOException {
		Scanner sc2 = new Scanner(System.in);
		String inFile = sc2.nextLine();
		String outFile = inFile + ".out.txt";
		FileReader fr = new FileReader(inFile);
		Scanner sc = new Scanner(new BufferedReader(fr));
		FileWriter fw = new FileWriter(outFile);
		BufferedWriter bw = new BufferedWriter(fw);
		PrintWriter pw = new PrintWriter(bw);
		int T = sc.nextInt();
		for (int i = 0; i < T; i++)
			new CaseC(sc, pw, i + 1);
		sc.close();
		pw.close();
	}

}

class CaseC {

	CaseC(Scanner sc, PrintWriter pw, int caseNo) {
		boolean ans = exec(sc);
		pw.println("Case #" + caseNo + ": " + (ans ? "YES" : "NO"));
		System.out.println("Case #" + caseNo + ": " + (ans ? "YES" : "NO"));
	}

	boolean exec(Scanner sc) {
		int L = sc.nextInt(), X = sc.nextInt();
		String q_str = sc.next();
		if (L * X < 3)
			return false;
		Quaternion q[] = new Quaternion[L];
		Quaternion q1 = new Quaternion(0, 1);
		Quaternion qn1 = new Quaternion(0, -1);
		Quaternion product = new Quaternion(0, 1);
		for (int i = 0; i < L; i++) {
			q[i] = new Quaternion(q_str.charAt(i) - 'i' + 1, 1);
			product = product.mul(q[i]);
		}
		// System.out.println(product);
		// Check if product of whole is correct
		if (product.dim == 0) {
			if (product.sign == 1)
				return false;
			if (X % 2 != 1)
				return false;
		} else {
			if (X % 4 != 2)
				return false;
		}

		Quaternion productPower[] = new Quaternion[4];
		productPower[0] = product;
		for (int i = 1; i < 4; i++)
			productPower[i] = productPower[i - 1].mul(product);

		Quaternion leftTarget = null, rightTarget = null;
		int left[] = new int[4];
		int right[] = new int[4];
		for (int i = 0; i < 4; i++) {
			Quaternion qi = new Quaternion(1, 1);
			Quaternion qk = new Quaternion(3, 1);
			for (int j = 0; j < 4; j++) {
				for (int k = -1; k <= 1; k += 2) {
					Quaternion qtest = new Quaternion(j, k);
					if (productPower[i].mul(qtest).equals(qi))
						leftTarget = qtest;
					if (qtest.mul(productPower[i]).equals(qk))
						rightTarget = qtest;
				}
			}
			left[i] = -1;
			Quaternion tmp = q1;
			for (int j = 0; j < L; j++) {
				tmp = tmp.mul(q[j]);
				if (tmp.equals(leftTarget)) {
					left[i] = j;
					break;
				}
			}
			right[i] = -1;
			tmp = q1;
			for (int j = L - 1; j >= 0; j--) {
				tmp = q[j].mul(tmp);
				if (tmp.equals(rightTarget)) {
					right[i] = j;
					break;
				}
			}
			// System.out.println("left[" + i + "]=" + left[i]);
			// System.out.println("right[" + i + "]=" + right[i]);
		}
		/*
		 * for (int i = 0; i < 4; i++) { int l = left[i], r = right[(X % 4 - i + 3) % 4]; if (l != -1 && r != -1 && (X / 4 > 0 || l + 1 < r)) return true; } for (int i = 0; i < 4; i++) { int l = left[(X % 4 - i + 3) % 4], r = right[i]; if (l != -1 &&
		 * r != -1 && (X / 4 > 0 || l + 1 < r)) return true; }
		 */
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				int l = left[i], r = right[j];
				int l_count = (i + 1) % 4, r_count = (j + 1) % 4;
				if (l != -1 && r != -1) {
					if (l_count + r_count + 1 < X)
						return true;
					else if (l + 1 < r)
						return true;
				}
			}
		}
		return false;
	}
}

class Quaternion {
	static final int mulDim[][] = { { 0, 1, 2, 3 }, { 1, 0, 3, 2 }, { 2, 3, 0, 1 }, { 3, 2, 1, 0 } };
	static final int mulSign[][] = { { 1, 1, 1, 1 }, { 1, -1, 1, -1 }, { 1, -1, -1, 1 }, { 1, 1, -1, -1 } };

	int dim, sign;

	Quaternion(int dim, int sign) {
		this.dim = dim;
		this.sign = sign;
	}

	Quaternion mul(Quaternion q) {
		return new Quaternion(mulDim[dim][q.dim], mulSign[dim][q.dim] * sign * q.sign);
	}

	boolean equals(Quaternion q) {
		return dim == q.dim && sign == q.sign;
	}

	public String toString() {
		String name[] = { "1", "i", "j", "k" };
		if (sign == -1)
			return "-" + name[dim];
		else
			return name[dim];
	}
}