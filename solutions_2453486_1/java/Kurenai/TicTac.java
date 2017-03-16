package googlecodejam.tictac;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class TicTac {

    public static void main(String[] args) throws FileNotFoundException, IOException {
        ArrayList<Tablero> tableros = getTableros("C:\\Users\\Patri\\Downloads\\A-large.in");
        for (int i = 0; i<tableros.size(); i++) {
            Tablero t = tableros.get(i);
            System.out.println("Case #" + (i+1) + ": " + t.toString());
        }
    }

    public static ArrayList<String> readFile(String aFileName) throws FileNotFoundException, IOException {
        ArrayList<String> result = new ArrayList<String>();
        FileReader fr = new FileReader(aFileName);
        BufferedReader br = new BufferedReader(fr);
        String s;
        while ((s = br.readLine()) != null) {
            result.add(s);
        }
        return result;
    }

    public static ArrayList<Tablero> getTableros(String aFileName) throws FileNotFoundException, IOException {
        ArrayList<Tablero> tableros = new ArrayList<Tablero>();
        ArrayList<String> lines = readFile(aFileName);
        for (int i = 1; i < lines.size(); i += 5) {
           // System.out.println("****" + (i+1) + "-" + (i+5));
            tableros.add(new Tablero(new ArrayList<String>(lines.subList(i, i + 4))));
        }
        return tableros;
    }
}
