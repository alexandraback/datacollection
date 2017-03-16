import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collection;
import java.util.Collections;
import java.util.Map;
import java.util.Scanner;
import java.util.TreeMap;


public class Tongues {
	private File file = new File("D:\\Sources\\GoogleCodeJam\\files\\A-small-attempt0.in");
	private File mappingFile = new File("D:\\Sources\\GoogleCodeJam\\files\\mapping.out");
	private File outFile = new File("D:\\Sources\\GoogleCodeJam\\files\\result.out");
	
	private File testMap = new File("D:\\Sources\\GoogleCodeJam\\files\\testMap.in");
	
	private TreeMap<String, String> mapping = new TreeMap<String, String>();
	private String[] results;
	
	private Integer solved = 0;
	
	public void readData() {
		readMapping();
		Scanner scanner;
		boolean first = true;
		try {
			scanner = new Scanner(file);
			while (scanner.hasNextLine()) {
				String line = scanner.nextLine();
				Scanner scan = new Scanner(line);
				if(first) {
					results = new String[scan.nextInt()];
					first = false;
				} else {
					results[solved] = solveProblem(scan.nextLine());
					solved++;
				}
			}
			printResult();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}
	
	private String solveProblem(String line) {
		StringBuilder strBuilder = new StringBuilder();
		for (int i = 0; i < line.length(); i++) {
			String ch = line.substring(i, i+1);
			if(ch.equals(" "))
				strBuilder.append(" ");
			else
				strBuilder.append(mapping.get(ch));
		}
		return strBuilder.toString();
	}
	
	private void printResult() {
		try {
			FileWriter fstream = new FileWriter(outFile);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i = 0; i < results.length; i++) {
				out.write("Case #" + (i + 1) + ": " + results[i]);
				out.newLine();
			}
			out.close();
		} catch (Exception e) {
			e.printStackTrace();
		}
	}

	public void readMapping() {
		Scanner scanner;
		try {
			scanner = new Scanner(mappingFile);
			while (scanner.hasNext()) {
				String key = scanner.next();
				String value= scanner.next();
				mapping.put(key, value);
			}
		}catch (Exception e) {
			e.printStackTrace();
		}
	}
	
//	public void readData() {
//		Scanner scanner;
//		try {
//			scanner = new Scanner(testMap);
//			while (scanner.hasNextLine()) {
//				String google = scanner.nextLine();
//				String trans = scanner.nextLine();
//				solveProblem(google, trans);
//			}
//			Collection<String> vals = new ArrayList<>(mapping.values());
//			vals.removeAll(mapping.keySet());
//			Collection<String> keys = new ArrayList<>(mapping.keySet());
//			keys.removeAll(mapping.values());
//			mapping.put((String)vals.toArray()[0], (String)keys.toArray()[0]);
//			printResult();
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
//	}
//
//	private void solveProblem(String google, String trans) {
//		for (int i = 0; i < google.length(); i++) {
//			String key = trans.substring(i, i+1);
//			String value = google.substring(i, i+1);
//			if(!key.equals(" "))
//				mapping.put(value, key);
//		}
//	}
//
//	private void printResult() {
//		try {
//			FileWriter fstream = new FileWriter(mappingFile);
//			BufferedWriter out = new BufferedWriter(fstream);
//			for (Map.Entry<String, String> el : mapping.entrySet()) {
//				out.write(el.getKey() + " " + el.getValue());
//				out.newLine();
//			}
//			out.close();
//		} catch (Exception e) {
//			e.printStackTrace();
//		}
//	}
}
