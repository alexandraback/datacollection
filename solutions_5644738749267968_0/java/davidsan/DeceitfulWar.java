package codejam;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

import com.google.gson.Gson;

public class DeceitfulWar {

	int nbTest;
	List<List<Double>> naomi;
	List<List<Double>> ken;

	StringBuilder result;

	public DeceitfulWar(String filename) {
		super();
		naomi = new ArrayList<List<Double>>();
		ken = new ArrayList<List<Double>>();
		try {
			readFile(filename);
		} catch (IOException e) {
			e.printStackTrace();
		}

		result = new StringBuilder();
		computeResult();
	}

	public void readFile(String filename) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(filename));
		String line = br.readLine();
		nbTest = Integer.parseInt(line);
		try {
			for (int cpt = 0; cpt < nbTest; cpt++) {
				line = br.readLine(); // nrof weight
				int nbElem = Integer.parseInt(line);
				naomi.add(new ArrayList<Double>());

				line = br.readLine();
				String[] weightStr = line.split(" ");
				if (weightStr.length == 0) {
					weightStr = new String[1];
					weightStr[0] = line;
				}
				for (int j = 0; j < weightStr.length; j++) {
					naomi.get(cpt).add(Double.parseDouble(weightStr[j]));
				}

				ken.add(new ArrayList<Double>());

				line = br.readLine();
				weightStr = line.split(" ");
				if (weightStr.length == 0) {
					weightStr = new String[1];
					weightStr[0] = line;
				}
				for (int j = 0; j < weightStr.length; j++) {
					ken.get(cpt).add(Double.parseDouble(weightStr[j]));
				}
			}
		} finally {
			br.close();
		}

	}

	public void computeResult() {
		for (int i = 0; i < nbTest; i++) {

			int war = 0;
			int dwar = 0;
			List<Double> nw = new ArrayList<Double>(naomi.get(i));
			Collections.sort(nw);
			List<Double> kw = new ArrayList<Double>(ken.get(i));
			Collections.sort(kw);
			int nbElem = nw.size();
			for (int j = 0; j < nbElem; j++) {
				Double chosenN = nw.remove(0);
				Double chosenK = null;
				int k;
				for (k = 0; k < kw.size(); k++) {
					if (kw.get(k) > chosenN) {
						chosenK = kw.remove(k);
						break;
					}
				}
				if (chosenK == null) {
					chosenK = kw.remove(0);
				}
				if (chosenK < chosenN) {
					war++;
				}
			}
			nw = new ArrayList<Double>(naomi.get(i));
			Collections.sort(nw);
			Collections.reverse(nw);
			kw = new ArrayList<Double>(ken.get(i));
			Collections.sort(kw);
			Collections.reverse(kw);

			for (int j = 0; j < nbElem; j++) {
				Double chosenN = nw.remove(0);
				Double chosenK = null;
				int k;
				for (k = 0; k < kw.size(); k++) {
					if (kw.get(k) < chosenN) {
						chosenK = kw.remove(k);
						dwar++;
						break;
					}

				}

				if (chosenK == null) { // plus de possibilité
					chosenK = kw.remove(0);
					break;
				}

			}
			result.append("Case #");
			result.append(i + 1);
			result.append(": ");
			result.append(dwar);
			result.append(" ");
			result.append(war);
			result.append(System.lineSeparator());
		}
	}

	public static void main(String[] args) {
		DeceitfulWar mt = new DeceitfulWar(args[0]);
		Gson g = new Gson();
		// System.err.println(g.toJson(mt.nbTest));
		// System.err.println(g.toJson(mt.naomi));
		// System.err.println(g.toJson(mt.ken));
		// System.out.println(mt.result.toString());
		PrintWriter writer;
		try {
			writer = new PrintWriter(args[0].substring(0,
					args[0].lastIndexOf('.'))
					+ ".out", "UTF-8");
			writer.println(mt.result.toString());
			writer.close();
		} catch (FileNotFoundException | UnsupportedEncodingException e) {
			e.printStackTrace();
		}
	}
}
