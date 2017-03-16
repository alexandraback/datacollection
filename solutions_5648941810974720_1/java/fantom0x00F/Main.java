import java.io.*;
import java.util.*;

public class Main {
    /**
     * author geshpaniec
     * 23.10.2014
     */

    StringTokenizer in;
    BufferedReader inb;
    PrintWriter out;
    static boolean local;
    final String problemname = "A";
    final static String _localArg="ageshpaniecz";
    final static byte IO=3;
        /* IO:
         * 1 - standard I/O
         * 2 - input.txt/output.txt
         * 3 - problemname.in/problemname.out
         */

    public void solveCase(int Case) throws Exception{
        out.print("Case #"+Case+": ");
        String s = next();
        int[] words = new int[26];
        for (int i = 0; i < s.length(); i++) {
            words[s.charAt(i)-'A']++;
        }
        List<Character> res = new ArrayList<>();
        while(words['Z'-'A']>0){
            res.add('0');
            words['Z'-'A']--;
            words['E'-'A']--;
            words['R'-'A']--;
            words['O'-'A']--;
        }
        while(words['G'-'A']>0){
            res.add('8');
            words['E'-'A']--;
            words['I'-'A']--;
            words['G'-'A']--;
            words['H'-'A']--;
            words['T'-'A']--;
        }
        while(words['X'-'A']>0){
            res.add('6');
            words['S'-'A']--;
            words['I'-'A']--;
            words['X'-'A']--;
        }
        while(words['S'-'A']>0){
            res.add('7');
            words['S'-'A']--;
            words['E'-'A']--;
            words['V'-'A']--;
            words['E'-'A']--;
            words['N'-'A']--;
        }
        while(words['W'-'A']>0){
            res.add('2');
            words['T'-'A']--;
            words['W'-'A']--;
            words['O'-'A']--;
        }
        while(words['H'-'A']>0){
            res.add('3');
            words['T'-'A']--;
            words['H'-'A']--;
            words['R'-'A']--;
            words['E'-'A']--;
            words['E'-'A']--;
        }
        while(words['R'-'A']>0){
            res.add('4');
            words['F'-'A']--;
            words['O'-'A']--;
            words['U'-'A']--;
            words['R'-'A']--;
        }
        while(words['F'-'A']>0){
            res.add('5');
            words['F'-'A']--;
            words['I'-'A']--;
            words['V'-'A']--;
            words['E'-'A']--;
        }
        while(words['O'-'A']>0){
            res.add('1');
            words['O'-'A']--;
            words['N'-'A']--;
            words['E'-'A']--;
        }
        while(words['N'-'A']>0){
            res.add('9');
            words['N'-'A']--;
            words['I'-'A']--;
            words['N'-'A']--;
            words['E'-'A']--;
        }
        Collections.sort(res);
        for (char r:res)
            out.print(r);
        out.println();
    }


    public void solve() throws Exception {
        int T = nextInt();
        for (int q = 1; q <= T; q++) {
            solveCase(q);
        }
//        System.out.println((long)Math.pow(29,11));
//        long L = 12200509765705828L;
//        L/=29L;
//        System.out.println(L);
    }

    public static void main(String[] args) throws Exception {
        local = false;
        if (args.length == 1 && args[0].equals(_localArg))
            local = true;
        new Main().run();

    }

    public void run() throws Exception {
        if (local) {
            inb = new BufferedReader(new FileReader("input.txt"));
            out = new PrintWriter(new OutputStreamWriter(System.out));
        } else {
            switch (IO){
                case 1:
                    inb = new BufferedReader(new InputStreamReader(System.in));
                    out = new PrintWriter(new OutputStreamWriter(System.out));
                    break;
                case 2:
                    inb = new BufferedReader(new FileReader("input.txt"));
                    out = new PrintWriter(new FileWriter("output.txt"));
                    break;
                case 3:
                    inb = new BufferedReader(new FileReader(problemname+".in"));
                    out = new PrintWriter(new FileWriter(problemname+".out"));
                    break;
            }
        }
        in = new StringTokenizer("");
        double Time=System.nanoTime();
        solve();
        if (local){
            Time=System.nanoTime()-Time;
            out.println();
            out.println(" Time work: "+Time/(1e9)+" seconds");
        }
        out.flush();
    }

    int nextInt() throws Exception {
        return Integer.parseInt(next());
    }

    long nextLong() throws Exception{
        return Long.parseLong(next());
    }

    double nextDouble() throws Exception {
        return Double.parseDouble(next());
    }

    String next() throws Exception {
        if (!in.hasMoreTokens())
            in=new StringTokenizer(inb.readLine());
        return in.nextToken();
    }

    int[] nextArray(int n) throws Exception{
        int[] a=new int[n];
        for (int i=0;i<n;i++)
            a[i]=nextInt();
        return a;
    }

    long[] nextLArray(int n) throws Exception{
        long[] a=new long[n];
        for (int i=0;i<n;i++)
            a[i]=nextLong();
        return a;
    }

    double[] nextDArray(int n) throws Exception{
        double[] a=new double[n];
        for (int i=0;i<n;i++)
            a[i]=nextDouble();
        return a;
    }

    String[] nextSArray(int n) throws Exception{
        String[] a=new String[n];
        for (int i=0;i<n;i++)
            a[i]=next();
        return a;
    }


}