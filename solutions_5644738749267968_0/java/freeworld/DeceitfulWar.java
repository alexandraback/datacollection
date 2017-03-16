import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.FileReader;
import java.io.FileWriter;
import java.util.HashMap;
import java.util.TreeMap;

/**
 * Created by freeworld on 4/11/14.
 */
public class DeceitfulWar {
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("D-small-attempt0.in"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("prob4.out"));
        int caseNum = Integer.parseInt(br.readLine());
        for (int i = 1; i <= caseNum; i++) {
            int blockNum = Integer.parseInt(br.readLine());
            double[] Naomi = new double[blockNum];
            double[] Ken = new double[blockNum];
            String[] strs1 = br.readLine().split("\\s+");
            String[] strs2 = br.readLine().split("\\s+");
            for (int j = 0; j < blockNum; j++) {
                Naomi[j] = Double.parseDouble(strs1[j]);
                Ken[j] = Double.parseDouble(strs2[j]);
            }
            HashMap<Double, String> map1 = new HashMap<Double, String>();
            HashMap<Double, String> map2 = new HashMap<Double, String>();
            for (double a : Naomi)
                map1.put(a, "A");
            for (double a : Ken)
                map2.put(a, "B");
            TreeMap<Double, String> map = new TreeMap<Double, String>();
            map.putAll(map1);
            map.putAll(map2);
            StringBuilder sb = new StringBuilder();
            for (double a : map.keySet())
                sb.append(map.get(a));
            String str = sb.toString();

            String tmpStr = new String(str);
            int point1 = 0, point2 = 0;

            while (true) {
                int idxA = 0, idxB = 0, k = 0;
                StringBuilder tmp = new StringBuilder();
                while (tmpStr.length() > 0 && tmpStr.charAt(k) == 'A') {
                    tmp.append(tmpStr.charAt(k));
                    k++;
                }
                idxB = k++;
                while (k < tmpStr.length() && tmpStr.charAt(k) == 'B') {
                    tmp.append(tmpStr.charAt(k));
                    k++;
                }
                if (k < tmpStr.length() && idxB < k) {
                    point1++;
                    idxA = k;
                    tmp.append(tmpStr.substring(idxA+1));
                    tmpStr = tmp.toString();
                } else {
                    break;
                }
            }

            tmpStr = new String(str);
            while (true) {
                int idxA = 0, idxB = 0, k = 0;
                StringBuilder tmp = new StringBuilder();
                while (tmpStr.length() > 0 && tmpStr.charAt(k) == 'B') {
                    tmp.append(tmpStr.charAt(k));
                    k++;
                }
                idxA = k++;
                while (k < tmpStr.length() && tmpStr.charAt(k) == 'A') {
                    tmp.append(tmpStr.charAt(k));
                    k++;
                }
                if (k < tmpStr.length() && idxA < k) {
                    point2++;
                    idxB = k;
                    tmp.append(tmpStr.substring(idxB+1));
                    tmpStr = tmp.toString();
                } else {
                    break;
                }
            }
            point2 = blockNum - point2;

            bw.write("Case #" + i + ": " + point1 + " " + point2);
            bw.newLine();
        }

        br.close();
        bw.close();
    }
}
