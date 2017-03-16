import java.io.BufferedReader;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.*;

public class Main
{
    public static void main(String[] args)
            throws Exception
    {
        BufferedReader in = new BufferedReader(new FileReader(args[0]));
        FileWriter out = new FileWriter(args[1]);
        int T = Integer.parseInt(in.readLine());

        for (int t = 1; t <= T; t++)
        {
            String data[] = in.readLine().split("\\ ");
            int A = Integer.parseInt(data[0]);
            int B = Integer.parseInt(data[1]);

            Set<Integer> checked = new LinkedHashSet<Integer>();

            int recycledPairNumber = 0;

            for (int i = A; i <= B; i++)
            {
                if (checked.contains(i))
                    continue;

                String s = Integer.toString(i);
                String ss = s + s;

                Set<Integer> recycled = new LinkedHashSet<Integer>();
                recycled.add(i);
                for (int j = 0; j < s.length(); j++)
                {
                    int candidate = Integer.parseInt(ss.substring(j, j + s.length()));
                    if (candidate >= A && candidate <= B)
                        recycled.add(candidate);
                }

                if (recycled.size() == 1)
                    continue;

                checked.addAll(recycled);

                recycledPairNumber += (recycled.size() * (recycled.size() - 1)) / 2;
            }

            out.write("Case #" + t + ": " + recycledPairNumber + "\n");
        }

        in.close();
        out.close();
    }
}
