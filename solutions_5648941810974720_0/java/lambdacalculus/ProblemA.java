import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


public class ProblemA {

	static PrintStream out = System.out;

	public static void main(String[] args) throws FileNotFoundException {
		new ProblemA().run();
	}

	public void run() throws FileNotFoundException {
		//Scanner in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Documents/Taktik/Sources/problems/files/ina")));
		Scanner in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/A-small.in")));
		//Scanner in = new Scanner(new BufferedReader(new FileReader("/Users/abaudoux/Downloads/A-large.in")));
		int size = in.nextInt();

		for (int p = 0 ; p < size ; p++) {
			out.println("Case #" + (p+1) + ": " + solve(in.next()));
		}
	}

	public String solve(String n) {

		StringBuilder b = new StringBuilder();
		Map<String, Integer> letters = new HashMap<>();
		letters.put("A", 0);
		letters.put("B", 0);
		letters.put("C", 0);
		letters.put("D", 0);
		letters.put("E", 0);
		letters.put("F", 0);
		letters.put("G", 0);
		letters.put("H", 0);
		letters.put("I", 0);
		letters.put("J", 0);
		letters.put("K", 0);
		letters.put("L", 0);
		letters.put("M", 0);
		letters.put("N", 0);
		letters.put("O", 0);
		letters.put("P", 0);
		letters.put("Q", 0);
		letters.put("R", 0);
		letters.put("S", 0);
		letters.put("T", 0);
		letters.put("U", 0);
		letters.put("V", 0);
		letters.put("W", 0);
		letters.put("X", 0);
		letters.put("Y", 0);
		letters.put("Z", 0);
		for (char c : n.toCharArray()) {
			String key = new String(new char[]{c});
			Integer count = letters.get(key);
			if (count == null) {
				count = 0;
			}
			letters.put(key, count + 1);
		}


		int countZeroes = letters.get("Z");

		for (int i=0 ; i< countZeroes ; i++) {
			dec(letters,"E");
			dec(letters,"R");
			dec(letters,"O");
		}

		int countTwo= letters.get("W");

		for (int i=0 ; i< countTwo ; i++) {
			dec(letters,"T");
			dec(letters,"O");
		}

		int countEight= letters.get("G");

		for (int i=0 ; i< countEight ; i++) {
			dec(letters,"E");
			dec(letters,"I");
			dec(letters,"H");
		}

		int countSix= letters.get("X");

		for (int i=0 ; i< countSix ; i++) {
			dec(letters,"S");
			dec(letters,"I");
		}

		int countSeven= letters.get("S");

		for (int i=0 ; i< countSeven ; i++) {
			dec(letters,"E");
			dec(letters,"V");
			dec(letters,"E");
			dec(letters,"N");
		}

		int countThree= letters.get("H");

		for (int i=0 ; i< countThree ; i++) {
			dec(letters,"T");
			dec(letters,"R");
			dec(letters,"E");
			dec(letters,"E");
		}
		int countFour= letters.get("R");

		for (int i=0 ; i< countFour ; i++) {
			dec(letters,"F");
			dec(letters,"O");
			dec(letters,"U");
		}
		int countFive= letters.get("V");

		for (int i=0 ; i< countFive ; i++) {
			dec(letters,"F");
			dec(letters,"I");
			dec(letters,"E");
		}

		int countOne= letters.get("O");

		for (int i=0 ; i< countOne ; i++) {
			dec(letters,"N");
			dec(letters,"E");
		}

		int countNinee= letters.get("I");

		for (int i=0 ; i< countOne ; i++) {
			dec(letters,"N");
			dec(letters,"E");
		}

		for (int i = 0; i < countZeroes; i++) {
			b.append('0');
		}
		for (int i = 0; i < countOne; i++) {
			b.append('1');
		}
		for (int i = 0; i < countTwo; i++) {
			b.append('2');
		}
		for (int i = 0; i < countThree; i++) {
			b.append('3');
		}
		for (int i = 0; i < countFour; i++) {
			b.append('4');
		}
		for (int i = 0; i < countFive; i++) {
			b.append('5');
		}
		for (int i = 0; i < countSix; i++) {
			b.append('6');
		}
		for (int i = 0; i < countSeven; i++) {
			b.append('7');
		}
		for (int i = 0; i < countEight; i++) {
			b.append('8');
		}
		for (int i = 0; i < countNinee; i++) {
			b.append('9');
		}
		return b.toString();
	}


	public void dec(Map<String, Integer> letters , String key) {
		Integer count = letters.get(key);
		letters.put(key, count - 1);
	}
}
