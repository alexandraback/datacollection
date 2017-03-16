import java.util.*;
import java.io.*;
import static java.lang.Math.*;

public class A{
    public static void main(String[] args) throws Exception{
        new A().run();
    }

    String dic = "yhesocvxduiglbkrztnwjpfmaq";
    String translate(String s){
        String ret = "";
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(c == ' ')ret += c;
            else ret += dic.charAt(s.charAt(i)-'a');
        }
        return ret;
    }

    void run() throws Exception{
        Scanner sc = new Scanner(System.in);
        //BufferedReader sc = new BufferedReader(new InputStreamReader(System.in));
        // only sc.readLine() is available
        int T = Integer.parseInt(sc.nextLine());
        for(int o = 1; o <= T; o++){
            System.out.printf("Case #%d: %s\n", o, translate(sc.nextLine()));
        }
    }
}
