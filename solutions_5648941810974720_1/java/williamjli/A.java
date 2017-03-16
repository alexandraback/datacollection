import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

public class A {

	public static void main(String[] args) throws IOException {
		
		BufferedReader input = new BufferedReader(new FileReader("C:\\Users\\Wenjuan\\Desktop\\A.txt"));
		PrintWriter output = new PrintWriter(new FileWriter("C:\\Users\\Wenjuan\\Desktop\\answer.txt"));
		
		int T = Integer.parseInt(input.readLine());
		
		for (int t = 1; t <= T; t++) {
			
			String s = input.readLine();
			
			int[] number = new int[10];
			int[] frequency = new int[26];
			
			for (int i = 0; i < s.length(); i++) {
				
				frequency[s.charAt(i) - 'A']++;
				
			}
			
			int min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['Z' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			min = Math.min(min, frequency['R' - 'A']);
			min = Math.min(min, frequency['O' - 'A']);
			
			number[0] += min;
			
			frequency['Z' - 'A'] -= min;
			frequency['Z' - 'A'] -= min;
			frequency['Z' - 'A'] -= min;
			frequency['Z' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['S' - 'A']);
			min = Math.min(min, frequency['I' - 'A']);
			min = Math.min(min, frequency['X' - 'A']);
			
			number[6] += min;
			
			frequency['S' - 'A'] -= min;
			frequency['I' - 'A'] -= min;
			frequency['X' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['T' - 'A']);
			min = Math.min(min, frequency['W' - 'A']);
			min = Math.min(min, frequency['O' - 'A']);
			
			number[2] += min;
			
			frequency['T' - 'A'] -= min;
			frequency['W' - 'A'] -= min;
			frequency['O' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['E' - 'A']);
			min = Math.min(min, frequency['I' - 'A']);
			min = Math.min(min, frequency['G' - 'A']);
			min = Math.min(min, frequency['H' - 'A']);
			min = Math.min(min, frequency['T' - 'A']);
			
			number[8] += min;
			
			frequency['E' - 'A'] -= min;
			frequency['I' - 'A'] -= min;
			frequency['G' - 'A'] -= min;
			frequency['H' - 'A'] -= min;
			frequency['T' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['F' - 'A']);
			min = Math.min(min, frequency['O' - 'A']);
			min = Math.min(min, frequency['U' - 'A']);
			min = Math.min(min, frequency['R' - 'A']);
			
			number[4] += min;
			
			frequency['F' - 'A'] -= min;
			frequency['O' - 'A'] -= min;
			frequency['U' - 'A'] -= min;
			frequency['R' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['T' - 'A']);
			min = Math.min(min, frequency['H' - 'A']);
			min = Math.min(min, frequency['R' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			
			number[3] += min;
			
			frequency['T' - 'A'] -= min;
			frequency['H' - 'A'] -= min;
			frequency['R' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['F' - 'A']);
			min = Math.min(min, frequency['I' - 'A']);
			min = Math.min(min, frequency['V' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			
			number[5] += min;
			
			frequency['F' - 'A'] -= min;
			frequency['I' - 'A'] -= min;
			frequency['V' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['S' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			min = Math.min(min, frequency['V' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			min = Math.min(min, frequency['N' - 'A']);
			
			number[7] += min;
			
			frequency['S' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			frequency['V' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			frequency['N' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['N' - 'A']);
			min = Math.min(min, frequency['I' - 'A']);
			min = Math.min(min, frequency['N' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			
			number[9] += min;
			
			frequency['N' - 'A'] -= min;
			frequency['I' - 'A'] -= min;
			frequency['N' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			
			min = Integer.MAX_VALUE;

			min = Math.min(min, frequency['O' - 'A']);
			min = Math.min(min, frequency['N' - 'A']);
			min = Math.min(min, frequency['E' - 'A']);
			
			number[1] += min;
			
			frequency['O' - 'A'] -= min;
			frequency['N' - 'A'] -= min;
			frequency['E' - 'A'] -= min;
			
			String num = "";
			
			for (int i = 0; i < 10; i++) {
				
				for (int j = 0; j < number[i]; j++) {
					
					num += i;
					
				}
				
			}
			
			output.println(num);
			
		}
		
		input.close();
		output.close();
		
	}
	
}