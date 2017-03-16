package com.company.codejam;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Scanner;

public class LargeOmino {
    private final static String GABRIEL = "GABRIEL";
    private final static String RICHARD = "RICHARD";

    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int cases = in.nextInt();
            for(int index = 1; index<=cases; index++){


                int X = in.nextInt();
                int R = in.nextInt();
                int C = in.nextInt();

                //answer can only be RICHARD or GABRIEL
                int min = Math.min(R,C);
                int max = Math.max(R,C);
                String answer = solve(X,min,max);
                out.printf("Case #%d: %s\n",index,answer);
            }


        } catch (Exception e) {
            e.printStackTrace();
        } finally {
            if (in != null)
                in.close();
            if (out != null)
                out.close();
        }
    }//end method main

    public static String solve(int X, int min, int max){
        if(X==1){
            return GABRIEL;
        }

        if(X==2){
            if((min*max)%2==0){
                return GABRIEL;
            }else{
                return RICHARD;
            }
        }

        if(X==3){
            if((min*max)%3!=0){
                return RICHARD;
            }else{
                if(min==1)
                    return RICHARD;
                else
                    return GABRIEL;
            }
        }

        if(X==4){
            if((min*max)%4!=0){
                return RICHARD;
            }else{
                if(min<3)
                    return RICHARD;
                else
                    return GABRIEL;
            }
        }

        if(X==5){
            if((min*max)%5!=0){
                return RICHARD;
            }else{
                if(min<4){
                    if(min==3 && max>5){
                        return GABRIEL;
                    }else{
                        return RICHARD;
                    }
                }else{
                    return GABRIEL;
                }
            }
        }

        if(X==6){
            if((min*max)%6!=0){
                return RICHARD;
            }else{
                if(min<4)
                    return RICHARD;
                else
                    return GABRIEL;
            }
        }

        if(X>=7){
            return RICHARD;
        }
        throw new IllegalArgumentException("Illegal X:"+X);
    }//end method solve
}//end class SmallOmino
