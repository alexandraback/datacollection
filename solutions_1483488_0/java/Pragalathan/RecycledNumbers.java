
import codejam.StoreCredit;
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedHashSet;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author java
 */
public class RecycledNumbers {

    static BufferedReader in;

    private static void open() {
        in = new BufferedReader(new InputStreamReader(System.in));
    }

    private static void close() {
        try {
            in.close();
        } catch (IOException ex) {
            Logger.getLogger(StoreCredit.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    private static int readInt() throws IOException {
        Integer i = Integer.parseInt(in.readLine());
        return i;
    }

    private static int[] readInts() throws IOException {
        String[] vals = in.readLine().split(" ");
        int[] arr = new int[vals.length];
        for (int i = 0; i < vals.length; i++) {
            arr[i] = Integer.parseInt(vals[i]);
        }
        return arr;
    }

    public static void main(String[] args) throws IOException {
        open();
        int T = readInt();
        for (int t = 0; t < T; t++) {
            int[] arr = readInts();
            int A = arr[0];
            int B = arr[1];
            Set<Integer> set = new LinkedHashSet<Integer>();
            Set<Integer> additionalSet = new HashSet<Integer>();
            while (A <= B) {
                String v = String.valueOf(A);
                set.add(A);
                A++;
            }
            Iterator<Integer> it = set.iterator();
            Set<String> used = new LinkedHashSet<String>();
            StringBuilder b = new StringBuilder();
            while (it.hasNext()) {
                int val = it.next();
                it.remove();
                b.delete(0, b.length());
                b.append(val);
                int iteration = b.length();
                boolean added = false;
                if (iteration > 1) {
                    for (int i = 0; i < iteration - 1; i++) {
                        char c = b.charAt(0);
                        b.deleteCharAt(0);
                        b.append(c);
                        String newItem = b.toString();

                        // remove leading 0
                        int j = 0;
//                    for (; j < newItem.length() && newItem.charAt(j) == '0'; j++);
//                    newItem = newItem.sub1string(j);
                        int newNumber = Integer.parseInt(newItem);
                        if ((set.contains(newNumber)
                                || additionalSet.contains(newNumber)) && !used.contains(val + "#" + newNumber)) {
                            used.add(val + "#" + newNumber);
                            added = true;
                        }
                    }
                }
                if (!added) {
                    additionalSet.add(val);
                }

            }
            System.out.println("Case #" + (t + 1) + ": " + used.size());
//        System.out.println(used);
        }
        close();
    }
}
