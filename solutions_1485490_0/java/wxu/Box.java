package codejam.round1c;

import java.io.*;
import java.util.ArrayList;
import java.util.List;

class Prod{
    long quantity;
    long type;

    Prod(long quantity, long type) {
        this.quantity = quantity;
        this.type = type;
    }

    public Prod(Prod item) {
        this.quantity = item.quantity;
        this.type = item.type;
    }

    @Override
    public String toString() {
        return String.format("%d %d", quantity, type);
    }
}

public class Box {
    public static void main(String[] args) throws IOException {
        InputStream is;
        OutputStream os;
        if (args.length > 0) {
            is = new FileInputStream(args[0]);
        } else {
            is = System.in;
        }

        if (args.length > 1) {
            os = new FileOutputStream(args[1]);
        } else {
            os = System.out;
        }

        BufferedWriter writer = new BufferedWriter(new OutputStreamWriter(os));
        BufferedReader inputReader = new BufferedReader(new InputStreamReader(is));
        String firstLine = inputReader.readLine();
        int count_of_cases = Integer.parseInt(firstLine);

        for (int idx_of_case = 1; idx_of_case <= count_of_cases; idx_of_case++) {
            String[] nums = inputReader.readLine().split(" ");

            int line1_count = Integer.parseInt(nums[0]);
            int line2_count = Integer.parseInt(nums[1]);

            String line1 = inputReader.readLine();
            String line2 = inputReader.readLine();

            String[] line1_prods = line1.split(" ");
            ArrayList<Prod> prods1 = new ArrayList<Prod>();
            for (int i = 0; i < line1_count; i++) {
                prods1.add(new Prod(Long.parseLong(line1_prods[2 * i]), Long.parseLong(line1_prods[2 * i + 1])));
            }

            String[] line2_prods = line2.split(" ");
            ArrayList<Prod> prods2 = new ArrayList<Prod>();
            for (int i = 0; i < line2_count; i++) {
                prods2.add(new Prod(Long.parseLong(line2_prods[2 * i]), Long.parseLong(line2_prods[2 * i + 1])));
            }

            long c = count(prods1, prods2);

            writer.write(String.format("Case #%d: %s", idx_of_case, c));
            writer.newLine();
            System.out.println("=====================");

        }

        writer.close();
        inputReader.close();
    }

    private static long count(List<Prod> prods1, List<Prod> prods2) {
        long result = 0;

//        System.out.println(prods1);
//        System.out.println(prods2);

        if (prods1.size() == 0 || prods2.size() == 0) {
            return 0;
        }

        List<Prod> prods11 = cloneList(prods1);
        List<Prod> prods22 = cloneList(prods2);

        Prod prod1 = prods11.get(0);
        Prod prod2 = prods22.get(0);

        if (prod1.type == prod2.type) {
            long matched = Math.min(prod1.quantity, prod2.quantity);

            result += matched;
            if (matched > 0) {
//                System.out.println(String.format("got %d", matched));
//                System.out.println(String.format("   %d %d  and %d %d", prod1.quantity, prod1.type, prod2.quantity, prod2.type));
                prod1.quantity -= matched;
                prod2.quantity -= matched;

//                System.out.println(prods11);
//                System.out.println(prods22);

                long count1 = count(prods11, prods22);

                result += count1;

            }else{
                long count1 = count(prods11.subList(1, prods11.size()), prods22);
                long count2 = count(prods11, prods22.subList(1, prods22.size()));

//                System.out.println(prods11);
//                System.out.println(prods22);
                result += Math.max(count1, count2);
//                System.out.println(String.format("%d   and %d", count1, count2));
            }


        }else{
            long count1 = count(prods11.subList(1, prods11.size()), prods22);
            long count2 = count(prods11, prods22.subList(1, prods22.size()));
//
//            System.out.println(prods11);
//            System.out.println(prods22);
            result += Math.max(count1, count2);
//            System.out.println(String.format("%d   and %d", count1, count2));

        }


        return result;
    }
    public static List<Prod> cloneList(List<Prod> list) {
        List<Prod> clone = new ArrayList<Prod>(list.size());
        for(Prod item: list)
            clone.add(new Prod(item));
        return clone;
    }
}
