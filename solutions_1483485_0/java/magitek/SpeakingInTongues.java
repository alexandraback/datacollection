import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.Arrays;

public class SpeakingInTongues {

    public static char[] map = new char[26];

    public static void init() {
        String[] googlerese = 
                {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
                 "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
                 "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
        String[] english =
                {"our language is impossible to understand",
                 "there are twenty six factorial possibilities",
                 "so it is okay if you want to just give up"};
         
        for (int i = 0; i < map.length; i++)
            map[i] = (char) ('a' + i);
        System.out.println(Arrays.toString(map));
        
        Arrays.fill(map, ' ');
        for (int i = 0; i < english.length; i++)
            for (int j = 0; j < english[i].length(); j++)
                if (googlerese[i].charAt(j) != ' ')
                    map[ googlerese[i].charAt(j) - 'a' ] = english[i].charAt(j);
        System.out.println(Arrays.toString(map));
         
        // add missing letters
        map['q' - 'a'] = 'z';
        map['z' - 'a'] = 'q';
        System.out.println(Arrays.toString(map));
    }

    public static String goo2eng(String g) {
        String e = "";
        for (int i = 0; i < g.length(); i++) {
            if (g.charAt(i) == ' ')
                e += " ";
            else
                e += map[g.charAt(i) - 'a'];
        }
        return e;
    }

    public static void solve(String file) throws Exception {
        
        init();
        
        BufferedReader f = new BufferedReader(new FileReader(file + ".in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter(file + ".out")));

        int T = Integer.parseInt(f.readLine());
        for (int i = 0; i < T; i++) {
            String g = f.readLine();
            System.out.println("Case #" + (i+1) +": " + goo2eng(g));
            out.println("Case #" + (i+1) +": " + goo2eng(g));
        }
        out.close();
    }
    
    public static void main(String[] args) throws Exception {
        
        //String file = "A-test";
        String file = "A-small-attempt0";
        
        solve(file);
    }
}
