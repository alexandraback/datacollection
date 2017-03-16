import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.text.DecimalFormat;
import java.util.ArrayList;

import javax.swing.JFileChooser;

public class Main {

	private static int nbCase;
	private static ArrayList<Case> listCase;
	private static String output = "";

	public static void main(String[] args) {
		String filePath = getFilePath();
		listCase = new ArrayList<Case>();
		getInput(filePath);
		test();
		setOutput(filePath, output);
		System.out.println("FIN");
	}

	private static void test() {
		for (int i = 0; i < nbCase; i++) {

			double cookies = 2;
			double time = 0;

			Case c = listCase.get(i);

			output += "Case #" + (i + 1) + ":\n";

			// 1 * 1
			if (c.R == 1 && c.C == 1 && c.M == 0) {
				output += "c";
				if (i != nbCase - 1)
					output += "\n";
				// 1 libre
			} else if (c.R * c.C - c.M == 1) {
				for (int j = 0; j < c.R; j++) {
					for (int k = 0; k < c.C; k++) {
						if (j == 0 && k == 0) {
							output += "c";
						} else {
							output += "*";
						}
					}
					if (j != c.R - 1 || i != nbCase - 1)
						output += "\n";
				}
				// 1 hori + mines
			} else if (c.R == 1 && c.C - c.M >= 2) {
				output += "c";
				for (int j = 1; j < c.C - c.M; j++) {
					output += ".";
				}
				for (int j = 0; j < c.M; j++) {
					output += "*";
				}
				if (i != nbCase - 1)
					output += "\n";
				// 1 vert + mines
			} else if (c.C == 1 && c.R - c.M >= 2) {
				output += "c\n";
				for (int j = 1; j < c.R - c.M; j++) {
					output += ".";
					if (j != (c.R - c.M - 1) || i != nbCase - 1)
						output += "\n";
				}
				for (int j = 0; j < c.M; j++) {
					output += "*";
					if (j != (c.M - 1) || i != nbCase - 1)
						output += "\n";
				}
				// pair et sup 4 ou sup 9
			} else if (((c.R * c.C - c.M) % 2 == 0 && c.R * c.C - c.M >= 4)
					|| (c.R * c.C - c.M >= 9 && c.C != 2 && c.R != 2)) {
				int cpt = c.R * c.C - c.M - 4;
				for (int j = 0; j < c.R; j++) {
					for (int k = 0; k < c.C; k++) {
						if (j == 0 && k == 0) {
							output += "c";
						} else if ((j == 0 && k == 1) || (j == 1 && k == 0)
								|| (j == 1 && k == 1)) {
							output += ".";
						} else if ((j == 0 || j == 1)
								&& cpt > 0
								&& ((c.R * c.C - c.M) % 2 != 0
										&& k < (c.R * c.C - c.M - 2) / 2 || (c.R
										* c.C - c.M) % 2 == 0)
								&& k < (c.R * c.C - c.M) / 2) {
							output += ".";
							cpt--;
						} else if (j > 1 && cpt > 0 && (cpt !=2 || k != c.C -1 )) {
							output += ".";
							cpt--;
						} else {
							output += "*";
						}
					}
					if (j != c.R - 1 || i != nbCase - 1)
						output += "\n";
				}
				// impossible
			} else {
				output += "Impossible";
				if (i != nbCase - 1)
					output += "\n";
			}
		}
	}

	private static String getFilePath() {
		JFileChooser fc = new JFileChooser(
				"C:\\Users\\Maxime\\Desktop\\Codejam");
		if (fc.showOpenDialog(null) != JFileChooser.APPROVE_OPTION)
			return null;
		return fc.getSelectedFile().getPath();
	}

	private static void getInput(String path) {
		try {
			FileInputStream fis = new FileInputStream(path);
			BufferedReader br = new BufferedReader(new InputStreamReader(fis));
			String s = br.readLine();
			nbCase = Integer.parseInt(s);
			for (int i = 0; i < nbCase; i++) {
				String[] row;
				Case c = new Case();

				row = br.readLine().split(" ");
				c.R = Integer.parseInt(row[0]);
				c.C = Integer.parseInt(row[1]);
				c.M = Integer.parseInt(row[2]);

				listCase.add(c);
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void setOutput(String path, String output) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter(path.replaceFirst(
					"\\.in", ".out")));
			out.print(output);
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}

class Case {
	int R, C, M;
}
