import java.util.*;
import java.io.*;


public class gcj3 {
	
	public static void main(String [] args) throws Exception
	{
		//test(null);
		long [] arr = new long[100];
		arr[0]=1L;
		arr[1]=4L;
		arr[2]=9L;
		arr[3]=121L;
		arr[4]=484L;
		arr[5]=10201L;
		arr[6]=12321L;
		arr[7]=14641L;
		arr[8]=40804L;
		arr[9]=44944L;
		arr[10]=1002001L;
		arr[11]=1234321L;
		arr[12]=4008004L;
		arr[13]=100020001L;
		arr[14]=102030201L;
		arr[15]=104060401L;
		arr[16]=121242121L;
		arr[17]=123454321L;
		arr[18]=125686521L;
		arr[19]=400080004L;
		arr[20]=404090404L;
		arr[21]=10000200001L;
		arr[22]=10221412201L;
		arr[23]=12102420121L;
		arr[24]=12345654321L;
		arr[25]=40000800004L;
		arr[26]=1000002000001L;
		arr[27]=1002003002001L;
		arr[28]=1004006004001L;
		arr[29]=1020304030201L;
		arr[30]=1022325232201L;
		arr[31]=1024348434201L;
		arr[32]=1210024200121L;
		arr[33]=1212225222121L;
		arr[34]=1214428244121L;
		arr[35]=1232346432321L;
		arr[36]=1234567654321L;
		arr[37]=4000008000004L;
		arr[38]=4004009004004L;
		arr[39]=100000020000001L;
		arr[40]=100220141022001L;
		arr[41]=102012040210201L;
		arr[42]=102234363432201L;
		arr[43]=121000242000121L;
		arr[44]=121242363242121L;
		arr[45]=123212464212321L;
		arr[46]=123456787654321L;
		arr[47]=400000080000004L;
		
		
		String file = "C-large-1.in";
		Scanner scanner = new Scanner(new FileInputStream(file));
		PrintStream ps = new PrintStream(file + ".out");
		
		int tot = scanner.nextInt();
		for (int tt = 0; tt < tot; tt ++) {
			long beg = scanner.nextLong();
			long end = scanner.nextLong();
			int idbeg = 0;
			int idend = 47;
			while (beg > arr[idbeg] && idbeg < 47) {
				idbeg ++;
			}
			while (end < arr[idend] && idend >= 0) {
				idend --;
			}
			ps.println("Case #" + (tt + 1) + ": " + (idend - idbeg + 1));
			
		}
		ps.close();
	}
	
	public static boolean ispa(String x)
	{
		for (int i = 0; i < x.length() / 2; i ++) {
			if (x.charAt(i) != x.charAt(x.length() - 1 - i)) return false;
		}
		return true;
	}
	public static void test(String [] args) throws Exception {
		int cnt = 0;
		for (long i = 1; i < 100000000; i ++) {
			if (ispa("" + i) && ispa("" + i * i)) {
				if (i * i < 10e14) {
					System.out.println("arr[" + cnt + "]=" + i * i + "L;");
					cnt ++;
				}
			}
		}
		
		
	}
}
