import java.util.*;
import java.io.*;
import java.lang.*;

class A { 
	static double[] score;
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int T = Integer.parseInt(sc.nextLine());
    
    for (int a=0; a<T; a++) {
    	int N = sc.nextInt();
    	score = new double[N];
    	double sum = 0;
    	for (int i=0; i<N; i++) {
    		score[i] = sc.nextDouble();
    		sum += score[i];
    	}
    	
    	double[] dist = new double[N];
    	for (int i=0; i<N; i++) {
    		int idx1 = i;
    		double max = -1.0;
    		int idx2 = -1;
    		for (int j=0; j<N; j++) {
    			if (i!=j && score[j] > max) { max = score[j]; idx2 = j; }
    		}
    		
    		double low = 0.0, high = 1.0;
    		boolean win = false;
    		//System.out.println(idx1+" "+idx2);
    		while (Math.abs(high-low) > 1e-10) {
    			double cur = (low+high)/2.0;
    			win = ok(cur, idx1, idx2, sum);
    			//System.out.println(win);
    			if (win) high = cur;
    			else low = cur;
    		}
    		dist[i] = high;
    	}
    	
    	String res = "";
    	for (int i=0; i<N; i++) {
    		//System.out.println(min+" "+score[i]);
    		//dist[i] = (min - score[i])/sum * 100.0;
    		res += dist[i]*100.0 +" ";
    	}
    	res = res.trim();
    	System.out.println("Case #" + (a+1) + ": " +res );
    }
  }
  
  public static boolean ok(double percentage, int id1, int id2, double sum) {
  	double score1 = score[id1] + percentage * sum;
  	int count = 0;
  	boolean win = true;
  	double remPercent = 1.0 - percentage;
  	for (int i=0; i<score.length; i++) {
  		if (i != id1) {
  			double req = (score1 - score[i])/ sum;
  			if (req > 0) {
  				remPercent -= req;
  			}
  		}
  		
  		//if (count == 0) { win = false; break; }
  	}
  	if (remPercent < 0) return true;
  		return false;
  	//double score2 = score[id2] + (1.0-percentage) * sum;
  	//System.out.println(percentage+" "+score1+" "+score2);
  	//return win;
  }
}


