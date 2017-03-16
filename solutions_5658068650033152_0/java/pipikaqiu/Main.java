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

    public int n,m,k;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/C-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            n = Integer.parseInt(split[0]);
            m = Integer.parseInt(split[1]);
            k = Integer.parseInt(split[2]);
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Integer.toString(cal()));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }

    public int cal(){
        if (n==1 || n==2 || m==1 || m==2 || k<=4) {
            return k;
        }
        k-=5;
        int result = 4;
        int inner = (n-2)*(m-2)-1;
        if (k<=0) {
            return result;
        }
        if (inner > 0) {
            if (k<=2) {
                return result + k;
            }
            k-=3;
            result += 2;
            if (k<=0) {
                return result;
            }
        }
        inner --;
        if (n==3 || m==3){
            while(inner > 0) {
                inner --;
                if (k<=2) {
                    return result + k;
                }
                k-=3;
                result += 2;
                if (k<=0) {
                    return result;
                }
            }
        } else {
            while(inner > 0) {
                inner --;
                k -= 2;
                result ++;
                if (k<=0) {
                    return result;
                }
            }
        }
        if (k>0) {
            return result + k;
        }
        return result;
    }
}