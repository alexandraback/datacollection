import java.io.*;
import java.util.*;
import java.math.BigInteger;

public class Pal{

	public static long[] q = {1,
4,
9,
121,
484,
10201,
12321,
14641,
40804,
44944,
1002001,
1234321,
4008004,
100020001,
102030201,
104060401,
121242121,
123454321,
125686521,
400080004,
404090404,
10000200001L,
10221412201L,
12102420121L,
12345654321L,
40000800004L,
1000002000001L,
1002003002001L,
1004006004001L,
1020304030201L,
1022325232201L,
1024348434201L,
1210024200121L,
1212225222121L,
1214428244121L,
1232346432321L,
1234567654321L,
4000008000004L,
4004009004004L,
100000020000001L,
100220141022001L,
102012040210201L,
102234363432201L,
121000242000121L,
121242363242121L,
123212464212321L,
123456787654321L,
400000080000004L};

	public static void main(String[] args) throws IOException{

		BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		int t = Integer.parseInt(br.readLine());

		for(int i = 1; i <= t; i++) {
			String[] tmp = br.readLine().split(" ");
			long a = Long.parseLong(tmp[0]);
			long b = Long.parseLong(tmp[1]);

			int ret = 0;

			for(long l : q) {
				if(a <= l && l <= b)
					ret++;
			}

			pw.println("Case #" + i + ": " + ret);

		}



		pw.flush();
		pw.close();
	}



		/*
	public static void main(String[] args) throws IOException{

		//BufferedReader br = new BufferedReader(new FileReader("in.txt"));
		PrintWriter pw = new PrintWriter(new FileWriter("out.txt"));

		//int t = Integer.parseInt(br.readLine());

		long N = 100000000L;

		for(long n = 1; n <= N; n++) {
			if(n % 1000000L == 0)
				System.out.println(n);

			if(!pal(n + ""))
				continue;

			BigInteger big = new BigInteger(n +"");
			big = big.multiply(big);
			if(pal(big.toString()))
				pw.println(big.toString());
		}



		pw.flush();
		pw.close();
	}

	public static boolean pal(String s) {
		for(int i = 0; i < (1+s.length())/2; i++) {
			if(s.charAt(i) != s.charAt(s.length() - i - 1))
				return false;
		}

		return true;
	}
*/
}