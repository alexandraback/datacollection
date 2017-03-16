import java.util.*;
import java.io.*;

class Main {

    public static void main(String[] args) throws IOException {
	final Scanner stdin = new Scanner(System.in);
	final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	final int T = Integer.parseInt(br.readLine());
	for (int t = 1; t <= T; t++){
	    final char[][] map = new char[4][4];
	    for (int i = 0; i < 4; i++){
		map[i] = br.readLine().toCharArray();
	    }
	    //printArray(map);
	    br.readLine();

	    solve(map, t);
	}
    }

    static void solve(char[][] map, int t){
	System.out.printf("Case #%d: ", t);

	final boolean isOWin = checkColumn('O', map) || checkRow('O', map) || checkDiag('O', map);
	final boolean isXWin = checkColumn('X', map) || checkRow('X', map) || checkDiag('X', map);
	final boolean hasEmptyCell = checkEmpty(map);

	if (isOWin && !isXWin){
	    System.out.println("O won");
	} else if (!isOWin && isXWin){
	    System.out.println("X won");
	} else if (!isOWin && !isXWin && !hasEmptyCell){
	    System.out.println("Draw");
	} else {
	    System.out.println("Game has not completed");
	}
    }

    static boolean checkEmpty(char[][] map){
	for (int c = 0; c < map.length; c++){
	    for (int r = 0; r < map[c].length; r++){
		if (map[c][r] == '.'){
		    return true;
		}
	    }
	}
	return false;
    }

    static boolean checkColumn(char mark, char[][] map){
	for (int r = 0; r < map[0].length; r++){
	    int count = 0;
	    for (int c = 0; c < map.length; c++){
		if (map[c][r] == 'T' || map[c][r] == mark){
		    count++;
		}
	    }
	    if (count == 4){
		return true;
	    }
	}
	return false;
    }

    static boolean checkRow(char mark, char[][] map){
	for (int c = 0; c < map[0].length; c++){
	    int count = 0;
	    for (int r = 0; r < map.length; r++){
		if (map[c][r] == 'T' || map[c][r] == mark){
		    count++;
		}
	    }
	    if (count == 4){
		return true;
	    }
	}
	return false;
    }

    static boolean checkDiag(char mark, char[][] map){
	int count = 0;
	for (int d = 0; d < map[0].length; d++){
	    if (map[d][d] == 'T' || map[d][d] == mark){
		count++;
	    }
	}
	if (count == 4){
	    return true;
	}
	
	count = 0;
	for (int d = 0; d < map[0].length; d++){
	    if (map[3-d][d] == 'T' || map[3-d][d] == mark){
		count++;
	    }
	}
	if (count == 4){
	    return true;
	}
	return false;
    }

    static void printArray(char[][] map){
	for (int i = 0; i < map.length; i++){
	    System.out.println(Arrays.toString(map[i]));
	}
    }
    
}
