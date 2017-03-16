import java.io.File;
import java.io.FileNotFoundException;
import java.io.PrintWriter;
import java.util.*;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Mark
 */
public class Pogo {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  static int destX, destY;
  static boolean[][] visited;
  static int MIN = 200;
  
  public static void print(String text) {
    System.out.println(text);
  }
  
  static class Node implements Comparable<Node> {
    Node prev;
    int x;
    int y;
    int cost;
    int ordering;
    
    Node(Node prev, int x, int y, int cost, int ordering) {
      this.prev = prev;
      this.x = x;
      this.y = y;
      this.cost = cost;
      this.ordering = ordering;
    }

    @Override
    public int compareTo(Node t) {
      return Integer.valueOf(ordering).compareTo(Integer.valueOf(t.ordering));
    }
    
    @Override
    public String toString() {
      return "("+x+", "+y+")";
    }
  }
  
  static void expandNode(Node node, Collection fringe) {
    //print("Expanding node: "+node);
    if(!visited[node.x+MIN][node.y+MIN]) {
      visited[node.x+MIN][node.y+MIN] = true;
      int x = node.x;
      int y = node.y;
      int d = node.cost+1;
      addNode(x+d, y, node, fringe);
      addNode(x-d, y, node, fringe);
      addNode(x, y+d, node, fringe);
      addNode(x, y-d, node, fringe);
    }
  }
  
  static void addNode(int x, int y, Node prev, Collection fringe) {
    if(Math.abs(x) <= MIN && Math.abs(y) <= MIN && !visited[x+MIN][y+MIN]) {
    //print("Expanding node: "+adding);
    int cost = prev.cost + 1;
    int dx = destX - x;
    int dy = destY - y;
    //int diff = Math.abs(dx)+Math.abs(dy);
    //int dist = diff + (cost*(cost+1))/2;
    //double est = (Math.sqrt(1+8*dist) - 1) * 0.5;
    //int ordering = (int)Math.ceil(est) - cost;
    int ordering = cost;
    Node node = new Node(prev, x, y, cost, ordering);
    //print("Node: "+node+" ordering: "+ordering+" cost: "+cost+" diff: "+diff+" dist: "+dist);
    fringe.add(node);
    } else {
      //print("Didn't expand: "+x+" "+y);
    }
  }
  
  static Node search() {
    PriorityQueue<Node> fringe = new PriorityQueue<Node>();
    Node start = new Node(null, 0, 0, 0, 0);
    
    visited = new boolean[2*MIN+1][2*MIN+1];
    
    fringe.add(start);
    
    while(!fringe.isEmpty()) {
      Node node = fringe.peek();
      if(node.x==destX && node.y==destY) {
        print("Destingation reached");
        return fringe.poll();
      }
      expandNode(fringe.poll(), fringe);
    }
    
    return null;
  }

  /**
   * @param args the command line arguments
   */
  public static void main(String[] args) {
    try {
      File file = new File(inputFileName);
      Scanner in = new Scanner(file);
      file = new File(outputFileName);
      PrintWriter out = new PrintWriter(file);
      
      
      int num = in.nextInt();
      
      for(int n=1; n<=num; n++) {
        destX = in.nextInt();
        destY = in.nextInt();
        
        Node node = search();
        
        LinkedList<String> ll = new LinkedList<String>();
        
        int px = node.x;
        int py = node.y;
        print("node: "+node);
        while(node.prev!=null) {
          print("prev: "+node.prev);
          node = node.prev;
          String s = "";
          if(px>node.x) {
            s = "E";
          }
          if(px<node.x) {
            s = "W";
          }
          if(py>node.y) {
            s = "N";
          }
          if(py<node.y) {
            s = "S";
          }
          px = node.x;
          py = node.y;
          ll.addFirst(s);
        }
        
        String path = "";
        ListIterator<String> it = ll.listIterator();
        
        while(it.hasNext()) {
          String s = it.next();
          path += s;
        }
          
        String str = "Case #"+n+": "+path;
        
        print(str);
        out.println(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(Pogo.class.getName()).log(Level.SEVERE, null, ex);
    }
  }
}
