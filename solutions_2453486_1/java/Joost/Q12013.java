package gcj2013;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class Q12013 {

	public static void main(String[] args) throws Exception {
		new Q12013();
	}
	
	static final String filename = "Q1/A-large";
	int testcases;
	
	public Q12013() throws Exception {
		FileReader ifile = new FileReader(filename+".in");
		Scanner scanner = new Scanner(ifile);
		testcases = (scanner.nextInt());
		FileWriter ofile = new FileWriter(filename+".out");
		for (int i = 1; i <= testcases; i++) {
			ofile.write("Case #"+i+": "+solve(scanner)+(i != testcases ? "\n" : ""));
		}
		ofile.close();
		System.out.println("Finished");
	}
	
	private String solve(Scanner scanner) throws Exception {
        scanner.nextLine();
		char[][] b = new char[4][4];
        for (int i = 0; i < 4; i++) {
            String t = scanner.nextLine();
            b[i] = t.toCharArray();
        }
        char[] c = {'O', 'X'};
        for (int i = 0; i < 2; i++) {
            if (checkHoriz(b, c[i]) || checkDiag(b, c[i]) || checkVert(b, c[i])) {
                return c[i]+" won";
            }
        }
        if (checkDraw(b)) {
            return "Draw";
        }
        return "Game has not completed";
    }
    
    private void printBoard(char[][] b) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                System.out.print(b[i][j]);
            }
            System.out.println();
        }
    }
    
    private boolean checkHoriz(char[][] b, char c) {
        rowloop:
        for (int i = 0; i < 4; i++) { 
            for (int j = 0; j < 4; j++) {
                if (b[i][j] != c && b[i][j] != 'T') {
                    continue rowloop;
                }
            }
            return true;
        }
        return false;
    }
    
    private boolean checkVert(char[][] b, char c) {
        rowloop:
        for (int i = 0; i < 4; i++) { 
            for (int j = 0; j < 4; j++) {
                if (b[j][i] != c && b[j][i] != 'T') {
                    continue rowloop;
                }
            }
            return true;
        }
        return false;
    }
    
    private boolean checkDiag(char[][] b, char c) {
        rowloop:
        for (int i = 0; i < 2; i++) { 
            for (int j = 0; j < 4; j++) {
                if (b[j][i == 0 ? j : 3-j] != c && b[j][i == 0 ? j : 3 - j] != 'T') {
                    continue rowloop;
                }
            }
            return true;
        }
        return false;
    }

    private boolean checkDraw(char[][] b) {
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 4; j++) {
                if (b[i][j] == '.') {
                    return false;
                }
            }
        }
        return true;
    }
    
    
	
}
