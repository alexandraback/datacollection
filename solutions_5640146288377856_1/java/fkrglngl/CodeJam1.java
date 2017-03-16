import java.io.FileInputStream;
import java.util.Scanner;

/**
 * Created by Fatih on 10/05/2015.
 */
public class CodeJam1 {
    public static void main(String args[]) throws  Exception{
        A();
    }

    public static void A()throws  Exception{
        //Scanner scan = new Scanner(System.in);
        Scanner scan = new Scanner(new FileInputStream("C:\\Users\\Fatih\\Downloads\\A-large(1).in"));

        int T = scan.nextInt();

        for(int i = 0 ; i < T;i++){
            int R = scan.nextInt();
            int C = scan.nextInt();
            int W = scan.nextInt();
            int count =0;
            if(W ==1)
                count = C * R;
            else
            {
                int prs = (int)Math.ceil((double)C/W);
                count = prs*R+W-1;
            }
            System.out.printf("Case #%d: %d\n",i+1,count);
        }

    }
}
