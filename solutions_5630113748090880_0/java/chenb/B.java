import com.google.common.base.Enums;
import com.google.common.base.Joiner;
import com.google.common.base.Optional;
import com.google.common.base.Predicate;
import com.google.common.collect.Collections2;
import com.google.common.collect.FluentIterable;
import com.google.common.collect.ForwardingObject;
import com.google.common.math.IntMath;
import com.google.common.primitives.Ints;
import com.sun.istack.internal.Nullable;

import java.util.*;


public class Main {

    public static void main(String... args) {
        Main a = new Main();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {
            int rowCount = scanner.nextInt();
            List<Integer> heights = new ArrayList();
            for(int j=0; j< 2*rowCount-1; j++) {
                for(int k=0; k< rowCount; k++) {
                    int num = scanner.nextInt();
                    heights.add(num);
                }
            }

            String result = a.solve(heights);
            System.out.println(String.format("Case #%d: %s", i+1, result));
        }
    }


    public String solve(List<Integer> heights) {
        final Map<Integer, Integer> counts = new HashMap<Integer, Integer>();
        for(int height: heights) {
            if(counts.containsKey(height)) {
                counts.put(height, counts.get(height) + 1);
            } else {
                counts.put(height, 1);
            }
        }
        return Joiner.on(' ').join(FluentIterable.from(counts.keySet())
                .filter(new Predicate<Integer>() {
                    @Override
                    public boolean apply(java.lang.Integer integer) {
                        return counts.get(integer) % 2 != 0;
                    }
                }).toSortedList(new Comparator<Integer>() {
            @Override
            public int compare(Integer o1, Integer o2) {
                return o1 - o2;  //To change body of implemented methods use File | Settings | File Templates.
            }
        }));
    }




}