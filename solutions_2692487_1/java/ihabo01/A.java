import java.io.File;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;


	public class A {
		static long R = 0;
		static long E = 0;

		public static void main(String[] args) {
			String inputSource = "C:\\Personal\\Personal\\Competitions\\codejam-commandline-1.2-beta1\\source\\";
			String inputRelative = "A-small-0";

			File input = new File(inputSource + inputRelative + ".in");

			try {
				Scanner in = new Scanner(input);
				String result = "";
				// String debug="";
				int numberOfCases;
				numberOfCases = in.nextInt();
				for (int i = 0; i < numberOfCases; i++) {
					long A = in.nextLong();
					int N = in.nextInt();
					
					long[] a = new long[N];
					ArrayList<Long> ab=new ArrayList();
					
					//long[] r = new long[N];// number of jules we could have used
											// but we did not
					
					
					for (int j = 0; j < N; j++) {
						a[j] = in.nextLong();

						ab.add(a[j]);
					}
					
					Arrays.sort(a);
					long resultt=0;
					int last=N;
					int start=0;
					
					
					
					result+="Case #"+(i+1)+": "+min(A,a,0)+"\n";
				//	System.out.println(result);
				}	
				System.out.println(result);
				PrintWriter out = new PrintWriter(inputSource + inputRelative
						+ ".out");
				out.println(result);
				out.close();
				// PrintWriter debugp = new PrintWriter(inputSource +
				// inputRelative
				// + ".debug");
				// debugp.println(debug);
				// debugp.close();
				in.close();
				// System.out.println(debug);
				// System.out.println(result);
			} catch (Exception e) {
				e.printStackTrace();
			}
		}
		public static long min(long A, long[] a, int j){
			if(j==a.length-1){ 
				if (A> a[a.length-1]) return 0;
				else
				return 1;
			}
			if(A> a[j]) return min(A+a[j],a,j+1);
			else{
				System.out.println(A+","+j);
				if(A==1)return a.length-j;
				return Math.min(a.length-j,1+min(A+A-1,a,j));
			}
		}
	}


