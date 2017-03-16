import java.io.File;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Dancing {

	public static void main(String[] args) throws IOException{
		Scanner sc = new Scanner(new File("dancing.in"));
		System.setOut(new PrintStream(new File("dancing.out")));
		ArrayList<Googler> changeAble = new ArrayList<Googler>(100);
		int t = sc.nextInt();
		for(int i=1; i<=t; i++){
			changeAble.clear();
			int n = sc.nextInt();//number of googlers
			int s = sc.nextInt();//number of surprises
			int p = sc.nextInt();//target
			int y = 0;//number that match
			for(int j=0; j<n; j++){
				Googler temp = new Googler(sc.nextInt(),p);
				if(temp.distAway < 1)
					y++;
				else if(temp.changeAble){
					changeAble.add(temp);
				}
			}
			Collections.sort(changeAble);
			for(int j=0; j<s && j<changeAble.size(); j++){
				Googler temp = changeAble.get(j);
				if(temp.maxScore+1 < p)
					break;
				y++;
			}
			System.out.println("Case #"+i+": "+y);
		}

	}

}
class Googler implements Comparable<Googler>{
	int distAway;
	boolean changeAble = false;
	int maxScore;
	int sScore;
	int score;
	int t;
	public Googler(int score, int target){
		t = target;
		this.score=score;
		int i = score/3;
		if(i*3==score){
			maxScore = i;
			changeAble = true;
		}
		else if(i*2+i+1 == score)
			maxScore = i+1;
		else if(i+(i+1)*2==score){
			maxScore = i+1;
			changeAble = true;
		}
		if(maxScore==0)
			changeAble = false;
		distAway = target-maxScore;
	}
	public int compareTo(Googler g){
		return distAway-g.distAway;
	}
	public String toString(){
		return score+"";
	}
}
