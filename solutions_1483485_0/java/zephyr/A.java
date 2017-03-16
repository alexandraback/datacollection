import java.io.*;

public class A {
	public void run()
	{
		char[] gtoe = new char[26];
		String[] to = new String[3];
		String[] from = new String[3];
		to[0] = "ejp mysljylc kd kxveddknmc re jsicpdrysi";
		to[1] = "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd";
		to[2] = "de kr kd eoya kw aej tysr re ujdr lkgc jv";
		from[0] = "our language is impossible to understand";
		from[1] = "there are twenty six factorial possibilities";
		from[2] = "so it is okay if you want to just give up";

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < to[i].length(); j++) {
				char c = to[i].charAt(j);
				if (c == ' ')
					continue;
				gtoe[c-'a'] = from[i].charAt(j);
			}
		}
		gtoe['z'-'a'] = 'q';
		gtoe['q'-'a'] = 'z';

		/*
		for (int i = 0; i < 26; i++) {
			char t = (char)('a'+i);
			System.out.println(t + " -> " + gtoe[i]);
		}
		*/
		try {
			BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
			String buf = "";

			buf = in.readLine();
			int T = Integer.parseInt(buf);
			for (int t = 1; t <= T; t++) {
				buf = in.readLine();
				String rs = "";

				for (int i = 0; i < buf.length(); i++) {
					if (buf.charAt(i) == ' ')
						rs += ' ';
					else
						rs += gtoe[buf.charAt(i)-'a'];
				}

				System.out.println("Case #" + t + ": " + rs);

			}
		}
		catch (IOException e) {
		}
	}

	public static void main(String [] args) {
		new A().run();
	}
};
