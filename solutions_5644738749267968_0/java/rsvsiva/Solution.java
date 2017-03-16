import java.text.DecimalFormat;
import java.io.*;
import java.util.Scanner;
import java.util.*;
import java.math.*;
class Solution{
	public static void main(String args[]) throws IOException{
		Scanner in = new Scanner(System.in);
		int cases = in.nextInt();
		for (int i=0;i<cases;i++){
			int n = in.nextInt();
			List<Double> naomi = new ArrayList<Double>();
			List<Double> naomi1 = new ArrayList<Double>();
			List<Double> ken = new ArrayList<Double>();
			List<Double> ken1 = new ArrayList<Double>();
			for(int k=0;k<n;k++) naomi.add(in.nextDouble());
			for(int k=0;k<n;k++) ken.add(in.nextDouble());
			Collections.sort(naomi);
			Collections.sort(ken);
			for(int k=0;k<n;k++) {ken1.add(ken.get(k));}
			for(int k=0;k<n;k++) {naomi1.add(naomi.get(k));}

// deceitful war
	int kenTotal = n,flag = 0;
	int deceit = 0;
	while(!naomi.isEmpty()&&flag==0){
		Double kenMax = ken.get(kenTotal-1),kenMin = ken.get(0);
		Double naoMax = naomi.get(kenTotal-1),naoMin = naomi.get(0);
		if(Double.compare(kenMax,naoMin) < 0 ){deceit=deceit+kenTotal;flag=1;}
		else if (Double.compare(naoMax,kenMin) < 0){flag = 1;}
		else if (Double.compare(naoMin,kenMin) > 0){deceit++;naomi.remove(0);ken.remove(0);}
		else if(Double.compare(naoMin,kenMin)<0){naomi.remove(0);ken.remove(kenTotal-1);}
		kenTotal--;
	}

	kenTotal = n;
	int flag1 = 0;
	int war = 0;
	while(!naomi1.isEmpty()&&flag1==0){
		Double kenMax = ken1.get(kenTotal-1),kenMin = ken1.get(0);
		Double naoMax = naomi1.get(kenTotal-1),naoMin = naomi1.get(0);
		if(Double.compare(kenMax,naoMin) < 0 ){war=war+kenTotal;flag1=1;}
		else if (Double.compare(naoMax,kenMin) < 0){flag1 = 1;}
		else { int index = binarySearch(ken1,naoMin);ken1.remove(index);naomi1.remove(0);}
		kenTotal--;
	}
	System.out.println("Case #"+(i+1)+": "+deceit+" "+ war);
	}
	}
	public static int binarySearch(List<Double> arr,Double value){
		int start, end, midPt;

		start = 0;                // The starting index of the search range.
		end = arr.size()-1;  // The ending index of the search range.

	// Loop until we know the value has not been found...
	// ... or a return within this loop will terminate the
	//     method when the value is found.
	while (start <= end) {

	    // Find the midpoint of the range being searched.
	    midPt = (start + end) / 2;

	    if (Double.compare(arr.get(midPt),value)==0) {
		// If the midpoint contains the value being searched
		// for then we are done, just return the index of
		// the midpoint which terminates the method.
		return midPt;
	    }
	    else if (Double.compare(arr.get(midPt),value)< 0) {
		// The midpoint contains a value less than the value
		// being searched for, so from now on we only need to
		// consider values in the upper half of the search
		// range.
		start = midPt + 1;
	    }
	    else {
		// The midpoint contains a value greater than the
		// value being searched for, so from now on we only
		// need to consider values in the lower half of the
		// search range.
		end = midPt - 1;
	    }
	}

	// start became > end which implies that the value
	// being searched for was not found.  So return -1.
	return start;

	}
}
