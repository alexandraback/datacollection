import java.util.*;
public class c {
	public static int n;
	public static int[] nums;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			n = br.nextInt();
			
			nums = new int[n];
			for(int i = 0;i<n;i++){
				nums[i] = br.nextInt()-1;
			}
			int best = 2;
			for(int i = 0;i<(1<<n);i++){
				best = Math.max(best, go(0, i, new boolean[n], new int[Integer.bitCount(i)]));
			}
			System.out.println("Case #"+c+": "+best);
			
		}
	}
	public static int go(int pos, int mask, boolean[] used, int[] arr){
		if(pos == Integer.bitCount(mask)){
			int res = arr.length;
			for(int i = 0;i<arr.length;i++){
				if(arr[(i-1+arr.length)%arr.length] == nums[arr[i]] || arr[(i+1)%arr.length] == nums[arr[i]]){
					
				}
				else{
					res = 0;
					break;
				}
			}
			return res;
		}
		
		
		int max = 0;
		for(int i = 0;i<n;i++){
			if(!used[i] && (mask & (1<<i)) > 0){
				used[i] = true;
				arr[pos] = i;
				max = Math.max(max, go(pos+1, mask, used, arr));
				used[i] = false;
			}
		}
		return max;
	}
}
