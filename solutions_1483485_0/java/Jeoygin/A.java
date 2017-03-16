/*******************************************************************************
 * Copyright (c) 2012 by Institute of Computing Technology,
 * 		Chinese Academic of Sciences, Beijing, China.
 *
 * 	Author: Ruijian Wang
 * 	  File: A.java
 * 	  Date: 2012-04-14
 * 	  Time: 12:53:43
 ******************************************************************************/

package gcj12;

import java.util.Scanner;

/**
 * Todo.
 * <p/>
 * User: Ruijian Wang
 * Date: 4/14/12
 * Time: 12:53 PM
 *
 * @author Ruijian Wang<br>
 * @version 1.0.0 2012-04-14<br>
 */
public class A {
    String[] encode = {"ejp mysljylc kd kxveddknmc re jsicpdrysi" ,
            "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd" ,
            "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
    String[] raw = {"our language is impossible to understand",
            "there are twenty six factorial possibilities" ,
            "so it is okay if you want to just give up"};
    char[] map = new char[256];

    void solve() {
        map['a'] = 'y';
        map['o'] = 'e';
        map['z'] = 'q';
        map['q'] = 'z';
        for (int i = 0; i < 3; i++){
            char[] encodes = encode[i].toCharArray();
            char[] raws = raw[i].toCharArray();
            int l = raws.length;
            for (int j = 0; j < l; j++) {
                map[encodes[j]] = raws[j];
            }
        }

        Scanner scan =  new Scanner(System.in);
        int tCase = scan.nextInt();
        scan.nextLine();
        for (int i = 1; i<=tCase; i++) {
            System.out.print("Case #" + i + ": ");
            String in = scan.nextLine();
            char[] chars = in.toCharArray();
            for (int j = 0; j < chars.length; j++) {
                char c = ' ';
                if (chars[j] != ' ') {
                    c = map[chars[j]];
                }
                System.out.print(c);
            }
            System.out.println();
        }

    }

    public static void main(String[] args) {
        new A().solve();
    }
}
