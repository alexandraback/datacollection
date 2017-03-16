import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;


public class Dijkstra {
	HashMap<String, String> map = new HashMap<String, String>();
	
	public Dijkstra() {
		map.put("11", "1");
		map.put("i1","i");
		map.put("j1","j");
		map.put("k1","k");
		
		map.put("1i", "i");
		map.put("ii","-1");
		map.put("ji","-k");
		map.put("ki","j");
		
		map.put("1j", "j");
		map.put("ij","k");
		map.put("jj","-1");
		map.put("kj","-i");
		
		map.put("1k", "k");
		map.put("ik","-j");
		map.put("jk","i");
		map.put("kk","-1");
		
	}
	
	public boolean reduceChar(StringBuilder sb, char checkChar) {

		boolean isPositive = true;
		while (sb.length() > 0) {
			if (sb.charAt(0) == checkChar && isPositive) {
				sb.delete(0, 1);
				return true;
			}
			if (sb.length() == 1) return false;
			String result = map.get(sb.substring(0, 2));
			sb.delete(0, 2);
			if (result.startsWith("-")) {
				isPositive = !isPositive;
				sb.insert(0,  result.substring(1));
			}
			else {
				sb.insert(0,  result);
			}
		}
		return false;
		
	}
	
	public boolean isK(StringBuilder sb) {
		boolean isPositive = true;
		while (sb.length() > 1) {
			
			String result = map.get(sb.substring(0, 2));
			// System.out.println(sb.substring(0, 2) + "\t" + result);
			sb.delete(0, 2);
			if (result.startsWith("-")) {
				isPositive = !isPositive;
				sb.insert(0,  result.substring(1));
			}
			else {
				sb.insert(0,  result);
			}
		}
		return isPositive && sb.toString().equals("k");
	}
	public boolean Check(StringBuilder sb) {
		if (!reduceChar(sb, 'i')) return false;
		if(!reduceChar(sb, 'j')) return false;
		return isK(sb);
	}
	public void solution(String inputFile, String outputFile) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader(new File(inputFile)));
		PrintWriter pw = new PrintWriter(new FileWriter(new File(outputFile)));
		String line = br.readLine();
		int N = Integer.parseInt(line);
		
		int id = 1;
		for (int i = 0; i < N; ++i) {
			String[] a = br.readLine().split(" ");
			int L = Integer.parseInt(a[0]);
			int C = Integer.parseInt(a[1]);
			
			line = br.readLine();
			StringBuilder sb = new StringBuilder();
			// System.out.println("check this" + L + "\t" + C);
			// System.out.println("check this line " + line.substring(0,10));
			for (int j = 0; j < C; ++j) {
				sb.append(line);
			}
			// System.out.println("check this line size" + sb.length());
			if (Check(sb)) 
				pw.println("Case #"+id+": "+"YES");
			else
				pw.println("Case #"+id+": "+"NO");
			id++;
		}
		br.close();
		pw.close();
	}
	
	public static void main(String[] args) throws IOException {
		String inputFile = "src/Dijkstra.in";
		String outputFile = "src/Dijkstra.out";
		Dijkstra d = new Dijkstra();
		d.solution(inputFile, outputFile);
	}
}
