import java.io.*;
import java.util.*;

public class ProblemD {

    private static int getKeyMap(HashMap<Integer, Integer> map, int raw) {
	if (!map.containsKey(raw)) {
	    map.put(raw, map.size() + 1);
	}
	return map.get(raw);
    }

    public static String makeSignature(int[] keys, int[] locks) {
	StringBuffer sbuf = new StringBuffer(keys.length * 4 + locks.length);
	for (int i = 0; i < keys.length; i++) {
	    if (keys[i] > 0) {
		sbuf.append(keys[i] + "x" + i + ",");
	    }
	}
	sbuf.append("<>");
	for (int i = 0; i < locks.length; i++) {
	    if (locks[i] != 0) {
		sbuf.append(i + "@" + locks[i] + ",");
	    }
	}
	return sbuf.toString();
    }

    public static String getResult(int[] keys, int[] locks, int[][] contents, HashMap<String, String> cache) {
	int remaining = 0;
	for (int i = 0; i < locks.length; i++) {
	    remaining += (locks[i] > 0 ? 1 : 0);
	}
	if (remaining == 0) {
	    return "";
	}
	String SIGNATURE = makeSignature(keys, locks);
	if (cache.containsKey(SIGNATURE)) {
	    return cache.get(SIGNATURE);
	}
	String solution = null;
	for (int i = 0; i < locks.length; i++) {
	    if ((locks[i] == 0) || (keys[locks[i]] == 0)) {
		continue;
	    }
	    // Opening chest i!
	    //System.out.println("opening " + i + " from " + SIGNATURE);
	    int lockTmp = locks[i];
	    locks[i] = 0;
	    keys[lockTmp]--;
	    for (int k = 0; k < keys.length; k++) {
		keys[k] += contents[i][k];
	    }

	    String subSolution = getResult(keys, locks, contents, cache);

	    // Close chest i!
	    for (int k = 0; k < keys.length; k++) {
		keys[k] -= contents[i][k];
	    }
	    keys[lockTmp]++;
	    locks[i] = lockTmp;

	    if (subSolution != null) {
		solution = " " + (i+1) + subSolution;  // +1 for users
		break;
	    }
	}
	cache.put(SIGNATURE, solution);
	return solution;
    }

    public static String getResult(int[] keys, int[] locks, int[][] contents) {
	//System.out.println("key = " + Arrays.toString(keys));
	for (int i = 0; i < locks.length; i++) {
	    //System.out.println(i + "@" + locks[i] + " = " + Arrays.toString(contents[i]));
	}
	HashMap<String, String> cache = new HashMap<String, String>();
	String solution = getResult(keys, locks, contents, cache);
	//System.out.println(cache);
	return solution != null ? solution.substring(1) : "IMPOSSIBLE";
    }

    public static void main(String[] args) throws Exception {
	Scanner input = new Scanner(System.in);
	int cases = Integer.parseInt(input.nextLine().trim());
	for (int c = 0; c < cases; c++) {
	    String[] k_n = input.nextLine().split(" ");
	    int k = Integer.parseInt(k_n[0]);
	    int n = Integer.parseInt(k_n[1]);
	    int[] keysTmp = new int[k];
	    String[] starting = input.nextLine().split(" ");
	    for (int i = 0; i < k; i++) {
		keysTmp[i] = Integer.parseInt(starting[i]);
	    }
	    int[] locks = new int[n];
	    int[][] contentsTmp = new int[n][];
	    HashMap<Integer, Integer> keyMap = new HashMap<Integer, Integer>();
	    for (int i = 0; i < n; i++) {
		String[] lock_contents = input.nextLine().split(" ");
		locks[i] = getKeyMap(keyMap, Integer.parseInt(lock_contents[0]));
		contentsTmp[i] = new int[lock_contents.length - 2];
		for (int j = 2; j < lock_contents.length; j++) {
		    contentsTmp[i][j - 2] = Integer.parseInt(lock_contents[j]);
		}
	    }
	    //System.out.println(keyMap);
	    int[] keys = new int[keyMap.size() + 1];
	    Arrays.fill(keys, 0);
	    for (int raw : keysTmp) {
		if (keyMap.containsKey(raw)) {
		    keys[keyMap.get(raw)]++;
		}
	    }
	    int[][] contents = new int[n][keyMap.size() + 1];
	    for (int i = 0; i < contentsTmp.length; i++) {
		Arrays.fill(contents[i], 0);
		for (int raw : contentsTmp[i]) {
		    if (keyMap.containsKey(raw)) {
			contents[i][keyMap.get(raw)]++;
		    }
		}
	    }

	    System.out.println("Case #" + (c+1) + ": " + getResult(keys, locks, contents));
	}
    }
}