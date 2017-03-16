package gcj.gcj2012.qualif;

import gcj.SolverBase;

import java.io.BufferedReader;
import java.io.PrintStream;
import java.util.HashMap;
import java.util.Map;

public class ProblemA extends SolverBase {

    public ProblemA() {
        super("Speaking in Tongues");
    }

    public static void main(String[] args) throws Exception {
        SolverBase problem = new ProblemA();
        // problem.verbose = true;
        problem.solve(System.in, System.out);
    }

    @Override
    public void solveSingle(BufferedReader reader, PrintStream out) throws Exception {
        String line = reader.readLine();

        Map<Character, Character> map = new HashMap<Character, Character>();
        map.put('a', 'y');
        map.put('b', 'h');
        map.put('c', 'e');
        map.put('d', 's');
        map.put('e', 'o');
        map.put('f', 'c');
        map.put('g', 'v');
        map.put('h', 'x');
        map.put('i', 'd');
        map.put('j', 'u');
        map.put('k', 'i');
        map.put('l', 'g');
        map.put('m', 'l');
        map.put('n', 'b');
        map.put('o', 'k');
        map.put('p', 'r');
        map.put('q', 'z');
        map.put('r', 't');
        map.put('s', 'n');
        map.put('t', 'w');
        map.put('u', 'j');
        map.put('v', 'p');
        map.put('w', 'f');
        map.put('x', 'm');
        map.put('y', 'a');
        map.put('z', 'q');


        StringBuilder tr = new StringBuilder();
        for(int i=0;i<line.length();i++){
            char c = line.charAt(i);
            if( c >= 'a' && c <= 'z' ){
                tr.append(map.get(c));
            }else{
                tr.append(c);
            }
        }

        out.println(tr.toString());
    }
}
