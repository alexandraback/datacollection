package round1b;

import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;

/**
 * {在这里补充类的功能说明}
 * 
 * @author 高磊 gaolei@feinno.com
 */
public class C
{	
	public static void main(String[] args) throws Exception
	{
		C instance = new C("C-small-attempt0.in");
		instance.loadDictionary();
		instance.slove();
		instance.writer.close();
	}
	
	private Scanner scaner;
	private PrintWriter writer; 
	
	public C(String inf) throws Exception
	{
		scaner = new Scanner(new FileInputStream(inf));
		writer = new PrintWriter(new FileOutputStream(inf + ".out"));		
	}
	
	private HashSet<String> dic = new HashSet<String>();
	private List<String> words = new ArrayList<String>();
	private HashMap<R, Integer> results = new HashMap<R, Integer>();
	
	private void loadDictionary() throws Exception
	{
		FileInputStream stream = new FileInputStream("garbled_email_dictionary.txt");
		Scanner scanner = new Scanner(stream);
		int count = 0;
		int maxLength = 0;
		while (scanner.hasNext()) {
			String word = scanner.next();
			dic.add(word);
			words.add(word);
			if (word.length() > maxLength) {
				maxLength = word.length();
			}
		}
		System.out.println("load words count=" + dic.size());
		System.out.println("max length = " + maxLength);
		
		scanner.close();
		stream.close();
	}
	
	private void slove() throws IOException
	{
		int caseCount = scaner.nextInt();
		for (int caseNumber = 1; caseNumber <= caseCount; caseNumber++) {
			String s = scaner.next();
			results.clear();
			int result = scan(s, 0);
			System.out.printf("Case #%d: %d\n", caseNumber, result);
			writer.printf("Case #%d: %d\n", caseNumber, result);
		}
	}
	
	/**
	 * 
	 * @param s
	 * @param j: next change char index 
	 * @return
	 */
	private int scan(String s, int j)
	{
		if (s.equals("")) {
			return 0;
		}
		if (j < 0) {
			j = 0;
		}
		R r = new R();
		r.s = s;
		r.j = j;
		if (results.get(r) != null) {
			return results.get(r).intValue();
		}		
	
		int min = Integer.MAX_VALUE;
		for (String word: words) {
			Match match = compare(s, word, j);
			if (match != null) {
				//System.out.printf("match %s(%d) <-> %s = %d, %d\n", s, j, word, match.cost, match.j);
				int cost = scan(s.substring(word.length()), match.j - word.length());
				if (cost >= 0) {
					int v = match.cost + cost; 
					
					if (min > v) {
						min = v;
					}
				}
			}
		}
		if (min == Integer.MAX_VALUE) {
			results.put(r, -1);
			return -1;
		} else {
			results.put(r, min);
			//System.out.printf("put result %s(%d) = %d", s, j, min);
			return min;
		}
	}
	
	private Match compare(String s, String word, int j)
	{
		Match match = new Match();
		if (s.length() < word.length()) {
			return null;
		}
		match.cost = 0;
		match.j = j;
		for (int i = 0; i < word.length(); i++) {
			if (s.charAt(i) == word.charAt(i)) {
				continue;				
			} else {
				if (i >= match.j) {
					match.j = i + 5;				
					match.cost++;
				} else {
					return null;
				}
			}
		}
		return match;
	}

	private static class Match 
	{
		int cost;
		int j;
	}
	
	private static class R
	{
		String s;
		int j;
		@Override
		public int hashCode()
		{
			final int prime = 31;
			int result = 1;
			result = prime * result + j;
			result = prime * result + ((s == null) ? 0 : s.hashCode());
			return result;
		}
		@Override
		public boolean equals(Object obj)
		{
			if (this == obj)
				return true;
			if (obj == null)
				return false;
			if (getClass() != obj.getClass())
				return false;
			R other = (R) obj;
			if (j != other.j)
				return false;
			if (s == null) {
				if (other.s != null)
					return false;
			} else if (!s.equals(other.s))
				return false;
			return true;
		}
		
	}
}
