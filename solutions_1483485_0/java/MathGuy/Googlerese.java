import java.util.*;
import java.io.*;
public class Googlerese {
    static char[] mapping = {'y','h','e','s','o','c','v','x','d','u','i','g','l','b','k','r','z','t','n','w','j','p','f','m','a','q'};
    static char mapChar(char c) {
	if (c == ' ') return c;
	char r = mapping[c-'a'];
	return r == 0 ? c : r;
    }
    static String convert(String s) {
	String ret = "";
	for (int i = 0; i < s.length(); ++i) {
	    char c = s.charAt(i);
	    ret += mapChar(c);
	}
	return ret;
    }
    public static void main(String[] args) throws Exception {
	BufferedReader in = new BufferedReader(new FileReader(args[0]));
	String line = in.readLine();
	int N = Integer.parseInt(line);
	for (int i = 0; i < N; ++i) {
	    line = in.readLine();
	    System.out.println("Case #"+(i+1)+": "+convert(line));
	}
    }
}