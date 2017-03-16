import java.util.Arrays;
import java.util.Scanner;

public class C {
	private static Scanner sc;
	
	public static void main(String[] args) {
		sc = new Scanner(System.in);
		int t = sc.nextInt();
		for (int i = 0; i < t; i++) {
			System.out.printf("Case #%d: %s\n", i + 1, exec());
		}
	}
	
	static String[] zips;
	static long[] hops;
	
	static class City implements Comparable<City> {
		String zip;
		int order;
		
		City(String zip, int order) {
			this.zip = zip;
			this.order = order;
		}
		
		@Override public int compareTo(City o) {
			return zip.compareTo(o.zip);
		}
	}
	
	public static String exec() {
		int cityCount = sc.nextInt();
		int hopCount = sc.nextInt();
		City[] z = new City[cityCount];
		for (int i = 0; i < cityCount; i++) z[i] = new City(sc.next(), i);
		Arrays.sort(z);
		int[] trans = new int[cityCount];
		for (int i = 0; i < cityCount; i++) trans[z[i].order] = i;
		zips = new String[cityCount];
		for (int i = 0; i < cityCount; i++) zips[i] = z[i].zip;
		
		hops = new long[cityCount];
		for (int i = 0; i < hopCount; i++) {
			int a = sc.nextInt() - 1;
			int b = sc.nextInt() - 1;
			a = trans[a];
			b = trans[b];
			hops[a] = hops[a] | (1 << b);
			hops[b] = hops[b] | (1 << a);
		}
		
		long left = (1 << cityCount) - 1;
		
		return recurse(new State("", left), 0L, -1).sofar;
	}
	
	private static final String MARKER = "NopeGoBack";
	
	private static class State {
		String sofar;
		long left;
		
		State(String sofar, long left) {
			this.sofar = sofar;
			this.left = left;
		}
	}
	
	private static State recurse(State state, long skip, int location) {
		if (state.left == 0) return state;
		
		while (true) {
			// attempt travel to the still remaining 'cheapest' city.
			long available = (location == -1 ? Long.MAX_VALUE : hops[location]) & ~skip & state.left;
			if (available == 0) return state;
			int dest = Long.numberOfTrailingZeros(available);
			State ns = recurse(new State(state.sofar + zips[dest], state.left & ~Long.lowestOneBit(available)), 0, dest);
			if (ns.left == 0) return ns;
			state = ns;
			skip = skip | Long.lowestOneBit(available);
		}
	}
}
