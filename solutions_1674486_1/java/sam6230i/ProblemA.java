import java.io.*;
import java.util.*;

public class ProblemA {

  public static class Cell{

    public int pos;

    public int inherits = 0;

    public Set<Integer> list = new HashSet<Integer>();
    public Set<Integer> to = new HashSet<Integer>();

    public Cell(int pos){
      this.pos = pos;
    }

    public void incr(){
      this.inherits++;
    }
    
    public boolean addToList(Cell cell){
      boolean v = list.add(cell.pos);
      if(!v) return true;
      for(int p: cell.list){
        v = list.add(p);
        if(!v) return true;
      }
      inherits--;
      return false;
    }
  }

  public static void main(String... args) throws IOException {
//    BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
    BufferedReader reader = new BufferedReader(new FileReader("A-large.in"));
//    PrintWriter writer = new PrintWriter(System.out);
    PrintWriter writer = new PrintWriter("A-large.out");

    int cases = Integer.parseInt(reader.readLine());

    String [] split;

    Label:
    for(int i = 1; i <= cases; i++){
      writer.print("Case #" + i + ": ");
      int N = Integer.parseInt(reader.readLine());
      Cell [] cells = new Cell[N];
      for(int j = 0; j < N; j++){
        split = reader.readLine().split(" ");
        if(cells[j] == null)
          cells[j] = new Cell(j);
        for(int k = 1; k < split.length; k++){
          int a = Integer.parseInt(split[k]) - 1;
          if(cells[a] == null){
            cells[a] = new Cell(a);
          }
          cells[a].incr();
          cells[j].to.add(a);
        }
      }
      LinkedList<Cell> queue = new LinkedList<Cell>();
      boolean [] processed = new boolean[N];
      for(int j = 0; j < N; j++){
        if(cells[j].inherits == 0){
          queue.add(cells[j]);
          processed[j] = true;
        }
      }

      LinkedList<Cell> nQueue = new LinkedList<Cell>();
      while (!queue.isEmpty()){
        for(Cell cell: queue){
          for(int pos: cell.to){
            if(cells[pos].addToList(cell)){
              writer.println("Yes");
              continue Label;
            }else if(!processed[pos] && cells[pos].inherits == 0){
              nQueue.add(cells[pos]);
              processed[pos] = true;
            }
          }
        }
        queue.clear();
        queue.addAll(nQueue);
        nQueue.clear();
      }
      writer.println("No");
    }

    writer.flush();
  }
}
