package QualificationRound;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.PriorityQueue;
import java.util.Scanner;

public class P2InfiniteHouseOfPancakes {
	private static int best;
	public static int indexOfMax(ArrayList<Integer> q)
	{
		int index = 0;
		for(int i = 1; i < q.size(); i++)
			if(q.get(i) > q.get(index))
				index = i;
		return index;
	}
	public static void numberOfMin(ArrayList<Integer> q, int cut)
	{
		if( cut >= best )
			return;
		int index = indexOfMax(q);
		int n = q.size();
		q.add(0);
		int max = q.get(index);
		if(max + cut < best)
			best = max + cut;
		for(int i = 2; i <= max / 2; i++)
		{
			q.set(index, max - i);
			q.set(n, i);
			numberOfMin(q, cut + 1);
		}
		q.remove(q.size() - 1);
		q.set(index, max);
	}
	public static int numberOfMinites(PriorityQueue<Integer> q)
	{
		int best = q.peek();
		int cut = 0;
		while(cut < best)
		{
			int max = q.remove();
			if(max + cut < best)
				best = max + cut;
			cut++;
			q.add(max / 2);
			q.add(max - max / 2);
		}
		return best;
	}
	public static void main(String[] args) {

		File fin = new File("src/QualificationRound/B-small-attempt2.in");
		Scanner scan;
		try {
			scan = new Scanner(fin);
		
			PrintWriter output = new PrintWriter("src/QualificationRound/B-small-attempt2.out.txt");
			int N = scan.nextInt();
			for(int i = 0; i < N; i++)
			{
				int n = scan.nextInt();
//				PriorityQueue<Integer> q = new PriorityQueue<Integer>(Collections.reverseOrder());
				ArrayList<Integer> q = new ArrayList<Integer>();
				for(int j = 0; j < n; j++)
					q.add(scan.nextInt());
				best = q.get(indexOfMax(q));
//				output.println("Case #" + (i + 1) + ": " + numberOfMinites(q));
				numberOfMin(q, 0);
				output.println("Case #" + (i + 1) + ": " + best);
//				output.println(q);
				
			}
			scan.close();
			output.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}
}
