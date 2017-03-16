import java.util.Scanner;

/**
 * Created by james on 16/04/10.
 */
public class Fractiles {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int tests = in.nextInt();
        int K[] = new int[tests];
        int C[] = new int[tests];
        int S[] = new int[tests];
        for(int i = 0; i < tests; i++){
            K[i] = in.nextInt();
            C[i] = in.nextInt();
            S[i] = in.nextInt();
        }
        for(int i = 0; i < tests; i++){
            System.out.printf("Case #%d:", i + 1);
            if(K[i] > C[i] * S[i])
                System.out.println(" IMPOSSIBLE");
            else {
                int counter = 1;
                long sum = 0;
                int c = 1;
                while(true){
                    sum *= K[i];
                    sum += counter > K[i] ? 0 : counter - 1;
                    if(c == C[i]) {
                        System.out.print(" " + (sum + 1));
                        if(counter >= K[i])
                            break;
                        c = 1;
                        sum = 0;
                    } else {
                        c++;
                    }
                    counter++;
                }
                System.out.println();
            }
        }
    }
}
