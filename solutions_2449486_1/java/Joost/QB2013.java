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

public class QB2013 {

	public static void main(String[] args) throws Exception {
		new QB2013();
	}
	
	static final String filename = "Q1/B-large";
	int testcases;
	
	public QB2013() throws Exception {
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
        int r = scanner.nextInt();
        int c = scanner.nextInt();
		int[][] f = new int[r][c];
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++) {
                f[i][j] = scanner.nextInt();
            }
        int[] maxR = new int[r];
        int[] maxC = new int[c];
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (f[i][j] > maxR[i])
                    maxR[i] = f[i][j];
            }
        }
        for (int i = 0; i < c; i++) {
            for (int j = 0; j < r; j++) {
                if (f[j][i] > maxC[i])
                    maxC[i] = f[j][i];
            }
        }
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (f[i][j] < maxR[i] && f[i][j] < maxC[j])
                    return "NO";
            }
        }
        return "YES";
    }
    
    
	
}
