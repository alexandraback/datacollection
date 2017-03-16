import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;

public class A {
	public static void main(String[] args) throws FileNotFoundException, UnsupportedEncodingException {
		Scanner sc = new Scanner(new File("A-small-attempt0.in"));
//		Scanner sc = new Scanner(System.in);
		PrintWriter pw = new PrintWriter("A-out-small.txt", "UTF-8");
		while(sc.hasNext()) {
			int T = sc.nextInt();
			sc.nextLine();
			for(int i = 1; i <= T; i++) {
				String str = sc.nextLine();
				int[] arr = new int[26];
				int[] num = new int[10];
				for(int j = 0; j < str.length(); j++) {
					arr[str.charAt(j)-'A']++;
				}
				num[0] = arr['Z'-'A'];
				arr['Z'-'A'] -= num[0];
				arr['E'-'A'] -= num[0];
				arr['R'-'A'] -= num[0];
				arr['O'-'A'] -= num[0];
				num[2] = arr['W'-'A'];
				arr['T'-'A'] -= num[2];
				arr['W'-'A'] -= num[2];
				arr['O'-'A'] -= num[2];
				num[6] = arr['X'-'A'];
				arr['S'-'A'] -= num[6];
				arr['I'-'A'] -= num[6];
				arr['X'-'A'] -= num[6];
				num[8] = arr['G'-'A'];
				arr['E'-'A'] -= num[8];
				arr['I'-'A'] -= num[8];
				arr['G'-'A'] -= num[8];
				arr['H'-'A'] -= num[8];
				arr['T'-'A'] -= num[8];
				num[7] = arr['S'-'A'];
				arr['S'-'A'] -= num[7];
				arr['E'-'A'] -= num[7];
				arr['V'-'A'] -= num[7];
				arr['E'-'A'] -= num[7];
				arr['N'-'A'] -= num[7];
				num[3] = arr['H'-'A'];
				arr['T'-'A'] -= num[3];
				arr['H'-'A'] -= num[3];
				arr['R'-'A'] -= num[3];
				arr['E'-'A'] -= num[3];
				arr['E'-'A'] -= num[3];
				num[4] = arr['R'-'A'];
				arr['F'-'A'] -= num[4];
				arr['O'-'A'] -= num[4];
				arr['U'-'A'] -= num[4];
				arr['R'-'A'] -= num[4];
				num[5] = arr['V'-'A'];
				arr['F'-'A'] -= num[5];
				arr['I'-'A'] -= num[5];
				arr['V'-'A'] -= num[5];
				arr['E'-'A'] -= num[5];
				num[1] = arr['O'-'A'];
				arr['O'-'A'] -= num[1];
				arr['N'-'A'] -= num[1];
				arr['E'-'A'] -= num[1];
				num[9] = arr['I'-'A'];
				arr['N'-'A'] -= num[9];
				arr['I'-'A'] -= num[9];
				arr['N'-'A'] -= num[9];
				arr['E'-'A'] -= num[9];
				System.out.print("Case #" + i + ": ");
				pw.print("Case #" + i + ": ");
				for(int j = 0; j < num.length; j++) {
					for(int k = 0; k < num[j]; k++) {
						System.out.print(j);
						pw.print(j);
					}
				}
				System.out.println();
				pw.println();
			}
			pw.close();
		}
	}
}
