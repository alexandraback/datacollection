package codejam2015;
import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashMap;
import java.util.Scanner;

public class ProblemC {

	public static void main(String[] args) throws NumberFormatException, IOException {
		FileWriter writer = new FileWriter("C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\output.txt");
		String filename = "C:\\Users\\mchang\\workspace\\Google Code Jam\\src\\input.txt";
		try {
			BufferedReader br = new BufferedReader(new FileReader(filename));
			int numCases = Integer.parseInt(br.readLine());
			for (int caseNum = 1; caseNum <= numCases; caseNum++) {
				String line = br.readLine();
				Scanner sc = new Scanner(line);
				int n = Integer.parseInt(sc.next());
				int j = Integer.parseInt(sc.next());
				int found = 0;
				printAnswer("", caseNum, writer);
				for(int i = (int)Math.pow(2, n - 1) + 1; i < Math.pow(2, n); i+=2){
					String s = Integer.toBinaryString(i);
					String result = "";
					boolean pass = true;
					for(int base = 2; base <= 10; base++){
						long x = Long.parseLong(s, base);
						long factor = getFactor(x);
						if(factor == -1){
							pass = false;
							break;
						} else {
							result += factor + " ";
						}
					}
					if(pass){
						found++;
						result = s + " " + result;
						System.out.println(result);
						writer.write(result.trim() + "\n");
					}
					if(found == j) break;
				}
			}
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		writer.close();
	}

	public static long getFactor(long x){
		for(int i = 2; i <= Math.sqrt(x); i++){
			if(x % i == 0) return i;
		}
		return -1;
	}
	
	public static String prependZeroes(String base, int targetLength){
		while(base.length() < targetLength){
			base = "0" + base;
		}
		return base;
	}
	
	public static void printAnswer(String answer, int caseNumber,
			FileWriter writer) throws IOException {
		writer.write("Case #" + caseNumber + ": " + answer + "\n");
	}
}
