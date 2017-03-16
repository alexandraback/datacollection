import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * Created by arudenko on 03.05.14.
 */
public class C {
    public static void main(String[] args) throws FileNotFoundException {
        String fileName = "C-small-attempt0";
//        String fileName = "c";
        System.setIn(new FileInputStream(fileName + ".in"));
        System.setOut(new PrintStream(new FileOutputStream(fileName + ".out")));

        Scanner sc = new Scanner(System.in);

        int t = sc.nextInt();
        for(int ti = 0; ti < t;ti++) {
            int n = sc.nextInt();
            int m = sc.nextInt();
            sc.nextLine();
            String zips[] = new String[n];
            for(int i = 0; i < n;i++) {
                zips[i] = sc.nextLine();
            }
            boolean mp[][] = new boolean[n][n];
            for(int i = 0; i < m;i++) {
                int a = sc.nextInt() - 1;
                int b = sc.nextInt() - 1;
                mp[a][b] = mp[b][a] = true;
            }
            String result = solve(zips, mp);
            System.out.println("Case #"+(ti+1)+": " + result);
        }
    }

    private static String solve(String[] zips, boolean[][] mp) {
        Integer arr[] = new Integer[zips.length];
        String best = null;
        for(int i = 0; i < arr.length; i++) arr[i] = i;
        do {
            String join = join(arr, zips);
            if((best == null || best.compareTo(join) > 0) && test(mp, arr) ) {
                best = join;
//                System.out.println("Best:" + best);
            }
        } while((arr = nextPermutation(arr)) != null);
        return best;
    }

    private static boolean test(boolean[][] mp, Integer[] arr) {
        Stack<Integer> que = new Stack<Integer>();
        que.push(arr[0]);
        for(int i = 1; i < arr.length; i++) {
            while(!que.isEmpty() && !mp[que.peek()][arr[i]])
                que.pop();
            if(que.isEmpty())
                return false;
            que.push(arr[i]);
        }
        return true;
    }

    public static String join(Integer a[], String names[]) {
        String result = "";
        for(int i = 0; i < a.length; i++) {
            result += names[a[i]];
        }
        return result;
    }
    // modifies c to next permutation or returns null if such permutation does not exist
    private static Integer[] nextPermutation( final Integer[] c ) {
        // 1. finds the largest k, that c[k] < c[k+1]
        int first = getFirst( c );
        if ( first == -1 ) return null; // no greater permutation
        // 2. find last index toSwap, that c[k] < c[toSwap]
        int toSwap = c.length - 1;
        while ( c[ first ].compareTo( c[ toSwap ] ) >= 0 )
            --toSwap;
        // 3. swap elements with indexes first and last
        swap( c, first++, toSwap );
        // 4. reverse sequence from k+1 to n (inclusive)
        toSwap = c.length - 1;
        while ( first < toSwap )
            swap( c, first++, toSwap-- );
        return c;
    }

    // finds the largest k, that c[k] < c[k+1]
    // if no such k exists (there is not greater permutation), return -1
    private static int getFirst( final Comparable[] c ) {
        for ( int i = c.length - 2; i >= 0; --i )
            if ( c[ i ].compareTo( c[ i + 1 ] ) < 0 )
                return i;
        return -1;
    }

    // swaps two elements (with indexes i and j) in array
    private static void swap( final Comparable[] c, final int i, final int j ) {
        final Comparable tmp = c[ i ];
        c[ i ] = c[ j ];
        c[ j ] = tmp;
    }
}
