import java.io.BufferedReader;
import java.io.FileInputStream;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;

public class B implements Comparable<B> {
    int l2;
    int l1;
    int numCompleted;
    
    public B(int l1, int l2) {
        this.l2 = l2;
        this.l1 = l1;
        this.numCompleted = 0;
    }

    @Override
    public int compareTo(B arg0) {
        return (l2 == arg0.l2 ? l1 - arg0.l1 : (l2 - arg0.l2));
    }
    
    
	public static void main(String[] args) throws NumberFormatException, IOException {
			// Use scanner! Good for reading in bigints too.
			// Arrays.fill for initialising arrays
			// Look up cumulative frequency tables (only for dynamic querying with new numbers coming in)
		BufferedReader reader = new BufferedReader(new InputStreamReader(new FileInputStream("in.in")));
		PrintStream writer = new PrintStream(new FileOutputStream("out.out"));
		int cases = Integer.parseInt(reader.readLine());
		for (int i = 1; i <= cases; i++) {
            int numLevels = Integer.parseInt(reader.readLine());
            ArrayList<B> levels = new ArrayList<B>(numLevels);
            for (int j = 0; j < numLevels; j++) {
                String[] tokens = reader.readLine().split(" ");
                levels.add(new B(Integer.parseInt(tokens[0]), Integer.parseInt(tokens[1])));
            }
            Collections.sort(levels, Collections.reverseOrder());
            int played = 0;
            int stars = 0;
            boolean playable = true;
            while (numLevels > 0) {
                boolean found = false;
                for (int j = 0; j < levels.size(); j++) {
                    if ((levels.get(j).numCompleted < 2) && (levels.get(j).l2 <= stars)) {
                        found = true;
                        played++;
                        stars += (2 - levels.get(j).numCompleted);
                        levels.get(j).numCompleted = 2;
                        numLevels--;
                        break;
                    }
                }
                if (found == true) {
                    continue;
                }
                for (int j = 0; j < levels.size(); j++) {
                    if ((levels.get(j).numCompleted < 1) && (levels.get(j).l1 <= stars)) {
                        found = true;
                        played++;
                        stars += (1 - levels.get(j).numCompleted);
                        levels.get(j).numCompleted = 1;
                        break;
                    }
                }
                if (found == false) {
                    playable = false;
                    break;
                }
            }
            if (playable) {
                writer.printf("Case #%d: %d\n", i, played);
            } else {
                writer.printf("Case #%d: Too Bad\n", i);
            }
		}
	}
	
}
