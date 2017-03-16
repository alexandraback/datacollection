package at.jaki.round1B.C;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;
import java.util.*;

public class C {

    //private static final String INPUT = "C-large.in";
    private static final String INPUT = "C-small-attempt0.in";
    //private static final String INPUT = "C-test.in";
    //private static final String OUTPUT = "C-large.out";
    private static final String OUTPUT = "C-small-attempt0.out";
    //private static final String OUTPUT = "C-test.out";

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new FileReader(INPUT));
        PrintWriter pw = new PrintWriter(OUTPUT);
        int totalTests = Integer.parseInt(br.readLine());
        for (int testNo = 1; testNo <= totalTests; testNo++) {
            String[] temp = br.readLine().split(" ");
            int n = Integer.parseInt(temp[0]);
            int m = Integer.parseInt(temp[1]);
            String[] zips = new String[n];
            Map<Integer, List<Integer>> graph = new HashMap<Integer, List<Integer>>();
            String minCity = "99999";
            int minId = -1;
            for (int i = 0; i < n; i++) {
                zips[i] = br.readLine();
                graph.put(i + 1, new ArrayList<Integer>());
                if (zips[i].compareTo(minCity) < 0) {
                    minCity = zips[i];
                    minId = i;
                }
            }
            int[][] allPaths = new int[m][2];
            for (int i = 0; i < m; i++) {
                temp = br.readLine().split(" ");
                int a = Integer.parseInt(temp[0]);
                int b = Integer.parseInt(temp[1]);
                graph.get(a).add(b);
                graph.get(b).add(a);
                allPaths[i][0] = a;
                allPaths[i][1] = b;
            }

            ////System.out.println(Arrays.toString(zips));
            ////System.out.println(graph);
            ////System.out.println(minCity);
            ////System.out.println(minId);
            List<String> all = new ArrayList<String>();
            collectAll(all, minId + 1, zips, graph, new HashSet<Integer>(), "", new HashSet<Integer>(), new HashSet<Integer>(), n * 5, allPaths);

            Collections.sort(all);
            //System.out.println(all);
            //System.out.println(all.get(0));

            pw.print("Case #" + testNo + ": ");
            pw.println(all.get(0));

        }

        pw.flush();
        pw.close();

    }

    private static void collectAll(List<String> all, int currCity, String[] zips, Map<Integer, List<Integer>> graph, Set<Integer> usedPaths, String currPath, Set<Integer> visitedCities, Set<Integer> openReturns, int targetLength, int[][] allPaths) {
        String newPath = visitedCities.contains(currCity) ? currPath : currPath.concat(zips[currCity - 1]);
        //System.out.println("In city " + zips[currCity - 1] + " with path: " + newPath);
        visitedCities.add(currCity);
        if (newPath.length() == targetLength) {
            //System.out.println("Save: " + newPath);
            all.add(newPath);
            return;
        }

        List<Integer> tempOR = new ArrayList<Integer>(openReturns.size());
        for (int x : openReturns) {
            tempOR.add(x);
        }

        for (int or : tempOR) {
            int[] trip = allPaths[or];
            if (trip[0] == currCity) {
                openReturns.remove(or);
                //System.out.println("go back");
                collectAll(all, trip[1], zips, graph, usedPaths, newPath, visitedCities, openReturns, targetLength, allPaths);
                openReturns.add(or);
            } else if (trip[1] == currCity) {
                openReturns.remove(or);
                //System.out.println("go back");
                collectAll(all, trip[0], zips, graph, usedPaths, newPath, visitedCities, openReturns, targetLength, allPaths);
                openReturns.add(or);
            }
        }

        for (int pathId = 0; pathId < allPaths.length; pathId++) {
            if (usedPaths.contains(pathId)) continue;
            int[] trip = allPaths[pathId];
            if (trip[0] == currCity && !visitedCities.contains(trip[1])) {
                boolean remNewCityFromVisited = !visitedCities.contains(trip[1]);
                openReturns.add(pathId);
                usedPaths.add(pathId);
                //System.out.println("go forth");
                collectAll(all, trip[1], zips, graph, usedPaths, newPath, visitedCities, openReturns, targetLength, allPaths);
                usedPaths.remove(pathId);
                openReturns.remove(pathId);
                if (remNewCityFromVisited) {
                    visitedCities.remove(trip[1]);
                }
            } else if (trip[1] == currCity && !visitedCities.contains(trip[0])) {
                boolean remNewCityFromVisited = !visitedCities.contains(trip[0]);
                openReturns.add(pathId);
                usedPaths.add(pathId);
                //System.out.println("go forth");
                collectAll(all, trip[0], zips, graph, usedPaths, newPath, visitedCities, openReturns, targetLength, allPaths);
                usedPaths.remove(pathId);
                openReturns.remove(pathId);
                if (remNewCityFromVisited) {
                    visitedCities.remove(trip[0]);
                }
            }
        }
        ////System.out.println("Drop back");
    }
}
