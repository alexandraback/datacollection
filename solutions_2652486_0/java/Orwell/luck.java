import java.io.*;
import java.util.*;

class luck {
	public static void main (String [] args) throws IOException {
		long start = System.currentTimeMillis();
		BufferedReader br = new BufferedReader(new FileReader("luck.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("luck.out")));
		br.readLine();
		br.readLine();
		out.println("Case #1:");
		for (int i = 0; i < 100; i++) {
			int[] vals = new int[7];
			StringTokenizer st = new StringTokenizer(br.readLine());
			for (int j = 0; j < 7; j++) {
				vals[j] = Integer.parseInt(st.nextToken());
			}
			out.println(det(vals));
			out.flush();
		}
		long end = System.currentTimeMillis();
		System.out.println(end-start);
		out.close();
		System.exit(0);
	}
	public static String det(int[] vals) {
		if (contains(vals, 18)) return "233";
		if (contains(vals, 24)) return "234";
		if (contains(vals, 27)) return "333";
		if (contains(vals, 30)) return "235";
		if (contains(vals, 32)) return "244";
		if (contains(vals, 36)) return "334";
		if (contains(vals, 40)) return "245";
		if (contains(vals, 45)) return "335";
		if (contains(vals, 48)) return "344";
		if (contains(vals, 60)) return "345";
		if (contains(vals, 64)) return "444";
		if (contains(vals, 75)) return "355";
		if (contains(vals, 80)) return "445";
		if (contains(vals, 100)) return "455";
		if (contains(vals, 125)) return "555";
		ArrayList def = new ArrayList<String>();
		if (contains(vals, 2)) def.add("2");
		if (contains(vals, 3)) def.add("3");
		if (contains(vals, 5)) def.add("5");
		if (contains(vals, 6)) { def.add("2"); def.add("3"); }
		if (contains(vals, 9)) { def.add("3"); def.add("3"); }
		if (contains(vals, 10)) { def.add("2"); def.add("5"); }
		if (contains(vals, 15)) { def.add("5"); def.add("3"); }
		if (contains(vals, 25)) { def.add("5"); def.add("5"); }
		if (def.size() > 0) {
			String toReturn = "";
			for (int i = 0; i < Math.min(def.size(), 3); i++) {
				toReturn += def.get(i);
			}
			for (int i = toReturn.length(); i < 3; i++) {
				toReturn += "2";
			}
			return toReturn;
		}
		else return "222";
	}
	public static boolean contains(int[] vals, int num) {
		for (int i = 0; i < 7; i++) {
			if (vals[i] == num) return true;
		}
		return false;
	}
}

