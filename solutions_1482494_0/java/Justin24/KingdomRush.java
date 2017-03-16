package googleJam;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.Scanner;


public class KingdomRush 
{
	public static void main(String[]args)
	{  
		Scanner scan = null;
		try
		{
			scan = new Scanner(new File(args[0]));
		}
		catch (FileNotFoundException e)
		{
			System.err.println("File not found!");
			return;
		}
		if (!scan.hasNext())
		{
			System.err.println("Nothing in File!");
			return;
		}
		int testCases = Integer.parseInt(scan.nextLine());
		int testC = testCases;
		String[] line;
		int levels;
		int stars = 0;
		int caseNum = 1;
		while (testCases != 0)
		{
			levels = scan.nextInt();
			int lev = levels;
			LinkedList list = new LinkedList();
			Node current = null;
			int games = 0;
			while (lev != 0)
			{
				Node n = new Node();
				n.oneStar = scan.nextInt();
				n.twoStar = scan.nextInt();
				if(lev == levels)
				{
					list.root = n;
					n.prev = null;
				}
				else
				{
					current.next = n;
					n.prev = current;
				}
				current = n;
				lev--;
			}
			stars = games(list, stars);
			if (stars == 0)
			{
				System.out.println("Case #" + caseNum  + ": Too Bad");
			}
			else
			{
				System.out.print("Case #" + caseNum  + ": " + stars);
				if(caseNum != testC)
				{
					System.out.println();
				}
			}
			testCases--;
			caseNum++;
			stars = 0;
		}

	}

	public static int games(LinkedList r, int stars)
	{
		int games = 0;
		boolean checkTwo = false;
		boolean haveChecked = false;
		while(r.root != null)
		{
			Node point = r.root;
			while (point != null)
			{	point = r.root;
				while(!checkTwo && r.root != null)
				{
					if(!point.countTwo && point.twoStar <= stars)
					{
						games++;
						if (point.countOne == true)
						{
							stars++;
						}
						else
						{
							stars = stars + 2;	
						}
						haveChecked = true;
						if (point.prev == null)
						{
							if (point.next == null)
							{
								r.root = null;
							}
							else
							{
								point.next.prev = point.prev;
								r.root = point.next;
							}
						}
						else
						{
							point.prev.next = point.next;
							if(point.next != null)
							{
								point.next.prev = point.prev;								
							}
						}
					}
					point = point.next;
					if (point == null && !haveChecked)
					{
						checkTwo = true;
					}
					else if (point == null && haveChecked)
					{
						point = r.root;
						haveChecked = false;
					}

				}
				point = r.root;
				boolean runOnce = false;
				int highestBar = 0;
				while (r.root != null)
				{ 
					checkTwo = false;
					while (!runOnce)
					{
						if(!point.countOne && point.oneStar <= stars)
						{
							if (point.twoStar > highestBar)
							{
								highestBar = point.twoStar;
							}
						}
						point = point.next;
						if (point == null)
						{
							runOnce = true;
							point = r.root;
						}
					}
					if(!point.countOne && point.oneStar <= stars && point.twoStar == highestBar)
					{
						games++;
						stars++;
						point.countOne = true;
						break;
					}
					else
					{
						point = point.next;
					}
					if (point == null)
					{
						return 0;
					}
				}
			}
		}
		return games;
	}
}


class LinkedList
{
	Node root;
}
class Node
{
	int oneStar;
	int twoStar;
	boolean countOne = false;
	boolean countTwo = false;
	Node next;
	Node prev;
}
