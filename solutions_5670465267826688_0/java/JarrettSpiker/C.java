import java.io.*;
import java.util.Scanner;

/**
 * Created by jarrett on 10/04/15.
 */
public class C {
    public static void main(String[] args) throws IOException {
        //Scanner in = new Scanner(System.in);
        BufferedReader in = new BufferedReader(new FileReader(new File("CIn.txt")));
        int numCases =Integer.parseInt(in.readLine());
        for(int i = 0; i<numCases; i++){
            String[] input = in.readLine().split(" ");
            int l = Integer.parseInt(input[0]);
            int x = Integer.parseInt(input[1]);
            String subLine = in.readLine();
            String line = "";
            int j;
            for(j=0;j<x;j++){
                line = line.concat(subLine);
            }
            int p;
            int q;
            boolean found = false;
            if(reduce(line) == 'w')
                outer: for(p=0;p<line.length(); p++){
                    if(reduce(line.substring(0,p)) == 'i'){
                        for(q=p;q<line.length(); q++){
                            if(reduce(line.substring(p,q)) == 'j'){
                                if(reduce(line.substring(q,line.length())) =='k'){
                                    found = true;
                                    break outer;
                                }
                            }
                        }
                    }
                }
            else
                found = false;




            if(found)
                System.out.println("Case #" + (i+1) + ": YES");
            else
                System.out.println("Case #" + (i+1) + ": NO");
        }
    }
    public static char reduce(String in){
        if(in.length() == 0){
            return '0';
        }
        else{
            int i;
            char next;
            char tmp = in.charAt(0);
            for(i=1;i<in.length();i++){
                next = in.charAt(i);
                tmp = mul(tmp, next);
            }
            return tmp;
        }
    }




    public static char mul(char a, char b){
        if(a == 'i'){
            if(b == 'i'){
                return 'w';
            }
            else if(b == 'j'){
               return 'k';
            }
            else if(b == 'k'){
                return 'y';
            }
            else{ //b==1
                return 'i';
            }

        }
        else if(a == 'j'){
            if(b == 'i'){
                return 'z';
            }
            else if(b == 'j'){
                return 'w';
            }
            else if(b == 'k'){
                return 'i';
            }
            else{ //b==1
                return 'j';
            }
        }
        else if(a == 'k'){
            if(b == 'i'){
                return 'j';
            }
            else if(b == 'j'){
                return 'x';
            }
            else if(b == 'k'){
                return 'w';
            }
            else{ //b==1
                return 'k';
            }
        }
        else if(a == 'x'){
            if(b == 'i'){
                return '1';
            }
            else if(b == 'j'){
                return 'z';
            }
            else if(b == 'k'){
                return 'j';
            }
            else{ //b==1
                return 'x';
            }
        }
        else if(a == 'y'){
            if(b == 'i'){
                return 'k';
            }
            else if(b == 'j'){
                return '1';
            }
            else if(b == 'k'){
                return 'x';
            }
            else{ //b==1
                return 'y';
            }
        }
        else if(a == 'z'){
            if(b == 'i'){
                return 'y';
            }
            else if(b == 'j'){
                return 'i';
            }
            else if(b == 'k'){
                return '1';
            }
            else{ //b==1
                return 'z';
            }
        }
        else if(a == '1'){
            if(b == 'i'){
                return 'i';
            }
            else if(b == 'j'){
                return 'j';
            }
            else if(b == 'k'){
                return 'k';
            }
            else{ //b==1
                return '1';
            }
        }
        else{//a == w
            if(b == 'i'){
                return 'x';
            }
            else if(b == 'j'){
                return 'y';
            }
            else if(b == 'k'){
                return 'z';
            }
            else{ //b==1
                return 'w';
            }
        }
    }
}
