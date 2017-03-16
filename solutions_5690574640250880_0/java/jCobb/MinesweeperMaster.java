/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package codejam2014;

import InputOutput.IOHandle;
import java.io.IOException;
import java.util.ArrayList;

/**
 *
 * @author kando
 */
public class MinesweeperMaster {
    private IOHandle ioh;
    private int numberOfCases;
    
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        MinesweeperMaster mt = new MinesweeperMaster();
    }
    
    public MinesweeperMaster() {
        ioh = new IOHandle("input.in","output.out");
        
        numberOfCases = Integer.parseInt(ioh.getLine());
        int[] pom;
        int[][] res;
        for(int i=1;i<=numberOfCases;i++) {
            pom = ioh.getLineNumbers();
            res = oneCase(pom[0],pom[1],pom[2]);
            printResult(res, i);
        }
        
        ioh.flush();
    }
    
    /**
     * 
     * @param height
     * @param width
     * @param numberOfMines
     * @return if impossible return null otherwise array of chars for print 
     */
    private int[][] oneCase(int height, int width, int numberOfMines) {
        int[][] arr = new int[height][width];
        
        if(width*height-numberOfMines == 1){
            initArr(arr,-1);
            arr[0][0] = -2;
            return arr;
        }
        
        if(numberOfMines < height*width-numberOfMines){
            initArr(arr,0);
            if(recursive_add_mine(arr,0,numberOfMines,0,0,height,width))
                return arr;
            else
                return null;
        }
        else{
            initArr(arr,-1);
            if(recursive_add_blank(arr,0,height*width-numberOfMines,0,0,height,width))
                return arr;
            else
                return null;
        }
    }
    
    private boolean recursive_add_blank(int[][] arr, int current, int target, int x, int y, int height,int width){
        if(x < 0 || x >= height || y < 0 || y >= width || arr[x][y] != -1)
             return false;
        
        if(current == target){
            if(isGood(arr,height, width)){
                print(arr,width,height);
                return true;
            }
            return false;
        }
        
        arr[x][y] = 0;
        recountArray(arr, x, y, width, height);
        
        //move to all sides
        //print(arr,width,height);
            if(recursive_add_blank(arr,current+1,target,x,y+1,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x,y-1,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x+1,y,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x+1,y+1,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x+1,y-1,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x-1,y,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x-1,y-1,height,width))return true;
            if(recursive_add_blank(arr,current+1,target,x-1,y+1,height,width))return true;

            arr[x][y] = -1;
            recountArray(arr,x,y,width,height);
            return false;
        
    }
    
    private boolean recursive_add_mine(int[][] arr, int current, int target, int x, int y, int height,int width){
         if(x < 0 || x >= height || y < 0 || y >= width || arr[x][y] == -1)
             return false;
        
        if(current == target){
            if(isGood(arr,height, width)){
                print(arr,width,height);
                return true;
            }
            return false;
        }
        
        arr[x][y] = -1;
        recountArray(arr, x, y, width, height);
        
        //move to all sides
        //print(arr,width,height);
            if(recursive_add_mine(arr,current+1,target,x,y+1,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x,y-1,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x+1,y,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x+1,y+1,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x+1,y-1,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x-1,y,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x-1,y-1,height,width))return true;
            if(recursive_add_mine(arr,current+1,target,x-1,y+1,height,width))return true;

       
            arr[x][y] = 0;
            recountArray(arr,x,y,width,height);
            return false;
        
    }
    
    private boolean isGood(int[][] arr, int height, int width){
        for(int i=0;i<height;i++){
            for(int k=0;k<width;k++){
                if(arr[i][k] == 0) {
                    //we found 0, all zeros must be connected and connected to all numbers
                    transformConnections(arr, i, k, height, width);
                    if(checkArr(arr,height,width)){
                        //print(arr,width,height);
                        arr[i][k] = -2;
                        return true;
                    }else{
                        return false;
                    }
                }
            }
        }
        return false;
    }
    
    private void transformConnections(int[][] arr, int x, int y,int height, int width){
         if(x < 0 || x >= height || y < 0 || y >= width || arr[x][y] >= 10)
             return;
         
         if(arr[x][y] == 0){
             arr[x][y] = 100;
             transformConnections(arr,x,y+1,height,width);
             transformConnections(arr,x,y-1,height,width);
             transformConnections(arr,x+1,y-1,height,width);
             transformConnections(arr,x+1,y,height,width);
             transformConnections(arr,x+1,y+1,height,width);
             transformConnections(arr,x-1,y-1,height,width);
             transformConnections(arr,x-1,y,height,width);
             transformConnections(arr,x-1,y+1,height,width);
         }else if(arr[x][y] != -1) {
             arr[x][y] *= 10;
         }
    }
    
    private boolean checkArr(int[][] arr, int height, int width){
        boolean found = false;
        for(int i=0;i<height;i++){
            for(int k=0;k<width;k++){
                if(arr[i][k] >= 0 && arr[i][k] < 10)
                    found = true;
                else if(arr[i][k] != -1)
                    if(arr[i][k] != 100)
                        arr[i][k] = arr[i][k] / 10;
                    else
                        arr[i][k] = 0;
            }
        }
        return !found;
    }
    
    private void recountArray(int[][] arr, int x, int y, int width, int height){
        for(int i=0;i<height;i++){
            for(int k=0;k<width;k++){
                if(arr[i][k] != -1)
                arr[i][k] = neighbourMines(arr, i, k, width, height);
            }
        }
    }
    
    private int neighbourMines(int[][] arr, int x, int y, int width, int height){
        return 
                isMine(arr,x,y+1,width,height)+
                isMine(arr,x,y-1,width,height)+
                isMine(arr,x+1,y,width,height)+
                isMine(arr,x+1,y-1,width,height)+
                isMine(arr,x+1,y+1,width,height)+
                isMine(arr,x-1,y+1,width,height)+
                isMine(arr,x-1,y-1,width,height)+
                isMine(arr,x-1,y,width,height);
    }
    
    private int isMine(int[][] arr, int x, int y, int width, int height){
        if(x < 0 || x >= height || y < 0 || y >= width)
            return 0;
        else
            return (arr[x][y]==-1)?1:0;
    }
    
    
    
    /**
     * Initialize all array with sign
     * @param arr
     * @param sign 
     */
    private void initArr(int[][] arr, int sign) {
        for(int i=0;i<arr.length;i++) {
            for(int k=0;k<arr[i].length;k++)
                arr[i][k] = sign;
        }
    }
    
    
    
    /**
     * Transpone array arr from dimension [h][w] to new array [w][h]
     * @param arr
     * @return 
     */
    private char[][] transponeArr(char[][] arr) {
        if(arr == null)
            return null;
        int oldWidth = arr[0].length;
        int oldHeight = arr.length;
        
        char[][] res = new char[oldWidth][oldHeight];
        
        int index = 0;
        for(int i=0;i<oldWidth;i++)
            for(int k=0;k<oldHeight;k++,index++){
                res[index/oldHeight][index%oldHeight] = arr[k][i];
            }
        return res;
    }
    
    /**
     * Print array with format of task.
     * @param result
     * @param index 
     */
    private void printResult(int[][] result, int index) {
        ioh.addLine("Case #"+index+":");
        
        if(result == null){
            ioh.addLine("Impossible");
            return;
        }
        
        for(int r=0;r<result.length;r++) {
            ioh.addLine(arrayToString(result[r]));
        }
    }
    
    private String arrayToString(int[] arr) {
        String pom = "";
        for(int i=0;i<arr.length;i++) {
            if(arr[i]==-1)
                pom += '*';
            else if(arr[i] == -2)
                pom += 'c';
            else
                //pom += arr[i]+"";
                pom += '.';
        }
        
        return pom;
    }
    
    private void print(int[][] arr, int width, int height){
        for(int i=0;i<height;i++)
            System.out.println(arrayToString(arr[i]));
        System.out.println("");
    }
}
