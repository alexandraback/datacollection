import java.io.File;
import java.io.PrintWriter;

import java.util.Scanner;


	public class b {
		static long R = 0;
		static long E = 0;
		final static boolean debug=false;
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
					int XX = in.nextInt();
					int YY = in.nextInt();
					
					int X=Math.abs(XX);
					int Y=Math.abs(YY);
					
					
					
					if(debug)System.out.println("case "+(i+1));
					if(debug)System.out.println("tho min"+(Math.sqrt(((double)2*(X+Y)+0.25))-0.5));
					//long[] r = new long[N];// number of jules we could have used
							
					// but we did not
					String YS="";
					if(YY<0)YS="NS";
					else if (YY>0) YS="SN";
					String XS="";
					if(XX<0)XS="EW";
					else if (XX>0) XS="WE";
					
					
					
					
					
					
					
					result+="Case #"+(i+1)+": "+repeat(YS,Y)+repeat(XS,X)+"\n";
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
		private static String repeat(String xS, int x) {
			
			return new String(new char[x]).replace("\0",xS);
		}
		private static int cal(String substring,int n) {
			int result=0;
			if(debug)System.out.println("first char "+ substring);
			for (int i=0;i<substring.length()-n+1;i++){
				//if(debug)System.out.println("second char "+ i);
			boolean run=true;
				for(int j=i;j<n+i ;j++){
					char c=substring.charAt(j);
				//	if(debug)System.out.println("second char "+ c);
					//if(debug)System.out.println("char "+c);
					if(c=='e' ||c=='a' || c=='e' || c=='i'||c=='o' ||c=='u' )
						{run=false;i=j;break;}
				}
				if(run){return 1;
				
				}
			}
			return result;
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


