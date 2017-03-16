import java.io.File;
import java.io.PrintWriter;
import java.util.*;


public class KingdomRush {
	public static void main(String[] args) throws Exception{
		Scanner scanner = new Scanner(new File("B-small-attempt5.in"));
		int num = scanner.nextInt();
		scanner.nextLine();
		PrintWriter writer = new PrintWriter(new File("KingdomRushAnswer.txt"));
		for(int a = 1;a<=num;a++) {
			int N = scanner.nextInt();
			List<Level> ones = new ArrayList<Level>();
			List<Level> twos = new ArrayList<Level>();
			for(int i = 0;i<N;i++) {
				int one=scanner.nextInt();
				int two=scanner.nextInt();
				Level level = new Level(i, one,two);
				ones.add(level);
				twos.add(level);
			}
			Collections.sort(ones, new OneComparator());
			Collections.sort(twos, new TwoComparator());
			System.out.println(ones);
			System.out.println(twos);
			int stars = 0;
			int levels = 0;
			while(twos.size()>0) {
				levels++;
				if(stars>=twos.get(0).two) {
					Level level = twos.remove(0);
					stars+=level.doneTwo();
					ones.remove(level);
				} else if(ones.size()>0 && stars>=ones.get(0).one){
					Level maxLevel = ones.get(0);
					for(Level level: ones) {
						if(level.two>maxLevel.two) 
							maxLevel=level;
						if(level.one>stars) break;
					}
					ones.remove(maxLevel);
					maxLevel.doneOne();
					stars+=1;
				} else {
					levels=-1;
					break;
				}
				//System.out.println(levels + ": " + stars);
			}
			if(levels==-1) {
				writer.println("Case #" + a + ": Too Bad");
				System.out.println("Case #" + a + ": Too Bad");				
			} else {
				writer.println("Case #" + a + ": " + levels);
				System.out.println("Case #" + a + ": " + levels);	
			}
			writer.flush();
			
		}
		writer.close();
	}
}

class Level {
	public int level;
	public int one;
	public int two;
	
	public boolean oneDone;
	public boolean twoDone;
	public Level(int level, int one, int two) {
		this.level=level;
		this.one=one;
		this.two=two;
	}
	
	public int doneOne() {
		oneDone=true;
		return 1;
	}
	
	public int doneTwo() {
		twoDone=true;
		if(oneDone) {
			return 1;
		} else {
			return 2;
		}
	}
	
	public String toString() {
		return "("  + one + ", " + two + ")";
	}
}

class OneComparator implements Comparator<Level> {
	public int compare(Level arg0, Level arg1) {
		if(arg0.one!=arg1.one)
			return arg0.one-arg1.one;
		else 
			return arg1.two-arg0.two;
	}
}

class TwoComparator implements Comparator<Level> {
	public int compare(Level arg0, Level arg1) {
		if(arg0.two!=arg1.two)
			return arg0.two-arg1.two;
		else 
			return arg0.one-arg1.one;
	}
}
