import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.InputStreamReader;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;


public class FairAndSquare {

	List<BigInteger> list;

	BigInteger current;
	boolean even;

	public BigInteger squarePalindrome(BigInteger big) {

		big = big.pow(2);

		String num = big.toString();
		StringBuffer buffer = new StringBuffer(num);
		String rev = buffer.reverse().toString();

		if (num.equals(rev))
			return big;

		return null;
	}

	public BigInteger nextSqPalindrome() {
		BigInteger sq = squarePalindrome(nextPalindrome());
		while (sq == null)
			sq = squarePalindrome(nextPalindrome());
		return sq;

	}

	public BigInteger nextPalindrome() {
		if (current == null) {
			current = BigInteger.ONE;
			even = false;
		}
		else {
			int len = current.toString().length();
			current = current.add(BigInteger.ONE);
			if (len < current.toString().length()) {
				even = !even;
				if (even)
					current = current.divide(BigInteger.TEN);
			}
		}
		return getPalindrome(current, even);
	}

	public BigInteger getPalindrome(BigInteger current, boolean even) {

		StringBuffer normal = new StringBuffer(current.toString());
		StringBuffer rev = new StringBuffer(current.toString());
		rev.reverse();

		//		System.out.println("normal : " + normal);
		//		System.out.println("reverse: " + rev);

		if (even) {
			normal.append(rev.substring(0));
		}
		else {
			normal.append(rev.substring(1));
		}
		return new BigInteger(normal.toString());
	}

	public void readFile(String file) {
		BufferedReader br;
		FileReader fr;
		BufferedWriter bw;
		FileWriter fw;
		try {
			fr = new FileReader(file);

			br = new BufferedReader(fr);
			fw = new FileWriter("out");
			bw = new BufferedWriter(fw);

			int numCases = Integer.parseInt(br.readLine());

			String[] line;
			BigInteger lo, hi;
			for (int i = 0; i < numCases; ++i) {
				line = br.readLine().split(" ");

				int count = getCount(line[0], line[1]);
				bw.write("Case #" + (i + 1) + ": " + count + "\n");
				System.out.println("Case #" + (i + 1) + ": " + count);
			}
			bw.flush();
			fw.flush();
			fr.close();
			br.close();
			fw.close();
			bw.close();
		} catch (FileNotFoundException e) {
			e.printStackTrace();
		} catch (IOException e) {
			e.printStackTrace();
		}

	}

	//	public void init() {
	//		list = new LinkedList<BigInteger>();
	//
	//		BufferedWriter bw;
	//		FileWriter fw;
	//		try {
	//			fw = new FileWriter("out");
	//			bw = new BufferedWriter(fw);
	//
	//			//pre compute fair squares
	//			String lim = "1";
	//			for (int i = 0; i < 50; ++i)
	//				lim += "0";
	//			System.out.println("limit: " + lim);
	//			
	//			
	//			BigInteger limit = new BigInteger(lim);
	//			BigInteger cur = BigInteger.ONE;
	//			while (cur.compareTo(limit) <  0) {
	//				if ()
	//			}
	//			for (int i = 1; i < 1000000; ++i) {
	//				num = getFair(""+i);
	//				if (num != null)
	//					list.add(num);
	//			}
	//		} catch (IOException e) {
	//			e.printStackTrace();
	//		}
	//	}

	public int getCount(String l, String h) {
		BigInteger lo = new BigInteger(l);
		BigInteger hi = new BigInteger(h);
		BigInteger cur;
		int count = 0;
		Iterator<BigInteger> it = list.iterator();

		//find low
		while (it.hasNext()) {
			cur = it.next();
			//System.out.println(cur);
			if (cur.compareTo(hi) > 0)
				break;
			if (cur.compareTo(lo) >= 0) {
				count++;
			}
		}
		return count;
	}

	public void readSquares(String file) {
		BufferedReader br;
		FileReader fr;
		list = new LinkedList<BigInteger>();

		
		try {
			fr = new FileReader(file);
			br = new BufferedReader(fr);

			String line = br.readLine();
			while (line != null) {
				list.add(new BigInteger(line));
				line = br.readLine();
			}

			fr.close();
			br.close();
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {

		FairAndSquare fas = new FairAndSquare();
		//fas.init();
		fas.readSquares("squares");

		//		Iterator<BigInteger> it = fas.list.iterator();
		//		while (it.hasNext()) 
		//			System.out.println(it.next());


		//		for (int i = 0; i < 1000; ++i)
		//			System.out.println(fas.nextSqPalindrome());

		try {
			//get file
			
			BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
			String file = br.readLine();
			while (file != null && file.length() != 0) {
				fas.readFile(file);
				file = br.readLine();
			}
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
}
