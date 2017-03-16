
import java.io.*;
import java.math.*;
import java.util.*;

/**
 *
 * @author Daniel Sheng (dsheng)
 */
public class Kingdom {
    private static class Level implements Comparable<Level> {
        int star1;
        int star2;
        
        public Level(int i, int j)
        {
            star1 = i;
            star2 = j;
        }

        @Override
        public int compareTo(Level o) {
            return star2 == o.star2 ? ((Integer) star1).compareTo(o.star1) : ((Integer) star2).compareTo(o.star2);
        }
        
        public String toString()
        {
            return "[" + star1 + ", " + star2 + "]";
        }
    }

    private static Scanner in;
    private static PrintStream fout;
    private static int caseNum = 1;
    
    public static void main(String[] args) throws FileNotFoundException {
        in = new Scanner(System.in);
        fout = new PrintStream("Kingdom.out");
        
        int nln = Integer.parseInt(in.nextLine());
        PriorityQueue<Level> unplayable1s = new PriorityQueue<Level>(11, new Comparator<Level>()
        {

            @Override
            public int compare(Level o1, Level o2) {
                return o1.star1 == o2.star1 ? ((Integer) o1.star2).compareTo(o2.star2) : ((Integer) o1.star1).compareTo(o2.star1);
            }
            
        }),
                             unplayable2s = new PriorityQueue<Level>();
        PriorityQueue<Level> playable1s = new PriorityQueue<Level>(11, new Comparator<Level>()
        {

            @Override
            public int compare(Level o1, Level o2) {
                return o2.star1 == o1.star1 ? ((Integer) o2.star2).compareTo(o1.star2) : ((Integer) o2.star1).compareTo(o1.star1);
            }
            
        }), playable2s = new PriorityQueue<Level>(11, new Comparator<Level>()
        {

            @Override
            public int compare(Level o1, Level o2) {
                return o2.star2 == o1.star2 ? ((Integer) o2.star1).compareTo(o1.star1) : ((Integer) o2.star2).compareTo(o1.star2);
            }
            
        });
        HashSet<Level> played = new HashSet<Level>();
        for (int ln = 0; ln < nln; ln++) {
            int nlvl = integer();
            for(int lvl = 0; lvl < nlvl; lvl++)
            {
                int[] rewards = intsplit();
                Level l = new Level(rewards[0], rewards[1]);
                unplayable1s.add(l);
                unplayable2s.add(l);
            }
            
            int stars = 0, lplayed = 0;
            while(!unplayable2s.isEmpty())
            {
                while(!unplayable2s.isEmpty() && unplayable2s.peek().star2 <= stars)
                    playable2s.add(unplayable2s.poll());
                while(!unplayable1s.isEmpty() && unplayable1s.peek().star1 <= stars)
                    playable1s.add(unplayable1s.poll());
                
                if(unplayable2s.isEmpty())
                    break;
                
                println(playable1s);
                println(playable2s);
                
                if(playable2s.isEmpty())
                {
                    if(playable1s.isEmpty())
                    {
                        lplayed = -1;
                        break;
                    }
                    else
                    {
                        Level lll = playable1s.poll();
                        played.add(lll);
                        lplayed++;
                        stars += 1;
                    }
                }
                else
                {
                    Level lll = playable2s.poll();
                    if(played.contains(lll))
                        stars += 1;
                    else
                        stars += 2;
                    lplayed++;
                }
            }
            
            if(lplayed == -1)
            {
                println("Too Bad");
                result("Too Bad");
            }
            else
            {
                lplayed += playable2s.size();
                println(lplayed);
                result(lplayed);
            }
            
            unplayable1s.clear();
            unplayable2s.clear();
            playable1s.clear();
            playable2s.clear();
            played.clear();
        }
    }
    
    private static String line() {
        return in.nextLine();
    }
    
    private static int integer() {
        return Integer.parseInt(line());
    }
    
    private static double decimal() {
        return Double.parseDouble(line());
    }
    
    private static BigInteger bigint() {
        return new BigInteger(line());
    }
    
    private static BigDecimal bigdec() {
        return new BigDecimal(line());
    }
    
    private static String[] strsplit() {
        return line().split("\\s+");
    }
    
    private static int[] intsplit() {
        String[] strs = strsplit();
        int[] ints = new int[strs.length];
        for (int i = 0; i < ints.length; i++) {
            ints[i] = Integer.parseInt(strs[i]);
        }
        return ints;
    }
    
    private static double[] doublesplit() {
        String[] strs = strsplit();
        double[] dbls = new double[strs.length];
        for (int i = 0; i < dbls.length; i++) {
            dbls[i] = Double.parseDouble(strs[i]);
        }
        return dbls;
    }
    
    private static BigInteger[] bigintsplit() {
        String[] strs = strsplit();
        BigInteger[] ints = new BigInteger[strs.length];
        for (int i = 0; i < ints.length; i++) {
            ints[i] = new BigInteger(strs[i]);
        }
        return ints;
    }
    
    private static BigDecimal[] bigdecsplit() {
        String[] strs = strsplit();
        BigDecimal[] decs = new BigDecimal[strs.length];
        for (int i = 0; i < decs.length; i++) {
            decs[i] = new BigDecimal(strs[i]);
        }
        return decs;
    }
    
    private static void result(Object o) {
        fout.println("Case #" + (caseNum++) + ": " + o);
    }
    
    private static void resultf(String fmt, Object... args) {
        fout.printf("Case #%d: " + fmt, caseNum++, args);
    }
    
    private static void print(Object o) {
        System.out.print(o);
    }
    
    private static void println(Object o) {
        System.out.println(o);
    }
    
    private static void printf(String fmt, Object... args) {
        System.out.printf(fmt, args);
    }
}
