import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class KRush {
    enum Game {
        NEVER, ONE, TWO;
    }
    public static void main(String[] args) throws FileNotFoundException {
        Scanner scanner = new Scanner(new BufferedInputStream(new FileInputStream("B-small-attempt0.in")));
        PrintStream out = new PrintStream(new FileOutputStream("B-small.out"));
        int nTests = scanner.nextInt();
        for (int test = 1; test <=nTests; test++) {
            int n = scanner.nextInt();
            int []min1Star = new int[n];
            int []min2Star = new int[n];
            for (int f = 0; f< n; f++) {
                min1Star[f] = scanner.nextInt();
                min2Star[f] = scanner.nextInt();
            }
            Game[] games = new Game[n];
            Arrays.fill(games, Game.NEVER);
            int left = n;
            int played =0;
            int stars = 0;
            mainloop:
            while ( left > 0) {
                played ++;
                for (int f = 0 ; f< n ;f++) {

                    if (games[f] == Game.NEVER && stars>=min2Star[f]) {
                        stars += 2;
                        games[f] = Game.TWO;
                        left --;
                        continue mainloop;
                    }

                }
                for (int f = 0 ; f< n ;f++) {

                    if (games[f] == Game.ONE && stars>=min2Star[f]) {
                        stars += 1;
                        games[f] = Game.TWO;
                        left --;
                        continue mainloop;
                    }

                }
                for (int f = 0 ; f< n ;f++) {

                    if (games[f] == Game.NEVER && stars>=min1Star[f]) {
                        stars += 1;
                        games[f] = Game.ONE;
                        continue mainloop;
                    }
                }
                break;
            }
            if (left>0) {
                out.printf("Case #%d: Too Bad\n", test);
            } else {
                out.printf("Case #%d: %d\n", test, played);
            }
        }
        out.close();
    }

/*
    int binary_search(int A[], int key, int imin, int imax)
    {
        // continue searching while [imin,imax] is not empty
        while (imax >= imin)
        {
            */
/* calculate the midpoint for roughly equal partition *//*

            int imid = (imin + imax) / 2;

            // determine which subarray to search
            if      (A[imid] <  key)
                // change min index to search upper subarray
                imin = imid + 1;
            else if (A[imid] > key )
                // change max index to search lower subarray
                imax = imid - 1;
            else
                // key found at index imid
                return imid;
        }
        // key not found
        return -99999999;
    }
*/
}
