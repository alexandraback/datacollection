import java.io.IOException;

/**
 * Copyright - Arghya Sur
 * Created by sur on 9/4/16.
 */
public class QRA {
    static boolean SEEN[] = {false, false, false, false, false, false, false, false, false, false};

    private static void examineNumber(int n) {
        while(n > 0) {
            int r = n % 10;
            SEEN[r] = true;
            n = n/10;
        }
    }

    private static boolean allSeen() {
        for(int i = 0; i < 10; i++) {
            if(!SEEN[i]) {
                return false;
            }
        }
        return true;
    }

    public static void main(String[] args) throws IOException {

        java.io.BufferedReader r = new java.io.BufferedReader
                (new java.io.InputStreamReader (System.in));

        String line;
        int c = 0;
        int t = Integer.parseInt(r.readLine());


        while(t > 0) {
            for(int i = 0; i < 10; i++) {
                SEEN[i] = false;
            }

            line = r.readLine();
            int n = Integer.parseInt(line);

            String res = "";
            int m = 1;

            if(n == 0) {
                res = "INSOMNIA";
            } else {
                int k = n;
                while(!allSeen()) {
                    k = n * m;
                    examineNumber(k);
                    m++;
                }
                res = k + "";
            }

            System.out.println("Case #" + (c + 1) + ": " + res);
            t--;
            c++;
        }
    }
}
