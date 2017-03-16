import java.util.Arrays;
import java.util.Scanner;


public class Q3 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        for (int i = 0; i < num; i++) {
            int b = in.nextInt();
            int t = in.nextInt();
            
            long[] boxes = new long[2*b];
            for (int j = 0; j < 2*b; j++) {
                boxes[j] = in.nextLong();
            }
            
            long[] toys = new long[2*t];
            for (int j = 0; j < 2*t; j++) {
                toys[j] = in.nextLong();
            }
            
            System.out.println("Case #" + (i + 1) +": " + solve(boxes, toys, -1, -1, 0, ""));
        }
    }

    private static long solve(long[] boxes, long[] toys, long box, long toy, long num, String trace) {
        if (box == -1)
            box = read(boxes);
        if (toy == -1)
            toy = read(toys);
        
        //System.out.println(trace);
        // end
        if (box == -2 || toy == -2) {
            return num;
        }
        
        if (box == toy) {
            // Continue
            long nBox = get(boxes);
            long nToy = get(toys);
            long cont = Math.min(nBox, nToy);
            if (cont < 0) {
                System.err.println("Error!");
            }
            return solve(th(boxes.clone(), cont), th(toys.clone(), cont), -1, -1, num + cont, trace + 'c');
        }
        else {
            long tBox = solve(th(boxes.clone(), -1), toys.clone(), -1, toy, num, trace + 'b');
            long tToy = solve(boxes.clone(), th(toys.clone(), -1), box, -1, num, trace + 't');
            
            return Math.max(tBox, tToy);
        }
    }
    
    // Throw away the current type
    private static long[] th(long[] arr, long n) {
        for (int i = 0; i < arr.length; i += 2) {
            if (arr[i] > 0) {
                if (n == -1)
                    arr[i] = 0;
                else
                    arr[i] -= n;
                break;
            }
        }
        //System.out.println(Arrays.toString(arr));
        return arr;
    }
    
    // Get amount of current type
    private static long get(long[] arr) {
        for (int i = 0; i < arr.length; i += 2) {
            if (arr[i] > 0) {
                return arr[i];
            }
        }
        return 0;
    }

    private static long read(long[] arr) {
        for (int i = 0; i < arr.length; i += 2) {
            if (arr[i] > 0) {
                return arr[i+1];
            }
        }
        return -2;
    }

}
