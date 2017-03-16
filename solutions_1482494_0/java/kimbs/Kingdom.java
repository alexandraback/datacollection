import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.StringTokenizer;


public class Kingdom {
	
	static class cost{
		int cost1;
		int cost2;
		int level;
		boolean isDone1;
		boolean isDone2;
		int money2;
		
		public cost(int cost1, int cost2, int level){
			this.cost1 = cost1;
			this.cost2 = cost2;
			this.level = level;
			isDone1 = false;
			isDone2 = false;
			money2= 0 ;
		}
	}
	
	static class Ret{
		int level;
		int earn;
		public Ret(int level, int earn){
			this.level = level;
			this.earn = earn;
		}
	}
	
	public static String solve(int level, List<cost> stage) {
		String result = "";
		
		int money = 0;
		Ret val;
		int cnt = 0;
		Set<Integer> set = new HashSet<Integer>();
		
		while(true){
			val = complete(stage, money);
			if (val.level == -1)
				return "Too Bad";
			
			money += val.earn;
			cnt++;
			if (val.level > 0){
				set.add(val.level);
				if (set.size() == level)
					break;
			}
		}
		
		result = ""+cnt;
		
		return result;
	}
	
	public static Ret complete(List<cost> levels, int money){
		int index = -1;
		int max = -1;
		for (int i = 0; i < levels.size(); i++){
			cost c = levels.get(i);
			if (money >= c.cost2 && c.cost2 > max && !c.isDone2){
				max = c.cost2;
				index = i;
			}
		}
		if (index != -1){
			cost c = levels.get(index);
			c.isDone2 = true;
			c.money2 = money;
			if (c.isDone1){
				return new Ret(c.level, 3);
			}
			else
				return new Ret(c.level, 2);
		}
		
		int min = 10000;
		index = -1;
		for (int i = 0; i < levels.size(); i++){
			cost c = levels.get(i);
			if (money >= c.cost1 && c.cost1 < min && !c.isDone1){
				min = c.cost1;
				index = i;
			}
		}
		if (index != -1){
			cost c = levels.get(index);
			c.isDone1 = true;
			if (c.isDone2){
				if (c.money2 >= money){
					return new Ret(0, 2);
				}
				else
					return new Ret(0, 1);
			}
			else
				return new Ret(0, 1);
		}
		
		return new Ret(-1, 0);
	}
	
	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int T = 0;
		String str = "";
		
		File input = new File(args[0]);
		FileReader fileReader;
		BufferedReader br;
		
		File output = new File("output_kingdom.txt");
		BufferedWriter bw;

		StringTokenizer tokenizer;
		
		try {
			bw = new BufferedWriter(new FileWriter(output));
			
			fileReader = new FileReader(input);
			br = new BufferedReader(fileReader);
			str = br.readLine();
			
			T = Integer.parseInt(str);
			
			for (int i = 0; i < T; i++) {
				int level;
				List<cost> stage;
				
				str = br.readLine();
				level = Integer.parseInt(str);
				
				stage = new LinkedList<cost>();
				for (int j = 0; j < level; j++){
					int n, m;
					
					str = br.readLine();
					tokenizer = new StringTokenizer(str);
					n = Integer.parseInt(tokenizer.nextToken());
					m = Integer.parseInt(tokenizer.nextToken());
					
					stage.add(new cost(n, m, (j+1)));
				}
				bw.write(String.format("Case #%d: %s\n", i+1, solve(level, stage)));
			}
			
			fileReader.close();
			br.close();
			
			bw.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		
	}

}
