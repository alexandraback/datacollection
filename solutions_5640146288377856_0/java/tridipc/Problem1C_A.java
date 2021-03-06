import java.io.*;

/**
 * Created by Tridip on 10-05-2015.
 */
public class Problem1C_A {

    public static void main(String args[]) throws IOException {

        BufferedReader br = new BufferedReader(new FileReader("A-small-attempt1.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("A-small-output1.txt"));

        int testCases = Integer.parseInt(br.readLine());

        for (int t = 1; t <= testCases; t++) {

            String input = br.readLine();
            String arr[] = input.split(" ");
            int r = Integer.parseInt(arr[0]);
            int c = Integer.parseInt(arr[1]);
            int w = Integer.parseInt(arr[2]);

            int count = 0;

            if (w == 1)
                count = c;
            else if ( w ==c )
                count = w;
            else if (c%w == 0)
                count = (c/w) + (w-1);
            else {
                count = (c/w) + (w-1) + 1;
            }

            bw.write("Case #" + t +": "+count+"\r\n");
        }
        bw.close();
        br.close();
    }
}