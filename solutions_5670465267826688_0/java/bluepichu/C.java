import java.io.*;
import java.math.*;
import java.util.*;

public class C{
	
	// 0 -> -1
	// 1 -> 1
	// 2 -> i
	// 3 -> -i
	// 4 -> j
	// 5 -> -j
	// 6 -> k
	// 7 -> -k
	
	public static int[][] mult = {
		{1, 0, 3, 2, 5, 4, 7, 6},
		{0, 1, 2, 3, 4, 5, 6, 7},
		{3, 2, 0, 1, 6, 7, 5, 4},
		{2, 3, 1, 0, 7, 6, 4, 5},
		{5, 4, 7, 6, 0, 1, 2, 3},
		{4, 5, 6, 7, 1, 0, 3, 2},
		{7, 6, 4, 5, 3, 2, 0, 1},
		{6, 7, 5, 4, 2, 3, 1, 0}
	};
	
	public static void main (String [] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw = new PrintWriter(System.out);
		
		int cases = Integer.parseInt(br.readLine());
		
		for(int t = 1; t <= cases; t++){
			pw.print("Case #" + t + ": ");
			
			StringTokenizer st = getst(br);
			int l = nextInt(st);
			int x = nextInt(st);
			String str = br.readLine();
			int[] pre = new int[l];
			int[] post = new int[l];
			
			for(int i = 0; i < l; i++){
				pre[i] = get(str.charAt(i));
				post[i] = pre[i];
			}
			
			for(int i = 1; i < l; i++){
				pre[i] = mult[pre[i-1]][pre[i]];
			}
			
			for(int i = l-2; i >= 0; i--){
				post[i] = mult[post[i]][post[i+1]];
			}
			
			int[] pows = new int[4];
			pows[0] = 1;
			
			for(int i = 1; i < 4; i++){
				pows[i] = mult[pows[i-1]][post[0]];
			}
			
			boolean ans = false;
			for(int i = 0; i < 4; i++){
				for(int j = 0; j < 4; j++){
					if(i+j >= x){
						continue;
					}
					for(int k = 0; k < l; k++){
						for(int m = 0; m < l; m++){
							if(mult[pows[i]][pre[k]] == get('i') && mult[post[m]][pows[j]] == get('k')){
								if(i + j == x-1){
									if(k >= m){
										continue;
									}
									if(mult[pre[k]][get('j')] == pre[m-1]){
										ans = true;
										break;
									}
								} else {
									int f2 = mult[(k+1 < l ? post[k+1] : 1)][pows[(x-i-j-2)%4]];
									int all = mult[f2][(m-1 >= 0 ? pre[m-1] : 1)];
									if(all == get('j')){
										ans = true;
										break;
									}
								}
							}
						}
						if(ans){
							break;
						}
					}
					if(ans){
						break;
					}
				}
				if(ans){
					break;
				}
			}
			
			if(ans){
				pw.println("YES");
			} else {
				pw.println("NO");
			}
		}
		
		br.close();
		pw.close();
	}
	
	public static int get(char ch){
		switch(ch){
			case 'i':
				return 2;
			case 'j':
				return 4;
			case 'k':
				return 6;
		}
		return -1; // ???
	}
	
	public static int nextInt(BufferedReader br) throws Exception{
		return Integer.parseInt(br.readLine());
	}
	
	public static int nextInt(StringTokenizer st) throws Exception{
		return Integer.parseInt(st.nextToken());
	}
	
	public static StringTokenizer getst(BufferedReader br) throws Exception{
		return new StringTokenizer(br.readLine(), " ");
	}
}