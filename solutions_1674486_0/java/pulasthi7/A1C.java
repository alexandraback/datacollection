import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;
/**
 *
 * @author pulasthi
 */
public class A1C {
    public static void main(String[] args) throws Exception{
        Scanner sc = new Scanner(System.in);
        PrintWriter out = new PrintWriter("A.txt");
        int T = sc.nextInt();
        l1:for (int i = 0; i < T; i++) {
            out.print("Case #" + (i + 1) + ": ");
            int N = sc.nextInt();
            HashMap<Integer, ArrayList<Integer>> inh = new HashMap<Integer, ArrayList<Integer>>();
            for (int j = 0; j < N; j++) {
                int csups = sc.nextInt();
                ArrayList<Integer> sups = new ArrayList<Integer>();
                for (int k = 0; k < csups; k++) {
                    sups.add(sc.nextInt());
                }
                inh.put(j+1, sups);
            }
            for (int j = 0; j < N; j++) {
                if(inh.get(j+1).size()>0){
                    ArrayList<Integer> occ = new ArrayList<Integer>();
                    ArrayList<Integer> rem = new ArrayList<Integer>();
                    occ.addAll(inh.get(j+1));
                    while (!occ.isEmpty()) {                        
                        int cur = occ.get(0);
                        ArrayList<Integer> fromCur = inh.get(cur);
                        for (Integer integer : fromCur) {
                            if(occ.contains(integer)||rem.contains(integer)){
                                out.println("Yes");
                                continue l1;
                            } else{
                                occ.add(integer);
                            }
                        }
                        occ.remove(new Integer(cur));
                        rem.add(cur);
                    }
                }
            }
            out.println("No");
        }
        out.flush();
        out.close();
    }    
}