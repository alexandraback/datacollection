package pkj;

import java.io.PrintWriter;
import java.util.Scanner;

/**
 * Created by puneet.jaiswal on 4/15/16.
 */
public class TheLastWord {
    static class DLL {
        char ch;
        DLL next;
        DLL prev;
    }

    public void solve(int testNumber, Scanner in, PrintWriter out) {
        out.println("Case #" + testNumber + ": ");
        String str = in.next();
        DLL head = null;
        DLL tail = null;
        for (int i = 0; i < str.length(); i++) {
            char ch = str.charAt(i);
            if (head == null) {
                head = new DLL();
                head.ch = ch;
                tail = head;
            } else {
                DLL dll = new DLL();
                dll.ch = ch;
                if(dll.ch >= head.ch) {
                    dll.next = head;
                    head.prev = dll;
                    head = dll;
                } else {
                    dll.prev = tail;
                    tail.next = dll;
                }
            }
        }

        String ret = "";
        while (head != null) {
            ret += head.ch;
            head = head.next;
        }
        out.println(ret);
    }
}