import java.util.*;
import java.io.*;
public class pass {
	public static void main(String[] args) throws Exception{
		Scanner sc = new Scanner(new File("pass.in"));
		PrintWriter out = new PrintWriter("pass.out");
		int C = sc.nextInt();
		for(int i=1;i<=C;i++){
			int A = sc.nextInt();
			int B = sc.nextInt();
			double happy = 1.0;
			double[] array = new double[A];
			for(int a=0;a<A;a++){
				array[a]=sc.nextDouble();
				happy*=array[a];
			}
			double ans = Double.MAX_VALUE;

			double temp = (happy*(B-A+1))+((1-happy)*(B-A+1+B));
			ans = Math.min(temp,ans);
			int T = A-1;
			while(T>=0){
				happy/=array[T];
				temp = (happy*(B-T+1))+((1-happy)*(B-T+1+B+1))+(A-T);
				ans = Math.min(temp,ans);
				T--;
			}
			
			
			
			
			//enter type
			ans=Math.min(ans,B+2);
			
			
			out.printf("Case #%d: %.6f\n",i,ans);

	}
		out.close();
}

}

