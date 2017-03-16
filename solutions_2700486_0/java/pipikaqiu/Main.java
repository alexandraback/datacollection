package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }

    public int n,x,y;
    public int [][] c;
    public int MAXC = 8;
    public int [] fac = new int[]{1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    public int [] pow2 = new int []{1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024};
    public int [] block = new int []{1,6,15,28};
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/B-small-attempt3.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        c = new int [MAXC][MAXC];
        for (int i = 1; i < MAXC; i++) {
            for (int j = 0; j <= i; j++) {
                c[i][j] = fac[i]/fac[j]/fac[i-j];
            }
        }
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            n = Integer.parseInt(split[0]);
            x = Integer.parseInt(split[1]);
            x = Math.abs(x);
            y = Integer.parseInt(split[2]);
            double result = 0;
            for (int i = 0; i < block.length; i++) {
                if(n == block[i]){
                    if((x+y)/2 <= i) result = 1;
                    else result = 0;
                    break;
                }
                if(n < block[i]){
                    if((x+y)/2 <= i-1){
                        result = 1;
                        break;
                    }
                    if((x+y)/2 > i){
                        result = 0;
                        break;
                    }
                    int t = (block[i]-block[i-1])/2;
                    int k = n - block[i-1];
                    int base = 0;
                    while(k>t){
                        base++;
                        t--;
                        k-=2;
                    }
                    if(y<base){
                        result = 1;
                        break;
                    }
                    if(k==0){
                        result = 0;
                        break;
                    }
                    int up = 0;
                    for (int j = y+1-base; j <= k; j++) {
                        up += c[k][j];
                    }
                    result = (double)up/pow2[k];
                    break;
                }
            }
            // output
            System.out.println("Case #"+(caseNum+1)+": ");
            System.out.println(Double.toString(result));
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Double.toString(result));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
}