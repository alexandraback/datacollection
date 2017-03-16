import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.Scanner;

public class A {

	public static void main(String[] args) {


		try {
			Scanner in = new Scanner(new File("A.in"));
			BufferedWriter out = new BufferedWriter(new FileWriter("A.out"));

			int T = in.nextInt();
			
			for (int nCase = 1; nCase <= T; nCase++) {
				String[] game = new String[4];
				boolean completed = true;
				in.nextLine();
				for (int i = 0; i < 4; i++) {
					game[i] = in.nextLine();
					for (int j = 0; j < 4; j++)
						if (game[i].charAt(j) == '.')
							completed = false;
				}
				
				// ----
				boolean win = false;
				char first = ' ';
				for (int i = 0; i < 4; i++) {
					int j = 0;
					while (j < 4 && game[i].charAt(j) == 'T')
						j++;
					if (j == 4)
						continue;
					first = game[i].charAt(j);
					if (first == '.')
						continue;
					win = true;
					while (win && j < 4) {
						if (game[i].charAt(j) != 'T'
								&& game[i].charAt(j) != first) {
							win = false;
						}
						j++;
					}
					if (win)
						break;
				}
				// ||||
				if (!win) {

					for (int i = 0; i < 4; i++) {
						int j = 0;
						while (j < 4 && game[j].charAt(i) == 'T')
							j++;
						if (j == 4)
							continue;
						first = game[j].charAt(i);
						if (first == '.')
							continue;
						win = true;
						while (win && j < 4) {
							if (game[j].charAt(i) != 'T'
									&& game[j].charAt(i) != first) {
								win = false;
							}
							j++;
						}
						if (win)
							break;
					}
				}
				// \
				if (!win) {

					int j = 0;
					while (j < 4 && game[j].charAt(j) == 'T')
						j++;

					if (j != 4) {

						first = game[j].charAt(j);
						if (first != '.') {
							win = true;
							while (win && j < 4) {
								if (game[j].charAt(j) != 'T'
										&& game[j].charAt(j) != first) {
									win = false;
								}
								j++;
							}
						}
					}

				}
				////
				if (!win) {
					
					int j = 0;
					while (j <4 && game[j].charAt(3-j) == 'T')
						j++;

					if (j != 4) {

						first = game[j].charAt(3-j);
						if (first != '.') {
							win = true;
							while (win && j <4) {
								if (game[j].charAt(3-j) != 'T'
										&& game[j].charAt(3-j) != first) {
									win = false;
								}
								j++;
							}
						}
					}
					
				}
				
				if (!win){
					if (completed)
						out.write("Case #"+nCase+": Draw");
					else
						out.write("Case #"+nCase+": Game has not completed");
				}
				else {
					if (first == 'X')
						out.write("Case #"+nCase+": X won");
					else
						out.write("Case #"+nCase+": O won");
				}
				out.newLine();

			}

			in.close();
			out.close();
		} catch (Exception e) {
			System.out.println(e.toString());
		}

	}

}
