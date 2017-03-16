import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.Scanner;



public class B {

	
//	public int[] walk(int xGoal, int yGoal){
//		
//		if(xGoal)
//		
//		int[] answer;
//		
//		
//		return answer;
//	}
	
	
	public void genAnswer(String filename) throws FileNotFoundException{
		
		Scanner sc = new Scanner(new File(filename+".in"));
		PrintStream ps = new PrintStream(new File(filename+".out"));
		
		int caseCnt = sc.nextInt();
		int xGoal, yGoal;
		
		for(int itr=1; itr<=caseCnt ;itr++){	
			xGoal = sc.nextInt(); yGoal = sc.nextInt();
//			int answer[] = walk(xGoal, yGoal);
			
			String answer = "";
			if(xGoal>0){
				for(int i=0;i<xGoal;i++) answer += "WE";
			}
			else if(xGoal<0){
				int temp = Math.abs(xGoal);
				for(int i=0;i<temp;i++) answer += "EW";
			}
			
			if(yGoal>0){
				for(int i=0;i<yGoal;i++) answer += "SN";
			}
			else if(yGoal<0){
				int temp = Math.abs(yGoal);
				for(int i=0;i<temp;i++) answer += "NS";
			}
			
			System.out.printf("Case #%d: %s\n", itr, answer);
			ps.printf("Case #%d: %s\n", itr, answer);
		}
		
	}
	
	public static void main(String[] args) throws FileNotFoundException {
		B b = new B();	
		b.genAnswer("B-small-attempt0 (1)");

	}

}
