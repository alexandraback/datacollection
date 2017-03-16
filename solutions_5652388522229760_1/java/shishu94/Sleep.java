import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Sleep {
    static Scanner in;
    static PrintStream out;

    static void solve(int caseNb) {
	long n = in.nextInt();

	String res = "INSOMNIA";
	if (n > 0) {
	    boolean[] digits = new boolean[10];
	    boolean done = false;
	    int i = 0;
	    while (!done) {
		i++;
		long c = i * n;
		while (c > 0) {
		    digits[(int) (c % 10)] = true;
		    c /= 10;
		}
		done = digits[0];
		for (boolean bol : digits) {
		    done = done && bol;
		}
	    }
	    res= ""+(i*n);
	}
	out.println(String.format("Case #%d: %s", caseNb + 1, res));
    }

    public static void main(String[] args) throws FileNotFoundException {
	Locale.setDefault(new Locale("en", "US"));
	in = new Scanner(new FileInputStream("inputs/A-large.in"));
	out = new PrintStream("outputs/A-large.out");

//	 in = new Scanner(System.in);
//	 out = System.out;

	int cases = in.nextInt();
	in.nextLine();
	for (int i = 0; i < cases; i++)
	    solve(i);
    }

}