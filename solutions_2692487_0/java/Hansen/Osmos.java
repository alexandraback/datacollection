package round1B;

import java.io.BufferedWriter;
import java.io.FileInputStream;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Arrays;
import java.util.Scanner;

public class Osmos {
	public static void main(String[] args) throws IOException {
		Scanner scanner = new Scanner( new FileInputStream( "/home/hansen/workspace/CodeJam/src/round1B/Osmos.in" ) );
		BufferedWriter bw =  new BufferedWriter( new FileWriter( "/home/hansen/workspace/CodeJam/src/round1B/Osmos.out" ) );
		int testCases = scanner.nextInt();
		for (int testCase = 0; testCase < testCases; testCase++) {
			int A = scanner.nextInt();
			int N = scanner.nextInt();
			N++;
			int[] volumen = new int[ N ];
			int[] mass = new int[ N ];
			int[] better = new int[ N ];
			for (int i = 0; i < N -1; i++) {
				mass[i+1] = scanner.nextInt();
			}
			mass[ 0 ]= 0;
			Arrays.sort( mass );
			Arrays.fill( volumen , 0 );
			Arrays.fill( better , N -1 );
			volumen[ 0 ] = A;
			better[ 0 ] = 0;
			for (int i = 0; i < N; i++) {
				int massA = volumen[ i ];
				int penalty = 0;
				//Absorb
				absorb:
				for (int j = i + 1; j < N; j++) {
					while ( massA <= mass[ j ] ){
						if ( massA == 1 )							
							break absorb;
						massA += massA -1;
						penalty++;
					}
					massA += mass[j];
					if ( better[ i ] + penalty < better[ j ]  ){
						better[ j ] = better[ i ] + penalty ;
						volumen[ j ] = massA 	;
					}
					if ( better[ i ] + penalty == better[ j ]  ){						
						volumen[ j ] = Math.max( volumen[ j ] , massA );
					}
				}
				//Remove
				penalty = 1;
				for (int j = i + 1; j < N; j++ , penalty++) {
					if ( better[ i ] + penalty < better[ j ]  ){
						better[ j ] = better[ i ] + penalty ;
						volumen[ j ] = volumen[i];
					}
					if ( better[ i ] + penalty == better[ j ]  ){						
						volumen[ j ] = Math.max( volumen[ j ] , volumen[i] );
					}
				}
				
			}
			
			bw.write("Case #" + (testCase +1 )+ ": " + better[ N - 1 ] );
			bw.newLine();
		}
		scanner.close();
		bw.close();
	}
}
