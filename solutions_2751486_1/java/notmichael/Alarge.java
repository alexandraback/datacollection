import java.util.*;

public class Alarge {

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		char[] con = {'b', 'c', 'd', 'f', 'g', 'h', 'j', 'k', 'l', 'm', 'n', 'p', 'q', 'r', 's', 
				't', 'v', 'w', 'x', 'y', 'z'};
		char[] vow = {'a', 'e', 'i', 'o', 'u'};
		TreeSet<Character> cons = new TreeSet<Character>();
		for (int i=0; i<21; i++) {
			cons.add(con[i]);
		}
		TreeSet<Character> vows = new TreeSet<Character>();
		for (int i=0; i<5; i++) {
			vows.add(vow[i]);
		}
		for (int a=0; a<cases; a++) {
			String[] line = in.nextLine().split(" ");
			String name = line[0];
			int n = Integer.parseInt(line[1]);
			char[] nameA = name.toCharArray();
			ArrayList<Integer> points = new ArrayList<Integer>();
			int length = nameA.length;
			int consec = 0;
			for (int i=0; i<length; i++) {
				if (cons.contains(nameA[i])) {
					consec++;
				}
				else {
					consec = 0;
				}
				if (consec>=n) {
					points.add(i-n+1);
				}
			}
			int total = 0;
			int place = 0;
			int size = points.size();
			for (int i=0; i<length; i++) {
				if (place==size) {
					break;
				}
				if (i>points.get(place)) {
					place++;
				}
				if (place==size) {
					break;
				}
				int first = points.get(place);
				total += (length - (first + n - 1));
			}
			System.out.println("Case #" + (a+1) + ": " + total);
		}
	}

}
