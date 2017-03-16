package b;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Scanner;

public class B {
	static class Prod {
		BigInteger count;
		int type;
	}

	static class State {
		int toyNbr;
		int boxNbr;
		BigInteger usedToys;
		BigInteger usedBoxes;

		public State(int toyNbr, int boxNbr, BigInteger usedToys,
				BigInteger usedBoxes) {
			super();
			this.toyNbr = toyNbr;
			this.boxNbr = boxNbr;
			this.usedToys = usedToys;
			this.usedBoxes = usedBoxes;
		}

		@Override
		public int hashCode() {
			int hash = 17;
			hash *= 31 + toyNbr;
			hash *= 31 + boxNbr;
			hash *= 31 + usedToys.hashCode();
			hash *= 31 + usedBoxes.hashCode();
			return hash;
		}

		@Override
		public boolean equals(Object obj) {
			State other = (State) obj;
			return toyNbr == other.toyNbr && boxNbr == other.boxNbr
					&& usedBoxes.equals(other.usedBoxes)
					&& usedToys.equals(other.usedToys);
		}

	}

	private static ArrayList<Prod> boxes;
	private static ArrayList<Prod> toys;
	private static int m;
	private static int n;
	private static HashMap<State, BigInteger> calculated;
	private static int count;
	
	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();

		int nbr = 1;
		while (t-- > 0) {
			n = sc.nextInt();
			m = sc.nextInt();

			calculated = new HashMap<B.State, BigInteger>();

			toys = new ArrayList<Prod>();

			for (int i = 0; i < n; i++) {
				Prod toy = new Prod();
				toy.count = new BigInteger(sc.next());
				toy.type = sc.nextInt();
				toys.add(toy);
			}

			boxes = new ArrayList<Prod>();

			for (int i = 0; i < m; i++) {
				Prod box = new Prod();
				box.count = new BigInteger(sc.next());
				box.type = sc.nextInt();
				boxes.add(box);
			}
			BigInteger ans = solve(0, 0, BigInteger.ZERO, BigInteger.ZERO);
			System.out.printf("Case #%d: %d\n", nbr++, ans);
		}
	}

	public static BigInteger solve(int toyNbr, int boxNbr, BigInteger usedToys,
			BigInteger usedBoxes) {

		if (toyNbr == n || boxNbr == m) {
			return BigInteger.ZERO;
		}

		State state = new State(toyNbr, boxNbr, usedToys, usedBoxes);

		if (!calculated.containsKey(state)) {
			BigInteger myScore = BigInteger.ZERO;
			Prod toy = toys.get(toyNbr);
			Prod box = boxes.get(boxNbr);

			if (toy.type == box.type) {
				BigInteger toysAvailable = toy.count.subtract(usedToys);
				BigInteger boxesAvailable = box.count.subtract(usedBoxes);
				BigInteger diff = toysAvailable.subtract(boxesAvailable);

				if (diff.signum() > 0) {
					myScore = toysAvailable.subtract(diff);
					usedToys = usedToys.add(myScore);
					usedBoxes = usedBoxes.add(myScore);
				} else {
					diff = BigInteger.ZERO.subtract(diff);
					myScore = boxesAvailable.subtract(diff);
					usedToys = usedToys.add(myScore);
					usedBoxes = usedBoxes.add(myScore);
				}
			}
			BigInteger toyTry = solve(toyNbr + 1, boxNbr, BigInteger.ZERO,
					usedBoxes);
			BigInteger boxTry = solve(toyNbr, boxNbr + 1, usedToys,
					BigInteger.ZERO);

			calculated
					.put(state,
							myScore.add(toyTry.compareTo(boxTry) > 0 ? toyTry
									: boxTry));
		}
		return calculated.get(state);

	}
}
