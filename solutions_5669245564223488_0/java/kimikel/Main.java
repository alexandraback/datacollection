import java.io.*;
import java.util.*;

public class Main {
    
    public static void main(String args[]) throws FileNotFoundException {
        
        final Scanner in = new Scanner(new File("/home/mikel/Desktop/codejam/Round1C/input.txt"));
        final PrintWriter out = new PrintWriter(new File("/home/mikel/Desktop/codejam/Round1C/output.txt"));
        
        final int t = in.nextInt(); in.nextLine();
        for (int it = 1; it <= t; it++) {
            
            final int n = in.nextInt(); in.nextLine();
            //final String s[] = new String[n];
            List<String> available = new ArrayList<>();
            for (int i = 0; i < n; i++) available.add(in.next());//s[i] = in.next();
            in.nextLine();
            
            System.err.println("Case #" + it + "...");
            
            out.println("Case #" + it + ": " + solve("", available));
            
        }
        
        out.close();
    }
    
    private static boolean check(String s) {
        final Set<Character> usedChars = new HashSet<>();
        Character lastCharacter = null;
        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (lastCharacter != null && c != lastCharacter && usedChars.contains(c)) return false;
            lastCharacter = c;
            usedChars.add(c);
        }
        return true;
    }
    
    private static int solve(String used, List<String> available) {
        if (available.isEmpty()) return check(used) ? 1 : 0;
        int result = 0;
        for (String s : available) {
            List<String> nextAvailable = new ArrayList<>(available);
            nextAvailable.remove(s);
            result += solve(used+s, nextAvailable);
        }
        return result;
    }
    
}