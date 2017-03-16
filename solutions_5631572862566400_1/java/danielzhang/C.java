package round1A2016;

import utils.FileIO;

import java.io.IOException;
import java.util.*;

public class C {
    public static void main(String[] args) throws IOException {
        FileIO io = new FileIO(C.class);
        C solution = new C();
        int T = Integer.parseInt(io.readLine());

        for (int t = 1; t <= T; t++) {
            int N = io.readInt();

            int[] bff = io.readInts(N);
            for(int i = 0; i < N; i ++){
                bff[i] -= 1;
            }
            int output = solution.solve(N, bff);
            io.writeLineWithHeader(t, output);

        }
        io.close();
    }

    private int solve(int n, int[] bff) {
        Set<Integer> loops = new HashSet<>();
        Set<Integer> chains = new HashSet<>();
        int maxLoop = 0;

        for (int i = 0; i < n; i ++){
            if(!loops.contains(i) && !chains.contains(i)){
                Set<Integer> loop = findLoop(bff, i);
                loops.addAll(loop);
                if(loop.size() > maxLoop){
                    maxLoop = loop.size();
                }
                if(!loops.contains(i) && mutax(bff, i)){
                    Set<Integer> chain = findChain(bff, i);
                    chains.addAll(chain);
                }
            }
        }
        return Math.max(maxLoop, chains.size());
    }

    private Set<Integer> findChain(int[] bff, int i) {
        Set<Integer> set = new HashSet<>();
        set.addAll(findChainTo(bff, i));
        set.addAll(findChainTo(bff, bff[i]));
        return set;
    }

    private Collection<? extends Integer> findChainTo(int[] bff, int i) {
        List<List<Integer>> list = new ArrayList<>();
        List<Integer> set = new ArrayList<>();
        set.add(i);
        list.add(set);
        while (true){
            List<List<Integer>> next = new ArrayList<>();
            for (List<Integer> candidate : list){
                int tail = candidate.get(candidate.size() - 1);
                for (int j = 0; j < bff.length; j ++){
                    if(bff[j] == tail && j != bff[tail]){
                        List<Integer> newCandidate = new ArrayList<>(candidate);
                        newCandidate.add(j);
                        next.add(newCandidate);
                    }
                }
            }
            if(next.size() == 0){
                return list.get(0);
            }
            list = next;
        }
    }

    private Set<Integer> findLoop(int[] bff, int i) {
        Set<Integer> set = new HashSet<>();
        if(mutax(bff, i)){
            return set;
        }
        int head = i;
        while (!set.contains(i)){
            set.add(i);
            i = bff[i];
        }
        if(head == i) {
            return set;
        }else {
            return new HashSet<>();
        }
    }

    private boolean mutax(int[] bff, int i) {
        return bff[bff[i]] == i;
    }
}