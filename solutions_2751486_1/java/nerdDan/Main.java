import java.util.*;

public class Main {
    private static boolean isVowel(char x) {
        return x=='a' || x=='o' || x=='e' || x=='i' || x=='u';
    }
    public static void main(String[] args) {
        Scanner cin = new Scanner(System.in);
        int nCase = cin.nextInt();
        for(int iCase = 1; iCase<=nCase; iCase++) {
            String s = cin.next();
            int n = cin.nextInt(), b = -1, e = -1, c = 0;
            long ans = 0;
            for(int i = 0; i<s.length(); i++) {
                if(!isVowel(s.charAt(i))) {
                    c++;
                    if(c>=n) {
                        b = i-n+1;
                        e = i;
                    }
                }
                else {
                    c = 0;
                }
                if(c>=n) {
                    //System.out.print(" "+(i-n+2));
                    ans += i-n+2;
                }
                else {
                    //System.out.print(" "+(b+1));
                    ans += b+1;
                }
            }
            //System.out.println("\n"+s);
            System.out.printf("Case #%d: %d\n", iCase, ans);
        }
    }
}
