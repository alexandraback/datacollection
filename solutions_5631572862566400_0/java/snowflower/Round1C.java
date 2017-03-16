import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Scanner;


public class Round1C {

	public static void main(String[] args) throws FileNotFoundException {
		Scanner sc = new Scanner(new File("D:\\Downloads\\C-small-attempt2.in"));
		// Scanner sc = new Scanner(new File("small3.in"));
		
		int T = sc.nextInt();
		
		for (int x = 1; x <= T; ++x) {
			int N = sc.nextInt();
			ArrayList<Integer> r = new ArrayList<>();
			int max = 0;
			boolean findReverse = false; 
			
			int[] arr = new int[N + 1];
			for (int i = 1; i <= N; ++i) {
				arr[i] = sc.nextInt();
			}
					
			// Start Point = 1
			int[] use = new int[N + 1];
			for (int i = 1; i <= N; ++i) {
				// Start
				int k = i;
				use[k] = 1;
				r.add(k);
				
				while (true) {
					if (use[arr[k]] == 0) {
						k = arr[k];
						use[k] = 1;
						r.add(k);
					}
					else {
						if (arr[k] != i) {
							if (r.size() > 2 && arr[k] != r.get(r.size() - 2)) {
								r.remove(r.size() - 1);
							}
							else {
								findReverse = true;
							}
						}
						break;
					}
				}
				
				// find reverse
				if (findReverse) {
					boolean bAdd = true;
					while (bAdd) {
						bAdd = false;
						for (int j = 1; j <= N; ++j) {
							if (r.get(r.size() - 1) == arr[j] &&
									r.indexOf(j) == -1 && use[j] == 0) {
								use[j] = 1;
								r.add(j);
								bAdd = true;
								break;
							}
						}					
					}
				}
				
				if (max < r.size()) {
					max = r.size();
				}
				
				// Clear
				for (int j = 0; j <= N; ++j) {
					use[j] = 0;
				}
				r.clear();
			}
			
			System.out.println("Case #" + x + ": " + max);
			
		}

		sc.close();
	}
}
