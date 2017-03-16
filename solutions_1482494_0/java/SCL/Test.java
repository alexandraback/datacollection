import java.util.*;
import java.io.*;

public class Test {

	public static void main(String args[]) throws Exception{
		Scanner input = new Scanner(new FileReader("./iothings/B-small-attempt5.in"));
		PrintWriter pw = new PrintWriter(new FileWriter("./iothings/output.txt"));
        int n = input.nextInt();
        for(int i = 0 ; i < n ; i++){
            int stage = input.nextInt();
            MyPair[] pair = new MyPair[stage];
            for(int j = 0 ; j < stage ; j++){
            	pair[j] = new MyPair();
            	int st1 = input.nextInt();
            	int st2 = input.nextInt();
            	pair[j].setFirst(st2);
            	pair[j].setSecond(st1);
            }
            pw.println("Case #"+(i+1)+": "+num(stage,pair));
        }
		input.close();
		pw.flush();
		pw.close();
	}
	    	
    public static String num(int stage,MyPair[] pair){
    	Arrays.sort(pair);
    	boolean isng = true;
    	for(int i = 0 ; i < stage ; i++){
			//System.out.println(pair[i].getFirst()+","+pair[i].getSecond());
    		if((Integer)pair[i].getFirst() == 0 || (Integer)pair[i].getSecond() == 0){
    			isng = false;
    			break;
    		}
    	}
    		if(isng)return "Too Bad";
    		int stagecount = 0;
    		int stars = 0;
    		int stagec = 0;
    		int[] completenumber = new int[stage];
    		while(stagecount != stage){
    			boolean siraberu = true;
    			if(stars >= (Integer)pair[stagecount].getFirst()){
    				stars+=(2-completenumber[stagecount]);
    				completenumber[stagecount] +=2;
    				stagecount++;
    				stagec++;
    				siraberu = false;
    			}
    			if(siraberu){
    				int maxhor = -1;
    				int maxsec = 0;
    				int index = -1;
        			for(int i = 0 ; i < stage ; i++){
        				if(stars >= (Integer)pair[i].getSecond() && completenumber[i] == 0){
        					if((Integer)pair[i].getFirst() >= maxhor){
        						int tmpsec = (Integer)pair[i].getFirst();
        						if(tmpsec > maxsec){
        							maxhor = (Integer)pair[i].getSecond();
        							maxsec = tmpsec;
        							index = i;
        						}
        					}
        				}
        			}
        			if(index != -1){
        				siraberu = false;
        				stars+=1;
        				stagec++;
        				completenumber[index]++;
        			}
    			}
    			if(siraberu){
    				return "Too Bad";
    			}
    		}
    		
    		return stagec+"";
    }
 
}

class MyPair<S, T> implements Cloneable,Comparable<MyPair<?, ?>>, Serializable {
    private static final long serialVersionUID = -553348920790587668L;
    @Override
    public MyPair<?, ?> clone() {
        try {
            return (MyPair<?, ?>) super.clone();
        } catch (CloneNotSupportedException e) {
            throw new IllegalStateException(e);
        }
    }
    public MyPair(){//S first, T second) {
        //this.first = first;
        //this.second = second;
    	//return;
    }
    private S first;
    private T second;
    @SuppressWarnings("unchecked")
	public MyPair(MyPair<?, ?> p) {
        first = (S) p.getFirst();
        second = (T) p.getSecond();
    }
    public S getFirst() {
        return first;
    }
    public void setFirst(S first) {
        this.first = first;
    }
    public T getSecond() {
        return second;
    }
    public void setSecond(T second) {
        this.second = second;
    }
    @Override
    public boolean equals(Object obj) {
        if (obj == this) { return true; }
        if (!(obj instanceof MyPair)) { return false; }
        MyPair<?, ?> pair = (MyPair<?, ?>) obj;
        if (first == null) {
            if (second == null) {
                if (pair.first == null && pair.second == null) { return true; }
                return false;
            }
            if (pair.first == null) { return second.equals(pair.second); }
            return false;
        }
        if (second == null) {
            if (first != null) {
                if (pair.second == null) { return first.equals(pair.first); }
                return false;
            }
        }
        return first.equals(pair.first) && second.equals(pair.second);
    }
    /**
     * hashcode
     */
    @Override
    public int hashCode() {
        int result = 17;
        result *= 31;
        if (first != null) {
            result += first.hashCode();
        }
        result *= 31;
        if (second != null) {
            result += second.hashCode();
        }
        return result;
    }
    @Override
    public String toString() {
        return "[" + (first != null ? first : "null") + ", " + (second != null ? second : "null") + "]";
    }
    @SuppressWarnings("unchecked")
    public int compareTo(MyPair<?, ?> o) {// Comparable>
        Comparable f = null;
        Comparable s = null;
        try {
            f = (Comparable) first;
            s = (Comparable) second;
        } catch (ClassCastException e) {
            throw new IllegalStateException(e);
        }
        if (f == null || s == null || o == null) throw new NullPointerException();
        int c = f.compareTo(o.first);
        if (c != 0) {return c; }
        return s.compareTo(o.second);
    }
}
