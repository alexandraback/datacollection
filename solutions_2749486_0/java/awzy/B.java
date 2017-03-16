import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.util.Scanner;

public class B {
	public static void main(String[] args) throws IOException {
		String name = "B-small-attempt0";
		Scanner sc = new Scanner(new File(name + ".in"));
		//Scanner sc = new Scanner(System.in);
		PrintWriter out = new PrintWriter(new FileWriter(name + ".out"));
		int n = sc.nextInt();
		for (int c = 1; c <= n; c++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			String str = "";
			if(x < 0) {
				for(int i = 0; i < -x; i++) {
					str += "EW";
				}
			} else {
				for(int i = 0; i < x; i++) {
					str += "WE";
				}
			}
			if(y < 0) {
				for(int i = 0; i < -y; i++) {
					str += "NS";
				}
			} else {
				for(int i = 0; i < y; i++) {
					str += "SN";
				}
			}
			String ans = "Case #" + c + ": " + str;
			out.println(ans);
			System.out.println(ans);
		}
		out.close();
		sc.close();
	}

}
