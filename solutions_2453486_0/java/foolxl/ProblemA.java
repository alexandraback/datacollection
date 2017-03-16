import java.io.BufferedReader;
import java.io.FileReader;
import java.util.ArrayList;
import java.util.List;


public class ProblemA {

	public static void main(String args[]) throws Exception{
		BufferedReader reader = new BufferedReader(new FileReader("data/A-small-attempt0.in"));
		int numberOfTestcase = Integer.parseInt(reader.readLine());
		
		for (int i = 0; i < numberOfTestcase; i++){
			boolean haveEmpty = false;
			char [][] matrix = new char[4][4];
			for (int j = 0; j < 4; j++){
				String line = reader.readLine();
				for (int k = 0; k < 4; k++){
					matrix[j][k] = line.charAt(k);
					if (matrix[j][k] == '.'){
						haveEmpty = true;
					}
				}
			}
			List<char[]> toTest = new ArrayList<char[]>();
			for (int j = 0; j < 4; j++){
				char[] row = matrix[j];
				toTest.add(row);
			}
			for (int k = 0; k < 4; k++){
				char[] column = new char[4];
				for (int j = 0; j < 4; j++){
					column[j] = matrix[j][k];
				}
				toTest.add(column);
			}
			char[] d1 = new char[4];
			d1[0] = matrix[0][0];
			d1[1] = matrix[1][1];
			d1[2] = matrix[2][2];
			d1[3] = matrix[3][3];
			char[] d2 = new char[4];
			d2[0] = matrix[0][3];
			d2[1] = matrix[1][2];
			d2[2] = matrix[2][1];
			d2[3] = matrix[3][0];
			toTest.add(d1);
			toTest.add(d2);
			boolean won = false;
			for (char[] row: toTest){
				boolean ok = true;
				for (int k = 0; k < 4 ; k++){
					if (row[k] == '.'){
						ok = false;
						break;
					}
				}
				if (!ok){
					continue;
				}
				char first = row[0];
				char second = row[1];
				char match = first;
				if (match == 'T'){
					match = second;
				}
				for (int k = 0; k < 4; k++){
					if (row[k] != match && row[k] != 'T'){
						ok = false;
						break;
					}
				}
				if (ok){
					System.out.println("Case #" + (i + 1) + ": " + match + " won");
					won = true;
					break;
				}
			}
			if (!won){
				if (haveEmpty){
					System.out.println("Case #" + (i + 1) + ": Game has not completed");
				}
				else{
					System.out.println("Case #" + (i + 1) + ": Draw");
				}
			}
		    reader.readLine();
		}
		
		reader.close();
		
	}
}
