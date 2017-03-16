import java.io.*;

public class Energy {

    private static void debug(String msg) {
        System.err.println(msg);
    }
    
    private static long maxenergy;
    private static long regain;
    private static long[] values;
    private static long[] spend;
    
    private static void recurse(int begin, int end, long beginenergy, long endenergy) {
        if (begin >= end)
            return;
        long maxval = values[begin];
        int maxindex = begin;
        for (int i = begin; i < end; ++i) {
            if (values[i] > maxval) {
                maxval = values[i];
                maxindex = i;
            }
        }

        long maxpossible = beginenergy + (maxindex - begin) * regain;
        if (maxpossible > maxenergy)
            maxpossible = maxenergy;
        long minneeded = endenergy - (end - maxindex) * regain;
        if (minneeded < 0)
            minneeded = 0;
        spend[maxindex] = maxpossible - minneeded;
        recurse(begin, maxindex, beginenergy, maxpossible);
        recurse(maxindex+1, end, minneeded + regain, endenergy);
    }
    
    public static void main(String[] args) throws Exception {
        String inputfile = args[0];
        String outputfile = args[1];
        
        BufferedReader in = new BufferedReader(new FileReader(inputfile));
        PrintWriter out = new PrintWriter(new FileWriter(outputfile));
        
        int cases = Integer.parseInt(in.readLine());
        debug("Number of test cases: " + cases);
        
        for (int i = 1; i <= cases; ++i) {
            debug("Processing Case #" + i);
            
            String[] params = in.readLine().split(" ");
            assert(params.length == 3) : "incorrect number of params " + params.length;
            maxenergy = Long.parseLong(params[0]);
            regain = Long.parseLong(params[1]);
            int actcount = Integer.parseInt(params[2]);
            debug("  E="+maxenergy+" R="+regain+" N="+actcount);
            
            String[] vstrs = in.readLine().split(" ");
            assert(vstrs.length == actcount) : "incorrect number of values " + vstrs.length;
            values = new long[actcount];
            for (int j = 0; j < actcount; ++j)
                values[j] = Long.parseLong(vstrs[j]);
            spend = new long[actcount];

            recurse(0, values.length, maxenergy, 0);
            
            long gain = 0;
            long energy = maxenergy;
            String debugstr = "";
            for (int j = 0; j < actcount; ++j) {
                debugstr += " "+spend[j];
                gain += spend[j] * values[j];
                energy -= spend[j];
                assert(energy >= 0) : "energy=" + energy;
                energy += regain;
                if (energy > maxenergy)
                    energy = maxenergy;
            }
            debug("  spend: " + debugstr);
            
            out.println("Case #" + i + ": " + gain);
        }
        
        out.close();
        in.close();
    }
}
