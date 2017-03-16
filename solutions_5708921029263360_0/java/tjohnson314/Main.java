
import java.util.Scanner;
import java.util.ArrayList;
import java.util.Stack;

public class Main
{
	public static int aMax;
	public static int bMax;
	public static int cMax;
	public static int k;
	public static ArrayList<Outfit> allOutfits;
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		int tests = sc.nextInt();
		for(int testNum = 1; testNum <= tests; testNum++)
		{
			System.out.print("Case #" + testNum + ": ");
			
			aMax = sc.nextInt();
			bMax = sc.nextInt();
			cMax = sc.nextInt();
			k = sc.nextInt();
			
			allOutfits = new ArrayList<Outfit>();
			Outfit outfit = new Outfit();
			while(outfit != null)
			{
				allOutfits.add(outfit);
				Outfit newOutfit = outfit.nextOutfit();
				outfit = newOutfit;
			}
			
			SearchNode.computeMaxSizes();
			//System.out.println(allOutfits.size());
			
			if(cMax <= k)
			{
				System.out.println(aMax*bMax*cMax);
				for(Outfit o : Main.allOutfits)
					System.out.println(o.toString());
			}
			else
			{
				SearchNode currNode = new SearchNode();
				Stack<SearchNode> stack = new Stack<SearchNode>();
				stack.add(currNode);
				int maxWorn = 0;
				SearchNode maxNode = currNode;
				
				while(!stack.isEmpty())
				{
					currNode = stack.pop();
					//System.out.println("Current node: " + currNode.wornToString());
					if(currNode.worn.size() > maxWorn)
					{
						maxWorn = currNode.worn.size();
						maxNode = currNode;
					}
					
					for(SearchNode nextNode : currNode.next())
						stack.add(nextNode);
				}
				
				System.out.println(maxNode.worn.size());
				System.out.println(maxNode.wornToString());
			}
		}
		
		sc.close();
	}
}

class Outfit
{
	public int a;
	public int b;
	public int c;
	
	public Outfit()
	{
		this.a = 0;
		this.b = 0;
		this.c = 0;
	}
	
	public Outfit(int a, int b, int c)
	{
		this.a = a;
		this.b = b;
		this.c = c;
	}
	
	public Outfit nextOutfit()
	{
		if(this.c < Main.cMax - 1)
		{
			return new Outfit(this.a, this.b, this.c + 1);
		}
		else if(this.b < Main.bMax - 1)
		{
			return new Outfit(this.a, this.b + 1, 0);
		}
		else if(this.a < Main.aMax - 1)
		{
			return new Outfit(this.a + 1, 0, 0);
		}
		else return null;
	}
	
	public String toString()
	{
		return ((a + 1) + " " + (b + 1) + " " + (c + 1));
	}
}

class SearchNode
{
	static int maxPairs12;
	static int maxPairs13;
	static int maxPairs23;

	int[] usedPair12;
	int[] usedPair13;
	int[] usedPair23;
	int currOutfit;
	ArrayList<Integer> worn;
	
	public static void computeMaxSizes()
	{
		maxPairs12 = Main.aMax*Main.bMax;
		maxPairs13 = Main.aMax*Main.cMax;
		maxPairs23 = Main.bMax*Main.cMax;
	}
	
	public SearchNode()
	{
		this.usedPair12 = new int[maxPairs12];
		this.usedPair13 = new int[maxPairs13];
		this.usedPair23 = new int[maxPairs23];
		currOutfit = 0;
		worn = new ArrayList<Integer>();
	}
	
	public SearchNode copy()
	{
		SearchNode newNode = new SearchNode();
		newNode.usedPair12 = new int[maxPairs12];
		newNode.usedPair13 = new int[maxPairs13];
		newNode.usedPair23 = new int[maxPairs23];
		
		for(int i = 0; i < maxPairs12; i++)
			newNode.usedPair12[i] = this.usedPair12[i];
		
		for(int i = 0; i < maxPairs13; i++)
			newNode.usedPair13[i] = this.usedPair13[i];
		
		for(int i = 0; i < maxPairs23; i++)
			newNode.usedPair23[i] = this.usedPair23[i];
		
		newNode.currOutfit = this.currOutfit;
		newNode.worn = new ArrayList<Integer>();
		for(Integer outfit : this.worn)
			newNode.worn.add(outfit);
		
		return newNode;
	}

	//Assume that we either wear the current outfit, or skip to the next one
	public ArrayList<SearchNode> next()
	{
		ArrayList<SearchNode> nextNodes = new ArrayList<SearchNode>();
		if(this.currOutfit < Main.allOutfits.size())
		{		
			//Wear current outfit
			SearchNode next1 = this.copy();
			next1.wearCurrent();		
			
			//Skip current outfit
			SearchNode next2 = this.copy();
			next2.currOutfit++;
			
			if(next1.isValid())
				nextNodes.add(next1);
			
			if(next2.isValid())
				nextNodes.add(next2);
		}
		
		return nextNodes;
	}
	
	public void wearCurrent()
	{
		int a = Main.allOutfits.get(currOutfit).a;
		int b = Main.allOutfits.get(currOutfit).b;
		int c = Main.allOutfits.get(currOutfit).c;
		
		int pair12 = a*Main.bMax + b;
		int pair13 = a*Main.cMax + c;
		int pair23 = b*Main.cMax + c;
		
		usedPair12[pair12]++;
		usedPair13[pair13]++;
		usedPair23[pair23]++;
		
		worn.add(currOutfit);
		currOutfit++;
	}
	
	public boolean isValid()
	{
		if(currOutfit > Main.allOutfits.size())
			return false;
		
		for(int i = 0; i < maxPairs12; i++)
			if(usedPair12[i] > Main.k)
				return false;
		
		for(int i = 0; i < maxPairs13; i++)
			if(usedPair13[i] > Main.k)
				return false;
		
		for(int i = 0; i < maxPairs23; i++)
			if(usedPair23[i] > Main.k)
				return false;
		
		return true;
	}
	
	public String wornToString()
	{
		StringBuilder strBuild = new StringBuilder();
		for(int outfitNum : worn)
		{
			String outfitStr = Main.allOutfits.get(outfitNum).toString() + "\n";
			strBuild.append(outfitStr);
		}
		
		return strBuild.toString();
	}
}