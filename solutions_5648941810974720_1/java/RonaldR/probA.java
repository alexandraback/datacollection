package r1b2016;

/**
 * Created by Ronald on 4/30/2016.
 */
import java.io.BufferedReader;
import java.io.BufferedWriter;
import java.io.File;
import java.io.FileReader;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Collections;

public class probA{
    public static void main(String[] args) throws NumberFormatException, IOException{
        BufferedReader in = new BufferedReader( new FileReader("A-large.in"));
        int numinput = Integer.parseInt(in.readLine());
        File file = new File("output.txt");
        BufferedWriter bw = new BufferedWriter(new FileWriter(file));
        for( int currinput = 0; currinput < numinput; currinput++){
            System.out.print("Case #" + (1 + currinput) + ": ");
            bw.write("Case #" + (1 + currinput) + ": ");
            String unordered = in.readLine();
            ArrayList<Integer> numlist = new ArrayList<>();
            while(unordered.indexOf('Z') != -1){
                unordered = removechar('Z', unordered);
                unordered = removechar('E', unordered);
                unordered = removechar('R', unordered);
                unordered = removechar('O', unordered);
                numlist.add(0);
            }
            while( unordered.indexOf('X') != -1){
                unordered = removechar('S', unordered);
                unordered = removechar('I', unordered);
                unordered = removechar('X', unordered);
                numlist.add(6);

            }

            while(unordered.indexOf('G') != -1){
                unordered = removechar('E', unordered);
                unordered = removechar('I', unordered);
                unordered = removechar('G', unordered);
                unordered = removechar('H', unordered);
                unordered = removechar('T', unordered);
                numlist.add(8);
            }
            while(unordered.indexOf('W') != -1){
                unordered = removechar('T', unordered);
                unordered = removechar('W', unordered);
                unordered = removechar('O', unordered);
                numlist.add(2);
            }
            while( unordered.indexOf('H') != -1){
                unordered = removechar('T', unordered);
                unordered = removechar( 'H',unordered);
                unordered =  removechar('R', unordered);
                unordered = removechar('E', unordered);
                unordered = removechar('E', unordered);
                numlist.add(3);
            }

            while( unordered.indexOf('U') != -1){
                unordered = removechar('F', unordered);
                unordered = removechar('O', unordered);
                unordered = removechar('U', unordered);
                unordered = removechar('R', unordered);
                numlist.add(4);
            }
            while( unordered.indexOf('S') != -1){
                unordered = removechar('S', unordered);
                unordered = removechar('E', unordered);
                unordered = removechar('V', unordered);
                unordered = removechar( 'E', unordered);
                unordered = removechar('N', unordered);
                numlist.add(7);
            }
            while(unordered.indexOf('O') != -1){
                unordered = removechar('O', unordered);
                unordered = removechar('N', unordered);
                unordered = removechar('E', unordered);
                numlist.add(1);
            }
            while(unordered.indexOf('V') != -1){
                unordered = removechar('F', unordered);
                unordered = removechar('I', unordered);
                unordered = removechar('V', unordered);
                unordered = removechar('E' , unordered);
                numlist.add(5);
            }
            while( unordered.indexOf('I') != -1){
                unordered = removechar('N', unordered);
                unordered = removechar('I', unordered);
                unordered = removechar('N', unordered);
                unordered = removechar('E', unordered);
                numlist.add(9);
            }
            Collections.sort(numlist);
            for( int i =0;i < numlist.size();i++){
                String output = "" + numlist.get(i) ;
                System.out.print(output);
                bw.write(output);
            }
            System.out.print("\n");
            bw.write("\n");

        }
        bw.close();
    }
    public static String removechar(char letter, String unordered){
        int index = unordered.indexOf(letter);
        unordered = unordered.substring(0, index) + unordered.substring(index + 1);
        return unordered;

    }
}
