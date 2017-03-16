import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStream;
import java.util.Scanner;

public class Main {
	public static void main(String[] args) throws IOException{
		// Scanner s = new Scanner(System.in);
		InputStream is = new FileInputStream(".\\input_and_output\\1A2016\\C-small-1A2016.in");
		FileWriter fr = new FileWriter(".\\input_and_output\\1A2016\\C-small-1A2016.out");
		Scanner s = new Scanner(is);
		
		int n = s.nextInt();
		for (int i = 1; i <= n; ++i){			
			int N = s.nextInt();

			int[] bff = new int[N];
			for (int j = 0; j < N; ++j){
				bff[j] = s.nextInt();
			}
			
			int res = 0;
			int[] flag = new int[N];
			for (int j = 0; j < N; ++j){
				if (flag[j] == 0){
					int c = 1, start = j, pre = j, cur = bff[pre] - 1;
					flag[start] = -1;
					while (flag[cur] == 0){
						++c;
						flag[cur] = -1;
						cur = bff[cur] - 1;
						if (cur == pre){
							flag[bff[cur] - 1] = c;
						}
						pre = bff[pre] - 1;
					}
					
					if (cur != start){
						flag[start] = c;
					}
					
					if (flag[cur] != -1){						
						res = Math.max(res, c + flag[cur]);
						flag[start] = c + flag[cur];
						flag[cur] = -1;
					} else {
						res = Math.max(res, c);
					}
				}
			}
			
			fr.write(String.format("Case #%d: %d\n", i, res));
			// System.out.print(String.format("Case #%d: %d\n", i, res));
		}
		
		fr.close();
		s.close();
	}
}




