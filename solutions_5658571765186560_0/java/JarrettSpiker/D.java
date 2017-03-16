import java.util.Scanner;

/**
 * Created by jarrett on 11/04/15.
 */
public class D {

    public static void main(String[] args){
        Scanner in = new Scanner(System.in);
        int numCases =Integer.parseInt(in.nextLine());
        for(int i = 0; i<numCases; i++){
            String[] tmp = in.nextLine().split(" ");
            Integer[] input = new Integer[tmp.length];
            int j;
            int a;
            int b;
            for(j=0;j<tmp.length; j++){
                input[j] = Integer.parseInt(tmp[j]);
            }

            int t = (input[0]);
            if(input[1] <= input[2]){
                a = input[1];
                b = input[2];
            }
            else{
                b = input[1];
                a = input[2];
            }
            char c;
            if(t == 1){
                if(a == 1){
                    if(b==1){
                        c = 'G';
                    }
                    else if(b==2){
                        c = 'G';
                    }
                    else if(b==3){
                        c = 'G';
                    }
                    else{
                        c = 'G';
                    }
                }
                else if(a == 2){

                    if(b==2){
                        c = 'G';
                    }
                    else if(b==3){
                        c = 'G';
                    }
                    else{
                        c = 'G';
                    }
                }
                else if(a == 3){
                    if(b==3){
                        c = 'G';
                    }
                    else{
                        c = 'G';
                    }
                }
                else{//a==4
                    c = 'G';
                }
            }
            else if(t == 2){
                if(a == 1){
                    if(b==1){
                        c = 'R';
                    }
                    else if(b==2){
                        c = 'G';
                    }
                    else if(b==3){
                        c = 'R';
                    }
                    else{
                        c = 'G';
                    }
                }
                else if(a == 2){

                    if(b==2){
                        c = 'G';
                    }
                    else if(b==3){
                        c = 'G';
                    }
                    else{
                        c = 'G';
                    }
                }
                else if(a == 3){
                    if(b==3){
                        c = 'R';
                    }
                    else{
                        c = 'G';
                    }
                }
                else{//a==4
                    c = 'G';
                }
            }
            else if(t == 3){
                if(a == 1){
                    if(b==1){
                        c = 'R';
                    }
                    else if(b==2){
                        c = 'R';
                    }
                    else if(b==3){
                        c = 'R';
                    }
                    else{
                        c = 'R';
                    }
                }
                else if(a == 2){

                    if(b==2){
                        c = 'R';
                    }
                    else if(b==3){
                        c = 'G';
                    }
                    else{
                        c = 'R';
                    }
                }
                else if(a == 3){
                    if(b==3){
                        c = 'G';
                    }
                    else{
                        c = 'G';
                    }
                }
                else{//a==4
                    c = 'R';
                }
            }
            else{//t==4
                if(a == 1){
                    if(b==1){
                        c = 'R';
                    }
                    else if(b==2){
                        c = 'R';
                    }
                    else if(b==3){
                        c = 'R';
                    }
                    else{
                        c = 'R';
                    }
                }
                else if(a == 2){

                    if(b==2){
                        c = 'R';
                    }
                    else if(b==3){
                        c = 'R';
                    }
                    else{
                        c = 'R';
                    }
                }
                else if(a == 3){
                    if(b==3){
                        c = 'R';
                    }
                    else{
                        c = 'G';
                    }
                }
                else{//a==4
                    c = 'G';
                }
            }
            String name = "";
            if(c == 'R'){
                name = "RICHARD";
            }
            else{
                name = "GABRIEL";
            }
            System.out.println("Case #" + (i+1) + ": " + name);

        }
    }
}
