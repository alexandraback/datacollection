import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		PrintWriter out=new PrintWriter(new File("output.txt"));
		BufferedReader in=new BufferedReader(new FileReader(new File("input.txt")));
		int T=Integer.parseInt(in.readLine());
		for(int t=0;t<T;t++)
			{
			int Wall[]=new int[10000];
			int N=Integer.parseInt(in.readLine());
			TreeSet<Attack> Attacks=new TreeSet<Attack>();
			for(int i=0;i<N;i++)
				{
				String S[]=in.readLine().split(" ");
				int di=Integer.parseInt(S[0]);
				int ni=Integer.parseInt(S[1]);
				int wi=Integer.parseInt(S[2])+5000;
				int ei=Integer.parseInt(S[3])+5000;
				int si=Integer.parseInt(S[4]);
				int delta_di=Integer.parseInt(S[5]);
				int delta_pi=Integer.parseInt(S[6]);
				int delta_si=Integer.parseInt(S[7]);
				for(int attack=0;attack<ni;attack++)
					Attacks.add(new Attack(i,wi+attack*delta_pi,ei+attack*delta_pi,si+attack*delta_si,di+attack*delta_di));
				}
			int ans=0;
			while(!Attacks.isEmpty())
				{
				Attack curAttack=Attacks.pollFirst();
				Collection<Attack> Coll=new TreeSet<Attack>();
				Coll.add(curAttack);
				while(!Attacks.isEmpty()&&Attacks.first().time==curAttack.time)
					Coll.add(Attacks.pollFirst());
				for(Attack attack:Coll)
					{
					int strength=attack.strength;
					for(int i=attack.lo;i<attack.hi;i++)
						{
						if(Wall[i]<strength)
							{
							ans++;		//this attack was successful
							break;	
							}
						}
					}
				for(Attack attack:Coll)
					{
					int strength=attack.strength;
					for(int i=attack.lo;i<attack.hi;i++)
						{
						if(Wall[i]<strength)
							Wall[i]=strength;	
						}
					}
				}
			out.println("Case #"+(t+1)+": "+ans);
			}
		out.close();
		}
	}

class Attack implements Comparable<Attack>
	{
	int tribenum;
	int lo;
	int hi;
	int strength;
	int time;
	public Attack(int tribenum, int lo,int hi,int strength,int time)
		{
		this.tribenum=tribenum;
		this.lo=lo;
		this.hi=hi;
		this.strength=strength;
		this.time=time;
		}
	
	public int compareTo(Attack o)
		{
		if(this.time<o.time)
			return -1;
		else if(this.time==o.time&&this.tribenum<o.tribenum)
			return -1;
		else if(this.time==o.time&&this.tribenum==o.tribenum)
			return 0;
		return 1;
		}
	

	}

//must declare new classes here