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
    final String problemname = "B";
    final static String _localArg="ageshpaniecz";
    final static byte IO=3;
        /* IO:
         * 1 - standard I/O
         * 2 - input.txt/output.txt
         * 3 - problemname.in/problemname.out
         */

    String s1,s2;

    boolean greater(String st1,String st2){
        for (int i = 0; i < st1.length(); i++) {
            if (st1.charAt(i) == st2.charAt(i))
                continue;
            if (st1.charAt(i)=='?')
                return false;
            if (st2.charAt(i)=='?')
                return true;
            if (st1.charAt(i)>st2.charAt(i))
                return true;
            else
                return false;
        }
        return true;
    }

    StringBuilder str1,str2;
    boolean minimizeFirst = false;

    boolean rec(int ind,boolean needTorec){
        if (ind >= s1.length() && needTorec)
            return false;
        if (ind >= s1.length() && !needTorec)
            return true;
        if (s1.charAt(ind) == '?' || s2.charAt(ind)=='?'){
            if (s1.charAt(ind) != '?'){
                if (needTorec){
                    if (rec(ind + 1, true)) {
                        str2.setCharAt(ind,'9');
                        return true;
                    }
                    else {
                        if (s1.charAt(ind) != '9') {
                            str2.setCharAt(ind, '9');
                            return rec(ind+1,false);
                        }
                        else{
                            return false;
                        }
                    }
                }
                else{
                    str2.setCharAt(ind,s1.charAt(ind));
                    return rec(ind+1,false);
                }
            }
            else if (s2.charAt(ind)!='?'){
                if (needTorec) {
                    if (rec(ind + 1, true)) {
                        str1.setCharAt(ind, s2.charAt(ind));
                        return true;
                    } else {
                        if (s2.charAt(ind) != '0') {
                            str1.setCharAt(ind, (char) (s2.charAt(ind) - 1));
                            rec(ind+1,false);
                            return true;
                        } else {
                            return false;
                        }
                    }
                } else {
                    str1.setCharAt(ind, s2.charAt(ind));
                    return rec(ind + 1, false);
                }
            }
            else{
                if (needTorec){
                    if (rec(ind+1,true)){
                        str1.setCharAt(ind,'0');
                        str2.setCharAt(ind,'9');
                        return true;
                    }
                    else{
                        str1.setCharAt(ind,'0');
                        str2.setCharAt(ind,'9');
                        return rec(ind+1,false);
                    }
                }
                else{
                    str1.setCharAt(ind,'0');
                    str2.setCharAt(ind,'0');
                    return rec(ind+1,false);
                }

            }
        }
        else{
            if (needTorec)
            {
                if (s1.charAt(ind)>=s2.charAt(ind)){
                    return false;
                }
                else {
                    return rec(ind + 1, false);
                }
            }
            else{
                if (s1.charAt(ind) > s2.charAt(ind)){
                    if (rec(ind+1,true)){
                        return true;
                    }
                }
                else
                    if (s1.charAt(ind) == s2.charAt(ind))
                        return rec(ind+1,false);
                    else{
                        return rec(ind+1,true);
                    }
            }
        }
        return true;
    }

    public void solveCase(int Case) throws Exception{
        out.print("Case #"+Case+": ");
        s1 = next();
        s2 = next();
        boolean ret = false;
        if (greater(s2,s1)){
            String t = s1;
            s1 = s2;
            s2 = t;
            ret = true;
        }
        str1 = new StringBuilder(s1);
        str2 = new StringBuilder(s2);
        int index = 0;
        while (index<s1.length()&&s1.charAt(index) == s2.charAt(index) && s1.charAt(index) == '?'){
            str1.setCharAt(index,'0');
            str2.setCharAt(index,'0');
            index++;
        }
        if (index<s1.length())
            rec(index,false);
        if (ret){
            out.print(str2.toString()+" "+str1.toString());
        }
        else{
            out.print(str1.toString()+" "+str2.toString());
        }
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