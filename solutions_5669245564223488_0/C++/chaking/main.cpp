#include <iostream>
#include <cstring>

using namespace std;

int input();
int process();
int printResult();

int result;
int N;
char array[100][101];
int pairArray[100][100];
int checkGroup[100];
int group[100][100];
int groupLength[100];

int main ( void ){
    int i;
    int count;

    cin >> count;

    for( i = 0; i < count; i++ ){
        input();
        process();
        cout << "Case #" << i + 1 << ": ";
        printResult();
    }

    return 0;
}

int input(){
    int i;

    cin >> N;

    for( i = 0; i < N; i++ ){
        cin >> array[i]; 
        //cout << array[i] << endl;
    }

    return 0;
}

int makeGroup( int depth, int left, int groupCount ){
    int i, j;

    if( depth >= N ){
        //checkValid
        if( groupCount == 1 ) result++;
        else{
            for( i = 0; i < groupCount; i++ ){
                for( j = 0; j < groupCount; j++ ){
                    if( i != j ){
                        char rowFirst = array[group[i][0]][0];
                        char rowLast = array[group[i][groupLength[i] - 1]][strlen( array[group[i][groupLength[i] - 1]] ) - 1];
                        char colFirst = array[group[j][0]][0];
                        char colLast = array[group[j][groupLength[j] - 1]][strlen( array[group[j][groupLength[j] - 1]] ) - 1];
                        if( rowLast == colFirst || rowFirst == colLast ) return 0;
                        //cout << "rowFirst:" << rowFirst << " rowLast:" << rowLast << " colFisrt:" << colFirst << " colLast:" << colLast << endl;
                    }
                }
            } 
            
            //cout << groupCount << endl;
            //int sum = 1;
            //for( i = 0; i < groupCount; i++ ){
                //sum = sum * ( i + 1 ); 
            //}
            //result += sum;
            result++;
        }
        return 0;
    }

    if( left < 0 ){
        for( i = 0; i < N; i++ ){
            if( checkGroup[i] == 0 ){
                checkGroup[i] = 1;
                groupLength[groupCount] = 0;
                group[groupCount][groupLength[groupCount]++] = i;
                makeGroup( depth + 1, i, groupCount + 1 );
                groupLength[groupCount] = 0;
                checkGroup[i] = 0;
            }
        }
    }
    else{
        for( i = 0; i < N; i++ ){
            if( checkGroup[i] == 0 ){
               if( pairArray[left][i] & 1  ){
                    checkGroup[i] = 1;
                    group[groupCount - 1][groupLength[groupCount - 1]++] = i;
                    makeGroup( depth + 1, i, groupCount );
                    groupLength[groupCount - 1]--;
                    checkGroup[i] = 0;
                }
                else{
                     if( groupLength[groupCount - 1] > 1 ){
                        checkGroup[i] = 1;
                        groupLength[groupCount] = 0;
                        group[groupCount][groupLength[groupCount]++] = i;
                        makeGroup( depth + 1, i, groupCount + 1 );
                        groupLength[groupCount] = 0;
                        checkGroup[i] = 0;
                    }

                }
            }
        }
    }
}

int process(){
    int row, col;
    result = 0;

    // find pair
    for( row = 0; row < N; row++ ){
        checkGroup[row] = 0;
        for( col = 0; col < N; col++ ){
            pairArray[row][col] = 0; 
            if( row != col ){
                char rowFirst = array[row][0];
                char rowLast = array[row][strlen( array[row] ) - 1];
                char colFirst = array[col][0];
                char colLast = array[col][strlen( array[col] ) - 1];

                if( rowLast == colFirst ) pairArray[row][col] |= 1;
                if( rowFirst == colLast ) pairArray[row][col] |= 2;
            }
        }
    }

    makeGroup( 0, -1, 0 );

    return 0;
}

int printResult(){
    int i;
    
    cout << result;

    cout << endl;
    
    return 0;
}
