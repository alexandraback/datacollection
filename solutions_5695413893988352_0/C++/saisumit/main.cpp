
 #include <bits/stdc++.h>
using namespace std;
 /*
  Mistakes -
   0) Dont rush to conclusion on seeing a question , keep yourself relaxed and go easy on ques .
   1) To see at each step if integer is not causing an error , best way is to use long long always.
   2) To see if my solution can be verified , if yes then do that .
   3) To see if my code can be simplified , if yes make it simple.
   4) If my code is wrong , dont be in a hurry to change to the code, first think for 2 min if any modification can be done to make it
      right.
   5) always typecast (int) arr.size() because   size_t does not support subtraction.
   6) Never use such expression   Int ct = max( ct ,left) ; (declartion should be done before assignment , absurd behaviour)
   7) Using l  ong long for everything may cause Time Limit Exceeded some times , so better be sure
   8) appending at the end of the string takes too much time 339 Div2 - B
   9) Keep calm and Code.

 */
#define REP(i, a, b) for (int i = a; i <= b; i++)
#define FOR(i, n) for (int i = 0; i < n; i++)
#define foreach(it, ar) for ( typeof(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
#define fill(ar, val) memset(ar, val, sizeof(ar))
#define PI 3.1415926535897932385
#define uint64 unsigned long long
#define Int long long
#define int64 long long
#define all(ar) ar.begin(), ar.end()
#define pb push_back
#define ff first
#define ss second
#define bit(n) (1<<(n))
#define Last(i) ( (i) & (-i) )
#define sq(x) ((x) * (x))
#define INF INT_MAX
#define mp make_pair

int ar [] = { 1 , 10 , 100 }  ;
char  a[100] ;
char  b[100] ;

int ans = INT_MAX ;

int aa , bb  ;

void  rec( int idx , int  po , int num1 , int num2  )
 {
    if (idx ==  strlen(a))
       {  int tp = abs (  num1 - num2 ) ;
          if(  tp < ans )
           { aa =  num1;
             bb = num2;
             ans =  tp ;}

           if( tp == ans  &&  num2 <  bb )
               { aa = num1 ; bb = num2 ; }


           return ;
        }



  if ( a[idx] == '?' && b[idx] == '?')
        for( int i = 0 ; i <= 9 ; i++ )
           for( int j = 0 ; j<= 9 ; j ++ )
                 rec(  idx +1 ,po-1,  num1 +i*ar[po] ,num2 + j*ar[po] ) ;

  else  if( a[idx] == '?' )
         for( int i = 0 ; i<= 9 ; i ++ )
                 rec(  idx +1 ,po-1 , num1 +i*ar[po] ,num2 + (b[idx]- '0')*ar[po] ) ;

  else  if( b[idx] == '?' )
         for( int i = 0 ; i<= 9 ; i ++ )
                 rec(  idx +1 , po-1, num1 +(a[idx]- '0')*ar[po]  ,num2 +i*ar[po])  ;

   else     rec(  idx +1 ,po-1 ,  num1 +(a[idx]- '0')*ar[po]  , num2 + (b[idx]- '0')*ar[po]  ) ;



 }
int main()
{
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
int t;
    cin >> t;
 for( int p = 1 ; p<= t ; p ++ )
     {

 ans = INT_MAX ;


 scanf(" %s",a);

 scanf(" %s",b);

  rec(  0 , strlen(a)  -1,0,0) ;




 cout<<"Case #"<<p<<": ";
 string ansa =  to_string(aa);
 string ansb = to_string(bb);

 int di =  (int)strlen(a) - (int)ansa.length();
 int di2 =  (int)strlen(b) - (int)ansb.length();
 FOR( i , di)cout<<0;
 cout<<aa;
 cout<<" ";
  FOR( i , di2)cout<<0;
 cout<<bb;

  cout<<endl;



      }

 }
