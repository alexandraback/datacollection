package jc2012a;

import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class b {

	static PrintWriter pw;
	static int testOut=1;
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		Scanner sc = new Scanner(new FileReader("C://CODEJAM//2012//B-small-attempt3.in"));
		pw = new PrintWriter(new FileWriter("C://CODEJAM//2012//B.out"));
		
		int ntest = sc.nextInt();
		sc.nextLine();
		
		int y=0;
		int stars=0;
		for(int test=1;test<=ntest;++test) {
			int N= sc.nextInt(); //levels

			int[] as = new int[N];
			int[] bs = new int[N];
			int[] bigstars = new int[N];
			int maxa=0; int maxb=0;
			for(int i=0;i<N;i++)
			{
				int a =sc.nextInt(); //req 1 s
				int b =sc.nextInt(); //req 2 s
				as[i]=a;
				bs[i]=b;
				if (a>maxa)
				{
					maxa=a;
				}
				if (b>maxb)
				{
					maxb=b;
				}
				bigstars[i]=2;
			}
			
//			for(int i=0;i<N;i++)
//			{
//				System.out.print(as[i]+",");
//			}
//			System.out.println();
			
			//sort(as);
			//sort(bs);
			int[] orgas = Arrays.copyOf(as, as.length);
			Arrays.sort(as);
			Arrays.sort(bs);
			
			
//			for(int i=0;i<N;i++)
//			{
//				System.out.print(as[i]+",");
//			}
//			System.out.println();
			
			int apos=0; int bpos=0; stars=0;y=0;
			while (true)
			{
				if (bpos<N && stars>=bs[bpos])
				{
					stars++;
					for(int i=0;i<N;i++)
					{
						if (orgas[i]==bs[bpos] && bigstars[i]==2)
						{
							//bigstars[i]=0;
							stars++;
							break;
						}
					}
					bpos++;
				}
				else if (apos<N && stars>=as[apos])
				{
					stars+=1;
					for(int i=0;i<N;i++)
					{
						if (orgas[i]==as[apos] && bigstars[i]!=1)
						{
							bigstars[i]=1;
							break;
						}
					}
					apos++;
				}
				else
				{
					y=0;
					break;
				}
					
				
				y++;
				if (bpos==N)
				{
					break;
				}
				if (apos>N || bpos>N)
				{
					y=0;
					break;
				}
			}
			
			if(y==0)
			{
				wc("Too Bad");
			}
			else
			{
			wc(y+"");
			}
			
		}
		
	
		pw.close();
		sc.close();
		System.out.println("finished");
	}
	
//    public static void sort(int[] a, int maxVal){
//        int [] bucket=new int[maxVal+1];
//
//        for (int i=0; i<bucket.length; i++){
//            bucket[i]=0;
//        }
//
//        for (int i=0; i<a.length; i++){
//            bucket[a[i]]++;
//        }
//
//        int outPos=0;
//        for (int i=0; i<bucket.length; i++){
//            for (int j=0; j<bucket[i]; j++){
//                a[outPos++]=i;
//            }
//        }
//    }
	
		 
//		   public static int[] sort(int[] arr) {
//		     int i, j;
//		     int[] count = new int[arr.length];
//		     for(i = 0; i < arr.length; i++ ) {
//		       count[arr[i]]++;
//		     }
//		     for(i=0,j=0; i < count.length; i++) {
//		       for(; count[i]>0; (count[i])--) {
//		         arr[j++] = i;
//		       }
//		     }
//		     return arr;
//		   }


	private static void wc(String text) {
		String tt="Case #" + testOut++ + ": " + text;
		pw.print(tt);
		pw.println();
		System.out.println(tt);
	}
}
