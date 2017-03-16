import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;

public class A {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String line;
		String filename1 = "A-large.in";
		String filename2 = filename1.split("[.]")[0] + ".out";
		BufferedReader input;
		BufferedWriter output;
		int counter = 0;
		int numberOfCases = 0;
		int caseNr = 0;
		int tempCounter = 0;
		int numberOfNodes = 0;
		node root;
		ArrayList<node> array = new ArrayList<node>();
		boolean skaitykTempCounter = false;
		StringBuilder sb = new StringBuilder();
		try {
			input = new BufferedReader(new FileReader(filename1));
			output = new BufferedWriter(new FileWriter(filename2));
			while ((line = input.readLine()) != null) {
				if (counter == 0) {
					numberOfCases = Integer.parseInt(line);
					skaitykTempCounter = true;
				} else {
					if (skaitykTempCounter) {
						tempCounter = Integer.parseInt(line);
						numberOfNodes = Integer.parseInt(line);
						skaitykTempCounter = false;
						if (counter != 1) {
							caseNr++;
							output.write("Case #" + caseNr + ": ");
							output.write(skaiciuok(array));
							//							System.out.println(array);
							array = new ArrayList<node>();
							output.write("\n");
						}
					} else {
						if (numberOfNodes == tempCounter) {
							root = new node(line, numberOfNodes - tempCounter);
							array.add(root);
						} else {
							array.add(new node(line, numberOfNodes - tempCounter));
						}
						tempCounter--;
						if (tempCounter == 0) {
							skaitykTempCounter = true;
						}
					}
				}
				counter++;
			}
			//			System.out.println(array);
			caseNr++;
			output.write("Case #" + caseNr + ": ");
			output.write(skaiciuok(array));
			for (int i = 0; i < array.size(); i++) {
//				System.out.println(array.get(i).pasiekiu);
			}
			//			System.out.println(array);
			array = new ArrayList<node>();
			input.close();
			output.close();
		} catch (IOException e1) {
			System.exit(1);
		}
		//		System.out.println(array);
	}

	public static String skaiciuok(ArrayList<node> array) {
		for (int i = 0; i < array.size(); i++) {
			nunulink(array);
			if (gilyn(array, array.get(i)).equals("Yes")) {
				return "Yes";
			}
		}
		return "No";
	}
	public static void nunulink(ArrayList<node> array){
		for(int i=0;i<array.size();i++){
			array.get(i).pasiekiu=false;
		}
			
	}
	public static String gilyn(ArrayList<node> array, node tempNode) {
		//			System.out.println("array size:" + array.size());
		if (tempNode.pasiekiu) {
//			System.out.println("YES");
			return "Yes";
		}
//		System.out.println("reiksme:" + tempNode.reiksme + " vaikaiL:" + tempNode.vaikai.length
//				+ " pasiekiu:" + tempNode.pasiekiu);
		tempNode.pasiekiu = true;
		for (int j = 0; j < tempNode.vaikai.length; j++) {
//			System.out.println("sekantis :" + (tempNode.vaikai[j] - 1));
			node temptempNode = array.get(tempNode.vaikai[j] - 1);
			if (temptempNode.pasiekiu) {
//				System.out.println("YES");
				return "Yes";
			}
			if (gilyn(array, temptempNode).equals("Yes")) {
				return "Yes";
			}
		}
//		System.out.println("NO");
		return "No";
	}

	public static class node {

		int reiksme;
		int[] vaikai;
		boolean pasiekiu = false;

		public node(String line, int reiksmius) {
			String[] temp = line.split("[ ]");
			this.reiksme = reiksmius;
			vaikai = new int[temp.length - 1];
			for (int i = 1; i < temp.length; i++) {
				vaikai[i - 1] = Integer.parseInt(temp[i]);
			}
		}
	}
}
