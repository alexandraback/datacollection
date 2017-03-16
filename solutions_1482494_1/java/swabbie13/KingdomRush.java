import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Scanner;


public class KingdomRush {
	public static void main(String[] args){
		Scanner in;
		try {
			in = new Scanner(new File("B-large (1).in"));
			KingdomRush test = new KingdomRush();
			test.solve(in);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}
	public void solve(Scanner in){

		int cases =in.nextInt();
		for(int i = 1; i<=cases; i++){
			int levelCount = in.nextInt();
			int score =0;
			int turns =0;
			ArrayList<Level> levels = new ArrayList<Level>();
			for(int j =0; j<levelCount; j++){
				int oneStar = in.nextInt();
				int twoStar = in.nextInt();
				Level newLevel =  new Level(oneStar,twoStar);
				levels.add(newLevel);

			}
			boolean skip = false;
			while(score<levelCount*2){
				boolean found = false;
				Level foundLevel = null;
				for(Level l: levels){
					if(!l.twoStar&&l.canCompleteTwoStar(score)){
						if(!l.oneStar){
							score +=2;
							l.oneStar = true;
							l.twoStar=true;
							turns++;
							found = true;
							break;
						}
						else{
							score +=1;
							l.oneStar = true;
							l.twoStar=true;
							turns++;
							found = true;
							break;
						}
					}	
				}
				if(!found){
					for(Level l: levels){
						if(!l.oneStar&&l.canCompleteOneStar(score)){
							if(foundLevel==null){
								foundLevel = l;
								found = true;
							}
							if(foundLevel.twoStarReq<l.twoStarReq){
								foundLevel = l;
							}
							
						}
					}
					if(!found){
						System.out.println("Case #" +i+": Too Bad");
						skip = true;
						break;
					}
					else{
						score+=1;
						foundLevel.oneStar=true;
						turns++;
					}
				}
			}
			if(!skip){
				System.out.println("Case #" +i+": "+ turns);
			}
		}

	}

	public class Level{
		boolean oneStar;
		boolean twoStar;
		public int oneStarReq;
		public int twoStarReq;
		public Level(int oneStarReq, int twoStarReq){
			this.oneStarReq = oneStarReq;
			this.twoStarReq = twoStarReq;
		}
		public boolean canCompleteTwoStar(int score){
			if(score>=twoStarReq){
				return true;
			}
			return false;
		}
		public boolean canCompleteOneStar(int score){
			if(score>=oneStarReq){
				return true;
			}
			return false;
		}
	}


}
