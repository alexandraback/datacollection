import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.List;
import java.util.Locale;
import java.util.Scanner;

public class Fractiles {
    static Scanner in;
    static PrintStream out;

    static void solve(int caseNb) {
	int k = in.nextInt();
	int c = in.nextInt();
	int s = in.nextInt();

	String res = "1";
	//Small case s==k
	for (int i = 2; i <= s; i++) {
	    res += " " + i;
	}

	out.println(String.format("Case #%d: %s", caseNb + 1, res));
    }

    public static void main(String[] args) throws FileNotFoundException {
	Locale.setDefault(new Locale("en", "US"));
	 in = new Scanner(new FileInputStream("inputs/D-small-attempt0.in"));
	 out = new PrintStream("outputs/D-small-attempt0.out");

//	in = new Scanner(System.in);
//	out = System.out;

	int cases = in.nextInt();
	in.nextLine();
	for (int i = 0; i < cases; i++)
	    solve(i);
    }

}