package googlecodejam;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.LinkedList;
import java.util.List;

public class TheGreatWall {
	public static void main(String[] args) throws Exception {
		File f = new File("/Users/peter/Downloads/C-small-attempt0.in");
		BufferedReader br = new BufferedReader(new FileReader(f));

		String outputFile = f.getName().substring(0, f.getName().lastIndexOf('.')) + ".out";
		 PrintStream ps = new PrintStream(new File(f.getParent(), outputFile));
//		PrintStream ps = System.out;

		int N = Integer.parseInt(br.readLine());

		for (int caseCount = 1; caseCount <= N; caseCount++) {
			String line = br.readLine();

			int totalAttacks = 0;
			List<Tribe> tribes = new LinkedList<Tribe>();
			int amountOfTribes = Integer.valueOf(line);
			for (int tribe = 0; tribe < amountOfTribes; tribe++) {
				String[] values = br.readLine().split(" ");
				Tribe t = new Tribe();
				tribes.add(t);

				t.dayOfFirstAttack = Integer.valueOf(values[0]);
				t.numberOfAttacks = Integer.valueOf(values[1]);
				totalAttacks += t.numberOfAttacks;
				t.westMostOfFirstAttack = Integer.valueOf(values[2]);
				t.eastMostOfFirstAttack = Integer.valueOf(values[3]);
				t.strengthOfFirstAttack = Integer.valueOf(values[4]);
				t.daysBetweenAttacks = Integer.valueOf(values[5]);
				t.distanceToEastEachAttack = Integer.valueOf(values[6]);
				t.changeInStrengthEachAttack = Integer.valueOf(values[7]);
			}

			long solution = calculateValue(tribes, totalAttacks);

			ps.print("Case #" + caseCount + ": ");

			ps.print("" + solution);

			ps.println();
		}

		br.close();
		ps.close();
	}

	private static long calculateValue(List<Tribe> tribes, int totalAttacks) {
		List<Attack> attacks = new ArrayList<Attack>(totalAttacks);

		for (Tribe t : tribes) {
			int westPos = t.westMostOfFirstAttack;
			int size = t.eastMostOfFirstAttack - t.westMostOfFirstAttack;
			int strength = t.strengthOfFirstAttack;
			int day = t.dayOfFirstAttack;
			for (int i = 0; i < t.numberOfAttacks; i++) {
				attacks.add(new Attack(day, westPos, westPos + size, strength));

				westPos += t.distanceToEastEachAttack;
				strength += t.changeInStrengthEachAttack;
				day += t.daysBetweenAttacks;
			}
		}

		Collections.sort(attacks);

//		System.out.println(attacks);

		long successes = 0;
		for (int i = 0; i < attacks.size(); i++) {
			Attack attack1 = attacks.get(i);
			if (attack1.successful)
				successes++;
//			else
//				System.out.println("unsuccessful " + attack1);
			for (int j = i + 1; j < attacks.size(); j++) {
				Attack attack2 = attacks.get(j);

				if (attack2.successful) {
					if (attack2.day > attack1.day) {
						if (attack2.strength <= attack1.strength) {
							attack2.remove(attack1);
						}
					}
				}
			}
		}

		return successes;
	}

	private static class Attack implements Comparable<Attack> {
		List<Integer> indices;

		public Attack(int day, int westMost, int eastMost, int strength) {
			this.day = day;
			indices = new LinkedList<Integer>();
			for (int i = westMost * 2; i <= eastMost * 2; i++) {
				indices.add(i);
			}
			this.strength = strength;

			successful = true;
		}

		public void remove(Attack attack1) {

			for (Integer i : attack1.indices) {
				indices.remove((Integer) i);
			}

//			System.out.println("remaining indices: " + indices + " after removing " + attack1.indices);

			if (indices.size() == 0) {
				successful = false;
			}
		}

		public boolean successful;
		public int day;
		public int strength;

		@Override
		public int compareTo(Attack o) {

			return this.day - o.day;
		}

		@Override
		public String toString() {
			return "Attack(" + day + "," + indices + ")";
		}
	}

	private static class Tribe {
		public int dayOfFirstAttack;
		public int numberOfAttacks;
		public int westMostOfFirstAttack;
		public int eastMostOfFirstAttack;
		public int strengthOfFirstAttack;
		public int daysBetweenAttacks;
		public int distanceToEastEachAttack;
		public int changeInStrengthEachAttack;
	}
}
