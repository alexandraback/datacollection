import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


public class password {
	public static void main(String[] args) throws IOException {
		FileInputStream file = new FileInputStream(args[0]);
        //DataInputStream in = new DataInputStream(file);
        Scanner ins = new Scanner(file);
        BufferedWriter out = new BufferedWriter(new FileWriter(args[1]));
        int n = ins.nextInt();     
        for (int i = 0; i < n; i++){
        	int a = ins.nextInt();
        	int b = ins.nextInt();
        	double ar[] = new double[a];
        	for (int j = 0; j < a; j++)
        		ar[j] = ins.nextDouble();
        	double minexp = Double.MAX_VALUE;
        	double probcorrect = 1;
        	for (int delete = a; delete >= 0; delete--){
        		int ifcor = delete + 1 + b - a + delete;
        	    int ifnotcor = ifcor + b + 1;
        	    double exp = ifcor * probcorrect + ifnotcor*(1-probcorrect);
        		if (delete != 0)probcorrect *= ar[a-delete];
        		if (exp < minexp) minexp = exp;
        	}
        	if (minexp > (b+2)) minexp = b+2;
        	out.write("Case #"+ (i+1) +": "+String.format("%.6f",minexp));
        	out.newLine();
        }
        ins.close();
        out.close();
        file.close();
	}

}
