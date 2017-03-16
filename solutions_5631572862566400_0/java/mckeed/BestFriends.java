import java.io.FileNotFoundException;
import java.io.FileReader;
import java.io.PrintWriter;
import java.io.UnsupportedEncodingException;
import java.util.ArrayList;
import java.util.Scanner;

/**
 * Created by danielmckee on 4/15/16.
 */
public class BestFriends {
    Scanner in;
    PrintWriter out;
    int number_of_students;
    ArrayList<Integer> orig_bffs;
    ArrayList<Integer> bffs;
    ArrayList<Boolean> visited;
    int longest_circle = 0;




    public BestFriends() throws FileNotFoundException, UnsupportedEncodingException {
        in = new Scanner(new FileReader("bestfriends_small_in.txt"));
        out = new PrintWriter("bestfriends_small_out.txt", "UTF-8");
    }



    private void parse(){
        int num_cases = in.nextInt();
        for (int i = 0; i < num_cases; i++) {
            number_of_students = in.nextInt();
            orig_bffs = new ArrayList<>();
            for (int j = 0; j < number_of_students; j ++ ) { orig_bffs.add(in.nextInt() - 1); }
            resetVisited();
            resetBFFs();
            longest_circle = 0;



            for (int j = 0; j < number_of_students; j++) {
                search(j);
            }


            int case_num = i + 1;
            //System.out.println("Case #" + case_num + ": " + output);
            out.println("Case #" + case_num + ": " + longest_circle);
        }
        out.close();
    }



    void search(int start) {
        resetVisited();
        int prev = -1;
        int curr = start;
        visited.set(start, true);
        int length = 1;
        while (true) {
            int next_bff = bffs.get(curr);


            if ( visited.get(next_bff) ) {
                if (next_bff == prev) {
                    // look for other pointing to me
                    boolean can_Add1 = false;
                    for (int i = 0; i < bffs.size(); i ++ ) {
                        //  other one cannot have been visited
                        if (bffs.get(i) == curr && !visited.get(i)) {
                            can_Add1 = true;
                        }
                    }

                    if (can_Add1) {
                        if (longest_circle < length + 1) {
                            longest_circle = length + 1;
                        }

                    }
                    else {
                        if (longest_circle < length + 1) {
                            longest_circle = length;
                        }
                    }
                }


                else {
                    if (longest_circle < length) {
                        longest_circle = length;
                    }
                }

                break;
            }

            prev = curr;
            curr = next_bff;
            length += 1;
            visited.set(curr, true);

        }
    }





    void resetVisited() {
        visited = new ArrayList<>();
        for (int j = 0; j < number_of_students; j ++) { visited.add(false); }
    }

    void resetBFFs() {
        bffs = new ArrayList<>();
        for (Integer i: orig_bffs) {
            bffs.add(new Integer(i));
        }
    }


    public static void main(String[] args) {
        BestFriends b = null;
        try {
            b = new BestFriends();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        } catch (UnsupportedEncodingException e) {
            e.printStackTrace();
        }
        b.parse();
    }



}
