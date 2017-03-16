import java.io.File;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;


public class A {
	public static void main(String[] args) throws Exception{
		Scanner sc =new Scanner(new File("A.in"));
		PrintWriter out = new PrintWriter(new File("A.out"));
		int T = sc.nextInt();
		int best = Integer.MAX_VALUE;
		for(int t=1;t<=T;t++){
			int many = 0;
			long cur = sc.nextLong();
			int N = sc.nextInt();
			best = N;
			int[] array = new int[N];
			for(int a=0;a<N;a++)array[a]=sc.nextInt();
			if(cur!=1){
				Arrays.sort(array);
				for(int a=0;a<N;a++){
					while(cur<=array[a]){
						cur+=cur-1;
						many++;
					}
					best = Math.min(many+(N-a-1),best);
					cur+=array[a];
				}
			}
			System.out.printf("Case #%d: %d%n",t,best);
			out.printf("Case #%d: %d%n",t,best);
		}
		out.close();
	}
}
