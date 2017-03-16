import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Scanner;


public class safety {
	
	public static void main(String[] args) throws FileNotFoundException{
		Scanner s = new Scanner(new File("A-large.in"));
		
		int nbcase = s.nextInt();
		for(int i=0; i<nbcase; i++){
			int n= s.nextInt();
			int[] scores = new int[n];
			LinkedList<Integer> list = new LinkedList<Integer>();
			int x=0;
			for(int j=0; j<n; j++){
				int val = s.nextInt();
				list.add(val);
				x+=val;
				scores[j]=val;
			}
			Collections.sort(list);
			//System.out.println(list);
			System.out.print("Case #"+(i+1)+":");
			double val = minvalue(scores, list, i, x);
			
			//System.out.println("val: "+val);
			for(int j=0; j<n; j++){
				System.out.print(" "+Math.max(0, (val-scores[j])/x)*100);
			}
			System.out.println();
		}
	}

	private static double minvalue(int[] scores,LinkedList<Integer> list, int i, double X) {
		if(scores.length<2){
			return 0.;
		}
		Iterator<Integer> it = list.iterator();
		int current = it.next();
		int next = it.next();
		double quota=1;
		int nbsmall=1;
		while(true){
			if((next-current)*nbsmall>quota*X){
				return current+X*quota/nbsmall;
			}
			else{
				quota-= (next-current)*nbsmall/X;
			}
			current=next;
			if(!it.hasNext()){
				return next+quota*X/(nbsmall+1);
			}
			next = it.next();
			nbsmall++;
		}
	}
}
