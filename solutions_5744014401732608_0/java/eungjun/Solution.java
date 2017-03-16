import java.util.*;

public class Solution {
    public static void main(String[] args) {
        Solver solver = new Solver();
        solver.solve();
    }
}

class Solver {

    int traverse(boolean[][] slides, int goal, Queue<Integer> q) {
        int cnt = 0;
        for(int i = 0; i < slides.length; i++) {
            if (q.size() == 0) {
                break;
            }
            Queue<Integer> nq = new LinkedList<>();
            while(q.size() > 0) {
                int p = q.poll();
                if (p == goal) {
                    cnt++;
                } else {
                    for (int j = 0; j < slides[p].length; j++) {
                        if (slides[p][j]) {
                            nq.add(j);
                        }
                    }
                }
            }
            q = nq;
        }
        return cnt;
    }

    boolean fulfill(boolean[][] slides, int m) {
        // graph 탐색
        // 점1에서 끝점에 도달할 수 있는 경로의 갯수 합계
        // (사실 한 점이기만 하면 무슨 점이든 상관은 없다)

        // 중복만 피하면 된다.
        //
        // 순환이 있다고 무조건 실패인 것은 아니라는게 어렵다.
        // 순환이 출발점과 목적지를 모두 연결한 경우에만 실패다.
        // 무조건 BFS로 하면 순환은 문제가 안된다.
        // 
        // 문제가 아예 안되는 건 아니고... 
        //
        // 순환이 있는 경우
        // 1. 순환이 start와 goal을 잇는 경우: 무조건 실패
        // 2. 잇지 않는 경우
        //
        // node 만큼 BFS를 하고,
        // 그러고도 남아있는 것은 모두 loop이다.
        // node 만큼 다시 한번 BFS를 시도하고
        // 만약 goal을 방문한다면 무조건 실패
        // 아니라면 성공
        // 그 시점에서 남아있는 것은 모두 loop이다.
        int goal = slides.length - 1;
        Queue<Integer> q = new LinkedList<>();
        q.add(0);
        int cnt = traverse(slides, goal, q);
        int loop = traverse(slides, goal, q);

        if (loop > 0) {
            return false;
        }

        return cnt == m;
    }

    List<List<Boolean>> gen(int p, int size, int itemSize) {
        List<List<Boolean>> result = new ArrayList<>();

        if (p >= size) {
            result.add(new ArrayList<Boolean>());
            return result;
        }

        List<List<Boolean>> gs = gen(p + 1, size, itemSize);

        int i = 0;
        for (List<Boolean> g : gs) {
            if ((p < size - itemSize) && // 마지막 node에는 true가 필요없다.
                (p / itemSize < p % itemSize)) { // 나에게 가는 것은 의미없다. 왕복도 의미없다.
                List<Boolean> ng1 = new ArrayList<>();
                ng1.add(true);
                ng1.addAll(g);
                result.add(ng1);
            }
            
            List<Boolean> ng2 = new ArrayList<>();
            ng2.add(false);
            ng2.addAll(g);
            result.add(ng2);
        }

        System.err.println(result.size());

        return result;
    }

    String toString(boolean[][] s) {
        String result = "";
        for(int i = 0; i < s.length; i++) {
            String line = "";
            for(int j = 0; j < s.length; j++) {
                if (s[i][j] == true) {
                    line += "1";
                } else {
                    line += "0";
                }
            }
            result += line + "\n";
        }
        return result;
    }

    String solve(int b, int m) {
        // edge를 모두 연결해보고
        // 조건에 맞는 것이 있으면 반환 아니면 impossible
        // 몽땅 traverse
        // 2^12=4096 충분하다
        // 2^36인가??

        System.err.printf("b: %d%n", b);
        List<List<Boolean>> slidess = gen(0, b * b, b);

        String result = "";
        
        for(List<Boolean> slides : slidess) {
            boolean[][] s = new boolean[b][b];
            for(int i = 0; i < b; i++) {
                for(int j = 0; j < b; j++) {
                    s[i][j] = slides.get(i * b + j);
                }
            }
            if (fulfill(s, m)) {
                result += "POSSIBLE\n";
                result += toString(s);
                return result;
            }
        }

        return "IMPOSSIBLE";
    }

    void solve() {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int j = 0; j < t; j++) {
            int b = sc.nextInt();
            int m = sc.nextInt();
            System.out.printf("Case #%d: %s%n", j + 1, solve(b, m));
        }
    }
}
