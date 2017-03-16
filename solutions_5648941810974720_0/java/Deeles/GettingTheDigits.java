import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class GettingTheDigits {
	
	private void solve(File in, File out) throws FileNotFoundException {
		Scanner s = new Scanner(in);
		PrintWriter pw = new PrintWriter(out);
		int T = s.nextInt();
		for (int i = 0; i < T; i++) {
			pw.println("Case #" + (i+1) + ": " + solve(s.next()));
		}
		pw.flush();
		pw.close();
	}

	private String solve(String text) {
		StringBuilder sb = new StringBuilder();
		int[] numbers = new int[10];
		int[] letters = new int[26];
		for (int i = 0; i < text.length(); i++) {
			letters[text.charAt(i)-65]++;
		}
		numbers[0] = letters['Z' - 65];
		letters['E' - 65] -= letters['Z' - 65];
		letters['R' - 65] -= letters['Z' - 65];
		letters['O' - 65] -= letters['Z' - 65];
		
		numbers[2] = letters['W' - 65];
		letters['T' - 65] -= letters['W' - 65];
		letters['O' - 65] -= letters['W' - 65];
		
		numbers[4] = letters['U' - 65];
		letters['F' - 65] -= letters['U' - 65];
		letters['O' - 65] -= letters['U' - 65];
		letters['U' - 65] -= letters['U' - 65];
		
		numbers[6] = letters['X' - 65];
		letters['S' - 65] -= letters['X' - 65];
		letters['I' - 65] -= letters['X' - 65];
		
		numbers[8] = letters['G' - 65];
		letters['E' - 65] -= letters['G' - 65];
		letters['I' - 65] -= letters['G' - 65];
		letters['H' - 65] -= letters['G' - 65];
		letters['T' - 65] -= letters['G' - 65];
		
		numbers[1] = letters['O' - 65];
		letters['N' - 65] -= letters['O' - 65];
		letters['E' - 65] -= letters['O' - 65];
		
		numbers[3] = letters['T' - 65];
		letters['H' - 65] -= letters['T' - 65];
		letters['R' - 65] -= letters['T' - 65];
		letters['E' - 65] -= 2*letters['T' - 65];
		
		numbers[5] = letters['F' - 65];
		letters['I' - 65] -= letters['F' - 65];
		letters['V' - 65] -= letters['F' - 65];
		letters['E' - 65] -= letters['F' - 65];
		
		numbers[7] = letters['V' - 65];
		letters['S' - 65] -= letters['V' - 65];
		letters['E' - 65] -= 2*letters['V' - 65];
		letters['N' - 65] -= letters['V' - 65];
		
		numbers[9] = letters['I' - 65];
		
		for (int i = 0; i < numbers.length; i++) {
			for (int j = 0; j < numbers[i]; j++) {
				sb.append(i);
			}
		}
		
		return sb.toString();
	}

	public static void main(String[] args) throws FileNotFoundException {
		File in = new File("in.txt");
		File out = new File("out.txt");
		GettingTheDigits gtf = new GettingTheDigits();
		gtf.solve(in, out);
	}

}
