import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.Scanner;

public class Ex2 {
    private static String input = "B-small-attempt2.in";
    private static String output = "out.txt";
    private PrintWriter out;
    private int index = 1;

    public int execute(int N, int M) {
        System.out.println("Rozwiazuje dla M="+M);
        int[][] dist = new int[N][N];
        int[] ins = new int[N];

        if (M > (1<<N-2)) {
            out.println("IMPOSSIBLE");
            return 0;
        }

        int k = 2;
        while (M >= (1<<k-2)) k++;
        int total = 1<<k-3;
        k -= 2;
        for (int i=0; i<k; i++) {
            dist[i][N-1] = 1;
            for (int j=0; j<i; j++) {
                dist[j][i] = 1;
            }
        }

        ins[0] = 1;
        for (int i=1; i<k; i++) ins[i] = 1<<i-1;

        System.out.println(total);
        int last = k;
        for (int curr=k-1; curr>=0 && total<M; curr--) {
            if (total + ins[curr] <= M ) {
                dist[curr][last] = 1;
                total += ins[curr];
                dist[last][N-1] = 1;
            }
        }

        out.println("POSSIBLE");
        for (int i=0; i<N; i++) {
            for (int j=0; j<N; j++) out.print(dist[i][j]);
            out.println();
        }

        index++;
        return 1;
    }


    public void runTests(Scanner input) throws FileNotFoundException {
        out = new PrintWriter(output);
        int testsNo = Integer.valueOf(input.nextLine());

        for (int i=1; i<=testsNo; i++) {
            String[] someData = input.nextLine().split(" ");
            out.print("Case #"+i+": ");
            execute(Integer.valueOf(someData[0]), Integer.valueOf(someData[1]));
        }
        out.close();
    }


    public static void main(String[] args) throws FileNotFoundException {
        Scanner file = new Scanner(new FileInputStream(input));
        new Ex2().runTests(file);
        file.close();
    }
}
