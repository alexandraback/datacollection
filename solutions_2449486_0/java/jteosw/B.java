import java.util.*;
public class B{
    static Scanner s;

    public static void main(String[] args){
        s = new Scanner(System.in);
        int rounds = s.nextInt();
        for(int i = 1; i <= rounds; i++) {
            int m = s.nextInt();
            int n = s.nextInt();
            String result = play(m, n);
            System.out.printf("Case #%d: %s\n", i, result);
        }
    }

    public static String play(int m, int n) {
        int[][] array = new int[m][n];
        scan(array, m, n);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                boolean flag = check(array, i, j, m, n);
                if (flag) {
                    return "NO";
                }
            }
        }
        return "YES";
    }

    public static boolean check(int[][] array, int i, int j, int m, int n) {
        int key = array[i][j];
        boolean horizontal = true;
        for(int a = 0; a < m; a++) {
            if ( array[a][j] > key) horizontal = false;
        }
        if (horizontal) return false;
        boolean vertical = true;
        for(int b = 0; b < n; b++) {
            if ( array[i][b] > key) vertical = false;
        }
        if (vertical) return false;
        return true;
    }

        


    public static void scan(int[][] array, int m, int n) {
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                array[i][j] = s.nextInt();
            }
        }
    }
} 
