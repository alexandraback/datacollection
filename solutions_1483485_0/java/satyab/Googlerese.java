import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;


public class Googlerese {

	public static void main(String[] args) throws Exception {
		BufferedReader bfrd = new BufferedReader(new FileReader("input.in"));
		BufferedWriter bfrw = new BufferedWriter(new FileWriter("output.out"));
		int N = Integer.parseInt(bfrd.readLine());
		String output = "";
		for(int i = 0; i < N; i++){
			String s = bfrd.readLine();
			output += "Case #"+(i+1)+": " + solve(s) + "\n";
		}

		bfrw.write(output);
		bfrw.close();
		bfrd.close();
	}
	
	private static String solve(String s) {
		String ret = "";
		
		String old = "abcdefghijklmnopqrstuvwxyz";
		String ne  = "ynficwlbkuomxsevzpdrjgthaq";
		
		for(int i = 0; i < s.length();i++){
			if(s.charAt(i) == ' ') { ret += ' '; continue;}
			
			int j = ne.indexOf(s.charAt(i));
			ret += old.charAt(j); 
		}
		return ret;
	}
	
	
}
