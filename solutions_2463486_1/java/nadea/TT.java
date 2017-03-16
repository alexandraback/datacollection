import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.math.BigInteger;
import java.util.ArrayList;
import java.util.List;

public class TT {
    public static void main(String[] args) throws IOException {
        List<Integer> core = new ArrayList<Integer>();
        core.add(1);
        BigInteger result = new BigInteger("1");
        BufferedWriter writer = new BufferedWriter(new FileWriter("TT.out"));
//        writer.write(core.get(0) + ";" + result + "\n");
        while (result.toString().length() < 20) {
            String pal = getPal(core);
            String pal2 = getPal2(core);
            BigInteger res2 = new BigInteger(pal2);
            result = res2.pow(2);
            if (ispal(result)) {
                writer.write(pal2 + ";" + result + "\n");
            }
            BigInteger res = new BigInteger(pal);
            result = res.pow(2);
            if (ispal(result)) {
                writer.write(pal + ";" + result + "\n");
            }
            updateCore(core);
        }
        writer.close();
    }

    private static String getPal2(List<Integer> core) {
        StringBuilder res = new StringBuilder();
        for (int i = core.size() - 1; i >= 0; i--) {
            res.append(core.get(i));
        }
        for (Integer it : core) {
            res.append(it);
        }
        return res.toString();
    }

    private static boolean ispal(BigInteger res2) {
        String s = res2.toString();
        for (int i = 0; i < s.length() / 2; ++i) {
            if (s.charAt(i) != s.charAt(s.length() - 1 - i)) {
                return false;
            }
        }
        return true;
    }

    private static String getPal(List<Integer> core) {
        StringBuilder res = new StringBuilder();
        for (int i = core.size() - 1; i > 0; i--) {
            res.append(core.get(i));
        }
        for (Integer it : core) {
            res.append(it);
        }
        return res.toString();
    }

    private static void updateCore(List<Integer> core) {
        boolean isAdd = false;
        for (int i = 0; i < core.size(); i++) {
            if (core.get(i) < 9) {
                core.set(i, core.get(i) + 1);
                break;
            } else {
                core.set(i, 0);
                if (i == (core.size() - 1)) {
                    isAdd = true;
                }
            }
        }
        if (isAdd) {
            core.add(1);
        }
    }

}