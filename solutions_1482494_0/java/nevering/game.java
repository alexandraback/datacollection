import java.util.HashSet;
import java.util.Queue;
import java.util.Scanner;
import java.util.Set;
import java.util.PriorityQueue;

public class Solution {
	
	public static class Level implements Comparable<Level>{
		int level;
		int required;
		int gain;
		Level other;
		@Override
		public int compareTo(Level other) {
			// TODO Auto-generated method stub
			return required-other.required;
		}
	}
	
	public static void main(String[] args)
	{
		Scanner s = new Scanner(System.in);
		int size = s.nextInt();
		s.nextLine();
		Queue<Level> star1s = new PriorityQueue<Level>();
		Queue<Level> star2s = new PriorityQueue<Level>();
		Queue<Level> canTries = new PriorityQueue<Level>();
		
		
		for (int count = 1; count <= size; count++){
		//double result = 0;
		
		star1s.clear();
		star2s.clear();
		
		int level = s.nextInt();
		boolean[] completed = new boolean[level];
		int stars = 0;
		
		for (int i = 0; i < level; i ++)
		{
			completed[i] = false;
			Level l1 = new Level();
			Level l2 = new Level();
			
			l1.level = i;
			l2.level = i;
			
			l1.required = s.nextInt();
			l2.required = s.nextInt();
			
			l1.other = l2;
			l2.other = l1;
			
			l1.gain = 1;
			l2.gain = 2;
			
			star1s.add(l1);
			star2s.add(l2);
		}
		
		//System.out.println(level1s.size());
	
		
		int step = 0;
		boolean tooBad = false;
		
		while (stars != level * 2)
		{
			canTries.clear();
			while((!star1s.isEmpty()) && star1s.peek().required <= stars)
			{
				canTries.add(star1s.remove());
			}
			while((!star2s.isEmpty()) && star2s.peek().required <= stars)
			{
				canTries.add(star2s.remove());
			}
			Level toTry = null;
			Level pair = null;
			boolean twoStar = false;
			if (canTries.size() == 0){
				tooBad = true;
				break;
			}
			for (Level l : canTries)
			{
				//toTry = l;
				if ((l.gain == 2) && (!completed[l.level])){
					twoStar = true;
					break;
				}else if (l.gain == 2){
					toTry = l;
				}
			}
			
			if (toTry == null){
				toTry = canTries.peek();
			}
			
			//System.out.println("choosed -> " + (toTry.level+1) + "; " + toTry.gain);
			if (twoStar)
			{	
				pair = toTry.other;
				stars += 2;
				//System.out.println("gain 2 -> " + stars);
			}else{
				
				stars += 1;
				//System.out.println("gain 1 -> " + stars);
			}
			
			completed[toTry.level] = true;
			
			for (Level l : canTries)
			{
				if (l == toTry || l == pair)
				{
					continue;
				}else
				{
					if (l.gain == 1){
						star1s.add(l);
					}else{
						star2s.add(l);
					}
				}
			}
			
			step++;
		}
		
		if (tooBad)
		{
			System.out.println("Case #" + count+ ": " + "Too Bad");	
		}else
		{
			System.out.println("Case #" + count+ ": " + step);	
		}


		
		}
		
		
		
	}

}
