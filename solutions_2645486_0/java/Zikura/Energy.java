import java.util.Scanner;

public class Energy {
    public static void main(String[] args) {
        new Energy().go();
    }

    private void go() {
        Scanner s = new Scanner(System.in);

        int numCases = s.nextInt();
        for(int c=1;c<=numCases;c++) {
            int maximumEnergy = s.nextInt();
            int regen = s.nextInt();
            int numActivities = s.nextInt();

            int[] activities = new int[numActivities];
            for(int j=0;j<numActivities;j++) {
                activities[j] = s.nextInt();
            }

            int[][] grid = new int[numActivities][maximumEnergy+1];

            for(int i=0;i<=maximumEnergy;i++) {
                grid[0][maximumEnergy-i] = i * activities[0];
            }

            for(int i=1;i<numActivities;i++) {
                for(int j=0;j<=maximumEnergy;j++) {
                    int currentWeight = activities[i];
                    int best = 0;

                    for(int pe=maximumEnergy;pe>=0 && pe >=j-regen;pe--) {
                        int numThisTier = Math.min(maximumEnergy, pe+regen)-j;
                        int temp = grid[i-1][pe] + numThisTier*currentWeight;

                        if(temp>best)
                            best = temp;
                    }

                    grid[i][j] = best;
                }
            }

            System.out.println(String.format("Case #%d: %d", c, grid[numActivities-1][0]));
        }
    }
}
