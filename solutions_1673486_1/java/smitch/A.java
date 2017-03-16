import java.util.*;
import java.io.*;
public class A {
		private static void GcjMethod(String[] input1, String[] input2){
// 				System.out.println(Arrays.deepToString(input1));
// 				System.out.println(Arrays.deepToString(input2));
				double res=Double.MAX_VALUE;
				int N=Integer.parseInt(input1[1]);
				int M=Integer.parseInt(input1[0]);
				double[] p = new double[M];
				double[] first_mis_prob = new double[M+1];
				double[] exp_val=new double[M];
				for(int i=0; i<M; i++) p[i]=Double.parseDouble(input2[i]);
// 				for(int i=0; i<M; i++) System.out.println(p[i]);

				double tmp_prob=1;
				for(int i=0; i<M; i++){
						first_mis_prob[i]=tmp_prob*(1-p[i]);
						tmp_prob*=p[i];
				}
				first_mis_prob[M]=tmp_prob;
// 				for(int i=0; i<M+1; i++) System.out.println(first_mis_prob[i]);

				// keep typing
				double e_type=(N-M+1)*first_mis_prob[M] + (2*N-M+2)*(1-first_mis_prob[M]);
				if(res>e_type) res=e_type;
				// enter imediately
				double e_enter=N+2;
				if(res>e_enter) res=e_enter;

				// backspace nth character
				tmp_prob=1.0;
				for(int n=0; n<M+1; n++){
						double exp;
						tmp_prob-=first_mis_prob[M-n];
						exp=(2*n+N-M+1)*(1-tmp_prob) + (2*(n+N+1)-M)*tmp_prob;
						if(res>exp) res=exp;
				}

				System.out.println(res);
				return;
		}

		public static final void main(final String[] args) {
				String line1, line2;
				int numCase;
				String[] input1, input2;

				BufferedReader d = new BufferedReader(new InputStreamReader(System.in));
				try{
						numCase=Integer.parseInt(d.readLine());
						for(int i=0; i<numCase; i++){
								System.out.print(String.format("Case #%d: ", i+1));

								line1=d.readLine();
								input1=line1.split(" ");
								line2=d.readLine();
								input2=line2.split(" ");

								GcjMethod(input1, input2);
						}
				}
				catch(Exception e){
						System.out.println(e);
				}
		}
}
