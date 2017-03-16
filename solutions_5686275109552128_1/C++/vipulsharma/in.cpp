#include<iostream>
#include<vector>
#include<fstream>
#include<algorithm>
using namespace std;
int main()
{
      //ifstream in("a.txt");
      //ofstream out("b.txt");
      int t , tt = 1;
      cin >> t;
      while(t--)
      {

            int n ;
            cin >> n;
            int a[n+1];
            int mx = 0;
            for(int i = 0; i < n ; ++i ){
                cin >> a[i];
                mx = max( mx,  a[i]);
            }
              int val , as = mx ;
               for(int i =  1 ; i <= mx ; ++i )
                {
                       val = 0;
                 for(int j = 0; j < n ; ++j )
                 {
                     if (a[j] > i )
                     {
                          val = val + (a[j]/i - 1 );
                          val = val + (((a[j]%i)==0) ? 0:1);

                     }

                 }
                 val = val + i;
                  as = min ( as , val );
               }
                 cout <<"Case #"<<tt++<<": "<<as << endl;
      }
        return 0;

}
