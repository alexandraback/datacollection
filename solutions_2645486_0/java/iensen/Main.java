import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.io.BufferedReader;
import java.io.OutputStream;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.io.FileInputStream;
import java.util.StringTokenizer;
import java.io.InputStream;

/**
 * Built using CHelper plug-in
 * Actual solution is at the top
 */
public class Main {
	public static void main(String[] args) {
		InputStream inputStream;
		try {
			inputStream = new FileInputStream("task2.in");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		OutputStream outputStream;
		try {
			outputStream = new FileOutputStream("task2.out");
		} catch (IOException e) {
			throw new RuntimeException(e);
		}
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		Task2 solver = new Task2();
		solver.solve(1, in, out);
		out.close();
	}
}

class Task2 {
    public void solve(int testNumber, InputReader in, PrintWriter out) {
        int t=in.nextInt();
        for(int tcase=1;tcase<=t;tcase++) {
            int E=in.nextInt();
            int R=in.nextInt();
            int N=in.nextInt();
            int []v=new int[N];
            for(int i=0;i<N;i++) {
                v[i]=in.nextInt();
            }
            SegmentTree sg=new SegmentTree(v, SegmentTreeOperation.MAX);
            int currentEnergy=E;
            long gained=0;
            for(int i=0;i<N;i++) {

               //find nearest greater element:
               int lo=i;
               int hi=v.length-1;
               while(lo<hi-1) {

                   int c=(lo+hi)/2;
                   if(sg.query(i+1,c)>v[i]) {
                       hi=c;
                   }
                   else {
                       lo=c;
                   }
               }
               
               if(sg.query(i+1,hi)<=v[i]) {
                  //spend all energy:
                   gained+=(long)v[i]*(long)currentEnergy;
                   currentEnergy=0;
               }
               
               
               else {
                   int willGain=R*(hi-i);
                   int canSpend=Math.min(currentEnergy,currentEnergy-(E-willGain)) ;
                   if(canSpend>0) {
                      gained+=(long)v[i]*(long)canSpend;

                      currentEnergy-=canSpend;
                   }
               }
               currentEnergy+=R;
            }
            out.println("Case #"+tcase+": "+gained);
        }
    }
}

class InputReader {
    StringTokenizer st;
    BufferedReader in;
    public InputReader(InputStream ins)
    {
        in = new BufferedReader(new InputStreamReader(ins));
    }

    public String nextToken()
    {
        while(st==null || !st.hasMoreTokens())
        {
            try {
                st=new StringTokenizer(in.readLine());
            } catch (IOException e) {
                e.printStackTrace();  //To change body of catch statement use File | Settings | File Templates.
            }
        }
        return st.nextToken();
    }
    public int nextInt()
    {

        return Integer.parseInt(nextToken());
    }

    }

class SegmentTree
{

    SegmentTreeOperation op;
    int array[];
    final int initVal;

    public SegmentTree(int[] initArray, SegmentTreeOperation op)
    {
        switch (op)
        {
            case SUM:
                initVal = 0;
                break;
            case MIN:
                initVal = Integer.MAX_VALUE;
                break;
            case MAX:
                initVal = Integer.MIN_VALUE;
                break;
            default:
                initVal = 0;
        }
        this.op = op;
        int togetCap = initArray.length * 2;
        int curLength = 1;
        while (curLength < togetCap)
        {
            curLength *= 2;
        }
        array = new int[curLength];
        Arrays.fill(array, initVal);
        build(initArray, 1, 0, curLength / 2 - 1);

    }

    private void build(int initArray[], int segmentTreeIdx, int initArrayLIdx, int initArrayRIdx)
    {

            //FILL leaves:
            if (initArrayLIdx == initArrayRIdx)
            {
                array[segmentTreeIdx] = (initArrayLIdx < initArray.length) ? initArray[initArrayLIdx] : initVal;
            } else
            {
                int initArrayMIdx = (initArrayLIdx + initArrayRIdx) / 2;
                //build subtrees:
                build(initArray, segmentTreeIdx * 2, initArrayLIdx, initArrayMIdx);
                build(initArray, segmentTreeIdx * 2 + 1, initArrayMIdx + 1, initArrayRIdx);
                //assign value to current vertex
                switch (op)
                {
                    case MIN:
                        array[segmentTreeIdx] = Math.min(array[segmentTreeIdx * 2],
                                array[segmentTreeIdx * 2 + 1]);
                        break;
                    case SUM:
                        array[segmentTreeIdx] = array[segmentTreeIdx * 2] +
                                array[segmentTreeIdx * 2 + 1];
                        break;
                    case MAX:
                        array[segmentTreeIdx] = Math.max(array[segmentTreeIdx * 2],
                                array[segmentTreeIdx * 2 + 1]);
                        break;
                }

            }
    }


    public int query(int left, int right)
    {
        return query(1, 0, array.length / 2 - 1, left, right);
    }

    private int query(int segmentTreeIdx, int coverLIdx, int coverRIdx, int queryLIdx, int queryRIdx)
    {

        if (queryLIdx > queryRIdx)
            return initVal;
        if (coverLIdx == queryLIdx && coverRIdx == queryRIdx)
            return array[segmentTreeIdx];
        int coverMIdx = (coverLIdx + coverRIdx) / 2;
        switch (op)
        {

            case MIN:
                return Math.min(query(segmentTreeIdx * 2, coverLIdx, coverMIdx, queryLIdx, Math.min(queryRIdx, coverMIdx))
                        , query(segmentTreeIdx * 2 + 1, coverMIdx + 1, coverRIdx, Math.max(queryLIdx, coverMIdx + 1), queryRIdx));

            case MAX:
                return Math.max(query(segmentTreeIdx * 2, coverLIdx, coverMIdx, queryLIdx, Math.min(queryRIdx, coverMIdx))
                        , query(segmentTreeIdx * 2 + 1, coverMIdx + 1, coverRIdx, Math.max(queryLIdx, coverMIdx + 1), queryRIdx));

            case SUM:
                return query(segmentTreeIdx * 2, coverLIdx, coverMIdx, queryLIdx, Math.min(queryRIdx, coverMIdx)) +
                        query(segmentTreeIdx * 2 + 1, coverMIdx + 1, coverRIdx, Math.max(queryLIdx, coverMIdx + 1), queryRIdx);

            default:
                return 0;
        }


    }

    }

enum SegmentTreeOperation{MIN,MAX,SUM;}

