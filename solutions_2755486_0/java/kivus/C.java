import java.util.*;
import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

/**
 *
 *
 */
public class C {
    public static void main(String[] args) {
         try {
             Scanner scanner = (new Scanner(new File("c:/codejam/src/input.txt")));


             FileOutputStream out = new FileOutputStream("c:/codejam/src/output.txt");

             int numberOfCases;
             numberOfCases = scanner.nextInt();

             PrintWriter wr = new PrintWriter(out);
             for (int i = 0; i < numberOfCases; i++) {
                 doCase(i + 1, scanner, wr);
             }
             wr.close();
             out.close();

         } catch (IOException e) {
             System.out.println("Error: " + e);
         }
     }



    private static void doCase(int caseNumber, Scanner scanner, PrintWriter wr) {

        TreeMap<Integer, Integer> wall = new TreeMap<Integer, Integer>();


        int n = scanner.nextInt();
        PriorityQueue<Tribe> queue = new PriorityQueue<Tribe>(n, new Comparator<Tribe>() {
            public int compare(Tribe o1, Tribe o2) {
                return o1.dayStart - o2.dayStart;
            }
        });

        for (int i = 0; i < n; i++) {
            Tribe t = new Tribe();
            t.tribeNum = (i+1);
            t.dayStart = scanner.nextInt();
            t.numAttacks = scanner.nextInt();
            t.west = scanner.nextInt();
            t.east = scanner.nextInt() - 1;
            t.strength = scanner.nextInt();
            t.deltaDays = scanner.nextInt();
            t.distanceTravel = scanner.nextInt();
            t.strengthChange = scanner.nextInt();
            queue.add(t);
        }

        int result = 0;
        int currentDay = 0;
        while (!queue.isEmpty()) {
            List<Tribe> list = new ArrayList<Tribe>();
            Tribe t = queue.poll();
            list.add(t);
            int attack = isAttackSuccessfull(wall, t);
//            if (attack > 0) {
//                System.out.println("Day: " + t.dayStart + ", tribe: " + t.tribeNum + " attack successful");
//            } else {
//                System.out.println("Day: " + t.dayStart + ", tribe: " + t.tribeNum + " attack failed");
//            }
            result += attack;
            while (true) {
                Tribe t1 = queue.peek();
                if (t1 == null) break;


                if (t1.dayStart == t.dayStart) {
                    t1 = queue.remove();
                    int a = isAttackSuccessfull(wall, t1);
//                    if (a > 0) {
//                        System.out.println("Day: " + t1.dayStart + ", tribe: " + t1.tribeNum + " attack successful");
//                    } else {
//                        System.out.println("Day: " + t1.dayStart + ", tribe: " + t1.tribeNum + " attack failed");
//                    }
                    result += a;
                    list.add(t1);
                } else {
                    break;
                }
            }

            // modify the wall and each tribe on the list
            for (int i = 0; i < list.size(); i++) {
                Tribe tribe = list.get(i);
                modifyWall(wall, tribe);
                tribe.numAttacks--;
                tribe.east += tribe.distanceTravel;
                tribe.west += tribe.distanceTravel;
                tribe.strength += tribe.strengthChange;
                tribe.dayStart += tribe.deltaDays;
                if (tribe.numAttacks > 0) {
                    queue.add(tribe);
                }
            }

        }



        wr.println("Case #" + caseNumber + ": " + result);
        System.out.println("Case #" + caseNumber + ": " + result);
        // ...
    }

    private static void modifyWall(TreeMap<Integer, Integer> wall, Tribe tribe) {
        int strengthWest = getStrengthAtPoint(wall, tribe.west);
        int strengthWest_1 = 0;
        if (strengthWest < tribe.strength) {
            strengthWest_1 = getStrengthAtPoint(wall, tribe.west - 1);
        }
        int strengthEast = getStrengthAtPoint(wall, tribe.east);
        int strengthEast_1 = 0;
        if (strengthEast < tribe.strength) {
            strengthEast_1 = getStrengthAtPoint(wall, tribe.east + 1);
        }
        if (strengthWest < tribe.strength) {
            Integer i = wall.get(tribe.west - 1);
            if (i == null) {
                wall.put(tribe.west - 1, strengthWest_1);
            }
            wall.put(tribe.west, tribe.strength);
        }
        if (strengthEast < tribe.strength) {
            Integer i = wall.get(tribe.east + 1);
            if (i == null) {
                wall.put(tribe.east + 1, strengthEast_1);
            }
            wall.put(tribe.east, tribe.strength);
        }
        NavigableMap<Integer, Integer> subMap = wall.subMap(tribe.west, false, tribe.east, false);
        for (Integer key : subMap.keySet()) {
            Integer value = subMap.get(key);
            if (value < tribe.strength) {
                subMap.put(key, tribe.strength);
            }
        }

//        // optimize map
//        Integer lower = wall.lowerKey(tribe.west);
//        if (lower == null) {
//            lower = tribe.west;
//        }
//        Integer higher = wall.higherKey(tribe.east);
//        if (higher == null) {
//            higher = tribe.east;
//        }
//        subMap = wall.subMap(lower, true, higher, true);
//        Iterator<Map.Entry<Integer, Integer>> it = subMap.entrySet().iterator();
//
//        while (it.hasNext()) {
//            Map.Entry<Integer, Integer> next = it.next();
//
//        }
//
//
    }

    private static int isAttackSuccessfull(TreeMap<Integer, Integer> wall, Tribe t) {
        // check if tribe with strength t can break the wall

        int strengthWest, strengthEast;
        strengthWest = getStrengthAtPoint(wall, t.west);
        strengthEast = getStrengthAtPoint(wall, t.east);

        if (strengthWest < t.strength || strengthEast < t.strength) {
            return 1;
        }

        NavigableMap<Integer, Integer> subMap = wall.subMap(t.west, false, t.east, false);
        for (Map.Entry<Integer, Integer> entry : subMap.entrySet()) {
            if (entry.getValue() < t.strength) {
                return 1;
            }
        }
        return 0;
    }

    private static int getStrengthAtPoint(TreeMap<Integer, Integer> wall, int point) {
        int strengthWest;
        if (wall.containsKey(point)) {
            strengthWest = wall.get(point);
        } else {
            Integer westernBound = wall.lowerKey(point);
            if (westernBound == null) {
                strengthWest = 0;
            } else {
                strengthWest = wall.get(westernBound);
            }
        }
        return strengthWest;
    }


}

class Tribe {
    int tribeNum;
    int dayStart;
    int numAttacks;
    int west, east;
    int strength;
    int deltaDays;
    int distanceTravel;
    int strengthChange;
}

class WallHeights {
    int before;
    int after;
}