import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;


public class R1A_2_2012 {

	public static void main(String[] args) {
		
		try {
			
			BufferedReader bf = new BufferedReader(new InputStreamReader(System.in));

			int T = Integer.parseInt(bf.readLine());
			
			for (int i=0; i<T; i++) {
				
				int N = Integer.parseInt(bf.readLine());
				List<Integer> a = new ArrayList<Integer>();
				List<Integer> b = new ArrayList<Integer>();
				
				for (int j=0; j<N; j++) {
					String[] strTemp = bf.readLine().split(" ");
					addToList (a, b, Integer.parseInt(strTemp[0]), Integer.parseInt(strTemp[1]));
				}
				
				Integer[] A = new Integer[a.size()];
				a.toArray(A);
				
				Integer[] B = new Integer[b.size()];
				b.toArray(B);
				
				int[] starsEarned = new int[a.size()];
				
				boolean feasible = true;
				int rounds = N;
				int stars = 0;
				
				for (int x=0; x<N; x++) {
					if (B[x] > stars) {
						int count = 0;
						for (int y=N-1; y>=x; y--) {
							for (int z=N-1; z>=x && count<(B[x] - stars); z--) {
								if (A[z] <= stars) {
									starsEarned[z] = 1;
									stars++;
									count++;
									break;
								}
							}
						}
						
						if (count < (B[x] - stars)) {
							
							feasible = false;
							break;
							
						}
						rounds++;
					}
					stars = stars + 2 - starsEarned[x];
				}
				
				System.out.println("Case #" + (i+1) + ": " + (feasible ? rounds : "Too Bad"));
				
			}
			
			
		} catch (Exception e) {
			e.printStackTrace();
		}
		
	}
	
	private static void addToList(List<Integer> a, List<Integer> b, int a1, int b1) {
		
		int i = 0;
		for (i=0; i<b.size(); i++) {
			if (b.get(i) > b1 || (b.get(i) == b1 && a.get(i) >= a1 ))
				break;
		}
		
		a.add(i, a1);
		b.add(i, b1);
		
	}
	
}
