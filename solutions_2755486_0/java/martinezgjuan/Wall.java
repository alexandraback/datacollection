import java.io.FileNotFoundException;
import java.util.Scanner;


public class Wall {

	private static String solve(Scanner sc) {
		int n = sc.nextInt();
		
		int[] wall = new int[303*2]; 
		
		int[] d = new int[n]; // First attack
		int[] na = new int[n]; // Number of attacks
		int[] w = new int[n]; // Westmost
		int[] e = new int[n]; // Eastmost
		int[] s = new int[n]; // Strenght of first attack
		int[] delta_d = new int[n]; // Attack freq
		int[] delta_p = new int[n]; // Distance travelled
		int[] delta_s = new int[n]; // Change in stregth
		
		long total = 0;
		
		for(int i=0; i<n; i++){
			d[i] = sc.nextInt();
			na[i] = sc.nextInt();
			w[i] = sc.nextInt();
			e[i] = sc.nextInt();
			s[i] = sc.nextInt();
			delta_d[i] = sc.nextInt();
			delta_p[i] = sc.nextInt();
			delta_s[i] = sc.nextInt();
		}
		
		int maxDay = 750000;
		boolean[][] attDay = new boolean[n][maxDay];
		
		for(int i = 0; i<n; i++){
			for(int j = 0; j<na[i]; j++){
				attDay[i][d[i]+ j*delta_d[i]] = true;
				total++;
			}
		}
		

		int succ = 0;
		
		// For each day
		for(int day=0; day<maxDay || total<0; day++){
			
			int[] attack = new int[303*2]; // accumulated attack
			
			for(int t=0; t<n; t++){
				if(attDay[t][day]){

					total--;
					
					boolean hit = false;
					for(int i=w[t]+300; i<e[t]+300; i++){
						if(wall[i]<s[t]){
							hit = true;
							attack[i] = Math.max(attack[i], s[t]);
						}
					}
					
					if(hit) succ++;
					
					w[t]+=delta_p[t];
					e[t]+=delta_p[t];
					s[t]+=delta_s[t];
				}
			}
			
			for(int i = 0; i<2*300; i++){
				wall[i] = Math.max(wall[i], attack[i]);
			}
			
		}
		
		
		return succ+"";
	}
	
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            String s = "Case #" + (i + 1) + ": " + solve(in);
            System.out.println(s);
        }
    }

}
