import java.io.File;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

import commons.FileUtilities;

public class Toys {
    public static void main(String[] args) throws IOException {
        List<String> cases = FileUtilities.readFile(new File(
                "C-small-attempt1.in"));

        int nrCases = new Scanner(cases.get(0)).nextInt();
        List<String> result = new LinkedList<String>();

        int line = 1;

        for (int i = 1; i <= nrCases; i++) {
            Scanner s = new Scanner(cases.get(line++));

            int N = s.nextInt();
            int M = s.nextInt();

            Scanner boxS = new Scanner(cases.get(line++));
            LinkedList<prod> boxes = new LinkedList<prod>();

            for (int j = 0; j < N; j++) {
                prod p = new prod();
                p.amount = boxS.nextLong();
                p.type = boxS.nextInt();
                boxes.add(p);
            }

            Scanner toyS = new Scanner(cases.get(line++));
            LinkedList<prod> toys = new LinkedList<prod>();

            for (int j = 0; j < M; j++) {
                prod p = new prod();
                p.amount = toyS.nextLong();
                p.type = toyS.nextInt();
                toys.add(p);
            }

            result.add("" + compute(boxes, toys));
            
        }
        
        FileUtilities.writeFile(result, new File("C-small-attempt1.out"));
    }

    @SuppressWarnings( "unchecked" )
    private static long compute(LinkedList<prod> boxes, LinkedList<prod> toys) {

        if (!(boxes.isEmpty() || toys.isEmpty())) {
            prod box = boxes.poll();
            prod toy = toys.poll();

            int produce = 0;
            if (box.type == toy.type) {
                LinkedList<prod> newboxes = (LinkedList<prod>) boxes.clone();
                LinkedList<prod> newtoys = (LinkedList<prod>) toys.clone();
                long producableAmount = Math.min(box.amount, toy.amount);
                if (!(box.amount - producableAmount <= 0)) {
                    prod remboxes = new prod();
                    remboxes.type = box.type;
                    remboxes.amount = box.amount - producableAmount;
                    newboxes.push(remboxes);
                }
                if (!(toy.amount - producableAmount <= 0)) {
                    prod remtoys = new prod();
                    remtoys.type = toy.type;
                    remtoys.amount = toy.amount - producableAmount;
                    newtoys.push(remtoys);
                }
                //System.out.println("produce " + producableAmount + " times " + toy.type);
                return producableAmount + compute(newboxes, newtoys);
            }

            LinkedList<prod> newboxes = (LinkedList<prod>) boxes.clone();
//            long changeAmount = Math.min(box.amount, toy.amount);
//            if (!(box.amount - changeAmount <= 0)) {
//                prod remboxes = new prod();
//                remboxes.type = box.type;
//                remboxes.amount = box.amount - changeAmount;
//                newboxes.push(remboxes);
//            }
            LinkedList<prod> newClonetoys = (LinkedList<prod>) toys.clone();
            newClonetoys.push(toy);
            long throwBoxes = compute(newboxes, newClonetoys);

            LinkedList<prod> newtoys = (LinkedList<prod>) toys.clone();
//            if (!(toy.amount - changeAmount <= 0)) {
//                prod remtoys = new prod();
//                remtoys.type = toy.type;
//                remtoys.amount = toy.amount - changeAmount;
//                newtoys.push(remtoys);
//            }
            LinkedList<prod> newCloneboxes = (LinkedList<prod>) boxes.clone();
            newCloneboxes.push(box);
            long throwToys = compute(newCloneboxes, newtoys);

            return Math.max(Math.max(throwBoxes, throwToys), produce);
        } else {
            return 0;
        }

    }

    public static class prod {
        public int type;
        public long amount;
        
        @Override
        public String toString() {
            return "(" + amount + " " + type + ")";
        }
    }
}
