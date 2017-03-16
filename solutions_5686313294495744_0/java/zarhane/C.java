import java.io.*;
import java.math.BigInteger;
import java.util.*;

import static java.lang.Math.*;
import static java.util.Arrays.*;

public class C {
	
  public static void main(String[] args) throws IOException {
    String        pb        = "C";
    Scanner       sc        = new Scanner(new FileReader(new File(pb+".in")));
    PrintWriter   out       = new PrintWriter(new File(pb+".out"));
		StringBuilder resultat  = new StringBuilder("");
		//long time = System.currentTimeMillis();
				
		
		//TEST CASES----------------------------------------------------
		int TC = sc.nextInt();
//		System.out.println("TC="+TC);
    for (int tc = 1; tc <= TC; tc++) {
      if(tc!=1) resultat.append("\n");
      resultat.append("Case #"+tc+": ");
    
//      System.out.println(tc);
      
      //READ----------------------------------------------------
      int N = sc.nextInt(); sc.nextLine();
      //System.out.println("N="+N);
      int max = 0;
      ArrayList<String> first = new ArrayList<String>();
      ArrayList<String> firstReal = new ArrayList<String>();
      HashMap<String, Integer> countFirst = new HashMap<String, Integer>();
      ArrayList<String> second = new ArrayList<String>();
      ArrayList<String> secondReal = new ArrayList<String>();
      HashMap<String, Integer> countSecond = new HashMap<String, Integer>();
      ArrayList<String[]> comb = new ArrayList<String[]>();
      ArrayList<String[]> real = new ArrayList<String[]>();
      ArrayList<String[]> fake = new ArrayList<String[]>();
      ArrayList<String[]> unk = new ArrayList<String[]>();
      
      for (int i = 0; i < N; i++)
      {
        String str = sc.nextLine();
        //System.out.println("str="+str);
        String[] co = str.split(" ");
        comb.add(co);
        if(!first.contains(co[0])){
          first.add(co[0]);
          countFirst.put(co[0],0);
        }
        countFirst.put(co[0],countFirst.get(co[0])+1);
        
        if(!second.contains(co[1])){
          second.add(co[1]);
          countSecond.put(co[1],0);
        }
        countSecond.put(co[1],countSecond.get(co[1])+1);
      }
      
      
      for (int i = 0; i < comb.size(); i++)
      {
        if(countFirst.get(comb.get(i)[0])==1 || countSecond.get(comb.get(i)[1])==1){
          real.add(comb.get(i));
          firstReal.add(comb.get(i)[0]);
          secondReal.add(comb.get(i)[1]);
        }
      }
      
//      System.out.println("real=");
//      for (int i = 0; i < real.size(); i++)
//      {
//        System.out.println(real.get(i)[0] + " " + real.get(i)[1]);
//      }
      
      ArrayList<String> firstFake = new ArrayList<String>();
      ArrayList<String> secondFake = new ArrayList<String>();
      for (int i = 0; i < comb.size(); i++)
      {
        if(!real.contains(comb.get(i)) && firstReal.contains(comb.get(i)[0]) && secondReal.contains(comb.get(i)[1])){
          fake.add(comb.get(i));
          firstFake.add(comb.get(i)[0]);
          secondFake.add(comb.get(i)[1]);
        }
      }
      int f = fake.size();
      
//      System.out.println("fake=");
//      for (int i = 0; i < fake.size(); i++)
//      {
//        System.out.println(fake.get(i)[0] + " " + fake.get(i)[1]);
//      }
      
      for (int i = 0; i < comb.size(); i++)
      {
        if(!real.contains(comb.get(i)) && !fake.contains(comb.get(i)))
          unk.add(comb.get(i));
      }
      
//      System.out.println("unk=");
//      for (int i = 0; i < unk.size(); i++)
//      {
//        System.out.println(unk.get(i)[0] + " " + unk.get(i)[1]);
//      }
//      System.out.println("\n");
      
      int u = unk.size();
      
//      String[][] unkn = new String[u][2];
//      for (int i = 0; i < unkn.length; i++)
//      {
//        unkn[i] = unk.get(i);
//      }
      
//      ArrayList<String[][]> permutations = permute(unkn);
//      
//      for (int i = 0; i < permutations.size(); i++)
//      {
//        String[][] poss = permutations.get(i);
//        int scorePoss = 0;
//        ArrayList<String> fir = new ArrayList<String>();
//        ArrayList<String> sec = new ArrayList<String>();
//        for (int j = 0; j < poss.length; j++)
//        {
//          boolean cf = fir.contains(poss[j][0]) || first.contains(poss[j][0]);
//          boolean cs = sec.contains(poss[j][1]) || second.contains(poss[j][1]);
//          
//          if(cf && cs)
//            scorePoss++;
//          
//          if(!cf)
//            fir.contains(poss[j][0]);
//          if(!cs)
//            sec.contains(poss[j][1]);
//        }
//        
//        if(scorePoss<max)
//          max = scorePoss;
//      }
      
      
      ArrayList<Integer> scores = new ArrayList<Integer>(); 
      int[] scoComb = new int[u];
      for (int i = 0; i < unk.size(); i++)
      {
//        for (int j = i+1; j < unk.size(); j++)
//        {
          //System.out.println(i + " " + j + " " + unk.get(i)[0]+" "+unk.get(i)[1] + " - " + unk.get(j)[0]+" "+unk.get(j)[1]);
          if(firstFake.contains(unk.get(i)[0]) && secondFake.contains(unk.get(i)[1])){
            scoComb[i]++;
            //System.out.println(i + " " + j + " " + unk.get(i) + " - " + unk.get(j));
          }
//        }
      }
      for (int i = 0; i < scoComb.length; i++)
      {
        if(!scores.contains(scoComb[i]))
            scores.add(scoComb[i]);
      }
      
      Collections.sort(scores);
      
      //System.out.println(scores);
      
      ArrayList<String[]> unkOrder = new ArrayList<String[]>(); 
      for (int i = 0; i < scores.size(); i++)
      //for (int i = scores.size()-1; i >= 0; i--)
      {
        for (int j = 0; j < scoComb.length; j++)
        {
          if(scores.get(i)==scoComb[j])
            unkOrder.add(unk.get(j));
        }
      }
      
      
      int scorePoss = 0;
      ArrayList<String> fir = new ArrayList<String>();
      ArrayList<String> sec = new ArrayList<String>();
      for (int j = 0; j < unkOrder.size(); j++)
      {
        boolean cf = fir.contains(unkOrder.get(j)[0]) || firstReal.contains(unkOrder.get(j)[0]);
        boolean cs = sec.contains(unkOrder.get(j)[1]) || secondReal.contains(unkOrder.get(j)[1]);
        
        if(cf && cs)
          scorePoss++;
        
        if(!cf)
          fir.add(unkOrder.get(j)[0]);
        if(!cs)
          sec.add(unkOrder.get(j)[1]);
      }
      
      
      
      
      max = f + scorePoss;
      
      //PRINT--------------------------------------------------
			System.out.println(max);
			resultat.append(max);
			//System.out.println("Finished testcase " + tc + ", time = " + (System.currentTimeMillis() - time));
		}
		
    //CLOSE----------------------------------------------------
		out.print(resultat);
		out.close(); sc.close();
	}
  
  
  public static ArrayList<String[][]> permute(String[][] num) {
    ArrayList<String[][]> result = new ArrayList<String[][]>();
    permute(num, 0, result);
    return result;
  }
   
  static void permute(String[][] num, int start, ArrayList<String[][]> result) { 
    if (start >= num.length)
      result.add(num.clone());
   
    for (int j = start; j <= num.length - 1; j++) {
      swap(num, start, j);
      permute(num, start + 1, result);
      swap(num, start, j);
    }
  }
   
  private static void swap(String[][] a, int i, int j) {
    String[] temp = a[i];
    a[i] = a[j];
    a[j] = temp;
  }
  
}