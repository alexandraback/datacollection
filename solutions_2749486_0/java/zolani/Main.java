import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;


public class Main {
	
	
	public static void main(String[] args) {
		ex2();
	}
	
	public static void ex2() {
		
		String output = "";
		
		try {
			File file = new File("ex2/input");
			FileInputStream is = new FileInputStream(file);
			InputStreamReader ir = new InputStreamReader(is);
			BufferedReader in = new BufferedReader(ir);

			String str_line = in.readLine();
			String[] str_line_parts;
			int x = 0;
			int y = 0;
			int i = 0;
			int number_cases = 0;
			int number_cases_processed = 0;
			number_cases = Integer.parseInt(str_line);
			
			while(number_cases_processed < number_cases) {
				str_line = in.readLine();
				str_line_parts = str_line.split(" ");
				x = Integer.parseInt(str_line_parts[0]);
				y = Integer.parseInt(str_line_parts[1]);
				i = number_cases_processed + 1;
				output += "Case #" + i + ": " + return_combinaison(x, y) + "\n";
				number_cases_processed++;
			}
			
			is.close();
			ir.close();
			in.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} 
		
		try {
			FileWriter fw = new FileWriter(new File("ex2/output"));
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(output);
			bw.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public static void ex1() {
		int number_cases;
		int number_cases_processed = 0;
		String output = "";
		
		try {
			File file = new File("ex1/input");
			FileInputStream is = new FileInputStream(file);
			InputStreamReader ir = new InputStreamReader(is);
			BufferedReader in = new BufferedReader(ir);

			String str_line = in.readLine();
			String[] str_line_parts;
			String noun = "";
			int n = 0;
			int i = 0;
			number_cases = Integer.parseInt(str_line);
			
			while(number_cases_processed < number_cases) {
				str_line = in.readLine();
				str_line_parts = str_line.split(" ");
				noun = str_line_parts[0];
				n = Integer.parseInt(str_line_parts[1]);
				i = number_cases_processed + 1;
				output += "Case #" + i + ": " + return_nuplet(noun, n) + "\n";
				number_cases_processed++;
			}
			
			is.close();
			ir.close();
			in.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} 
		
		try {
			FileWriter fw = new FileWriter(new File("ex1/output"));
			BufferedWriter bw = new BufferedWriter(fw);
			bw.write(output);
			bw.close();

		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		} 
	}
	
	public static String return_combinaison(int x, int y) {
		String combinaison = "";
		int current_x = 0;
		int current_y = 0;
		if(x < 0) {
			while(current_x != x) {
				combinaison += "EW";
				current_x--;
			}
		}
		else {
			while(current_x != x) {
				combinaison += "WE";
				current_x++;
			}
		}
		if(y < 0) {
			while(current_y != y) {
				combinaison += "NS";
				current_y--;
			}
		}
		else {
			while(current_y != y) {
				combinaison += "SN";
				current_y++;
			}
		}
		return combinaison;
	}
	
	public static int return_nuplet(String word, int n) {
		int number_nuplet = 0;
		int length_word = word.length();
		int i = 0;
		int start = 0;
		int end = 0;
		String sequence = "";
		String new_sequence = "";
		String sequence_limit = "";
		ArrayList<String> sequences = new ArrayList<String>();
		while(i < length_word && (i+n) <= length_word) {
			sequence = word.substring(i, (i+n));
			if(!(sequence.contains("a") || sequence.contains("e") || sequence.contains("i") || sequence.contains("o") || sequence.contains("u"))) {
				sequence_limit = i + "-" + (i+n-1);
				sequences.add(sequence_limit);
				number_nuplet++;
				start = i;
				end = i+n-1;
				
				for(int j = start; j >= 0; j--) {
					for(int k = end; k < length_word; k++) {
						new_sequence = word.substring(j, k+1);
						new_sequence = j + "-" + k;
						if(!sequences.contains(new_sequence)) {
							sequences.add(new_sequence);
							number_nuplet++;
						}
							
					}
				}
				
			}	
			i++;
		}
		
		return number_nuplet;
	}
	
}
