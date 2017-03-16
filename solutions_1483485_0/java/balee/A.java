import java.io.FileInputStream;
import java.util.Scanner;

// Speaking in Tongues
// https://code.google.com/codejam/contest/1460488/dashboard

public class A {

	private static byte[] mappingRev = new byte[256];
	private static byte[] mapping = new byte[256];

	private static String process(Scanner in) {
		byte[] text = in.nextLine().getBytes();
		StringBuffer res = new StringBuffer();
		for(int i = 0; i < text.length; i++)
			res.append((char)mapping[text[i]]);
		return new String(res);
	}

	private static void init(String from, String to) {
		byte[] fromBytes = from.getBytes();
		byte[] toBytes = to.getBytes();
		for(int i = 0; i < fromBytes.length; i++) {
			mappingRev[toBytes[i]] = fromBytes[i];
			mapping[fromBytes[i]] = toBytes[i];
		}
	}

	public static void main(String[] args) throws Exception {
		Scanner in = new Scanner(System.in.available() > 0 ? System.in : 
			new FileInputStream(Thread.currentThread().getStackTrace()[1].getClassName() + ".practice.in"));
		int T = in.nextInt();
		in.nextLine();

		init("a zoo", "y qee");
		init("ejp mysljylc kd kxveddknmc re jsicpdrysi", "our language is impossible to understand");
		init("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd", "there are twenty six factorial possibilities");
		init("de kr kd eoya kw aej tysr re ujdr lkgc jv", "so it is okay if you want to just give up");

		/*
		// 122 is not mapped
		for(int i = 97; i < 123; i++)
			if ( mapping[i] == 0 )
				System.out.println(i + ": " + i); 

		// 113 is not mapped to
		for(int i = 97; i < 123; i++)
			if ( xmapping[i] == 0 )
				System.out.println(i + ": " + i);
		 */

		mapping[113] = 122;

		for(int i = 1; i <= T; i++) 
			System.out.format("Case #%d: %s\n", i, process(in));
	}
}
