import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedHashSet;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Set;
import java.util.StringTokenizer;

public class GreatWall {
	private static String PROG_NAME = GreatWall.class.getSimpleName();
	private static PrintWriter out;

	public static void main(String[] args) throws Exception {
		main(new FileReader(PROG_NAME + ".small.in"), new FileWriter(PROG_NAME + ".small.out"));
		// main(new FileReader(PROG_NAME + ".large.in"), new
		// FileWriter(PROG_NAME + ".large.out"));
	}

	public static String caseStr(int caseId) {
		return "Case #" + caseId + ":";
	}

	public static void main(FileReader fileReader, FileWriter fileWriter) throws Exception {
		long start = System.currentTimeMillis();
		BufferedReader f = new BufferedReader(fileReader);
		out = new PrintWriter(new BufferedWriter(fileWriter));
		Integer caseCount = Integer.parseInt(f.readLine());
		for (int caseId = 1; caseId <= caseCount; caseId++) {
			Wall wall = new Wall();

			StringTokenizer st = new StringTokenizer(f.readLine());
			int N = Integer.parseInt(st.nextToken());
			Tribe[] tribes = new Tribe[N];
			PriorityQueue<Tribe> tribeAttackQueue = new PriorityQueue<>();
			for (int i = 0; i < tribes.length; i++) {
				st = new StringTokenizer(f.readLine());
				Tribe tribe = new Tribe();
				tribe.firstAttackDay = Integer.parseInt(st.nextToken());
				tribe.numberOfAttacks = Integer.parseInt(st.nextToken());
				tribe.westPoint = Integer.parseInt(st.nextToken());
				tribe.eastPoint = Integer.parseInt(st.nextToken());
				tribe.strength = Integer.parseInt(st.nextToken());
				tribe.deltaDay = Integer.parseInt(st.nextToken());
				tribe.deltaDistance = Integer.parseInt(st.nextToken());
				tribe.deltaStrength = Integer.parseInt(st.nextToken());

				tribeAttackQueue.add(tribe);
			}

			int successfullAttacks = 0;
			while (!tribeAttackQueue.isEmpty()) {
				Set<Tribe> tribesAttackingToday = new LinkedHashSet<>();
				Tribe t = tribeAttackQueue.poll();
				tribesAttackingToday.add(t);
				int today = t.nextAttackDay();
				while (!tribeAttackQueue.isEmpty() && tribeAttackQueue.peek().nextAttackDay() == today) {
					tribesAttackingToday.add(tribeAttackQueue.poll());
				}

				Set<WallPart> successfulToday = new LinkedHashSet<>();
				for (Tribe tribe : tribesAttackingToday) {
					WallPart attackRange = new WallPart();
					int currDeltaDistance = tribe.deltaDistance * tribe.attackCount;
					attackRange.west = tribe.westPoint + currDeltaDistance;
					attackRange.east = tribe.eastPoint + currDeltaDistance;
					attackRange.strength = tribe.strength + tribe.deltaStrength * tribe.attackCount;

					boolean attackBlocked = false;
					for (Integer wallStrength : wall.wallParts.keySet()) {
						if (wallStrength < attackRange.strength) {
							continue;
						}
						Set<WallPart> wallParts = wall.wallParts.get(wallStrength);
						for (WallPart wallPart : wallParts) {
							if (attackRange.west >= wallPart.west && attackRange.east <= wallPart.east) {
								attackBlocked = true;
								break;
							}
						}
						if (attackBlocked) {
							break;
						}
					}
					if (!attackBlocked) {
						successfullAttacks++;
						successfulToday.add(attackRange);
					}

					tribe.attackCount++;
					if (tribe.attackCount < tribe.numberOfAttacks) {
						tribeAttackQueue.add(tribe);
					}
				}

				wall.build(successfulToday);

			}

			System.out.println(caseStr(caseId) + " " + successfullAttacks);
			out.println(caseStr(caseId) + " " + successfullAttacks);
		}
		System.out.println(System.currentTimeMillis() - start);
		out.close(); // close the output file
	}

	private static class Tribe implements Comparable<Tribe> {
		int firstAttackDay;
		int numberOfAttacks;
		int westPoint;
		int eastPoint;
		int strength;
		int deltaDay;
		int deltaDistance;
		int deltaStrength;

		int attackCount = 0;

		@Override
		public int compareTo(Tribe o) {
			return Integer.compare(this.nextAttackDay(), o.nextAttackDay());
		}

		private int nextAttackDay() {
			return this.attackCount * this.deltaDay + this.firstAttackDay;
		}

		@Override
		public String toString() {
			return "di: " + firstAttackDay + "; ni: " + numberOfAttacks + "; wi: " + westPoint + "; ei: " + eastPoint
					+ "; si: " + strength + "; delta_di: " + deltaDay + "; delta_pi: " + deltaDistance + "; delta_si: "
					+ deltaStrength;
		}
	}

	private static class Wall {
		Map<Integer, Set<WallPart>> wallParts = new HashMap<Integer, Set<WallPart>>();

		public void build(Set<WallPart> successfulToday) {
			for (WallPart attackRange : successfulToday) {

				if (!wallParts.containsKey(attackRange.strength)) {
					LinkedHashSet<WallPart> parts = new LinkedHashSet<WallPart>();
					for (Integer wallStrength : wallParts.keySet()) {
						if (wallStrength > attackRange.strength) {
							for (WallPart wallPart : wallParts.get(wallStrength)) {
								WallPart newPart = new WallPart();
								newPart.west = wallPart.west;
								newPart.east = wallPart.east;
								newPart.strength = attackRange.strength;
								parts.add(newPart);
							}

						}
					}

					wallParts.put(attackRange.strength, parts);
				}

				for (Integer wallStrength : wallParts.keySet()) {
					if (wallStrength > attackRange.strength) {
						continue;
					}

					Set<WallPart> current = wallParts.get(wallStrength);
					Set<WallPart> newWallParts = new LinkedHashSet<>();
					int newWest = attackRange.west;
					int newEast = attackRange.east;
					for (WallPart wallPart : current) {
						boolean collides = false;
						if (wallPart.west >= attackRange.west && wallPart.west <= attackRange.east) {
							newEast = Math.max(newEast, wallPart.east);
							collides = true;
						}
						if (wallPart.east <= attackRange.east - 1 && wallPart.east >= attackRange.west) {
							newWest = Math.min(newWest, wallPart.west);
							collides = true;
						}
						if (!collides) {
							newWallParts.add(wallPart);
						}
					}
					WallPart newWallPart = new WallPart();
					newWallPart.east = newEast;
					newWallPart.west = newWest;
					newWallPart.strength = wallStrength;
					newWallParts.add(newWallPart);
					wallParts.put(wallStrength, newWallParts);
				}

			}
		}
	}

	private static class WallPart {
		int east;
		int west;
		int strength;

		@Override
		public String toString() {
			return west + ":" + east + "|" + strength;
		}
	}
}
