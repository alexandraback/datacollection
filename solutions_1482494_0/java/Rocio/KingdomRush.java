import java.util.*;

public class KingdomRush {
	
	
	
	public int solve(int[] one, int[] two){
		int earned = 0;
		int levels = 0;
		TreeSet<LevelOne> trone = new TreeSet<LevelOne>();
		TreeSet<LevelTwo> trtwo = new TreeSet<LevelTwo>();

		for(int i = 0; i<one.length;i++){
			LevelOne lo = new LevelOne(i, one[i], two[i]);
			LevelTwo lt = new LevelTwo(i, two[i]);
			lo.addLevelTwo(lt);
			lt.addLevelOne(lo);
			trone.add(lo);
			trtwo.add(lt);
		//	System.out.println("i: "+i+" one: "+one[i]+ " two "+two[i]);
		}
		while(!trtwo.isEmpty()){
			LevelTwo lt = trtwo.first();
			if(lt.two <=earned){
				if(trone.contains(lt.link)){
					earned+=2;
					trtwo.remove(lt);
					trone.remove(lt.link);
				}else {
					earned++;
					trtwo.remove(lt);
				}
				levels++;
				continue;
			}
			else{
				if(!trone.isEmpty()){
					LevelOne lo = trone.first();
					if(lo.one <= earned){
						earned++;
						levels++;
						trone.remove(lo);
						continue;
					} else {  //one star levels but not enough stars
						return -1;
					}
				}else{ //no more levels reachable
					return -1;
				}
			}
		}
		return levels;
	}
	
	public static void main(String args[]){
	
		Scanner s = new Scanner(System.in);
		int T = s.nextInt();
		
		for(int i = 1; i<=T; i++){
			int n = s.nextInt();
			int[] one = new int[n];
			int[] two = new int[n];
			
			for(int j = 0; j< n; j++){
				one[j] = s.nextInt();
				two[j] = s.nextInt();
			}
			KingdomRush kr = new KingdomRush();
			int y = kr.solve(one, two);
			if(y>=0){
				System.out.println("Case #"+i+": "+y);
			}else {
				System.out.println("Case #"+i+": Too Bad");
			}
		}

	}
	
	class LevelOne implements Comparable<LevelOne>{
		int index, one;
		LevelTwo link;
		int two;
		LevelOne(int index, int one, int two){
			this.index = index;
			this.one = one;
			this.two = two;
		}
		
		public void addLevelTwo(LevelTwo link){
			this.link = link;
		}
		public int compareTo(LevelOne other){
			if(one!=other.one){
				return one - other.one;
			}
			else{
				if(two!=other.two){
					return other.two - two;
				}
			}
			return index - other.index;
			
		}

		public String toString(){
			return "index "+index+" :"+one;
		}
	}
	
	class LevelTwo implements Comparable<LevelTwo>{
		int index, two;
		LevelOne link;
		LevelTwo(int index, int two){
			this.index = index;
			this.two = two;
		}
		public int compareTo(LevelTwo other){
			if(two!=other.two)
				return two - other.two;
			else
				return index - other.index;
		}
		
		public void addLevelOne(LevelOne link){
			this.link = link;
		}
		public String toString(){
			return "index "+index+" :"+two;
		}
		
	}
}