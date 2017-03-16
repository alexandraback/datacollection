import java.io.*;import java.util.*;
public class aa {
static LinkedList<Integer> g[];
static boolean vis[];
static int N;
public static void main(String [] args) throws IOException {
BufferedReader br = new BufferedReader (new FileReader("Downloads/A-large.in"));
System.setOut(new PrintStream(new FileOutputStream("alarge.out")));
int T = Integer.parseInt(br.readLine());
for (int c = 0; c < T; c++) {
N = Integer.parseInt(br.readLine()); g = new LinkedList [N]; vis = new boolean[N];
for (int i = 0; i < N; i++) {
	args = br.readLine().split(" ");
	g[i] = new LinkedList<Integer>();
	for (int j = 1; j < args.length; j++) {
		g[i].add(Integer.parseInt(args[j]) - 1);
	}
}
boolean diam = false;
for (int i = 0; i < N & !diam; i++) {
	vis = new boolean[N];
	LinkedList<Integer> q = new LinkedList<Integer>(); q.add(i);vis[i] = true;
	while (!q.isEmpty() & !diam) {
		int cur = q.remove();
		for (int j : g[cur]) {
			
			if (vis[j]) {diam = true; break;}
			q.add(j);vis[j] = true;
		
		}
	}
}
System.out.println("Case #" + (c + 1) + ": " + (diam ? "Yes" : "No"));
}

}
}
