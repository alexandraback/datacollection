#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<climits>
#include<cmath>

using namespace std;

int N,M;
char A[20],B[20];
char a[20],b[20];
int diff = INT_MAX;
char fa[20],fb[20];

int toInt( int size,char* ch){
    int num = 0;
    for(int i=0;i<size;i++)
        num = num*10 + ch[i] - '0';
    return num;
}

void init(){
    memset( a, '\0', sizeof a );
    memset( fa, '\0', sizeof a );
    memset( b, '\0', sizeof a );
    memset( fb, '\0', sizeof a );
    diff = INT_MAX;
}

void solve(int size,int pos){

    if( pos >= size ){
        int tA = toInt( N, a );
        int tB = toInt( M, b );

        if( abs(tA-tB) < diff ){
            diff = abs(tA-tB);
            strcpy( fa, a );
            strcpy( fb, b );
        }else if( abs(tA-tB) == diff ){
            if( toInt(N, fa) > toInt(N, a) ){
                strcpy( fa, a );
                strcpy( fb, b );
            }else if( toInt(N, fa) == toInt(N, a) && toInt(M, fb) > toInt(M, b) ){
                strcpy( fa, a );
                strcpy( fb, b );
            }
        }
        return;
    }

    if( pos < N ){
        if( A[pos] == '?' ){
            for(int i=0;i<=9;i++){
                a[pos] = i + '0';
                solve(size,pos+1);
            }
        }else{
            a[pos] = A[pos];
            solve(size,pos+1);
        }
    }else{
        if( B[pos-N] == '?' ){
            for(int i=0;i<=9;i++){
                b[pos-N] = i + '0';
                solve(size,pos+1);
            }
        }else{
            b[pos-N] = B[pos-N];
            solve(size,pos+1);
        }
    }

}

int main(){
    freopen( "input.txt", "r", stdin );
    freopen( "output.txt", "w", stdout );

    int T; cin>>T;
    for(int t=1;t<=T;t++){
        cin>>A>>B;
        N = strlen( A );
        M = strlen( B );
        init();
        solve( N+M, 0);
        printf( "Case #%d: %s %s\n", t, fa, fb );
    }
}
