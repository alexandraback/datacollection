package qual;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;

public class A {

	static char[] d = new char[26];
	public static int indxOf(char c){
		return c - 'a';
	}
	
	public static void initDictionary() throws Exception{
		BufferedReader sin = new BufferedReader(new FileReader("q/a/sample_in.txt"));
		BufferedReader sout = new BufferedReader(new FileReader("q/a/sample_out.txt"));
		boolean[] incl = new boolean[26];
		//a' -> 'y', 'o' -> 'e', and 'z' -> 'q'
		d[indxOf('y')] = 'a';
		d[indxOf('e')] = 'o';
		d[indxOf('q')] = 'z';
		d[25] = 'q';
		sin.readLine();
		for (int i = 0; i < 3; i++){
			String in = sin.readLine();
			String out = sout.readLine().substring("Case #X: ".length());
			for (int j = 0; j < in.length(); j++){
				char ch_in = in.charAt(j);
				char ch_out = out.charAt(j);
				if (ch_in != ' '){
					int idx = indxOf(ch_in);
					if (d[idx] == 0) {
						d[idx] = ch_out;
						incl[indxOf(ch_out)] = true;
					}
					if (d[idx] != ch_out) throw new Exception("not match");
				}
			}
		}
	/*	for (int i = 0; i < incl.length; i++){
			if (!incl[i]) {
				System.out.print((char)(i + (int)'a'));
			}
		}*/
		sin.close();
		sout.close();
	}

	public static void main(String[] args) throws Exception{
		initDictionary();
		String in_file = "q/a/a_in.txt";
		String out_file = in_file.replace("_in.txt", "_out.txt");
		BufferedReader in = new BufferedReader(new FileReader(in_file));
		BufferedWriter out = new BufferedWriter(new FileWriter(out_file));
		int n = Integer.parseInt(in.readLine());
		for (int i = 1; i <= n; i++){
			out.write("Case #" + i + ": ");
			String s = in.readLine();
			for (int j = 0; j < s.length(); j++){
				char c = s.charAt(j);
				out.write(c == ' ' ? ' ' : d[indxOf(c)]);
			}
			out.write("\n");
		}
		
		
		in.close();
		out.close();
		
	}
}
