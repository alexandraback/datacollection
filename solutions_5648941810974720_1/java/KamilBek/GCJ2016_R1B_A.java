import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;
import java.util.stream.Stream;

/**
 * Created by Kamil Khadiev
 */
public class GCJ2016_R1B_A {
    public static void main(String[] args) throws IOException {
//        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
//        PrintWriter out = new PrintWriter(System.out);
        BufferedReader in = new BufferedReader(new FileReader("c:/inputs/input.txt"));
        PrintWriter out = new PrintWriter("c:/inputs/output.txt");
        t = Integer.parseInt(in.readLine().trim());

        for (int i = 0; i < t; i++) {
            System.out.println(i + 1);
            init(in);
            solve();

            print(out, i+1);
        }

            in.close();
            out.close();

    }
    public static int n,p,t;
    public static long[] x,y;
    static String s;
    public static StringBuilder ans;
    static HashMap<Character, Integer> d;

    private static void init(BufferedReader in) throws IOException {
        s = in.readLine().trim();
        d = new HashMap<>();
        for (int i = 0; i < s.length(); i++){
            int j = 0;
            if (d.get(s.charAt(i))== null){
                j = 0;
            }
            else{
                j = d.get(s.charAt(i));
            }
            j++;
            d.put(s.charAt(i),j);
        }
    }

    private static void solve() {
        String[] dig = new String[]{"ZERO","TWO", "SIX", "SEVEN", "FIVE",  "EIGHT", "THREE","NINE", "FOUR",  "ONE"   };
        Integer[] dig2 = new Integer[]{0, 2      ,   6,    7,        5,      8,    3,     9 , 4, 1};
        ans = new StringBuilder("");
        for (int i = 0; i <=9; i++){
            for (int j  =0; j<dig[i].length();j++){
                if (d.get(dig[i].charAt(j))==null)
                    d.put(dig[i].charAt(j), 0);
            }
        }
        int[]ansd = new int[10];
        for (int i =0;i<=9; i++){
            int k = d.get(dig[i].charAt(0));

            for (int j = 1; j < dig[i].length(); j++){
                if (dig2[i] == 3 && j >=3 || dig2[i] ==7 && j == 1|| dig2[i] ==9 && j == 0){
                    k = Math.min(k,d.get(dig[i].charAt(j))/2 );
                }
                else
                k = Math.min(k,d.get(dig[i].charAt(j)) );
            }
            ansd[dig2[i]] = k;
            for (int j = 0; j < dig[i].length(); j++){
                d.put(dig[i].charAt(j), d.get(dig[i].charAt(j))-k);
            }
        }
        for (Map.Entry<Character, Integer> e : d.entrySet()){
            if (e.getValue()>0){
                throw new RuntimeException("fsdfs");
            }
        }
        for (int i = 0; i <=9; i++){
            for (int j = 0; j < ansd[i]; j++)
                ans.append(i);
        }

    }





    private static void print(PrintWriter out, int cn) throws IOException {
        if (cn != 1) out.println();
        out.print("Case #"+cn+": "+ans.toString());
    }
}
