#include<iostream>
#include<fstream>
using namespace std;
long long  rev( long long n)
{
      long long s = 0;
      while(n)
      {
          s= s*10+(n%10);
          n = n/10;
      }
       return s;
}
long long  arr[1000001];
int main()
{
    arr[1] = 1;
    for(long long i = 2; i <= 1000000; ++i ){
            int r = rev(i);
             if( r < i && rev(r) == i)
        arr[i] = 1+min(arr[i-1] ,arr[r]);
        else
            arr[i]=1+arr[i-1];
    }
       ifstream cin("aa.txt");
       ofstream cout("bb.txt");
       int t , tt = 1;
       cin >> t;
       while(t--){
         long long n,ans = 1;
         cin >> n;


           cout <<"Case #"<<tt++<<": "<<arr[n]<<endl;
       }
       return 0;
}
