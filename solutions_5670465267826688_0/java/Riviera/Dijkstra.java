import java.io.*;
import java.util.*;

/**
 * Created by yilinhe on 4/10/15. All right reserved.
 */
public class Dijkstra {
    public static Map<String,String> A;

    public static boolean[] findI(String input){
        boolean[] res = new boolean[input.length()];
        String cur = "";
        for (int i = 0;i<input.length();i++){
            cur+=input.charAt(i);
            cur = merge(cur);
            if ("i".equals(cur)){
                res[i] = true;
            }else{
                res[i] = false;
            }
        }
        return res;
    }

    public static boolean[] findJ(String input){
        boolean[] res = new boolean[input.length()];
        String cur = "";
        for (int i = 0;i<input.length();i++){
            cur+=input.charAt(i);
            cur = merge(cur);
            if ("j".equals(cur)){
                res[i] = true;
            }else{
                res[i] = false;
            }
        }
        return res;
    }

    public static boolean[] findK(String input){
        boolean[] res = new boolean[input.length()];
        String cur = "";
        for (int i = input.length()-1;i>=0;i--){
            cur=input.charAt(i)+cur;
            cur = merge(cur);
            if ("k".equals(cur)){
                res[i] = true;
            }else{
                res[i] = false;
            }
        }
        return res;
    }

    private static String merge(String cur) {
        int pos = 1;
        String temp = cur;
        if (cur.charAt(0) == '-'){
            pos *= -1;
            temp = temp.substring(1);
        }else if (cur.length()>1 && cur.charAt(1) == '-'){
            pos *= -1;
            temp = temp.substring(0,1)+temp.substring(2);
        }
        String newStr;
        if (temp.length() ==1){
            newStr = temp;
        }else {
            newStr = A.get(temp);

            if (newStr.charAt(0) == '-') {
                pos *= -1;
                newStr = newStr.substring(1);
            }
        }
        if (pos == 1){
            return newStr;
        }else{
            return "-"+newStr;
        }
    }


    public static boolean calculate(String myStr){
        boolean[] is = findI(myStr);
        boolean ks[] = findK(myStr);

        for (int i = 0; i < myStr.length()-1;i++){
            if (!is[i]){
                continue;
            }

            boolean js[] = findJ(myStr.substring(i+1));
            for (int j = i+1;j<myStr.length()-1;j++){
                boolean jval = js[j-i-1];
                boolean kval = ks[j+1];
                if (jval && ks[j+1]){
                    return true;
                }
            }
        }
        return false;
    }


    public static void main(String args[]) throws IOException {
        A = new HashMap<>();
        A.put("ii","-");
        A.put("ij","k");
        A.put("ik","-j");
        A.put("jj","-");
        A.put("ji","-k");
        A.put("jk","i");
        A.put("kk","-");
        A.put("ki","j");
        A.put("kj","-i");

        Scanner input = new Scanner(new FileInputStream( new File("p3small.txt")));
        BufferedWriter bfr = new BufferedWriter(new FileWriter( new File("p3small.result")));
        int counter = 1;
        input.nextLine();
        while(input.hasNext()){
            String[] line = input.nextLine().split(" ");
            int a = Integer.valueOf(line[0]);
            int b = Integer.valueOf(line[1]);
            String str = input.nextLine();
            String myStr = "";
            while(b-->0){
                myStr +=str;
            }
            String ans;
            if (calculate(myStr)){
                ans = "YES";
            }else{
                ans = "NO";
            }
            bfr.write("Case #" + counter++ + ": " + ans + "\n");
        }
        bfr.flush();
    }
}
