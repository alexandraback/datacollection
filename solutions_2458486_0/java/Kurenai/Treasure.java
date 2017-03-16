package googlecodejam.treasure;

import java.io.BufferedReader;
import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.IOException;
import java.util.ArrayList;

public class Treasure {

    public static void main(String[] args) throws FileNotFoundException, IOException {
       ArrayList<ChestOpener> chests = getChests("C:\\Users\\Patri\\Downloads\\D-small-attempt2.in");
       //  ArrayList<ChestOpener> chests = getChests("C:\\Users\\Patri\\Downloads\\ttt_test.in");
        int size = chests.size();
        for (int i = 0; i < size; i++) {
            ChestOpener chest = chests.get(0);
            chest.openAll();
            System.out.println("Case #" + (i + 1) + ": " + chest.toString());
            chests.remove(0);
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

    private static ArrayList<ChestOpener> getChests(String aFileName) throws FileNotFoundException, IOException {
        ArrayList<ChestOpener> chestOpeners = new ArrayList<ChestOpener>();
        ArrayList<String> lines = readFile(aFileName);
        int num = parseLine(lines)[0];

        while (num > 0) {

            ArrayList<Chest> chests = new ArrayList<Chest>();
            ArrayList<Integer> keys = new ArrayList<Integer>();
            
            int[] parsed = parseLine(lines);
            int numChests = parsed[1];

            int[] keysArray = parseLine(lines);
            for (int key : keysArray) {
                keys.add(key);
            }

            while (numChests > 0) {
                int[] chestArray = parseLine(lines);
                ArrayList<Integer> chestKeys = new ArrayList<Integer>();
                for (int i = 2; i < chestArray.length; i++) {
                    chestKeys.add(chestArray[i]);
                }
                chests.add(new Chest(chestArray[0], chestKeys));
                numChests--;
            }
            chestOpeners.add(new ChestOpener(chests, keys));
            num--;
        }
        return chestOpeners;
    }

    private static int[] parseLine(ArrayList<String> lines) {
        String[] split = lines.get(0).split(" ");
        int[] result = new int[split.length];
        for (int i = 0; i < split.length; i++) {
            result[i] = Integer.parseInt(split[i]);
        }
        lines.remove(0);
        return result;
    }
}
