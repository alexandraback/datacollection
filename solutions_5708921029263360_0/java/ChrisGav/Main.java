import java.io.File;
import java.io.FileNotFoundException;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Main {
    public static void main(String[] args) {
        File file = new File("dataset");
        Scanner sc = null;
        try {
            sc = new Scanner(file);
            int cases = sc.nextInt();
            sc.nextLine();

            for (int k = 1; k <= cases; k++) {
                System.out.print("Case #" + k + ": ");
                int J = sc.nextInt();
                int P = sc.nextInt();
                int S = sc.nextInt();
                int K = sc.nextInt();

                Set<Outfit> set = new HashSet<>();
                int loops = 0;
                Set<Outfit> giameta = new HashSet<>();

                for (int i = 1; i <= J; i++)
                    for (int j = 1; j <= P; j++)
                        for (int c = 1; c <= S; c++) {
                            Outfit outfit = new Outfit(i, j, c);
                            if (exists(set, outfit) != null) {
                                giameta.add(outfit);
                                continue;
                            }
                            loops++;
                            if (!set.contains(outfit))
                                set.add(outfit);
                        }


                boolean flag;
                K--;
                while (K-- > 0) {
                    flag = false;
                    for (Outfit outfit : giameta) {
                        loops++;
                        set.add(outfit);
                        if (K == 0) {
                            flag = true;
                            break;
                        }
                    }

                    if (!flag)
                        break;
                }



                System.out.println(loops);
                set.forEach(outfit -> System.out.println(outfit.toString()));
            }
        } catch (FileNotFoundException e) {
            System.out.println("File not found");
        }
    }

    public static Outfit exists(Set<Outfit> set, Outfit o2) {
        for (Outfit o1 : set) {
            if ((o1.shoes == o2.shoes && (o1.pants == o2.pants || o1.jacket == o2.jacket))
                    || (o1.pants == o2.pants && (o1.pants == o2.pants || o1.jacket == o2.jacket))
                    || (o1.jacket == o2.jacket && (o1.shoes == o2.shoes || o1.pants == o2.pants)))
                return o2;
        }

        return null;
    }

}
