import java.io.*;

public class HikingDeer {
    private static int[] D = new int[1001];
    private static int[] H = new int[1001];
    private static int[] M = new int[1001];
    public static void main(String[] args) throws Exception {
        String filename = "C-small-1-attempt1.in";
        File file = new File("/Users/tanin/Downloads/" + filename);
        File outFile = new File("/Users/tanin/Downloads/" + filename + ".out");
        BufferedReader br = new BufferedReader(new FileReader(file));
        BufferedWriter bw = new BufferedWriter(new FileWriter(outFile));
        int testCases = Integer.parseInt(br.readLine());
        for(int t=1;t<=testCases;t++){
            int N = Integer.parseInt(br.readLine());


            for (int n=0;n<N;n++) {
                String[] tokens = br.readLine().split(" ");
                D[n] = Integer.parseInt(tokens[0]);
                H[n] = Integer.parseInt(tokens[1]);
                M[n] = Integer.parseInt(tokens[2]);
            }

            int result = solve(N, D, H, M);
            System.out.println("Case #" + t + ": " + result + "\n");
            bw.write("Case #" + t + ": " + result + "\n");
        }
        br.close();
        bw.close();
    }

    private static int solve(int N, int[] D, int[] H, int[] M) {
        int minNumEncounters = Integer.MAX_VALUE;

        for (int n=0;n<N;n++) {
            for (int h=0;h<H[n];h++) {
                int thisNumEncounters = calculateNumEncounters(n, h, N, D, H, M);

                if (thisNumEncounters < minNumEncounters) {
                    minNumEncounters = thisNumEncounters;
                }
            }
        }

        return minNumEncounters;
    }

    // we follow selectedN,selectedH
    private static int calculateNumEncounters(int selectedN, int selectedH, int N, int[] D, int[] H, int[] M) {
        double totalTimes = timePerLoop(selectedN, selectedH, M) * D[selectedN] / 360;

        int thisNumEncounters = 0;

        for (int n=0;n<N;n++) {
            for (int h = 0; h < H[n]; h++) {
                if (n == selectedN && h == selectedH) {
                    continue;
                }

                double thisPerLoop = timePerLoop(n, h, M);
                double thisToEnd = thisPerLoop * D[n] / 360;
                System.out.println("Time " + n + " " + h  + " = " + (int)thisPerLoop + " " + (int)thisToEnd);

                if (thisToEnd >= totalTimes) { // it is slower, therefore, we must pass it.
                    thisNumEncounters++;
                    System.out.println("slower ");
                } else {
                    System.out.println(((totalTimes - thisToEnd) / thisPerLoop) + " " + totalTimes);
                    long moreEncounter = (long) ((totalTimes - thisToEnd) / thisPerLoop);
                    System.out.println("More " + moreEncounter);
                    thisNumEncounters += moreEncounter;
                }
            }
        }

        System.out.println("Follow " + selectedN + " " + selectedH  + " = " + thisNumEncounters);

        return thisNumEncounters;
    }

    private static double timePerLoop(int n, int h, int[] M) {
        return M[n] + h;
    }
}
