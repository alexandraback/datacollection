// Author: Alejandro Sotelo Arevalo
package round1b;

import java.io.*;
import java.util.*;

public class C_TheBoredTravelingSalesman {
  // --------------------------------------------------------------------------------
  private static String ID="C";
  private static String NAME="small-attempt0";
  private static String STAGE="round1b";
  private static boolean STANDARD_OUTPUT=false;
  // --------------------------------------------------------------------------------
  private static BufferedReader reader=null;
  private static PrintStream output=null;
  // --------------------------------------------------------------------------------
  public static void main(String[] args) throws Throwable {
    try (BufferedReader bufferedReader=reader=new BufferedReader(new FileReader(new File("data/"+STAGE+"/"+ID+"-"+NAME+".in")))) {
      try (PrintStream printStream=output=STANDARD_OUTPUT?System.out:new PrintStream(new File("data/"+STAGE+"/"+ID+"-"+NAME+".out"))) {
        process();
      }
    }
  }
  // --------------------------------------------------------------------------------
  private static int N,M;
  private static String[] codes;
  private static List<Integer>[] ady;
  private static String answer=null;
  @SuppressWarnings("unchecked")
  private static void process() throws Throwable {
    for (int c=1,T=Integer.parseInt(reader.readLine()); c<=T; c++) {
      StringTokenizer tokenizer=new StringTokenizer(reader.readLine());
      N=Integer.parseInt(tokenizer.nextToken());
      M=Integer.parseInt(tokenizer.nextToken());
      ady=new List[N];
      codes=new String[N];
      for (int i=0; i<N; i++) {
        codes[i]=reader.readLine();
        ady[i]=new ArrayList<>();
      }
      for (int j=0; j<M; j++) {
        tokenizer=new StringTokenizer(reader.readLine());
        int x=Integer.parseInt(tokenizer.nextToken())-1,y=Integer.parseInt(tokenizer.nextToken())-1;
        ady[x].add(y);
        ady[y].add(x);
      }
      for (int i=0; i<N; i++) {
        Collections.sort(ady[i]);
      }
      answer=null;
      visitPermutations(new int[N],0,new boolean[N]);
      output.println("Case #"+c+": "+answer);
    }
  }
  private static void visitPermutations(int[] permutation, int i, boolean[] visited) {
    if (i==N) {
      ArrayDeque<Integer> route=new ArrayDeque<>();
      route.add(permutation[0]);
      for (int k=1; !route.isEmpty()&&k<permutation.length; k++) {
        while (!route.isEmpty()&&!ady[route.getLast()].contains(permutation[k])) {
          route.removeLast();
        }
        if (!route.isEmpty()) {
          route.addLast(permutation[k]);
        }
      }
      if (!route.isEmpty()) {
        StringBuilder builder=new StringBuilder();
        for (int v:permutation) {
          builder.append(codes[v]);
        }
        String string=builder.toString();
        if (answer==null||string.compareTo(answer)<0) {
          answer=string;
        }
      }
      return;
    }
    for (int v=0; v<N; v++) {
      if (!visited[v]) {
        visited[v]=true;
        permutation[i]=v;
        visitPermutations(permutation,i+1,visited);
        visited[v]=false;
      }
    }
  } 
}
  
