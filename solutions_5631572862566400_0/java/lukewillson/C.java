import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class C{
    static {
        try {
            System.setIn(new FileInputStream(new File("C-small-attempt1.in")));
        }
        catch(Exception e){
            System.err.println("Error setting input");
        }
        try {
            System.setOut(new PrintStream(new File("C-small.out")));
        }
        catch(Exception e){
            System.err.println("Error setting output");
        }
    }
    static int[]students;
    static int max;
    static int step;
    static ArrayList<Integer>maxList;
    public static void main(String[]args)throws Exception{
        Scanner sc = new Scanner(System.in);
        int cases = Integer.parseInt(sc.nextLine());

        for(int Case=1;Case<=cases;++Case){
            int count = sc.nextInt();
            max = 1;
            step = 0;
            students = new int[count];
            for(int i=0;i<count;++i){
                students[i] = sc.nextInt()-1;
            }


            for(int i=0;i<count;++i){
                ArrayList<Integer>circle = new ArrayList<>();
                circle.add(i);
                addToCircleForwards(circle,i);

            }
            System.out.print("Case #"+Case+": ");
            System.out.println(max);
            //System.err.println("Max: "+max);
            //System.err.println("List: "+maxList);

        }
    }
    public static void addToCircleForwards(ArrayList<Integer>circle, int lastStudent){

        if(!circle.contains(students[lastStudent])){
            circle.add(students[lastStudent]);
            //System.err.println(step++ +": Adding "+lastStudent+"'s bff, "+ students[lastStudent]);
            //System.err.println("New Circle"+circle);
            addToCircleForwards(circle,students[lastStudent]);
        }
        else if(lastStudent==students[students[lastStudent]]){

            //System.err.println("Going to add backwards");
            addToCircleBackwards(circle,lastStudent);
        }
        else if(students[lastStudent]==circle.get(0)){
            if(circle.size()>max) {
                max = circle.size();
                maxList = new ArrayList<>(circle);
            }
        }
        else if(!circle.isEmpty()){
            circle.remove(circle.size()-1);
            if(circle.size()>max) {
                max = circle.size();
                maxList = new ArrayList<>(circle);
            }
        }


    }
    public static void addToCircleBackwards(ArrayList<Integer>circle,int lastStudent) {


        ArrayList<Integer>potential = claimAsBff(lastStudent);
        //System.err.println("Got potentials for "+lastStudent);
        //System.err.println(potential);
        for(int i:potential){
            if(!circle.contains(i)){
                circle.add(i);
                if(circle.size()>max) {
                    max = circle.size();
                    maxList = new ArrayList<>(circle);
                }
                addToCircleBackwards(circle,i);
                //System.err.println(step++ +": Adding because "+i+"'s bff is "+lastStudent);
                //System.err.println("New Circle"+circle);
                circle.remove(new Integer(i));
            }
        }
    }
    public static ArrayList<Integer> claimAsBff(int student){
        ArrayList<Integer>list = new ArrayList<>();
        for(int i=0;i<students.length;++i){
            if(students[i]==student)
                list.add(i);
        }
        return list;
    }
}
