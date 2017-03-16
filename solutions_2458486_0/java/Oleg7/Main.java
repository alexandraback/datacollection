import java.io.*;
import java.util.*;

public class Main {

    // system
    public static String charset = "UTF-8";
    public static Locale locale = new Locale("en", "US");
    public static PrintWriter stdOut, fileOut;
    public static Scanner stdIn, fileIn;

    // task
    public static class Chest {
        public int n;
        public int openKey;
        public int[] keys;
    }

    public static int N;
    public static Chest[] trove;
    //public static Map<Integer, Integer> keys;
    public static int[] keys;
    public static int NKeys;

    public static void main(String[] args) {
        setIO("D-small-attempt1.in", "output.out");
        Scanner input = fileIn;
        PrintWriter output = fileOut;

        int T = input.nextInt();
        for (int i = 1; i <= T; i++) {
            NKeys = input.nextInt();
            N = input.nextInt();
            //keys = new HashMap<Integer, Integer>(NKeys);
            keys = new int[400];
            for (int j = 1; j <= N; j++) {
                keys[j] = 0;
            }
            for (int j = 0; j < NKeys; j++) {
                /*int readKey = input.nextInt();
                Integer key = keys.get(readKey);
                if (key == null) {
                    keys.put(readKey, 1);
                } else {
                    keys.put(readKey, key + 1);
                }*/
                int key = input.nextInt();
                //stdOut.println(key);
                keys[key]++;
            }
            trove = new Chest[N+1];
            for (int j = 1; j <= N; j++) {
                Chest chest = new Chest();
                chest.n = j;
                chest.openKey = input.nextInt();
                int Ki = input.nextInt();
                chest.keys = new int[Ki];
                for (int k = 0; k < Ki; k++) {
                    chest.keys[k] = input.nextInt();
                }
                trove[j] = chest;
            }
            String resStr = "Case #" + i + ": " + solve();
            output.println(resStr);
            stdOut.println(resStr);
        }

        input.close();
        output.close();
    }

    // task
    public static String solve() {
        ArrayList<Chest> stack = new ArrayList<Chest>();
        int openChests = 0;
        int startI = 1;

        while (true) {
            if (openChests == N) {
                // solved
                String res = "";
                for (int i = 0; i < stack.size() - 1; i++) {
                    res += stack.get(i).n + " ";
                }
                res += stack.get(stack.size() - 1).n;
                return res;
            } else if (NKeys > 0) {
                // step forward
                boolean isFound = false;
                for (int i = startI; i <= N; i++) {
                    Chest chest = trove[i];
                    if (chest != null) {
                        //Integer key = keys.get(chest.openKey);
                        //if (key != null && key > 0) {
                        if (keys[chest.openKey] > 0) {
                            stack.add(chest);
                            // apply chest
                            trove[i] = null;
                            //keys.put(chest.openKey, key - 1);
                            keys[chest.openKey]--;
                            NKeys--;
                            for (int j = 0; j < chest.keys.length; j++) {
                                /*key = keys.get(chest.keys[j]);
                                if (key == null) {
                                    keys.put(chest.keys[j], 1);
                                } else {
                                    keys.put(chest.keys[j], key + 1);
                                }*/
                                keys[chest.keys[j]]++;
                                NKeys++;
                            }
                            openChests++;
                            startI = 1;
                            isFound = true;
                            break;
                        }
                    }
                }
                if (!isFound) return "IMPOSSIBLE";
            } else if (stack.size() > 0) {
                // step back
                Chest chest = stack.remove(stack.size() - 1);
                trove[chest.n] = chest;
                //Integer key = keys.get(chest.openKey);
                //keys.put(chest.openKey, key + 1);
                keys[chest.openKey]++;
                NKeys++;
                for (int j = 0; j < chest.keys.length; j++) {
                    /*key = keys.get(chest.keys[j]);
                    keys.put(chest.keys[j], key - 1);*/
                    keys[chest.keys[j]]--;
                    NKeys--;
                }
                openChests--;
                startI = chest.n + 1;
            } else {
                return "IMPOSSIBLE";
            }
        }
    }

    // system
    public static void setIO(String fileInName, String fileOutName) {
        // Standard input
        stdIn = new Scanner(new BufferedInputStream(System.in), charset);
        stdIn.useLocale(locale);

        // Standard output
        try {
            stdOut = new PrintWriter(new OutputStreamWriter(System.out, charset), true);
        }
        catch (UnsupportedEncodingException e) {
            System.err.println(e);
        }

        // File input
        if (fileInName != null) {
            try {
                File file = new File(fileInName);
                if (file.exists()) {
                    fileIn = new Scanner(file, charset);
                    fileIn.useLocale(locale);
                }
            }
            catch (IOException ioe) {
                System.err.println("Could not open " + fileInName);
            }
        }

        // File output
        if (fileOutName != null) {
            try {
                OutputStreamWriter osw = new OutputStreamWriter(new FileOutputStream(fileOutName), charset);
                fileOut = new PrintWriter(osw, true);
            }
            catch (IOException e) {
                System.err.println(e);
            }
        }
    }
}
