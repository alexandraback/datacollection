package be.filip.coinjam;

import java.nio.charset.Charset;
import java.nio.file.Files;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.util.List;

public class Main {

	public static void main(String[] args) throws Exception {

		// JamCoinGenerator.generateJamCoins(15,3);

		executeTest(16, 50, "/Users/filip/Desktop/GCM_2016/Primes/small.out");
		executeTest(32, 500, "/Users/filip/Desktop/GCM_2016/Primes/large.out");
	}

	public static void executeTest(int length, int numberOf, String fileName) throws Exception {

		List<String> lines = JamCoinGenerator.generateJamCoins(length, numberOf);
		if (lines.size() != numberOf) {
			System.out.println("Number of lines not correct");
		}

		lines.add(0, "Case #1:");

		Path outputPath = Paths.get(fileName);
		Files.write(outputPath, lines, Charset.forName("UTF-8"));

	}

}
