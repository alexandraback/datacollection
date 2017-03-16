import java.util.*;
public class b {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			int n = br.nextInt();
			int[] freq = new int[2501];
			for(int i = 0;i<2*n-1;i++){
				for(int j = 0;j<n;j++){
					freq[br.nextInt()]++;
				}
			}
			System.out.print("Case #"+c+":");
			for(int i = 0;i<2501;i++){
				if(freq[i] %2 == 1){
					System.out.print(" "+i);
				}
			}
			System.out.println();
			
		}
	}
	public static class thing implements Comparable<thing>{
		int[] nums;
		public thing(int[] a){
			nums = a;
		}
		public int compareTo(thing o){
			for(int i = 0;i<nums.length;i++){
				if(nums[i] != o.nums[i]){
					return nums[i]-o.nums[i];
				}
			}
			return 0;
		}
	}
}
