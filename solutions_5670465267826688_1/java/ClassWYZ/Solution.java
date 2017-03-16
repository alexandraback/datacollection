import java.util.Scanner;


public class Solution {
	//1:1;
	//i:2;
	//j:3;
	//k:4;
	//-1:5;
	//-i:6;
	//-j:7;
	//-k:8
	public static int multiply(int a, int b) {
		if (a == 1) {
			if (b == 1) return 1;
			else if (b == 2) return 2;
			else if (b == 3) return 3;
			else return 4;
		}
		else if (a == 2) {
			if (b == 1) return 2;
			else if (b == 2) return 5;
			else if (b == 3) return 4;
			else return 7;
		}
		else if (a == 3) {
			if (b == 1) return 3;
			else if (b == 2) return 8;
			else if (b == 3) return 5;
			else return 2;
		}
		else {
			if (b == 1) return 4;
			else if (b == 2) return 3;
			else if (b == 3) return 6;
			else return 5;
		}
	}
	public static boolean judge(String s, int repeat, long origin) {
		if (repeat > 4) repeat = repeat % 4 + 4;
		int length = s.length() * repeat;
		//sign: true:positive; false:negative
		boolean sign = true;
		int count;
		int[] a = new int[length];
		for (int i = 0; i < length; ++i) {
			if (s.charAt(i % s.length()) == 'i') a[i] = 2;
			else if (s.charAt(i % s.length()) == 'j') a[i] = 3;
			else a[i] = 4;
		}
		count = a[0];
		for (int i = 1; i < length; ++i) {
			count = multiply(count, a[i]);
			if (count > 4) {
				sign = !sign;
				count -= 4;
			}
		}
		if ((!sign && count == 1) == false) return false;
		int i = 0;
		boolean signi = true;
		int counti = a[0];
		while (!(counti == 2 && signi) && (i + 1) < length) {
			++i;
			counti = multiply(counti, a[i]);
			if (counti > 4) {
				signi = !signi;
				counti -= 4;
			}
		}
		
		boolean signj = true;
		int countj = a[i];
		int j;
		for (j = i + 1; j < length; ++j) {
			countj = a[j];
			signj = true;
			for (int x = j; x < length - 1; ++x) {
				//if (j == 6) System.out.println(countj + " " + signj);
				countj = multiply(countj, a[x + 1]);
				if (countj > 4) {
					signj = !signj;
					countj -=4;
				}
			}
			//System.out.println(j + " " + countj + " "+ signj);
			if (countj == 4 && signj) break;
		}
		if (signi && signj && counti == 2 && countj == 4 && i < (j + origin * s.length() - length)) return true;
		else return false;
	}
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int num = in.nextInt();
		in.nextLine();
		for (int i = 0; i < num; ++i) {
			in.nextInt();
			long repeat = in.nextLong();
			long origin = repeat;
			if (repeat > 4) repeat = repeat % 4 + 4;
			in.nextLine();
			String s = in.nextLine();
			String res = judge(s, (int) repeat, origin) ? "YES" : "NO";
			System.out.println("Case #" + (i + 1) + ": " + res);
		}
		in.close();
	}

}
