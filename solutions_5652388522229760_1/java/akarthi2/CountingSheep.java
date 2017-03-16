import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.HashSet;


public class CountingSheep {
    private static final String INSOMNIA = "INSOMNIA";
    private static final String CASE = "Case #";
public static void main(String[] args) throws Exception {
//    String ipFileName = "A-small-attempt0.in";
//    BufferedReader br = new BufferedReader(new FileReader(new File(ipFileName)));
//    PrintWriter pw = new PrintWriter(ipFileName+".out");
      
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      PrintWriter pw = new PrintWriter(new OutputStreamWriter(System.out));
    
    long start = System.currentTimeMillis();
    int tcs = Integer.parseInt(br.readLine());
    for(int i=1;i<=tcs;++i){
        int currentVal = Integer.parseInt(br.readLine());
        String opFormat = CASE+i+": ";
        if(currentVal==0){
            pw.println(opFormat+INSOMNIA);
        }else{
            pw.println(opFormat+bruteForceIt(currentVal));
        }
    }
    
    
    long end = System.currentTimeMillis();
//    System.out.println("Total Time Taken : "+((end-start)/1000d)+"s");
    pw.flush();
    pw.close();
    br.close();
}

public static long bruteForceIt(int value){
    HashSet<Integer> digits = new HashSet<Integer>();
    for(int i=0;i<10;++i){
        digits.add(i);
    }
    long currentValue = value;
    while(!digits.isEmpty()){
        long tempValue = currentValue;
        while(tempValue>0){
            digits.remove((int)(tempValue%10));
            tempValue/=10;
        }
        currentValue+=value;
    }
    
    return (currentValue-value);
}
}

