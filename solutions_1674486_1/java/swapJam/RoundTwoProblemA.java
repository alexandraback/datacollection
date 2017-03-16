package codejam12;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.text.DecimalFormat;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;

public class RoundTwoProblemA {

public static void main(String[] args) throws IOException {
		
		BufferedReader input = new BufferedReader(new FileReader("input.txt"));
		BufferedWriter output = new BufferedWriter(new FileWriter("output.txt"));
		
		int noOfTestCases = Integer.parseInt(input.readLine());
		
		
		for(int i=1;i<=noOfTestCases;i++)
		{
			ArrayList<ArrayList<Integer>> graph = new ArrayList<ArrayList<Integer>>();
			graph.add(new ArrayList<Integer>()); //dummy
			
			int n = Integer.parseInt(input.readLine());
			
			for(int j=1;j<=n;j++)
			{
				String line = input.readLine();
				Scanner scanner = new Scanner(line);
				int noOfParentClasses = scanner.nextInt();
				ArrayList<Integer> parentClassList = new ArrayList<Integer>();
				
				for(int k=1;k<=noOfParentClasses;k++)
				{
					
					int parentClass = scanner.nextInt();
					parentClassList.add(parentClass);
					
				}
				
				graph.add(parentClassList);
			}
			
			boolean isDiamond = false;
			
			for(int j=1;j<=n;j++)
			{
				LinkedList<Integer> queue = new LinkedList<Integer>();
				queue.offer(j);
				boolean discovered[] = new boolean[1001];
				discovered[j] = true;
				
				while(!queue.isEmpty())
				{
					int curr = queue.poll();
					ArrayList<Integer> parents = graph.get(curr);
					
					int size = parents.size();
					for(int k=0;k<size;k++)
					{
						int parent  = parents.get(k);
						if(discovered[parent])
						{
							isDiamond = true;
							break;
						}
						else
						{
							queue.offer(parent);
							discovered[parent] = true;
						}
					}
					
					if(isDiamond)
						break;
				}
				
				if(isDiamond)
					break;
			}
			
			String outputStr;
			if(isDiamond)
				outputStr = "Case #" + i + ": Yes";
			else
				outputStr = "Case #" + i + ": No";
			
			output.write(outputStr + "\n");
		}
		
		output.close();
		input.close();
   }
}
