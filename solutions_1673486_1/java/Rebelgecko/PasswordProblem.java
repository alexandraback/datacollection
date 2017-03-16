import java.io.BufferedOutputStream;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

class testcase {
	public int completed,remaining,total;
	double probbad;
	public double min;
	ArrayList<Double> probs;
	
	testcase(int completed, int total, ArrayList<Double> probs) {
		this.completed = completed;
		this.total = total;
		this.remaining = total-completed;
		this.probs = probs;
		probbad = probBad();
		min = EVfinishasis();
		double doover = EVdoover();
		if (doover < min) min = doover;
		double deleteev = EVdelete();
		if (deleteev < min) min = deleteev;
	}

	private double EVdelete() {
		double min = 999999;
		for (int i=0;i<completed;i++) {
			double ev = evifdeleting(i);
			if (ev < min) min = ev;
		}
		return min;
	}
	private double evifdeleting(int i) {
		double strokes = i;
		double probGood = probGoodInRange(0,completed-i);
		strokes += probGood * (i + remaining + 1);
		strokes += (1-probGood) * (i + remaining + 1 + total + 1);
		return strokes;
	}
	private double EVfinishasis() {
		double strokes = 0;
		strokes += (probbad*(remaining + 1 + total + 1));
		strokes += (1-probbad) * (remaining + 1);
		return strokes;
	}
	
	private double EVdoover() {
		if (probbad == 0 && remaining == 0) return 1;
		double strokes = 0;
		strokes += probbad * (1 + total + 1);
		strokes += (1-probbad) * (1 + total + 1);
		return strokes;
	}
	
	private double probBad() {
		return (1-probPerfect());
	}
	private double probPerfect() {
		return probGoodInRange(0,completed);
	}
	private double probGoodInRange(int start, int finish) {	
		double p = 1;
		for (int i=start;i<finish;i++) {
			p *= probs.get(i);
		}
		return p;
	}
}

public class PasswordProblem {

	final static String inputfile = "inputs.txt",outfile = "output.txt";
	static HashMap<Integer,Integer> maxifnotsurprising,maxifsurprising;


	public static void main(String[] args) {
		ArrayList<testcase> cases = new ArrayList<testcase>();
		Scanner sc = null;
		try {
			sc = new Scanner(new File(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("OHONEZ");
		}
		int numtestcases = sc.nextInt();
		for (int i=0;i<numtestcases;i++) {
			int completed = sc.nextInt();
			int remaining = sc.nextInt();
			ArrayList<Double> probs = new ArrayList<Double>();
			for (int j=0;j<completed;j++) probs.add(sc.nextDouble());
			cases.add(new testcase(completed, remaining, probs));
		}
		//for (testcase c : cases) System.out.println(c.min);
		FileWriter fstream = null;
		try {
			fstream = new FileWriter(outfile);
			BufferedWriter out = new BufferedWriter(fstream);
			for (int i=0;i<cases.size();i++) {
				System.out.println("Case #"+(i+1)+": "+cases.get(i).min);
				out.write("Case #"+(i+1)+": "+cases.get(i).min+"\n");
			}
			out.close();
		} catch (IOException e) {}

	}

}
