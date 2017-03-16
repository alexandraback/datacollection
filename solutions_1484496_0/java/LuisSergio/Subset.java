import java.util.ArrayList;

public class Subset {
    public static ArrayList<ArrayList<Long>> getSubsets(
            ArrayList<Long> set) {

        ArrayList<ArrayList<Long>> subsetCollection = new ArrayList<ArrayList<Long>>();

        if (set.size() == 0) {
            subsetCollection.add(new ArrayList<Long>());
        } else {
            ArrayList<Long> reducedSet = new ArrayList<Long>();

            reducedSet.addAll(set);

            long first = reducedSet.remove(0);
            ArrayList<ArrayList<Long>> subsets = getSubsets(reducedSet);
            subsetCollection.addAll(subsets);

            subsets = getSubsets(reducedSet);

            for (ArrayList<Long> subset : subsets) {
                subset.add(0, first);
            }

            subsetCollection.addAll(subsets);
        }

        return subsetCollection;
    }

}