import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;


public class A {
    
    public static void main(String[] args) {
        try {
            Scanner in = new Scanner(new File("consonants.txt"));
            int num = in.nextInt();
            Set<Character> set = new HashSet<Character>();
            set.add('a');
            set.add('e');
            set.add('i');
            set.add('o');
            set.add('u');
            for(int z = 1; z <= num; z++) {
                String s = in.next();
                int n = in.nextInt();
                
                int cnt = 0;
                for(int i = 0; i < s.length(); i++) {
                    for(int j = i; j < s.length(); j++) {
                        int max = 0;
                        int tmp = 0;
                        for(int k = i ; k <= j; k++) {
                            if(set.contains(s.charAt(k))) {
                                tmp = 0;
                            } else {
                                tmp ++;
                                if(tmp > max) {
                                    max = tmp;
                                }
                            }
                        }
                        if(max >= n) {
                            cnt ++;
                        }
                    }
                }
                
                System.out.println(String.format("Case #%d: %d", z,cnt));
                
                
            }
        } catch (FileNotFoundException e) {
            // TODO Auto-generated catch block
            e.printStackTrace();
        }
    }
}
