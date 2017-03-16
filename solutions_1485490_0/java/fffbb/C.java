import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;


public class C {

    public static void main(String[] args) throws Exception {
        if(args.length != 1) {
            return;
        }
        FileInputStream inputStream = new FileInputStream(args[0]);
        InputStreamReader istReader = new InputStreamReader(inputStream);
        BufferedReader buffReader = new BufferedReader(istReader);

        // T
        int T = Integer.valueOf(buffReader.readLine());

        for(int t = 1; t <= T; t++) {
            String[] term = buffReader.readLine().split(" ");
            int N = Integer.valueOf(term[0]);
            int M = Integer.valueOf(term[1]);

            List<Long> anList = new ArrayList<Long>();
            List<Integer> AnList = new ArrayList<Integer>();
            term = buffReader.readLine().split(" ");
            for(int n = 0; n < N; n++) {
                long an = Long.valueOf(term[2 * n]);
                anList.add(an);
                int An = Integer.valueOf(term[2 * n + 1]);
                AnList.add(An);
            }

            List<Long> bnList = new ArrayList<Long>();
            List<Integer> BnList = new ArrayList<Integer>();
            term = buffReader.readLine().split(" ");
            for(int m = 0; m < M; m++) {
                long bn = Long.valueOf(term[2 * m]);
                bnList.add(bn);
                int Bn = Integer.valueOf(term[2 * m + 1]);
                BnList.add(Bn);
            }
            
            System.out.print("Case #" + t + ": ");
            List<Stats> statsList = new ArrayList<C.Stats>();
            statsList.add(new Stats(0, 0, anList.get(0), bnList.get(0), 0));
            long result = 0;
            Set<Stats> resultStats = new HashSet<C.Stats>();
            while(true) {
                List<Stats> nextStats = new ArrayList<C.Stats>();
                while(!statsList.isEmpty()) {
                    Stats target = statsList.remove(0);
                    if(AnList.get(target.n) == BnList.get(target.m)) {
                        // can make present
                        long min = (target.remainan > target.remainbn)?target.remainbn:target.remainan;
                        target.result += min;
                        target.remainan -= min;
                        target.remainbn -= min;
                        if(target.remainan == 0) {
                            target.n++;
                            if(target.n < N) {
                                target.remainan = anList.get(target.n);
                            }
                        }
                        if(target.remainbn == 0) {
                            target.m++;
                            if(target.m < M) {
                                target.remainbn = bnList.get(target.m);
                            }
                        }
                        if((target.n < N) && (target.m < M)) {
                            nextStats.add(target);
                        } else {
                            resultStats.add(target);
                        }
                    } else {
                        // can not make present
                        if(target.n + 1 < N) {
                            nextStats.add(new Stats(target.n + 1, target.m, anList.get(target.n + 1), target.remainbn, target.result));
                        }
                        if(target.m + 1 < M) {
                            nextStats.add(new Stats(target.n, target.m + 1, target.remainan, bnList.get(target.m + 1), target.result));
                        }
                        if(target.n + 1 == N && target.m + 1 == M) {
                            resultStats.add(target);
                        }
                    }
                }
                if(nextStats.isEmpty()) {
                    break;
                }
                statsList = nextStats;
            }
            for(Stats stats:resultStats) {
                if(result < stats.result) {
                    result = stats.result;
                }
            }
            System.out.print(result);
            if(t != T) {
                System.out.println();
            }
        }
    }

    public static class Stats {
        int n = 0;
        int m = 0;
        long remainan = 0;
        long remainbn = 0;
        long result = 0;
        
        public Stats(int n, int m, long remainan, long remainbn, long result) {
            this.n = n;
            this.m = m;
            this.remainan = remainan;
            this.remainbn = remainbn;
            this.result = result;
        }
    }
}
