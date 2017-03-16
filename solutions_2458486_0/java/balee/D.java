import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;

// Treasure
// https://code.google.com/codejam/contest/2270488/dashboard#s=p3

public class D {

	private static int keyCount; // key count in hand
	private static int chestCount; // chest count
	private static ArrayList<Integer> keys; // keys in hand
	private static int[] keyOpeningChest; // key that opens chest i
	private static int[] keyCountInChest; // key count in chest i
	private static ArrayList<ArrayList<Integer>> keysInChest; // keys in chest

	private static String dump(int[] b) {
		return dump(b, b.length);
	}

	private static String dump(int[] b, int count) {
		StringBuffer res = new StringBuffer();
		for(int i = 0; i < count; i++) {
			if ( i > 0 )
				res.append(" ");
			res.append(b[i]);
		}
		return new String(res);
	}

	private static String dump(ArrayList<Integer> b) {
		StringBuffer res = new StringBuffer();
		for(int i = 0; i < b.size(); i++) {
			if ( i > 0 )
				res.append(" ");
			res.append(b.get(i));
		}
		return new String(res);
	}

	private static boolean check(int[] chestOrder, int count) {

		ArrayList<Integer> hand = new ArrayList<Integer>(keys);

		for(int i = 0; i < count; i++) {

			int chest = chestOrder[i] - 1;

			// Able to open?
			if ( ! hand.contains(keyOpeningChest[chest]) ) {
				/*
				System.out.println(cnt + ": " + dump(chestOrder, count) + " (" + keyOpeningChest[chest] + ") - " + dump(hand));
				if ( cnt > 190000 && count > 1 ) {
					for(int x = 0; x < chestCount; x++) {
						boolean found = false;
						for(int y = 0; y < count; y++)
							if ( chestOrder[y] - 1 == x )
								found = true;
						if ( ! found )
							System.out.println("\t" + (x + 1) + ": " + " (" + keyOpeningChest[x] + ") " + dump(keysInChest.get(x)));
					}
					Runtime.getRuntime().halt(1);
				}
				cnt++;*/
				return false;
			}

			// Remove the opener key
			hand.remove(new Integer(keyOpeningChest[chest]));

			// Add the keys from the chest
			hand.addAll(keysInChest.get(chest));

			//////////////// nomore			
			if ( ! hand.contains(keyOpeningChest[chest]) ) {
				boolean ok = true;
				for(int x = 0; x < chestCount; x++) {
					boolean found = false;
					for(int y = 0; y <= i; y++)
						if ( chestOrder[y] - 1 == x )
							found = true;
					//if ( ! found ) System.out.println("\t" + (x + 1) + ": " + " (" + keyOpeningChest[x] + ") " + dump(keysInChest.get(x)));
					if ( ! found ) {
						if ( keyOpeningChest[x] == keyOpeningChest[chest] )
							ok = false;
						if ( keyOpeningChest[x] != keyOpeningChest[chest] ) 
							if ( keysInChest.get(x).contains(keyOpeningChest[chest]) ) {
								ok = true;
								break;
							}
					}
				}
				//System.out.println("-");
				if ( ! ok )	{
					//System.out.println(cnt + "zzz: " + dump(chestOrder, count) + " (" + keyOpeningChest[chest] + ") - " + dump(hand));
					return false;
				}
			}
		}

		return true;
	}

	private static boolean preCheck(int[] chestOrder, int pos) {
		if ( pos >= 0 ) {
			int last = chestOrder[pos];
			for(int i = 0; i < pos; i++)
				if ( chestOrder[i] == last )
					return false;
		}
		return true;
	}

	static long cnt = 0;

	private static boolean tryIt(int min, int max, int[] chestOrder, int pos) {
		if ( preCheck(chestOrder, pos) )  {
			if ( ! check(chestOrder, pos + 1) ) 
				return false;
			if ( pos == chestOrder.length - 1 ) {
				if ( check(chestOrder, chestCount) )
					//dump(chestOrder);
					return true;
			}
			else {
				pos++;
				for(int i = min; i <= max ; i++) {
					chestOrder[pos] = i;
					if ( tryIt(min, max, chestOrder, pos) )
						return true;
				}
			}
		}
		return false;
	}

	private static String process(Scanner in) {

		keyCount = in.nextInt(); // key count in hand
		chestCount = in.nextInt(); // chest count
		keys = new ArrayList<Integer>(); // keys in hand
		keyOpeningChest = new int[chestCount]; // key that opens chest i
		keyCountInChest = new int[chestCount]; // key count in chest i
		keysInChest = new ArrayList<ArrayList<Integer>>(); // keys in chest

		//System.out.println(keyCount + " " + chestCount);

		int MAX = 10000;
		int keysAvail[] = new int[MAX];
		int keysNeeded[] = new int[MAX];

		// read keys in hand
		for(int i = 0; i < keyCount; i++) {
			int key = in.nextInt();
			keys.add(key);
			keysAvail[key]++;
		}

		// read chest info
		for(int i = 0; i < chestCount; i++) {
			keyOpeningChest[i] = in.nextInt();
			keysNeeded[keyOpeningChest[i]]++;
			keyCountInChest[i] = in.nextInt();
			ArrayList<Integer> keys = new ArrayList<Integer>();
			keysInChest.add(keys);
			for(int j = 0; j < keyCountInChest[i]; j++) {
				int key = in.nextInt();
				keys.add(key);
				keysAvail[key]++;
			}
		}

		// dummy precheck
		for(int i = 0; i < MAX; i++)
			if ( keysAvail[i] < keysNeeded[i] )
				return "IMPOSSIBLE";

		// do the work
		int[] chestOrder = new int[chestCount];
		if ( tryIt(1, chestCount, chestOrder, -1) )
			return dump(chestOrder);

		return "IMPOSSIBLE";
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
