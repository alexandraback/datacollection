import java.io.*;
import java.util.*;


public class C_Qual {
	public static void main(String[] args) throws IOException {
		Scanner in = new Scanner(System.in);
		int T = in.nextInt();
		for (int tt = 1; tt <= T; tt++) {
			int a=in.nextInt(),b=in.nextInt();
			int res=0;
			for(int i=a;i<=b;i++){
				String num = i+"";
				HashSet<Integer> vis=new HashSet<Integer>();
				for(int j=0;j<num.length();j++){
					String newNum = num.substring(j)+num.substring(0,j);
					int n = new Integer(newNum);
					if(i<n&&n>=a&&n<=b){
						if(vis.contains(n)){
							continue;
						}
						vis.add(n);
						res++;
					}
				}
			}
			System.out.printf("Case #%d: %d\n", tt,res);
		}
	}
	}