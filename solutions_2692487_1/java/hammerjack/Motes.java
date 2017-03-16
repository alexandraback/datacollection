import java.io.*;
import java.util.*;

public class Motes {

	public static void main(String[] args) throws IOException{
		Scanner input = new Scanner(new File("Motes.in"));
		PrintWriter out = new PrintWriter(new File("Motes.out"));
		int sets =input.nextInt(); input.nextLine();
		for(int x=0; x<sets; x++){
			int answer = 0;
			
			ArrayList<Integer> motes = new ArrayList<Integer>();
			int armin = input.nextInt(), numMotes = input.nextInt();
			for(int a=0; a<numMotes; a++)
				motes.add(input.nextInt());
		
			Collections.sort(motes);
						
			answer = answer(armin, motes, 0, 0);
			
			out.println("Case #"+(x+1)+": "+answer);
		}
		out.close();
	}
	
	public static int answer(int armin, ArrayList<Integer> motes, int at, int needed){
		//if(armin==1) return motes.size();
		for(; at<motes.size(); at++){
			int m = motes.get(at);
			if(armin>m) armin+=m;
			else {
				int[] add = addMotes(armin, m);
				int answer1 = Integer.MAX_VALUE, answer2 = Integer.MAX_VALUE;
				answer1 = answer(armin, motes, at+1, needed+1);
				if(add[1] != Integer.MAX_VALUE) 
					answer2 = answer(add[0], motes, at, needed+add[1]);
				needed = Math.min(answer1, answer2);
				break;
			}
		}
		return needed;
	}
	
	public static int[] addMotes(int armin, int next){
		int needed = 0;
		while(armin<=next){
			if(armin==1)
				return new int[] {Integer.MAX_VALUE, Integer.MAX_VALUE};
			armin+=armin-1;
			needed++;
		}
		if(armin==39)
			System.out.println(needed);
		return new int[]{armin, needed};
	}
	
}
