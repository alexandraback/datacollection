import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;


public class KingdomRush {

	public class Level{
		int l1;
		int l2;
		boolean f1;
		boolean f2;
		
		public Level(int l1, int l2){
			this.l1 = l1;
			this.l2 = l2;
		}
	}
	
	public String solve(String[] input){
		List<Level> list = new ArrayList<Level>();
		for(String s : input){
			String[] sp = s.split("\\s");
			list.add(new Level(Integer.parseInt(sp[0]), Integer.parseInt(sp[1])));
		}
		
		int star = 0;
		int step = 0;
		while(list.size() > 0){
			boolean move = false;
			
			for(int i = 0 ; i < list.size(); i++){
				Level l = list.get(i);
				if(l.l2 <= star){
					if(l.f1)
						star++;
					else
						star += 2;
					
					move = true;
					list.remove(i);
					step++;
					break;
				}
			}
			if(move)
				continue;
			
			Level n = null;
			for(int i = 0; i < list.size(); i++){
				Level l = list.get(i);
				if(!l.f1 && l.l1 <= star){
					if(n == null)
						n = l;
					else if(n.l2 <= l.l2)
						n = l;
				}
			}
			
			if(n != null){
				star ++;
				step++;
				n.f1 = true;
				move = true;
			}
			
			if(!move)
				return "Too Bad";
		}
		return Integer.toString(step);
	}
	
	
	public static void main(String[] args) throws FileNotFoundException {
		KingdomRush k = new KingdomRush();
		
		File f = new File(args[0]);
		Scanner sc = new Scanner(f);
		int l = Integer.parseInt(sc.nextLine());
		for(int i = 1; i <= l ;i++){
			int lc  = Integer.parseInt(sc.nextLine());
			String[] input = new String[lc];
			for(int j = 0; j < lc; j++)
				input[j] = sc.nextLine();

			System.out.printf("Case #%d: %s\n", i, k.solve(input));
		}
	}

}
