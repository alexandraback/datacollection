import java.io.IOException;
import java.util.*;

/**
 * Date: 14/4/12
 * Time: 2:02 PM
 */
public class ProblemC {

    public static void main(String[] args) throws IOException {
        long start = System.currentTimeMillis();
        ArrayList<String> al = GoogleFileStream.getInput();
        ArrayList<String> ret = new ArrayList<String>();

        for( String i : al )
            ret.add( solution( i ) );


        long end = System.currentTimeMillis();
        System.out.println( "Time: " + (end - start) + "ms" );
        GoogleFileStream.setOutput(ret);
    }

    private static String solution(String in) {
        ArrayList<String> input = new ArrayList<String>(Arrays.asList(in.split(" ")));
        int A = Integer.valueOf( input.get(0) );
        int B = Integer.valueOf( input.get(1) );

        int count = 0;
        Set<Integer> dupeSet = new HashSet<Integer>();
        for( int i = A; i <= B; i++)
        {
            String is = String.valueOf(i);
            char[] c = is.toCharArray();

            System.out.print(i);
            System.out.print(":");
            dupeSet.clear();
            for( int j = 1; j < c.length; j++)
            {
                //rotate:
                char lastChar = c[c.length-1];
                System.arraycopy(c,0,c,1,c.length - 1);
                c[0]=lastChar;

                int num = Integer.valueOf(new String(c));
                if(i < num && num <= B)
                {
                    if( dupeSet.add(num) )
                    {
                        // (n,m) = (i, c)
                        count++;
                        System.out.print(num);
                        System.out.print(",");
                    }
                }
            }
            System.out.println();
        }

        return String.valueOf(count);
    }
}