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
    static long[] products;
    static long[] maxFactors;
    static long written;
    
    
    public static void main(String[] args) throws FileNotFoundException, IOException {
        Scanner scan = new Scanner(new File(in));
        BufferedWriter write = new BufferedWriter(new FileWriter(out));
        long numLines = scan.nextInt();
        for(long x = 1; x <= numLines; x++){
            write.write("Case #" + x + ":");
            r = scan.nextInt();
            n = scan.nextInt();
            m = scan.nextInt();
            k = scan.nextInt();
            while(scan.hasNext()){
                written = 0; // current number of answers written
                String answer = "";
                write.newLine();
                products = new long[k];
                maxFactors = new long[m+1];
                for(int y = 0; y < k; y++){
                    products[y] = scan.nextInt();
                }
                // for each possible factor, find the max number for all k's
                for(int y = 2; y <= m; y++){
                    long max = 0;
                    for(int z = 0; z < k; z++){
                        long temp = 0;
                        long currentProduct = products[z];
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
                        long currentProduct = products[y];
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
                } else {
                    for(int y = 0; y < k; y++){
                        long currentProduct = products[y];
                        for(int z = 5; z <= m; z+=2){
                            while(currentProduct % z == 0){
                                currentProduct /= z;
                            }
                        }
                        int twos = 0;
                        long counter = 2;
                        while(currentProduct % counter == 0){
                            twos++;
                            counter*=2;
                        }
                        int threes = 0;
                        counter = 3;
                        while (currentProduct % counter == 0){
                            threes++;
                            counter*=3;
                        }
                        
                        if(twos == n - written){
                            big = true;
                            for(int z = 0; z < n - written; z ++){
                                answer += 2;
                            }
                            break;
                        } else if((twos + 1) / 3 == n - written){
                            big = true;
                            while(currentProduct % 4 == 0){
                                answer += 8;
                                currentProduct /=8 ;
                            }
                            if(currentProduct == 8){
                                answer += 4;
                            }
                            break;
                        } else if (Math.min(twos, threes) >= n - written - 1){
                            big = true;
                            while(currentProduct % 6 == 0){
                                answer += 6;
                                currentProduct /= 6;
                            }
                            twos = twos-threes;
                            counter = 2;
                            while(twos>1){
                                counter *= 2;
                                twos--;
                            }
                            answer += counter;
                            break;
                        }
                    }
                }
                
                // ending
                if(!big && n - written > 0){
                    for(int y = m; y >= 2; y--){
                        if(y == 5 || y == 7) continue;
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