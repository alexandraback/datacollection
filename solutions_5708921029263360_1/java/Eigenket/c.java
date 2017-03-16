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
import java.util.ArrayList;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.HashSet;
public class c {
    static BufferedReader in;
    static StringTokenizer tok;
    static int test;
    static String line = "";


	
    static void solve() throws Exception {
		int one = nextInt();
		int two = nextInt();
		int three = nextInt();
		int m = nextInt();
		boolean happened;
		HashMap<Integer,Integer> map = new HashMap<Integer,Integer>();
		HashSet<Integer> set = new HashSet<Integer>();
		ArrayList<Integer> list = new ArrayList<Integer>();
		for(int i = 1 ; i<=one ; i++){
			int shift = 0;
			happened = true;
			while(happened){
				happened = false;
				for(int j = 1 ; j<=two ; j++){
					int k = j+shift+i-1;
					while(k>three){
						k = k - three;
					}
					Integer first = map.get(i*10000+j*100);
					Integer second = map.get(j*100+k);
					Integer third = map.get(i*10000+k);
					if((first!=null && first == m) || (second!=null && second == m) || (third!=null && third == m)){
						continue;
					}
					if(set.contains(i*10000+j*100+k)){
						continue;
					}
					list.add(i*10000+j*100+k);
					set.add(i*10000+j*100+k);
					if(first == null){
						map.put(i*10000+j*100,1);
					}else{
						map.put(i*10000+j*100,first+1);
					}
					if(second == null){
						map.put(j*100+k,1);
					}else{
						map.put(j*100+k,second+1);
					}
					if(third == null){
						map.put(i*10000+k,1);
					}else{
						map.put(i*10000+k,third+1);
					}
					happened = true;
				}
				shift++;
			}
		}
		System.out.println(list.size());
		for(int i = 0;i < list.size(); i++){
			int num = list.get(i);
			int ans1 = num/10000;
			if(ans1 == 0){
				ans1 = 10;
			}
			System.out.print(ans1 +" ");
			num = num %1000;
			ans1 = num/100;
						if(ans1 == 0){
				ans1 = 10;
			}
			System.out.print(ans1 +" ");
			num = num %10;
			ans1 = num;
						if(ans1 == 0){
				ans1 = 10;
			}
			System.out.println(ans1+" ");
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