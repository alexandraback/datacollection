package googlecontest;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class GoogleContest {

    public static void main(String[] args) {
        Scanner stdin = new Scanner(System.in);
        int numCases = stdin.nextInt();
        
        int n = stdin.nextInt();
        int j = stdin.nextInt();
        int counter =0 ;
        int min = (int)Math.pow(2, n-3);
        int max = (int)Math.pow(2, n-2);
        
        System.out.println("Case #" + 1 + ": ");
        
        for (int i = min; i < max; i++) {
            long[] bases = {0,0,0,0,0,0,0,0,0,0,0,0};
            for (int k = 2; k <= 10; k++) {
                String str2 = "1"+Integer.toString(Integer.parseInt(String.valueOf(i), 10), 2)+"1";
                long strK = Long.parseLong(str2, k);
                if(strK%2 == 0){
                    bases[k]=2;
                    continue;
                }
                for (long l = 3; l < Math.sqrt(strK); l++) {
                    long z=strK%l;
                    if( z != 0){
                       continue;
                    }else{
                        bases[k]=l;
                        break;
                    }                                
                }
                if(bases[k]==0){
                    break;
                }
            }
            boolean skip=false;
            for (int k = 2; k < 11; k++) {
                if(bases[k]==0){
                    skip=true;
                    break;
                }
            }
            if(!skip){
                String str2 = "1"+Integer.toString(Integer.parseInt(String.valueOf(i), 10), 2)+"1";
                str2 += " ";
                for (int k = 2; k < 11; k++) {
                    str2 += bases[k];
                    if(k!=10){
                        str2 += " ";
                    }
                }
                System.out.println(str2);
                counter++;
                if(counter == j){
                    break;
                }
            }
        }
    }

}
