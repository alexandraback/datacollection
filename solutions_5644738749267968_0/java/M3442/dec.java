import java.util.Arrays;
import java.util.Scanner;


public class dec {
	public static void main(String args[]){
		Scanner f = new Scanner(System.in);
		int t = Integer.parseInt(f.nextLine());
		for(int i = 0; i < t; i++){
			int num = Integer.parseInt(f.nextLine());
			Double[] n = new Double[num];
			Double[] k = new Double[num];
			String[] cur1 = f.nextLine().split(" ");
			String[] cur2 = f.nextLine().split(" ");
			for(int j = 0; j < cur1.length; j++){
				n[j] = (i(cur1[j]));
				k[j] = (i(cur2[j]));
			}
			Arrays.sort(n);
			Arrays.sort(k);
			int loc = 0; int wins = 0;
			for(int j = 0; j < n.length; j++){
				while(loc < k.length && k[loc] < n[j]){
					loc++;
				}
				if(loc < k.length){
					wins++;
				}
				loc++;
			}
			int y = k.length - wins;
			
			loc = 0; wins = 0;
			for(int j = 0; j < k.length; j++){
				while(loc < n.length && n[loc] < k[j]){
					loc++;
				}
				if(loc < n.length){
					wins++;
				}
				loc++;
			}
			System.out.println("Case #" + (i + 1) + ": " + wins + " " + y);
		}
	}
	public static double i(String s){ return Double.parseDouble(s);}
}
