import java.io.BufferedInputStream;
import java.util.Scanner;


public class MinesweeperMaster {
	public static void main(String[] args) {
		
		//read in input
		Scanner scanner = new Scanner(new BufferedInputStream(System.in));
		int n = scanner.nextInt();
		
		for (int i = 0; i < n; i++) {
			boolean impossible = false;
			int row = scanner.nextInt();
			int col = scanner.nextInt();
			int mines = scanner.nextInt();
			System.out.println("Case #" + (i+1) + ":");

			// if mines = row*col - 1 
			if (mines == row * col - 1) {
				for (int j = 0; j < row; j++) {
					for (int k = 0; k < col; k++) {
						if (j == 0 && k == 0) {
							System.out.print('c');
						}
						else System.out.print('*');
					}
					System.out.println();
				}
			}
			
			// if row or col = 1 then as long as mines < row * col - 2
			else if (row == 1 || col == 1) {
				if (mines <= row * col - 2) {
					int unaccounted = row * col - mines - 1;
					for (int j = 0; j < row; j++) {
						for (int k = 0; k < col; k++) {
							if (j == 0 && k == 0) {
								System.out.print('c');
							}
							else if (unaccounted > 0) {
								System.out.print('.');
								unaccounted--;
							}
							else {
								System.out.print('*');
							}
						}
						System.out.println();
					}
				}
				else {
					impossible = true;
				}
			}
			else if (row == 2 || col == 2) {
				if ((row * col - mines)%2 != 0 || mines > row*col - 4) {
					impossible = true;
				}
				else {
					int unaccounted = row * col - mines - 1;
					if ( row == 2) {
						unaccounted = row * col - mines;
					}
					for (int j = 0; j < row; j++) {
						for (int k = 0; k < col; k++) {
							if (j == 0 && k == 0) {
								System.out.print('c');
							}
							else if (col == 2 && unaccounted > 0) {
								System.out.print('.');
								unaccounted--;
							}
							else if (row == 2 && k < unaccounted/2 && j < 2) {
								System.out.print('.');
							}
							else {
								System.out.print('*');
							}
						}
						System.out.println();
					}
				}
			}
			
			// otherwise then as long as mines < row * col - 4
			else if (mines <= row * col - 4) {
				int[] opensquares = new int[row];
				int left = row * col - mines;
				int cur = 2;
				if (left >= col * 2) {
					opensquares[0] = col;
					opensquares[1] = col;
					left -= 2 * col;
				}
				else {
					opensquares[0] = left/2;
					opensquares[1] = left/2;
					left -= opensquares[0] * 2;
				}
				
				while (left > 0) {
					opensquares[cur] = Math.min(left, opensquares[cur-1]);
					left -= opensquares[cur];
					cur++;
				}
				if (opensquares[cur - 1] == 1) {
					if (opensquares[cur - 2] > 1 && cur > 3) {
						opensquares[cur - 1]++;
						opensquares[cur - 2]--;
					}
					else if (cur == 3 && opensquares[0] >= 4) {
						opensquares[0]--;
						opensquares[1]--;
						opensquares[2] += 2;
					}
					else {
						impossible = true;
					}
				}
				if (!impossible) {
					for (int j = 0; j < row; j++) {
						for (int k = 0; k < col; k++) {
							if (j == 0 && k == 0) {
								System.out.print('c');
								opensquares[0]--;
							}
							else if (opensquares[j] > 0) {
								System.out.print('.');
								opensquares[j]--;
							}
							else {
								System.out.print('*');
							}
						}
						System.out.println();
					}
				}
			}
			else {
				impossible = true;
			}
			if (impossible) {
				System.out.println("Impossible");
			}
		}
	}
}
