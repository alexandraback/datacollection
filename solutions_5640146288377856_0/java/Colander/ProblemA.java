package cj1C;

/**
 *
 * @author colander
 */
public class ProblemA {

    String[] input;

    public static void main(String[] args) {
        new ProblemA();
    }

    public ProblemA() {
        this.input = FileHandlers.FileInput.arrayRead("in.txt");
        for (int i = 1; i < input.length; i++) {
            String[] split = input[i].split(" ");
            System.out.println("Case #" + i + ": " + solve(Integer.parseInt(split[0]), Integer.parseInt(split[1]), Integer.parseInt(split[2])));
        }
    }

    public int solve(int r, int c, int w) {
        int turns = 0;
        turns += (int) r * Math.floor(c / w);
        if (c % w == 0) {
            turns += w - 1;
        } else {
            turns += w;
        }
        return turns;
    }
}
