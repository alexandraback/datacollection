

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * @author Poirot
 *
 */
public class TheLastWord {

	public static String find(String string) {
		StringBuilder stringBuilder = new StringBuilder();
		LinkedList<Character> linkedList = new LinkedList<>();
		linkedList.add(string.charAt(0));
		for (int i = 1; i < string.length(); i++) {
			if (string.charAt(i) >= linkedList.peekFirst()) {
				linkedList.addFirst(string.charAt(i));
			} else {
				linkedList.addLast(string.charAt(i));
			}
		}
		Iterator<Character> itr = linkedList.iterator();
		while (itr.hasNext()) {
			stringBuilder.append(itr.next());
		}
		return stringBuilder.toString();
	}
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

		int t = in.nextInt();
		in.nextLine();
		for (int i = 1; i <= t; ++i) {
			String line = in.nextLine();
			System.out.println("Case #" + i + ": " + find(line));
		}
	}

}
