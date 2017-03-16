import java.util.*;

public class B {
	
	private static int count;

	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int t=0; t<cases; t++) {
			int n = Integer.parseInt(in.nextLine());
			String[] line = in.nextLine().split(" ");
			HashSet<Integer> unused = new HashSet<Integer>();
			for (int i=0; i<n; i++) {
				unused.add(i);
			}
			count = 0;
			recursion(line, unused);
			System.out.println("Case #" + (t+1) + ": " + count);
		}
	}
	
	private static void recursion(String[] line, HashSet<Integer> unused) {
		for (int i=0; i<line.length; i++) {
			HashSet<Character> set = new HashSet<Character>();
			int l = line[i].length();
			boolean broken = false;
			set.add(line[i].charAt(0));
			for (int j=1; j<l; j++) {
				if (set.contains(line[i].charAt(j)) && line[i].charAt(j) != line[i].charAt(j-1)) {
					broken = true;
					break;
				}
				else {
					set.add(line[i].charAt(j));
				}
			}
			if (broken) {
				continue;
			}
			else {
				HashSet<Integer> unusedcopy = new HashSet<Integer>(unused);
				unusedcopy.remove(i);
				recursion(line, set, unusedcopy, line[i].charAt(l-1), line[i]);
			}
		}
	}
	
	private static void recursion(String[] line, HashSet<Character> set, HashSet<Integer> unused, char last, String total) {
		if (!unused.isEmpty()) {
			for (Integer i: unused) {
				int l = line[i].length();
				HashSet<Character> setcopy = new HashSet<Character>(set);
				boolean broken = false;
				if (line[i].charAt(0)==last || !setcopy.contains(line[i].charAt(0))) {
					setcopy.add(line[i].charAt(0));
					for (int j=1; j<l; j++) {
						if (setcopy.contains(line[i].charAt(j)) && line[i].charAt(j) != line[i].charAt(j-1)) {
							broken = true;
							break;
						}
						else {
							setcopy.add(line[i].charAt(j));
						}
					}
				}
				else {
					broken = true;
				}
				if (broken) {
					continue;
				}
				else {
					HashSet<Integer> unusedcopy = new HashSet<Integer>(unused);
					unusedcopy.remove(i);
					recursion(line, setcopy, unusedcopy, line[i].charAt(l-1), total + line[i]);
				}
			}
		}
		else {
			count++;
			//System.out.println(total);
		}
	}

}
