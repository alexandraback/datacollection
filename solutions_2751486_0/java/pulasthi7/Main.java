import java.util.HashSet;
import java.util.Scanner;

/* pulasthi7@gmail.com */
public class Main {
    static Scanner sc;
    public static void main(String[] args) {
        sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        long stime = System.nanoTime();
        for (int i = 0; i < T; i++) {
            System.err.println("Solving case "+(i+1));
            System.out.print("Case #" + (i + 1) + ": ");
            solve();
        }
        System.err.println("Finished in "+((System.nanoTime()-stime)/1000000)+" ms");
    }

    static void solve(){
        String[] param = sc.nextLine().split(" ");
        String name = param[0];
        int n = Integer.parseInt(param[1]);
        int l = name.length();
        name = name.replaceAll("[^aeiou]","x");
        name = name.replaceAll("[^x]","i");
        char[] comp = new char[n];
        for (int i = 0; i < n; i++) {
            comp[i] = 'x';
        }
        String c = new String(comp);
        HashSet<String> strings = new HashSet<String>();
        for (int st = 0; st < l; st++) {
            for (int fi = st+1; fi <= l; fi++) {
                String v = name.substring(st,fi);
                if(v.contains(c)){
                    char[] t = name.toCharArray();
                    for (int i = 0; i < st; i++) {
                        t[i] = '0';
                    }
                    for (int i = fi; i < l; i++) {
                        t[i] = '0';
                    }
                    strings.add(new String(t));
                }
            }
        }
        System.out.println(strings.size());
    }
}
