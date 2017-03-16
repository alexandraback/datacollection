package qual.d;

import java.io.BufferedWriter;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.Collections;
import java.util.LinkedList;
import java.util.Locale;
import java.util.Scanner;

public class D_large {
	private void solve(long case_T, Scanner reader, BufferedWriter writer) throws Exception {
		int blocks = reader.nextInt();
		LinkedList<Integer> naomi = new LinkedList<Integer>();
		for (int i=0;i<blocks;i++) {
			naomi.add((int)(reader.nextDouble()*1000000));
		}
		Collections.sort(naomi);
		LinkedList<Integer> naomiCopy = new LinkedList<Integer>(naomi);

		LinkedList<Integer> ken = new LinkedList<Integer>();
		for (int i=0;i<blocks;i++) {
			ken.add((int)(reader.nextDouble()*1000000));
		}
		Collections.sort(ken);
		LinkedList<Integer> kenCopy = new LinkedList<Integer>(ken);

		int warWins = 0;
		while (naomi.size()>0) {
			int n = naomi.removeFirst();
			int k = getKens(ken, n);
			if (n>k) {
				warWins++;
			}
		}

		naomi = new LinkedList<Integer>(naomiCopy);
		ken = new LinkedList<Integer>(kenCopy);
		int deceitfulWins = 0;
		while (naomi.size()>0) {
			int n = naomi.removeFirst();
			if (n>ken.getFirst()) {
				n = ken.getLast()+1;
			}
			else {
				n = ken.getLast()-1;
			}
			int k = getKens(ken, n);
			if (n>k) {
				deceitfulWins++;
			}
		}



		writeOutput(writer, case_T, deceitfulWins, warWins);
	}

	private int getKens(LinkedList<Integer> ken, int n) {
		Integer k = null;
		for (int i=0;i<ken.size();i++) {
			if (ken.get(i)>n) {
				k= ken.remove(i);
				break;
			}
		}
		if (null == k) {
			k = ken.removeFirst();
		}
		return k;
	}

	private void writeOutput(BufferedWriter writer, long case_T, int deceitful, int war) throws Exception {
		String result = String.format("Case #%d: %d %d",  case_T, deceitful, war);
		System.out.println(result);
		writer.write(result+"\n");
	}

	private void run() throws Exception {
		Locale.setDefault(Locale.US);

		String filename = "src/qual/d/D-large";
		Path inputFile = Paths.get(filename+".in");
		Path outputFile = Paths.get(filename+".out");

		System.out.println("Input file:  "+inputFile.toFile().getAbsolutePath());
		System.out.println("Output file: "+outputFile.toFile().getAbsolutePath());

		try (
				Scanner reader = new Scanner(Files.newBufferedReader(inputFile));
				BufferedWriter writer = Files.newBufferedWriter(outputFile)) {
			long cases_T = new Long(reader.nextLine());

			for (long case_T = 1; case_T<=cases_T; case_T++) {
				solve(case_T, reader, writer);
			}
		}
	}

	public static void main(String... args) throws Exception {
		new D_large().run();
	}
}
