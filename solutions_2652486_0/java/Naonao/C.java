import java.util.*;
public class C{
    public static void main(String[]args) {
        Scanner in = new Scanner(System.in);
        int[] facts = {2,3,5};
        in.nextLine();
        in.nextLine();
        System.out.println("Case #1:");
        for(int caseNum = 1; caseNum <= 100; caseNum++){
            int[] max = new int[3];
            for(int z = 0; z <7; z++){
                int num = in.nextInt();
                for(int i = 0; i<3; i++){
                    int temp = num;
                    int count = 0;
                    while(temp%facts[i] ==0 ){
                        count++;
                        temp/=facts[i];
                    }
                    if(count > max[i]){
                        max[i] = count;
                    }
                }
            }
            String out = "";
            for(int i = 0; i < max[1]; i++){
                out += facts[1];
            }
            for(int i = 0; i < max[2]; i++){
                out += facts[2];
            }
            int left = 3 - out.length();
            for(int i = 0 ; i <left; i++){
                if(left < max[0]){
                    out += 4;
                    max[0]-=2;
                }else {
                    out += 2;
                    max[0]-=1;
                }
            }
            System.out.println(out);
        }
    }
}