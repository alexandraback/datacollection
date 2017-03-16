import java.util.*;

public class codeJam3C
{

	static class Tribe implements Comparable<Tribe>
	{
		int nextAttack, noAttacks;
		int wallLeft, wallRight, strength;
		int dDays, dMove, dStr;
		public Tribe( int nA, int nAtt, int wallL, int wallR, int str,  int dD, int dM, int dS )
		{
			nextAttack = nA;
			noAttacks = nAtt-1;
			wallLeft = wallL*2;
			wallRight = wallR*2;
			strength = str;
			dDays = dD;
			dMove = dM*2;
			dStr = dS;
		}
		public int compareTo(Tribe t)
		{
			return nextAttack - t.nextAttack;
		}
		public boolean prepare()
		{
			if(noAttacks == 0)
				return false;
			noAttacks--;
				
			nextAttack += dDays;
			wallLeft += dMove;
			wallRight += dMove;
			strength += dStr;
				
			return true;
		}
	}
	
	static HashMap<Integer, Integer> hash;
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		
		for(int testNo = 1; testNo <= testCase; testNo++)
		{
			int noTribes = sc.nextInt();
			
			PriorityQueue<Tribe> theTribes = new PriorityQueue<Tribe>();
			hash =  new HashMap<Integer, Integer>();
			for(int i = 0; i < noTribes; i++)
			{
				theTribes.add(new Tribe(sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt(), 
										sc.nextInt(), sc.nextInt(), sc.nextInt(), sc.nextInt()));
			}
			
			int successful = 0;
			while(!theTribes.isEmpty())
			{
				HashMap<Integer, Integer> forRepair = new HashMap<Integer, Integer>();
				Tribe attacking = theTribes.poll();
				int attackDate = attacking.nextAttack;
				boolean success = false;
				for(int i = attacking.wallLeft; i <= attacking.wallRight; i++ )
				{
					if(!hash.containsKey(i))
					{
						success = true;
						forRepair.put(i, attacking.strength);
					}
					else
					{
						if(hash.get(i) < attacking.strength)
						{
							success = true;
							forRepair.put(i, attacking.strength);
						}
					}
				}
				if(success)
					successful++;
					
				if(attacking.prepare())
					theTribes.add(attacking);
				
				while(!theTribes.isEmpty() && theTribes.peek().nextAttack == attackDate)
				{
					attacking = theTribes.poll();
					success = false;
					for(int i = attacking.wallLeft; i <= attacking.wallRight; i++ )
					{
						if(!hash.containsKey(i))
						{
							success = true;
							if(forRepair.containsKey(i))
								forRepair.put(i, Math.max(attacking.strength, forRepair.get(i)));
							else
								forRepair.put(i, attacking.strength);
						}
						else
						{
							if(hash.get(i) < attacking.strength)
							{
								success = true;
								if(forRepair.containsKey(i))
									forRepair.put(i, Math.max(attacking.strength, forRepair.get(i)));
								else
									forRepair.put(i, attacking.strength);
							}
						}
					}
					
					if(success)
						successful++;
					if(attacking.prepare())
						theTribes.add(attacking);
				}
				
				Iterator it = forRepair.entrySet().iterator();
				while (it.hasNext()) {
					Map.Entry pairs = (Map.Entry)it.next();
					hash.put((Integer)pairs.getKey(), (Integer)pairs.getValue());
					it.remove(); // avoids a ConcurrentModificationException
				}
			}	
			
			
			
			System.out.printf("Case #%d: %d\n", testNo, successful);
		}
	}
}