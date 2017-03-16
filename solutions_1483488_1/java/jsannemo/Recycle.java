
import java.util.Scanner;
import java.util.Set;
import java.util.TreeSet;


/**
 *
 * @author juice
 */
public class Recycle {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int tc = 1; tc <=t; tc++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            int digs = String.valueOf(a).length();
            long cnt = 0;
            for (int i = a; i <= b; i++) {
                String s = String.valueOf(i);
                Set<Integer> added = new TreeSet<Integer>();
                for(int j = 0; j<digs; j++){
                    String ns = s.substring(j)+s.substring(0, j);
                    if(!ns.startsWith("0")){
                        int w = Integer.parseInt(ns);
                        if(a <= w && w < i && !added.contains(w)){
                            cnt++;
                            added.add(w);
                        }
                    }
                }

            }
            System.out.println("Case #"+tc+": "+cnt);
        }
    }
}
