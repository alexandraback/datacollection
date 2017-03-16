import java.util.*;

public class A {

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
			int length = nameA.length;
			int total = 0;
			for (int i=0; i<length; i++) {
				if (length-i < n) {
					break;
				}
				for (int j=i+n-1; j<length; j++) {
					int place = i;
					int consec = 0;
					while (place<=j) {
						if (cons.contains(nameA[place])) {
							consec++;
						}
						else {
							consec = 0;
						}
						if (consec==n) {
							total++;
							break;
						}
						place++;
					}
				}
			}
			System.out.println("Case #" + (a+1) + ": " + total);
		}
	}

}
