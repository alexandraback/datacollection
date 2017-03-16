import java.util.*;

public class codeJamD
{
	static class Chest
	{
		ArrayList<Integer> keys;
		int type;
		public Chest(int n)
		{
			type = n;
			keys = new ArrayList<Integer>();
		}
	}
	
	static int noChests;
	static Chest[] chests;
	static HashSet<String> hash;
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		
		int testCase = sc.nextInt();
		
		for(int testNo = 1; testNo <= testCase; testNo++)
		{
			hash = new HashSet<String>();
			int noKeys = sc.nextInt();
			noChests = sc.nextInt();
			chests = new Chest[noChests];
			
			ArrayList<Integer> myKeys = new ArrayList<Integer>();
			ArrayList<Integer> masterList = new ArrayList<Integer>();
			for(int i = 0; i < noKeys; i++)
			{
				int keyC = sc.nextInt();
				myKeys.add(keyC);
				masterList.add(keyC);
			}
			String bM = "";
			for(int i = 0; i < noChests; i++)
			{
				chests[i] = new Chest(sc.nextInt());
				int keysIn = sc.nextInt();
				for(int j = 0; j < keysIn; j++)
				{
					int keyC = sc.nextInt();
					chests[i].keys.add(keyC);
					masterList.add(keyC);
				}
				bM+= "0";
			}
			
			String ans = naive(bM, myKeys, masterList, "");
			
			System.out.println("Case #" + testNo + ": " + ans.trim());
		}
	}
	public static String naive(String bM, ArrayList<Integer> myKeys, ArrayList<Integer> masterList, String path)
	{
		if(hash.contains(bM))
			return "IMPOSSIBLE";
		else
			hash.add(bM);
		String origPath = path;
		//System.out.println(bM + " " + myKeys);
		//System.out.println(path + "\n");
		if(checkBM(bM))
		{
			return path;
		}
		if(myKeys.size() == 0)
		{
			return "IMPOSSIBLE";
		}
		boolean found = false;
		for(int i = 0; i < noChests; i++)
		{
			if(bM.charAt(i) == '0')
			{
				
				int type = chests[i].type;
				int mIndex = masterList.indexOf(type);
				if(mIndex < 0)
				{
					return "IMPOSSIBLE";
				}
				int keyIndex = myKeys.indexOf(type);
				if(keyIndex >= 0)
				{
					myKeys.remove(keyIndex);
					masterList.remove(mIndex);
					String bM2 = bM.substring(0, i) + "1" + bM.substring(i+1);
					ArrayList<Integer> nextKeys = new ArrayList<Integer>();
					ArrayList<Integer> nextList = new ArrayList<Integer>();
					nextKeys.addAll(myKeys);
					nextKeys.addAll(chests[i].keys);
					nextList.addAll(masterList);
					
					String path2 = origPath + " " + (i+1);
					String path3 = naive(bM2, nextKeys, nextList, path2);
					if(!path3.equals("IMPOSSIBLE"))
					{
						path = path3;
						found = true;
						break;
					}
					masterList.add(type);
					myKeys.add(type);
				}
			}
		}
		if(!found)
			return "IMPOSSIBLE";
		else
			return path;
	}
	public static boolean checkBM(String bM)
	{
		for(int i = 0; i < bM.length(); i++)
		{
			if(bM.charAt(i) == '0')
				return false;
		}
		return true;
	}
}