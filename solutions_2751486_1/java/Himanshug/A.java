package gcj.r1c;

import java.io.BufferedOutputStream;
import java.io.File;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;

public class A {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        //String inPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\in.txt";
        
        String inPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\A-large.in";
        
        String outPath = "C:\\himanshu\\personal\\work\\ds-algo-lib\\gcj\\out.txt";
        
        Scanner scanner = new Scanner(new File(inPath));
        
        PrintWriter out = pw(outPath);
        //PrintWriter out = pw(null);

        A x = new A();
        
        int T = Integer.parseInt(scanner.nextLine().trim());
        
        for(int c = 1; c <= T; c++) {
            String[] tmp = scanner.nextLine().trim().split("\\s+");
            char[] s = tmp[0].toLowerCase().toCharArray();
            int n = Integer.parseInt(tmp[1]);
            out.println("Case #" + c + ": " + x.solve(s, n));
        }
        
        scanner.close();
        out.close();
    }


    public long solve(char[] s, int n) {
        long r = 0;
        int l = s.length;
        int last = -1;
        int start = 0;
        while(true) {
            //System.out.println("start = " + start);
            int x = find_cons(s,l,start,n);
            if(x >= l)
                break;
            long a = last >= 0 ? x - last - 1 : x;
            long b = l - x - n;
            r += (a+1)*(b+1);
            last = x;
            start = x+1;
        }
        return r;
    }

    private int find_cons(char[] s, int l, int start, int n) {
        for(int i = start; i <= l-n; i++) {
            boolean b = true;
            for(int j = 0; j < n; j++) {
                if(!isCons(s[i+j])) {
                    b = false;
                    break;
                }
            }
            if(b) return i;
        }
        return l;
    }

    private boolean isCons(char c) {
        return c != 'a' &&
                c != 'e' &&
                c != 'i' &&
                c != 'o' &&
                c != 'u';
    }
    
    private static PrintWriter pw(String file) throws Exception {
        if(file == null) {
            return new PrintWriter(System.out);
        } else {
            return new PrintWriter(new BufferedOutputStream(new FileOutputStream(file)));
        }
    }
}


