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

public class C {
    static BufferedReader in;
    static StringTokenizer tok;
    static int test;
    static String line = "";
    
    
    static void solve() throws Exception {
		int length = nextInt();
		int number = nextInt();
		Long min;
		String count;
		Long out = 0l;
		Long arr[] = new Long[11];
		
		min = (long)(Math.pow(2,length-1)+1);
		count = min.toString(min,2);
		while(true){
			int j;
			for(j = 2 ; j<=10; j++){
				long curr = Long.parseLong(count,j);
				long k;
				for(k = 2 ;k<(long)Math.pow(curr,0.5) ;k++){
					if(curr%k ==0){
						arr[j] = k;
						break;
					}
				}
				if(k == (long)Math.pow(curr,0.5)){
					break;
				}
			}
			if(j == 11){
				System.out.print(count);
				if(count.length()==8){
					System.out.print(count);
				}

				for(int l = 2 ;l<11 ; l++){
					System.out.print(" " + arr[l]);
				}
				out++;
				if (out == number){
					return;
				}
				System.out.println();
			}
			do{
				min++;
				count = min.toString(min,2);
				if(count.length()%2 ==1){
					min = (long)(Math.pow(min,2)/2);
					count = min.toString(min,2);
				}
			}while(count.charAt(count.length()-1)=='0');
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
            int count = nextInt();
            for(test = 1 ; test<=count ; test++){
                printlnCase();
                solve();
            }
            in.close();
        } catch (Throwable e) {
            e.printStackTrace();
            exit(1);
        }
    }
}