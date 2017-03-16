import java.util.Scanner;


public class BoxFactory {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		
		//number of case tests
		int test_cases;
		test_cases = scanner.nextInt();
		scanner.nextLine();
		
		
		int n, m;
		long[] a, atype, b, btype;
		
		for(int t=1; t<= test_cases; t++){
			n = scanner.nextInt();
			m = scanner.nextInt();
			scanner.nextLine();
			
			a = new long[n]; atype = new long[n];
			b = new long[m]; btype = new long[m];
			
			for (int i = 0; i < n; i++) {
				a[i] = scanner.nextLong();
				atype[i] = scanner.nextLong();
			}
			scanner.nextLine();
			for (int i = 0; i < m; i++) {
				b[i] = scanner.nextLong();
				btype[i] = scanner.nextLong();
			}
			scanner.nextLine();
			
			
			long max_sum = 0;
			int x = 0, y = 0;
			
			while(x<n && y<m){
				if(atype[x] == btype[y]){
					long min = Math.min(a[x], b[y]);
					a[x] -= min;
					b[y] -= min;
					
					max_sum += min;
					
					if(a[x] == 0) x++;
					if(b[y] == 0) y++;
				}
				else{
					
					boolean founda  = false;
					long lost_for_a = 0;
					int next_y;
					for (next_y = y; next_y < m; next_y++) {
						
						if(atype[x] == btype[next_y]){
							founda=true;
							lost_for_a -= Math.min(a[x],b[next_y]);
							break;
						}
						
						lost_for_a += b[next_y];
					}
					
					boolean foundb  = false;
					long lost_for_b = 0;
					int next_x;
					for (next_x = x; next_x < n; next_x++) {
						
						if(atype[next_x] == btype[y]){
							foundb = true;
							lost_for_b -= Math.min(a[next_x], b[y]); 
							break;
						}
						
						lost_for_b += a[next_x];
					}
					
					if(!founda)
						x++;
					if(!foundb)
						y++;
					if(founda && foundb){
						if(lost_for_a > lost_for_b)
							x ++;
						else
							if(lost_for_a < lost_for_b)
								y ++;
							else{
								if((next_y - y) > (next_x-x))
									y++;
								else
									x++;
							}
					}
				}
				
			}
			
			System.out.println("Case #" + t + ": " + max_sum);			
		}
	}

}
