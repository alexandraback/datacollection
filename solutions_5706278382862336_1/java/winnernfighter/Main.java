import java.awt.peer.SystemTrayPeer;
import java.util.Scanner;

import org.omg.CORBA.PUBLIC_MEMBER;

public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();// test cases

		for (int t = 0; t < T; t++) {
			String s = sc.next();
			String p = "";
			int i = 0;
			for (i = 0; i < s.length(); i++) {
				if (s.charAt(i) != '/')
					p += s.charAt(i);
				else
					break;
			}

			String q = s.substring(i + 1, s.length());
			
			double a = Long.valueOf(p);
			double b = Long.valueOf(q);

			double d = a / b;
			String k = convert_to_binary(d);
			int r = 0;
			if (k.equals("Impossible"))
				System.out.println("Case #" + (t + 1) + ": impossible");
			else {
				for (i = 0; i < k.length(); i++) {
					if (k.charAt(i) == '0')
						r++;
					else {
						System.out.println("Case #" + (t + 1) + ": "+(r+1));
						break;
					}
				}
			}
		}

	}

	public static String convert_to_binary(double d) {
		String s = "";

		int k = 0;

		while (k < 40) {
			if (d == 0)
				break;
			d = d * 2;
			if (d >= 1) {
				s += "1";
				d--;
			} else
				s += "0";

			k++;
		}
		if (k == 40)
			s = "Impossible";
		return s;
	}
}
