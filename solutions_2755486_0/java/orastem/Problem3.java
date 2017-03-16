import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;


public class Problem3 {

	static BufferedWriter out;
	static int testCount;
	static final int D = 0;
	static final int N = 1;
	static final int W = 2;
	static final int E = 3;
	static final int S = 4;
	static final int DELTA_D = 5;
	static final int DELTA_P = 6;
	static final int DELTA_S = 7;
	
	static int[] wall = new int[401];
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new FileReader("/Users/blazejczapp/workspace/1C1/src/input2.in"));
		out = new BufferedWriter(new FileWriter("/Users/blazejczapp/workspace/1C1/src/output2.out"));

		String line;
		
		line = br.readLine();
		testCount = Integer.parseInt(line);
		
		for (int i = 0; i < testCount; i++) {
			if (i > 0) {
				out.newLine();
			}
			
			int tribeCount = Integer.parseInt(br.readLine());
			

//		    di - the day of the tribe's first attack (where 1st January, 250BC, is considered day 0)
//		    ni - the number of attacks from this tribe
//		    wi, ei - the westmost and eastmost points respectively of the Wall attacked on the first attack
//		    si - the strength of the first attack
//		    delta_di - the number of days between subsequent attacks by this tribe
//		    delta_pi - the distance this tribe travels to the east between subsequent attacks (if this is negative, the tribe travels to the west)
//		    delta_si - the change in strength between subsequent attacks

			int[][] tribes = new int[tribeCount][8];
			ArrayList<Attack> attacks = new ArrayList<Attack>();
			
			for (int j = 0; j < tribeCount; j++) {
				String[] data = br.readLine().split(" ");
				tribes[j][D] = Integer.parseInt(data[D]);
				tribes[j][N] = Integer.parseInt(data[N]);
				tribes[j][W] = Integer.parseInt(data[W]);
				tribes[j][E] = Integer.parseInt(data[E]);
				tribes[j][S] = Integer.parseInt(data[S]);
				tribes[j][DELTA_D] = Integer.parseInt(data[DELTA_D]);
				tribes[j][DELTA_P] = Integer.parseInt(data[DELTA_P]);
				tribes[j][DELTA_S] = Integer.parseInt(data[DELTA_S]);
				
				extractAttacks(tribes[j], attacks);
			}
			
			wall = new int[401];
			Collections.sort(attacks);
			int successfulAttacks = simulateHistory(attacks);
			
			out.write("Case #" + (i + 1) + ": " + successfulAttacks);
			System.out.println("Case #" + (i + 1) + ": " + successfulAttacks);
		}

		br.close();
		out.close();
	}

	private static void extractAttacks(int[] tribe, ArrayList<Attack> attacks) {
		int day = tribe[D];
		int west = tribe[W];
		int east = tribe[E];
		int strength = tribe[S];
		int delta_dist = tribe[DELTA_P];
		int delta_day = tribe[DELTA_D];
		int delta_s = tribe[DELTA_S];
		
		attacks.add(new Attack(day, east, west, strength));
		
		for (int i = 1; i < tribe[N]; i++) {
			day += delta_day;
			west += delta_dist;
			east += delta_dist;
			strength += delta_s;
			
			attacks.add(new Attack(day, east, west, strength));
		}
	}

	private static int simulateHistory(ArrayList<Attack> attacks) {
		int successfulAttacks = 0;
		ArrayList<Breach> breaches = new ArrayList<Breach>();
		for (int i = 0; i < attacks.size(); i++) {
			Attack attack = attacks.get(i);
			ArrayList<Breach> outcome = willBreach(attack.west, attack.east, attack.strength);
			
			if (outcome.size() != 0) {
				successfulAttacks++;
			}
			
			breaches.addAll(outcome);
			if (attacks.size() <= i + 1 || attacks.get(i + 1).day != attack.day) {
				fixWall(breaches);
				breaches.clear();
			}
		}
		return successfulAttacks;
	}

	private static void fixWall(ArrayList<Breach> breaches) {
		for (Breach breach : breaches) {
			if (wall[breach.position] < breach.height) {
				wall[breach.position] = breach.height;
			}
		}
	}

	private static ArrayList<Breach> willBreach(int west, int east, int strenght) {
		west += 200;
		east += 200;
		ArrayList<Breach> breaches = new ArrayList<Breach>();
		for (int i = west; i < east; i++) {
			if (wall[i] < strenght) {
				breaches.add(new Breach(i, strenght));
			}
		}
		return breaches;
	}
}

class Breach {
	int position, height;
	public Breach(int position, int height) {
		this.position = position;
		this.height = height;
	}
}

class Attack implements Comparable<Attack> {
	
	public int day, east, west, strength;
	
	public Attack(int day, int east, int west, int strength) {
		this.day = day;
		this.east = east;
		this.west = west;
		this.strength = strength;
	}
	
	@Override
	public int compareTo(Attack other) {
		if (other.day < this.day) {
			return 1;
		} else if (other.day > this.day) {
			return -1;
		} else {
			return 0;
		}
	}
}
