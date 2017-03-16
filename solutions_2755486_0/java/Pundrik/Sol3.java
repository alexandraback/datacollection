package r1;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;

public class Sol3 {
	public static BufferedWriter log = null;

	public static void main(String[] args) throws IOException {

		long startTime = System.nanoTime();
		Scanner sip = null;
		BufferedWriter brop = null;
		try {
			String ipfile = "C-small-attempt0.in";

			log = new BufferedWriter(new FileWriter(
					"X:\\Un-official\\programming\\CJ13\\R1\\3\\log.txt"));

			sip = new Scanner(new File(
					"X:\\Un-official\\programming\\CJ13\\R1\\3\\" + ipfile));

			// create output file
			brop = new BufferedWriter(new FileWriter(
					"X:\\Un-official\\programming\\CJ13\\R1\\3\\output.txt"));

			int T = sip.nextInt();

			int d = 0;// day
			int n = 0;// number of attacks
			int w = 0;// west
			int e = 0;// east
			int s = 0;// strength
			int dd = 0;
			int dp = 0;
			int ds = 0;
			ArrayList<Attack> alAttack = null;
			Attack aSort = new Attack();
			Wall wall = new Wall();

			int ans = 0;

			for (int i = 0; i < T; i++) {
				log.write("Case #" + (i + 1) + ": \n");
				alAttack = new ArrayList<Attack>();
				wall.reset();
				int nT = sip.nextInt();

				for (int tn = 0; tn < nT; tn++) {
					d = sip.nextInt();
					n = sip.nextInt();
					w = sip.nextInt();
					e = sip.nextInt();
					s = sip.nextInt();
					dd = sip.nextInt();
					dp = sip.nextInt();
					ds = sip.nextInt();

					for (int attack = 0; attack < n; attack++) {
						alAttack.add(new Attack(d + attack * dd, w + attack
								* dp, e + attack * dp, s + attack * ds));
					}

					log.write(d + " " + n + " " + w + " " + e + " " + s + " "
							+ dd + " " + dp + " " + ds + "\n");
				}
				// sort arraylist based on days
				Collections.sort(alAttack, aSort);
				log.write("sorted attack:\n");
				for (Attack a : alAttack) {
					log.write(a + "\n");
				}

				ans = countSuccess(alAttack, wall);

				// print output
				brop.write("Case #" + (i + 1) + ": " + ans);
				if (i < T - 1)
					brop.write("\n");
			}
			long endTime = System.nanoTime();
			log.write("\nTotal execution time: " + (endTime - startTime)
					+ " nano seconds");
			log.write("\nTotal execution time: " + (endTime - startTime)
					/ 1000.0 + " micro seconds");
			log.write("\nTotal execution time: " + (endTime - startTime)
					/ 1000000.0 + " milli seconds");
			log.write("\nTotal execution time: " + (endTime - startTime)
					/ 1000000000.0 + " seconds");

		} catch (Exception e) {
			e.printStackTrace();
		} finally {
			System.out.println("Finally executed");
			if (sip != null)
				sip.close();
			if (brop != null) {
				brop.flush();
				brop.close();
			}
			if (log != null) {
				log.flush();
				log.close();
			}
		}
	}

	private static int countSuccess(ArrayList<Attack> alAttack, Wall wall)
			throws IOException {
		int success = 0;
		int prevDay = -1;
		int startAttacki = -1;

		for (int i = 0; i < alAttack.size(); i++) {
			Attack attack = alAttack.get(i);

			if (attack.day != prevDay) {
				wall.build(alAttack, startAttacki, i - 1);
				prevDay = attack.day;
				startAttacki = i;
			}

			if (wall.isSuccess(attack)) {
				log.write("Success: " + attack + "\n");
				success++;
			}
		}

		return success;
	}
}

class Wall {
	HashMap<Integer, Integer> wall;

	public Wall() {
		super();
		reset();
	}

	public void build(ArrayList<Attack> alAttack, int startAttacki,
			int endAttacki) {

		if (startAttacki == -1 || endAttacki == -1)
			return;

		while (startAttacki <= endAttacki) {
			Attack attack = alAttack.get(startAttacki);

			for (int co = attack.west; co < attack.east; co++) {
				if (wall.containsKey(co)) {
					if (wall.get(co) < attack.strength)
						wall.put(co, attack.strength);
				} else {
					wall.put(co, attack.strength);
				}
			}
			startAttacki++;
		}
	}

	public void reset() {
		wall = new HashMap<Integer, Integer>();
	}

	public boolean isSuccess(Attack attack) {
		System.out.println("isSuccess method: " + attack);
		for (int i = attack.west; i < attack.east; i++) {
			if (wall.containsKey(i)) {
				if (wall.get(i) < attack.strength) {
					return true;
				}
			} else {
				return true;
			}
		}
		return false;
	}
}

class Attack implements Comparator<Attack> {
	int day;
	int west;
	int east;
	int strength;

	public Attack(int day, int west, int east, int strength) {
		super();
		this.day = day;
		this.west = west;
		this.east = east;
		this.strength = strength;
	}

	public Attack() {
		// TODO Auto-generated constructor stub
	}

	public int getDay() {
		return day;
	}

	public void setDay(int day) {
		this.day = day;
	}

	public int getWest() {
		return west;
	}

	public void setWest(int west) {
		this.west = west;
	}

	public int getEast() {
		return east;
	}

	public void setEast(int east) {
		this.east = east;
	}

	public int getStrength() {
		return strength;
	}

	public void setStrength(int strength) {
		this.strength = strength;
	}

	@Override
	public int compare(Attack a0, Attack a1) {
		return a0.day - a1.day;
	}

	@Override
	public String toString() {
		// TODO Auto-generated method stub
		return day + " " + west + " " + east + " " + strength;
	}

}