package codejam.treasure;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

import codejam.filestuff.FileStuff;

public class Treasure {
	
	static class treasureChest {
		public int keyType;
		public ArrayList<Integer> keyContain;
		
		public treasureChest()
		{
			keyContain = new ArrayList<Integer>();
		}
		
		public int getVariation()
		{
			Collections.sort(keyContain);
			if (keyContain.size() <= 0) return 0;
			int xRes = 1;
			for (int i=1;i<keyContain.size();i++)
			{
				if (keyContain.get(i) != keyContain.get(i - 1)) xRes++;
			}
			return xRes;
		}
	}
	
	public static void main(String[] args) throws IOException 
	{
		FileStuff fs = new FileStuff("D-small.in","D-small.out","treasure");
		ArrayList<String> input = new ArrayList<String>();
		input = fs.ReadFromFile();
		
		ArrayList<String> output = new ArrayList<String>();
		
		int xCase = Integer.parseInt(input.get(0));
		int xPointer = 1;
		
		for (int i=1;i<=xCase;i++)
		{
			String strOut = "Case #" + String.valueOf(i) + ":";
			
			String[] arrLine = input.get(xPointer).split(" ");
			xPointer++;
			int xKey = Integer.parseInt(arrLine[0]);
			int xChest = Integer.parseInt(arrLine[1]);
			
			ArrayList<Integer> arrKey = new ArrayList<Integer>();
			arrLine = input.get(xPointer).split(" ");
			xPointer++;
			
			for (int a=0;a<xKey;a++) arrKey.add(Integer.parseInt(arrLine[a]));
			
			ArrayList<treasureChest> arrChest = new ArrayList<treasureChest>();
			for (int a=0;a<xChest;a++)
			{
				arrChest.add(new treasureChest());
				arrLine = input.get(xPointer).split(" ");
				xPointer++;
				arrChest.get(a).keyType = Integer.parseInt(arrLine[0]);
				int xCountKey = Integer.parseInt(arrLine[1]);
				for (int b=0;b<xCountKey;b++)
				{
					arrChest.get(a).keyContain.add(Integer.parseInt(arrLine[2+b]));
				}
			}
			
			ArrayList<Integer> arrRes = new ArrayList<Integer>();
			boolean[] boolOpen = new boolean[xChest];
			while (arrKey.size() > 0)
			{
				int bestVar = -1;
				int bestLength = -1;
				int xOpen = -1;
				int keyUsed = -1;				
				for (int a=xChest-1;a>=0;a--)
				{
					treasureChest currChest = arrChest.get(a);
					if (boolOpen[a] == false)
					{
						for (int b=0;b<arrKey.size();b++)
						{
							int xCurrKey = arrKey.get(b);
							if (xCurrKey == currChest.keyType)
							{
								int xVar = currChest.getVariation();
								if (xVar > bestVar)
								{
									xOpen = a;
									bestVar = xVar;
									bestLength = currChest.keyContain.size();
									keyUsed = b;
								} else if (xVar == bestVar)
								{
									if (currChest.keyContain.size() >= bestLength)
									{
										xOpen = a;
										bestVar = xVar;
										bestLength = currChest.keyContain.size();
										keyUsed = b;
									}
								}
								break;
							}
						}
					}
				}
				if (xOpen < 0) break;
				arrKey.remove(keyUsed);
				boolOpen[xOpen] = true;
				treasureChest openChest = arrChest.get(xOpen);
				for (int a=0;a<openChest.keyContain.size();a++)
				{
					arrKey.add(openChest.keyContain.get(a));
				}
				arrRes.add(xOpen+1);
			}
			
			boolean boolPossible = true;
			for (int a=0;a<xChest;a++)
			{
				if (boolOpen[a] == false)
				{
					boolPossible = false;
					break;
				}
			}
			
			StringBuilder strRes = new StringBuilder();
			if (boolPossible)
			{
				for (int a=0;a<arrRes.size();a++)
				{
					strRes.append(String.valueOf(arrRes.get(a)));
					if (a < arrRes.size()-1) strRes.append(" ");
				}
			} else
			{
				strRes.append("IMPOSSIBLE");
			}
			
			strOut += " " + strRes.toString();
			output.add(strOut);
		}
		
		fs.WriteToFile(output);
		System.out.print("Done!!!");
	}

}
