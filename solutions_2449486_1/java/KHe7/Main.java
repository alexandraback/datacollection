import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	/**
	 * @param args
	 * @throws IOException
	 * @throws NumberFormatException
	 */
	public static void main(String[] args) throws NumberFormatException,
			IOException {
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		String[] ia;

		int C = Integer.parseInt(in.readLine());
		loop:for(int i = 1; i <= C; ++i){
			System.out.print("Case #" + i + ": ");
			ia = in.readLine().split(" ");
			int N = Integer.parseInt(ia[0]);
			int M = Integer.parseInt(ia[1]);
			int[][] F = new int[N][M];
			for(int j = 0;j < N; ++j){
				ia = in.readLine().split(" ");
				for(int k = 0;k < M; ++k){
					F[j][k] = Integer.parseInt(ia[k]);
				}
			}
			for(int j = 0;j < N; ++j){
				for(int k = 0;k < M; ++k){
					boolean p = false, r = false;
					for(int l = 0;l < N; ++l){
						if(F[j][k] < F[l][k]){
							if(r){
								System.out.println("NO");
								continue loop;
							} else {
								p = true;
							}
						}
					}
					for(int l = 0;l < M; ++l){
						if(F[j][k] < F[j][l]){
							if(p){
								System.out.println("NO");
								continue loop;
							} else {
								r = true;
							}
						}

					}
				}
			}
			System.out.println("YES");
		}
	}

}
