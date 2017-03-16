/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package DancingWithTheGooglers;

import java.io.File;
import java.io.FileWriter;
import java.io.Writer;
import java.util.Scanner;

/**
 *
 * @author Rishabh
 */
public class DancingWithTheGooglers {
    
    public void readFile(String path) throws Exception{
        File f = new File(path);
        Scanner scanner = new Scanner(f);
        String name = f.getName().substring(0,f.getName().indexOf('.'));
        Writer writer = new FileWriter(name+".out");
        int n = Integer.parseInt(scanner.nextLine());
        int caseno=0;
        while(scanner.hasNextLine()){
            caseno++;
            long[] num_arr = toIntArray(scanner.nextLine().split(" "));
            int N = (int)num_arr[0];
            int S = (int)num_arr[1];
            int p = (int)num_arr[2];
            int[] arr = new int[N];
            for(int i=0;i<N;i++){
                arr[i] = (int)num_arr[i+3];
            }
            int max_people = compute(N,S,p,arr);
            writer.write("Case #"+caseno+": "+max_people+"\r\n");
        }
        writer.close();
        scanner.close();
    }
    public static long[] toIntArray(String[] arr){
        long[] new_arr = new long[arr.length];
        int count = 0;
        for(String g : arr){
            new_arr[count] = Long.parseLong(g);
            count++;
        }
        return new_arr;
    }

    private int compute(int N, int S, int p, int[] arr) {
        boolean[][] vals = new boolean[N][2];
        int people=0;
        for(int i=0;i<N;i++){
            vals[i][0] = false;
            vals[i][1] = false;
            if(arr[i]<=30&&arr[i]>=Math.max(0,3*p-2))
                vals[i][0] = true;
            if(arr[i]<=28&&arr[i]>=Math.max(2, 3*p-4))
                vals[i][1] = true;
        }
        int single_count=0;
        for(int i=0;i<N;i++){
            if(vals[i][0])
                people++;
            if(vals[i][1]&&!vals[i][0])
                single_count++;
        }
        int ans = people + Math.min(S, single_count);
        return ans;
    }
    public static void main(String args[]) throws Exception{
        DancingWithTheGooglers dancingWithTheGooglers = new DancingWithTheGooglers();
        dancingWithTheGooglers.readFile("A-small-practice.in");
    }

    
}
