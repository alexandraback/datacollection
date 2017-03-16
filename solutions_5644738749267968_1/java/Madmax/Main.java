import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;

import javax.swing.JFileChooser;
import javax.swing.filechooser.FileFilter;
import javax.swing.filechooser.FileNameExtensionFilter;

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

			Case c = listCase.get(i);

			int deceitful = 0;
			int war = c.nb;

			Collections.sort(c.naomiWar);
			Collections.sort(c.kenWar);

			for (int j = 0; j < c.naomiWar.size(); j++) {
				if (c.naomiDeceitful.get(0) <= c.kenDeceitful.get(0)) {
					c.naomiDeceitful.remove(0);
					c.kenDeceitful.remove(c.kenDeceitful.size() - 1);
				} else {
					c.naomiDeceitful.remove(0);
					c.kenDeceitful.remove(0);
					deceitful ++;
				}	
			}

			for (Double d : c.naomiWar) {
				for (int j = 0; j < c.kenWar.size(); j++) {
					if (d < c.kenWar.get(j)) {
						war--;
						for (int k = 0; k <= j; k++) {
							c.kenWar.remove(0);
						}
						break;
					}
				}
				if (c.kenWar.size() == 0)
					break;
			}

			output += "Case #" + (i + 1) + ": " + deceitful + " " + war;
			if (i != nbCase - 1)
				output += "\n";
		}
	}

	private static String getFilePath() {
		JFileChooser fc = new JFileChooser(
				"C:\\Users\\Maxime\\Desktop\\Codejam");
		FileFilter filter = new FileNameExtensionFilter("Input", "in");
		fc.setFileFilter(filter);
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

				s = br.readLine();
				c.nb = Integer.parseInt(s);

				row = br.readLine().split(" ");
				for (int j = 0; j < c.nb; j++) {
					c.naomiWar.add(Double.parseDouble(row[j]));
				}
				Collections.sort(c.naomiWar);
				c.naomiDeceitful = new ArrayList<>(c.naomiWar);

				row = br.readLine().split(" ");
				for (int j = 0; j < c.nb; j++) {
					c.kenWar.add(Double.parseDouble(row[j]));
				}
				Collections.sort(c.kenWar);
				c.kenDeceitful = new ArrayList<>(c.kenWar);

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
	int nb;
	ArrayList<Double> naomiWar, kenWar, naomiDeceitful, kenDeceitful;

	Case() {
		naomiWar = new ArrayList<Double>();
		kenWar = new ArrayList<Double>();
	}
}
