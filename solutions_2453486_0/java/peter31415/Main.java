import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;

public class Main {
	static String file = "A-small-attempt0";

	public static void main(String[] args) throws IOException {

		FileInputStream fis = new FileInputStream(file + ".in");
		InputStreamReader isr = new InputStreamReader(fis);
		BufferedReader br = new BufferedReader(isr);

		FileOutputStream fos = new FileOutputStream(file + ".out");
		OutputStreamWriter isw = new OutputStreamWriter(fos);
		BufferedWriter bw = new BufferedWriter(isw);

		String line = null;
		List<String> lines = new ArrayList<String>();
		while ((line = br.readLine()) != null) {
			lines.add(line);
		}

		int problemCount = Integer.parseInt(lines.get(0));
		int currentIndex = 0;
		for (int i = 0; i < problemCount; i++) {
			char[][] g = new char[4][4];
			for (int j = 0; j < g.length; j++) {
				g[j] = lines.get(++currentIndex).toCharArray();
			}
			++currentIndex;
			
			String solution = getSolution(g);
			String r = "Case #" + (i + 1) + ": " + solution;

			System.out.println(r);
			bw.write(r);
			bw.newLine();
		}

		if (bw != null)
			bw.close();

		if (br != null)
			br.close();
		
	}

	public static String getSolution(char[][] g) {
		String[] possible = new String[] { " won", "Draw",
				"Game has not completed" };		
		char[] m = new char[] { 'X', 'O' };
		boolean full = true;
				
		for (int x = 0; x < m.length; x++) {
			// row
			for (int i = 0; i < g.length; i++) {
				if(check(g[i], m[x]))
					return m[x] + possible[0];
			}
			
			// col
			for (int i = 0; i < g[0].length; i++) {
				char[] t = new char[g.length];
				for (int j = 0; j < g.length; j++) {
					if (g[j][i] == '.')
						full = false;
					
					t[j] = g[j][i];					
				}
				
				if(check(t, m[x]))
					return m[x] + possible[0];
			}
			
			// diag
			char[] diag1 = new char[g.length];
			char[] diag2 = new char[g.length];
			for (int i = 0; i < diag1.length; i++) {
				diag1[i]=g[i][i];
				diag2[i]=g[i][g[0].length-i-1];
			}
			
			if(check(diag1, m[x]) || check(diag2, m[x]))
				return m[x] + possible[0];
		}

		if(full)
			return possible[1];
		
		return possible[2];
	}
	
	static boolean check(char[] d, char x)
	{
		HashMap<Character, Integer> c = new HashMap<Character, Integer>();
		for (int i = 0; i < d.length; i++) {
			if (!c.containsKey(d[i]))
				c.put(d[i], 1);
			else
				c.put(d[i], c.get(d[i])+1);
		}
		
		if (c.containsKey('.') || (c.containsKey('X') && c.containsKey('O')))
			return false;
		else if (c.containsKey(x))
			return true;
		
		return false;
	}
}
