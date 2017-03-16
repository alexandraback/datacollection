import java.io.IOException;

/**
 * Copyright - Arghya Sur
 * Created by sur on 5/10/15.
 */
public class R1CC {
    public static void main(String[] args) throws IOException {

        java.io.BufferedReader r = new java.io.BufferedReader
                (new java.io.InputStreamReader (System.in));

        String line;
        int c = 0;
        int t = Integer.parseInt(r.readLine());

        while(t > 0) {
            line = r.readLine();
            String[] components = line.split(" ");

            int C = Integer.parseInt(components[0]);
            int D = Integer.parseInt(components[1]);
            int V = Integer.parseInt(components[2]);

            line = r.readLine();
            components = line.split(" ");

            int[] arr = new int[V];
            for(int i = 0; i < D; i++) {
                arr[i] = Integer.parseInt(components[i]);
            }

            int count = 0;
            int size = D;

            for(int i = 1; i <= V; i++) {
                if(!isSubsetSum(arr, size, i)) {
                    count++;
                    arr[size] = i;
                    size++;
                }
            }

            System.out.println("Case #" + (c + 1) + ": " + count);
            t--;
            c++;
        }
    }

    public static boolean isSubsetSum(int set[], int n, int sum)
    {
        // Base Cases
        if (sum == 0)
            return true;
        if (n == 0 && sum != 0)
            return false;

        // If last element is greater than sum, then ignore it
        if (set[n-1] > sum)
            return isSubsetSum(set, n-1, sum);

        return isSubsetSum(set, n-1, sum) || isSubsetSum(set, n-1, sum-set[n-1]);
    }
}
