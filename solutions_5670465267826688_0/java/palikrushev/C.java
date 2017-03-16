import java.util.HashSet;

import org.apache.commons.collections4.map.MultiKeyMap;


public class C {
  
  public static String I = "i";
  public static String J = "j";
  public static String K = "k";

  public static String MI = "-i";
  public static String MJ = "-j";
  public static String MK = "-k";
  
  public static String O = "1";
  public static String MO = "-1";
  
  
  private static MultiKeyMap<String, String> mult = new MultiKeyMap<String, String>() {{
    put(O, O, O);
    put(O, I, I);
    put(O, J, J);
    put(O, K, K);
    
    put(I, O, I);
    put(I, I, MO);
    put(I, J, K);
    put(I, K, MJ);
    
    put(J, O, J);
    put(J, I, MK);
    put(J, J, MO);
    put(J, K, I);
    
    put(K, O, K);
    put(K, I, J);
    put(K, J, MI);
    put(K, K, MO);
    
    put(MO, MO, O);
    put(O, MO, MO);

    put(MO, O, MO);
    put(MO, I, MI);
    put(MO, J, MJ);
    put(MO, K, MK);  
  }};
  
  public static boolean check(String baseString, int repetition) {
    
    String[] input = compileInput(baseString, repetition);
    
    int posI = 0;
    String lastI = O;

    boolean[] failedJ = new boolean[240000];
    boolean[] failedK = new boolean[240000];
    
    while (true) {
      
      posI = find(input, I, posI, lastI);
      if (posI == -1) {
        break;
      }
      lastI = I;
      
      int posJ = posI;
      String lastJ = O;
      
      if (!failedJ[posI]) {
        while (true) {
          
          posJ = find(input, J, posJ, lastJ);
          if (posJ == -1) {
            break;
          }
          lastJ = J;
          
          if (!failedK[posJ] && endCompilesToK(input, posJ)) {
            return true;
          } else {
            failedK[posJ] = true;
          }
        }
        failedJ[posI] = true;
      }
    }  
    
    return false;
  }
  
  private static boolean endCompilesToK(String[] input, int startingPos) {
    String currentValue = O;
    
    for (int i = startingPos; i < input.length; i++) {
      currentValue = multiply(currentValue, input[i]);
    }
    
    return currentValue == K;
  }
  
  private static String[] compileInput(String baseString, int repetition) {
    
    if (repetition > 20) {
      repetition = 20 + (repetition % 4);
    }

    StringBuilder sb = new StringBuilder();
    for (int i = 0; i < repetition; i++) {
      sb.append(baseString);
    }
    
    return stringToArray(sb.toString());
  }
  
  private static String[] stringToArray(String input) {
    String[] output = new String[input.length()];
    
    for (int i = 0; i < input.length(); i++) {
      
      switch (input.charAt(i)) {
        case 'i': output[i] = I; break;
        case 'j': output[i] = J; break;
        case 'k': output[i] = K; break;
        default: break;
      }
    }
    
    return output;
  }
  
  
  private static int find(String[] line, String desiredOutput, int startingPosition, String startingValue) {
    
    if (startingPosition >= line.length) {
      return -1;
    }
    
    int currentPosition = startingPosition;
    String currentValue = startingValue;
    
    while(true) {
      currentValue = multiply(currentValue, line[currentPosition]);
      currentPosition++;
      
      if (currentValue == desiredOutput || currentPosition >= line.length) {
        break;
      }
      
    };
    
    
    if (currentValue == desiredOutput) {
      return currentPosition;
    } else {
      return -1;
    }
  }
  
  public static String multiply(String first, String second) {

    String base1 = getBase(first);
    String base2 = getBase(second);    
    String sign1 = getSign(first);
    String sign2 = getSign(second);
    
    String result = mult.get(base1, base2);
    String sign3 = getSign(result);
    result = getBase(result);
    String sign = mult.get(mult.get(sign1, sign2), sign3);
    
    return mult.get(sign, result);
  }
  
  private static String getBase(String input) {
    
    String base = input;
    
    if (input == MI) {
      base = I;
    } else if (input == MJ) {
      base = J;
    } else if (input == MK) {
      base = K;
    }
    
    return base;
  }
  
  private static String getSign(String input) {
    String sign = O;
    
    if (input == MI || input == MJ || input == MK) {
      sign = MO;
    }
      
    return sign;
  }

}
