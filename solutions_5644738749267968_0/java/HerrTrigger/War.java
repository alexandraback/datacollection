import java.util.*;
import java.lang.*;

public class War{
	public static void main(String[] args){
		Scanner scan = new Scanner(System.in);
		int num_problems = Integer.parseInt(scan.nextLine());
		for(int case_no = 1; case_no <= num_problems; case_no++) {
			int size = Integer.parseInt(scan.nextLine());
			ArrayList<Float> blocks_naomi 	= new ArrayList<Float>();
			ArrayList<Float> blocks_ken 	= new ArrayList<Float>();
			String[] ns = scan.nextLine().split(" ");
			String[] ks = scan.nextLine().split(" ");
			
			for (int i = 0; i < size; i++){
				blocks_naomi.add(Float.valueOf(ns[i]));	
				blocks_ken.add(Float.valueOf(ks[i]));
			}
		
			Collections.sort(blocks_naomi);
			Collections.sort(blocks_ken);
			// String a = "";
			// String b = "";
			// for ( int i = 0; i < size; i++) {
				// a += blocks_naomi.get(i) + " ";
				// b += blocks_ken.get(i) + " ";
			// }
			// System.out.println(a + "\n" + b);
			
			System.out.println("Case #" + case_no + ": " + deceitfulWar(blocks_naomi, blocks_ken) + " " + fairWar(blocks_naomi, blocks_ken));
			
			
			
		}
		scan.close();		
	}
	
	public static int fairWar(ArrayList<Float> blocks_naomi, ArrayList<Float> blocks_ken){
		int score = 0;
		ArrayList<Float> bk = cloneBlocks(blocks_ken);
		for (int i = blocks_naomi.size() - 1; i >= 0; i--) { // Naomi chaoses the largest 
			if (blocks_naomi.get(i).floatValue() > kenChoice(bk, blocks_naomi.get(i).floatValue())){
				score++;
			}
		}		
		return score;
	}
	
	public static int deceitfulWar(ArrayList<Float> blocks_naomi, ArrayList<Float> blocks_ken){
		int score = 0;
		ArrayList<Float> bn = cloneBlocks(blocks_naomi);
		ArrayList<Float> bk = cloneBlocks(blocks_ken);
		double scale = 0.000001;
		while (bn.size() > 0 && bk.size() > 0){
			while ( bn.size() > 0 && bk.size() > 0 && bn.get(0) < bk.get(0)) {
				if (bn.get(0).floatValue() > kenChoice(bk, (new Double(bk.get(bk.size() - 1).floatValue() - 0.000001)).floatValue())){
					score++;
				}
				bn.remove(0);
			}
			
			while(bn.size() > 0 && bk.size() > 0 && bn.get(0) > bk.get(0)){
				if (bn.get(0).floatValue() > kenChoice(bk, (new Double(bk.get(bk.size() - 1).floatValue() + scale)).floatValue())){
					score++;
					scale = scale / 2;
				}
				bn.remove(0);
			}
		}
		// for (int i = bn.size() - 1; i >= 0; i--) { // Naomi chaoses the largest 
			// if (bn.get(i).floatValue() > kenChoice(bk, bn.get(i).floatValue())){
				// score++;
			// }
		// }		
		
		
		
		return score;
		
	}
	
	// will edit blocks_ken
	public static float kenChoice(ArrayList<Float> blocks, float naomi_choice) {	
		for (int i = 0; i < blocks.size(); i++) {
			if (blocks.get(i).floatValue() > naomi_choice){
				return blocks.remove(i); // can win, return smallest winner
			}
		}
		return blocks.remove(0); // cant win, return smallest
	}
	
	public static ArrayList<Float> cloneBlocks(ArrayList<Float> blocks){
		ArrayList<Float> new_blocks = new ArrayList<Float>();
		for ( int i = 0; i < blocks.size(); i++) {
			new_blocks.add(Float.valueOf(blocks.get(i).floatValue()));
		}
		return new_blocks;
	}
}