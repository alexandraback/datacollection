/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package googlecodejam;

import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;

/**
 *
 * @author Bansari
 */
public class pancakes {
public static int solve(ArrayList<Integer> arr) {

    //    int time = 0;
//    int max = Collections.max(arr);
//    int minTime = max;
//    int min = 0;
//    while(max>2){        
//        max = Collections.max(arr);
//        arr.remove(new Integer(max));
//        arr.add(max/2);
//        arr.add(max-(max/2));
//        time = time+1;
//        max =  Collections.max(arr);
//        min = time +  max;
//        if(minTime > min){
//            minTime = min;
//        }
//    }
    int ans = Collections.max(arr);
    int min = 2;
    while(min < ans){
        ans = Math.min(ans, dosum(arr,min)+min);
        min++;
    }
    return ans;
    

    }
     
     public static void main(String[] args) throws Exception {
//        InputReader input = new InputReader(System.in);
//        OutputWriter output = new OutputWriter(System.out);

        BufferedReader f = new BufferedReader(new FileReader("pancakes.in"));
        PrintWriter out = new PrintWriter(new BufferedWriter(new FileWriter("pancakesout.txt")));
        int totacases = Integer.parseInt(f.readLine());
        for (int i = 0; i < totacases; i++) {
            int n = Integer.parseInt(f.readLine());
            ArrayList<Integer> arr = new ArrayList<>();
            String str = f.readLine();
            StringTokenizer st = new StringTokenizer(str);
            for (int j = 0; j < n; j++) {
                arr.add(Integer.parseInt(st.nextToken()));
            }
            
            int mm = solve(arr);
            out.println("Case #" + (i+1) + ": " + mm);
            System.out.println("Case #" + (i+1) + ": " + mm);
        }

        f.close();
        out.close();
    }

    private static int dosum(ArrayList<Integer> arr,int min) {
        
        int sum = 0;
        for(int i = 0;i<arr.size();i++){
            sum = sum+(arr.get(i)-1)/min;
        }
        return sum;
    }
}
