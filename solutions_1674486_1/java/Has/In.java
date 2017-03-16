package inout;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.List;

public final class In {

    private In() {
    }

    public static String[] read(String path, int mult) throws FileNotFoundException, IOException {
        System.out.println("IN");
        File f = new File(path);
        BufferedReader br = new BufferedReader(new FileReader(f));
        String[] array = new String[Integer.parseInt(br.readLine()) * mult];
        String s = br.readLine();
        int i = 0;
        while (s != null) {
            array[i] = s;
            System.out.println(s);
            i++;
            s = br.readLine();
        }
        System.out.println();
        System.out.println();
        br.close();
        return array;
    }

    public static List<String> dynamicRead(String path) throws FileNotFoundException, IOException {
        System.out.println("IN");
        File f = new File(path);
        BufferedReader br = new BufferedReader(new FileReader(f));
        ArrayList<String> array = new ArrayList<String>();
        System.out.println(br.readLine() + " tests");
        String s = br.readLine();
        int i = 0;
        while (s != null) {
            array.add(s);
            System.out.println(s);
            i++;
            s = br.readLine();
        }
        System.out.println();
        System.out.println();
        br.close();
        return array;
    }
}
