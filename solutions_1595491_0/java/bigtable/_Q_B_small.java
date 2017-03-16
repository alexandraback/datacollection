package codejam;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;

public class _Q_B_small {
	public static void main(String[] args) throws Exception {
		String input_file = "B-small-attempt0.in";
		String output_file = "_Q_B_small_out.txt";
		
		BufferedReader in = new BufferedReader(new FileReader(input_file));
		PrintStream out = new PrintStream(new FileOutputStream(output_file));
		
		in.readLine();
		String line;
		int case_num = 1;
		while ((line=in.readLine()) != null) {  
			String[] line_str = line.split(" ");
			int n = Integer.parseInt(line_str[0]);
			int s = Integer.parseInt(line_str[1]);
			int p = Integer.parseInt(line_str[2]);
			int[] t = new int[n];
			for (int i = 0; i < n; ++i)
				t[i] = Integer.parseInt(line_str[i+3]);
			
			int[] base = new int[n];
			int[] remain = new int[n];
			
			for (int i = 0; i < n; ++i) {
				base[i] = t[i]/3;
				remain[i] = t[i]%3;
			}
			
			// Filter by p
			ArrayList<Integer> valid_index = new ArrayList<Integer>();
			for (int i = 0; i < n; ++i) {
				if (base[i] >= p - 1 ||	base[i] + remain[i] >= p)
					valid_index.add(i);
			}
			
			int s_consumed = 0;
			int result = 0;
			for (Integer i : valid_index) {				
				if (remain[i] == 0) {
					if (base[i] < p) {
						if (base[i] > 0 && s_consumed < s) {
							++s_consumed;
							++result;	
						}
					} else {
						++result;
					}
				}
			}
			
			for (Integer i : valid_index) {				
				if (remain[i] == 1) {
					++result;
				} else if (remain[i] == 2){
					if (base[i] < p - 1) {
						if (s_consumed < s) {
							++s_consumed;
							++result;
						}
					} else {				
						++result;
					}
				}
			}
			
			out.println("Case #" + case_num + ": " + result);
			++case_num;
		}
	}
}
