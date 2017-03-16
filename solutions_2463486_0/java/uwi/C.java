package gcj2013.q;
import java.io.File;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.Date;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class C {
	static String BASEPATH = "x:\\gcj\\";
	static boolean LARGE = false;
	static String INPATH = BASEPATH + C.class.getSimpleName().charAt(0) + (LARGE ? "-large.in" : "-small-attempt0.in");
	static String OUTPATH = INPATH.substring(0, INPATH.length()-3) + new SimpleDateFormat("-HHmmss").format(new Date()) + ".out";
	
	static String INPUT = "";
	
	static List<BigInteger> list;
	
	public static void prepare()
	{
		Set<BigInteger> set = new HashSet<BigInteger>();
		set.add(BigInteger.valueOf(3));
		for(int L = 1;L <= 25;L++){
			// center
			for(int i = 0;i < 1<<L-1;i++){
				int j = i<<1|1;
				int h = i>>>L&1;
				int x = 2*Integer.bitCount(j)-h;
				if(x <= 9){
					char[] num = new char[2*L-1];
					for(int k = 0;k < L;k++){
						num[k] = num[2*L-2-k] = (char)('0'+(j>>>k&1));
					}
					set.add(new BigInteger(new String(num)));
				}
			}
			// LR
			for(int i = 0;i < 1<<L-1;i++){
				int j = i<<1|1;
				int x = 2*Integer.bitCount(j);
				if(x <= 9){
					char[] num = new char[2*L];
					for(int k = 0;k < L;k++){
						num[k] = num[2*L-1-k] = (char)('0'+(j>>>k&1));
					}
					set.add(new BigInteger(new String(num)));
				}
			}
			
			// 2001002
			{
				char[] num = new char[2*L-1];
				Arrays.fill(num, '0');
				num[L-1] = '1';
				num[0] = num[2*L-2] = '2';
				set.add(new BigInteger(new String(num)));
			}
			// 2000002
			{
				char[] num = new char[2*L-1];
				Arrays.fill(num, '0');
				num[0] = num[2*L-2] = '2';
				set.add(new BigInteger(new String(num)));
			}
			// 200002
			{
				char[] num = new char[2*L];
				Arrays.fill(num, '0');
				num[0] = num[2*L-1] = '2';
				set.add(new BigInteger(new String(num)));
			}
			// 1012101
			for(int i = 0;i < L;i++){
				char[] num = new char[2*L-1];
				Arrays.fill(num, '0');
				num[L-1] = '2';
				num[0] = num[2*L-2] = '1';
				num[i] = num[2*L-2-i] = '1';
				set.add(new BigInteger(new String(num)));
			}
		}
		
		list = new ArrayList<BigInteger>(set);
		Collections.sort(list);
		for(int i = 0;i < list.size();i++){
			list.set(i, list.get(i).multiply(list.get(i)));
		}
//		System.err.println(list.size());
//		for(BigInteger b : list){
//			String x = b.multiply(b).toString();
//			for(int i = 0, j = x.length()-1;i < j;i++,j--){
//				if(x.charAt(i) != x.charAt(j)){
//					tr("dead", b);
//					break;
//				}
//			}
//		}
	}
	
	public void call()
	{
		BigInteger a = in.nextBigInteger();
		BigInteger b = in.nextBigInteger();
		int inda = Collections.binarySearch(list, a.subtract(BigInteger.ONE));
		int indb = Collections.binarySearch(list, b);
		if(inda < 0)inda = -inda-2;
		if(indb < 0)indb = -indb-2;
		out.println(indb-inda);
	}
	
	Scanner in;
	PrintWriter out;
	int cas;
	
	public C(int cas, Scanner in, PrintWriter out)
	{
		this.cas = cas;
		this.in = in;
		this.out = out;
	}
	
	int ni() { return Integer.parseInt(in.next()); }
	long nl() { return Long.parseLong(in.next()); }
	double nd() { return Double.parseDouble(in.next()); }
	void tr(Object... o) { if(INPUT.length() != 0)System.out.println(Arrays.deepToString(o)); }
	
	public static void main(String[] args) throws Exception
	{
		long start = System.currentTimeMillis();
		boolean real = INPUT.isEmpty();
		
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
		Scanner in = real ? new Scanner(new File(INPATH)) : new Scanner(INPUT);
		PrintWriter out = real ? new PrintWriter(new File(OUTPATH)) : new PrintWriter(System.out);
		prepare();
		int n = in.nextInt();
		in.nextLine();
		
		for(int i = 0;i < n;i++){
			out.printf("Case #%d: ", i+1);
			new C(i+1, in, out).call();
			out.flush();
			if(real)System.err.println("case " + (i + 1) + " solved.\t");
		}
		
		long end = System.currentTimeMillis();
		System.out.println((end - start) + "ms");
		if(real){
			System.out.println("INPATH : " + INPATH);
			System.out.println("OUTPATH : " + OUTPATH);
		}
	}
}
