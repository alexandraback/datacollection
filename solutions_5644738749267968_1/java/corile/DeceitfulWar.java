import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.BitSet;
import java.util.LinkedList;
import java.util.List;

import javax.naming.spi.DirObjectFactory;


public class DeceitfulWar {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		//Open The file
		BufferedReader br=null;
		try {
			br = new BufferedReader(new FileReader("D-large.in"));
			//br = new BufferedReader(new InputStreamReader(System.in));
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		//FileWriter fstream = new FileWriter("out.txt");
		//BufferedWriter out = new BufferedWriter(fstream);
		
		//Get the test case number
		int casenum = readLineAsInt(br);
		
		//Process each case
		for(int j = 1; j <= casenum; j++)
		{
			int numBlocks = readLineAsInt(br);
			
			//Read the selected row
			Double[] naomiBlocks = new Double[numBlocks];
			Double[] kenBlocks = new Double[numBlocks];
			
			String[] s = new String[numBlocks];
			try {
				s = br.readLine().split(" ");
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			for(int i=0;i<numBlocks;i++)
				naomiBlocks[i]=Double.parseDouble(s[i]);
			
			try {
				s = br.readLine().split(" ");
			} catch (IOException e) {
				e.printStackTrace();
			}
			
			for(int i=0;i<numBlocks;i++)
				kenBlocks[i]=Double.parseDouble(s[i]);
			
			int deceitfulwarScore = playDeceitfulWarOptimally(naomiBlocks, kenBlocks, numBlocks);
			int warScore = playWarOptimally(naomiBlocks, kenBlocks, numBlocks);
			
			System.out.printf("Case #%d: %d %d\n",j,deceitfulwarScore,warScore);
								
			//System.out.println("Case #"+(j+1)+": "+getProbability(numDiamonds, x, y));
		}
		try {
			br.close();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		

	}
	
	@SuppressWarnings("finally")
	public static int readLineAsInt(BufferedReader br)
	{
		int val = 0;
		try {
			val = Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}finally{
			return val;
		}
	}
	
	public static void printStringArray(String[] s)
	{
		for(String str:s)
		{
			System.out.print(str+", ");
		}
		System.out.println("");
	}

	private static int playWarOptimally(Double[] p1Blocks,Double[] p2Blocks,int numBLocks)
	{
		Arrays.sort(p1Blocks);
		Arrays.sort(p2Blocks);
		List<Double> p1List = new LinkedList<Double>(Arrays.asList(p1Blocks));
		List<Double> p2List = new LinkedList<Double>(Arrays.asList(p2Blocks));
		//System.out.println(p1List);
		//System.out.println(p2List);
		int score=0;
		for(int i=0;i<numBLocks;i++)
		{
			Double p1Weight = p1List.get(i);
			int idx = binarySearchWeight(p2List, p1Weight);
			if(idx>=p2List.size())
			{
				score++;
				p2List.remove(0);
			}
			else
				p2List.remove(idx);
		}
		return score;
	}
	
	private static int playDeceitfulWarOptimally(Double[] p1Blocks,Double[] p2Blocks,int numBLocks)
	{
		Arrays.sort(p1Blocks);
		Arrays.sort(p2Blocks);
		
		int p1Index=0;
		int p2IndexBeg = 0;
		int p2IndexEnd=numBLocks-1;
		int score=0;
		for(int i=0;i<numBLocks;i++)
		{
			if(p1Blocks[p1Index]<p2Blocks[p2IndexBeg])
			{
				p2IndexEnd--;
			}
			else
			{
				score++;
				p2IndexBeg++;
			}
			p1Index++;
		}
		return score;
	}
	
	public static int binarySearchWeight(List<Double> weights,Double w)
	{
		int count, step;
		int beg=0;
		count = weights.size();
		while (count>0)
		{
		  int it = beg; 
		  step=count/2; 
		  it+=step;
		  if (w>weights.get(it))
		  { 
			  beg=++it; 
			  count-=step+1;  
		  }
		  else count=step;
		}
		return beg;
	}

}
