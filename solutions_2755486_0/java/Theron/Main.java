package com.company;

import java.io.*;
import java.util.*;

public class Main {

    public static void main(String[] args) throws IOException {
        final String in = args[0];
        final String out = args[1];

        BufferedReader br = null;
        BufferedWriter bw = null;

        try {
            br = new BufferedReader(new FileReader(in));
            bw = new BufferedWriter(new FileWriter(out));

            int numCases = Integer.parseInt(br.readLine());
            for (int i = 0; i < numCases; i++) {
                int numTribes = Integer.parseInt(br.readLine());

                TreeSet<Tribe> tribes = new TreeSet<Tribe>();

                Map<Integer, Integer> wall = new HashMap<Integer, Integer>();

                int numAttacks = 0;
                for (int j = 0; j < numTribes; j++) {
                    int[] tribeData = convertToInts(br.readLine().split("\\s"));
                    tribes.add(new Tribe(j, tribeData));
                }

                while (!tribes.isEmpty()) {
                    Tribe t = tribes.first();
                    int day = t.getDay();
                    List<Attack> batchedAttacks = new ArrayList<Attack>();
                    do {
                        // inefficient! good enough.
                        t = tribes.pollFirst();
                        List<Attack> attacks = t.attack(wall);

                        if (!attacks.isEmpty()) {
                            numAttacks++;
                            batchedAttacks.addAll(attacks);
                        }

                        if (!t.isFinished()) {
                            tribes.add(t);
                        }

                        if (tribes.isEmpty())
                            break;
                        t = tribes.first();
                    } while (day == t.getDay());

                    for (Attack attack : batchedAttacks) {
                        int index = attack.getIndex();
                        Integer wallPiece = wall.get(index);
                        if (wallPiece == null) wallPiece = 0;
                        wallPiece = Math.max(wallPiece, attack.getStrength());
                        wall.put(index, wallPiece);
                    }
                }

                bw.write("Case #" + (i + 1) + ": " + numAttacks);
                bw.newLine();
            }
        } finally {
            try {
                if (br != null) br.close();
                if (bw != null) bw.close();
            } catch (IOException ex) {
                ex.printStackTrace();
            }
        }
    }

    private static int[] convertToInts(String[] strings) {
        int[] ints = new int[strings.length];
        for (int i = 0; i < strings.length; i++) {
            ints[i] = Integer.parseInt(strings[i]);
        }

        return ints;
    }
}
