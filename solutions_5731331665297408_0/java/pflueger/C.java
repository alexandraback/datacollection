import java.io.IOException;
import java.util.*;

//5/3/14 in competition.

public class C extends CodeJammer {

	@Override
	public void process() throws IOException {
		int[] line = reader.readArray();
		n = line[0];
		m = line[1];
		link = new boolean[n][n];
		zip = new int[n];
		
		for (int i=0; i<n; i++) {
			zip[i] = reader.readInt();
		}
		for (int i=0; i<m; i++) {
			int[] l = reader.readArray();
			link[l[0]-1][l[1]-1] = link[l[1]-1][l[0]-1] = true;
		}
		
		PriorityQueue<Itin> pq = new PriorityQueue<Itin>();
		
		for (int i=0; i<n; i++) {
			boolean[] v = new boolean[n];
			v[i] = true;
			Stack<Integer> p = new Stack<Integer>();
			p.add(i);
			int[] o = new int[1];
			o[0] = i;
			Itin seed = new Itin(v,p,o);
			pq.add(seed);
		}
		
		while (!pq.isEmpty()) {
			Itin trip = pq.poll();
			if (trip.visitOrder.length == n) {
				String output = "";
				for (int i=0; i<n; i++) {
					output += zip[trip.visitOrder[i]];
				}
				output(output);
				return;
			} else {
				for (Itin next : trip.extend()) {
					pq.add(next);
				}
			}
		}
		output("No path!");
	}
	public boolean[][] link;
	public int[] zip;
	public int n;
	public int m;
	
	public class Itin implements Comparable<Itin> {
		boolean[] visited;
		Stack<Integer> prior;
		int[] visitOrder;
		public Itin(boolean[] v, Stack<Integer> p, int[] o) {
			visited = v;
			prior = p;
			visitOrder = o;
		}
		
		public List<Itin> extend() {
			List<Itin> result = new ArrayList<Itin>();
			
			while (!prior.isEmpty()) {
				int source = prior.peek();
				
				for (int i = 0; i<n; i++) {
					if (!visited[i] && link[source][i]) {
						boolean[] v = Arrays.copyOf(visited, n);
						v[i] = true;
						Stack<Integer> s = (Stack<Integer>) prior.clone();
						s.add(i);
						int[] o = Arrays.copyOf(visitOrder, visitOrder.length+1);
						o[visitOrder.length] = i;
						Itin nextItin = new Itin(v,s,o);
						result.add(nextItin);
					}
				}
				
				prior.pop();
			}
			
			return result;
		}
		
		public int compareTo(Itin other) {
			for (int i=0; i<visitOrder.length; i++) {
				if (i >= other.visitOrder.length) return 1;
				int z1 = zip[visitOrder[i]];
				int z2 = zip[other.visitOrder[i]];
				if (z1 > z2) return 1;
				if (z1 < z2) return -1;
			}
			if (other.visitOrder.length > visitOrder.length) return -1;
			return 0;
		}
	}

	public static void main(String[] args) {
		new C().run(args);
	}

}
