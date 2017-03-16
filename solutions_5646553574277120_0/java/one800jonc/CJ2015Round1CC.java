import java.io.*;
import java.util.*;


public class CJ2015Round1CC {
	
	public static boolean isSubsetSum(int[] set, int n, int sum)
	{
	   // Base Cases
	   if (sum == 0)
	     return true;
	   if (n == 0 && sum != 0)
	     return false;
	 
	   // If last element is greater than sum, then ignore it
	   if (set[n-1] > sum)
	     return isSubsetSum(set, n-1, sum);
	 
	   /* else, check if sum can be obtained by any of the following
	      (a) including the last element
	      (b) excluding the last element   */
	   //System.out.println(n);
	   return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
	}
	
	public static int solve(List<Integer> D, int V){
		int[] set = new int[D.size()];
		int count = 0;
		for (Integer i : D){
			set[count] = i;
			count++;
		}
		int cur = 0;
		for (int i = 1; i <= V; i++){
			if (!isSubsetSum(set,set.length,i)){
				//System.out.println(i);
				cur = i;
				break;
			}
		}
		if (cur == 0) return 0;
		D.add(new Integer(cur));
		return 1+solve(D,V);
	}
	
	public static void main(String[] args) throws IOException {
		BufferedReader in = new BufferedReader(new FileReader("C-small-attempt0.in"));
		//BufferedReader in = new BufferedReader(new FileReader("temp.txt"));
		PrintWriter out  = new PrintWriter(new File("2015Round1CCout.txt"));
		int T = Integer.parseInt(in.readLine());
		for(int a = 1; a < T+1; a++){
			String[] nums = in.readLine().split(" ");
			int C = Integer.parseInt(nums[0]);
			int V = Integer.parseInt(nums[2]);
			String[] temp = in.readLine().split(" ");
			List<Integer> D = new ArrayList<Integer>();
			for (int i = 0; i < temp.length; i++){
				D.add(Integer.parseInt(temp[i]));
			}
			int ret = solve(D,V);
			System.out.println("Case #"+a+": "+ret);
			out.println("Case #"+a+": "+ret);
		}
		in.close();
		out.close();
	}
}
