

import java.util.Scanner;

import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.Double.parseDouble;
import static java.lang.Float.parseFloat;

public class Ovations {
	public static Scanner s = new Scanner(System.in);
	
	public static void main(String[] args) {
		int n = parseInt(s.nextLine());
		
		for (int i=1 ; i<=n ; i++) {
			System.out.print("Case #" + i + ": ");
			
			run();
		}
	}
	
	public static void run() {
		String[] line = s.nextLine().split(" ");
		
		int n = parseInt(line[0])+1;
		int audience[] = new int[n];
		
		for (int i=0 ; i<n ; i++) {
			audience[i] = (int)(line[1].charAt(i) - '0');
		}
		
		int stand = audience[0], add = 0;
		for (int i=1 ; i<n ; i++) {
			if (stand < i) {
				int diff = i - stand;
				
				stand += diff;
				add += diff;
			}
			
			stand += audience[i];
		}
		
		System.out.println(add);
	}
	
}
