import java.util.*;

public class GC1B_15{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for(int ca = 1; ca <= T; ca++){
			int N = sc.nextInt();
			int arr[] = new int[N];
			int max = 0;
			int sum = 0;

			for(int i = 0; i < N ; i++){
				arr[i] = sc.nextInt();
				max = Math.max(max,arr[i]);
				sum += arr[i];
			}	
			int ans = max;
			
			for(int i = 0; i < sum; i++){
				int total = N + i;
				int left = i;
				int toFind = sum / total + (sum%total!=0 ? 1 : 0);
				// if(toFind + i > ans) break;
				PriorityQueue<Integer> pq = new PriorityQueue<Integer>(20, new Comparator<Integer>(){public int compare(Integer o1, Integer o2){ return o2 - o1;}});
				for(int e: arr)
					pq.offer(e);

				while(left--> 0){
					int curr = pq.poll();
					pq.offer(toFind);
					pq.offer(curr-toFind);
				}
				// System.out.println(toFind + " " + i +  " "+  pq.toString() );
				ans = Math.min(ans,pq.peek()+i);
			}

			System.out.printf("Case #%d: %d\n",ca,ans);
		}
	}
}