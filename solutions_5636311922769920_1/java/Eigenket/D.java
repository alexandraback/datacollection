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

public class D {
    static BufferedReader in;
    static StringTokenizer tok;
    static int test;
    static String line = "";
    
    
    static void solve() throws Exception {
		int length = nextInt();
		int complexity = nextInt();
		int checks = nextInt();
		if(complexity == 1 && checks<length){
			System.out.println(" IMPOSSIBLE");
			return;
		}
		if(checks<(length+1)/2){
			System.out.println(" IMPOSSIBLE");
			return;
		}
		
		if(complexity == 1){
			for(int i = 0 ;i<length ; i++){
				System.out.print(" " + (i+1));
			}
			System.out.println();
			return;
		}
		if(length == 1){
			System.out.println(" " +1);
			return;
		}
		int i;
		for(i = 0 ;i<length/2 ; i++){
			System.out.print(" " + (i*length*2 + (i+1)*2));
		}
		if(length %2 == 1){
			System.out.print(" " + (i*length*2 + (i+1)*2 - length-1));
		}
		System.out.println();
    }
    

    
    static void printCase() {
        System.out.print("Case #" + test + ":");
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