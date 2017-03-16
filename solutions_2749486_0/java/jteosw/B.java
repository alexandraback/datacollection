import java.util.*;

public class B{
    static Scanner s;
    public static void main(String[] args){
        s = new Scanner(System.in);
        int cases = s.nextInt();
        for(int i = 0; i < cases; i++) {
            String result = solve();
            System.out.printf("Case #%d: %s\n", i+1, result);
        }
    }

    public static String solve(){
        String result = "";
        int x = s.nextInt();
        int y = s.nextInt();
        if (x > 0 ) {
            for(int i = 0 ; i < x; i++) {
                result += "WE";
            } 
        } else {
            for(int i = 0; i > x; i--) {
                result += "EW";
            }
        }
        if (y > 0) {
            for(int i = 0; i < y; i++) {
                result += "SN";
            }
        } else {
            for(int i = 0; i > y; i--) {
                result += "NS";
            }
        }
        return result;
    }





}
