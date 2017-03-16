import java.io.FileNotFoundException;
import java.io.PrintStream;
import java.util.*;

/**
 * Created by slycer on 4/1/16.
 */
public class C {

    public static void main ( String [] args ) throws FileNotFoundException {
        System.setOut( new PrintStream( "C.out" ));
        Scanner s = new Scanner( System.in ) ;
        int tests = s.nextInt();
        for ( int  test=1; test<=tests; test++ ){
            String answer = "";
            int J = s.nextInt();
            int P = s.nextInt();
            int S = s.nextInt();
            int K = s.nextInt();

            List<String> bestSol = new ArrayList<>();

            List<int[]> data = new ArrayList<>();
            for ( int i = 1; i<=J; i++ ){
                for ( int j=1; j<=P; j++ ){
                    for ( int k=1; k<=S; k++ ){
                        data.add( new int[]{i,j,k} );
                    }
                }
            }
            for ( int i=(1<<data.size())-1; i>=1; i-- ){

                int [] count = new int[1000];
                boolean ok = true;
                int size = 0;
                if ( bestSol.size() == data.size() ){
                    break;
                }
                if ( bestSol.size() >= Integer.bitCount( i ) ){
                    continue;
                }

                for ( int j=0; j<data.size(); j++ ){
                    if ( ( i & (1<<j))>0) {
                        size ++;
                        int [] aux = data.get(j);
                        int ij =  aux[0] +   + aux[1]*10;
                        int ik =  aux[0] +   + aux[2]*100;
                        int jk =  aux[1]*10 +  + aux[2]*100;

                        if ( count( count, ij )<K &&  count( count, ik ) <K && count(count,jk) <K ){
                            increment(count, ij);
                            increment( count, ik );
                            increment( count, jk );
                        } else {
                            ok = false;
                            break;
                        }
                    }
                }

                if ( ok ){


                    if ( size > bestSol.size() ){
                        bestSol = new ArrayList<>();
                        for ( int j=0; j<data.size(); j++ ) {
                            if ((i & (1 << j)) > 0) {
                                int[] aux = data.get(j);
                                bestSol.add(aux[0] + " " + aux[1] + " " + aux[2]);
                            }
                        }
                    }
                }

            }


            answer = bestSol.size() + "";
            for ( int i=0; i<bestSol.size(); i++ ){
                answer += "\n" + bestSol.get( i );
            }

            System.err.println("Case #"+test + ": " + answer + " \n->>" + J + " " + P + " " + S + " " + K );
            System.out.println("Case #"+test + ": " + answer );
        }
    }


    public static int increment( int [] count, int key ){
        count[key]++;
        return  count[key];
    }
    public static int count ( int [] count, int key ){
        return count[key];
    }

    public static int minPos( int [] current, int [] data ){
        int pos = -1;
        int min = Integer.MAX_VALUE;
        for ( int i=0; i<data.length; i++ ){
            if ( current[i]<min && current[i] < data[i] ){
                min = current[i];
                pos = i;
            }
        }
        return pos;
    }
}
