import java.util.*;
public class A {
	public static void main(String[] args){
		Scanner in = new Scanner(System.in);
		int t = in.nextInt();
		for(int z = 1; z <= t; z ++){
			int n = in.nextInt();
			int[] a = new int[n + 1];
			Arrays.fill(a, -1);
			a[1] = 1;
			Queue<Integer> q = new LinkedList<Integer>();
			q.add(1);
			while(!q.isEmpty()){
				int at = q.poll();
				if(at == n)break;
				if(at > n)continue;
				if(a[at + 1] == -1){
					a[at + 1] = a[at] + 1;
					q.add(at + 1);
				}
				int to = reverse(at);
				if(to <= at || to > n || a[to] != -1)
					continue;
				q.add(to);
				a[to] = a[at] + 1;
			}
			System.out.println("Case #" + z + ": " + a[n]);
		}
	}
	public static int reverse(long a){
		int len = 0;
		long aa = a;
		while(aa!=0){
			aa/=10;
			len++;
		}
		len--;
		long ans = 0;
		while(a>0){
			ans+=(a%10)*(Math.pow(10,  len));
			len--;
			a/=10;
		}
		return (int)ans;
	}
}
