import com.google.common.base.Enums;
import com.google.common.base.Optional;
import com.google.common.base.Predicate;
import com.google.common.collect.Collections2;
import com.google.common.collect.FluentIterable;
import com.google.common.collect.ForwardingObject;
import com.google.common.math.IntMath;
import com.google.common.primitives.Ints;
import com.sun.istack.internal.Nullable;

import java.util.Collection;
import java.util.List;

import java.util.Scanner;


public class Main {

    public static void main(String... args) {
        Main a = new Main();
        Scanner scanner = new Scanner(System.in);
        int caseNum = scanner.nextInt();
        for(int i=0; i< caseNum; i++) {

            String str = scanner.next();
            String result = a.solve(str);
            System.out.println(String.format("Case #%d: %s", i+1, result));
        }
    }

    private int largest(String str) {
        int ret = str.length() -1;
        for(int i= str.length()-1; i>=0; i--) {
            if (str.charAt(i) > str.charAt(ret)) {
                ret = i;
            }
        }
        return ret;
    }

    public String solve(String str) {
        int largest = largest(str);
        String before =  largest !=0 ? solve(str.substring(0, largest)) : "";
        String after = largest != str.length() -1 ? str.substring(largest +1 ) : "";

        return  str.charAt(largest) + before + after;
    }




}