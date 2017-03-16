package qual;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Scanner;

public class FairandSquare {
	private HashSet<Long> fairs;

	public static void main(String[] args) {
		new FairandSquare().run();
	}

	private boolean isFair(long l) {
		String origStr = Long.toString(l);
		String newStr = new StringBuffer(origStr).reverse().toString();
		return origStr.equals(newStr);
	}

	private void run() {
		fairs = new HashSet<Long>();
//		long max = (long) Math.sqrt(100000000000000);
//		for (long i = 1; i <= max; i++) {
//			if (isFair(i) && isFair(i * i)) {
//				System.out.printf("fairs.add(%dL);\n", i * i);
//				fairs.add(i * i);
//			}
//		}
		fairs.add(1L);
		fairs.add(4L);
		fairs.add(9L);
		fairs.add(121L);
		fairs.add(484L);
		fairs.add(10201L);
		fairs.add(12321L);
		fairs.add(14641L);
		fairs.add(40804L);
		fairs.add(44944L);
		fairs.add(1002001L);
		fairs.add(1234321L);
		fairs.add(4008004L);
		fairs.add(100020001L);
		fairs.add(102030201L);
		fairs.add(104060401L);
		fairs.add(121242121L);
		fairs.add(123454321L);
		fairs.add(125686521L);
		fairs.add(400080004L);
		fairs.add(404090404L);
		fairs.add(10000200001L);
		fairs.add(10221412201L);
		fairs.add(12102420121L);
		fairs.add(12345654321L);
		fairs.add(40000800004L);
		fairs.add(1000002000001L);
		fairs.add(1002003002001L);
		fairs.add(1004006004001L);
		fairs.add(1020304030201L);
		fairs.add(1022325232201L);
		fairs.add(1024348434201L);
		fairs.add(1210024200121L);
		fairs.add(1212225222121L);
		fairs.add(1214428244121L);
		fairs.add(1232346432321L);
		fairs.add(1234567654321L);
		fairs.add(4000008000004L);
		fairs.add(4004009004004L);
		fairs.add(100000020000001L);
		fairs.add(100220141022001L);
		fairs.add(102012040210201L);
		fairs.add(102234363432201L);
		fairs.add(121000242000121L);
		fairs.add(121242363242121L);
		fairs.add(123212464212321L);
		fairs.add(123456787654321L);
		fairs.add(400000080000004L);
		fairs.add(10000000200000001L);
		fairs.add(10002000300020001L);
		fairs.add(10004000600040001L);
		fairs.add(10020210401202001L);
		fairs.add(10022212521222001L);
		fairs.add(10024214841242001L);
		fairs.add(10201020402010201L);
		fairs.add(10203040504030201L);
		fairs.add(10205060806050201L);
		fairs.add(10221432623412201L);
		fairs.add(10223454745432201L);
		fairs.add(12100002420000121L);
		fairs.add(12102202520220121L);
		fairs.add(12104402820440121L);
		fairs.add(12122232623222121L);
		fairs.add(12124434743442121L);
		fairs.add(12321024642012321L);
		fairs.add(12323244744232321L);
		fairs.add(12343456865434321L);
		fairs.add(12345678987654321L);
		fairs.add(40000000800000004L);
		fairs.add(40004000900040004L);
		fairs.add(1000000002000000001L);
		fairs.add(1000220014100220001L);
		fairs.add(1002003004003002001L);
		fairs.add(1002223236323222001L);
		fairs.add(1020100204020010201L);
		fairs.add(1020322416142230201L);
		fairs.add(1022123226223212201L);
		fairs.add(1022345658565432201L);
		fairs.add(1210000024200000121L);
		fairs.add(1210242036302420121L);
		fairs.add(1212203226223022121L);
		fairs.add(1212445458545442121L);
		fairs.add(1232100246420012321L);
		fairs.add(1232344458544432321L);
		fairs.add(1234323468643234321L);
		fairs.add(4000000008000000004L);

		Scanner sc = new Scanner(System.in);
		int T = sc.nextInt();
		for (int t = 0; t < T; t++) {
			long start = sc.nextLong();
			long end = sc.nextLong();
			int result = solve(start, end);
			System.out.printf("Case #%d: %d\n", t + 1, result);
		}
	}

	private int solve(long start, long end) {
		int count = 0;
		Iterator<Long> it = fairs.iterator();
		while (it.hasNext()) {
			Long l = (Long) it.next();
			if (start <= l && l <= end) {
//				System.err.printf(" - %d\n", l);
				count++;
			}
		}
//		long s = (long) Math.sqrt(start);
//		if (s * s < start) s++;
//		long e = (long) Math.sqrt(end);
//		for (long i = s; i <= e; i++) {
//			if (isFair(i) && isFair(i * i)) {
//				count++;
//			}
//		}
		return count;
	}

}
