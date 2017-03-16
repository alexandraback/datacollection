import java.io.*;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

/**
 * Created by noMoon on 2015-05-02.
 */
public class CounterCulture {
    public static class Node {
        int number;
        int depth;
    }

    public static void main(String[] args) throws IOException {
//        System.out.println(reverse(19));

        File file = new File("A-small-attempt1.in.txt");
//        File file = new File("CounterCulture.in");
        File outputFile = new File("CounterCulture.out");
        BufferedWriter bw = new BufferedWriter(new FileWriter(outputFile));
        BufferedReader br = new BufferedReader(new InputStreamReader(
                new FileInputStream(file)));
        int numberOfTestCases = Integer.valueOf(br.readLine());
        int count = 0;
        while (count++ < numberOfTestCases) {
            System.out.println(count);
            int n = Integer.valueOf(br.readLine());
            List<Node> list = new ArrayList<Node>();
            Map<Integer,Integer> numbers=new HashMap<Integer,Integer>();
            numbers.put(1,1);
            Node current = new Node();
            current.number = 1;
            current.depth = 1;
            list.add(current);
            mainloop:
            while (current.number != n) {
                Node node1 = new Node();
                node1.number = current.number + 1;
                node1.depth = current.depth + 1;
                if(node1.number==n){
                    current=node1;
                    break mainloop;
                }
                if(!numbers.containsKey(node1.number)){
                    numbers.put(node1.number,1);
                    list.add(node1);
                }

                int r = reverse(current.number);
                if (r > current.number && r<=n && !numbers.containsKey(r)) {
                    numbers.put(r,1);
                    Node node2 = new Node();
                    node2.number = r;
                    node2.depth = current.depth + 1;
                    list.add(node2);
                    if(node2.number==n){
                        current =node1;
                        break mainloop;
                    }
                }
                list.remove(0);
                current = list.get(0);
//                System.out.println(current.number);
            }

            bw.write("Case #" + String.valueOf(count) + ": " + String.valueOf(current.depth));
            bw.newLine();
        }

        bw.close();
        br.close();
    }

    public static int reverse(int a) {
        if (a < 10) return a;
        int temp = a;
        int mod = a % 10;
        while (mod == 0) {
            temp /= 10;
            mod = temp % 10;
        }
        int result = mod;
        while (temp >= 10) {
            temp /= 10;
            result = result * 10 + temp % 10;
        }
        return result;
    }
}
