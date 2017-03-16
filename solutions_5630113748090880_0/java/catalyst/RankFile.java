/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package rankfile;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.HashMap;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author bhavishyasharma
 */
public class RankFile {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
            // TODO code application logic here
            Scanner sc = new Scanner(System.in);
            int t=sc.nextInt();
            for(int i=0;i<t;i++){
                int n=sc.nextInt();
                HashMap<Integer,Integer> start=new HashMap();
                int temp=0;
                for(int j=0;j<(2*n)-1;j++){
                    for(int k=0;k<n;k++){
                        temp=sc.nextInt();
                        if(start.containsKey(temp)){
                            start.put(temp, start.get(temp)+1);
                        }
                        else{
                            start.put(temp, 1);
                        }
                    }
                }
                Object keys[]=start.keySet().toArray();
                ArrayList tmp=new ArrayList(Arrays.asList(keys));
                tmp.sort(new Comparator() {
                    @Override
                    public int compare(Object o1, Object o2) {
                        Integer i1=(Integer) o1;
                        Integer i2=(Integer) o2;
                        if(i1<i2){
                            return -1;
                        }
                        else{
                            return 1;
                        }
                    }
                });
                System.out.printf("Case #%d:", i + 1);
                for(int j=0;j<tmp.size();j++){
                    if(start.get(tmp.get(j))%2!=0){
                        System.out.print(" "+tmp.get(j));
                    }
                }
                System.out.println();
            }
            
    }
    
}
