import java.io.*;
import java.util.*;
public class Solve3 {
  static class Tab implements Comparable<Tab>{
    int[] tab;
	Tab(int[] t) {
	  this.tab = t;
	}
	public int compareTo(Tab other) {
      return tab[0] - other.tab[0];
    }
  }

  public static void main(String[] args) {
	MyScanner scanner = new MyScanner();
	PrintWriter out = new PrintWriter(new BufferedOutputStream(System.out));
	int n = scanner.nextInt();
    for(int t = 0; t < n; t++) {
      int m = scanner.nextInt();
	  ArrayList<Tab> tabs = new ArrayList<Tab>();
	  for(int i = 0; i < 2 * m - 1; i++) {
	    Tab tab = new Tab(new int[m]);
	    for(int j = 0; j < m; j++)
		  tab.tab[j] = scanner.nextInt();
		tabs.add(tab);
      }
	  Collections.sort(tabs);
	  int[][] tab2 = new int[m][m];
	  
	  int[] columns = new int[m];
	  int[] rows = new int[m];
	  for(int[] a : tab2) Arrays.fill(a, -1);
      if(tabs.get(0).tab[0] == tabs.get(1).tab[0]){
	    columns[0] = 1;
	    rows[0] = 1;
	    for(int i = 0; i < m; i++) {
		  tab2[0][i] = tabs.get(0).tab[i];
		  tab2[i][0] = tabs.get(1).tab[i];
		}
		tabs.remove(0);
		tabs.remove(0);
	  } else if (tabs.get(tabs.size()-1).tab[m-1] == tabs.get(tabs.size()-2).tab[m-1]) {
	  	columns[m-1] = 1;
	    rows[m-1] = 1;
		//System.out.println(rows[m-1] + " " + columns[m-1]);
	  	for(int i = 0; i < m; i++) {
		  tab2[m-1][i] = tabs.get(tabs.size()-1).tab[i];
		  tab2[i][m-1] = tabs.get(tabs.size()-2).tab[i];
		}
		tabs.remove(tabs.size()-1);
		tabs.remove(tabs.size()-1);
	  }
      tab2 = solve(0, columns, rows, tabs, tab2);
	  
	  out.print("Case #" + (t+1) + ": ");
	  //printTab(tab2);
      //System.out.println(m);
	  for(int i = 0; i < m; i++) {
	    
	    if(columns[i] == 0) {
		  for(int j = 0; j < m; j++)
		    out.print(tab2[i][j] + " ");
		} else if(rows[i] == 0) {
		  for(int j = 0; j < m; j++)
		    out.print(tab2[j][i] + " ");
		}
      }
	  out.println();
	}
	out.close();
  }
  public static void printTab(int[][] tab2) {
  	  for(int i = 0; i < tab2.length; i++){
	    for(int j = 0; j < tab2.length; j++)
		  System.out.print(tab2[i][j] + " ");
		System.out.println();
	  }
  }
  public static int[][] solve(int ind, int[] columns, int[] rows, ArrayList<Tab> tabs, int[][] tab) {
    //printTab(tab);
    if(ind == tabs.size()) { //printTab(tab); 
	return tab; }
	Tab t = tabs.get(ind);
    int[][] tab2 = cpy(tab);
	for(int i = 0; i < tab.length; i++) {
	  boolean match = true;
	  for(int j = 0; j < tab.length; j++)
	    if(tab2[i][j] != t.tab[j] && tab2[i][j] != -1) match = false;
	  if(match && columns[i] == 0){
	    columns[i] = 1;
		for(int j = 0; j < tab2.length; j++)
		  tab2[i][j] = t.tab[j];
		int[][] res = solve(ind+1, columns, rows, tabs, tab2);
		if(res != null)
		  return res;
		columns[i] = 0;
	  }
	}
	tab2 = cpy(tab);
	for(int i = 0; i < tab.length; i++) {
	  boolean match = true;
	  for(int j = 0; j < tab.length; j++)
	    if(tab2[j][i] != t.tab[j] && tab2[j][i] != -1) match = false;
	  if(match && rows[i] == 0){
	    rows[i] = 1;
		for(int j = 0; j < tab2.length; j++)
		  tab2[j][i] = t.tab[j];
		int[][] res = solve(ind+1, columns, rows, tabs, tab2);
		if(res != null)
		  return res;
		rows[i] = 0;
	  }
	}
    return null;	
  }
  public static int[][] cpy(int[][] tab) {
    int[][] tab2 = new int[tab.length][tab.length];
	for(int i = 0; i < tab.length; i++)
	for(int j = 0; j < tab.length; j++)
	  tab2[i][j] = tab[i][j];
	return tab2;
  }
  public static class MyScanner {
      BufferedReader br;
      StringTokenizer st;
 
      public MyScanner() {
         br = new BufferedReader(new InputStreamReader(System.in));
      }
 
      String next() {
          while (st == null || !st.hasMoreElements()) {
              try {
                  st = new StringTokenizer(br.readLine());
              } catch (IOException e) {
                  e.printStackTrace();
              }
          }
          return st.nextToken();
      }
 
      int nextInt() {
          return Integer.parseInt(next());
      }
 
      long nextLong() {
          return Long.parseLong(next());
      }
 
      double nextDouble() {
          return Double.parseDouble(next());
      }
 
      String nextLine(){
          String str = "";
	  try {
	     str = br.readLine();
	  } catch (IOException e) {
	     e.printStackTrace();
	  }
	  return str;
      }

   }
}
