package codejam;

import java.io.BufferedReader;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.HashSet;

public class _Q_C {
	public static void main(String[] args) throws Exception {
		String input_file = "C-small-attempt0.in";
		String output_file = "_Q_C_small_out.txt";
	
		BufferedReader in = new BufferedReader(new FileReader(input_file));
		PrintStream out = new PrintStream(new FileOutputStream(output_file));
		
		in.readLine();
		String line;
		int case_num = 1;
		while ((line=in.readLine()) != null) {  
			String[] line_str = line.split(" ");
			int a = Integer.parseInt(line_str[0]);
			int b = Integer.parseInt(line_str[1]);
			
			HashSet<String> hs = new HashSet<String>();
			for (Integer n = a; n <= b; ++n) {
				String n_str = n.toString();
				int len = n_str.length();
				for (int r = 1; r < len; ++r) {
					String rotated_n_str =
						n_str.substring(len - r) + n_str.substring(0, len - r);
					if (isValidPair(a, b, n_str, rotated_n_str)) {						
						String check_str =
							removeLeadingZero(n_str) + "_" +
							removeLeadingZero(rotated_n_str);
						String check_str_rev =
							removeLeadingZero(rotated_n_str) + "_" +
							removeLeadingZero(n_str);
						if (!hs.contains(check_str) &&
								!hs.contains(check_str_rev)) {
							int rotated_n =
								Integer.parseInt(rotated_n_str);
							if (n <= rotated_n)
								hs.add(check_str);
							else
								hs.add(check_str_rev);
						}						
					}
				}
			}
						
			//System.out.println("Case #" + case_num + ": " + hs.size() + "\n" + hs.toString());
			out.println("Case #" + case_num + ": " + hs.size());
			++case_num;
		}
	}
	
	private static boolean isValidPair(int a, int b, String n_str, String m_str) {		
		Integer n = Integer.parseInt(n_str);
		Integer m = Integer.parseInt(m_str);
		
		String n_str_strip = n.toString();
		String m_str_strip = m.toString();
		
		return (n_str_strip.length() == m_str_strip.length() &&
				a <= n && n < m && m <= b);		
	}
	
	private static String removeLeadingZero(String s) {
		int i = 0;
		for (; i < s.length(); ++i) {
			if (s.charAt(i) != '0')
				break;
		}
		return s.substring(i);
	}
}
