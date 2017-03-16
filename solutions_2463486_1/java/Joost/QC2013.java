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
	
	static final String filename = "Q1/C-large-1";
	int testcases;
	
	public QC2013() throws Exception {
		FileReader ifile = new FileReader(filename+".in");
		Scanner scanner = new Scanner(ifile);
		testcases = (scanner.nextInt());
		FileWriter ofile = new FileWriter(filename+".out");
		for (int i = 1; i <= testcases; i++) {
			ofile.write("Case #"+i+": "+solve(scanner)+(i != testcases ? "\n" : ""));
//            System.out.println(i);
		}
		ofile.close();
		System.out.println("Finished");
	}
	
	private String solve(Scanner scanner) throws Exception {
        long A = scanner.nextLong();
        long B = scanner.nextLong();

        int n = 0;
        boolean flag = true;
        for (long i = (long) Math.sqrt(A); i < 10 && i*i <= B; i++) {
            if (i*i >= A && i*i <= B) {
                if (isPalindrome(i*i)) {
//                    System.out.print(i+"("+(i*i)+")");
                    n++;
                }
            }
        }
        for (int i = 1; flag; i++) {
            int l = (int)Math.log10(i)+1;
            long l10 = (long) Math.pow(10, l);
            long l10plus1 = l10*10;
            long q0 = i * l10 + reverse(i);
            long q1 = i * l10plus1 + reverse(i);
            for (int j = 0; j <= 9; j++) {
                long pal = q1 + j * l10;
                if (pal*pal > B)
                    break;
                if (pal*pal >= A && isPalindrome(pal*pal)) {
//                    System.out.print(pal+"("+(pal*pal)+")");
                    n++;
                }
            }
            if (q0*q0 > B) {
                flag = false;
            }
            else if (q0*q0 >= A && isPalindrome(q0*q0)) {
//                System.out.print(q0+"("+(q0*q0)+")");
                n++;
            }
        }
        
//        System.out.println();
        
        /*int n2 = 0;
        for (long i = (long) Math.sqrt(A); i <= (long) Math.sqrt(B) + 1; i++) {
            if (i*i >= A && i*i <= B) {
                if (isPalindrome(i) && isPalindrome(i*i)) {
                    n2++;
                    System.out.println(i);
                }
            }
        }
        if (n != n2) {
            System.out.println(n+"!"+n2+": "+A+" - "+B);
        }*/
        return ""+n;
    }
    
    private boolean isPalindrome(long N) {
        return reverse(N) == N;
    }

    private long reverse(long n) {
        long rev = 0;
        while (n > 0)
        {
             long d = n % 10;
             rev = rev * 10 + d;
             n /= 10;
        }
        return rev;
    }
    
	
}
