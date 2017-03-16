import java.util.*;

public class B {

	public static void main(String[] args) {
		B b = new B();
		b.run();
	}

	public void run() {
		Scanner in = new Scanner(System.in);
		int cases = Integer.parseInt(in.nextLine());
		for (int a=0; a<cases; a++) {
			String[] line = in.nextLine().split(" ");
			int b = Integer.parseInt(line[0]);
			long m = Long.parseLong(line[1]);
			boolean[][] connected = new boolean[b][b];
			long[] value = new long[b];
			value[b-1] = 1;
			value[b-2] = 1;
			connected[b-2][b-1] = true;
			for (int i=b-3; i>=0; i--) {
				int j = i+1;
				while (j < b && value[i] < m) {
					if (value[i] + value[j] <= m) {
						value[i] += value[j];
						connected[i][j] = true;
					}
					j++;
				}
			}
			if (value[0]==m) {
				System.out.printf("Case #%d: POSSIBLE\n",a+1);
				print(connected);
			}
			else {
				System.out.printf("Case #%d: IMPOSSIBLE\n",a+1);
			}
		}
	}

	private void print(boolean[][] connected) {
		int b = connected.length;
		for (int i=0; i<b; i++) {
			StringBuilder build = new StringBuilder();
			for (int j=0; j<b; j++) {
				if (connected[i][j]) {
					build.append(1);
				}
				else {
					build.append(0);
				}
			}
			System.out.println(build.toString());
		}
	}
}