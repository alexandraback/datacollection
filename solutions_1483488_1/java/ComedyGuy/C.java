import java.util.*;

public class C {

    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        int testCount = scanner.nextInt();
        HashSet<String> hashResult = new HashSet<String>();
        for (int test = 1; test <= testCount; test++){
            int min = scanner.nextInt();
            int max = scanner.nextInt();
            int total=0;
            for (Integer i=min; i<=max;i++){
                char[]numChar= i.toString().toCharArray();
                for (int k=0; k<=numChar.length-1;k++){

                    // Move ponteiro
                    char charTemp=numChar[numChar.length-1];
                    for (int j=numChar.length-2;j>=0;j--){
                        numChar[j+1]=numChar[j];
                    }
                    numChar[0]=charTemp;
                    Integer result = Integer.parseInt(new String(numChar));
                    if(i<result && result <=max) {
                        hashResult.add(i.toString()+result.toString());
                        total+=1;
                    }

                }

            }
            System.out.println("Case #" + (test) + ": "+hashResult.size());
            hashResult.clear();
        }
    }

}
