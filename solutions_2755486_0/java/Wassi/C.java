package c1;

import java.util.Arrays;
import java.util.HashMap;
import java.util.Scanner;

public class C {

	/**
	 * @param args
	 */
	
	
	public static void main(String[] args) {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		class attack implements Comparable<attack>{
			int d,w,e,s;
			public attack(int d, int w, int e, int s){
				this.d=d;
				this.w=w;
				this.e=e;
				this.s=s;
			}
			@Override
			public int compareTo(attack o) {
				return this.d-o.d;
			}
			
		}
		
		for(int t=1;t<=T;t++){
			int cnt = 0;
			int N = in.nextInt();
			int[] d =new int[N];
			int[] n =new int[N];
			int[] w =new int[N];
			int[] e =new int[N];
			int[] s =new int[N];
			int[] delta_d = new int[N];
			int[] delta_p = new int[N];
			int[] delta_s = new int[N];
			for(int i=0;i<N;i++){
				d[i] = in.nextInt();
				n[i] = in.nextInt();
				w[i] = in.nextInt();
				e[i] = in.nextInt();
				s[i] = in.nextInt();
				delta_d[i] = in.nextInt();
				delta_p[i] = in.nextInt();
				delta_s[i] = in.nextInt();
				cnt+=n[i];
				
						
						
			}
			attack[] a = new attack[cnt];
			cnt--;
			for(int i=0;i<N;i++){
			for(int j=0;j<n[i];j++){
				a[cnt--] = new attack(d[i]+j*delta_d[i], w[i]+j*delta_p[i], e[i]+j*delta_p[i], s[i]+j*delta_s[i]);
			}
			}
			
			Arrays.sort(a);
			int curDay = 0;
			int lastDayStart = 0;
			int success = 0;
			HashMap<Integer,Integer> height = new HashMap<Integer,Integer>();
			for(int i=0;i<a.length;i++){
				if(a[i].d>curDay){
					for(int j=lastDayStart;j<i;j++){
						for(int k=a[j].w;k<a[j].e;k++){
							if(!height.containsKey(k)) height.put(k, 0);
							if(height.get(k)<a[j].s) height.put(k, a[j].s);
						}
					}
					lastDayStart = i;
					curDay = a[i].d;
				}
				boolean attackSucceed = false;
				for(int k=a[i].w;k<a[i].e;k++){
					if(!height.containsKey(k) || height.get(k)<a[i].s){
						success ++;
						break;
					}
				}
			}
			
			System.out.println("Case #" + t + ": " + success);
		}

	}

}
