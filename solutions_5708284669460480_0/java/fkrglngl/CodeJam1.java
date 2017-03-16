import java.io.FileInputStream;
import java.util.ArrayList;
import java.util.Scanner;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

/**
 * Created by Fatih on 10/05/2015.
 */
public class CodeJam1 {
    public static void main(String args[]) throws  Exception{
        B();

    }

    public static void A()throws  Exception{
        Scanner scan = new Scanner(System.in);
        //Scanner scan = new Scanner(new FileInputStream("C:\\Users\\Fatih\\Downloads\\A-large(1).in"));

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
    public static void C() throws  Exception{

        //Scanner scan = new Scanner(new FileInputStream("C:\\Users\\Fatih\\Downloads\\B-large(1).in"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        for(int i = 0 ; i < T;i++) {
            int C= scan.nextInt();
            int D = scan.nextInt();
            int V = scan.nextInt();
            int count = 0;
            ArrayList<Integer> list = new ArrayList<Integer>();
            for(int j = 0; j < D;j++){
                list.add(scan.nextInt());
            }



            System.out.printf("Case #%d: %d\n",i+1,count);
        }
    }
    public static void B() throws  Exception{
        //Scanner scan = new Scanner(new FileInputStream("C:\\Users\\Fatih\\Downloads\\B-large(1).in"));
        Scanner scan = new Scanner(System.in);
        int T = scan.nextInt();
        int repet =0;
        for(int i = 0 ; i < T;i++){
            int K = scan.nextInt();
            int L = scan.nextInt();
            int S = scan.nextInt();

            double result = 0.0;
            String keys = scan.next();
            String target = scan.next();
            boolean flag = true;
            for(int j = 0; j < target.length();j++){
                if(keys.indexOf(target.charAt(j)) == -1)
                    flag = false;
            }
            if(target.length() > S || !flag)
                repet = 0;
            else{
                String pat = "";
                while(pat.length() <S)
                    pat+=target;


                repet = occurs(pat.substring(0,S),target);

            }
            double ratio = 1;
            for(int j = 0; j < target.length();j++)
            {
                ratio= ratio / ((double)keys.length()/occurs(keys,target.charAt(j)+""));
            }
            //ratio = (S - target.length() + 1) * ratio;
           // ratio = Math.pow(ratio, repet);

            System.out.printf("Case #%d: %.7f\n",i+1,repet * (1-ratio));

        }
    }
    public static int occurs(String str, String b){
        int lastIndex = 0;
        int count =0;

        while(lastIndex != -1){

            lastIndex = str.indexOf(b,lastIndex-b.length()+1);

            if( lastIndex != -1){
                count ++;
                lastIndex+=b.length();
            }
        }
        return count;
    }
}
