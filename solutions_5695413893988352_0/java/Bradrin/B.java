import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	
	public void solve(Scanner scan, PrintWriter out) {
	    char[] a = scan.next().toCharArray();
	    char[] b = scan.next().toCharArray();
	    
	    for (int i = 0; i < a.length; i++) {
	        if (a[i] == '?' && b[i] == '?') {
	            if (i == a.length - 1) {
	                a[i] = '0';
	                b[i] = '0';
	                continue;
	            }
	            if (a[i+1] == '?' || b[i+1] == '?') {
                    a[i] = '0';
                    b[i] = '0';
                    continue;
	            }
                int aValue = a[i+1] - '0';
                int bValue = b[i+1] - '0';
                if (aValue - bValue > 10 + bValue - aValue) {
                    a[i] = '0';
                    b[i] = '1';
                    continue;
                }
                if (bValue - aValue > 10 + aValue - bValue) {
                    a[i] = '1';
                    b[i] = '0';
                    continue;
                }
	            if (Math.abs(aValue - bValue) == Math.abs(bValue - aValue)) {
	                a[i] = '0';
	                b[i] = '0';
	                continue;
	            }
	            throw new RuntimeException();
	        }
            if (a[i] == '?' && b[i] != '?') {
                a[i] = b[i];
                continue;
            }
            if (a[i] != '?' && b[i] == '?') {
                b[i] = a[i];
                continue;
            }
            if (a[i] == b[i]) {
                continue;
            }
            if (a[i] > b[i]) {
                fill(a, i+1, '0');
                fill(b, i+1, '9');
                break;
            }
            if (a[i] < b[i]) {
                fill(a, i+1, '9');
                fill(b, i+1, '0');
                break;
            }
            throw new RuntimeException();
	    }
	    
	    for (char c : a) {
	        System.out.print(c);
	        out.print(c);
	    }
	    System.out.print(" ");
	    out.print(" ");
	    for (char c : b) {
            System.out.print(c);
            out.print(c);
	    }
	    
	    System.out.println();
	    out.println();
	}
	
	public void fill(char[] c, int index, char value) {
	    for (int i = index; i < c.length; i++) {
	        if (c[i] == '?') {
	            c[i] = value;
	        }
	    }
	}
	
    public static void main(String[] args) throws Exception {
		String filename = "B-small-attempt2";
        Scanner scan = new Scanner(new FileReader(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new B().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}