
import java.io.*;
import java.util.*;

public class ProblemA
{
	private static final char[] map = new char[128];
	
	public static void main(String[] args)
	{
		map['a'] = 'y';
		map['b'] = 'h';
		map['c'] = 'e';
		map['d'] = 's';
		map['e'] = 'o';
		map['f'] = 'c';
		map['g'] = 'v';
		map['h'] = 'x';
		map['i'] = 'd';
		map['j'] = 'u';
		map['k'] = 'i';
		map['l'] = 'g';
		map['m'] = 'l';
		map['n'] = 'b';
		map['o'] = 'k';
		map['p'] = 'r';
		map['q'] = 'z';
		map['r'] = 't';
		map['s'] = 'n';
		map['t'] = 'w';
		map['u'] = 'j';
		map['v'] = 'p';
		map['w'] = 'f';
		map['x'] = 'm';
		map['y'] = 'a';
		map['z'] = 'q';
		map[' '] = ' ';
		
		//try { System.setIn(new FileInputStream("A-small-attempt2.in")); } catch (Exception e) { }
		
		Scanner sc = new Scanner(System.in);
		int N = Integer.parseInt(sc.nextLine());
		for (int i = 1; i <= N; i++)
		{
			char[] cs = sc.nextLine().toCharArray();
			for (int k = 0; k < cs.length; k++)
			{
				cs[k] = map[cs[k]];
			}
			System.out.printf("Case #%d: %s\n", i, new String(cs));
		}
	}
}
/*
3
ejp mysljylc kd kxveddknmc re jsicpdrysi
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd
de kr kd eoya kw aej tysr re ujdr lkgc jv
*/
