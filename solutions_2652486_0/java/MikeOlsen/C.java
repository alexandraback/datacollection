import java.io.*;
import java.util.Scanner;
import java.util.Arrays;
import java.text.*;
import java.util.ArrayList;
import java.math.*;

public class C {
    static String in = "src/in";
    static String out = "src/out";
    
    static int r;
    static int n;
    static int m;
    static int k;
    static int[] products;
    static int[] maxFactors;
    static int written;
    
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        int numLines = scan.nextInt();
        for(int x = 1; x <= numLines; x++){
            write.write("Case #" + x + ":");
            r = scan.nextInt();
            n = scan.nextInt();
            m = scan.nextInt();
            k = scan.nextInt();
            while(scan.hasNext()){
                written = 0; // current number of answers written
                String answer = "";
                write.newLine();
                products = new int[k];
                maxFactors = new int[m+1];
                for(int y = 0; y < k; y++){
                    products[y] = scan.nextInt();
                }
                // for each possible factor, find the max number for all k's
                for(int y = 2; y <= m; y++){
                    int max = 0;
                    for(int z = 0; z < k; z++){
                        int temp = 0;
                        int currentProduct = products[z];
                        while(currentProduct % y == 0 && currentProduct != 1){
                            temp++;
                            currentProduct = currentProduct/y;
                        }
                        if(temp > max) max = temp;
                    }
                    maxFactors[y] = max;
                }
                // m can be 2, 3, 4, 5, (6, 7, 8)
                

                
                
                if(n == 3){
                    for(int y = 3; y <= m; y+=2){
                        for(int z = 0; z < maxFactors[y]; z++){
                            written++;
                            answer+=y;
                        }
                    }
                } else {
                    for(int y = 5; y <= m; y+=2){
                        for(int z = 0; z < maxFactors[y]; z++){
                            written++;
                            answer+=y;
                        }
                    }
                }
                
                
                // n - written number of factors that are possible are left
                
                // check for any big numbers that only have one way of factoring into 3
                boolean big = false;
                if(n == 3){
                    for(int y = 0; y < k; y++){
                        int currentProduct = products[y];
                        for(int z = 3; z <= m; z+=2){
                            while(currentProduct % z == 0){
                                currentProduct /= z;
                            }
                        }
                        int twos = 0;
                        int counter = 2;
                        while(currentProduct >= counter){
                            twos++;
                            counter*=2;
                        }
                        if(twos == n - written){
                            big = true;
                            for(int z = 0; z < n - written; z ++){
                                answer += 2;
                            }
                            break;
                        } else if((twos + 1) / 2 == n - written){
                            big = true;
                            while(currentProduct % 4 == 0){
                                answer += 4;
                                currentProduct /=4 ;
                            }
                            if(currentProduct == 2){
                                answer += 2;
                            }
                            break;
                        }
                    }
                }
                
                System.out.println(Arrays.toString(maxFactors));
                // ending
                if(!big && n - written > 0){
                    for(int y = m; y >= 2; y-=2){
                        while(n - written > 0 && maxFactors[y] > 0){
                            answer+=y;
                            written++;
                            maxFactors[y]--;
                        }
                    }
                    while(written < n){
                        answer +=2;
                        written++;
                    }
                }
                System.out.println(answer);
                write.write(answer);
            }
            
            

        }
        scan.close();
        write.close();
    }
    
    static String generate(){
        String answer = "";
        return answer;
    }
}