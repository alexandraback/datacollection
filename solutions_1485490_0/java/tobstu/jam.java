/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

import java.io.FileNotFoundException;
import java.util.Scanner;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.regex.Pattern;

import java.text.*;
import java.util.ArrayList;
import java.util.Queue;

/**
 *
 * @author Tobi
 */
public class jam {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int T = s.nextInt(); //number of testcases
        for(int t = 1; t <= T; t++) {
            int N = s.nextInt(); //number of boxe-batches
            int M = s.nextInt(); //number of toy-batches
            ArrayList<Batch> boxes = new ArrayList<Batch>(N);
            for(int n = 0; n < N; n++)
                boxes.add(new Batch(s.nextBigInteger().longValue(), s.nextInt()));
            ArrayList<Batch> toys = new ArrayList<Batch>(M);
            for(int m = 0; m < M; m++)
                toys.add(new Batch(s.nextBigInteger().longValue(), s.nextInt()));
            
            long max = step(0, 0, 0, 0, boxes.toArray(new Batch[boxes.size()]), toys.toArray(new Batch[toys.size()]));
            System.out.println("Case #" + t + ": " + max);
        }
    }
    
    private static long step(int boxBatch, long boxOffset, int toyBatch, long toyOffset, Batch[] boxes, Batch[] toys) {
        if(boxBatch > boxes.length || toyBatch > toys.length)
            return 0;
        //System.out.println(boxBatch + "(" + boxOffset + ") | " + toyBatch + "(" + toyOffset + ")");
        long matches = 0;
        long newBoxOffset,  newToyOffset;
        int newToyBatch, newBoxBatch;
        long[] shifts = new long[3]; //0 = shift boxes, 1 = shift Toys, 2 = shift Both        
        if(toys[toyBatch].type == boxes[boxBatch].type) {
            if(toys[toyBatch].number - toyOffset < boxes[boxBatch].number - boxOffset)
                matches = toys[toyBatch].number - toyOffset;
            else
                matches = boxes[boxBatch].number - boxOffset;
            //System.out.println("matched " + matches);
            newBoxOffset = (boxOffset + matches >= boxes[boxBatch].number ? 0 : boxOffset + matches);
            newBoxBatch =  boxOffset + matches >= boxes[boxBatch].number ? boxBatch + 1 : boxBatch;
            newToyOffset = (toyOffset + matches >= toys[toyBatch].number ? 0 : toyOffset + matches);
            newToyBatch =  toyOffset + matches >= toys[toyBatch].number ? toyBatch + 1 : toyBatch;
            if(newToyBatch < toys.length && newBoxBatch < boxes.length)
                shifts[2] = step(newBoxBatch, newBoxOffset, newToyBatch, newToyOffset, boxes, toys);
        } else {
            newBoxOffset = newToyOffset = 0;
            newBoxBatch = boxBatch + 1;
            newToyBatch = toyBatch + 1;
            if(newBoxBatch < boxes.length)
                shifts[0] = step(newBoxBatch, newBoxOffset, toyBatch, toyOffset, boxes, toys);
            if(newToyBatch < toys.length)
                shifts[1] = step(boxBatch, boxOffset, newToyBatch, newToyOffset, boxes, toys);
        }
        
        long subRes = shifts[0];
        if(subRes < shifts[1])
            subRes = shifts[1];
        if(subRes < shifts[2])
            subRes = shifts[2];
        return subRes + matches;
    }
}

class Batch {
    public long number;
    public int type;
    
    public Batch(long n, int t) {
        number = n;
        type = t;
//        System.out.println("Batch: " + n + "x" + t);
    }
}
