import java.util.Scanner;

public class HikingDeer {
    
    public static void main(String[] args) {  
        Scanner s = new Scanner(System.in);
        int t = s.nextInt();
        for (int i = 1; i <= t; i++) {
            int N = s.nextInt();
            int[][] hikers = new int[N][3];
            for (int j = 0; j < N; j++) {
                hikers[j][0] = s.nextInt();
                hikers[j][1] = s.nextInt();
                hikers[j][2] = s.nextInt();
            }
            int result = 0;
            if (N == 2) {
                double a = ((360 - hikers[0][0]) / 360.0) * hikers[0][2];
                double b = ((360 - hikers[1][0]) / 360.0) * hikers[1][2];     
                double a2 = a + hikers[0][2];
                double b2 = b + hikers[1][2];
                if (a2 < b || b2 < a) {
                    result = 1;
                } 

            }
            System.out.println("Case #" + i + ": " + result);
        }
    }
    
}
