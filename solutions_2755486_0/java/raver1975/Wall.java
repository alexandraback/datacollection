import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;
import java.util.SortedSet;
import java.util.TreeSet;

public class Wall {
	static FileWriter fstream;
	static BufferedWriter out;

	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new File("wall.txt"));
		fstream = new FileWriter("out.txt");
		out = new BufferedWriter(fstream);
		int T = sc.nextInt();
		top: for (int t = 0; t < T; t++) {
			int N = sc.nextInt();
			HashMap<Integer, ArrayList<Nodes>> hm = new HashMap<Integer, ArrayList<Nodes>>();
			for (int i = 0; i < N; i++) {
				int d = sc.nextInt();
				int num = sc.nextInt();
				int w = sc.nextInt();
				int e = sc.nextInt();
				int s = sc.nextInt();
				int deltad = sc.nextInt();
				int deltap = sc.nextInt();
				int deltas = sc.nextInt();
				int day = d;
				int east = e;
				int west = w;
				int str = s;
				for (int g = 0; g < num; g++) {
					ArrayList<Nodes> al = hm.get(day);
					if (al == null) {
						al = new ArrayList<Nodes>();
						hm.put(day, al);
					}
					al.add(new Nodes(west, east, str));
					day += deltad;
					east += deltap;
					west += deltap;
					str += deltas;
				}
			}
			int countss = 0;
			HashMap<Float, Integer> hh = new HashMap<Float, Integer>();
			HashMap<Float, Integer> newhh = new HashMap<Float, Integer>();
			SortedSet<Integer> keys = new TreeSet<Integer>(hm.keySet());

			for (Integer key : keys) {

				ArrayList<Nodes> value = hm.get(key);
				// HashMap<Integer,Integer> hh1=new HashMap<Integer,Integer>();
				for (Nodes n : value) {
					boolean success = false;
					for (float ll = n.w; ll <= n.e; ll+=.5f) {

						int height = 0;
						if (hh.get(ll) != null)
							height = hh.get(ll);
						if (n.s > height) {
							success = true;
							int gh = 0;
							if (newhh.get(ll) != null)
								gh = newhh.get(ll);
							newhh.put((float)ll, Math.max(gh, n.s));
							//newhh.put(((float)ll)+0.5f, Math.max(gh, n.s));
						}
						//System.out.println("Day:"+key+"Attacking "+ll+" "+height+"-"+n.s+" "+countss);
					}
					if (success)
						countss++;
					
				}
				// if (success)countss++;
				// points=new ArrayList<Point>(temp);
				Map tmp = new HashMap(newhh);
				// tempmap.keySet().removeAll(pointmap.keySet());
				hh.putAll(tmp);
			}
//			System.out.println(countss);
			print(t,Integer.toString(countss));
			

		}

		out.close();
		fstream.close();
	}

	public static void print(int cas, String s) {
		s = "Case #" + (cas + 1) + ": " + s;
		System.out.println(s);
		try {
			out.write(s + "\n");
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}

class Nodes {
	int w = 0;
	int e = 0;
	int s = 0;

	public Nodes(int w, int e, int s) {
		this.w = w;
		this.e = e;
		this.s = s;
	}

}
