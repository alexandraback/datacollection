package codejam140503;

import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

/**
 *
 * @author peter
 */
public class CTheBoredTravelingSalesman {

    public static void main(String[] args) throws Exception {
        try (BufferedReader br = new BufferedReader(new FileReader("/Users/peter/Downloads/C-small-attempt1.in"));
                PrintStream ps = new PrintStream("/Users/peter/Downloads/C-small-attempt1.out")) {
            int amount = readOneLineInteger(br);
            for (int i = 1; i <= amount; i++) {
                String[] values = br.readLine().split(" ");
                int N = Integer.valueOf(values[0]);
                int M = Integer.valueOf(values[1]);
                List<String> zipCodes = new ArrayList<>(N);
                for (int j = 0; j < N; j++) {
                    zipCodes.add(br.readLine());
                }
                List<Flight> flights = new ArrayList<>(M);
                for (int j = 0; j < M; j++) {
                    String[] flightData = br.readLine().split(" ");
                    flights.add(new Flight(Integer.valueOf(flightData[0]) - 1, Integer.valueOf(flightData[1]) - 1));
                }
                System.out.println(flights);

                String result = calculateOptimal(zipCodes, flights);
                System.out.println("Case #" + i + ": " + result);
                ps.print("Case #" + i + ": ");
                ps.println(result);
            }
        }
    }

    private static int readOneLineInteger(BufferedReader br) throws IOException {
        return Integer.valueOf(br.readLine());
    }

    public static Map<Integer, String> zipCodeMap;
    public static Map<String, Integer> zipCodeMapInverted;
    public static boolean[][] possibleFlights;

    private static String calculateOptimal(List<String> zipCodes, List<Flight> flights) {
        zipCodeMap = new HashMap<>();
        zipCodeMapInverted = new HashMap<>();
        for (int i = 0; i < zipCodes.size(); i++) {
            zipCodeMap.put(i, zipCodes.get(i));
            zipCodeMapInverted.put(zipCodes.get(i), i);
        }
        possibleFlights = new boolean[zipCodes.size()][zipCodes.size()];
        for (Flight f : flights) {
            possibleFlights[f.getStart()][f.getEnd()] = true;
            possibleFlights[f.getEnd()][f.getStart()] = true;
        }

        Collections.sort(zipCodes);
        
        return getOptimal(zipCodes, new LinkedList<>());
    }

    private static String getOptimal(List<String> zipCodes, LinkedList<Integer> list) {
        if(zipCodes.isEmpty()) {
            return isPossible(new LinkedList<>(), new LinkedList<>(list), "");
        }
        
        for(int i = 0; i < zipCodes.size(); i++) {
            String zipCode = zipCodes.remove(i);
            int nextLocation = zipCodeMapInverted.get(zipCode);
            list.add(nextLocation);
            
            String result = getOptimal(zipCodes, list);
            if(result != null) {
                return result;
            }
            
            list.removeLast();
            zipCodes.add(i, zipCode);
        }
        
        return null;
    }

    private static String isPossible(LinkedList<Integer> stack, LinkedList<Integer> list, String concat) {
        if(list.size() == 1) {
            return concat + zipCodeMap.get(list.get(0));
        }
        
        Integer location = list.removeFirst();
        stack.add(location);
        int next = list.get(0);
        
        while(!stack.isEmpty()) {
            Integer possibleStartLocation = stack.getLast();
            if(possibleFlights[possibleStartLocation][next]) {
                String result = isPossible(new LinkedList<>(stack), new LinkedList<>(list), concat + zipCodeMap.get(location));
                if(result != null) {
                    return result;
                }
            }
            stack.removeLast();
        }
        return null;
    }

    private static class Flight {

        private final int start;
        private final int end;

        public Flight(int start, int end) {
            this.start = start;
            this.end = end;
        }

        public int getStart() {
            return start;
        }

        public int getEnd() {
            return end;
        }

        @Override
        public String toString() {
            return "[" + start + " " + end + "]";
        }
    }
}
