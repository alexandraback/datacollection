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
public class Treasure {
  static final String inputFileName = "in.txt";
  static final String outputFileName = "out.txt";
  static Chest[] chests;
  static final int MAX_TYPE = 200;
  static Node[] nodes;
  static boolean[] visited;
  static int[] keys;
  
  public static void print(String text) {
    System.out.println(text);
  }
  
  public static class Node {
    int type;
    ArrayList<Chest> leaving;
    ArrayList<Chest> arriving;
    
    public Node(int type) {
      this.type = type;
      leaving = new ArrayList<Chest>();
      arriving = new ArrayList<Chest>();
    }
  }
  
  public static class Chest implements Comparable<Chest> {
    int type;
    int[] keys;
    int index;
    
    public Chest(int type, int[] keys, int index) {
      this.type = type;
      this.keys = keys;
      this.index = index;
    }

    @Override
    public int compareTo(Chest t) {
      return Integer.valueOf(index).compareTo(Integer.valueOf(t.index));
    }
  }
  
  public static Node breadthFirstSearch(Node startNode, Node endNode) {
    /** fringe - unexpanded nodes */
    LinkedList<Node> fringe = new LinkedList<Node>();
    
    Arrays.fill(visited, false);
    
    // expand start node
    expandNode(startNode, fringe);
    
    while(!fringe.isEmpty()) {
      if(fringe.peek().type==endNode.type) {
        return fringe.pop();
      }
      expandNode(fringe.pop(), fringe);
    }
    
    return null;
  }
  
  public static Node breadthFirstSearch(Chest startChest) {
    /** fringe - unexpanded nodes */
    LinkedList<Node> fringe = new LinkedList<Node>();
    
    Arrays.fill(visited, false);
    
    // expand start node
    int[] ks = startChest.keys;
    for(int j=0; j<ks.length; j++) {
      addNode(nodes[ks[j]], fringe);
    }
    
    while(!fringe.isEmpty()) {
      if(fringe.peek().type==startChest.type) {
        return fringe.pop();
      }
      expandNode(fringe.pop(), fringe);
    }
    
    return null;
  }
  
  public static void expandNode(Node node, Collection fringe) {
    // only expand node if it has not been expanded before
    if(!visited[node.type]) {
      visited[node.type] = true;
      // add nodes
      for(int i=0; i<node.leaving.size(); i++) {
        int[] ks = node.leaving.get(i).keys;
        for(int j=0; j<ks.length; j++) {
          addNode(nodes[ks[j]], fringe);
        }
      }
    }
  }
  
  public static void addNode(Node node, Collection fringe) {
    if(!visited[node.type]) {
      fringe.add(node);
    }
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
        int startKeys = in.nextInt();
        int N = in.nextInt();
        
        int[] firstKeys = new int[startKeys];
        for(int i=0; i<startKeys; i++) {
          int k = in.nextInt();
          firstKeys[i] = k;
        }
        
        chests = new Chest[N];
        for(int i=0; i<N; i++) {
          int type = in.nextInt();
          int nk = in.nextInt();
          int[] ks = new int[nk];
          for(int j=0; j<nk; j++) {
            ks[j] = in.nextInt();
          }
          chests[i] = new Chest(type, ks, i);
        }
        
        /*
        int testCase = 2;
        if(n==testCase) {
          print("case "+testCase+":");
          print("Num Chests: "+N);
          String st = "First keys:";
          for(int i=0; i<firstKeys.length; i++) {
            st+=" "+firstKeys[i];
          }
          print(st);
          for(int i=0; i<N; i++) {
            String s = chests[i].type+" ";
            for(int j=0; j<chests[i].keys.length; j++) {
              s+=chests[i].keys[j]+" ";
            }
            print(s);
          }
        }
        */
        
        nodes = new Node[MAX_TYPE+1];
        visited = new boolean[MAX_TYPE+1];
        keys = new int[MAX_TYPE+1];
        for(int i=0; i<firstKeys.length; i++) {
          keys[firstKeys[i]]++;
        }
        
        for(int i=0; i<chests.length; i++) {
          Chest c = chests[i];
          if(nodes[c.type]==null) {
            nodes[c.type] = new Node(c.type);
          }
          nodes[c.type].leaving.add(c);
          for(int j=0; j<c.keys.length; j++) {
            int t = c.keys[j];
            if(nodes[t]==null) {
              nodes[t] = new Node(t);
            }
            nodes[t].arriving.add(c);
          }
        }
        
        ArrayList<Integer> order = new ArrayList<Integer>();
        
        while(true) {
          
          ArrayList<Chest> cs = new ArrayList<Chest>();
          for(int i=0; i<keys.length; i++) {
            if(keys[i]>0) {
              Node node = nodes[i];
              if(node!=null) {
                for(int j=0; j<node.leaving.size(); j++) {
                  cs.add(node.leaving.get(j));
                }
              }
            }
          }
          
          if(cs.isEmpty()) {
            break;
          }
          
          Chest[] x = new Chest[cs.size()];
          x = cs.toArray(x);
          Arrays.sort(x);
          
          boolean foundOne = false;
          for(int i=0; i<x.length; i++) {
            Chest chest = x[i];
            Node node = nodes[chest.type];
            //print("chest: "+(chest==null)+" node: "+(node==null));
            /*
            int otherKeys = 0;
            for(int j=0; j<node.arriving.size(); j++) {
              Chest ch = node.arriving.get(j);
              for(int k=0; k<ch.keys.length; k++) {
                if(ch.keys[k]==node.type) {
                  otherKeys++;
                }
              }
            }*/
            boolean add = false;
            if(node.leaving.size()==1 || keys[node.type] > 1
                    || breadthFirstSearch(chest)!=null) {
              add = true;
            } else {
              for(int j=0; j<keys.length; j++) {
                if(keys[j]>0 && j!=node.type) {
                  if(breadthFirstSearch(nodes[j], node)!=null) {
                    add = true;
                    break;
                  }
                }
              }
            }
            if(add) {
              order.add(chest.index+1);
              node.leaving.remove(chest);
              keys[node.type]--;
              for(int j=0; j<chest.keys.length; j++) {
                int k = chest.keys[j];
                keys[k]++;
                nodes[k].arriving.remove(chest);
              }
              foundOne = true;
              break;
            }
          }
          
          if(!foundOne) {
            break;
          }
          
          
        }
        
        /*
        int[] v = new int[N];
        boolean[] used = new boolean[N];
        int[] sol = new int[N];
        boolean possible = false;
        boolean tooLong = false;
        if(n==6 || n==10 || n==11 || n==12 || n==14 || n==24) {
          tooLong = true;
        } else {
        while(true) {
          int startI = 0;
          Arrays.fill(keys, 0);
          Arrays.fill(used, false);
          for(int i=0; i<firstKeys.length; i++) {
            keys[firstKeys[i]]++;
          }
          boolean solved = true;
          for(int i=0; i<v.length; i++) {
            int x = -1;
            for(int j=0; j<N; j++) {
              if(!used[j]) {
                x++;
              }
              if(x == v[i]) {
                x = j;
                used[j] = true;
                sol[i] = x;
                //print("trying x"+i+" = "+(x+1));
                break;
              }
            }
            int t = chests[x].type;
            if(keys[t]>0) {
              keys[t]--;
              for(int j=0; j<chests[x].keys.length; j++) {
                keys[chests[x].keys[j]]++;
              }
            } else {
              //print("x"+i+" = "+(x+1)+" gives incorrect sol");
              startI = i;
              solved = false;
              break;
            }
          }
          
          if(solved) {
            //print("Correct solution found");
            possible = true;
            break;
          }
          
          boolean incremented = false;
          for(int i=startI; i>=0; i--) {
            v[i]++;
            if(v[i]>N-1-i) {
              v[i] = 0;
            } else {
              incremented = true;
              break;
            }
          }
          if(!incremented) break;
        }
        }*/
        
          
        String str = "Case #"+n+":";
        
        /*
        if(tooLong) {
          str+=" TIME OUT";
        } else if(!possible) {
          str+=" IMPOSSIBLE";
        } else {
          for(int i=0; i<N; i++) {
            str+=" "+(sol[i]+1);
          }
        }
        */
        
        
        if(order.size()!=N) {
          str+=" IMPOSSIBLE";
        } else {
          for(int i=0; i<order.size(); i++) {
            str+=" "+order.get(i);
          }
        }
        
        
        
        print(str);
        out.println(str);
      }
      
      in.close();
      out.close();
    } catch (FileNotFoundException ex) {
      Logger.getLogger(Treasure.class.getName()).log(Level.SEVERE, null, ex);
    }
  }
}
