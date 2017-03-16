package round0;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;

public class Dijkstra {
	private static FileWriter writer;

	public static void main(String[] args) throws IOException {
		File file = new File("round0/C-large.in");
		BufferedReader reader = new BufferedReader(new FileReader(file));
	
		File outputFile = new File("round0/output-dijkstra.txt");
		writer = new FileWriter(outputFile);
		int numberOfTests = Integer.parseInt(reader.readLine());
		for (int test = 1; test <= numberOfTests; test++) {
			String[] split = reader.readLine().split(" ");
			int l = Integer.parseInt(split[0]);
			long x = Long.parseLong(split[1]);
			String quaternions = reader.readLine();
			String answer = ijk(l, x, quaternions) ? "YES" : "NO";
			generateOutput("Case #" + test + ": " + answer);
		}
		
		
		reader.close();
		writer.close();
	}
	
	private static void generateOutput(String line) throws IOException {
		System.out.println(line);
		writer.write(line + "\n");
	}

	private static boolean ijk(int length, long times, String quaternions) {
		Quaternion result = eval(length, quaternions.toCharArray());
		if (result.value == '1' && result.sign == 1) return false;
		else if (result.value == '1' && result.sign == -1) {
			if(times % 2 == 0) return false;
		}
		else if (times % 4 != 2) return false;
		// The entire string of quaternions evaluates to -1 (= ijk)
		// we just need to check whether somewhere in the beginning is a substring evaluating to i and then to ij (=k).
		// the repetition is useless after 4 cycles. We need to check two subsequent cases, so length 8 is sufficient.
		if (times > 8) {
			times = 8;
		}
		String entire = "";
		for (int t = 0; t < times; t++) {
			entire = entire + quaternions;
		}
		char[] entireArray = entire.toCharArray();
		Quaternion answer = new Quaternion(1, '1');
		boolean foundI = false;
		
		for (int l = 0; l < length * times; l++) {
			answer = multiply(answer, new Quaternion(1, entireArray[l]));
			if(answer.sign == 1 && answer.value == 'i') {
				foundI = true;
			}
			if(foundI && answer.sign == 1 && answer.value == 'k') {
				return true;
			}
		}

		return false;
	}
	
	private static Quaternion eval(int length, char[] quaternions) {
		Quaternion answer = new Quaternion(1, '1');
		for (int l = 0; l < length; l++) {
			answer = multiply(answer, new Quaternion(1, quaternions[l]));
		}
		return answer;
	}

	private static Quaternion multiply(Quaternion first, Quaternion second) {
		int newSign = first.sign * second.sign;
		char newValue = 0;
		if (first.value == '1') {newValue = second.value;}
		if (second.value == '1') {newValue = first.value;}
		if (first.value == second.value) {newValue = '1'; newSign *= -1;}
		if (first.value == 'i' && second.value == 'j') {newValue = 'k';}
		if (first.value == 'j' && second.value == 'i') {newValue = 'k'; newSign *= -1;}
		if (first.value == 'i' && second.value == 'k') {newValue = 'j'; newSign *= -1;}
		if (first.value == 'k' && second.value == 'i') {newValue = 'j';}
		if (first.value == 'j' && second.value == 'k') {newValue = 'i';}
		if (first.value == 'k' && second.value == 'j') {newValue = 'i'; newSign *= -1;}
		
		return new Quaternion(newSign, newValue);
	}

}

class Quaternion {
	public int sign;
	public char value;
	
	Quaternion(int sign, char value) {
		this.sign = sign;
		this.value = value;
	}
}