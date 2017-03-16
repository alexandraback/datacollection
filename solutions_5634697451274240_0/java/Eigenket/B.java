import static java.lang.Double.parseDouble;
import static java.lang.Integer.parseInt;
import static java.lang.Long.parseLong;
import static java.lang.System.exit;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.StringTokenizer;

public class B {
    static BufferedReader in;
    static StringTokenizer tok;
    static int test;
    static String line = "";
    
    
    static void solve() throws Exception {
		String thing = next();
		char last =thing.charAt(0);
		int count = 0;
		for(int i = 1;i < thing.length() ; i++){
			if(thing.charAt(i) != last){
				last = thing.charAt(i);
				count ++;
			}
		}
		if(thing.charAt(thing.length()-1) == '-'){
			count++;
		}
		System.out.println(count);
    }
    

    
    static void printCase() {
        System.out.print("Case #" + test + ": ");
    }
    
    static void printlnCase() {
        System.out.println("Case #" + test + ":");
    }
    
    static int nextInt() throws IOException {
        return parseInt(next());
    }

    static long nextLong() throws IOException {
        return parseLong(next());
    }

    static double nextDouble() throws IOException {
        return parseDouble(next());
    }
    
    static char nextChar() throws IOException {
        if(line.length() == 0){
            line = next();
        }
        char out = line.charAt(0);
        line = line.substring(1,line.length());
        return out;
    }
    static String next() throws IOException {
        while (tok == null || !tok.hasMoreTokens()) {
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }

    public static void main(String[] args) {
        try {
            in = new BufferedReader(new InputStreamReader(System.in));
            //in = new BufferedReader(new FileReader(new File("test")));
            int count = nextInt();
            for(test = 1 ; test<=count ; test++){
                printCase();
                solve();
            }
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}