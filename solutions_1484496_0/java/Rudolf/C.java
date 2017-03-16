package ua.rudolf.codejam.contest2012;

import java.io.BufferedInputStream;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.TreeMap;
import java.util.TreeSet;

public class C {

	/**
	 * @param args
	 * @throws FileNotFoundException 
	 */
	public static void main(String[] args) throws FileNotFoundException {
		System.setIn(new BufferedInputStream(new FileInputStream("C-small-attempt0.in")));
		System.setOut(new PrintStream(new FileOutputStream("c.out")));
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int ti = 0; ti < t; ti++)
		{
			int n = sc.nextInt();
			TreeMap<Long, Long> ts = new TreeMap<Long, Long>();
			ts.put(0l, 0l);
			Long needSum = null;
			Long secondItem = null;
			TreeMap<Long, Long> ts1;
			for(int j = 0; j < n; j++)
			{
				ts1 = new TreeMap<Long, Long>();
				ts1.putAll(ts);
				Long l = sc.nextLong();
				for(Entry<Long, Long> s: ts.entrySet())
				{
					Long nextV = l + s.getKey();
					if(ts1.containsKey(nextV)){
						needSum = nextV;
						secondItem = l;
					}else{
						ts1.put(nextV, l);
					}
				}
				ts = ts1;
			}
			System.out.println("Case #" + (ti + 1) + ":");
			if(needSum == null)
				System.out.println("Impossible");
			else{
				Long cur = needSum;
				while(cur != 0){
					System.out.print(ts.get(cur) + " ");
					cur -= ts.get(cur);
				}
				System.out.println();

				cur = needSum;
				ts.put(cur, secondItem);
				while(cur != 0){
					System.out.print(ts.get(cur) + " ");
					cur -= ts.get(cur);
				}
				System.out.println();
			}
		}
	}

}
