import java.util.Arrays;
import java.util.Scanner;


public class DeceitfulWar {

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int testNum = scan.nextInt();
		float[] naomi, ken;
		for (int test = 1; test <= testNum; test++) {
			scan.nextLine();
			int size = scan.nextInt();
			scan.nextLine();
			naomi = new float[size];
			ken = new float[size];
			for (int i = 0; i < size; i++) {
				naomi[i] = scan.nextFloat();
			}
			scan.nextLine();
			for (int i = 0; i < size; i++) {
				ken[i] = scan.nextFloat();
			}
			Arrays.sort(naomi);
			Arrays.sort(ken);
			int n1 = 0, n2 = 0, k = 0, nindex = 0, kindex = size - 1;
			for (int i = 0; i < size; i++) {
				while (ken[i] > naomi[nindex]) {
					nindex++;
					if (nindex == size) {
						break;
					}
				}
				if (nindex == size) {
					break;
				}
				n1++;
				nindex++;
				if (nindex == size) {
					break;
				}
			}
			for (int i = size - 1; i >= 0; i--) {
				if (naomi[i] < ken[kindex]) {
					kindex--;
					k++;
					if (kindex < 0) {
						break;
					}
				}
			}
			n2 = size - k;
			System.out.format("Case #%d: %d %d%n", test, n1, n2);
		}
		scan.close();
	}

}
