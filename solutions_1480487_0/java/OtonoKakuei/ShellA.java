import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;

public class ShellA {
	private static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	
    private static final String ERROR = "Error!";
    
    private static final String ERROR_INVALID_INT =
        "Ungueltige Integer-Zahl! (Nochmal eingeben) ";
    
    private static int numberOfCases = Integer.MAX_VALUE;

    private final static ShellA INSTANCE = new ShellA();
    
    private ShellA() {
    	
    }
    public static void main(String[] args) {
    	System.out.println("Input Something!");
		numberOfCases = readInt();
		int x = 0;
		while (x < numberOfCases) {
			String[] tokens = getTokens();
			int n = Integer.parseInt(tokens[0]);
			int[] array = new int[n];
			int i = 0;
			while (i < n) {
				array[i] = Integer.parseInt(tokens[i + 1]);
				i++;
			}
			double[] doubleArray = INSTANCE.minimumPercentage(array);
			String y = INSTANCE.doubleArrayToString(doubleArray);
			x++;
			System.out.println("Case #" + x + ": " + y);
		}

	}
	
    private static String[] getTokens() {
        String line;
        try {
            line = in.readLine();
        } catch (IOException e) {
            throw new Error(e);
        }
        if (line == null) {
            System.err.println(ERROR);
            return null;
        } else {
            return line.split("\\s");
        }
    }
    
    private static String[] getTokensAll() {
        String line;
        try {
            line = in.readLine();
        } catch (IOException e) {
            throw new Error(e);
        }
        if (line == null) {
            System.err.println(ERROR);
            return null;
        } else {
            return line.split("");
        }
    }

    private static int readInt() {
        while (true) {
            for (String token : getTokens()) {
                try {
                    return Integer.parseInt(token);
                } catch (NumberFormatException e) {
                    System.err.println(ERROR_INVALID_INT);
                }
            }
        }
    }
    
   private int biggestNumber(int[] array) {
	   int biggest = 0;
	   int i = 0;
	   while (i < array.length) {
		   if (biggest < array[i]) {
			   biggest = array[i];
		   }
		   i++;
	   }
	   return biggest;
   }
   
   private int indexBiggestNumber(int[] array) {
	   int biggest = 0;
	   int index = -1;
	   int i = 0;
	   while (i < array.length) {
		   if (biggest < array[i]) {
			   biggest = array[i];
			   index = i;
		   }
		   i++;
	   }
	   return index;
   }
   
   private int sumArray(int[] array) {
	   int sum = 0;
	   int i = 0;
	   while (i < array.length) {
		   sum = sum + array[i];
		   i++;
	   }
	   return sum;
   }
   
   private boolean validAccordingToNumber(int[] array, int number) {
	   boolean valid = false;
	   int x = sumArray(array);
	   int bigger = number;
	   int i = 0;
	   while (x >= 0 && i < array.length) {
		   if (array[i] < bigger) {
			   x = x - (bigger - array[i]);
		   }
		   i++;
	   }
	   if (x >= 0) {
		   valid = true;
	   }
	   return valid;
   }
   
   private int biggestAfter(int[] array, int bigger) {
	   int biggest = 0;
	   int i = 0;
	   while (i < array.length) {
		   if (biggest < array[i] && array[i] < bigger) {
			   biggest = array[i];
		   }
		   i++;
	   }
	   return biggest;
   }
   
   private double[] minimumPercentage(int[] array) {
	   double[] percentage = new double[array.length];
	   boolean validArray = false;
	   int bigger = biggestNumber(array);
	   int sum = sumArray(array);
	   int x = sum;
	   boolean loop = true;
	   int length = array.length;
	   int countDefinitelyWillPass = 0;
	   boolean firstLoop = true;
	   while (loop && x >= 0) {
		   int biggerBefore = bigger;
		   while (!validArray) {
			   if (validAccordingToNumber(array, bigger)) {
				   validArray = true;
			   } else {
				   bigger = biggestAfter(array, bigger);
			   }
		   }
		   if (!firstLoop && bigger == biggerBefore) {
			   loop = false;
		   } 
		   int i = 0;
		   while (loop && i < length) {
			   if (array[i] <= bigger) {
				   x = x - (bigger - array[i]);
				   percentage[i] = percentage[i] + bigger - array[i];
			   } else {
				   percentage[i] = -1;
				   countDefinitelyWillPass++;
			   }
			   i++;
		   }
		   firstLoop = false;
	   }
	   int i = 0;
	   double n = length - countDefinitelyWillPass;
	   double plusPercent = x / n;
	   while (i < length) {
		   if (percentage[i] >= 0) {
			   percentage[i] = (percentage[i] + plusPercent) / sum * 100;
		   } else {
			   percentage[i] = 0.0;
		   }
		   i++;
	   }
	   return percentage;
   }
   
   private String doubleArrayToString(double[] array) {
	   String result = "";
	   int i = 0;
	   while (i < array.length) {
		   result = result + Double.toString(array[i]);
		   i++;
		   if (i < array.length) {
			   result = result + " ";
		   }
	   }
	   return result;
   }

}
