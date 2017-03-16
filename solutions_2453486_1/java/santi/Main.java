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
			solvefromInputToOutPut("A-large.in", "A-large.out");
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
		final List<List<String>> tables = new ArrayList<List<String>>(testCases);
		for (int i = 0; i < testCases; i++) {
			List<String> table = new ArrayList<String>(4);
			for (int j = 0; j < 4; j++) {
				table.add(reader.readLine());
			}
			tables.add(i, table);
			if (i < testCases) {
				reader.readLine();
			}
		}
		reader.close();
		final List<String> result = checkTables(tables);
		final BufferedWriter writer = new BufferedWriter(new FileWriter(
				outputFileName));
		for (int i = 0; i < testCases; i++) {
			writer.write("Case #" + (i + 1) + ": " + result.get(i) + "\n");
		}
		writer.close();
	}

	private static List<String> checkTables(final List<List<String>> tables) {
		final List<String> result = new ArrayList<String>(tables.size());
		for (int i = 0; i < tables.size(); i++) {
			result.add(i, checkTable(tables.get(i)));
		}
		return result;
	}

	private static String checkTable(final List<String> table) {
		if(checkTable(table, 'O')){
			return "O won";
		}
		else if(checkTable(table, 'X')){
			return "X won";
		}else{
			for(int i = 0; i < 4; i++){
				if(table.get(i).lastIndexOf('.') >= 0){
					return "Game has not completed";
				}
			}
			return "Draw";
		}
		
		
	}

	private static boolean checkTable(final List<String> table, final char symbol) {
		boolean won;
		for (int i = 0; i < 4; i++) {
			final String row = table.get(i);
			won = true;
			for (int j = 0; j < 4; j++) {
				if (row.charAt(j) != symbol && row.charAt(j) != 'T') {
					won = false;
					break;
				}
			}
			if (won) {
				return true;
			}
		}
		for (int i = 0; i < 4; i++) {
			won = true;
			for (int j = 0; j < 4; j++) {
				final char c = table.get(j).charAt(i);
				if (c != 'T' && c != symbol) {
					won = false;
					break;
				}
			}
			if (won) {
				return true;
			}
		}
		won = true;
		for (int i = 0; i < 4; i++) {
			final char c = table.get(i).charAt(i);
			if (c != 'T' && c != symbol) {
				won = false;
				break;
			}
		}
		if (won) {
			return true;
		}
		won = true;
		for (int i = 0; i < 4; i++) {
			final char c = table.get(i).charAt(3-i);
			if (c != 'T' && c != symbol) {
				won = false;
				break;
			}
		}
		return won;

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