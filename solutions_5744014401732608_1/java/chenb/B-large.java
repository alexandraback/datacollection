import java.util.*;


public class Main {

    public static void main(String... args) {
        Main a = new Main();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for (int i = 0; i < caseNum; i++) {
            int b = scanner.nextInt();
            long m = scanner.nextLong();
            a.solve(b, m , i);
        }
    }


    public void solve(int b,  long m, int index) {
        if(m > Math.pow(2, b-2)) {
            System.out.println(String.format("Case #%d: IMPOSSIBLE", index + 1));
            return;
        }

        int i = 1;
        int[][] result = new int[b][b];
        m--;
        while (m > 0) {
            if(m %2 !=0) {
                result[i][b-1] = 1;
                for(int j=0; j<=i; j++) {
                    for(int k=0; k<j; k++) {
                        result[k][j] = 1;
                    }
                }
            }

            m/=2;
            i ++;
        }

        result[0][b-1] = 1;

        System.out.println(String.format("Case #%d: POSSIBLE", index + 1));
        for(i=0; i< b; i++) {
            for(int j=0; j< b; j++) {
                System.out.print(result[i][j]);
            }
            System.out.println();
        }
    }





}