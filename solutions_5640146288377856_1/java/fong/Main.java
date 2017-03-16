import java.util.Scanner;

public class Main {

    public static Scanner input = new Scanner(System.in);
    public static void main(String[] args) {

        int numInputs = input.nextInt();
        for(int i = 0; i<numInputs;i++){
            int R = input.nextInt();
            int C = input.nextInt();
            int W = input.nextInt();
            int r = getNum(R, C, W);
            System.out.println("Case #"+(i+1)+": "+r);
        }
    }

    public static int getNum(int R, int c, int w){
        int result;
        if((w<=c/2&&c%w==0)||w==c) {
            result = c / w * R + w - 1;
        }else {
            result = c/w*R+w;
        }
        return result;
    }
}
