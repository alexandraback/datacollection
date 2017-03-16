package round1c;

import java.io.IOException;
import java.util.Scanner;

public class B {

	static Scanner sc = new Scanner(System.in);
	public static void main(String[] args) throws Exception {
		int T;

		T = sc.nextInt();
		for (int i = 1; i <= T; i++) {
			System.out.println("Case #" + i + ": " + resolve());
		}
	}

	private static String resolve() throws IOException{//params) {
		int X, Y;
		StringBuilder sb = new StringBuilder();
		X = sc.nextInt();
		Y = sc.nextInt();
		
		if (X > 0){
			for (int i = 0; i < X; ++i) {
				sb.append("WE");
			}
		}
		else if (X <0){
			for (int i = 0; i < (X * -1); ++i) {
				sb.append("EW");
			}
		}
		
		if (Y > 0){
			for (int i = 0; i < Y; ++i) {
				sb.append("SN");
			}
		}
		else if (Y < 0){
			for (int i = 0; i < (Y * -1); ++i) {
				sb.append("NS");
			}
		}
		
		return sb.toString();
	}

}
