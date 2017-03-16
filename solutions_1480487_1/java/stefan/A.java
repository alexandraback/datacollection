import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.Scanner;


public class A {
	public static final String FILENAME = "A-large";
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("src/"+FILENAME+".in"));
		BufferedWriter out = new BufferedWriter(new FileWriter("src/"+FILENAME+".out"));
		Scanner s = new Scanner(in);
		int T = s.nextInt();
		s.nextLine();
		for(int i = 1; i <= T; i++) {
			System.out.println(i);
			int N = s.nextInt();
			int sc[] = new int[N];
			PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
			int x = 0;
			for(int j = 0; j < N; j++) {
				sc[j] = s.nextInt();
				pq.add(sc[j]);
				x += sc[j];
			}
			out.write("Case #"+i+":");
			int r = x;
			int sa = 1;//amount
			int ss = 0;//sum
			int sl = pq.poll();//last
			while(!pq.isEmpty() && r >= sa * (pq.peek() - sl)) {
				ss += sa * (pq.peek() - sl);
				r = x - ss;
				sl = pq.poll();
				sa++;
			}
			double needed = sl + ((double) r) / ((double) sa);
			System.out.println(needed);
			
			for(int j = 0; j < N; j++) {
				if(sc[j] >= needed) {
					out.write(" 0.0");
				}
				else {
					out.write(" "+(100.0*(needed-sc[j])/((double) x)));
				}
			}
			out.write("\n");
		}
		in.close();
		out.close();
	}
}
