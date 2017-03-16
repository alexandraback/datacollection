import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.Arrays;
import java.util.Scanner;


public class GCJCB {
	private static Scanner sc;
    private static PrintWriter out;
    private static String[] ar;

    public static void main(String[] args) {

        try {
            //sc = new Scanner( new File("/Users/sgururaj/Downloads/B-large.in"));
            //sc = new Scanner( new File("/Users/sgururaj/Downloads/test.in"));

            sc = new Scanner( new File("/Users/sgururaj/Downloads/B-small-attempt0.in"));
            out = new PrintWriter("/Users/sgururaj/Downloads/op-large.txt", "UTF-8");
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        int C = sc.nextInt();
        sc.nextLine();
        //l(C);
        for(int test=1; test<=C; test++) {
            count = 0;
            int N = Integer.parseInt(sc.nextLine());
            ar = sc.nextLine().split(" ");
            //l(N, ar);
            gen(new int[N], new boolean[N], 0, N);

            String pr = ("Case #"+test+": "+count);
            out.println(pr);
            System.out.println(pr);

        }
        out.close();

    }

    private static void gen(int[] per, boolean[] used, int now, int N) {
        if(now==N) process(per);
        for(int i=0; i<used.length; i++) {
            if(!used[i]) {
                per[now] = i;
                used[i] = true;
                gen(per, used, now+1, N);
                used[i] = false;
            }
        }
    }

    private static void process(int[] per) {
        int now = 0;
        boolean []seen = new boolean[27];
        char last = 'a'-1;
        boolean ok = true;
        for(int i=0; i<per.length; i++) {
            for(int j=0; j<ar[per[i]].length(); j++) {
                char c = ar[per[i]].charAt(j);
                if(seen[c-'a']&&c==last) {
                    last = c;
                    continue;
                }
                if(!seen[c-'a']) {
                    seen[c-'a'] = true;
                    last = c;
                    continue;
                }
                ok = false;
                break;
            }
        }
        if(ok) count++;
    }
    static int count = 0;

    public static void l(Object ...o) {
        String s = "";
        for(Object oo : o) {
            if(oo instanceof int[]) {
                s+=Arrays.toString((int[])oo)+" ";
                continue;
            }
            if(oo instanceof double[]) {
                s+=Arrays.toString((double[])oo)+" ";
                continue;
            }
            if(oo instanceof boolean[]) {
                s+=Arrays.toString((boolean[])oo)+" ";
                continue;
            }
            if(oo instanceof char[]) {
                s+=Arrays.toString((char[])oo)+" ";
                continue;
            }
            if(oo instanceof long[]) {
                s+=Arrays.toString((long[])oo)+" ";
                continue;
            }
            if(oo instanceof String[]) {
                s+=Arrays.toString((String[])oo)+" ";
                continue;
            }
            if(oo instanceof Object[]) {
                s+=Arrays.deepToString((Object[])oo)+" ";
                continue;
            }
            s += (oo.toString())+" ";
        }
        System.out.println(s);
    }
}
