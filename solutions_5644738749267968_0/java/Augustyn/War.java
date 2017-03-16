import java.util.Arrays;
import java.util.Scanner;

public class War {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		int T = scanner.nextInt();
		scanner.nextLine();
		int a;
		for (int t = 0; t < T; t++) {
			a = scanner.nextInt();

			double []d1 = new double[a];
			double []d2 = new double[a];
			scanner.nextLine();
			readArray(scanner, d1);
			readArray(scanner, d2);

			Arrays.sort(d1);
			Arrays.sort(d2);


			int x=0;
			int y=0;
			
			int i=0;
			int j=0;
			while(i<d1.length&&j<d2.length){
				if(d1[i]<=d2[j]){
					i++;
				} else {
					x++;
					i++;
					j++;
				}
			}
			
			i=d1.length-1;
			j=d2.length-1;
			while(i>-1&&j>-1){
				if(d1[i]>d2[j]){
					y++;
					i--;
				} else {
					i--;
					j--;
				}
			}
			
			
			System.out.println("Case #" + (t + 1) + ": "+x+" "+y);


		}

	}



	private static void readArray(Scanner scanner, double []t1) {
			String s = scanner.nextLine();
			String[] tab = s.split(" ");
			// System.out.println(s);
			for (int j = 0; j < tab.length; j++)
				t1[j] = Double.parseDouble(tab[j]);

	}
}
