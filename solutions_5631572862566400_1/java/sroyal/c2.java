import java.util.*;
public class c2 {
	public static int n;
	public static int[] nums;
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			n = br.nextInt();
			
			
			ArrayList<Integer>[] rgraph = new ArrayList[n];
			for(int i = 0;i<n;i++){
				rgraph[i] = new ArrayList<Integer>();
			}
			
			nums = new int[n];
			for(int i = 0;i<n;i++){
				nums[i] = br.nextInt()-1;
				rgraph[nums[i]].add(i);
			}
			
			
			int best = 2;
			boolean[] done = new boolean[n];
			for(int i = 0;i<n;i++){
				if(!done[i]){
					int[] seen = new int[n];
					int pos = i;
					int time = 1;
					while(true){
						if(seen[pos] != 0){
							best = Math.max(best, time-seen[pos]);
							break;
						}
						seen[pos] = time;
						done[pos] = true;
						pos = nums[pos];
						time++;
					}
				}
			}
			int count = 0;
			for(int i = 0;i<n;i++){
				if(nums[nums[i]] == i){
					count++;
				}
			}
			int add = 0;
			for(int i = 0;i<n;i++){
				if(nums[nums[i]] == i && i < nums[i]){
					ArrayDeque<Integer> qu = new ArrayDeque<Integer>();
					qu.add(i);
					int[] dist = new int[n];
					Arrays.fill(dist, -1);
					dist[i] = 0;
					int max1 = 0;
					while(qu.size() > 0){
						int cur = qu.poll();
						max1 = Math.max(max1, dist[cur]);
						for(int j : rgraph[cur]){
							if(j != nums[i] && j != i){
								if(dist[j] == -1){
									dist[j] = 1+dist[cur];
									qu.add(j);
								}
							}
						}
					}
					qu = new ArrayDeque<Integer>();
					qu.add(nums[i]);
					dist = new int[n];
					Arrays.fill(dist, -1);
					dist[nums[i]] = 0;
					int max2 = 0;
					while(qu.size() > 0){
						int cur = qu.poll();
						max2 = Math.max(max2, dist[cur]);
						for(int j : rgraph[cur]){
							if(j != nums[i] && j != i){
								if(dist[j] == -1){
									dist[j] = 1+dist[cur];
									qu.add(j);
								}
							}
						}
					}
					add+=max1;
					add+=max2;
				}
			}
			best = Math.max(best, count+add);
			System.out.println("Case #"+c+": "+best);
		}
	}
}
