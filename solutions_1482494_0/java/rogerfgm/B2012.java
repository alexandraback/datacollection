import java.util.*;
import java.io.*;

public class B2012 {

	String s  = null;
	String[] sp = null;
	
	
	
	public void run() throws Exception{
		
		BufferedReader br = new BufferedReader(new FileReader("B-small-attempt2.in"));
		
		BufferedWriter bw = new BufferedWriter(new FileWriter("OUTPUT.txt"));
		s = br.readLine();
		int T = Integer.parseInt(s);

		
		int t = 1;
		while(t <= T){
			s = br.readLine();
			int N = Integer.parseInt(s);
			int[][] num = new int[N][2];
			for(int i = 0; i < N; i++){
				s = br.readLine();
				String[] ss = s.split(" ");
				num[i][0] = Integer.parseInt(ss[0]);
				num[i][1] = Integer.parseInt(ss[1]);
			}
			
			Arrays.sort(num, new Comparator<int[]>() {

				@Override
				public int compare(int[] a0, int[] a1) {
//					if(a0[1] != a1[1]){
//						return a1[0] - a0[0];
//					}
					return a0[1] - a1[1];
				
				}
			});
			
			boolean[] flag1 = new boolean[N];
			boolean[] flag2 = new boolean[N];
			int ans = 0;
			int star = 0;
			boolean imposi = false;
			while(true){
				boolean end = true;
				boolean conti = false;
				for(int i = 0; i < flag2.length; i++){
					if(!flag2[i]){
						if(star >= num[i][1]){
							if(flag1[i]){
								star++;
							}
							else{
								star += 2;
							}
							ans++;
							flag2[i] = true;
							conti = true;
						}
						end = false;
						break;
					}

				}
				if(end){
					break;
				}
				if(conti){
					continue;
				}
				for(int i = flag1.length - 1; i >= 0; i--){
					if(!flag1[i] && !flag2[i] && star >= num[i][0]){
						flag1[i] = true;
						star++;
						ans++;
						conti = true;
						break;
					}
				}
				if(conti){
					continue;
				}
				else{
					imposi = true;
					break;
				}
			}
			
			if(imposi){
				bw.write("Case #" + t + ": " + "Too Bad" + "\n");
			}
			else{
				bw.write("Case #" + t + ": " + ans + "\n");
			}
			
			
			t++;
		}
		
		bw.close();
	}
	

	
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception {
		// TODO Auto-generated method stub
		B2012 b = new B2012();
		b.run();

		
	}
	
	

}