import java.util.*;

public class a {

	public static void main(String[] args) {

		Scanner stdin = new Scanner(System.in);

		int numCases = stdin.nextInt();

		for (int loop=1; loop<=numCases; loop++) {

			int N = stdin.nextInt();
			boolean[][] graph = new boolean[N][N];

			for (int i=0; i<N; i++)
				for (int j=0; j<N; j++)
					graph[i][j] = false;

			for (int i=0; i<N; i++) {

				int size = stdin.nextInt();

				for (int j=0; j<size; j++) {

					int myclass = stdin.nextInt();
					myclass--;
					graph[myclass][i] = true;
				}
			}





			// Run Floyd's.
			boolean flag = false;
			for (int k=0; k<N; k++) {
				for (int i=0; i<N; i++) {
					for (int j=0; j<N; j++) {

						if (graph[i][k] && graph[k][j] && graph[i][j])
							flag = true;
						else if (graph[i][k] && graph[k][j])
							graph[i][j] = true;

						if (flag == true)
							break;
					}

					if (flag) break;
				}

				if (flag) break;
			}



			if (flag)
				System.out.println("Case #"+loop+": Yes");
			else
				System.out.println("Case #"+loop+": No");
		}
	}
}