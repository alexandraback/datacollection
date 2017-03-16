
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Technobabble {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for (int i = 1; i <= t; i++) {
            int n = sc.nextInt();
            Set<String> s1 = new HashSet<>();
            Set<String> s2 = new HashSet<>();
            for (int j = 0; j < n; j++) {
                s1.add(sc.next());
                s2.add(sc.next());
            }
            System.out.println("Case #" + i + ": " + (n - Math.max(s1.size(), s2.size())));
        }
        
    }
    
}
