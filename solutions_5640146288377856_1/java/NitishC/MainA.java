import java.util.Scanner;

public class MainA {
    static int getCount(int R, int C, int W) {
        int count = 0;
        if(C==W) {
            count = W;
        } else {
            int p = -1;
            while(p+W<C){
                p = p+W;
//                System.out.println(p);
                count++;
            }
            if(p == C-1)
                count += W-1;
            else {
                count += W;
            }
        }
        for(int i=1;i<R;i++){
            int p = -1;
            while(p+W<C){
                p = p+W;
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int T = sc.nextInt();
        sc.nextLine();
        for (int t = 1; t <= T; t++) {
            int R = sc.nextInt();
            int C = sc.nextInt();
            int W = sc.nextInt();
            if(W == 1){
                System.out.println("Case #" + t + ": " + R*C);
            } else {
                System.out.println("Case #" + t + ": " + getCount(R,C,W));
            }
        }
    }
}
