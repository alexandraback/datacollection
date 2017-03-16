import java.util.*;
public class D{
    static int numBoxes;
    static Scanner s;
    static Stack<Integer> ans;
    static Set<Integer> openlist;
    static boolean flag;
    static List<Integer> keys;
    static Map<Integer, Box> boxes;
    static Map<Integer, Set<Set<Integer>>> used;
    static Set<Integer> state;
    public static void main(String[] args){
        s = new Scanner(System.in);
        keys = new ArrayList<Integer>();
        boxes = new TreeMap<Integer, Box>();
        int cases = s.nextInt();
        for(int i = 1; i <= cases; i++) {
            String result = play();
            System.out.printf("Case #%d:%s\n", i, result);
        }
    }



    public static String play() {
        int nKeys = s.nextInt();
        numBoxes = s.nextInt();
        used = new TreeMap<Integer, Set<Set<Integer>>>();
        for(int i = 1 ; i <= numBoxes; i++) {
            used.put(i, new HashSet<Set<Integer>>());
        }
        for(int i = 0; i < nKeys; i++) {
            keys.add(s.nextInt());
        }

        for(int i = 1; i <= numBoxes; i++) {
            int key = s.nextInt();
            int nContains = s.nextInt();
            boxes.put(i, new Box(key));
            for(int j = 0; j < nContains; j++) {
                boxes.get(i).containedKeys.add(s.nextInt());
            }
            if (boxes.get(i).containedKeys.contains(boxes.get(i).keyhole)) {
                boxes.get(i).repeat = true;
            }
        }

        

        //for(int i = 1; i <= numBoxes; i++) {
        //    System.out.println("box no. " + i + " can be opened with " + boxes.get(i).keyhole + " and contains " + boxes.get(i).containedKeys);
        //}
        
        openlist = new HashSet<Integer>();
        ans = new Stack<Integer>();
        flag = false;
        state = new HashSet<Integer>();

        solve(keys, boxes);
        keys.clear();
        boxes.clear();
        if (flag) {
            String result = "";
            while(!ans.empty()) {
                result = " " + ans.pop() + result;
            }
            return result;
            //return ans.substring(0, ans.length() - 1);
        } else return " IMPOSSIBLE";
    }

    public static void solve(List<Integer> keys, Map<Integer, Box> boxes) {

        for(int i = 1; i <= numBoxes; i++) {
            if(!openlist.contains(i)) {
                Box currBox = boxes.get(i);
                if(keys.contains(currBox.keyhole)) {
                    openlist.add(i);
                    ans.push(i);
                    state.add(i);
                    //System.out.println(ans );
                    if(!used.get(state.size()).contains(state)) {
                        keys.remove((Integer)currBox.keyhole);
                        keys.addAll(currBox.containedKeys);
                        if(openlist.size() == numBoxes) {
                            flag = true;
                            return;
                        }
                        solve(keys, boxes);

                        if(flag)
                            return;
                        //System.out.println("closing " + i);
                        used.get(state.size()).add(new HashSet<Integer>(state));

                        keys.removeAll(currBox.containedKeys);
                        keys.add(currBox.keyhole);
                    } 
                    state.remove(i);
                    ans.pop();
                    openlist.remove((Integer)i);
                }
            }
        }
    }

}
