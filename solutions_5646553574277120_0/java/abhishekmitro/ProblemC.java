package codejam.q1c2015;

import java.io.BufferedWriter;
import java.io.File;
import java.io.FileWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;


public class ProblemC {

    public static void main(String[] args) throws Exception {
		
		Scanner sc = new Scanner(new File("ProblemC.txt.in"));
		BufferedWriter bw = new BufferedWriter(new FileWriter(new File("ProblemC.txt.out")));
		
		int T = sc.nextInt();
		sc.nextLine();
		
		for(int i=0;i<T;i++) {
		    int C = sc.nextInt();
            int D = sc.nextInt();
            int V = sc.nextInt();
            System.out.println("Case #" + (i+1));
            List<Integer> DList = new ArrayList<Integer>();
            for(int idx=0;idx<D;idx++)
                DList.add(sc.nextInt());
            int lastCoinIndex = -1;
            int newCoin =0;
            for(int curr=1;curr<=V;curr++){
                if(!DList.contains(curr)) {
              //      if(lastCoinIndex != -1)
            //        System.out.println(curr - DList.get(lastCoinIndex));
                    if(lastCoinIndex == -1 || !(curr - DList.get(lastCoinIndex) < DList.get(lastCoinIndex) )){
                        if(lastCoinIndex == -1 || (curr - DList.get(lastCoinIndex) != DList.get(lastCoinIndex) || lastCoinIndex ==0 )) {
                            DList.add(curr);
                            System.out.println(curr);
                            Collections.sort(DList);
                            newCoin++;
                            lastCoinIndex = DList.indexOf(curr);
                        } else if (curr - DList.get(lastCoinIndex) == DList.get(lastCoinIndex) ) {
                            int newV = curr - DList.get(lastCoinIndex);
                            List<Integer> dNew = new ArrayList<Integer>();
                            for(int idx=0;idx<lastCoinIndex;idx++)
                                dNew.add(DList.get(idx));
                            if(newCoinCount(dNew, newV) == 1) {
                                DList.add(curr);
                                System.out.println(curr);
                                Collections.sort(DList);
                                newCoin++;
                                lastCoinIndex = DList.indexOf(curr);
                            }
                        }
                    }
                } else
                    lastCoinIndex = DList.indexOf(curr);
            }
            
		    bw.write("Case #" + (i+1) +": "+ newCoin +"\n");
		}
		bw.close();
        sc.close();
	}
    
    public static int newCoinCount(List<Integer> DList, int V){
        int lastCoinIndex = -1;
        int newCoin =0;
        for(int curr=1;curr<=V;curr++){
            if(!DList.contains(curr)) {
                if(lastCoinIndex != -1)
                if(lastCoinIndex == -1 || !(curr - DList.get(lastCoinIndex) < DList.get(lastCoinIndex) )){
                    DList.add(curr);
                    Collections.sort(DList);
                    newCoin++;
                    lastCoinIndex = DList.indexOf(curr);
                }
            } else
                lastCoinIndex = DList.indexOf(curr);
        }
        return newCoin;
        
    }
}