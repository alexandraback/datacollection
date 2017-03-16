import java.io.File;
import java.util.Scanner;


public class Ovation {
	public static void main(String[] args) throws Exception {
		
		Scanner s = new Scanner(new File("A-small-attempt0.in"));
		
		int numCases = Integer.parseInt(s.nextLine());
		for(int currentCase = 1;currentCase<=numCases;currentCase++) {
			String line = s.nextLine();
			String[] items = line.split("\\s+");
			int maxShyness = Integer.parseInt(items[0]);
			String shynessString = items[1];
			int[] counts = new int[maxShyness+1];
			for(int i = 0;i<=maxShyness;i++) {
				counts[i] = Integer.parseInt(""+shynessString.charAt(i));
				
			}
			System.out.println("Case #" + currentCase + ": " + minInvites(counts));
		}
	}
	
	
	public static int minInvites(int[] counts) {
		int standing = counts[0];
		int invites = 0;
		for(int i = 1;i<counts.length;i++) {
			if(standing<i) {
				invites += i-standing;
				standing += i-standing;
			}
			standing+=counts[i];
		}
		
		return invites;
	}
}
