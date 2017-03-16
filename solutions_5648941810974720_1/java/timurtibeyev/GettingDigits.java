import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 * Created by Timur on 30.04.2016.
 */
public class GettingDigits {
    public static void main(String args[]) throws IOException {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));

        int test = Integer.parseInt(in.readLine());
        for (int t=1;t<=test;t++) {
            String s = in.readLine();
            int a[] = new int[40];
            for (int i=0;i<s.length();i++) {
                int x = (s.charAt(i) - 'A');
                a[x]++;
            }

            int ans[] = new int [10];
            ans[0] +=a[25];
            a[4]-=a[25];
            a[17]-=a[25];
            a[14]-=a[25];
            a[25]-=a[25];

            ans[2] +=a[22];
            a[19]-=a[22];
            a[14]-=a[22];
            a[22]-=a[22];

            ans[4] +=a[20];

            a[14]-=a[20];
            a[5]-=a[20];
            a[17]-=a[20];
            a[20]-=a[20];

            ans[6] +=a[23];
            a[8]-=a[23];
            a[18]-=a[23];
            a[23]-=a[23];

            ans[8] +=a[6];
            a[4]-=a[6];
            a[8]-=a[6];
            a[7]-=a[6];
            a[19]-=a[6];
            a[6]-=a[6];

            ans[1] +=a[14];
            a[13]-=a[14];
            a[4]-=a[14];
            a[14]-=a[14];

            ans[3] +=a[17];
            a[19]-=a[17];
            a[7]-=a[17];
            a[4]-=a[17];
            a[4]-=a[17];
            a[17]-=a[17];

            ans[5] +=a[5];
            a[8]-=a[5];
            a[21]-=a[5];
            a[4]-=a[5];
            a[5]-=a[5];

            ans[7] +=a[18];
            a[13]-=a[18];

            ans[9] = a[13] / 2;
            System.out.print("Case #" + t + ": ");
            for (int i = 0; i<10;i++) {
                for (int j = 0; j < ans[i];j++) {
                    System.out.print(i);
                }
            }
            System.out.println();
        }

        in.close();
    }
}
