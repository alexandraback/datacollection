import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

class Item {
    long num;
    long type;

    Item(long num, long type) {
        this.num = num;
        this.type = type;
    }

    @Override
    public String toString() {
        return "{" +
                "num=" + num +
                ", type=" + type +
                '}';
    }
}

public class Box {
    public static void main(String[] args) {
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
            int t = Integer.parseInt(br.readLine());
            for (int i = 0; i < t; i++) {
                System.out.println("Case #" + (i + 1) + ": " + find(br));
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    private static long find(BufferedReader br) throws IOException {
        String[] s = br.readLine().split(" ");
        int n = Integer.parseInt(s[0]);
        int m = Integer.parseInt(s[1]);
        Item[] boxes = new Item[n];
        Item[] toys = new Item[m];

        s = br.readLine().split(" ");
        for(int i = 0; i < n; i++) {
            boxes[i] = new Item(Long.parseLong(s[2*i]), Integer.parseInt(s[2*i+1]));
        }
        s = br.readLine().split(" ");
        for(int i = 0; i < m; i++) {
            toys[i] = new Item(Long.parseLong(s[2*i]), Integer.parseInt(s[2*i+1]));
        }
        return find(boxes, toys, n-1, m-1);
    }

    private static long find(Item[] boxes, Item[] toys, int i, int j) {
        if (i==-1 || j == -1) return 0;
        if (boxes[i].type == toys[j].type) {
            if (boxes[i].num > toys[j].num) {
                long used = toys[j].num;
                boxes[i].num -= used;
                toys[j].num -= used;
                long r = find(boxes, toys, i, j-1);
                boxes[i].num += used;
                toys[j].num += used;
                return used + r;
            } else {
                long used = boxes[i].num;
                boxes[i].num -= used;
                toys[j].num -= used;
                long r =find(boxes, toys, i-1, toys[j].num == 0 ? j-1 : j);
                boxes[i].num += used;
                toys[j].num += used;
                return used + r;
            }
        } else return Math.max(find(boxes, toys, i-1, j), find(boxes, toys, i, j-1));
    }

}
