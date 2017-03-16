package main;

import java.io.*;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;

public class Main {
    
    public static final String changeLine = System.getProperty("line.separator");
    
    public static void main(String[] args) throws FileNotFoundException, IOException{
        Main main = new Main();
    }

    public int a,n;
    public int [] data;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/A-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            String [] split = br.readLine().split(" ");
            a = Integer.parseInt(split[0]);
            n = Integer.parseInt(split[1]);
            data = new int[n];
            split = br.readLine().split(" ");
            for (int i = 0; i < n; i++) {
                data[i] = Integer.parseInt(split[i]);
            }
            Arrays.sort(data);
            long longA = a;
            int result = n;
            int count = 0;
            if(longA!=1){
                for (int i = 0; i < n; i++) {
                    while (longA <= data[i]){
                        longA += (longA-1);
                        count++;
                    }
                    longA += data[i];
                    if(count + n-i-1 < result)
                        result = count + n-i-1;
                }
            }
            // output
            System.out.println("Case #"+(caseNum+1)+":");
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Integer.toString(result));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
}