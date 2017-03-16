import java.util.*;
public class BNewMain {
	
	public static int best(ArrayList<Integer> into, int time, int halt){
		ArrayList<Integer> food = new ArrayList<Integer>(into);
		if(time > halt){
			return 1001;
		}
		else{
			int max = 0;
			int maxPos = 0;
			for(int i = 0;i<food.size();i++){
				if(food.get(i)>max){
					max = food.get(i);
					maxPos = i;
				}
			}
			int stop = max / 2;
			int best = max + time;
			for(int s = 1; s <= stop; s++){
				food.add(s);
				food.set(maxPos, max-s);
				best =  Math.min(best, best(food, time+1, halt));
			}
			return best;
		}
	}
	
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		
		int cases = in.nextInt();
		
		for(int i = 0; i < cases; i++){
			System.out.print("Case #");
			System.out.print(i+1);
			System.out.print(": ");
			int D = in.nextInt();
			ArrayList<Integer> Plates = new ArrayList<Integer>();
			int max = 0;
			for(int j = 0;j<D;j++){
				int term = in.nextInt();
				if(term>max)
					max = term;
				Plates.add(term);
			}
			System.out.println(best(Plates, 0, max));
		}
	}
}
