import java.util.Scanner;

public class roundCQ1 {
     public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int testCase = scan.nextInt();
        for(int i = 1; i <= testCase; i++){
            int R = scan.nextInt();
            int C = scan.nextInt();
            int W = scan.nextInt();
            
            int num = getGaruntee(R, W, C);
            System.out.println("Case #"+i+": "+num);
            
            
        }
    }
     
     public static int getGaruntee(int R, int W, int C){
         int num = R * (C/W);
         if(C % W > 0){
             num = num + W;
         }else{
             num = num + W - 1;
         }
         return num;
     }
     
}
