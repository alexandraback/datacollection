package codejam;

import java.io.*;
import java.util.*;

/**
 *
 * @author Pavel.Shiryaev
 */
public class D_Treasure {

    static final int maxN = 200;
    static boolean debugMode = false;
    // chests collection (N = 1..200); each chest (i) has 0..400 keys in it
    // keys collection (K = 1..400); types 1..25
    // input structures
    static ArrayList<Integer> keys = new ArrayList<Integer>(400); // k
    static ArrayList<ArrayList> chests = new ArrayList<ArrayList>(maxN);  // n
    //static ArrayList<Integer> chestLocks = new <Integer>ArrayList(maxN);  // n
    static int chestLocks[] = new int[maxN];
    // solution structure
    //static List<Integer> solution = new <Integer>ArrayList(200); // n
    static int solution[] = new int[maxN];
    static int k = 0;   // # of keys
    static int n = 0;   // # of chests
    static int level = 0;

    public static void main(String fileName) {

        InputStream fis;
        OutputStream fos;
        BufferedReader br;
        BufferedWriter bw;

        String output = "";

        try {
            fis = new FileInputStream(fileName);
            fos = new FileOutputStream(fileName.concat(".out"));

            br = new BufferedReader(new InputStreamReader(fis)); //, Charset.forName("UTF-8")));
            bw = new BufferedWriter(new OutputStreamWriter(fos)); //, Charset.forName("UTF-8")));

            String line = br.readLine();
            int nc = Integer.parseInt(line); // The first line of the input gives the number of test cases, T. T test cases follow. 

            // read cases
            for (int cc = 1; cc <= nc; cc++) {

                System.out.print("Case #" + cc + " out of " + nc + ": ");


                loadCase(br);   // cleans up structs and loads test case


                // solution

                findSolution();



                // display results
                output = "";
                if (allChestsAreOpen()) {
                    for (int i = 0; i < n; i++) {
                        output += " " + (solution[i] + 1);
                    }
                } else {
                    output = " IMPOSSIBLE";
                }

                System.out.println("Result: " + output);

                bw.write("Case #" + cc + ":" + output);
                bw.newLine();


                // line = br.readLine(); // Each test case is followed by an empty line.

            }   // end for cc; test case


            br.close();
            fis.close();
            bw.close();
            fos.close();
        } catch (Exception ex) {
            System.out.println(ex.getMessage());
            ex.printStackTrace();
        }

    }

    static void loadCase(BufferedReader br) throws IOException {

        // clean up solution structure

        keys.removeAll(keys);
        chests.removeAll(chests);
        //chestLocks.removeAll(chestLocks);
        //solution.removeAll(solution);
        for (int i = 0; i < n; i++) {
            chestLocks[i] = 0;
            solution[i] = 0;
        }
        level = 0;


        // Each test case begins with a single line containing two positive integers K and N,
        // representing the number of keys you start with and the number of chests you need to open.
        String line = br.readLine();
        String[] nm = line.split(" ");

        k = Integer.parseInt(nm[0]);
        System.out.print("  K: " + Integer.toString(k));
        n = Integer.parseInt(nm[1]);
        System.out.print("  N: " + Integer.toString(n));

        // This is followed by a line containing K integers, representing the types of the keys that you start with.
        line = br.readLine();
        String[] kk = line.split(" ");
        System.out.println("  READ KEYS: " + kk.length);
        //ArrayList <Integer>keys = new <Integer>ArrayList(k);
        for (int i = 0; i < k; i++) {
            keys.add(Integer.parseInt(kk[i]));
        }

        // After that, there will be N lines, each representing a single chest. 
        //ArrayList <ArrayList>chests = new <ArrayList>ArrayList(n);
        //ArrayList <Integer>chestLocks = new <Integer>ArrayList(n);
        for (int l = 0; l < n; l++) {
            // Each line will begin with integers Ti and Ki, 
            // indicating the key type needed to open the chest and the number of keys inside the chest. 
            // These two integers will be followed by Ki more integers, indicating the types of the keys contained within the chest
            line = br.readLine();

            String[] tk = line.split(" ");
            int ti = Integer.parseInt(tk[0]); // the key type needed to open the chest
            chestLocks[l] = ti; //chestLocks.add(ti);
            int ki = Integer.parseInt(tk[1]);   // the number of keys inside the chest
            ArrayList<Integer> chest = new ArrayList<Integer>(ki);
            for (int i = 0; i < ki; i++) {
                chest.add(Integer.parseInt(tk[2 + i]));
            }
            chests.add(chest);

        }


        // print out contents for testing
        if (debugMode) {
            // dump keys list
            System.out.print("KEYS:");
            for (int i = 0; i < keys.size(); i++) {
                System.out.print(" " + keys.get(i));
            }
            System.out.println();

            // dump chests list
            System.out.println("CHESTS:");
            for (int c = 0; c < chests.size(); c++) {
                //System.out.print(c + ": LOCK " + chestLocks.get(c) + "; KEYS: ");
                System.out.print(c + ": LOCK " + chestLocks[c] + "; KEYS: ");
                ArrayList<Integer> chest = chests.get(c);
                for (int i = 0; i < chest.size(); i++) {
                    System.out.print(" " + chest.get(i));
                }
                System.out.println();
            }


        }

    }

    static boolean isChestOpen(int i) {
        //return (chestLocks.get(i) == 0) ? true : false;
        return (chestLocks[i] == 0) ? true : false;
    }

    static boolean allChestsAreOpen() {
        for (int i = 0; i < n; i++) {
            if (!isChestOpen(i)) {
                return false;
            }
        }
        return true;
    }

    static void findSolution() {

        // acid test - what if no solutions are possible?
        if (!acidTest()) {
            return;
        }

        level = 0;
        openChest(0);

    }

    /**
     *
     * @param i # of chest (0..400)
     * @return true if all chests are opened; false if can't solve - not more
     * keys left
     */
    static boolean openChest(int i) {

        if (debugMode) {
            System.out.print("I=" + i + " L=" + level + " TROVE: ");
            for (int z = 0; z < n; z++) {
                //System.out.print(chestLocks.get(z) + " ");
                System.out.print(chestLocks[z] + " ");
            }
            System.out.print("  KEYS: ");
            for (int z = 0; z < keys.size(); z++) {
                System.out.print(keys.get(z) + " ");
            }
            System.out.print("  SOLUTION: ");
            for (int z = 0; z < level; z++) {
                System.out.print((solution[z] + 1) + " ");
            }
            System.out.println();
        }

        boolean result = false;

        if (level == n) {
            return true;
        }
        //if (allChestsAreOpen()) {            return true; // success; 
        //}

        if (i >= n) // no more chests
        {
            return false;
        }

        // acid test?
        if (!acidTest()) {
            return false;
        } // no more keys to open all chests

        // is the chest already opened?
        while (i < n) {
            if (isChestOpen(i)) {
                i++;
            } else {
                // can open?
                //int cl = chestLocks.get(i); // get lock code
                int cl = chestLocks[i]; // get lock code
                if (keys.contains(cl)) // do we have a key??
                {
                    // yes
                    keys.remove(keys.indexOf(cl));    // use the key
                    //chestLocks.set(i, 0);   // open the lock
                    chestLocks[i] = 0;   // open the lock
                    ArrayList<Integer> newKeys = chests.get(i); // retrieve keys
                    chests.set(i, new ArrayList<Integer>(0)); // remove keys from the chest
                    keys.addAll(newKeys); // add to the keychain
                    //solution.add(i); level++;
                    solution[level] = i;
                    level++;
                    // ?? check if any keys left here?
                    // now start with #1 again

                    if (level == n) {
                        return true;
                    }
                    result = openChest(0);

                    if (result && (level == n)) {
                        return true;
                    }

                    //if (allChestsAreOpen()) {                        return true;                    }

                    if (!result) // didn't work -> try opening remaining chests
                    {
                        // restore the lock and the keys
                        //keys.removeAll(newKeys); // bug - will remove more than 1 matching key!
                        for (int z = 0; z < newKeys.size(); z++) {
                            int indx = keys.indexOf(newKeys.get(z));
                            if (indx != -1) {
                                keys.remove(indx);
                            }
                        }
                        chests.set(i, newKeys);
                        //chestLocks.set(i, cl);
                        chestLocks[i] = cl;
                        keys.add(cl);

                        //solution.remove(solution.size() - 1); level--;
                        solution[level] = 0;
                        level--;

                        i++; // goto next chest

                    }

                } else // no we don't have a key for this
                {
                    i++; // goto next chest
                }

            } // end if chest closed
        } // end while


        if (allChestsAreOpen()) {
            return true; // success; 
        }

        return false;


    }

    static boolean acidTest() {

        // check if there is enough keys left
        
        ArrayList<Integer> tc = new ArrayList<Integer>(400);

        for (int i = 0; i < n; i++) {
            int cl = chestLocks[i];
//            if (cl == 0) {  // chest is empty
//                tk.addAll(chests.get(i)); // 
//            } else {
            if (cl != 0) {  // the chest is still full
                tc.addAll(chests.get(i)); // add all keys
                // ArrayList<Integer> t = new ArrayList<Integer>();
                // t.addAll(chests.get(i));
                // int indx = t.indexOf(cl);
                // if (indx != -1 && t.size() == 1) {
                //     t.remove(indx);
                //     tk.addAll(t);
                // }
                // else
               //  {
                //     tc.add(cl);
                //     tk.addAll(t);
                }
            }
        
        ArrayList<Integer> tk = new ArrayList<Integer>(400);
        tk.addAll(tc);
        tk.addAll(keys);

        //System.out.println("Total " + tk.size() + " keys on hands");

        for (int i = 0; i < n; i++) {
            int cl = chestLocks[i];
            if (cl != 0) {
                int indx = tk.indexOf(cl);
                if (indx == -1) {
                    return false;
                } // not enough keys on hands and in chests to open all remaining locks
                else {
                    tk.remove(indx);
                }

            }
        }

        // check that the single keys left are not locked in the same cells
        for (int i = 0; i < n; i++) {
            int cl = chestLocks[i];
            if (cl != 0) {
                int indx = keys.indexOf(cl);
                if (indx == -1) {
                    // we have no key for this chest - let's check if it's in the same chest
                    if (chests.get(i).contains(cl))
                    {
                        tc.remove(tc.indexOf(cl)); // yes, remove it
                        if (!tc.contains(cl)) { return false;} // it was the only key so the chest is unreachable
                        
                    }
                    
                    
                } 
                

            }
        }
        
        return true;
    }
}
