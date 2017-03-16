import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;
import java.util.TreeSet;


public class Pali {
	public static void main(String[] args) throws Exception {
		PrintWriter out = new PrintWriter("outPali.txt");
		Scanner sc=  new Scanner(System.in);
		int T = sc.nextInt();
		TreeSet<Long> PALI = new TreeSet<Long>();
		for(long a=1;a<=10000000;a++){
			if(PAL(a)&&PAL(a*a)){
				PALI.add(a*a);
			//	System.out.println(a*a);
			}
		}
		long[] array = new long[PALI.size()];
		int place = 0;
		for(Long x : PALI)array[place++]=x;
		Arrays.sort(array);
		for(int t=1;t<=T;t++){
			long start = sc.nextLong();
			long end = sc.nextLong();
			int p1 = 0;
			int p2 = array.length-1;
			while(array[p1]<start)p1++;
			while(array[p2]>end)p2--;
			out.println("Case #"+t+": "+(p2-p1+1));
		}
		out.close();

	}

	private static boolean PAL(long i) {
		String cur = i+"";
		for(int a=0;a<cur.length()/2;a++){
			if(cur.charAt(a)!=cur.charAt(cur.length()-a-1))return false;
		}
		return true;
	}

}
