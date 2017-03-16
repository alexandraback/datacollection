import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.io.PrintWriter;


public class A {



    public static void main(String[] args) throws NumberFormatException, IOException {
        String name = "A";
        // TODO READER
        boolean isSmall = true;
        BufferedReader br;
        //BufferedReader br= new BufferedReader(new FileReader("bum.in"));
        if(isSmall) br = new BufferedReader(new FileReader(name+"-small-attempt0.in"));

        else br = new BufferedReader(new FileReader(name+"-large.in"));

        PrintWriter pw;
        if(isSmall) pw = new PrintWriter(name+"-small.txt", "UTF-8");
        else pw = new PrintWriter(name+"-large.txt", "UTF-8");

        int T=Integer.parseInt(br.readLine());
        for(int i = 0; i < T; i++){
            String tab =br.readLine();

            String a = solution(tab);


            System.out.print("Case #"+(i+1)+": "+a+"\n");
            pw.write("Case #"+(i+1)+": "+a+"\n");

        }
        pw.close();
    }


    static String solution(String tab){
        StringBuilder nov = new StringBuilder();
        nov.append(tab.charAt(0));
        for(int i=1; i<tab.length();i++){
            if(Character.getNumericValue(tab.charAt(i))>=Character.getNumericValue(nov.charAt(0)))nov.insert(0,tab.charAt(i));
            else nov.insert(i,tab.charAt(i));
            //System.out.println(nov.toString());
        }

        








        return nov.toString();
    }
}