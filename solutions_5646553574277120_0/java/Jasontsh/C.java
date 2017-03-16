import java.util.LinkedList;
import java.util.Scanner;


public class C {

	public static void main(String[] args) {
		Scanner reader = new Scanner(System.in);
		int testCases = reader.nextInt();
		for(int t = 0; t < testCases; t++){
			int repeats = reader.nextInt();
			int oldcoincount = reader.nextInt();
			int v = reader.nextInt();
			int[] oldcoins = new int[oldcoincount];
			LinkedList<Integer> list = new LinkedList<Integer>();
			for(int i = 0; i < oldcoincount; i++){
				oldcoins[i] = reader.nextInt();
				list.add(oldcoins[i]);
			}
			int answer = 0;
			for(int i = 1; i < v; i++){
				int count = 0;
				for(int j = list.size()-1; j>=0; j--){
					int r = 0;
					int lj = list.get(j);
					while(r < repeats && count + lj <= i){
						count += lj;
						r++;
					}
				}
				if(count == i){
					continue;
				}
				answer++;
				//add diff into the list
				boolean added = false;
				for(int j = 0; j < list.size(); j++){
					if(list.get(j) > i){
						list.add(j, i);
						added = true;
						break;
					}
				}
				if(!added){
					list.add(i);
				}
			}
				
			System.out.println("Case #" + (t+1) + ": " + answer);
			
		}
		reader.close();
	}

}
