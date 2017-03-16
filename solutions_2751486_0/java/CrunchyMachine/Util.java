package abc.template;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Util {
	
	public static List<String> readFile(String fileName) throws IOException {
		try (BufferedReader reader = new BufferedReader(new FileReader(fileName));) {
			List<String> lines = new ArrayList<>();
			String line = reader.readLine();
			while (line != null) {
				lines.add(line);
				line = reader.readLine();
			}
			return lines;
		}
	}
	
	public static void writeToFile(String fileName, List<String> lines) throws IOException {
		try (BufferedWriter writer = new BufferedWriter(new FileWriter(fileName));) {
			for(String line : lines) {
				writer.write(line);
				writer.newLine();
			}
		}
	}
	
	public static void writeToStdout(List<String> lines) throws IOException {
		for(String line : lines) {
			System.out.println(line);
		}
	}
	
	public static void assertTrue(boolean mustBeTrue) {
		if (mustBeTrue == false)
			throw new RuntimeException("Something broke");
	}
}
