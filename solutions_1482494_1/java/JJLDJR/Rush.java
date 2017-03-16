import java.util.Scanner;


public class Rush {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		
		int cases = Integer.parseInt(sc.nextLine());
		
		for(int c = 0; c < cases; c++) {
			Scanner line = new Scanner(sc.nextLine());
			
			int n = line.nextInt();
			
			int[] a = new int[n];
			int[] b = new int[n];
			
			for(int lev = 0; lev < n; lev++) {
				line = new Scanner(sc.nextLine());
				a[lev] = line.nextInt();
				b[lev] = line.nextInt();
			}
			
			int[] starsleft = new int[n];
			for(int i = 0; i < n; i++) {
				starsleft[i] = 2;
			}
			
			
			int stars = 0;
			
			int addcount = 0;
			
			while(stars < 2*n) {
				int biggest = -1;
				int biggestb = -1;
				
				boolean didone = false;
				
				for(int i = 0; i < n; i++) {
					if(starsleft[i] > 0) {
						if(b[i] <= stars) {
							//Might as well do it now
							stars += starsleft[i];
							starsleft[i] = 0;
							didone = true;
							addcount++;
							break;
						}
						else {
							if(a[i] <= stars && starsleft[i] == 2) {
								//only do the biggest bi
								if(b[i] > biggestb) {
									biggest = i;
									biggestb = b[i];
								}
							}
						}
					}
				}
				
				if(didone) {
					continue;
				}
				else {
					if(biggest == -1) {
						//none left
						break;
					}
					else {
						stars += 1;
						starsleft[biggest] = 1;
						addcount++;
					}
				}
				
			}
			
			if(stars < 2*n) {
				System.out.printf("Case #%d: Too Bad\n", c+1);
			}
			else {
				System.out.printf("Case #%d: %d\n", c+1, addcount);
			}

		}

	}

}
