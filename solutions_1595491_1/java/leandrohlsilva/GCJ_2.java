import java.util.Comparator;
import java.util.PriorityQueue;
import java.util.Scanner;


public class GCJ_2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
Scanner scan = new Scanner(System.in);
		
		int T = scan.nextInt();
		scan.nextLine();
		
		int nCase = 1;
		while (T-- > 0) {
			
			int N = scan.nextInt();
			int S = scan.nextInt();
			int p = scan.nextInt();
			
			PriorityQueue<Integer> queue = new PriorityQueue<Integer>(10, new Comparator<Integer>() {

				@Override
				public int compare(Integer o1, Integer o2) {
					
					return o2.compareTo(o1);
				}
				
			});
			for (int i = 0; i < N; i++) {
				queue.add(scan.nextInt());
			}
			
			int output = 0;
			while (!queue.isEmpty() && S >= 0) {
				Integer i = queue.poll();
				//System.out.println(i);
				int r = i % 3;
				int q = i / 3;
				
				if (r != 0) q++;
				
				//dont need to be surprising
				if (q >= p) {
					output++;
					continue;
				}
				
				if (S == 0) break; //dont need continue processing
				if (q == 0) continue;
				//needs to use surprising
				S--;
				if (r == 0) //everybody is equal
				{
					q++;
				} else if (r == 1)  
				{
					//cant add
				} else {
					q++;
				}
				
				if (q >= p) output++;
				
			}
			
			
			scan.nextLine();
			
			System.out.println("Case #" + (nCase++) + ": " + output);
		}

	}

}
