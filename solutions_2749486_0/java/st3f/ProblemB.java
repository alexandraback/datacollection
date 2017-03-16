import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
import java.util.Scanner;
import java.util.Set;


class Pos {
	int x, y;
	String path;
	
	public Pos(int x, int y, String path) {
		super();
		this.x = x;
		this.y = y;
		this.path = path;
	}
}

public class ProblemB {
	static Map<String, Integer> xy = new HashMap<String, Integer>();
	static String[] paths = new String[100];
	static int n;
	static int found = 0;
	static Set<String> visited = new HashSet<String>();
	static List<Pos> current = new ArrayList<Pos>();
	static List<Pos> next = new ArrayList<Pos>();

	static void check(Pos pos) {
		String s = pos.x + " " + pos.y;
		if (visited.contains(s))
			return;
		if (xy.containsKey(s)) {
			found++;
			paths[xy.get(s)] = pos.path;
		}
		next.add(pos);
		visited.add(s);
	}
	
	
	static void nextCase(Scanner sc, PrintStream ps) {
		n = sc.nextInt();
		for (int i = 0; i < n; i++) {
			int x = sc.nextInt();
			int y = sc.nextInt();
			xy.put(x + " " + y, i);
		}
		
		int length = 1;
		visited.add("0 0");
		current.add(new Pos(0, 0, ""));
		while (found < n) {
			System.out.println(length + " " + found + " " + current.size());
			for (Pos pos : current) {
				check(new Pos(pos.x + length, pos.y, pos.path + "E"));
				check(new Pos(pos.x - length, pos.y, pos.path + "W"));
				check(new Pos(pos.x, pos.y + length, pos.path + "N"));
				check(new Pos(pos.x, pos.y - length, pos.path + "S"));
			}
			List<Pos> tmp = current;
			current = next;
			next = tmp;
			tmp.clear();
			length++;
		}
		for (int i = 0; i < n; i++)
			ps.printf("Case #%d: %s%n", i + 1, paths[i]);
	}

	
	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File(args[0] + ".in"));
		PrintStream ps = new PrintStream(args[0] + ".out");
		
		nextCase(sc, ps);
	}
}
