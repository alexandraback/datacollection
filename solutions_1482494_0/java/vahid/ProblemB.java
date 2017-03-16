import java.io.*;
import java.util.LinkedList;
import java.util.Scanner;

/**
 * Created with IntelliJ IDEA.
 * User: Vahid
 * Date: 4/27/12
 * Time: 10:01 AM
 * To change this template use File | Settings | File Templates.
 */
public class ProblemB {
    public static class Level{
        int a,b;
        boolean completed1,completed2;

        public Level() {
            this.completed1 = false;
            this.completed2 = false;
        }
    }
    public static void main(String[] args) throws IOException {
        Scanner input = new Scanner(new BufferedReader(new FileReader("input.txt")));
        BufferedWriter output = new BufferedWriter(new FileWriter("ProblemB.txt"));

        int lines = input.nextInt();
        input.nextLine();
//        output.write("Case #"+(j+1)+": "+map.get(new Integer(c-item))+ " " + k);
//        output.newLine();

        for (int j=0; j<lines; j++){
            LinkedList<Level> list = new LinkedList<Level>();
            int n = input.nextInt();
            for (int i=0; i<n; i++){
                Level level = new Level();
                level.a = input.nextInt();
                level.b = input.nextInt();
                list.add(level);
            }

            int stars = 0;
            int played = 0;
            boolean found = false;
            while (stars < n*2){
                found = false;

                for (Level level:list){
                    if ((stars>=level.b) && level.completed1==false){
                        stars += 2;
                        played++;
                        found = true;
                        list.remove(level);
                        break;
                    }
                }

                if (!found){
                    for (Level level:list){
                        if ((stars>=level.b)){
                            stars += 1;
                            played++;
                            found = true;
                            list.remove(level);
                            break;
                        }
                    }

                }

                if (!found){
                    Level selected = null;
                    for (Level level:list){
                        if (((stars>=level.a) && (level.completed1==false))){
                            if (selected!=null){
                                if (level.b>selected.b) selected = level;
                            }
                            else selected = level;
                        }
                    }
                    if (selected!=null){
                        stars += 1;
                        played++;
                        found = true;
                        selected.completed1 = true;
                    }
                }

                if (!found) break;

            }

            String result = "Too Bad";
            if (found) result = "" + played;
            output.write("Case #"+(j+1)+": "+ result);
            output.newLine();

        }

        output.close();
        input.close();
    }
}
