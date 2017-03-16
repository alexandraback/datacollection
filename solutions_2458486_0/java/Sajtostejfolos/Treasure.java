import java.io.*;

public class Treasure {

    private static void debug(String msg) {
        System.err.println(msg);
    }
    
    private static final int KEY_TYPES = 200 + 1;
    
    private static class Chest {
        public int openswith;
        public int[] contents;
    }
    
    private static int[] inventory;
    private static Chest[] chests;
    private static int[] sequence;
    
    private static boolean walk(int pos) {
        String debugmsg = "";
        for (int p = 0; p < pos; ++p)
            debugmsg += " " + sequence[p];
        debug("    walking at [" + debugmsg + " ]");

        if (pos < chests.length) {
            int[] actualinv = new int[inventory.length];
            boolean[] opened = new boolean[chests.length];
            for (int k = 0; k < actualinv.length; ++k) 
                actualinv[k] = inventory[k];
            for (int p = 0; p < pos; ++p) {
                int c = sequence[p];
                actualinv[chests[c].openswith]--;
                for (int k = 0; k < inventory.length; ++k)
                    actualinv[k] += chests[c].contents[k];
                opened[c] = true;
            }

            boolean[] neededkeys = new boolean[inventory.length];
            for (int c = 0; c < chests.length; ++c)
                if (!opened[c])
                    neededkeys[chests[c].openswith] = true;
            int[] availablekeys = new int[inventory.length];
            for (int k = 0; k < availablekeys.length; ++k)
                availablekeys[k] = actualinv[k];
            for (int c = 0; c < chests.length; ++c) {
                if (!opened[c])
                    for (int k = 0; k < availablekeys.length; ++k)
                        if (k != chests[c].openswith)
                            availablekeys[k] += chests[c].contents[k];
            }
            for (int k = 0; k < neededkeys.length; ++k) {
                if (neededkeys[k] && (availablekeys[k] < 1)) {
                    debug("    EARLY CUT (AVAILABILITY)");
                    return false;
                }
            }
            
            int[] future = new int[inventory.length];
            for (int k = 0; k < future.length; ++k)
                future[k] = actualinv[k];
            for (int c = 0; c < chests.length; ++c) {
                if (!opened[c]) {
                    future[chests[c].openswith]--;
                    for (int k = 0; k < future.length; ++k)
                        future[k] += chests[c].contents[k];
                }
            }
            for (int k = 0; k < future.length; ++k) {
                if (future[k] < 0) {
                    debug("    EARLY CUT (NOT ENOUGH KEYS AT ALL)");
                    return false;
                }
            }
            
            for (int c = 0; c < chests.length; ++c) {
                if (!opened[c] && (actualinv[chests[c].openswith] > 0)) {
                    sequence[pos] = c;
                    if (walk(pos + 1))
                        return true;
                }
            }
            return false;
        }
        else {
            return true;
        }
    }
    
    private static String formatKeys(int[] k) {
        String result = "";
        for (int i = 0; i < k.length; ++i) {
            if (k[i] != 0) {
                result += " " + i + ":" + k[i];
            }
        }
        return result;
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

            String[] numbers = in.readLine().split(" ");
            assert(numbers.length == 2) : "incorrect number of numbers " + numbers.length;
            int keynum = Integer.parseInt(numbers[0]);
            int chestnum = Integer.parseInt(numbers[1]);

            String[] keytypes = in.readLine().split(" ");
            assert(keytypes.length == keynum) : "incorrect number of starting keys: " + keytypes.length + " instead of " + keynum;
            inventory = new int[KEY_TYPES];
            for (int k = 0; k < keynum; ++k)
                inventory[Integer.parseInt(keytypes[k])]++;
            
            chests = new Chest[chestnum];
            for (int c = 0; c < chestnum; ++c) {
                chests[c] = new Chest();
                String[] cinfo = in.readLine().split(" ");
                chests[c].openswith = Integer.parseInt(cinfo[0]);
                int ckeynum = Integer.parseInt(cinfo[1]);
                assert(cinfo.length == 2 + ckeynum) : "incorrect chest line format";
                chests[c].contents = new int[KEY_TYPES];
                for (int k = 0; k < ckeynum; ++k)
                    chests[c].contents[Integer.parseInt(cinfo[2 + k])]++;
            }
            
            String debugmsg = "";
            debugmsg += "  inventory: contains=" + formatKeys(inventory) + "\n";
            for (int c = 0; c < chestnum; ++c)
                debugmsg += "  chest " + c + ": openswith=" + chests[c].openswith + " contains=" +formatKeys(chests[c].contents) + "\n";
            debug(debugmsg);
            
            sequence = new int[chestnum];
            if (walk(0)) {
                out.print("Case #" + i + ":");
                for (int c : sequence)
                    out.print(" " + (c+1));
                out.println();
                debug("  possible");
            }
            else {
                out.println("Case #" + i + ": IMPOSSIBLE");
                debug("  impossible");
            }
        }

        out.close();
        in.close();
    }

}
