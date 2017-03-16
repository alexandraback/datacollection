import java.util.*;
public class c {
	public static void main(String[] args){
		Scanner br = new Scanner(System.in);
		
		int t = br.nextInt();
		for(int c = 1;c<=t;c++){
			int n = br.nextInt();
			int[] ds = new int[n];
			int[] hs = new int[n];
			int[] ms = new int[n];
			for(int i = 0;i<n;i++){
				ds[i] = br.nextInt();
				hs[i] = br.nextInt();
				ms[i] = br.nextInt();
			}
			
			int ans = 0;
			
			if(n == 2){
				hiker[] ts = new hiker[2];
				ts[0] = new hiker(ds[0], ms[0]);
				ts[1] = new hiker(ds[1], ms[1]);
				
				Arrays.sort(ts);
				
				if(ts[0].speed*1.5 < ts[1].speed){
					System.out.println("Case #"+c+": 1");
				}
				else{
					System.out.println("Case #"+c+": 0");
				}
			}
			else if(hs[0] == 2){
				hiker[] ts = new hiker[2];
				ts[0] = new hiker(ds[0], ms[0]);
				ts[1] = new hiker(ds[0], ms[0]+1);
				System.out.println("Case #"+c+": 0");
			}
			else{
				System.out.println("Case #"+c+": 0");
			}
			
		}
	}
	public static class hiker implements Comparable<hiker>{
		int pos, speed;
		public hiker(int a, int b){
			pos = a;
			speed = b;
		}
		public int compareTo(hiker o){
			if(speed == o.speed){
				return pos-o.pos;
			}
			return speed-o.speed;
		}
	}
}
