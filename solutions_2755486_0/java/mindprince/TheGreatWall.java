import java.util.*;
import java.io.*;
public class TheGreatWall {
	public static void main(String[] args) {
		String inputfile = args[0];
		BufferedReader input;
		try {
			input = new BufferedReader(new FileReader(inputfile));
		} catch (FileNotFoundException e) {
			System.err.println("File not found");
			return;
		}
		Scanner st = new Scanner(input);
		int T = st.nextInt();
		for (int x = 1; x <=T; x++) {
			TreeSet<Attack> attacklist = new TreeSet<Attack>();
			int N = st.nextInt();
			for (int y = 0; y < N; y++) {
				int d = st.nextInt();
				int n = st.nextInt();
				int w = st.nextInt();
				int e = st.nextInt();
				int s = st.nextInt();
				int delta_d = st.nextInt();
				int delta_p = st.nextInt();
				int delta_s = st.nextInt();
				for (int i = 0; i < n; i++) {
					Attack attack = new Attack(d + i*delta_d,
					                           w + i*delta_p,
											   e + i*delta_p,
											   s + i*delta_s);
					attacklist.add(attack);
				}
			}
			int count = 0;
			int[] positivewall = new int[1000];
			// positivewall[i] stores the height of wall from i to i+1.
			int[] negativewall = new int[1000];
			// negativewall[i] stores the height of wall from -i-1 to -i
			ArrayList<Wall> pendingImprovements = new ArrayList<Wall>();
			int day = 0;
			for (Attack attack : attacklist) {
				if (attack.day != day) {
					for (Wall w : pendingImprovements) {
						int positiveleft = Math.max(0, w.west);
						int positiveright = Math.max(0, w.east);
						for (int i = positiveleft; i < positiveright; i++) {
							positivewall[i] = Math.max(positivewall[i], w.height);
						}

						int negativeleft = Math.min(0, w.west);
						int negativeright = Math.min(0, w.east);
						for (int i = negativeleft; i < negativeright; i++) {
							negativewall[-1*(i+1)] = Math.max(negativewall[-1*(i+1)], w.height);
						}
					}
					day = attack.day;
					pendingImprovements = new ArrayList<Wall>();
				}
				for (int i = attack.westmost; i < attack.eastmost; i++) {
					if (i < 0) {
						if (negativewall[-1*(i+1)] < attack.strength) {
							// Attack successful.
							count++;
							pendingImprovements.add(new Wall(attack.strength, attack.westmost, attack.eastmost));
							break;
						}
					} else {
						if (positivewall[i] < attack.strength) {
							// Attack successful.
							count++;
							pendingImprovements.add(new Wall(attack.strength, attack.westmost, attack.eastmost));
							break;
						}
					}
				}
			}
        	System.out.println("Case #" + x + ": " + count);
		}
	}
}

class Wall {
	int height;
	int west;
	int east;

	public Wall(int h, int w, int e) {
		height = h;
		west = w;
		east = e;
	}
}

class Attack implements Comparable{
	int day;
	int westmost;
	int eastmost;
	int strength;

	public Attack(int d, int w, int e, int s) {
		day = d;
		westmost = w;
		eastmost = e;
		strength = s;
	}

    public int compareTo(Object otherobj) {
        Attack other = (Attack) otherobj;
        if (this.day < other.day) {
            return -1;
        } else {
            return 1;
        }
    }

	public String toString() {
		return "day: " + day + ". From " + westmost + " to " + eastmost + ". Strength: " + strength + "\n";
	}
}
