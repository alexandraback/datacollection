import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.*;
public class B {
	public static void main(String[] args) throws Exception {
		Scanner sc = new Scanner(new File("B.in"));
		PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("B.out")));
		int C = sc.nextInt();
		for(int i=1;i<=C;i++){
			int N = sc.nextInt();
			int S = sc.nextInt();
			int B = sc.nextInt();
			boolean[] pass = new boolean[N];
			boolean[] wierd = new boolean[N];
			troll:for(int a=0;a<N;a++){
				int P = sc.nextInt();
				for(int b=0;b<=10;b++){
					for(int c=b-2;c<=b+2;c++){
						if(c>10||c<0)continue;
						for(int d=b-2;d<=b+2;d++){
							
							if(d>10||d<0)continue;
							if(b+c+d!=P)continue;
							int small = Math.min(Math.min(b,c),d);
							int big = Math.max(Math.max(b,c),d);
						//	System.out.println(b+" "+c+" "+d);
							if(big>=B){
								if(big-small==2){
									
								//	System.out.println(b+" "+c+" "+d);
									wierd[a]=true;
								}
								else if(big-small<2){
									pass[a]=true;
								//	System.out.println(b+" "+c+" "+d);
									continue troll;
								}
							}
						}
					}
				}
			}
		//	System.out.println(Arrays.toString(pass));
		//	System.out.println(Arrays.toString(wierd));
			int ans = 0;
			int used = 0;
			for(int a=0;a<N;a++){
				if(pass[a]){
					ans++;
					continue;
				}
				if(wierd[a]){
					if(used<S)ans++;
					used++;
				}
			}
			out.println("Case #"+i+": "+ans);
		}
		out.close();

	}

}
