import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;


public class ProblemAOsmos {
    public static void main(String[] args) {
        try {
            FileReader input = new FileReader(args[0]);
            BufferedReader in = new BufferedReader(input);
            FileWriter output = new FileWriter("Osmos.out");
            BufferedWriter out = new BufferedWriter(output);
            
            int count = 1;            
            int cases = Integer.parseInt(in.readLine());
            
            while (count <= cases) {
                if (count != 1) {
                    out.write("\n");
                }
                
                String[] nums = in.readLine().split("\\s+");
                int aMote = Integer.parseInt(nums[0]);
                int nVal = Integer.parseInt(nums[1]);
                
                nums = in.readLine().split("\\s+");
                int[] nMotes = new int[nVal];
                for (int i = 0; i < nVal; i++) {
                    nMotes[i] = Integer.parseInt(nums[i]);
                }
                
                String outStr = "Case #" + count + ": " + minMoteOps(aMote, nMotes);
                System.out.print(aMote + " -> ");
                Arrays.sort(nMotes);
                for (int i = 0; i < nVal; i++) {
                    System.out.print(nMotes[i] + " ");
                }
                System.out.println();
                System.out.println(outStr);
                out.write(outStr);
                
                count++;
            }
            
            out.close();
            in.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static String minMoteOps(int aMote, int[] nMotes) {
        Arrays.sort(nMotes);
        
        int moteSize = aMote;
        int idx = 0;
        int size = nMotes.length;
        int ops = 0;
        int minDelOps = -1;
        
        while (idx < size) {
            if (moteSize > nMotes[idx]) {
                moteSize += nMotes[idx++];
            } else if ((2 * moteSize - 1) > nMotes[idx]) {
                ops++;
                moteSize += moteSize - 1;
            } else {
                //ops += size - idx;
                //size = idx;
                if (minDelOps == -1 || ops + size - idx < minDelOps) {
                    minDelOps = ops + size - idx;
                } else if (minDelOps != -1 && ops == minDelOps) {
                    ops += minDelOps;
                    break;
                }
                
                ops++;
                moteSize += moteSize - 1;
            }
        }
        
        if (minDelOps != -1 && minDelOps < ops) {
            ops = minDelOps;
        }
        
        return Integer.toString(ops);
    }
}
