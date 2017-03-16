package googlecodejam.lawnmower;

public class Lawn {

    int N;
    int M;
    int[][] grass;
    int[][] pattern;

    public Lawn(int[][] pattern) {
        this.pattern = pattern;
        N = pattern.length;
        M = pattern[0].length;
        this.grass = new int[N][M];
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                grass[i][j] = 100;
            }
        }
        shapeH();
        shapeV();
    }

    private void shapeH() {
        for (int i = 0; i < N; i++) {
            int maxHeight = findPatternMaxH(i);
            for (int j = 0; j < M; j++) {
                if (grass[i][j] > maxHeight) {
                    grass[i][j] = maxHeight;
                }
            }
        }

    }

    private void shapeV() {
        for (int j = 0; j < M; j++) {
            int maxHeight = findPatternMaxV(j);
            for (int i = 0; i < N; i++) {
                if (grass[i][j] > maxHeight) {
                    grass[i][j] = maxHeight;
                }
            }
        }
    }

    private int findPatternMaxH(int i) {
        int max = 0;
        for (int j = 0; j < M; j++) {
            if (pattern[i][j] > max) {
                max = pattern[i][j];
            }
        }
        return max;
    }

    private int findPatternMaxV(int j) {
        int max = 0;
        for (int i = 0; i < N; i++) {
            if (pattern[i][j] > max) {
                max = pattern[i][j];
            }
        }
        return max;
    }

    private boolean isPatternAchieved() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (grass[i][j] != pattern[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

    @Override
    public String toString() {
        if (isPatternAchieved()) {
            return "YES";
        }
        return "NO";
    }
}
