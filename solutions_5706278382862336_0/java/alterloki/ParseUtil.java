/**
 * Created by IntelliJ IDEA.
 * User: ashevenkov
 * Date: 22.02.14
 * Time: 17:52
 */
package common;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;

/**
 * @author ashevenkov
 */
public class ParseUtil {

    public static String parseFile(String file) {
        StringBuilder sb = new StringBuilder();
        try {
            BufferedReader br = new BufferedReader(new FileReader("codejam/input/" + file));
            String line = br.readLine();
            boolean first = true;
            while(line != null) {
                if(first) {
                    first = false;
                } else {
                    sb.append("\n");
                }
                sb.append(line);
                line = br.readLine();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
        return sb.toString();
    }
}
