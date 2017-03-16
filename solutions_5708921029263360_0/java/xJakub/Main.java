import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Locale;
import java.util.Scanner;

public class Main {

	static FileReader fr;
	static Scanner sc;
	static FileWriter fw;

	public static void openFiles(String inFile, String outFile) throws IOException {	
		fr = new FileReader(inFile);
		fw = new FileWriter(outFile);
		sc = new Scanner(fr);
		sc.useLocale(Locale.US);
	}
	public static void closeFiles() throws IOException {
		sc.close();
		fw.close();
		fr.close();
	}
	public static void writeLine(String line) throws IOException {
		write(line + "\n");
	}
	public static void write(String str) throws IOException {
		System.out.print(str);
		fw.write(str);
	}


	public static void main(String[] args) throws Exception {
		openFiles("C-small-attempt0.in", "output.txt");

		int t = sc.nextInt();
		sc.nextLine();

		// launch processCase(i) for every test case
		for (int i=1; i<=t; i++) {
			write("Case #"+i+": ");
			processCase(i);
			write("");
		}

		closeFiles();
	}

	private static HashMap<Integer, Integer> outfits;
	private static HashMap<Integer, Integer> twoCombs;
	
	public static void processCase(int caseNumber) throws Exception { 
		int j = sc.nextInt();
		int p = sc.nextInt();
		int s = sc.nextInt();
		int k = sc.nextInt();
		
		outfits = new HashMap<>();
		twoCombs = new HashMap<>();
		
		String result = "";
		
		for (int jacket=1; jacket<=j; jacket++) {
			for (int pants=1; pants<=p; pants++) {
				for (int shirt=1; shirt<=s; shirt++) {
					if (isValid(jacket, pants, shirt, k)) {
						result += jacket + " " + pants + " " + shirt + "\n";
						
					}
				}
			}
		}
		
		write(outfits.size() + "\n" + result);
	}
	
	private static boolean isValid(int jacket, int pants, int shirt, int k) {
		
		int outfitHash = (jacket*11 + pants) * 11 + shirt;
		int twoHash1 = (0*11 + pants) * 11 + shirt;
		int twoHash2 = (jacket*11 + 0) * 11 + shirt;
		int twoHash3 = (jacket*11 + pants) * 11 + 0;
		
		if (outfits.containsKey(outfitHash)) {
			return false;
		}
		
		if (!twoCombIsValid(twoHash1, k) || !twoCombIsValid(twoHash2, k)
				|| !twoCombIsValid(twoHash3, k)) {
			return false;
		}
		
		outfits.put(outfitHash, 1);
		twoCombs.put(twoHash1, twoCombs.get(twoHash1)+1);
		twoCombs.put(twoHash2, twoCombs.get(twoHash2)+1);
		twoCombs.put(twoHash3, twoCombs.get(twoHash3)+1);
		
		
		return true;
	}
	
	public static boolean twoCombIsValid(int twoHash, int k) {
		if (!twoCombs.containsKey(twoHash)) {
			twoCombs.put(twoHash, 0);
		}
		int count = twoCombs.get(twoHash);
		return count < k;
	}
	
	 
	
	
}
