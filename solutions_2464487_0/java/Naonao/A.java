import java.util.*;
public class A{
    public static void main(String[]args) {
        Scanner in = new Scanner(System.in);
        int inputs = in.nextInt();
        for(int caseNum = 1; caseNum <= inputs; caseNum++){
            long r = in.nextLong();
            long t = in.nextLong();
            long a1 = 2*r+1;
            long min = 1;
            long max = 10000000000000l;
            while(min != max) {
                long mid = (min + max+1)/2;
                long a2 = a1 + 4*(mid-1);
                if(Long.MAX_VALUE/ mid < a1+a2 || mid*(a1+a2)/2 > t){
                    max = mid-1;
                } else {
                    min = mid;
                }
                //System.err.println(min + " " + max + "!");
            }
            System.out.printf("Case #%d: %d\n", caseNum, min);
        }
    }
}