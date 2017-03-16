import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class D {
	
	
	public static int play_war(ArrayList<Double> naomis, ArrayList<Double> kens){
		final int size = naomis.size();
		
		int score = 0;
		for(int i = 0; i < size; i++){
			final double naomi = naomis.get(0);
			
			int ken_pos = Collections.binarySearch(kens, naomi);
			if(ken_pos < 0){ ken_pos = -(ken_pos + 1);}
			
			naomis.remove(0);
			if(ken_pos >= kens.size()){
				score++;
				kens.remove(0);
			}else{
				kens.remove(ken_pos);
			}
		}
		
		return score;
	}
	
	public static int play_d_war(ArrayList<Double> naomis, ArrayList<Double> kens){
		final int size = naomis.size();
		
		int score = 0;
		for(int i = 0; i < size; i++){
			final double naomi = naomis.get(0);
			
			final double ken_max = kens.get(kens.size() - 1);
			final double ken_min = kens.get(0);
			
			naomis.remove(0);
			if(naomi > ken_min){
				score++;
				kens.remove(0);
			}else if(naomi > ken_max){
				score++;
				kens.remove(0);
			}else{
				kens.remove(kens.size() - 1);
			}
		}
		
		return score;
	}
	
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		final int T = sc.nextInt();
		
		for(int tc = 0; tc < T; tc++){
			final int tc_index = tc + 1;
			
			final int size = sc.nextInt();
			
			ArrayList<Double> naomis = new ArrayList<Double>();
			ArrayList<Double> kens = new ArrayList<Double>();
			for(int i = 0; i < size; i++){
				naomis.add(sc.nextDouble());
			}
			for(int i = 0; i < size; i++){
				kens.add(sc.nextDouble());
			}
			
			Collections.sort(naomis);
			Collections.sort(kens);
			
			final int normal = play_war(new ArrayList<Double>(naomis), new ArrayList<Double>(kens));
			final int other = play_d_war(new ArrayList<Double>(naomis), new ArrayList<Double>(kens));
			
			
			//System.out.println(naomis + "\n" + kens);
			
			
			System.out.printf("Case #%d: %d %d\n", tc_index, other, normal);
		}
	}
	
}
