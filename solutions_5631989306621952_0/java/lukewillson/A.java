import java.io.File;
import java.io.FileInputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class A {
    static {
        try {
            System.setIn(new FileInputStream(new File("A-small-attempt0.in")));
        }
        catch(Exception e){
            System.err.println("Error setting input");
        }
        try {
            System.setOut(new PrintStream(new File("A-small-attempt0.out")));
        }
        catch(Exception e){
            System.err.println("Error setting output");
        }
    }
    public static void main(String[]args)throws Exception{
        Scanner sc = new Scanner(System.in);
        int cases = Integer.parseInt(sc.nextLine());

        for(int Case=1;Case<=cases;++Case){
            String input = sc.nextLine().trim();
            String str = "";
            for(char c:input.toCharArray()){
                if(str.length()==0) {
                    str += c;
                    continue;
                }
                if(c >= str.charAt(0)){
                    str = c + str;
                    continue;
                }
                else str +=c;
            }
            System.out.print("Case #"+Case+": ");
            System.out.println(str);

        }
    }
}
