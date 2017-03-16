import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public class Main {
	public static void main(String[] args) {
		try {
			//solvefromInputToOutPut("test.in", "test.out");
			solvefromInputToOutPut("B-small-attempt0.in", "B-small-attempt0.out");
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
	
	public static void solvefromInputToOutPut(final String inputFileName,
			final String outputFileName) throws NumberFormatException,
			IOException {
		final BufferedReader reader = new BufferedReader(new FileReader(
				inputFileName));
		final int testCases = Integer.parseInt(reader.readLine());
		final List<Integer[][]> tables = new ArrayList<Integer[][]>(testCases);
		for (int i = 0; i < testCases; i++) {
			String[] line = reader.readLine().split(" ");
			final int n = Integer.parseInt(line[0]);
			final int m = Integer.parseInt(line[1]);
			final Integer[][] table = new Integer[n][m];
			for(int j = 0 ; j < n; j++){
				line = reader.readLine().split(" ");
				for(int k = 0; k < m; k++){
				     table[j][k] = Integer.parseInt(line[k]);
				}
			}
			tables.add(i, table);
		}
		reader.close();
		final List<String> result = checkPatterns(tables);
		final BufferedWriter writer = new BufferedWriter(new FileWriter(
				outputFileName));
		for (int i = 0; i < testCases; i++) {
			writer.write("Case #" + (i + 1) + ": " + result.get(i) + "\n");
		}
		writer.close();
	}
	
	private static List<String> checkPatterns(final List<Integer[][]>tables){
		final List<String> result = new ArrayList<String>(tables.size());
		for(int i = 0; i < tables.size(); i++){
			result.add(i, checkPattern(tables.get(i)));
		}
		return result;
	}
	
	private static String checkPattern(final Integer[][] table ){
		for(int  i = 0; i < table.length; i++){
			for(int j = 0; j < table[i].length; j++){
				boolean possible = true;
				for(int k = 0; k < table.length; k++){
					if(table[i][j] < table[k][j]){
						possible = false;
						break;
					}
				}
				if(!possible){
					for(int k = 0; k < table[i].length; k++){
						if(table[i][j] < table[i][k]){
							return "NO";
						}
						
					}
				}
			}
		}
		return "YES";
	}
	

	/*
	 * (non-Java-doc)
	 * 
	 * @see java.lang.Object#Object()
	 */
	public Main() {
		super();
	}

}