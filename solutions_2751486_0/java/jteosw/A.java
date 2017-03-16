import java.util.*;

public class A{
    static Scanner s;
    static Set<Character> vowels;
    public static void main(String[] args){
        s = new Scanner(System.in);
        vowels = new HashSet<Character>();
        vowels.add('a');
        vowels.add('i');
        vowels.add('o');
        vowels.add('u');
        vowels.add('e');
        int cases = s.nextInt();
        for(int i = 0; i < cases; i++) {
            long result = solve();
            System.out.printf("Case #%d: %s\n", i+1, result);
        }
    }

    public static long solve() {
        String name = s.next();
        int num = s.nextInt();
        for(int i = 0; i < name.length(); i++) {
            if(!vowels.contains(name.charAt(i)) && name.charAt(i) != '1') {
                name = name.replace(name.charAt(i), '1');
            }
        }
        long result = 0;
        String key = "";
        for (int i = 0; i < num; i++) {
            key += "1";
        }
        while(name.indexOf(key) >= 0) {
            int pos = name.indexOf(key);
            result += (pos + 1) * (name.length() - num - pos + 1);
            name = name.substring(pos+1);
        }

        return result;
    }
}


