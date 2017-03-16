
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.Scanner;


public class Q1 
{

	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		
		int num = sc.nextInt();
		
		for(int i = 0; i < num ; i++)
		{
			int numbox = sc.nextInt();
			int numtoy = sc.nextInt();
			
			//G[] box = new G[numbox];
			//G[] toy = new G[numtoy];
			LinkedList<G> boxl = new LinkedList<G>();
			LinkedList<G> toyl = new LinkedList<G>();
			
			for(int q = 0; q < numbox; q++)
			{
				G curr = new G();
				curr.num = sc.nextLong();
				curr.type = sc.nextLong();
				boxl.add(curr);
			}
			
			for(int w = 0; w < numtoy; w++)
			{
				G curr = new G();
				curr.num = sc.nextLong();
				curr.type = sc.nextLong();
				toyl.add(curr);
				
			}
			
			
			for(int h = 0; h < 2000; h++)
			{

				//
				LinkedList<G> newbox = new LinkedList<G>();
				
				ListIterator<G> toyi = toyl.listIterator();
				ListIterator<G> boxi = boxl.listIterator();
				while(toyi.hasNext())
				{
					G currtoy = toyi.next();
					while(boxi.hasNext())
					{
						G currbox = boxi.next();
						if(currbox.type != currtoy.type 
								|| (currbox.type == currtoy.type && currbox.num <= currtoy.num))
						{ 
							newbox.add(currbox);
							continue; 
						}
						
						long diff = currbox.num - currtoy.num;
						currbox.num = currtoy.num;
						
						G newg = new G();
						newg.type = currbox.type;
						newg.num = diff;
						newbox.add(currbox);
						newbox.add(newg);
					}
				}
				boxl = newbox;
				//
				
				
				
				//
				
				LinkedList<G> newtoy = new LinkedList<G>();
				
				toyi = toyl.listIterator();
				boxi = boxl.listIterator();
				while(boxi.hasNext())
				{
					G currbox = boxi.next();
					while(toyi.hasNext())
					{
						G currtoy = toyi.next();
						if(currtoy.type != currbox.type 
								|| (currtoy.type == currbox.type && currtoy.num <= currbox.num))
						{ 
							newtoy.add(currtoy);
							continue; 
						}
						
						long diff = currtoy.num - currbox.num;
						currtoy.num = currbox.num;
						
						G newg = new G();
						newg.type = currtoy.type;
						newg.num = diff;
						newtoy.add(currtoy);
						newtoy.add(newg);
					}
				}
				toyl = newtoy;
				//
			}
			
			G[] box = boxl.toArray(new G[0]);
			G[] toy = toyl.toArray(new G[0]);
			
			numbox = box.length;
			numtoy = toy.length;
			
			long[][] array = new long[numbox+1][numtoy+1];
			
			
			for(int z = 0; z < numbox+1; z++)
			{
				array[z][0] = 0;
			}
			
			for(int t = 0; t < numtoy+1; t++)
			{
				array[0][t] = 0;
			}
			
			for(int y = 1; y < numtoy+1; y++)
			{
				for(int x = 1; x < numbox+1; x++)
				{
					long adjmax = Math.max(array[x-1][y], array[x][y-1]);
					long addmax = 0;
					if(box[x-1].type == toy[y-1].type)
					{
						long diag = array[x-1][y-1];
						addmax = Math.min(box[x-1].num,  toy[y-1].num) + diag;
					}
					
					array[x][y] = Math.max(addmax, adjmax);
				}
			}
			
			System.out.println("Case #" + (i+1) + ": " + array[numbox][numtoy]);
		}
		
	}

}

class G
{
	long type;
	long num;
}


