import java.util.*;

/**
 * Created by Wenzhao on 4/15/16.
 */
public class A1 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = Integer.parseInt(sc.nextLine());
        //System.out.println(t);
        for (int i = 0; i < t; i++) {
            String current = sc.nextLine();
            //System.out.println(current);
            StringBuilder str = new StringBuilder();
            for (int index = 0; index < current.length(); index++) {
                if (str.length() == 0 || current.charAt(index) >= str.charAt(0)) {
                    str.insert(0, current.charAt(index));
                }
                else {
                    str.append(current.charAt(index));
                }
            }
            System.out.println("Case #" + (i + 1) + ": " + str.toString());
        }
    }
}
