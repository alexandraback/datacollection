/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam2014;

import InputOutput.IOHandle;
import java.io.IOException;
import java.util.Arrays;
import java.util.Collections;

/**
 *
 * @author kando
 */
public class DeceitfulWar {
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        DeceitfulWar mt = new DeceitfulWar();
    }
    
    
    private IOHandle ioh;
    public DeceitfulWar(){
        ioh = new IOHandle("input.in","output.out");
        
        int numberOfCases = Integer.parseInt(ioh.getLine());
        for(int i=1;i<=numberOfCases;i++){
            //flush number of blocks
            ioh.getLine();
            ioh.addLine(oneCase(ioh.getLineDoubles(),ioh.getLineDoubles(),i));
        }
        
        ioh.flush();
    }
    
    private String oneCase(double[] first, double[] second, int i){
        
        int[] res = solveCase(first,second);
        
        return "Case #"+i+": "+res[0]+" "+res[1];
    }
    
    private int[] solveCase(double[] first, double[] second){
        int[] res = new int[]{0,0};
        double[] first_normal = copy(first);
        double[] second_normal = copy(second);
        
        //calculate normal
        for(int i=0;i<first_normal.length;i++){
            if(first_normal[i] > secondChooses(second_normal,first_normal[i])){
                res[1]++;
            }
        }
        
        //calculate discif
        int max = 0;
        for(int i=0;i<first.length;i++){
            //if i would win it alone dont use deceive
            if(findMax(first, false) > findMax(second,false)){
                findMax(first,true);
                findMax(second,true);
                res[0]++;
            }else{
                if(findMin(first,true) > findMax(second,true))
                res[0]++;
            }
        }
        
        
        return res;
    }
    
    
    private int alternateReality(double[] first, double[] second){
        double[] ff = copy(first);
        double[] ss = copy(second);
        int res = 0;
        //calculate normal
        for(int i=0;i<ff.length;i++){
            if(ff[i] != -1 && ff[i] > secondChooses(ss,ff[i])){
                res++;
            }
        }
        return res;
    }
    
    /**
     * He chooses the lightest heavier or if he doesnt have the lightest
     * @param second
     * @param told
     * @return 
     */
    private double secondChooses(double[] second, double told){
        double min = 10;
        int index = -1;
        for(int i=0;i<second.length;i++) {
            if(second[i] != -1 && second[i]-told > 0){
                if(second[i]-told < min){
                    min = second[i]-told;
                    index = i;
                }
            }
        }
        if(index != -1){
            double pom = second[index];
            second[index] = -1;
            return pom;
        }else{

            for(int i=0;i<second.length;i++){
                if(second[i]!=-1 && second[i] < min){
                    min = second[i];
                    index = i;
                }
            }
            
            if(index != -1)
                second[index] = -1;
            return min;
        }
    }
    
    private double findMax(double[] arr,boolean remove){
        double max = -1;
        int index = -1;
        for(int i=0;i<arr.length;i++){
            if(arr[i]>max){
                max = arr[i];
                index = i;
            }
        }
        if(remove)arr[index] = -1;
        return max;
    }
    
    private double findMin(double[] arr,boolean remove){
        double min = 10;
        int index = -1;
        for(int i=0;i<arr.length;i++){
            if(arr[i] != -1 && arr[i] < min){
                min = arr[i];
                index = i;
            }
        }
        if(remove)arr[index] = -1;
        return min;
    }
    
    private double[] copy(double[] pom) {
        double[] res = new double[pom.length];
        
        for(int i=0;i<pom.length;i++){
            res[i] = pom[i];
        }
        return res;
    }
}
