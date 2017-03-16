import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;

public class Treasure {
	public static LinkedList<Integer> solution;
	int chests, keys;
	int[] keyset, chestopen, totalkeys, totalchests;
	LinkedList<Integer>[] chestkeys;
	FileReader input;
	Scanner scanner;
	BufferedReader reader;
	HashMap<State, Boolean> visitedState;
	boolean solved;

	public class State {
		LinkedList<Integer> m_list;
		int[] m_keys;

		State(LinkedList<Integer> l, int[] k) {
			m_list = l;
			m_keys = k;
		}

		public boolean equals(Object b) {
			if (!(b instanceof State))
				return false;
			State b2 = (State) b;
			return m_list.equals(b2.m_list) && Arrays.equals(m_keys, b2.m_keys);
		}

		public int hashCode() {
			return Arrays.hashCode(m_keys);
		}
	}

	Treasure() {
		try {

			input = new FileReader("D-small-attempt2.in.txt");
			PrintStream out = new PrintStream(
					new FileOutputStream("output.txt"));
			reader = new BufferedReader(input);
			int testcase = Integer.parseInt(reader.readLine());
			for (int k = 1; k <= testcase; k++) {
				visitedState = new HashMap<State, Boolean>();
				solved = false;
				solution = null;
				scanner = new Scanner(reader.readLine());
				keys = scanner.nextInt();
				chests = scanner.nextInt();
				keyset = new int[50];
				totalkeys = new int[50];
				totalchests = new int[50];
				chestopen = new int[chests];
				Arrays.fill(keyset, 0);
				scanner = new Scanner(reader.readLine());
				int currentkey;
				for (int i = 0; i < keys; i++) {
					currentkey = scanner.nextInt();
					totalkeys[currentkey]++;
					
						keyset[currentkey-1]++;
					
				} 
				chestkeys = new LinkedList[chests];
				for (int i = 0; i < chests; i++) {
					scanner = new Scanner(reader.readLine());
					int dummy = scanner.nextInt();
					chestopen[i] = dummy;
					totalchests[dummy]++;
					int nokeys = scanner.nextInt();
					LinkedList<Integer> list = new LinkedList<Integer>();
					for (int j = 0; j < nokeys; j++) {
						dummy = scanner.nextInt();
						list.add(dummy);
						totalkeys[dummy]++;
					}
					chestkeys[i] = list;
				}
				boolean start = true;
				for (int i = 0; i < totalkeys.length; i++) {
					if (totalkeys[i] < totalchests[i]) {
						start = false;
						break;
					}
				}
			
				LinkedList<Integer> remain = new LinkedList<Integer>();
				for (int i = 1; i <= chests; i++) {
					remain.add(i);
				}
				LinkedList<Integer> order = new LinkedList<Integer>();
				if (start == true) {
					TreasureRecurse(remain, order, keyset);
				}
				if (solution == null) {
					out.println("Case #" + k + ": IMPOSSIBLE");
				} else {
					String string = "";
					for (int i : solution) {
						string = string + " " + i;
					}
					out.println("Case #" + k + ":" + string);
				}
			}
		} catch (NumberFormatException | IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	public void TreasureRecurse(LinkedList<Integer> remain,
			LinkedList<Integer> order, int[] keys) {
	
		if (remain.size() == 0) {
			solution = order;
			solved = true;
		} else {
			if (!solved) {
				for (Integer i : remain) {
					State state = new State(remain, keys);
					visitedState.put(state, true);
					if (keys[chestopen[i - 1] - 1] > 0) {
						int[] newkeys = Arrays.copyOf(keys, keys.length);
						newkeys[chestopen[i - 1] - 1]--;
						LinkedList<Integer> keysinroom = chestkeys[i - 1];
						for (int j : keysinroom) {
							newkeys[j - 1]++;
						}
						LinkedList<Integer> neworder = new LinkedList<Integer>(
								order);
						neworder.add(i);
						LinkedList<Integer> newremain = new LinkedList<Integer>(
								remain);
						newremain.removeFirstOccurrence(i);
						State newstate = new State(newremain, newkeys);
						if (!visitedState.containsKey(newstate)) {
							TreasureRecurse(newremain, neworder, newkeys);
						}
					}
				}
			}
		}
	}

	public static void main(String[] args) {
		Treasure test = new Treasure();
	}
}
