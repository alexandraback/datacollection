import java.util.*;

public class C
{
    public static List<Integer> findlongestPathTo(Integer curChild, List<Integer> bbfs, List<Integer> curPath)
    {
        List<Integer> longestRes = new ArrayList<>();
        for(int i = 0; i < bbfs.size(); i++)
        {
            if(bbfs.get(i) == curChild && !curPath.contains(i))
            {
                List<Integer> curr = new ArrayList<>();
                curr.addAll(curPath);
                curr.add(i);
                List<Integer> res = findlongestPathTo(i, bbfs, curr);
                res.add(i);
                if(longestRes.size() < res.size()) longestRes = res;
            }
        }
        return longestRes;
    }

    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);

        int T = sc.nextInt();

        for(int i = 0; i < T; i++)
        {
            String res = "";
            int N = sc.nextInt();
            List<Integer> bbfs = new ArrayList<>();
            List<Integer> maxCyrcle = new ArrayList<>();
            for(int j = 0; j < N; j++) bbfs.add(sc.nextInt()-1);

            for(int j = 0; j < N; j++)
            {
                if(!maxCyrcle.contains(j))
                {
                    List<Integer> curPath = new ArrayList<>();
                    int curChild = j;
                    curPath.add(curChild);
                    while(!curPath.contains(bbfs.get(curChild)))
                    {
                        curPath.add(bbfs.get(curChild));
                        curChild = bbfs.get(curChild);
                    }
                    if(bbfs.get(curChild) == j && curPath.size() > maxCyrcle.size()) maxCyrcle = curPath;
                    else if(curPath.size() > 2 && bbfs.get(curChild) == curPath.get(curPath.size()-2))
                    {
                        List<Integer> path = findlongestPathTo(curChild, bbfs, curPath);
                        curPath.addAll(path);
                        if(curPath.size() > maxCyrcle.size()) maxCyrcle = curPath;
                    } else {
                        int idx = curPath.indexOf(bbfs.get(curChild));
                        if(idx > maxCyrcle.size()) maxCyrcle = curPath.subList(0, idx);
                    }
                }
            }

            System.out.println("Case #"+(i+1)+": "+maxCyrcle.size());
        }
    }
}
