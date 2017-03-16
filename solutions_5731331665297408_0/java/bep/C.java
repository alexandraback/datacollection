/*Code uses Std libraries from Princeton's COS 226 class at algs4.cs.princeton.edu */
public class C {
	public static void main(String[] args) {
		int t = StdIn.readInt();
		for (int i = 1; i <= t; i++) {
			StdOut.print("Case #" + i +": ");
			solveCase();
		}
	}

	public static void solveCase() {
		int N = StdIn.readInt();
		int M = StdIn.readInt();
		Graph G = new Graph(N);
		RedBlackBST<String, Integer> ztoI = new RedBlackBST<String, Integer>();
		RedBlackBST<Integer, String> itoZ = new RedBlackBST<Integer, String>();
		for (int i = 0; i < N; i++) {
			String s = StdIn.readString();
			ztoI.put(s, i);
			itoZ.put(i, s);
		}
		for (int i = 0; i < M; i++) {
			int v = StdIn.readInt() - 1;
			int w = StdIn.readInt() - 1;
			G.addEdge(v, w);
		}
		boolean[] marked = new boolean[N];
		int current = ztoI.get(ztoI.min());
		int count = 0;
		StringBuilder out = new StringBuilder();
		RedBlackBST<String, Integer> reachable = new RedBlackBST<String, Integer>();
		Stack<Integer> path = new Stack<Integer>();
		while(count < N) {
			if (reachable.contains(itoZ.get(current))) reachable.delete(itoZ.get(current));
			marked[current] = true;
			out.append(itoZ.get(current));
			path.push(current);
			for (int v : G.adj(current)) {
				if(!marked[v]) {
					reachable.put(itoZ.get(v), v);
				}
			}
			for (int i = 0; i < reachable.size(); i++) {
				if (canComplete(reachable.get(reachable.select(i)), G, marked, path)) {
					current = reachable.get(reachable.select(i));
					break;
				}
			}
			count ++;
		}
		StdOut.println(out.toString());
	}

	public static boolean canComplete(int x, Graph G, boolean[] m, Stack<Integer> path) {
		int parent = -1;		
        Queue<Integer> q = new Queue<Integer>();
		for(int p : path) {
			for(int i: G.adj(x)) {
				if(i == p) {
					parent = p;
					break;
				}
			}
			if (parent != -1) {
				q.enqueue(p);
			}
		}
		boolean[] marked = new boolean[m.length];
		for(int i= 0; i < m.length; i++) marked[i] = m[i];
		while (!q.isEmpty()) {
            int v = q.dequeue();
            for (int w : G.adj(v)) {
                if (!marked[w]) {
                    marked[w] = true;
                    q.enqueue(w);
                }
            }
        }
        for(int i = 0; i < m.length; i++) {
        	if(!marked[i]) return false;
        }
        return true;
	}
}
