import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {
	
	public void solve(Scanner scan, PrintWriter out) {
	    String s = scan.next().toLowerCase();
	    int[] count = new int[26];
	    for (char c : s.toCharArray()) {
	        count[toNum(c)]++;
	    }
	    int[] numbers = new int[10];
	    
	    numbers[0] = count[toNum('z')];
	    numbers[2] = count[toNum('w')];
	    numbers[6] = count[toNum('x')];
	    numbers[8] = count[toNum('g')];

        reduce(count, numbers[0], 'z', 'e', 'r', 'o');
        reduce(count, numbers[2], 't', 'w', 'o');
        reduce(count, numbers[6], 's', 'i', 'x');
        reduce(count, numbers[8], 'e', 'i', 'g', 'h', 't');

        numbers[7] = count[toNum('s')];
        reduce(count, numbers[7], 's', 'e', 'v', 'e', 'n');

        numbers[5] = count[toNum('v')];
        reduce(count, numbers[5], 'f', 'i', 'v', 'e');
        
        numbers[9] = count[toNum('i')];
        reduce(count, numbers[9], 'n', 'i', 'n', 'e');

        numbers[1] = count[toNum('n')];
        reduce(count, numbers[9], 'o', 'n', 'e');
        
        numbers[3] = count[toNum('t')];
        reduce(count, numbers[9], 't', 'h', 'r', 'e', 'e');
        
        numbers[4] = count[toNum('f')];
        reduce(count, numbers[9], 'f', 'o', 'u', 'r');
        
        for (int i = 0; i < 10; i++) {
            for (int j = 0; j < numbers[i]; j++) {
                System.out.print(i);
                out.print(i);
            }
        }

        System.out.println();
	    out.println();
	}
	
	public int toNum(char c) {
	    return c - 'a';
	}
	
	public void reduce(int[] count, int value, char... cs) {
	    for (char c : cs) {
	        count[toNum(c)] -= value;
	    }
	}
	
    public static void main(String[] args) throws Exception {
		String filename = "A-large";
        Scanner scan = new Scanner(new FileReader(filename + ".in"));
        PrintWriter out = new PrintWriter(filename + ".out");
        int problems = scan.nextInt();
        for (int count = 0; count < problems; count++) {
            System.out.print("Case #" + (count+1) + ": ");
            out.print("Case #" + (count+1) + ": ");
            new A().solve(scan, out);
        }
        out.flush();
        out.close();
        scan.close();
    }
	
}