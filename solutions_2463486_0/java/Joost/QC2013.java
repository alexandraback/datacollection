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

public class QC2013 {

	public static void main(String[] args) throws Exception {
		new QC2013();
	}
	
	static final String filename = "Q1/C-small-attempt0";
	int testcases;
	
	public QC2013() throws Exception {
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
        int A = scanner.nextInt();
        int B = scanner.nextInt();
        int n = 0;
        for (int i = (int) Math.sqrt(A); i <= (int) Math.sqrt(B) + 1; i++) {
            if (i*i >= A && i*i <= B) {
                if (isPalindrome(i) && isPalindrome(i*i))
                    n++;
            }
        }
        return ""+n;
    }
    
    private boolean isPalindrome(int N) {
        int n = N;
        int rev = 0;
        while (n > 0)
        {
             int d = n % 10;
             rev = rev * 10 + d;
             n /= 10;
        }
        return rev == N;
    }
    
	
}
