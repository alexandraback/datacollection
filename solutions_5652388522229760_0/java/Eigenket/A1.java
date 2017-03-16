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

public class A1 {
    static BufferedReader in;
    static StringTokenizer tok;
    static int test;
    static String line = "";
    
    
    static void solve() throws Exception {
		long number = nextInt();
		if(number == 0){
			System.out.println("INSOMNIA");
			return;
		}
		
		boolean arr[] = new boolean[10];
		long current = number;
		while(true){
			long temp = current;
			while(temp>0){
				arr[(int)temp%10] = true;
				temp = temp/10;
			}
			boolean pass = true;
			for(boolean t : arr){
				if(t == false){
					pass = false;
				}
			}
			if(pass){
				System.out.println(current);
				return;
			}
			current += number;
		}
		
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