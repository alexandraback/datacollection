import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;
import java.util.TreeMap;

class Recycled {
    public static void main(String args[]) throws IOException{
        Scanner in = new Scanner(new File("recycle.txt"));
        PrintWriter fw = new PrintWriter(new FileWriter(new File("recycle.out")));
        TreeMap<Integer, ArrayList<Integer> > map = new TreeMap<Integer, ArrayList<Integer> >();
        for(int i = 1; i <= 2000000; i++){
            ArrayList<Integer> arr = new ArrayList<Integer>();
            String it = "" + i;
            for(int k = 0; k < it.length(); k++){
                int temp = Integer.parseInt(it.substring(k + 1, it.length()) + it.substring(0, k+1));
                if(temp > i){
                    boolean add = true;
                    for(int ad = 0; ad < arr.size(); ad++){
                        if(temp==arr.get(ad)) add = false;
                    }
                    if(add) arr.add(temp);
                }
            }
            Collections.sort(arr);
            map.put(i, arr);
        }
        int cases = in.nextInt();
        for(int c = 1; c <= cases; c++){
            int A = in.nextInt();
            int B = in.nextInt();
            int pass = 0;
            for(int a = A; a < B; a++){
                if(map.get(a)==null) continue;
                ArrayList<Integer> list = map.get(a);
                for(int l = 0; l < list.size(); l++){
                    if(list.get(l) <= B) pass++;
                    else break;
                }
            }
            String out = "Case #" + c + ": " + pass;
            fw.println(out);
        }
        fw.close();
    }
}
