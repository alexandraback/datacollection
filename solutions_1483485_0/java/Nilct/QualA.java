import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.Arrays;

/**
 * Apr 14, 2012 
 * @author parisel
 */
public class QualA {
    java.io.BufferedReader br;
    java.io.PrintWriter out;
    int N;
    String[] tok;

    String input=  "ejp mysljylc kd kxveddknmc re jsicpdrysi rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd de kr kd eoya kw aej tysr re ujdr lkgc jv";
    String output= "our language is impossible to understand there are twenty six factorial possibilities so it is okay if you want to just give up";

    char[] in2out;

    private void setAlphabet() {
        int i;
        in2out= new char['z'+1];
        for (i=0; i<input.length(); i++) in2out[input.charAt(i)]= output.charAt(i);
        in2out['q']= 'z';
        in2out['y']= 'a';
        in2out['e']= 'o';
        in2out['z']= 'q';
////      check what is missing from in
//        for (i='a'; i<='z'; i++)
//            if (in2out[i]==0) System.out.printf("[in] %s is missing\n", String.valueOf((char)i));
//        // check what is missing from out
//        String s= "";
//        for (i='a'; i<='z'; i++)
//            if (in2out[i]!=0) s+= String.valueOf(in2out[i]);
//        char[] cs= s.toCharArray(); Arrays.sort(cs);
//        s= String.valueOf(cs);
//
//        System.out.printf("[out] %s\n", s);
    }

    private String translate(String in) {
        char[] cout= new char[in.length()];
        for (int i=0; i<in.length(); i++) {
            if (in.charAt(i)==' ') cout[i]= ' ';
            else cout[i]= in2out[in.charAt(i)];
        }
        return String.valueOf(cout);
    }


    private String[] getTok() throws IOException {return br.readLine().split(" ");}
    private int getInt() throws IOException {return Integer.valueOf(br.readLine());}
    private int[] getInt(int N) throws IOException {
        int[] data= new int[N]; tok= br.readLine().split(" ");
        for (int i=0; i<N; i++) data[i]= Integer.valueOf(tok[i]);
        return data;
    }

    public void solve() throws IOException {
        int i,j,k;
        String s;

        br = new BufferedReader (new FileReader("A-small.in"));
        out = new PrintWriter(new BufferedWriter(new FileWriter("A-small.out")));

        setAlphabet();

        int C= Integer.valueOf(br.readLine());
        for (int c=1; c<=C; c++) {
            // read
            s= br.readLine();
            // output
            out.printf("Case #%d: %s\n", c, translate(s));
        }
        out.close(); 
    }

    public static void main(String[] args) throws IOException {
        new QualA().solve();
    }
}
