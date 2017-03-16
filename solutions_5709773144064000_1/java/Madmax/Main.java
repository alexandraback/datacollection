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
			while (c.X / cookies > c.C / cookies + c.X / (cookies + c.F)) {
				time += c.C / cookies;
				cookies += c.F;
			}
			time += c.X / cookies;
						
			output += "Case #" + (i + 1) + ": " + time;
			System.out.println(c.C + " " + c.F + " " + c.X + " ");
			if (i != nbCase - 1) {
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
				c.C = Double.parseDouble(row[0]);
				c.F = Double.parseDouble(row[1]);
				c.X = Double.parseDouble(row[2]);
				
				listCase.add(c);
			}
			br.close();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private static void setOutput(String path, String output) {
		try {
			PrintWriter out = new PrintWriter(new FileWriter(path.replaceFirst("\\.in", ".out")));
			out.print(output);
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

}

class Case {
	double C, F, X;
}
