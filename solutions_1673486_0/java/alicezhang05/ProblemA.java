import java.util.*;
import java.io.*;

public class ProblemA
{
  /**
   * Keep typing
   */
  public static double approachA(int A, int B, double[] probCorrect)
  {
    double probRight = 1; //probability all the values were typed correctly
    for (int i = 0; i < A; i++)
    {
      probRight *= probCorrect[i];
    }
    //if all right: type all remaining letters and press enter
    //if one is wrong: type all remaining letters (B-A), press enter (1), type all letters (B), press enter(1)
    return probRight * (B - A + 1) + (1 - probRight) * (2 * B - A + 2);      
    
  }
  // return the minimum of approach B
  /**
   * Press backspace some number of times
   */
  public static double approachB(int A, int B, double[] probCorrect)
  {
    double min = Double.POSITIVE_INFINITY;
    //return the minimum of expectedBackspace over 0 to A
    for (int i = 0; i <= A; i++)
    {
      double temp = expectedBackspace(A, B, probCorrect, i);
      if (temp < min)
        min = temp;
    }
    return min;
  }
  private static double expectedBackspace(int A, int B, double[] probCorrect, int numDelete)
  {
    double probRight = 1;
    for (int i = 0; i < A - numDelete; i++)
    {
      probRight *= probCorrect[i];
    }
    //if all right: delete, reenter deleted, finish the word, press enter
    //if one is wrong: delete, reenter deleted, finish the word, press enter, retype all letters, press enter
    return probRight * (numDelete * 2 + B - A + 1) + (1 - probRight) * (numDelete * 2 + 2 * B - A + 2);
  }
  /**
   * Give up and press enter right away
   */
  public static double approachC(int A, int B, double[] probCorrect)
  {
    if (A == B) //if you typed the entire password
    {
      double product = 1; //probability all were right
      for (int i = 0; i < A; i++)
      {
        product *= probCorrect[i];
      }
      return product + (B + 2) * (1 - product);
    }
    return B + 2; //num keys, two enters (first and second)
  }
  public static void main(String[] args)
  {
    Scanner in = new Scanner(System.in);
    int N = in.nextInt();
    for (int i = 0; i < N; i++)
    {
      
      int A = in.nextInt(); //number of keys already typed
      int B = in.nextInt(); //total number of keys
      double[] probCorrect = new double[A]; //the probability that you get each letter wrong
      for (int j = 0; j < A; j++)
      {
        probCorrect[j] = in.nextDouble();
      }
      
      double first = approachA(A, B, probCorrect);
      double second = approachB(A, B, probCorrect);
      double third = approachC(A, B, probCorrect);
      
      System.out.println("Case #" + (i + 1) + ": " +
                         Math.min(first, Math.min(second, third)));
                         
     }
    }
  }