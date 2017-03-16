package gcj2012.qual;


import java.util.Arrays;
import java.util.Comparator;

import org.korifey.ffalg.FFBitSet;

import common.AbstractRunner;
import common.AbstractRunner.SIZE;

public class A extends AbstractRunner {
	
	public A() {
		super();
		init();
	}
	
	char[] map;
	
	public void init() {
		map = new char[256];
		String testInput = "y qee ejp mysljylc kd kxveddknmc re jsicpdrysi "+
				"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd " +
				"de kr kd eoya kw aej tysr re ujdr lkgc jv";
		
		String testOutput = "a zoo our language is impossible to understand " +
				"there are twenty six factorial possibilities " +
				"so it is okay if you want to just give up";
		
		Arrays.fill(map, '?');
		//FFBitSet bs = new FFBitSet(26);
		for (int i=0; i<testInput.length(); i++) {
			assert(map[testInput.charAt(i)] == '?' || map[testInput.charAt(i)] == testOutput.charAt(i));			
			map[testInput.charAt(i)] = testOutput.charAt(i);
			//if (Character.isLetter(testOutput.charAt(i))) bs.set(testOutput.charAt(i) - 'a');
		}
		map['z'] = 'q';
		
		/*for (char c = 'a'; c <= 'z'; c++) {
			if (!bs.get(c - 'a')) System.out.println(c);
		}*/
	}
	
	@Override
	public void handleCase(int caseNumber) throws Exception {		
		String s = scanner.nextLine().trim();
		char[] res = new char[s.length()];
		for (int i=0; i<s.length(); i++) {
			res[i] = map[s.charAt(i)];
		}
		out.append(new String(res)+"\n");
	}
	
	public static void main(String[] args) throws Exception {
		new A().init(SIZE.small).execute();
	}
}
