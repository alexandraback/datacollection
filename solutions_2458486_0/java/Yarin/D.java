package qual2013;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.util.ArrayList;
import java.util.List;

public class D {
	public static void main(String[] args) throws FileNotFoundException {
		Kattio io;

//		io = new Kattio(System.in, System.out);
//		io = new Kattio(new FileInputStream("src/qual2013/D-sample.in"), System.out);
		io = new Kattio(new FileInputStream("src/qual2013/D-small-attempt0.in"), new FileOutputStream("src/qual2013/D-small-0.out"));
//		io = new Kattio(new FileInputStream("src/qual2013/D-large-0.in"), new FileOutputStream("src/qual2013/D-large-0.out"));

		int cases = io.getInt();
		for (int i = 1; i <= cases; i++) {
			io.print("Case #" + i + ": ");
			new D().solve(io);
		}
		io.close();
	}

    int N;
    int startKey[];
    int chestReq[], chestKeys[][];
    boolean vis[];

    private boolean canOpen(final int chest, int mask) {
        int req = chestReq[chest];
        int count = startKey[req];
        for(int i=0;i<N;i++) {
            if (((1<<i) & mask) > 0) {
                if (chestReq[i] == req) count--;
                count += chestKeys[i][req];
            }
        }
        return count > 0;
    }

	private void solve(Kattio io) {
        int K = io.getInt();
        N = io.getInt();
        startKey = new int[201];
        for(int i=0;i<K;i++) {
            startKey[io.getInt()]++;
        }
        chestReq = new int[N];
        chestKeys = new int[N][201];
        for(int i=0;i<N;i++) {
            chestReq[i] = io.getInt();
            int m = io.getInt();
            for(int j=0;j<m;j++) {
                chestKeys[i][io.getInt()]++;
            }
        }
        vis = new boolean[1<<N];
        List<Integer> order = go(0, new ArrayList<Integer>());
        if (order == null) {
            io.println("IMPOSSIBLE");
        } else {
            for (int x : order) {
                io.print((x+1) + " ");
            }
            io.println();
        }
    }

    private List<Integer> go(int mask, List<Integer> order) {
        if (mask == (1<<N)-1) {
            return order;
        }
        if (vis[mask]) return null;
        vis[mask] = true;
        for (int i=0;i<N;i++) {
            if (((1<<i)&mask)>0) continue;
            if (canOpen(i, mask)) {
                order.add(i);
                if (go(mask|(1<<i), order) != null) {
                    return order;
                }
                order.remove(order.size() - 1);
            }
        }
        return null;
    }
}
