import java.util.*;

public class C
{
  class Node
  {
    int id;
    boolean visited;
    boolean isStart;
    List<Node> neighbors = new ArrayList<Node>();
  }

  int N;
  List<Node> startNodes = new ArrayList<Node>();
  List<Node> endNodes = new ArrayList<Node>();
  List<Node> allNodes = new ArrayList<Node>();
  int[] bffs;
  

  public C(int N)
  {
    this.N = N;
    
    bffs = new int[N];
    
    for(int i = 0; i < N; ++i)
    {
      Node start = new Node();
      start.id = i;
      start.isStart = true;
      
      Node end = new Node();
      end.id = i;
      
      start.neighbors.add(end);
      
      startNodes.add(start);
      endNodes.add(end);
      allNodes.add(start);
      allNodes.add(end);
    }
  }
  
  public void setBFF(int node, int bffNode)
  {
    endNodes.get(node).neighbors.add(startNodes.get(bffNode));
    bffs[node] = bffNode;
  }
  
  public int solve()
  {
    List<Integer> nodes = new ArrayList<>();
    
    for(int i = 0; i < N; ++i)
      nodes.add(i);
      
    return solve(new ArrayList<Integer>(), nodes);
  }
  
  public int solve(List<Integer> picked, List<Integer> nodes)
  {
    /*for(Integer i : picked)
      System.out.print(i + " ");
    System.out.println();*/
    
    int best = getValidSize(picked);
  
    for(int i = 0; i < nodes.size(); ++i)
    {
      Integer node = nodes.get(i);
      picked.add(node);
      nodes.remove(node);
      
      int now = solve(picked,nodes);
      
      if(now > best)
        best = now;
      
      nodes.add(i,node);
      picked.remove(node);
    }
    
    return best; 
  }
  
  public int getValidSize(List<Integer> picked)
  {
    if(picked.size() == 0)
      return 0;
  
    boolean valid = true;
    
    for(int i = 0; i < picked.size(); ++i)
    {
      int now = picked.get(i);
      int left;
      
      if(i == 0)
        left = picked.get(picked.size()-1);
      else
        left = picked.get(i-1);
        
      int right;
      
      if(i+1 == picked.size())
        right = picked.get(0);
      else
        right = picked.get(i+1);
        
      if(bffs[now] == left || bffs[now] == right)
      {
        continue;
      }
      else
      {
        valid = false;
        break;
      }
    }
    
    if(valid)
      return picked.size();
    return 0;
  }
  
  public void resetState()
  {
    for(Node node : allNodes)
      node.visited = false;
  }
  
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    
    int T = in.nextInt();
    
    for(int i = 0; i < T; ++i)
    {
      int caseT = i+1;
      
      int N = in.nextInt();
      
      C c = new C(N);
      
      for(int e = 0; e < N; ++e)
      {
        int bff = in.nextInt()-1;
        c.setBFF(e,bff);
      }
      
      int result = c.solve();
      
      String resultString = ""+result;
      
      System.out.println("Case #"+caseT+": "+resultString);
    }
  }
}
