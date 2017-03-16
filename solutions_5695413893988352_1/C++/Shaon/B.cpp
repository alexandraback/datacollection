#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <bits/stdc++.h>

using namespace std;
using namespace __gnu_pbds;

typedef long long LL;

typedef tree<
    int,
    null_type,
    less<int>,
    rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;
//find_by_order
//order_of_key

#define FO(i,a,b) for (int i = (a); i < (b); i++)

#define PB push_back
#define FRO freopen("in.txt","r",stdin);

#define CLR(arr) memset( (arr),0,sizeof(arr) );
#define NEG(arr) memset( (arr),-1,sizeof(arr) );
#define ALL(v) v.begin(),v.end()

#define X first
#define Y second
#define MP make_pair

typedef pair<int,int> pint;
typedef map<int,int> mint;

void show() {cout<<'\n';}
template<typename T,typename... Args>
void show(T a, Args... args) { cout<<a<<" "; show(args...); }
template<typename T>
void show_c(T& a) { for ( auto &x:a ){ cout<<x<<" ";}cout<<endl;  }


const LL inf = LLONG_MAX/2;

#define SIZE 22

char A[SIZE];
char B[SIZE];
int n;
LL power[SIZE];


LL dpG[SIZE];
bool visG[SIZE];

LL funcGr( int ind ){
    if ( ind  == n )return 0;

    LL &ret = dpG[ind];
    if ( visG[ind] )return ret;
    ret =  -inf;
    if ( A[ind] != '?' && B[ind] != '?' ){
        ret = ( ( A[ind]-'0' )-( B[ind]-'0' ) ) * power[n-ind-1] + funcGr( ind+1 );
    }else if ( A[ind] == '?' && B[ind] != '?' ){
        int f = B[ind] - '0';
        ret = ( 9 - f  )*power[n-ind-1] + funcGr( ind+1 );
    }else if ( B[ind] == '?' && A[ind] != '?'  ){
        int f = A[ind] - '0';
        ret = ( f -0  )*power[n-ind-1] + funcGr( ind+1 );
    }else{
        ret = ( 9 -0 )*power[n-ind-1] + funcGr( ind+1 );
    }
    visG[ind] = true;
    return ret;
}
LL dpL[SIZE];
bool visL[SIZE];

LL funcLs( int ind ){
    if ( ind  == n )return 0;

    LL &ret = dpL[ind];
    if ( visL[ind] )return ret;

    ret =  -inf;
    if ( A[ind] != '?' && B[ind] != '?' ){
        ret = ( ( A[ind]-'0' )-( B[ind]-'0' ) ) * power[n-ind-1] + funcLs( ind+1 );
    }else if ( A[ind] == '?' && B[ind] != '?' ){
        int f = B[ind] - '0';
        ret = ( 0-f )*power[n-ind-1] + funcLs( ind+1 );
    }else if ( B[ind] == '?' && A[ind] != '?'  ){
        int f = A[ind] - '0';
        ret = ( f-9 )*power[n-ind-1] + funcLs( ind+1 );
    }else{
        ret = ( 0-9 )*power[n-ind-1] + funcLs( ind+1 );
    }
    visL[ind] = true;
    return ret;
}

LL dp1[SIZE];
bool vis1[SIZE];



LL funcEq(int ind){

    if ( ind == n )return 0;

    LL &ret = dp1[ind];
    if ( vis1[ind] )return ret;

    ret = inf;

    if ( A[ind] != '?' && B[ind] != '?' ){
        LL vvv = ( ( A[ind]-'0' )-( B[ind]-'0' ) ) * power[n-ind-1];
        ret =  vvv + funcEq( ind+1 );
        if ( abs(  vvv + funcLs( ind+1 ) ) < abs(ret) )ret = vvv + funcLs( ind+1 );
        if ( abs(  vvv + funcGr( ind+1 ) ) < abs(ret) )ret = vvv + funcGr( ind+1 );
    }else if ( A[ind] == '?' && B[ind] != '?' ){
        int f = B[ind]-'0';
        if ( f-1>=0 ){
            LL tmp = -1*power[n-ind-1] + funcGr( ind+1 );
            if ( abs(tmp)< abs(ret) )ret = tmp;
        }
        {
            LL tmp = funcEq( ind+1 ) ;
            if ( abs(tmp)< abs(ret) )ret = tmp;
        }
        if ( f+1<=9 ){
            LL tmp = +1*power[n-ind-1] + funcLs( ind+1 ) ;
            if ( abs(tmp)< abs(ret) )ret = tmp;
        }

    }else if ( B[ind] == '?' && A[ind] != '?' ){
        int f = A[ind]-'0';
        if ( f-1>=0 ){
            LL tmp = 1*power[n-ind-1] + funcLs( ind+1 );
            if ( abs(tmp)< abs(ret) )ret = tmp;
        }
        {
            LL tmp = funcEq( ind+1 ) ;
            if ( abs(tmp)< abs(ret) )ret = tmp;
        }
        if ( f+1<=9 ){
            LL tmp = -1*power[n-ind-1] + funcGr( ind+1 );
            if ( abs(tmp)< abs(ret) )ret = tmp;
        }

    }else{

        if ( abs( funcEq(ind+1) ) < abs(ret) )ret =  funcEq(ind+1);
        if ( abs( -1*power[n-ind-1] + funcGr( ind+1 ) ) < abs(ret) )ret =  -1*power[n-ind-1] + funcGr( ind+1  );
        if ( abs( 1*power[n-ind-1] + funcLs( ind+1 ) ) < abs(ret) )ret =  1*power[n-ind-1] + funcLs( ind+1 );

    }

    vis1[ind]=true;
    return ret;
}


string ansA,ansB;
void printGr( int ind ){
    if ( ind  == n )return ;

    if ( A[ind] != '?' && B[ind] != '?' ){
        ansA += A[ind];
        ansB += B[ind];
        printGr( ind+1 );
    }else if ( A[ind] == '?' && B[ind] != '?' ){
        ansA += char(9+'0');
        ansB += B[ind];
        printGr( ind+1 );
    }else if ( B[ind] == '?' && A[ind] != '?'  ){
        ansA += A[ind];
        ansB += char('0');
        printGr( ind+1 );
    }else{
        ansA += char(9+'0');
        ansB += char(0+'0');
        printGr( ind+1 );
    }

}


void printLs( int ind ){
    if ( ind  == n )return ;

    if ( A[ind] != '?' && B[ind] != '?' ){
        ansA += A[ind];
        ansB += B[ind];
        printLs( ind+1 );
    }else if ( A[ind] == '?' && B[ind] != '?' ){
        ansA += char(0+'0');
        ansB += B[ind];
        printLs( ind+1 );
    }else if ( B[ind] == '?' && A[ind] != '?'  ){

        ansA += A[ind];
        ansB += char( 9 +'0' );
        printLs( ind+1 );
    }else{
        ansA += char(0+'0');
        ansB += char(9+'0');
        printLs( ind+1 );
    }
}

void printEq(int ind){

    if ( ind == n )return ;

    LL &ret = dp1[ind];

    if ( A[ind] != '?' && B[ind] != '?' ){
        LL vvv = ( ( A[ind]-'0' )-( B[ind]-'0' ) ) * power[n-ind-1];
        if ( abs( ret ) == abs( vvv + funcEq( ind+1 ) ) ){
            ansA += A[ind];
            ansB += B[ind];
            printEq(ind+1);
            return ;
        }
        if ( abs(ret) ==  abs(  vvv + funcLs( ind+1 ) ) ){
            ansA += A[ind];
            ansB += B[ind];
            printLs(ind+1);
            return ;
        }
        if ( abs(  vvv + funcGr( ind+1 ) ) == abs(ret) ){
            ansA += A[ind];
            ansB += B[ind];
            printGr(ind+1);
            return ;
        }
    }else if ( A[ind] == '?' && B[ind] != '?' ){
        int f = B[ind]-'0';
        if ( f-1>=0 ){
            LL tmp = -1*power[n-ind-1] + funcGr( ind+1 );
            if ( abs(tmp) == abs(ret) ){
                ansA += char( (f-1)+'0' );
                ansB += B[ind];
                printGr(ind+1);
                return ;
            }
        }
        {
            LL tmp = funcEq( ind+1 ) ;
            if ( abs(tmp) == abs(ret) ){
                ansA += B[ind];
                ansB += B[ind];
                printEq(ind+1);
                return ;
            }
        }
        if ( f+1<=9 ){
            LL tmp = +1*power[n-ind-1] + funcLs( ind+1 ) ;
            if ( abs(tmp) ==  abs(ret) ){
                ansA += char( (f+1)+'0' );
                ansB += B[ind];
                printLs(ind+1);
                return ;
            }
        }

    }else if ( B[ind] == '?' && A[ind] != '?' ){
        int f = A[ind]-'0';
        if ( f-1>=0 ){
            LL tmp = 1*power[n-ind-1] + funcLs( ind+1 );
            if ( abs(tmp) == abs(ret) ){
                ansA += A[ind];
                ansB += char( (f-1)+'0' );
                printLs(ind+1);
                return ;
            }
        }
        {
            LL tmp = funcEq( ind+1 ) ;
            if ( abs(tmp) == abs(ret) ){
                ansA += A[ind];
                ansB += A[ind];
                printEq(ind+1);
                return ;
            }
        }
        if ( f+1<=9 ){
            LL tmp = -1*power[n-ind-1] + funcGr( ind+1 );
            if ( abs(tmp)== abs(ret) ){
                ansA += A[ind];
                ansB += char( (f+1)+'0' );
                printLs(ind+1);
                return ;
            }
        }

    }else{

        if ( abs( funcEq(ind+1) ) == abs(ret) ){
            ansA+="0";
            ansB+="0";
            printEq(ind+1);
            return ;
        }
        if ( abs( -1*power[n-ind-1] + funcGr( ind+1 ) ) == abs(ret) ){
            ansA+="0";
            ansB+="1";
            printGr(ind+1);
            return ;
        }
        if ( abs( 1*power[n-ind-1] + funcLs( ind+1 ) ) == abs(ret) ){
            ansA+="1";
            ansB+="0";
            printLs(ind+1);
            return ;
        }

    }
    assert( false );

}

int main(){

    freopen("B-large.in","r",stdin);
    freopen("outB.out","w",stdout);



    power[0] = 1;
    FO(i,1,SIZE){
        power[i] = power[i-1] * 10LL;
    }

    int kase;
    scanf("%d",&kase);

    for (int kk=1;kase--;++kk){

        scanf("%s %s",A,B);
        n = strlen(A);
        CLR(vis1);
        CLR(visG);
        CLR(visL);


        funcEq(0);
        printf("Case #%d:",kk);

        ansA="";
        ansB="";

        printEq(0);
        printf(" %s %s\n",ansA.c_str(),ansB.c_str());
    }

    return 0;
}
