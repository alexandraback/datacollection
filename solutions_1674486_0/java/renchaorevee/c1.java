import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.Scanner;


public class diamond2 {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Scanner cin = new Scanner(System.in);
		int linenum = cin.nextInt();
		
		for(int idx = 1; idx < linenum+1; idx++)
		{
			System.out.print("Case #" + idx + ": ");
			int n = cin.nextInt();
			ArrayList<ArrayList<Integer>> inherTable = new ArrayList<ArrayList<Integer>>();
			
			for(int classid = 0; classid < n; classid++)
			{
				int m = cin.nextInt();
				
				ArrayList<Integer> parentList = new ArrayList<Integer>();
				for(int jdx=0; jdx < m; jdx++)
				{
					int parentClassId = cin.nextInt() - 1;
					parentList.add(parentClassId);
				}
				inherTable.add(parentList);
			}
			
			boolean result = false;
			for(int classid = 0; classid < n; classid++)
			{
				if(findDiamondFromClass(classid, inherTable))
				{
					result = true;
					break;
				}
			}
			if(result)
			{
				System.out.println("Yes");
			}
			else
			{
				System.out.println("No");
			}
		}
		
	}
	public static boolean findDiamondFromClass(int c, ArrayList<ArrayList<Integer>> inherTable)
	{
		ArrayList<Integer> parentList = inherTable.get(c);
		
		if(parentList.size() == 0 || parentList.size() == 1)
		{
			return false;
		}
		else
		{
			HashSet<Integer> allparentClass = new HashSet<Integer>();
			allparentClass.addAll(parentList);
			for(int parentClass : parentList)
			{
				HashSet<Integer> tmp = getAllParentClass(parentClass, inherTable);
				if(tmp != null)
				{
					for(int t : tmp)
					{
						if(allparentClass.add(t) == false)
						{
							return true;
						}
					}
				}
			}
			return false;
		}
	}
	
	
	public static HashSet<Integer> getAllParentClass(int c, ArrayList<ArrayList<Integer>> inherTable)
	{
		ArrayList<Integer> parentList = inherTable.get(c);
		
		HashSet<Integer> allparentClass = new HashSet<Integer>();
		allparentClass.addAll(parentList);
		for(int parentClass : parentList)
		{
			allparentClass.addAll(getAllParentClass(parentClass, inherTable));
		}
		return allparentClass;
	}
}
