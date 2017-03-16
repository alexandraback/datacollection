import java.io.File;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.Scanner;


public class C {
	public static void main(String[] args) throws IOException {
		PrintWriter out = new PrintWriter(new File("C.out"));
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for(int caseOn = 1; caseOn <= cases; caseOn++) {
			out.printf("Case #%d:\n",caseOn);
			int n = in.nextInt();
			int[] arr = new int[n];
			for(int i = 0; i < n; i++) {
				arr[i] = in.nextInt();
			}
			
			HashMap<Integer, LinkedList<Integer>> map = new HashMap<Integer, LinkedList<Integer>>();
			LinkedList<Integer> sums = new LinkedList<Integer>();
			for(int i = 1; i < (1<<n); i++) {
				int sum = 0;
				for(int j = 0; j < n; j++) {
					if(((1<<j) & i) != 0) {
						sum+=arr[j];
					}
				}
				if(!map.containsKey(sum)) {
					sums.add(sum);
					map.put(sum, new LinkedList<Integer>());
				}
				map.get(sum).add(i);
			}
			int a = -1, b = -1;
			for(int i : sums) {
				LinkedList<Integer> nums = map.get(i);
				while(nums.size()>1 && a==-1) {
					int t = nums.poll();
					for(int j : nums) {
						if((t&j)==0) {
							a=t;
							b=j;
							break;
						}
					}
				}
				
				if(a!=-1)
					break;
			}
			
			if(a==-1) {
				out.println("Impossible");
			} else {
				int sum1 = 0;
				for(int i = 0; i < n; i++) {
					if(((1<<i)&a)!=0) {
						sum1+=arr[i];
						out.printf("%d ",arr[i]);
					}
				}
				out.println();
				
				int sum2 = 0;
				for(int i = 0; i < n; i++) {
					if(((1<<i)&b)!=0) {
						out.printf("%d ",arr[i]);
						sum2+=arr[i];
					}
				}
				System.out.printf("Case %d sum1:%d sum2:%d\n",caseOn,sum1,sum2);
				out.println();
			}
		}
		out.close();
	}
}
