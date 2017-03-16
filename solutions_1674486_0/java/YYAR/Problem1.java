import java.util.Scanner;

public class Problem1 {
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		int lines = scan.nextInt();

		for (int l = 0; l < lines; l++) {
			String output = null;
			int numClass = scan.nextInt();

			int classes[][] = new int[numClass][numClass];
			for (int i = 0; i < numClass; i++) {
				int inheriteNum = scan.nextInt();

				for (int j = 0; j < inheriteNum; j++) {
					classes[i][scan.nextInt() - 1] = 1;
				}
			}

			int product[][] = new int[numClass][numClass];
			int sumProduct[][] = new int[numClass][numClass];
			for (int i = 0; i < numClass; i++) {
				for (int j = 0; j < numClass; j++) {
					product[i][j] = classes[i][j];
					sumProduct[i][j] = classes[i][j];
				}
			}

			boolean isDia = false;
			
			
			for (int n = 0; n < numClass - 1 && !isDia; n++) {
				int newProduct[][] = new int[numClass][numClass];
				for (int i = 0; i < numClass && !isDia; i++) {
					for (int j = 0; j < numClass && !isDia; j++) {
						// product[i][j] = 0;
						int sum = 0;
						for (int k = 0; k < numClass; k++) {
							sum += (product[i][k] * classes[k][j]);
						}
						newProduct[i][j] = sum;
						sumProduct[i][j] += sum;
						if(sum >= 2) {
							isDia = true;
							break;
						}
					}
				}
				product = newProduct;
			}
			
			for(int i = 0 ; i < numClass && !isDia ; i++) {
				for(int j = 0 ; j < numClass && !isDia ; j++) {
					if(i != j && sumProduct[i][j] >= 2) {
						isDia = true;
						break;
					}
				}
			}
			
			if(isDia) output = "Yes";
			else {
				output = "No";
			}
			
			System.out.println("Case #" + (l + 1) + ": " + output);
		}
	}
}
