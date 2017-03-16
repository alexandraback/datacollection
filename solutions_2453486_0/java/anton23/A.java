import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class A {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 1; t <= T; t++) {
			sc.nextLine();
			char[][] b = new char[4][];
			boolean full = true;
			for (int i = 0; i < 4; i++) {
				String l = sc.nextLine();
				if (l.contains(".")) {
					full = false;
				}
				b[i] = l.toCharArray();
				//System.out.println(b[i]);
			}
			String res = "";
		
				Set<Character> won = new HashSet<Character>();
				for (Character c : new Character[] { 'O', 'X' }) {
					boolean allDiag1 = true, allDiag2 = true;
					for (int i = 0; i < 4; i++) {
						// Check rows and columns
						boolean allRow = true, allCol = true;
						for (int j = 0; j < 4; j++) {
							if (b[i][j] != c && b[i][j] != 'T') {
								allRow = false;
							}
							if (b[j][i] != c && b[j][i] != 'T') {
								allCol = false;
							}
						}
						if (b[i][i] != c && b[i][i] != 'T') {
							allDiag1 = false;
						}
						if (b[i][3 - i] != c && b[i][3 - i] != 'T') {
							allDiag2 = false;
						}
						if (allRow || allCol) {
							won.add(c);
							break;
						}
					}
					if (allDiag1 || allDiag2) {
						won.add(c); break;
					}
				}
				
				if (won.size() == 0 && !full) {
					res = "Game has not completed";
				}
				
				if (won.size() == 0 && full) {
					res = "Draw";
				}
				
				if (won.size() == 1) {
					res = won.iterator().next() + " won";
				} 


			System.out.println("Case #" + t + ": " + res);
		}
	}
}
