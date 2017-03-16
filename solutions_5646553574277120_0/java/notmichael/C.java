import java.util.*;

public class C {

	public static void main(String[] args) {
		C c = new C();
		c.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			int c = in.nextInt();
			int d = in.nextInt();
			int v = in.nextInt();
			ArrayList<Integer> den = new ArrayList<>();
			boolean[] poss = new boolean[v+1];
			poss[0] = true;
			int max = 0;
			for (int i=0; i<d; i++) {
				den.add(in.nextInt());
				int nMax = max;
				ArrayList<Integer> add = new ArrayList<>();
				for (int j=0; j<=max; j++) {
					if (j+den.get(i)>v) {
						break;
					}
					if (poss[j]) {
						add.add(j+den.get(i));
						nMax = j+den.get(i);
					}
				}
				max = nMax;
				for (Integer j: add) {
					poss[j] = true;
				}
			}
			if (a!=cases-1) {
				in.nextLine();
			}
			for (int i=0; i<=v; i++) {
				if (!poss[i]) {
					den.add(i);
					int nMax = max;
					ArrayList<Integer> add = new ArrayList<>();
					for (int j=0; j<=max; j++) {
						if (j+i>v) {
							break;
						}
						if (poss[j]) {
							add.add(j+i);
							nMax = j+i;
						}
					}
					max = nMax;
					for (Integer j: add) {
						poss[j] = true;
					}
				}
			}
			System.out.println("Case #" + (a+1) + ": " + (den.size()-d));
		}
	}

}