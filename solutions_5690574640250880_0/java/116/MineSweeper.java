package problem3;

import java.io.File;
import java.io.IOException;
import java.util.List;

import net.lab0.tools.FileUtils;

public class MineSweeper
{
    public static void main(String[] args)
    throws IOException
    {
        String in = "rc\\C-small-attempt1.in";
        List<String> lines = FileUtils.readFileAsText(new File(in));
        
        int count = Integer.parseInt(lines.get(0));
        for (int i = 1; i <= count; ++i)
        {
            String[] split = lines.get(i).split(" ");
            int x = Integer.parseInt(split[0]);
            int y = Integer.parseInt(split[1]);
            int m = Integer.parseInt(split[2]);
            
            Case c = new Case(x, y, m);
            System.out.println("Case #" + i + ":");
            System.out.println(c.solve());
        }
    }
}
