import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;

public class Dijkstra {
	static String[][] table = { { "NULL", "1", "i", "j", "k", "n"},
								{ "1",	  "1", "i", "j", "k", "n" },
								{ "i",	  "i", "n", "k", "nj", "ni" },
								{ "j",	  "j", "nk", "n", "i", "nj" },
								{ "k", 	  "k", "j", "ni", "n", "nk" },
								{ "n",    "n", "ni", "nj", "nk", "1" } };

	public static void main(String[] args) throws IOException {
		String fileRoot = "C-small-attempt1";
		String fileName = "C:\\Users\\Aaron\\Downloads\\" + fileRoot + ".in";
		BufferedReader reader = new BufferedReader(new FileReader(new File(
				fileName)));
		int nTestCases = Integer.parseInt(reader.readLine());
		ArrayList<String> out = new ArrayList<String>();
		for (int t = 0; t < nTestCases; t++) {
			String[] parts = reader.readLine().split(" ");
			int rep = Integer.parseInt(parts[1]);
			String s = reader.readLine();
			boolean foundSolution = false;
			
			String byStr = chainMult(s);
			String cumProd = byStr;
			for (int i = 1; i < rep; i++) {
				cumProd = mult(byStr, cumProd);
			}
			//System.out.println("cumProd: " + cumProd);
			
			if (cumProd.equals("n")) {
				StringBuilder huge = new StringBuilder();
				for (int i = 0; i < rep; i++) {
					huge.append(s);
				}
				String big = huge.toString();
				//System.out.println("Big: " + big);
				
				String prev = "1";
				outer: for (int i = 0; i < big.length(); i++) {
					String res = mult(prev, big.substring(i, i + 1));
					//System.out.println("res " + res);
					
					if (res.equals("i")) {
						
						String prev2 = "1";
						for (int j = i + 1; j < big.length(); j++) {
							String res2 = mult(prev2, big.substring(j, j + 1));
							//System.out.println("\t res2: " + res2);
							
							if (res2.equals("j")) {
								if (divide(cumProd, mult("i", "j")).equals("k")) {
									//System.out.println("found using math");
									foundSolution = true;
									break outer;
								}
								String chain = chainMult(big.substring(j + 1));
								
								if (chain.equals("k")) {
									//System.out.println("\t\t\tGot K, making the third substring " + big.substring(j + 1));
									//System.out.println("GOT IT!!");
									foundSolution = true;
									break outer;
								}
							}
							prev2 = res2;
						}
						
					}
					prev = res;
				}
			}
			
			String sol = "";
			if (foundSolution) {
				sol = "YES";
			} else {
				sol = "NO";
			}
			out.add("Case #" + (t+1) + ": " + sol);
			System.out.println("Case #" + (t+1) + ": " + sol);
		}

		PrintWriter writer = new PrintWriter(new BufferedWriter(new FileWriter(
				"C:\\Users\\Aaron\\Downloads\\" + fileRoot + "-sol.out")));
		for (String s : out) {
			writer.write(s + "\n");
		}

		writer.close();
		reader.close();
	}
	
	public static String divide (String a, String b) {
		
		for (int r = 0; r < table.length; r++) {
			for (int c = 0; c < table.length; c++) {
				if (table[r][c].equals(a)) {
					if (table[r][0].equals(b)) {
						return table[0][c];
					}
					else if (table[0][c].equals(b)) {
						return table[r][0];
					}
				}
			}
		}
		return "Uh oh!";
	}

	public static String chainMult(String s) {
		if (s.length() <= 1) {
			return s;
		}
		String prod = mult("" + s.charAt(0), "" + s.charAt(1));
		for (int i = 2; i < s.length(); i++) {
			prod = mult(prod, s.charAt(i) + "");
		}
		return prod;
	}

	public static String mult(String a, String b) {
		String takeOut = "";
		
		if (a.length() == 2) {
			takeOut += a.charAt(0);
			a = a.substring(1);
		}

		if (b.length() == 2) {
			takeOut += b.charAt(0);
			b = b.substring(1);
		}

		int row = -1;
		int col = -1;
		for (int r = 0; r < table.length; r++) {
			if (table[r][0].equals(a)) {
				row = r;
			}
		}

		for (int c = 0; c < table[0].length; c++) {
			if (table[0][c].equals(b)) {
				col = c;
			}
		}

		String ret = table[row][col];

		if (takeOut.length() == 1) {
			ret = "n" + ret;
		}
		
		if (ret.length() > 1 && ret.substring(0, 2).equals("nn")) {
			if (ret.length() == 2) ret = "1";
			else ret = ret.substring(2);
		}
		
		return ret;
	}

}
