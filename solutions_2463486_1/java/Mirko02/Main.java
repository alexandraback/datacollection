import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Scanner;

public class Main {

	private Scanner in;
	private ArrayList<BigInteger> list;

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		Main main = new Main();
		main.doWork();
	}

	private void doWork() {
		int T = in.nextInt();

		for (int i = 0; i < T; i++) {
			System.out.print("Case #" + (i + 1) + ": ");
			doCase();
		}
	}

	private void doCase() {
		BigInteger a = new BigInteger(in.next());
		BigInteger b = new BigInteger(in.next());

		int ans = 0;
		for (BigInteger x : list) {
			if (a.compareTo(x) <= 0 && x.compareTo(b) <= 0) {
				ans++;
			}
		}

		System.out.println(ans);
	}

	public Main() {
		in = new Scanner(System.in);
		list = new ArrayList<BigInteger>(100);
		list.add(new BigInteger("1"));
		list.add(new BigInteger("4"));
		list.add(new BigInteger("9"));
		list.add(new BigInteger("121"));
		list.add(new BigInteger("484"));
		list.add(new BigInteger("10201"));
		list.add(new BigInteger("12321"));
		list.add(new BigInteger("14641"));
		list.add(new BigInteger("40804"));
		list.add(new BigInteger("44944"));
		list.add(new BigInteger("1002001"));
		list.add(new BigInteger("1234321"));
		list.add(new BigInteger("4008004"));
		list.add(new BigInteger("100020001"));
		list.add(new BigInteger("102030201"));
		list.add(new BigInteger("104060401"));
		list.add(new BigInteger("121242121"));
		list.add(new BigInteger("123454321"));
		list.add(new BigInteger("125686521"));
		list.add(new BigInteger("400080004"));
		list.add(new BigInteger("404090404"));
		list.add(new BigInteger("10000200001"));
		list.add(new BigInteger("10221412201"));
		list.add(new BigInteger("12102420121"));
		list.add(new BigInteger("12345654321"));
		list.add(new BigInteger("40000800004"));
		list.add(new BigInteger("1000002000001"));
		list.add(new BigInteger("1002003002001"));
		list.add(new BigInteger("1004006004001"));
		list.add(new BigInteger("1020304030201"));
		list.add(new BigInteger("1022325232201"));
		list.add(new BigInteger("1024348434201"));
		list.add(new BigInteger("1210024200121"));
		list.add(new BigInteger("1212225222121"));
		list.add(new BigInteger("1214428244121"));
		list.add(new BigInteger("1232346432321"));
		list.add(new BigInteger("1234567654321"));
		list.add(new BigInteger("4000008000004"));
		list.add(new BigInteger("4004009004004"));
		list.add(new BigInteger("100000020000001"));
		list.add(new BigInteger("100220141022001"));
		list.add(new BigInteger("102012040210201"));
		list.add(new BigInteger("102234363432201"));
		list.add(new BigInteger("121000242000121"));
		list.add(new BigInteger("121242363242121"));
		list.add(new BigInteger("123212464212321"));
		list.add(new BigInteger("123456787654321"));
		list.add(new BigInteger("400000080000004"));
		list.add(new BigInteger("10000000200000001"));
		list.add(new BigInteger("10002000300020001"));
		list.add(new BigInteger("10004000600040001"));
		list.add(new BigInteger("10020210401202001"));
		list.add(new BigInteger("10022212521222001"));
		list.add(new BigInteger("10024214841242001"));
		list.add(new BigInteger("10201020402010201"));
		list.add(new BigInteger("10203040504030201"));
		list.add(new BigInteger("10205060806050201"));
		list.add(new BigInteger("10221432623412201"));
		list.add(new BigInteger("10223454745432201"));
		list.add(new BigInteger("12100002420000121"));
		list.add(new BigInteger("12102202520220121"));
		list.add(new BigInteger("12104402820440121"));
		list.add(new BigInteger("12122232623222121"));
		list.add(new BigInteger("12124434743442121"));
		list.add(new BigInteger("12321024642012321"));
		list.add(new BigInteger("12323244744232321"));
		list.add(new BigInteger("12343456865434321"));
		list.add(new BigInteger("12345678987654321"));
		list.add(new BigInteger("40000000800000004"));
		list.add(new BigInteger("40004000900040004"));
		list.add(new BigInteger("1000000002000000001"));
		list.add(new BigInteger("1000220014100220001"));
		list.add(new BigInteger("1002003004003002001"));
		list.add(new BigInteger("1002223236323222001"));
		list.add(new BigInteger("1020100204020010201"));
		list.add(new BigInteger("1020322416142230201"));
		list.add(new BigInteger("1022123226223212201"));
		list.add(new BigInteger("1022345658565432201"));
		list.add(new BigInteger("1210000024200000121"));
		list.add(new BigInteger("1210242036302420121"));
		list.add(new BigInteger("1212203226223022121"));
		list.add(new BigInteger("1212445458545442121"));
		list.add(new BigInteger("1232100246420012321"));
		list.add(new BigInteger("1232344458544432321"));
		list.add(new BigInteger("1234323468643234321"));
		list.add(new BigInteger("4000000008000000004"));
	}
}
