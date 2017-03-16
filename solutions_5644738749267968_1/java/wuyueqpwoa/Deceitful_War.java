import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.TreeSet;

public class Deceitful_War {

	private Scanner sc = new Scanner(System.in);
	private PrintStream ps = new PrintStream(System.out);

	public void setIO(InputStream is, OutputStream os) {
		sc = new Scanner(is);
		ps = new PrintStream(os);
	}

	public boolean findAndRemove(TreeSet<Double> setOfNaomi, double d) {
		for (double max : setOfNaomi) {
			if (max > d) {
				setOfNaomi.remove(max);
				return true;
			}
		}

		setOfNaomi.pollFirst();
		return false;
	}

	public void solve() throws FileNotFoundException {
		int cases = sc.nextInt();

		for (int tCases = 1; tCases <= cases; ++tCases) {
			int n = sc.nextInt();
			ArrayList<Double> listOfNaomi = new ArrayList<>();
			ArrayList<Double> listOfKen = new ArrayList<>();
			TreeSet<Double> setOfNaomi = new TreeSet<>();
			TreeSet<Double> setOfKen = new TreeSet<>();

			for (int i = n; i > 0; --i) {
				Double d = sc.nextDouble();
				listOfNaomi.add(d);
				setOfNaomi.add(d);
			}

			for (int i = n; i > 0; --i) {
				Double d = sc.nextDouble();
				listOfKen.add(d);
				setOfKen.add(d);
			}

			int countDeceitfulWar = 0, countWar = 0;

			for (double d : listOfKen) {
				if (findAndRemove(setOfNaomi, d)) {
					++countDeceitfulWar;
				}
			}

			for (double d : listOfNaomi) {
				if (!findAndRemove(setOfKen, d)) {
					++countWar;
				}
			}

			ps.println("Case #" + tCases + ": " + countDeceitfulWar + " "
					+ countWar);
		}

		sc.close();
	}

	public static void main(String[] args) throws FileNotFoundException {
		InputStream is = new FileInputStream("Problems\\Deceitful_War\\D-large.in");
		OutputStream os = new FileOutputStream("Problems\\Deceitful_War\\D-large.out");

		Deceitful_War solver = new Deceitful_War();
		solver.setIO(is, os);
		solver.solve();
	}
}
