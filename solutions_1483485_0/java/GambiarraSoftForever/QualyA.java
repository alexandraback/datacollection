package google2012.qualy;

import google.Arquivo;

import java.io.*;
import java.text.DecimalFormat;
import java.text.DecimalFormatSymbols;
import java.util.*;

public class QualyA {
	public static void main(String[] args) throws Exception {
		Hashtable<Character, Character> h = new Hashtable<Character, Character>();
		Vector<String> in = new Vector<String>(3);
		in.add("ejp mysljylc kd kxveddknmc re jsicpdrysi");
		in.add("rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd");
		in.add("de kr kd eoya kw aej tysr re ujdr lkgc jv");
		Vector<String> out = new Vector<String>(3);
		out.add("our language is impossible to understand");
		out.add("there are twenty six factorial possibilities");
		out.add("so it is okay if you want to just give up");
		for (int i = 0; i < in.size(); i++) {
			char[] entr = in.elementAt(i).toCharArray();
			char[] sai = out.elementAt(i).toCharArray();
			for (int j = 0; j < entr.length; j++) {
				char ci = entr[j];
				char co = sai[j];
				h.put(ci, co);
			}
		}
		h.put('z', 'q');
		h.put('q', 'z');
		/*List<Character> list = Collections.list(h.keys());
		Collections.sort(list);
		Vector<String> sort = new Vector<String>(30);
		for (Character c : list) {
			System.out.println(h.get(c)+ " " +c);
		}*/
		/*Collections.sort(sort);
		for (String string : sort) {
			System.out.println(string);
		}*/
		Scanner sc = new Scanner(new File("2012/qualy/a/A-small-attempt0.in"));
		int N = sc.nextInt();
		sc.nextLine();
		StringBuffer resposta = new StringBuffer();
		for (int i = 0; i < N; i++) {
			char[] str = sc.nextLine().toCharArray();
			char[] str2 = str;
			for (int j = 0; j < str.length; j++) {
				char c = str[j];
				str2[j] = h.get(c);
			}
			String o = "Case #"+(i+1)+": ";
			System.out.println(str2);
			resposta.append(o);
			resposta.append(str2);
			resposta.append("\n");
		}
		Arquivo.escrever(resposta.toString(), "2012/qualy/a/A-small-attempt0.out");
		System.exit(0);
	}

	/*double a = 0.3463635654567474746;
	DecimalFormat df = new DecimalFormat("0.0000000", new DecimalFormatSymbols(Locale.US));
	System.out.println(df.format(a));*/
}
