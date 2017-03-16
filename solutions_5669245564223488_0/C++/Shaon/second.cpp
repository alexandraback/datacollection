#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>
#include <map>
#include <iostream>
#include <queue>
#include <climits>

using namespace std;

typedef long long LL;

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );

#define X first
#define Y second

#define MP make_pair

#define snuke(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)


typedef pair<int,int> pint;
typedef map<int,int> mint;

#define SIZE 15

char str[SIZE][100000];
int arr[SIZE];

char fin[1000000];

bool check( char *x ){

    //cout<<x<<endl;

    bool ff[30]={false};
    int len=strlen(x);

    for (int i=0;i<len;){
        if ( ff[ x[i]-'a' ] )return false;
        ff[ x[i]-'a' ]=true;
        char tmp= x[i];
        while ( x[i] == tmp )i++;

    }
    return true;
}

int main(){

    //FRO
    freopen("B-small-attempt1.in","r",stdin);
    freopen("out.out","w",stdout);

    int kase;
    scanf("%d",&kase);

    for ( int kk=1; kase-- ;++kk ){

        int n;
        scanf("%d",&n);
        for (int i=0;i<n;++i){
            scanf("%s",str[i]);
        }
        for (int i=0;i<n;++i){
            arr[i]=i;
        }
        sort( arr,arr+n );
        int ans = 0;
        do{

            fin[0]='\0';
            for (int i=0;i<n;++i){
                strcat(fin,str[ arr[i] ] );
            }

            if ( check( fin ) ){
                ans= ( ans+1 )%1000000007;
            }

        }while ( next_permutation(arr,arr+n) );

        printf("Case #%d: %d\n",kk,ans);
    }



    return 0;
}
