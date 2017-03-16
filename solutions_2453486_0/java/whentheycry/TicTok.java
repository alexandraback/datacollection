import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Scanner;


public class TicTok {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			BufferedReader scan = new BufferedReader(new FileReader("A-small-attempt1.in"));
			FileWriter fstream = new FileWriter("out.txt");
			BufferedWriter out = new BufferedWriter(fstream);
			
		ArrayList<String> result = new ArrayList<String>();
		int number = Integer.parseInt(scan.readLine());
			int k;
			for (k = 0; k <number;k++){
				
				String[][] game = new String[4][4];
				String nline = "";
				boolean done = false;
				for (int i = 0;i<4;i++){
					nline = scan.readLine();
					for (int j = 0;j<4;j++){
						game[i][j] = String.valueOf(nline.charAt(j));
					}
				}
				
				for (int i= 0;i<4;i++){
					String row = game[i][0] + game[i][1] + game[i][2] + game[i][3];
					int countX = countOccurrences(row, 'X');
					int countO = countOccurrences(row, 'O');
					int countT = countOccurrences(row, 'T');
					if (countX >=3){
						if (countT == 1 || countX == 4){
						int n = k+1;
						result.add("Case #" + n +": " + "X" + " won" );
						done = true;
						}
					} else
					if (countO >=3 ){
						if (countT == 1 || countO == 4){
							int n = k+1;
						result.add("Case #" + n +": " + "O" + " won" );
						done = true;
						}
					}
				}
				
				if (!done){
				for (int j= 0;j<4;j++){
					String column = game[0][j] + game[1][j] + game[2][j] + game[3][j];
						int countX = countOccurrences(column, 'X');
						int countO = countOccurrences(column, 'O');
						int countT = countOccurrences(column, 'T');
						if (countX >=3){
							if (countT == 1 || countX == 4){
							int n = k+1;
							result.add("Case #" + n +": " + "X" + " won" );
							done = true;
							}
						} else
						if (countO >=3 ){
							if (countT == 1 || countO == 4){
								int n = k+1;
							result.add("Case #" + n +": " + "O" + " won" );
							done = true;
							}
						}

				}
				}
				
				if (!done){
						String diagonal1 = game[0][0] + game[1][1] + game[2][2] + game[3][3];
							int countX = countOccurrences(diagonal1, 'X');
							int countO = countOccurrences(diagonal1, 'O');
							int countT = countOccurrences(diagonal1, 'T');
							if (countX >=3){
								if (countT == 1 || countX == 4){
								int n = k+1;
								result.add("Case #" + n +": " + "X" + " won" );
								done = true;
								}
							} else
							if (countO >=3 ){
								if (countT == 1 || countO == 4){
									int n = k+1;
								result.add("Case #" + n +": " + "O" + " won" );
								done = true;
								}
							}
			
					}
				if (!done){
					String diagonal2 = game[0][3] + game[1][2] + game[2][1] + game[3][0];
						int countX = countOccurrences(diagonal2, 'X');
						int countO = countOccurrences(diagonal2, 'O');
						int countT = countOccurrences(diagonal2, 'T');
						if (countX >=3){
							if (countT == 1 || countX == 4){
							int n = k+1;
							result.add("Case #" + n +": " + "X" + " won" );
							done = true;
							}
						} else
						if (countO >=3 ){
							if (countT == 1 || countO == 4){
								int n = k+1;
							result.add("Case #" + n +": " + "O" + " won" );
							done = true;
							}
						}
				}
				
				if (!done){
					for (int i = 0; i<4;i++){
						if (!done)
						for (int j =0;j<4;j++){
						if(game[i][j].equals(".")){
							int n = k+1;
							result.add("Case #" + n +": " + "Game has not completed");
							done = true;
							break;
						}	
						}
					}
					
				}
				if (!done) {
					int n = k+1;
					result.add("Case #" + n +": " + "Draw");
					done = true;
				}
				
				scan.readLine();
			}
			
		
		for (int i = 0;i<k;i++){
			out.write(result.get(i)+"\n");
		}
		out.close();
		}catch (Exception e) {
	        System.err.println("Error:" + e.getMessage());
	    }
	}

	public static int countOccurrences(String haystack, char needle)
	{
	    int count = 0;
	    for (int i=0; i < haystack.length(); i++)
	    {
	        if (haystack.charAt(i) == needle)
	        {
	             count++;
	        }
	    }
	    return count;
	}

}
