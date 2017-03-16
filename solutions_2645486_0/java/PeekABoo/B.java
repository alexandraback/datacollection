package round1a;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Scanner;

public class B {
	private static final String PATH = "src\\ressources";
	private static final String PROBLEM = "B";
	private static final String VERSION = "small-attempt2"; //small-attempt0
	private static final String EXT_IN = "in";
	private static final String EXT_OUT = "out";
	
	private int max;
	private int[] valAct;
	private int regain;
	private int maxEnergy;
	
	public String solve(Scanner in) {
		max = 0;
		int energy = in.nextInt();
		maxEnergy = energy;
		regain = in.nextInt();
		int nbAct = in.nextInt();
		
		valAct = new int[nbAct];
		for(int i = 0; i < nbAct; i++) {
			valAct[i] = in.nextInt();
		}
		
		doSmth(0, energy, 0);
		
		return String.valueOf(max);
	}
	
	private void doSmth(int i, int energy, int currentVal) {
		if(i < valAct.length) {
			for(int j = 0; j <= energy; j++) {
				if(energy-j+regain <= maxEnergy) {
					doSmth(i+1, energy-j+regain, currentVal + (j*valAct[i]));
				} else {
					doSmth(i+1, maxEnergy, currentVal + (j*valAct[i]));
				}
			}
		} else {
			if(currentVal > max) {
				max = currentVal;
			}
		}
	}
	
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(new FileReader(getCompletPath(EXT_IN)));
		PrintWriter out = new PrintWriter(new FileWriter(getCompletPath(EXT_OUT)));
		
		int nbTestCase = in.nextInt();
		B pb = new B();
		for(int i = 0; i < nbTestCase; i++) {
			out.println("Case #" + (i+1) + ": " + pb.solve(in));
			out.flush();
		}
		
		in.close();
		out.close();
	}
	
	private static String getCompletPath(String ext) {
		return PATH + "\\" + PROBLEM + "-" + VERSION + "." + ext;
	}
}
