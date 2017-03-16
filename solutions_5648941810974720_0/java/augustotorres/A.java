/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package R1B2016;

import java.io.File;
import java.io.FileNotFoundException;
import java.util.Arrays;
import java.util.Scanner;

/**
 *
 * @author astorres
 */
public class A {
    
    static String nums[] = {"ZERO","ONE","TWO","THREE","FOUR","FIVE","SIX","SEVEN","EIGHT","NINE"};
    
    public static void main(String args[]) throws FileNotFoundException {
        String file = "A-small-attempt0.in";
        Scanner in = new Scanner(new File("C:\\Users\\astorres\\Desktop\\Personal\\CodeJam\\src\\CodeJam\\data\\"+file));
        int n = in.nextInt();
        for(int i=1;i<=n;i++) {
            
            String s = in.next();
            int ocur[] = new int[27];
            int ans[] = new int[10];
            Arrays.fill(ans, 0);
            Arrays.fill(ocur, 0);
            for(int j=0;j<s.length();j++)
                ocur[s.charAt(j)-'A']++;
            /* ZERO */
            ans[0]+=ocur['Z'-'A'];
            for(int j=0;j<nums[0].length();j++)
                ocur[nums[0].charAt(j)-'A']-=ans[0];
            /* SIX */
            ans[6]+=ocur['X'-'A'];
            for(int j=0;j<nums[6].length();j++)
                ocur[nums[6].charAt(j)-'A']-=ans[6];
            /* TWO */
            ans[2]+=ocur['W'-'A'];
            for(int j=0;j<nums[2].length();j++)
                ocur[nums[2].charAt(j)-'A']-=ans[2];
            /* EIGHT */
            ans[8]+=ocur['G'-'A'];
            for(int j=0;j<nums[8].length();j++)
                ocur[nums[8].charAt(j)-'A']-=ans[8];
            /* THREE */
            ans[3]+=ocur['H'-'A'];
            for(int j=0;j<nums[3].length();j++)
                ocur[nums[3].charAt(j)-'A']-=ans[3];
            /* FOUR */
            ans[4]+=ocur['U'-'A'];
            for(int j=0;j<nums[4].length();j++)
                ocur[nums[4].charAt(j)-'A']-=ans[4];
            /* FIVE */
            ans[5]+=ocur['F'-'A'];
            for(int j=0;j<nums[5].length();j++)
                ocur[nums[5].charAt(j)-'A']-=ans[5];
            /* SEVEN */
            ans[7]+=ocur['V'-'A'];
            for(int j=0;j<nums[7].length();j++)
                ocur[nums[7].charAt(j)-'A']-=ans[7];
            /* ONE */
            ans[1]+=ocur['O'-'A'];
            for(int j=0;j<nums[1].length();j++)
                ocur[nums[1].charAt(j)-'A']-=ans[1];
            /* NINE */
            ans[9]+=ocur['I'-'A'];
            for(int j=0;j<nums[9].length();j++)
                ocur[nums[9].charAt(j)-'A']-=ans[9];
            System.out.print("Case #"+i+": ");
            for(int j=0;j<10;j++)
                for(int k=0;k<ans[j];k++)
                    System.out.print(j);
            System.out.println();
        }
    }
    
}
