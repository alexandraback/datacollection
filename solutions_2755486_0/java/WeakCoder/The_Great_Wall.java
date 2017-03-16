package Round_1_C;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.List;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Scanner;

public class The_Great_Wall {

    /**
     * @param args
     */
    public static void main(String[] args) {
        Scanner in = null;
        PrintWriter out = null;
        try {
            in = new Scanner(new File("C-small-attempt2.in"));
            //in = new Scanner(new File("test.in"));
            out = new PrintWriter(new File("c_small.out"));
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }
        int T = in.nextInt();
        Map<Integer, Integer> walls = new HashMap<Integer, Integer>();
        for (int cs=1; cs<=T; cs++) {
            int N = in.nextInt();
            List<Attack> attacks = new ArrayList<Attack>();
            walls.clear();
            for (int i=0; i<N; i++) {
                int di = in.nextInt();
                int ni = in.nextInt();
                int wi = in.nextInt();
                int ei = in.nextInt();
                int si = in.nextInt();
                int delta_di = in.nextInt();
                int delta_pi = in.nextInt();
                int delta_si = in.nextInt();
                for (int j=0; j<ni; j++) {
                    Attack a = new Attack();
                    a.day = di;
                    a.west = wi;
                    a.east = ei;
                    a.strength = si;
                    attacks.add(a);
                    di += delta_di;
                    wi += delta_pi;
                    ei += delta_pi;
                    si += delta_si;
                }
            }
            for (int i=0; i<attacks.size(); i++) {
                for (int j=i+1; j<attacks.size(); j++) {
                    Attack ai = attacks.get(i);
                    Attack aj = attacks.get(j);
                    if (aj.day < ai.day) {
                        attacks.set(i, aj);
                        attacks.set(j, ai);
                    }
                }
            }
            int number = 0;
            int lastDay = -1;
            Map<Integer, Integer> tmp = new HashMap<Integer, Integer>();
            for (int i=0; i<attacks.size(); i++) {
                Attack ai = attacks.get(i);
                if (ai.day > lastDay && !tmp.isEmpty()) {
                    Iterator<Entry<Integer, Integer>> ite = tmp.entrySet().iterator();
                    while (ite.hasNext()) {
                        Entry<Integer, Integer> ne = ite.next();
                        if (walls.get(ne.getKey()) == null || walls.get(ne.getKey()) < ne.getValue())
                            walls.put(ne.getKey(), ne.getValue());
                    }
                    tmp.clear();
                }
                boolean success = false;
                for (int j=ai.west+1; j<=ai.east; j++) {
                    if (walls.get(j) == null || walls.get(j) < ai.strength) {
                        success = true;
                        break;
                    }
                }
                //System.out.println(ai.toString() + "   result->" + success);
                if (success) {
                    number++;
                    for (int j=ai.west+1; j<=ai.east; j++)
                        if (tmp.get(j) == null || tmp.get(j) < ai.strength)
                            tmp.put(j, ai.strength);
                    lastDay = ai.day;
                }
            }
            
            String result = "Case #"+cs+": " + number;
            out.println(result);
            out.flush();
            System.out.println(result);
        }
    }

}

class Attack {
    public int day;
    public int west;
    public int east;
    public int strength;
    
    public String toString() {
        return "day:"+day+" west:"+west+" east:"+east+" str:" +strength; 
    }
}