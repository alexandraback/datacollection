import java.io.*;
import java.util.*;
import java.math.*;

class Flight {
    int from, to;
    public Flight(int from, int to) {
        this.from = from;
        this.to = to;
    }
}

class Node implements Comparable<Node> {
    int start;
    String flights;
    int currentZip;
    boolean[] visited;
    List<Integer> returns;
    public Node(int start, String flights, int currentZip, boolean[] visited, List<Integer> returns) {
        //System.out.println(flights);
        this.start = start;
        this.flights = flights;
        this.currentZip = currentZip;
        this.visited = visited;
        this.returns = returns;
    }
    public boolean goal() {
        if (!returns.isEmpty())
            return false;
        for (int i = 0; i < visited.length; i++)
            if (i != start && !visited[i])
                return false;
        return true;
    }
    @Override public int compareTo(Node that) {
        String thisOne = this.flights;
        String thatOne = that.flights;
        while (thisOne.length() < thatOne.length())
            thisOne += "0";
        while (thatOne.length() < thisOne.length())
            thatOne += "0";
        return new BigInteger(thisOne).compareTo(new BigInteger(thatOne));
    }
}

public class Csalesman {
    private static BigInteger answer(List<Integer> zips, List<Flight> flights) {
        PriorityQueue<Node> queue = new PriorityQueue<Node>();
        for (int i = 0; i < zips.size(); i++) {
            boolean[] visited = new boolean[zips.size()];
            visited[i] = true;
            queue.add(new Node(i, zips.get(i).toString(), i, visited, new ArrayList<Integer>()));
        }
        while (!queue.isEmpty()) {
            Node n = queue.poll();
            //System.out.println(n.flights);
            if (n.goal())
                return new BigInteger(n.flights);
            // Use all outbound flights
            for (int i = 0; i < zips.size(); i++) {
                if (!n.visited[i]) {
                    boolean okay = false;
                    for (Flight f: flights) {
                        //System.out.printf("%d %d  %d %d\n", f.from, f.to, n.currentZip, i);
                        if ((f.from == n.currentZip && f.to == i) || (f.from == i && f.to == n.currentZip)) {
                            //System.out.println("               ********************");
                            okay = true;
                        }
                    }
                    if (!okay)
                        continue;
                    boolean[] visited = n.visited.clone();
                    visited[i] = true;
                    List<Integer> returns = new ArrayList<Integer>(n.returns);
                    returns.add(n.currentZip);
                    queue.add(new Node(n.start, n.flights + zips.get(i), i, visited, returns));
                }
            }
            // Use all return flights
            for (int i = 0; i < n.returns.size(); i++) {
                List<Integer> returns = new ArrayList<Integer>(n.returns);
                int currentZip = returns.remove(i);
                boolean[] visited = n.visited.clone();
                queue.add(new Node(n.start, n.flights, currentZip, visited, returns));
            }
        }
        return null;
        //return new BigInteger("12345");
    }

    public static void main(String[] args) throws IOException {
        if (args.length != 1) {
            System.err.println("Usage: java Csalesman <file>");
            return;
        }

        BufferedReader in = new BufferedReader(new FileReader(args[0]));
        int t = Integer.parseInt(in.readLine());
        for (int i = 0; i < t; i++) {
            String[] nm = in.readLine().split("\\s+");
            int n = Integer.parseInt(nm[0]);
            int m = Integer.parseInt(nm[1]);
            List<Integer> zips = new ArrayList<Integer>();
            for (int j = 0; j < n; j++) {
                zips.add(Integer.parseInt(in.readLine()));
            }
            List<Flight> flights = new ArrayList<Flight>();
            for (int j = 0; j < m; j++) {
                String[] ft = in.readLine().split("\\s+");
                flights.add(new Flight(Integer.parseInt(ft[0])-1, Integer.parseInt(ft[1])-1));
            }
            System.out.printf("Case #%d: %s\n", i+1, answer(zips, flights));
        }
    }
}
