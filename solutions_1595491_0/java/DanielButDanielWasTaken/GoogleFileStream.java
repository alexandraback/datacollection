import com.sun.xml.internal.messaging.saaj.packaging.mime.util.LineInputStream;
import sun.tools.tree.ReturnStatement;

import javax.swing.*;
import java.io.*;
import java.util.ArrayList;

/**
 * Date: 14/4/12
 * Time: 9:19 AM
 */
public class GoogleFileStream {
    public static ArrayList<String> getInput() throws IOException {
        JFileChooser fc = new JFileChooser();
        fc.showOpenDialog(null);
        File f = fc.getSelectedFile();

        ArrayList<String> ret = new ArrayList<String>();
        LineInputStream lis = new LineInputStream(new FileInputStream(f));
        String line;
        while( (line = lis.readLine()) != null )
        {
            ret.add(line);
        }

        // number of lines:
        ret.remove(0);

        return ret;
    }

    public static void setOutput(ArrayList<String> ret) throws IOException {

        JFileChooser fc = new JFileChooser();
        fc.showSaveDialog(null);
        File f = fc.getSelectedFile();

        StringBuilder sb = new StringBuilder();
        FileWriter fw = new FileWriter(f);
        for( int i = 0; i < ret.size(); i++ )
        {
            sb.delete(0, sb.length());
            sb.append(String.format( "Case #%d: ", i + 1));
            sb.append( ret.get(i) );
            sb.append( "\n" );

            String o = sb.toString();
            fw.write( o );
            System.out.print(o);
        }
        fw.close();
    }
}
