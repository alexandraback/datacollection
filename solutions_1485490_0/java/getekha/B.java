package b;

import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

import b.B.Prod;

public class B {
	static class Prod {
		BigInteger count;
		int type;
	}

	private static ArrayList<Prod> boxes;
	private static ArrayList<Prod> toys;
	private static int m;
	private static int n;

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();

		int nbr = 1;
		while (t-- > 0) {
			n = sc.nextInt();
			m = sc.nextInt();

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
//		System.out.println(toyNbr + " " + boxNbr + " " + usedToys + " "
//				+ usedBoxes);
//		System.out.println(myScore);
		BigInteger toyTry = solve(toyNbr + 1, boxNbr, BigInteger.ZERO,
				usedBoxes);
		BigInteger boxTry = solve(toyNbr, boxNbr + 1, usedToys, BigInteger.ZERO);

		return myScore.add(toyTry.compareTo(boxTry) > 0 ? toyTry : boxTry);

	}

}
