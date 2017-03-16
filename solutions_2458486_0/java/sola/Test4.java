import java.io.*;
import java.util.*;


public class Test4 {
    public static class Chest {
        public int keyReq;
        public int id;
        public int[] keysIn;
        public String s;
        public Chest (int id, int keyReq, int[] keys, String s) {
            this.id = id;
            this.keyReq = keyReq;
            this.keysIn = keys;
            this.s = s;
        }
        
        @Override
        public String toString () {
            return s;
        }
    }
    
    public static class Move {
        public State curState;
        public Move prevMove;
        public Chest last;
        public String path;
        public Move (State state, Move prev, Chest last) {
            this.curState = state;
            this.prevMove = prev;
            this.last = last;
            if (last!=null)
                this.path = prev.path.concat(" " + last.id);
            else this.path = "";
        }
        
        public List<Move> getNextMoves () {
            List<Move> states = new LinkedList<Move>();
            State s = curState;
            Iterator<Chest> iterator = s.chests.listIterator(1);
            while (iterator.hasNext()){
                Chest chest = iterator.next();
                if (s.keys[chest.keyReq]>0) {
                    int[] newKeys = Arrays.copyOf(s.keys,s.keys.length);
                    newKeys[chest.keyReq]--;
                    for (int key:chest.keysIn) {
                        newKeys[key]++;
                    }
                    List<Chest> newChests = new LinkedList<Chest>(s.chests);
                    newChests.remove(chest);
                    states.add(new Move(new State(newKeys,newChests),this,chest));
                }
            }
            return states;
        }
        
        @Override
        public boolean equals (Object obj) {
            if (obj.getClass()!=this.getClass()) {
                return false;
            }
            State state = ((Move)obj).curState;
            return curState.keys.equals(state.keys) && curState.chests.equals(state.chests);
        }
    }
    
    public static class State {
        public int[] keys;
        public List<Chest> chests;
        public int nChests;
        public String path;
        
        public State (int[] keys, List<Chest> chests) {
            this.keys = keys;
            this.chests = chests;
        }
        
        public boolean isGoal () {
            return this.chests.size()==1;
        }
        
        @Override
        public boolean equals (Object obj) {
            if (obj.getClass()!=this.getClass()) {
                return false;
            }
            State state = (State) obj;
            return keys.equals(state.keys) && chests.equals(state.chests);
        }
        
        
        
        public List<Chest> getAvailChests () {
            List<Chest> ret = new LinkedList<Chest>();
            Iterator<Chest> iterator = chests.listIterator(1);
            while (iterator.hasNext()){
                Chest chest = iterator.next();
                if (keys[chest.keyReq]>0) {
                    ret.add(chest);
                }
            }
            return ret;
        }
        
        public List<Chest> getUnavailChests () {
            List<Chest> ret = new LinkedList<Chest>();
            Iterator<Chest> iterator = chests.listIterator(1);
            while (iterator.hasNext()){
                Chest chest = iterator.next();
                if (keys[chest.keyReq]==0) {
                    ret.add(chest);
                }
            }
            return ret;
        }
        
        public int getAvailChestsN () {
            int cnt = 0;
            Iterator<Chest> iterator = chests.listIterator(1);
            while (iterator.hasNext()){
                Chest chest = iterator.next();
                if (keys[chest.keyReq]>0) {
                    cnt++;
                }
            }
            return cnt;
        }
        
        public String getKeys () {
            String ret = "";
            for (int k=0;k<201;k++) {
                if (keys[k]>0) {
                    ret += k + ": " + keys[k] + ", ";
                }
            }
            return ret;
        }
    }
    
    
    
    final static String WORK_DIR = "C:\\Users\\Sola\\Desktop\\";
    static Chest[] chestsList;
    public static void main (String[] args) throws IOException {
        
        Scanner sc = new Scanner(new FileReader(WORK_DIR + "4.in"));
        PrintWriter pw = new PrintWriter(new FileWriter(WORK_DIR + "4.out"));
        int tc = sc.nextInt();
        for (int tci=1;tci<=tc;tci++) {
            System.out.println(tci);
            int numKeys = sc.nextInt();
            int numChests = sc.nextInt();
            int[] keys = new int[201];
            Arrays.fill(keys,0);
            chestsList = new Chest[numChests+1];
            for (int i=0;i<numKeys;i++) {
                keys[sc.nextInt()]++;
            }
            for (int i=1;i<=numChests;i++) {
                String s = "[";
                int keyReq = sc.nextInt();
                int nKeysIn = sc.nextInt();
                int[] keysIn = new int[nKeysIn];
                s += i + ": "+ keyReq + ", ";
                for (int j=0;j<nKeysIn;j++) {
                    keysIn[j] = sc.nextInt();
                    s += keysIn[j] + " ";
                }
                
                chestsList[i]=new Chest(i,keyReq,keysIn,s);
            }
            
            List<Chest> iniChestsList = new LinkedList<Chest>(Arrays.asList(chestsList));
            if (enoughKeys(iniChestsList, keys)) {
                Move curMove;
                String curPath,finalPath=null;
                PriorityQueue<Move> queue = new PriorityQueue<Move>(1000,new MoveComparator());
                //Stack<String> path = new Stack<String>();
                queue.add(new Move(new State(keys,iniChestsList),null,null));
                //path.push("");
                ArrayList<State> visited = new ArrayList<State>();
                boolean found = false;
                while(queue.size()>0 && !found) {
                    curMove = queue.poll();
                    //curPath = path.pop();
                    visited.add(curMove.curState);
                    /*
                    System.out.println("Keys: " + curState.getKeys());
                    System.out.println("Total chests: " + curState.chests.size());
                    System.out.println("Chests keys: " + curState.getAvailChests());
                    System.out.println("Chests without keys: " + curState.getUnavailChests());
                    */
                    if (curMove.curState.isGoal()) {
                        finalPath = curMove.path;
                        break;
                    }
                    
                    List<Move> nextMoves = curMove.getNextMoves();
                    //ArrayList<Integer> chestIndices = curState.getAvailChests();
                    ListIterator<Move> iterator = nextMoves.listIterator(nextMoves.size());
                    while (iterator.hasPrevious()) {
                        Move nextMove = iterator.previous();
                        if (!visited.contains(nextMove.curState)) {
                            if (!enoughKeys(nextMove.curState.chests,nextMove.curState.keys)) visited.add(nextMove.curState);
                            else
                            //path.push(curPath + " " + chestIndices.get(nextStates.indexOf(nextState)));
                            queue.add(nextMove);
                        }
                    }
                }
                
                pw.print("Case #" + tci + ":");
                if (finalPath==null) pw.print(" IMPOSSIBLE");            
                else pw.print(finalPath);
                if (tci<tc) pw.println();
            }
            else {
                pw.print("Case #" + tci + ": IMPOSSIBLE");
                if (tci<tc) pw.println();
            }
        }
        sc.close();
        pw.flush();
        pw.close();
    }
    
    public static class MoveComparator implements Comparator<Move> {

        @Override
        public int compare(Move m1, Move m2) {
            // TODO Auto-generated method stub
            if (m1.curState.equals(m2.curState)) return 0;
            int v1 = rValueOf (m1);
            int v2 = rValueOf (m2);
            if (v1==v2) return 0;
            else if (v1>v2) return 1;
            else return -1;
        }
    }
    
    public static int rValueOf (Move m) {
        State state = m.curState;
        if (state.isGoal()) return Integer.MIN_VALUE;
        else if (!enoughKeys(state.chests,state.keys)) return Integer.MAX_VALUE;
        List<Chest> list = state.chests;
        ListIterator<Chest> iterator = list.listIterator(1);
        int[] keysNeed = new int[201];
        while (iterator.hasNext()) {
            Chest chest = iterator.next();
            keysNeed[chest.keyReq]++;
        }
        int ret = 5*state.chests.size()+m.last.id;
        
        return ret;
    }
    
    public static boolean enoughKeys (List<Chest> chests,int[] keys) {
        int [] keysNeed = new int[201];
        Arrays.fill(keysNeed, 0);
        int [] keysAvail = new int[201];
        Arrays.fill(keysAvail, 0);
        
        for (int k=1;k<201;k++) {
            keysAvail[k] += keys[k];
        }
        
        ListIterator<Chest> iterator = chests.listIterator(1);
        while (iterator.hasNext()) {
            Chest chest = iterator.next();
            
            boolean selfContained = false;
            for (int k=0;k<chest.keysIn.length;k++) {
                if (!selfContained && chest.keysIn[k]==chest.keyReq) {
                    selfContained = true;
                }
                else keysAvail[chest.keysIn[k]]++;
            }
            if (!selfContained || keysAvail[chest.keyReq]==0) {
                keysNeed[chest.keyReq]++;
            }
        }
        for (int k=1;k<201;k++) {
            if (keysAvail[k]<keysNeed[k]) {
                return false;
            }
        }
        return true;
    }
}