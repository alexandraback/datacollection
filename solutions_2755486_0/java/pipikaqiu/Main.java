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

    public int tribes;
    public int [] d,n,w,e,s,deld,delp,dels;
    public boolean [] active;
    
    public Main() throws FileNotFoundException, IOException{
        BufferedReader br = new BufferedReader(new FileReader("D:/C-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("D:/result.txt"));
        int cases = Integer.parseInt(br.readLine());
        for (int caseNum = 0; caseNum < cases; caseNum++) {
            tribes = Integer.parseInt(br.readLine());
            d = new int [tribes];
            n = new int [tribes];
            w = new int [tribes];
            e = new int [tribes];
            s = new int [tribes];
            deld = new int [tribes];
            delp = new int [tribes];
            dels = new int [tribes];
            active  = new boolean[tribes];
            String [] split;
            for (int i = 0; i < tribes; i++) {
                split = br.readLine().split(" ");
                d[i] = Integer.parseInt(split[0]);
                n[i] = Integer.parseInt(split[1]);
                w[i] = Integer.parseInt(split[2]);
                e[i] = Integer.parseInt(split[3]);
                s[i] = Integer.parseInt(split[4]);
                deld[i] = Integer.parseInt(split[5]);
                delp[i] = Integer.parseInt(split[6]);
                dels[i] = Integer.parseInt(split[7]);
                active[i] = true;
            }
            int [] height = new int[411];
            int [] newHeight = Arrays.copyOf(height, height.length);
            int base = 205;
            int count = 0;
            boolean changed;
            boolean noActive;
            for (int time = 0; time < 676061; time++) {
                changed = false;
                for (int i = 0; i < tribes; i++) {
                    if(active[i] && time >= d[i] && (time-d[i])%deld[i]==0){
                        int atkTime = (time-d[i]) / deld[i];
                        int atkStr = s[i]+atkTime*dels[i];
                        if(atkTime+1 == n[i])
                            active[i] = false;
                        for (int j = w[i]+atkTime*delp[i]; j < e[i]+atkTime*delp[i]; j++) {
                            if(height[j+base]<atkStr){
                                changed = true;
                                count ++;
                                break;
                            }
                        }
                        for (int j = w[i]+atkTime*delp[i]; j < e[i]+atkTime*delp[i]; j++) {
                            if(newHeight[j+base]<atkStr){
                                newHeight[j+base] = atkStr;
                            }
                        }
                    }
                }
                if(changed){
                    height = newHeight;
                    newHeight = Arrays.copyOf(height, height.length);
                }
                noActive = true;
                for (int i = 0; i < tribes; i++) {
                    if(active[i]) noActive = false;
                }
                if(noActive) break;
            }
            // output
            System.out.println("Case #"+(caseNum+1)+":"+count);
            bw.write("Case #"+(caseNum+1)+": ");
            bw.write(Integer.toString(count));
            bw.write(changeLine);
        }
        br.close();
        bw.close();
    }
}