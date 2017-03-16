package codejam2014;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.PrintStream;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.HashSet;

import util.InputReader;

public class DeceitfulWar implements Runnable{
	private InputReader in;
	private PrintWriter out;
	private static String delimiter = " ";

	public static void main(String[] args) {
		new Thread(new DeceitfulWar()).start();
	}

	public DeceitfulWar(){
		try{
			BufferedReader buffer = new BufferedReader(new FileReader("d:\\D-small-attempt0.in"));
			in = new InputReader(buffer);
			System.setOut(new PrintStream(new FileOutputStream("d:\\output.txt")));
			out = new PrintWriter(System.out);
		} catch (FileNotFoundException e) {
			throw new RuntimeException();
		}
	}

	@Override
	public void run() {
		int numTests = in.readInt();

		for (int testNumber = 0; testNumber < numTests; testNumber++) {
			out.print("Case #" + (testNumber + 1) + ": ");
			// handle inputs
			int count = in.readInt();
			String line1 = in.readString();
			String line2 = in.readString();
			
			double[] p1 = getVector(line1, count);
			double[] p2 = getVector(line2, count);
			
			int y = calcDeceifulWar(p1, p2);
			int z = calcWar(p1, p2);
			
			StringBuilder sb = new StringBuilder();
			sb.append(y + " " + z);			
			out.println(sb.toString().trim());
		}
		out.close();
	}
	
	private int calcWar(double[] p1, double[] p2) {
		int score = 0;
		if(p1.length == 1) {
			if(p1[0] > p1[0])
				score++;
			return score;
		}
		
		HashSet<Double> ken = new HashSet<Double>();
		for(double j: p2)
			ken.add(j);
		
		for(int i=p1.length-1; i>=0; i--) {
			double max = p1[i];
			double ken_pick = 0;
			for(double n: ken)
				if(n>max) {
					score++;
					ken_pick = n;
					break;
				}
			ken.remove(ken_pick);
		}
		return p1.length - score;
	}

	private int calcDeceifulWar(double[] p1, double[] p2) {
		
		int score = 0;
		if(p1.length == 1) {
			if(p1[0] > p1[0])
				score++;
			return score;
		}
		
		HashSet<Double> naomi = new HashSet<Double>();
		for(double i: p1)
			naomi.add(i);
		
		for(int i=p2.length-1; i>=0; i--) {
			double max = p2[i];
			double naomi_pick = 0;
			for(double n: naomi)
				if(n>max) {
					score++;
					naomi_pick = n;
					break;
				}
			naomi.remove(naomi_pick);
		}
		return score;
	}

	private double[] getVector(String line, int count) {
		
		String[] strVector = line.split(delimiter);
		double[] array = new double[count];
		
		for(int i=0; i<count; i++) {
			array[i] = Double.parseDouble(strVector[i]);
		}
		
		Arrays.sort(array);		
		return array;
	}
}
