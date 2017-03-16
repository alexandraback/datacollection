import java.io.*;
import java.util.*;

class Ver {
    public int getV() {
        return v;
    }

    int v;

    Ver(int x) {
        v = x;
    }

    @Override
    public boolean equals(Object ver) {
        Ver t = (Ver) ver;
        if (this.v == t.v) {
            return true;
        }
        return false;
    }

    @Override
    public int hashCode() {
        return v;
    }
}

public class DiamondInheritance {
    public static void main(String[] args) {
        int T, counter = 1;
        try {
            BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
            BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(new FileOutputStream(new File("output.txt"))));
            String input = reader.readLine();

            T = Integer.parseInt(input);
            while (T-- > 0) {


                input = reader.readLine();
                String[] in;
                int N;
                N = Integer.parseInt(input);
                List<Ver> vertices = new ArrayList<Ver>();
                Map<Ver, List<Ver>> relations = new HashMap<Ver, List<Ver>>();
                //System.out.println("one");
                for (int i = 0; i < N; i++) {
                    List<Ver> relation = new ArrayList<Ver>();
                    input = reader.readLine();
                    in = input.split(" ");
                    int M = Integer.parseInt(in[0]);
                    for (int j = 1; j <= M; j++) {
                        relation.add(new Ver(Integer.parseInt(in[j])));
                    }
                    //System.out.print("relations for: " + i);
                    //for(Ver v:relation)
                    {
                    //    System.out.print(" " + v.getV());
                    }
                   // System.out.println();
                    Ver v = new Ver(i + 1);
                    relations.put(v, relation);
                    vertices.add(v);
                }
                //System.out.println("done");
                Set<Ver> visited = new HashSet<Ver>();
                List<Ver> queue = new ArrayList<Ver>();
                Set<Ver> onceVisited = new HashSet<Ver>();
                queue.add(vertices.get(0));
                boolean sol = false;
                boolean flag = true;
                while (flag) {
                    while (!queue.isEmpty()) {
                        Ver vertex = queue.get(0);
                        queue.remove(vertex);
                        visited.add(vertex);
                        onceVisited.add(vertex);
                        for (Ver v : relations.get(vertex)) {
                            //System.out.println("getting relations for:"+vertex.getV());
                            if (visited.contains(v)) {
                                sol = true;
                                flag = false;
                                break;
                            } else {
                                queue.add(v);
                                visited.add(v);
                                onceVisited.add(v);
                                //System.out.println("Adding: "+v.getV()+" to queue");
                            }
                        }
                    }
                    if (onceVisited.size() == N) {
                        flag = false;
                    } else {
                        for (Ver v : vertices) {
                            if (!onceVisited.contains(v)) {
                                //System.out.println("queue empty: adding"+v.getV());
                                queue.add(v);
                                visited=new HashSet<Ver>();
                                break;
                            }
                        }
                    }
                }
                String ans;
                if (sol) {
                    ans = "Yes";
                } else {
                    ans = "No";
                }
                writer.write("Case #" + counter + ": " + ans);
                writer.write("\n");
                counter++;
                writer.flush();
            }
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

}
