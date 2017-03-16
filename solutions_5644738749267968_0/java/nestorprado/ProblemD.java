import java.io.*;
import java.util.*;

public class ProblemD {	
    private static int war(ArrayList<Double> N, ArrayList<Double> K, boolean deceitful){
    	int W = 0;
    	double d = 0.000000001;
    	while(N.size()>0){
    		double ke;
    		double na= N.remove(0);
    		if(deceitful)
    			na = na > K.get(0)  ? 1 : K.get(K.size()-1) - d;
    		int pos = Math.abs(Collections.binarySearch(K, na))-1;
    		if(pos<K.size())
    			ke = K.remove(pos);
    		else
    			ke = K.remove(0);
    		if(na>ke)
    			W++;
    	}
    	return W;
    }
    
    private static String solve(Scanner in){
    	String res="";
    	int  n = in.nextInt();
    	ArrayList<Double> N = new ArrayList<Double>();
    	ArrayList<Double> K = new ArrayList<Double>();
    	ArrayList<Double> Nd = new ArrayList<Double>();
    	ArrayList<Double> Kd = new ArrayList<Double>();
    	for(int i=0; i<n; i++){
    		N.add(in.nextDouble());
    	}
    	for(int i=0; i<n; i++){
    		K.add(in.nextDouble());
    	}
    	Collections.sort(N);
    	Collections.sort(K);
    	for(int i=0; i<n; i++){
    		Nd.add((double)N.get(i));
    		Kd.add((double)K.get(i));
    	}
    	int W = war(N,K,false);
    	int D = war(Nd,Kd,true);
    	return D + " " + W;
    }

    public static void main(String[] args) {
    	String file = "Qualification\\ProblemDsmall";
    	try{
    		System.out.println(file);
    		Scanner in = new Scanner(new File(file + ".in"));
    		PrintWriter out = new PrintWriter(new File(file + ".out"));
    		int T = in.nextInt();  in.nextLine();
    		for (int i = 1; i <= T; i++) {
    			String s = "Case #" + i + ": " + ProblemD.solve(in);
    			out.println(s);
    			System.out.println(s);
    		}
    		out.close();
    	}catch(Exception e){ e.printStackTrace(); }
    }
}