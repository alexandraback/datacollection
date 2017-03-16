import java.lang.reflect.Array;
import java.math.BigInteger;
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;

public class JamB2 {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int T = in.nextInt();
        in.nextLine();
        Pattern pattern = Pattern.compile("\\s+");
        Pattern same = Pattern.compile("^(.)\\1*$");
        for (int i = 1; i <= T; i++) {
            in.nextLine();
            String next = in.nextLine();
            String[] trains = pattern.split(next);
            int length = 'z' - 'a' + 1;
            int result = 1;
            String[] pieces = new String[length];
            int[] sameC = new int[length];
            for (String train : trains) {
                int index = train.charAt(0) - 'a';
                if (same.matcher(train).matches())
                    sameC[index]++;
                else {
                    if (pieces[index] != null)
                        result = 0;
                    else
                        pieces[index] = train;
                }
            }
            ArrayList<String> parts = new ArrayList<String>();
            outer:
            for (int j = 0; j < sameC.length; j++) {
                if (sameC[j] == 0)
                    continue;
                char ch = (char) (j + 'a');
                for (int k = 1; k <= sameC[j]; k++) {
                    result = (result * k) % 1000000007;
                }
                for (String piece : pieces) {
                    if (piece == null)
                        continue;
                    if (piece.charAt(0) == ch || piece.charAt(piece.length() - 1) == ch)
                        continue outer;
                }
                parts.add(new String(new char[]{ch, ch}));
            }

            boolean[] been = new boolean[pieces.length];
            outer:
            for (int j = 0; j < pieces.length; j++) {
                String piece = pieces[j];
                if (piece == null || been[j])
                    continue;
                int index = j;
                do {
                    char firstChar = pieces[index].charAt(0);
                    for (int k = 0; k < pieces.length; k++) {
                        String s = pieces[k];
                        if (s != null && s.charAt(s.length() - 1) == firstChar)
                            index = k;
                    }
                    break;
                } while (index != j);
                piece = pieces[index];
                StringBuilder tmp = new StringBuilder();
                tmp.append(piece);
                piece = null;
                been[index] = true;
                int count = 1;
                while (true) {
                    int lastChar = tmp.charAt(tmp.length() - 1) - 'a';
                    if (been[lastChar]) {
                        result = (result * count) % 1000000007;
                        break;
                    }
                    if (pieces[lastChar] == null)
                        break;
                    count++;
                    tmp.append(pieces[lastChar]);
                    pieces[lastChar] = null;
                    been[lastChar] = true;
                }
                parts.add(tmp.toString());
            }
            int size = parts.size();
            StringBuilder oneOf = new StringBuilder();
            for (String part : parts) {
                oneOf.append(part);
            }
            oneOf.append('!');

            boolean[] used = new boolean[length];
            int prev = oneOf.charAt(0) - 'a';
            for (int j = 1; j < oneOf.length(); j++) {
                int c = oneOf.charAt(j) - 'a';
                if (prev != c) {
                    if (used[prev])
                        result = 0;
                    else
                        used[prev] = true;
                }
                prev = c;
            }
            for (int j = 1; j <= size; j++)
                result = (result * j) % 1000000007;
            System.out.println("Case #" + i + ": " + result);
        }
        in.close();
    }
}
