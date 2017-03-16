package qulifying;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintStream;
import java.util.*;

/**
 * Created with IntelliJ IDEA.
 * User: raggzy
 * Date: 13.04.13
 * Time: 4:16
 * To change this template use File | Settings | File Templates.
 */
public class ProblemD {

    static class Solver {
        Keys startKeys;
        Chest[] chests;
        State[] states;
        int statesCount;

        Solver(Keys startKeys, Chest[] chest) {
            this.startKeys = startKeys;
            this.chests = chest;
            this.statesCount = (int) Math.pow(2, chests.length);
            this.states = new State[statesCount];
        }

        List<Integer> solve() {
            states[0] = new State();
            states[0].fromState = 0;
            states[0].chestIndex = -1;
            //
            for (int i = 1; i < statesCount; i++) {
                solveState(i);
            }
            return stateSequence(statesCount - 1);
        }

        void solveState(int stateCode) {
            states[stateCode] = new State();
            int test = 1;
            int chestIndex = 0;
            while (test <= stateCode) {
                int fromCode = ~test & stateCode;
                if (fromCode != stateCode) {
                    setFromState(stateCode, fromCode, chestIndex);
                }
                test = test << 1;
                chestIndex++;
            }
        }

        State s(int stateCode) {
            return states[stateCode];
        }

        Chest c(int chestIndex) {
            return chests[chestIndex];
        }

        void setFromState(int stateCode, int fromCode, int chestIndex) {
            if (s(fromCode).fromState >= 0 && stateKeys(fromCode).canOpen(c(chestIndex))) {
                if (s(stateCode).fromState < 0) {
                    s(stateCode).fromState = fromCode;
                    s(stateCode).chestIndex = chestIndex;
                } else {
                    List<Integer> currSeq = stateSequence(stateCode);
                    List<Integer> fromSeq = stateSequence(fromCode);
                    fromSeq.add(c(chestIndex).num);
                    if (firstIsLexSmaller(fromSeq, currSeq)) {
                        s(stateCode).fromState = fromCode;
                        s(stateCode).chestIndex = chestIndex;
                    }
                }
            }
        }

        Keys stateKeys(int stateCode) {
            Keys result = new Keys();
            result.takeFrom(startKeys);
            State state = states[stateCode];
            while (state.chestIndex >= 0) {
                result.open(c(state.chestIndex));
                state = states[state.fromState];
            }
            return result;
        }

        List<Integer> stateSequence(int stateCode) {
            State state = states[stateCode];
            LinkedList<Integer> result = new LinkedList<Integer>();
            while (state.chestIndex >= 0) {
                result.addFirst(c(state.chestIndex).num);
                state = states[state.fromState];
            }
            return result;
        }

        static boolean firstIsLexSmaller(List<Integer> first, List<Integer> second) {
            Iterator<Integer> it1 = first.iterator();
            Iterator<Integer> it2 = second.iterator();
            if (first.size() != second.size()) {
                throw new RuntimeException("OLALA");
            }
            int num1 = -1;
            int num2 = -1;
            while (it1.hasNext() && it2.hasNext()) {
                num1 = it1.next();
                num2 = it2.next();
                if (num1 != num2) break;
            }
            return num1 < num2;
        }
    }

    static class State {
        int fromState = -1;
        int chestIndex = -1;
    }

    public static final int MAX_KEY_TYPE = 200;

    static class Keys {
        int[] countPerType = new int[1 + MAX_KEY_TYPE];

        boolean canOpen(Chest chest) {
            return countPerType[chest.keyTypeToOpen] > 0;
        }

        void addKey(int type) {
            countPerType[type]++;
        }

        void removeKey(int type) {
            countPerType[type]--;
        }

        void takeFrom(Keys other) {
            System.arraycopy(other.countPerType, 0, countPerType, 0, countPerType.length);
        }

        void open(Chest chest) {
            removeKey(chest.keyTypeToOpen);
            for (int keyInside : chest.keyTypesInside) {
                addKey(keyInside);
            }
        }
    }

    static class Chest {
        int keyTypeToOpen;
        List<Integer> keyTypesInside = new ArrayList<Integer>();
        int num;

        Chest(int keyTypeToOpen, int num) {
            this.keyTypeToOpen = keyTypeToOpen;
            this.num = num;
        }

        void putInsideKey(int keyType) {
            keyTypesInside.add(keyType);
        }
    }

    static String toString(List<Integer> result) {
        StringBuilder sb = new StringBuilder();
        if (result.size() > 0) {
            for (Integer chestNum : result) {
                sb.append(" ").append(chestNum);
            }
        } else {
            sb.append(" IMPOSSIBLE");
        }
        return sb.toString();
    }

    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new FileInputStream("C:/Temp/gcj/d-in.txt"));
        PrintStream out = new PrintStream(new FileOutputStream("C:/Temp/gcj/d-out.txt"));
        int T = in.nextInt();
        for (int i = 0; i < T; i++) {
            int K = in.nextInt();
            int N = in.nextInt();
            //
            Keys startKeys = new Keys();
            for (int j = 0; j < K; j++) {
                startKeys.addKey(in.nextInt());
            }
            //
            Chest[] chests = new Chest[N];
            for (int j = 0; j < N; j++) {
                Chest chest = new Chest(in.nextInt(), j + 1);
                int Ki = in.nextInt();
                for (int c = 0; c < Ki; c++) {
                    chest.putInsideKey(in.nextInt());
                }
                chests[j] = chest;
            }

            out.println(String.format("Case #%d:%s", i + 1, toString(new Solver(startKeys, chests).solve())));
            System.out.println(String.format("Test case %d / %d", i + 1, T));
        }
        in.close();
        out.close();
    }
}
