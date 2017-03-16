import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;


public class Tiles {
	public static void main(String[] args) throws Exception {
	
		
		
		Scanner scan = new Scanner(new File("D-large.in"));
		int numCases = Integer.parseInt(scan.nextLine());
		for(int i = 1;i<=numCases;i++) {
			String line = scan.nextLine();
			String[] items = line.split("\\s+");
			int k = Integer.parseInt(items[0]);
			int c = Integer.parseInt(items[1]);
			int s = Integer.parseInt(items[2]);
			ArrayList<Long> answer = getTests(k,c,s);
			if(answer==null) {
				System.out.println("Case #" + i + ": IMPOSSIBLE");
			} else {
				System.out.print("Case #" + i + ":");
				for(Long ans : answer) {
					System.out.print(" " + ans);
				}
				System.out.println();
			}
			
		}
		
		
		
	}
	
	
	public static ArrayList<Long> getTests(int k, int c, int s) {
		ArrayList<Long> result = new ArrayList<Long>();
		if(s*c < k) {
			return null;
		}
		for(int base = 1;base<=k;base+=c) {
			//System.out.println("Starting from " + base);
			long target = base;
			int index = base;
			for(int depth = 2;depth<=c;depth++) {
				if(index<k) index++;
				target = (target-1)*k;
				target += index;
			//	System.out.println("After depth " + depth + " move to " + target);
				
				
			}
			result.add(target);
		}
		return result;
	}
}
