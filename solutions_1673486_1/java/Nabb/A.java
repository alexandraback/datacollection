import java.util.*;

class A {
    static Scanner scan;
    public static double solve() {
        int a = scan.nextInt();
        int b = scan.nextInt();
        double res = 2+b;
        double p = 1;
        for(int x=1;x<=a;x++) {
            double f = scan.nextDouble();
            p *= f;
            int v = b+a+1-2*x;
            double r2 = p*v+(1-p)*(v+b+1);
            if(res>r2) res=r2;
        }
        return res;
    }
    public static void main(String[] args) {
        scan = new Scanner(System.in);
        int n = scan.nextInt();
        for(int i=1;i<=n;i++) {
            System.out.print("Case #"+i+": ");
            System.out.println(solve());
        }
    }
}
