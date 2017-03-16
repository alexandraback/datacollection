/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package googlecodejam;
import java.util.*;
import java.lang.*;
/**
 *
 * @author Tom
 */
public class TheBoredTravelingSalesman {
    public String[] cities;
    public int [][] edges;
    public static TheBoredTravelingSalesman[] readFile(Scanner input) {
        TheBoredTravelingSalesman[] puzzles = new TheBoredTravelingSalesman[input.nextInt()];
        
        for(int i = 0; i < puzzles.length; ++i) {
            String[] cities = new String[input.nextInt()];
            int[][] edges = new int[input.nextInt()][2];
            input.nextLine();
            for(int j = 0; j < cities.length; ++j) {
                cities[j] = input.nextLine();
            }
            
            for(int j = 0; j < edges.length; ++j) {
                edges[j][0] = input.nextInt() - 1;
                edges[j][1] = input.nextInt() - 1;
            }
            
            puzzles[i] = new TheBoredTravelingSalesman(cities, edges);
        }
        
        return puzzles;
    }
    
    private TheBoredTravelingSalesman(String[] cities, int[][] edges) {
        this.cities = cities;
        this.edges = edges;
    }
    private int[] order;
    private boolean[] visited;
    private boolean set;
    private String min;
    private void solve(int city, int number) {
        order[city] = number;
        visited[city] = true;
        
        if(number + 1 == cities.length) {
            String current = "";
            int[] from = new int[cities.length];
            int where = -1;
            boolean possible = true;
            for(int i = 0; i < cities.length; ++i) {
                if(order[i] == 0) {
                    where = i;
                    from[i] = -1;
                    current = cities[i];
                }
            }

            for(int i = 1; i <= number && possible; ++i) {
                for(int j = 0; j < cities.length && possible; ++j) {
                    if(order[j] == i) {
                        boolean found = false;
                        while(!found && possible) {
                            for(int k = 0; k < edges.length; ++k) {
                                if(edges[k][0] == where && edges[k][1] == j) {
                                    found = true;
                                } else if(edges[k][1] == where && edges[k][0] == j) {
                                    found = true;
                                }
                            }
                            
                            if(found) {
                                from[j] = where;
                                where = j;
                                current += cities[j];
                            } else {
                                where = from[where];
                                if(where == -1) {
                                    possible = false;
                                }
                            }
                        }
                    }
                }
            }
            
            if(possible) {
                if(!set) {
                    set = true;
                    min = current;
                } else {
                    if(current.compareTo(min) < 0) {
                        min = current;
                    }
                }
            }
        } else {
            for(int i = 0; i < cities.length; ++i) {
                if(!visited[i]) {
                    solve(i, number + 1);
                }
            }
        }
        
        order[city] = 0;
        visited[city] = false;
    }
    
    public String solve() {
        set = false;
        min = "";
        for(int i = 0; i < cities.length; ++i) {
            visited = new boolean[cities.length];
            order = new int[cities.length];
            solve(i, 0);            
        }
        
        return min;
    }
}
