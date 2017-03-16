package com.dten.cj;

import java.io.File;
import java.util.Scanner;

import org.apache.commons.io.FileUtils;

public abstract class Problem {

	public String solveProblem(String line) {
		return solveProblem(new Scanner(line));
	}

	public abstract String solveProblem(Scanner scanner);

	public boolean processFile(String path) {
		int n = 1;
		path = path.replace("inputs\\", "");
		path = path.replace("outputs\\", "");
		File outFile = new File("outputs/" + path.replace(".in", ".out"));

		String sf0 = "Case #%1$s: %2$s";
		String sf1 = "\r\n" + sf0;

		try (Scanner scanner = new Scanner(new File("inputs/" + path))) {

			FileUtils.write(outFile, "", false);
			scanner.nextLine();
			if (!scanner.hasNext()) return false;

			FileUtils.write(outFile, String.format(sf0, n++, solveProblem(scanner)), true);
			while (scanner.hasNext())
				FileUtils.write(outFile, String.format(sf1, n++, solveProblem(scanner)), true);

		} catch (Exception e) {
			e.printStackTrace();
			return false;
		}
		return true;
	}
}
