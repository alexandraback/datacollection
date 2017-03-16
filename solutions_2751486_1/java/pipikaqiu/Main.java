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

    public int n;
    public String str;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/A-large.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            str = split[0];
            n = Integer.parseInt(split[1]);
            long result = 0;
            int l = str.length();
            if(n==0){
                result = ((long)l)*(l+1)/2;
            } else {
                int i=0,j=0;
                int count=0;
                char current;
                while(i<l){
                    for (; j < l; j++) {
                        current = str.charAt(j);
                        if(current == 'a' ||current == 'e' ||current == 'i' ||current == 'o' ||current == 'u'){
                            count=0;
                        } else {
                            count++;
                        }
                        if(count==n)
                            break;
                    }
                    if(j==l) break;
                    result += (((long)j)-n+1 -i+1)*(l-j);
                    i=j-n+2;
                    j++;
                    count--;
                }
            }
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Long.toString(result));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
}