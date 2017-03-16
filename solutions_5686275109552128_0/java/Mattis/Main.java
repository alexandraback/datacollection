package com.company;

import java.io.FileReader;
import java.io.PrintWriter;
import java.util.Arrays;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            in = new Scanner(new FileReader("input.txt"));
            out = new PrintWriter("output.txt");

            int cases = in.nextInt();
            for(int index=1; index<=cases; index++){

                int D = in.nextInt();
                int[] data = new int[D];
                for(int i=0; i<D; i++){
                    data[i] = in.nextInt();
                }
                int maxPancake = findMax(data);
                int answer = maxPancake;
                int[] pancakeFreq = new int[maxPancake+1];
                for(int num:data){
                    pancakeFreq[num]++;
                }
                maxPancake = biggestNonzero(pancakeFreq);
                int specialMinutes = 0;
                while( maxPancake > 3 ){
                    specialMinutes += pancakeFreq[maxPancake];
                    if(maxPancake%2==0){
                        pancakeFreq[maxPancake/2]+=pancakeFreq[maxPancake]*2;
                    }else{
                        pancakeFreq[maxPancake/2]+=pancakeFreq[maxPancake];
                        pancakeFreq[maxPancake/2+1]+=pancakeFreq[maxPancake];
                    }
                    pancakeFreq[maxPancake] = 0;
                    maxPancake = biggestNonzero(pancakeFreq);
                    int newAnswer = specialMinutes+maxPancake;
                    if(newAnswer<answer){
                        answer = newAnswer;
                    }
                }
                out.printf("Case #%d: %d\n",index,answer);





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

    public static int findMax(int[] data){
        int max = data[0];
        for(int i=1; i<data.length; i++){
            if(max<data[i])
                max = data[i];
        }//end for
        return max;
    }//end method findMax

    public static int biggestNonzero(int[] freqArray){
        boolean found = false;
        int result = freqArray.length - 1;
        while(!found && result>=1){
            if(freqArray[result]!=0){
                found = true;
            }else{
                result--;
            }
        }
        if(found)
            return result;
        else
            throw new RuntimeException();
    }
}//end class Main
