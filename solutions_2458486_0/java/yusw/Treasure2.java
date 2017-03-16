import java.util.Arrays;  //Arrays.toString(int[])
public class Treasure2 {
    public int[] Keys;
    public int[][] Chests;
    public int NumOfChests;
    public Stack<Integer> st = new Stack<Integer>();
    LinearProbingHashST<String, Boolean> hash = new LinearProbingHashST<String, Boolean>();
//    public int[] seq;
    public Treasure2(int[] vec1, int[][] vec2) {
        Keys = vec1;
        Arrays.sort(Keys);
        Chests = vec2;
        NumOfChests = Chests.length;
    }
    public boolean OpenOrNot(int[] keys, int[][] chests) {
//        StdOut.println("keys:");
//        StdOut.println(Arrays.toString(keys));
//        StdOut.println("chests:");
//        for (int i = 0; i < chests.length; i++) 
//            StdOut.println(Arrays.toString(chests[i]));
        if (hash.contains(KCtoString(keys,chests))) {
//            StdOut.println("cache hit");
//            StdOut.println(KCtoString(keys,chests));
            return hash.get(KCtoString(keys,chests));
        }
        
        int numKeys = keys.length;
        int numChests = chests.length;
        if (numChests == 0) return true;
        if (numKeys == 0 && numChests > 0)
            return false;
        if (numChests == 1) {
            if (hasKeyOfType(keys, TypeChest(chests[0]))) {
                st.push(0);
//                StdOut.println("push: 0");
                return true;
            }
            else
                return false;
        }
        for (int i = 0; i < numChests; i++) {
            int[] chest = chests[i];
            int type = TypeChest(chest);
            if (hasKeyOfType(keys, type)) {
                int[] add = KeysInChest(chest);
                if (OpenOrNot(removeKeyOfType(addKeys(keys,add), type), removeChest(chests, i))) {
//                    StdOut.println("push:"+ i);
                    st.push(i);
                    return true;
                }
//                else
//                    q = new Queue<Integer>();
            }
        }
//        StdOut.println("false");
//        StdOut.println("keys:");
//        StdOut.println(Arrays.toString(keys));
//        StdOut.println("chests:");
//        for (int i = 0; i < chests.length; i++) 
//            StdOut.println(Arrays.toString(chests[i]));
        hash.put(KCtoString(keys,chests), false);
//        StdOut.println("cache miss");
//        StdOut.println(KCtoString(keys,chests));
        return false;
    }
    public String KCtoString(int[] keys, int[][] chests) {
        String ans = Arrays.toString(keys)+":";
        for (int i=0; i<chests.length; i++) {
            ans += Arrays.toString(chests[i]);
        }
        return ans;
    }
    public String Output() {
        if (OpenOrNot(Keys, Chests))
            return OpenSeq();
        else
            return "IMPOSSIBLE";
    }
    public String OpenSeq() {
//        int[] ans = new int[q.size()];
//        for (int i = 0; i<q.size(); i++)
//            ans[i] = q.dequeue();
//        return ans;
        String seq = "";
        int[] arr = makeArr(NumOfChests);
        for (int i : st) {
            seq += (arr[i] + " ");
            arr = removeElem(arr, i);
        }
        return seq;
    }
    public int[] addKeys(int[] keys, int[] add) {
        int numKeys = keys.length;
        int numAdd = add.length;
        int[] ans = new int[numKeys + numAdd];
        for (int i = 0; i < numKeys + numAdd; i++) {
            if (i < numKeys)
                ans[i] = keys[i];
            else
                ans[i] = add[i - numKeys];
        }
        Arrays.sort(ans);
        return ans;
    }
    public int[] removeKeyOfType(int[] keys, int type) {
        int numKeys = keys.length;
        int[] ans = new int[numKeys - 1]; 
        boolean done = false; // only remove 1 key
        for (int i = 0, j = 0; i < numKeys; i++) {
            if (!done && keys[i] == type) {
                done = true;
                continue;
            }
            ans[j++] = keys[i];
        }
        return ans;
    }
    public int[] makeArr(int len) { //{1,2,...,len}
        int[] ans = new int[len];
        for (int i=0; i<len; i++) {
            ans[i] = i+1;
        }
        return ans;
    }
    public int[] removeElem(int[] arr, int idx) {
        int len = arr.length;
        int[] ans = new int[len-1];
        for (int i=0, j=0; i<len; i++) {
            if(i == idx) continue;
            ans[j++] = arr[i];
        }
        return ans;
    }
    public int[][] removeChest(int[][] chests, int idx) {
        int numChests = chests.length;
        int[][] ans = new int[numChests-1][];
        for (int i = 0, j = 0; i < numChests; i++) {
            if (i == idx) continue;
            ans[j++] = chests[i];
        }
        return ans;
    }
    public boolean hasKeyOfType(int[] keys, int type) {
//        for (int i = 0; i < keys.length; i++)
//            if(keys[i] == type) return true;
//        return false;
        return (Arrays.binarySearch(keys, type) >= 0);
    }
    public int TypeChest(int[] chest) {
        return chest[0];
    }
    public int[] KeysInChest(int[] chest) {
        int[] ans = new int[chest[1]];
        for (int i=0; i<chest[1]; i++)
            ans[i] = chest[2+i];
        return ans;
    }
   
    public static void main(String[] args) {
        if (args.length == 0) {
            int[] vec1 =  {1, 1, 1};//{2};//{1};//
            int[][] vec2 = {{1,0}, {1,0},{1,0}};//{{1,1,1}};//{{1, 0}, {1, 2, 1, 3}, {2, 0}, {3, 1, 2}}; //
            Treasure2 blk = new Treasure2(vec1, vec2);
//            StdOut.println(blk.OpenOrNot(vec1, vec2));

//            StdOut.println(blk.OpenSeq());
//            StdOut.println(Arrays.toString(blk.seq));
            StdOut.println(blk.Output());
            return;
        }
        In in = new In(args[0]);
        int T = in.readInt(); // # of test cases
        Out out = new Out(args[0]+".Out");
        for (int i = 0; i < T; i++) {
            int K = in.readInt();
            int N = in.readInt();
            int[] vecKeys = new int[K];
            int[][] vecChests = new int[N][];
            for (int j = 0; j < K; j++) {
                vecKeys[j] = in.readInt();
            }
            in.readLine();
//            StdOut.println(Arrays.toString(vecKeys));
            for (int j = 0; j < N; j++) {
                String[] chestStr = in.readLine().split(" ");
//                StdOut.println(Arrays.toString(chestStr));
                int numKey = Integer.parseInt(chestStr[1]);
                int[] chest = new int[2 + numKey];
                for (int k = 0; k < 2 + numKey; k++) {
                    chest[k] = Integer.parseInt(chestStr[k]);
                }
                vecChests[j] = chest;
            }
            Treasure2 blk = new Treasure2(vecKeys, vecChests);
            
            out.println("Case #" + (i+1) + ": " + blk.Output());
            
            //StdOut.println("Case #" + (i+1) + ": " + msp.MinProd());
        }
        out.close();
    }
}