import com.google.common.collect.*;
import com.google.common.primitives.Ints;

import java.util.*;

public
class ProblemC implements ProblemRunner.Problem
{
    private int n;
    private int m;
    private int k;
    private int[][] products ;


    public
    void parse(Scanner scanner)
    {
        int r = scanner.nextInt();
        n = scanner.nextInt();
        m = scanner.nextInt();
        int k = scanner.nextInt();

        products = new int[r][k];
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < k; j++)
            {
                products[i][j] = scanner.nextInt();
            }
        }
    }

    public
    String solve()
    {
        System.out.println("n = " + n);
        System.out.println("m = " + m);
        System.out.println("products = " + Arrays.deepToString(products));

        String res = "\n";

        Random random = new Random();
        for (int[] product : products)
        {
            Set<Set<Multiset<Integer>>> allPosibilities = Sets.newHashSet();
            for (int p : product)
            {
                Set<Multiset<Integer>> posibilities = new HashSet<Multiset<Integer>>();
                final HashMultiset<Integer> prefix = HashMultiset.create();
                divisibility(p, posibilities, prefix);

                allPosibilities.add(posibilities);
            }

            System.out.println("allPosibilities = " + allPosibilities);

            Multiset<Integer> known = HashMultiset.create();
            boolean keepRemoving = true;
            while(keepRemoving)
            {
                System.out.println("known = " + known);
                keepRemoving=false;
                for (Set<Multiset<Integer>> allPosibility : allPosibilities)
                {
                    for (Iterator<Multiset<Integer>> iterator = allPosibility.iterator(); iterator.hasNext(); )
                    {
                        final Multiset<Integer> allPos = iterator.next();
                        System.out.println("known = " + known);
                        if(Multisets.difference(allPos, known).size() > n-allPos.size())
                        {
                            System.out.println("allPos = " + allPos);
                            iterator.remove();
                            keepRemoving = true;
                        }
                    }

                    if(allPosibility.size() == 1)
                    {
                        final int size = known.size();
                        known = Multisets.union(known, allPosibility.iterator().next());
                        if(known.size()> size)
                            keepRemoving = true;
                    }
                }
            }

            System.out.println("allPosibilities = " + allPosibilities);
            for (Integer integer : known)
            {
                res += integer;
            }

            for (int i = 0; i < n-known.size(); i++)
            {
                res += random.nextInt(m-2) + 2;
            }

            res+="\n";
            //System.out.println("known = " + known);
            //System.out.println("allPosibilities = " + allPosibilities);
            //
            //for (Iterator<Multiset<Integer>> iterator = allPosibilities.iterator(); iterator.hasNext(); )
            //{
            //    final Multiset<Integer> allPosibility = iterator.next();
            //    if(!Multisets.containsOccurrences(allPosibility, known))
            //    {
            //        iterator.remove();
            //        continue;
            //    }
            //}
            //System.out.println("allPosibilities = " + allPosibilities);
            //
            //List<Multiset<Integer>> list = new ArrayList<Multiset<Integer>>(allPosibilities);
            //
            //Collections.sort(list, new Comparator<Multiset<Integer>>()
            //{
            //    @Override
            //    public
            //    int compare(final Multiset<Integer> o1, final Multiset<Integer> o2)
            //    {
            //        return Ints.compare(o2.size(), o1.size());
            //    }
            //});
            //
            //System.out.println("list = " + list);
            //System.out.println("posibilities = " + posibilities);
            //final List<Integer> integers = posibilities.get(0);
            //for (Integer integer : integers)
            //{
            //    res += integer;
            //}
            //


            //res+="\n";

        }


        return res;
    }

    private
    void divisibility(final int p, final Set<Multiset<Integer>> posibilities, Multiset<Integer> prefix)
    {
        //System.out.println("prefix = " + prefix);
        for (int i = 2; i <= m; i++)
        {
            if(p%i == 0)
            {
                //System.out.println("p = " + p);
                //System.out.println("i = " + i);

                Multiset<Integer> nextList = HashMultiset.create(prefix);
                nextList.add(i);
                int subP = p/i;

                if(subP == 1)
                {
                    posibilities.add(nextList);
                }
                if(nextList.size() == n)
                {
                    return;
                }
                else
                {
                    divisibility(subP, posibilities, nextList);
                }


            }
        }


    }

    public static
    void main(String[] args) throws Exception
    {
        ProblemRunner.run(args, ProblemC.class, 0);
    }

}
