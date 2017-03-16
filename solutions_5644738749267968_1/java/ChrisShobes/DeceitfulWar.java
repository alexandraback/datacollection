package codejam2014;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class DeceitfulWar {

	public void solve(String file) {
		try {
			Scanner reader = new Scanner(new File(file));
			reader.nextLine(); // skip first line
			int i = 1;
			String[] temp;
			Double[] naomi;
			Double[] ken;
			
			while(reader.hasNextLine()) {
				reader.nextLine();
				temp = reader.nextLine().split(" ");
				naomi = new Double[temp.length];
				for(int word = 0; word < temp.length; word++) {
					naomi[word] = Double.parseDouble(temp[word]);
				}
				temp = reader.nextLine().split(" ");
				ken = new Double[temp.length];
				for(int word = 0; word < temp.length; word++) {
					ken[word] = Double.parseDouble(temp[word]);
				}
				System.out.println("Case #" + i + ": " + solve(naomi, ken));
				i++;
			}
		} 
		catch (FileNotFoundException e) {
		// TODO Auto-generated catch block
		e.printStackTrace();
		}
	}
	private String solve(Double[] naomi, Double[] ken) {
		// sort the 2 arrays
		// go from least to greatest for naomi
		Arrays.sort(naomi);
		Arrays.sort(ken);
		ArrayList<Double> n = new ArrayList(Arrays.asList(naomi));
		ArrayList<Double> k = new ArrayList(Arrays.asList(ken));
		
		int normalWins = 0;
		double other;
		for(int i = n.size() - 1; i >= 0; i--) {
			other = pickBetterThan(n.get(i), k);
			if(other < n.get(i)) {
				normalWins++;
			}
			n.remove(i);
		}
		
		n = new ArrayList(Arrays.asList(naomi));
		k = new ArrayList(Arrays.asList(ken));
		
		int betterWins = 0;
		int currBetterWins = 0;
		int len = n.size();
		double currN, currK;
		for(int repeat = 0; repeat < len; repeat++) {
			for(int i = n.size() - 1; i >= 0; i--) {
				currN = n.get(i);
				currK = k.get(i);
				if(n.get(i) > k.get(i)) {
					currBetterWins++;
				}
			}
			if(currBetterWins > betterWins) {
				betterWins = currBetterWins;
			}
			currBetterWins = 0;
			n.remove(0);
			if(!k.isEmpty()) {
				k.remove(k.size() - 1);
			}
		}
		
		
		return betterWins + " " + normalWins;
	}
	
	private double pickBetterThan(Double n, ArrayList<Double> k) {
		double bestOption = 2.0;
		int indexOfBest = 0;
		
		double curr;
		for(int i =  k.size() - 1; i >= 0; i--) {
			curr = k.get(i);
			if( curr > n && k.get(i) < bestOption) {
				bestOption = k.get(i);
				indexOfBest = i;
			}
		}
		bestOption = k.remove(indexOfBest);	
		return bestOption;
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		
		DeceitfulWar test = new DeceitfulWar();
		test.solve("D-large.in");
		//Double[] a = new Double[]{0.186, 0.389, 0.907, 0.832, 0.959, 0.557, 0.300, 0.992, 0.899};
		//ArrayList<Double> aD = new ArrayList(Arrays.asList(a));
		//System.out.println(test.pickBetterThan(0.5, aD));
		/*
		
		double[] b = new double[]{0.916, 0.728, 0.271, 0.520, 0.700, 0.521, 0.215, 0.341, 0.458};
		double[] d = new double[b.length - 1];
		double[] e = new double[b.length - 1];
		
		Arrays.sort(a);
		Arrays.sort(b);
		System.arraycopy(b, 1, d, 0, b.length - 1);
		System.arraycopy(b, 0, e, 0, b.length - 1);
		for(Double c : a) {
		//	System.out.println(c);
		}
		System.out.println();
		for(Double c : b) {
			System.out.print(c + " ");
		}
		System.out.println();
		for(Double c : d) {
			System.out.print(c + " ");
		}
		System.out.println();
		for(Double c : e) {
			System.out.print(c + " ");
		}
		*/
	}

}
