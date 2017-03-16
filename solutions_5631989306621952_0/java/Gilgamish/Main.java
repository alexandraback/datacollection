import java.util.*;

class Main {

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int t = scanner.nextInt();
        for (int i = 1; i <= t; i++) {
            String s = scanner.next();
            char[] c =s.toCharArray();
            String winnerString = "" + c[0];
            int l = 1;
            while(l<c.length) {
                if ((winnerString + c[l]).compareTo(c[l] + winnerString) >= 0) winnerString = winnerString + c[l];
                else winnerString = c[l] + winnerString;
                l++;
            }
            System.out.println("Case #" + i+ ": " + winnerString);
        }
    }

}

