import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 * Created by slycer on 5/2/15.
 */
public class CounterCulture {

    public static void main ( String [] arg ) throws FileNotFoundException {

        Scanner s = new Scanner( System.in );

        System.setOut( new PrintStream( "CounterCulture.out" ) );
        
        int cases = s.nextInt();
        for ( int c=1; c<=cases; c++ ){
            long end = s.nextLong();
            Queue<Item> q = new LinkedList<>();
            Set<Long> added = new HashSet<>();
            q.add( new Item(1,1) );

            while ( q.size() > 0 ){
                Item current = q.poll();
               // System.out.println( current.value + " " + current.distance );
                if ( current.value == end ){
                    System.out.println("Case #" + c + ": " + current.distance);
                    break;
                }

                if ( !added.contains( current.value +1  ) ){
                    Item a = new Item(current.value+1,current.distance+1);
                    q.add( a );
                    added.add( current.value + 1 );
                }

                long reverse = reverse( current.value );
                if ( !added.contains( reverse ) ){
                    q.add( new Item( reverse, current.distance+1) );
                    added.add( reverse );
                }
            }
        }
    }


    public static long reverse( long x ){
        long ret = 0;
        while ( x>0){
            ret = ret*10;
            ret = ret + x%10;
            x=x/10;
        }
        return ret;
    }

    public static class Item{
        long value;
        long distance;

        public Item(long value, long distance) {
            this.value = value;
            this.distance = distance;
        }
    }
}
