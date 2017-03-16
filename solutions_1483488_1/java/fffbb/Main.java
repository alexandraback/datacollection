import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;


public class Main {

    /**
     * @param args
     */
    public static void main(String[] args) throws Exception {
        if(args.length != 1) {
            return;
        }
        FileInputStream inputStream = new FileInputStream(args[0]);
        InputStreamReader istReader = new InputStreamReader(inputStream);
        BufferedReader buffReader = new BufferedReader(istReader);

        // T:問題数
        String tStr = buffReader.readLine();
        int t = Integer.valueOf(tStr);

        for(int i = 1; i <= t; i++) {
            StringBuilder caseBuilder = new StringBuilder("Case #");
            caseBuilder.append(i);
            caseBuilder.append(": ");

            // A and B:問題
            String abStr = buffReader.readLine();
            String[] aandbStrs = abStr.split(" ");
            int a = Integer.valueOf(aandbStrs[0]);
            int b = Integer.valueOf(aandbStrs[1]);

            int y = 0;
            for(int n = a; n < b; n++) {
                String nStr = String.valueOf(n);

                int[] ms = new int[nStr.length() - 1];
                for(int k = 1; k < nStr.length(); k++) {
                    String mStr = nStr.substring(nStr.length() - k).concat(nStr.substring(0, nStr.length() - k));

                    int m = Integer.valueOf(mStr);
                    if(m <= a || b < m || m <= n)
                        continue;

                    boolean already = false;
                    for(int j = 0; j < nStr.length() - 1; j++) {
                        if(m == ms[j]) {
                            already = true;
                            break;
                        }
                    }
                    if(!already) {
                        y++;
                        ms[k - 1] = m;
                    }
                }
            }

            caseBuilder.append(y);

            System.out.print(caseBuilder.toString());
            if(i != t)
                System.out.println();
        }
    }

}
