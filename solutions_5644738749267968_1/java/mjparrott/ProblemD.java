// Deceitful War
import java.util.Scanner;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.ListIterator;
import java.util.List;
import java.util.Iterator;
public class ProblemD
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);

        int t = in.nextInt();
        for(int i = 0; i < t; i++)
        {
            int n = in.nextInt();
            double[] naomi = new double[n];
            double[] ken = new double[n];

            for(int j = 0; j < n; j++)
            {
                naomi[j] = in.nextDouble();
            }
            for(int j = 0; j < n; j++)
            {
                ken[j] = in.nextDouble();
            }

            Arrays.sort(naomi);
            Arrays.sort(ken);

            int maxWar = 0;
            LinkedList<Double> kenL = new LinkedList<Double>();
            LinkedList<Double> naomiL = new LinkedList<Double>();
            for(int j = 0; j < n; j++)
            {
                kenL.addLast(ken[j]);
                naomiL.addLast(naomi[j]);
            }

            for(int j = 0; j < n; j++)
            {
                // pick largest for naomi
                double nPick = naomiL.removeFirst();
                double kPick = -2.0;
                ListIterator li = kenL.listIterator(0);
                while(li.hasNext())
                {
                    double val = (Double)li.next();
                    if(val > nPick)
                    {
                        kPick = val;
                        li.remove();
                        break;
                    }
                }
                if(kPick < -1.0)
                {
                    kPick = kenL.removeFirst();
                }

                if(nPick > kPick)
                    maxWar++;
            }

            int maxDeceit = 0; 
            kenL = new LinkedList<Double>();
            naomiL = new LinkedList<Double>();
            for(int j = 0; j < n; j++)
            {
                kenL.addLast(ken[j]);
                naomiL.addLast(naomi[j]);
            }
            for(int j = 0; j < n; j++)
            {
                boolean forcePick = false;
                double nPick = 0;
                if(naomiL.getLast() > kenL.getLast())
                {
                    forcePick = true;
                    int ind = naomiL.size() - 2;
                    for(int k = ind; k >= 0; k--)
                    {
                        if(naomiL.get(k) < kenL.getLast())
                        {
                            naomiL.remove(k+1);
                            break;
                        }
                    }
                    kenL.removeLast();
                    maxDeceit++;
                }
                if(!forcePick && naomiL.getFirst() < kenL.getLast())
                {
                    forcePick = true;
                    naomiL.removeFirst();
                    kenL.removeLast();
                }

                if(!forcePick)
                {
                    nPick = naomiL.removeLast();
                    double kPick = -2.0;
                    ListIterator li = kenL.listIterator(0);
                    while(li.hasNext())
                    {
                        double val = (Double)li.next();
                        if(val > nPick)
                        {
                            kPick = val;
                            li.remove();
                            break;
                        }
                    }
                    if(kPick < -1.0)
                    {
                        kPick = kenL.removeFirst();
                    }

                    if(nPick > kPick)
                    {
                        maxDeceit++;
                    }
                }
            }

            System.out.printf("Case #%d: %d %d\n", i + 1, maxDeceit, maxWar);
        }

        in.close();
    }
}
