import static java.lang.Math.*;
import static java.util.Arrays.*;
import static java.util.Collections.*;

import java.io.*;
import java.text.*;
import java.util.*;
import java.math.*;

public class ProblemC {

    private static final String PROBLEM_CODE = "C";
//    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-large.in", PROBLEM_CODE);
    private static final String INPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-small-attempt4.in", PROBLEM_CODE);
    private static final String OUTPUT_PATH = String.format("C:\\Users\\Yasu\\Downloads\\%s-out%s.txt", PROBLEM_CODE, System.currentTimeMillis());

    private String solveProblem(int n, int[] elem) {
        return "";
    }

    class Type {
        String x;
        String y;
        Type (String  x, String y) {
            this.x = x;
            this.y = y;
        }
        Type (String  x, int xi, String y, int yi) {
            this.x = x + xi;
            this.y = y + yi;
        }
        @Override
        public int hashCode() {
            final int prime = 31;
            int result = 1;
            result = prime * result + getOuterType().hashCode();
            result = prime * result + ((x == null) ? 0 : x.hashCode());
            result = prime * result + ((y == null) ? 0 : y.hashCode());
            return result;
        }
        @Override
        public boolean equals(Object obj) {
            if (this == obj)
                return true;
            if (obj == null)
                return false;
            if (getClass() != obj.getClass())
                return false;
            Type other = (Type) obj;
            if (!getOuterType().equals(other.getOuterType()))
                return false;
            if (x == null) {
                if (other.x != null)
                    return false;
            } else if (!x.equals(other.x))
                return false;
            if (y == null) {
                if (other.y != null)
                    return false;
            } else if (!y.equals(other.y))
                return false;
            return true;
        }
        private ProblemC getOuterType() {
            return ProblemC.this;
        }
        @Override
        public String toString() {
            return this.x + " " + this.y;
        }
        
    }
    
    private List<String> solveProblem(String element) {
        String[] line = element.split(" ");
        int j = Integer.parseInt(line[0]);
        int p = Integer.parseInt(line[1]);
        int s = Integer.parseInt(line[2]);
        int k = Integer.parseInt(line[3]);
        
        Map<Type, Integer> map = new HashMap<>();
        addMap(j, p, "j", "p", map);
        addMap(j, s, "j", "s", map);
        addMap(p, s, "p", "s", map);
        
        List<String> list = new ArrayList<>();
        
        boolean[][][] used = new boolean[j+1][p+1][s+1];
        int[] useJ = new int[j+1];
        int[] useP = new int[p+1];
        int[] useS = new int[s+1];

        while(true) {
            int minJpCount = Integer.MAX_VALUE;
            List<Integer> minJIndex = new ArrayList<>();
            List<Integer> minPIndex = new ArrayList<>();
            for (int i = 1; i <= j; i++) {
                for (int l = 1; l <= p; l++) {
                    int jpCount = map.get(new Type("j", i, "p", l));
                    if(jpCount < minJpCount) {
                        minJpCount = jpCount;
                        minJIndex.add(i);
                        minPIndex.add(l);
                    } else if(jpCount == minJpCount) {
                        minJIndex.add(i);
                        minPIndex.add(l);
                    }
                }
            }

            if(minJpCount >= k) break;
            int minSCount = Integer.MAX_VALUE;
            int minJUse = 0;
            int minPUse = 0;
            int minSUse = 0;

            for (int i = 0 ; i < minJIndex.size(); i++) {
                int mj = minJIndex.get(i);
                int mp = minPIndex.get(i);
                for (int l = 1; l <= s; l++) {
                    if(used[mj][mp][l]) continue;
                    int jsCount = map.get(new Type("j", mj, "s", l));
                    int psCount = map.get(new Type("p", mp, "s", l));
                    
                    int count = Math.max(jsCount, psCount);
                    
                    if(minSCount > count || (minSCount == count && jsCount >= psCount)) {
                        minSCount = count;
                        minSUse = l;
                        minJUse = mj;
                        minPUse = mp;
                    }
                }
            }

            if(minSCount >= k) break;
            
            Integer jpType = map.get(new Type("j", minJUse, "p", minPUse));
            Integer jsType = map.get(new Type("j", minJUse, "s", minSUse));
            Integer psType = map.get(new Type("p", minPUse, "s", minSUse));
            map.put(new Type("j", minJUse, "p", minPUse), jpType + 1);
            map.put(new Type("j", minJUse, "s", minSUse), jsType + 1);
            map.put(new Type("p", minPUse, "s", minSUse), psType + 1);
            
            list.add(minJUse + " " + minPUse + " " + minSUse);
            used[minJUse][minPUse][minSUse] = true;
            useJ[minJUse]++;
            useP[minPUse]++;
            useS[minSUse]++;
        }
        
        
        

        for(int i = 1; i <= j; i++) {
            for (int l = 1; l <= p; l++) {
                for (int l2 = 1; l2 <= s; l2++) {
                    if(used[i][l][l2]) continue;
                    Integer jpType = map.get(new Type("j", i, "p", l));
                    Integer jsType = map.get(new Type("j", i, "s", l2));
                    Integer psType = map.get(new Type("p", l, "s", l2));
                    if(jpType >= k || jsType >= k || psType >= k) continue;
                    map.put(new Type("j", i, "p", l), jpType + 1);
                    map.put(new Type("j", i, "s", l2), jsType + 1);
                    map.put(new Type("p", l, "s", l2), psType + 1);
                    list.add(i + " " + l + " " + l2);
                    used[i][l][l2] = true;
                }
            }
        }

//        for(Map.Entry<Type, Integer> entry : map.entrySet()) {
//            System.out.println(entry.getKey() + ":"+ entry.getValue());
//        }
        return list;
    }

    private void addMap(int j, int p, String a, String b, Map<Type, Integer> map) {
        for (int i = 1; i <= j; i++) {
            for (int l = 1; l <= p; l++) {
                Type type = new Type(a, i, b, l);
                map.put(type, new Integer(0));
            }
        }
    }
    
    private void run() { 
        try (BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(new File(INPUT_PATH))))) {
            List<List<String>> answerList = new ArrayList<>();
            int testCaseCount = readInt(br);
            for (int testCaseIndex = 0; testCaseIndex < testCaseCount; testCaseIndex++) {
                String element = br.readLine();
//                int n = readInt(); 
//                int[] elem = new int[n];
//                String[] line = br.readLine().split(" ");
//                for(int i = 0 ; i < n; i++) {
//                    elem[i] = Integer.parseInt(line[i]);
//                }
//                String answer = solveProblem(n, elem); 
                List<String> answer = solveProblem(element); 
                answerList.add(answer);
                
                System.out.printf("%s: %s : %s \r\n", testCaseIndex + 1, element, answer);
            }
            writeFile(OUTPUT_PATH, answerList);
        } catch(Exception e) {
            e.printStackTrace();
        }
    }
    
    private static void writeFile(String filePath, List<List<String>> solve) {
        final String FORMAT = "Case #{0}: {1}";
        try (BufferedWriter bufferedWriter = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File (filePath))))){
            for (int i = 0; i < solve.size(); i++) {
                Object[] ans = new Object[2];
                ans[0] = String.valueOf(i + 1);
                ans[1] = solve.get(i).size();
                String write = MessageFormat.format(FORMAT, ans);
                bufferedWriter.write(write);
                bufferedWriter.newLine();
                for(String s : solve.get(i)) {
                    bufferedWriter.write(s);
                    bufferedWriter.newLine();
                }
            }
        } catch (Exception e) {
            e.printStackTrace();
        }
    }

    private int readInt(BufferedReader br) throws IOException {
        return Integer.parseInt(br.readLine());
    }

    public static void main(String[] args) {
        ProblemC app = new ProblemC();
//        System.out.println(app.solveProblem("1 1 1 10"));
//        System.out.println(app.solveProblem("1 2 3 2"));
//        System.out.println(app.solveProblem("1 1 3 2"));
//        System.out.println(app.solveProblem("1 2 3 1"));
        app.run();
    }
}


class UnionFind {
    // 各要素が保持している親のindex
    private int[] parentArray ;

    // 各要素が保持している木の深さ
    private int[] rankArray;

    // 要素数
    private int nodeCount;

    public UnionFind(int totalCount) {
        this.nodeCount = totalCount;
        parentArray = new int[totalCount];
        rankArray = new int[totalCount];

        for (int i = 0; i < totalCount; i++) {
            parentArray[i] = i;
            rankArray[i] = 0;
        }
    }

    /**
     * <pre>
     * 要素検索
     * インデックスが要素の順番と等しいときは引数の値をそのまま返却する。
     * インデックスの順番が等しくないときは検索したインデックスリストに
     * 格納されている番号を元に再度検索を行い、再帰的にインデックス配列の番号を入れ替える。
     * </pre>
     * @param nodeIndex
     * @return
     */
    public int findParent(int nodeIndex) {
        if (parentArray[nodeIndex] == nodeIndex) {
            return nodeIndex;
        } else {
            return parentArray[nodeIndex] = findParent(parentArray[nodeIndex]);
        }
    }

    public void union(int node1, int node2) {
        node1 = findParent(node1);
        node2 = findParent(node2);
        if (node1 == node2) {
            return;
        }

        if (rankArray[node1] < rankArray[node2]) {
            parentArray[node1] = node2;
        } else if (rankArray[node1] > rankArray[node2]) {
            parentArray[node2] = node1;
        } else {
            parentArray[node2] = node1;
            rankArray[node1]++;
        }

    }

    public boolean isSameParent(int node1, int node2) {
        return findParent(node1) == findParent(node2);
    }

    public int getNodeCount() {
        return this.nodeCount;
    }
}