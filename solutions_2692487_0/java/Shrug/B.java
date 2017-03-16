import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Collections;


public class B {
    public static ArrayList<Integer> motes;
    
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

        int cases = Integer.parseInt(br.readLine());

        for(int c = 1; c <= cases; c++) {
            String[] pieces = br.readLine().split(" ");
            int myMote = Integer.parseInt(pieces[0]);
            int otherMotes = Integer.parseInt(pieces[1]);
            motes = new ArrayList<Integer>();
            
            pieces = br.readLine().split(" ");
            for(int i = 0; i < otherMotes; i++)
                motes.add(Integer.parseInt(pieces[i]));
            Collections.sort(motes);
            
            int moves = 0;
            int minMoves = motes.size();
            
            // Print motes
//            System.out.print("("+moves+") "+myMote+" vs ");
//            for(int i = 0; i < motes.size(); i++)
//                System.out.print(motes.get(i)+" ");
//            System.out.println();
            
            while(motes.size() > 0) {
                if(motes.get(0) < myMote) {
                    myMote += motes.remove(0);
                }
                else {
                    // Add or remove?
                    if(stepsToNextByAdding(myMote) < stepsToNextByRemoving()) {
                        while(myMote <= motes.get(0)) {
                            moves++;
                            myMote += myMote-1;
                        }
                    }
                    else {
                        moves += motes.size();
                        motes.clear();
                    }
                }
                
                // Print motes
//                System.out.print("("+moves+") "+myMote+" vs ");
//                for(int i = 0; i < motes.size(); i++)
//                    System.out.print(motes.get(i)+" ");
//                System.out.println();
            }
            
            minMoves = Math.min(minMoves, moves + motes.size());
            System.out.println("Case #"+c+": "+minMoves);
        }
    }
    
    public static int stepsToNextByAdding(int myMote) {
        int steps = 0;
        
        while(myMote <= motes.get(0)) {
            myMote += myMote-1;
            steps++;
            
            if(myMote == 1) {
                steps = Integer.MAX_VALUE;
                break;
            }
        }
        
        return steps;
    }
    
    public static int stepsToNextByRemoving() {
        return motes.size();
    }
}
