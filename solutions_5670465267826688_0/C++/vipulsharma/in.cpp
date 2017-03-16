#include<iostream>
#include<string>
#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    //ifstream cin("a.txt");
    //ofstream cout("b.txt");
      int t , tt = 1;
      int arr[5][5]={{0,0,0,0,0},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
      cin >> t;
      while(t--){
        int n , l;
         cin >> n >> l;
        string x;
        cin >> x;
        for(int i = 0 ; i < x.size() ; ++i){
            if(x[i]=='i')
                x[i] = '2';
            else
                if(x[i]=='j')
                x[i] = '3';
            else
                x[i] = '4';
               }
        string y;
        for(int i = 1 ; i <= l ; ++i )
                y+=x;

               int posi = 1e9, posj =  0 , posk = 0 ;
               int val = y[0]-'0';
               int sign = 1;
                if(val == 2)
                    posi = 0;
               for(int i = 1 ; i < n*l ; ++i ){
                      val = arr[val][y[i]-'0'];
                      val = val*sign;
                       if(val < 0 )
                        {
                         sign = -1;
                         val = val * sign;
                       }
                         else
                         sign = 1;
                         if(val == 2 && sign == 1)
                            posi = min(posi , i );
                         if(val == 4 && sign == 1 )
                            posj = max( posj , i );
                          if(val == 1 && sign == -1)
                           posk = max(posk , i);

                            }
                            cout <<"Case #"<<tt++<<": ";
                if((posi < posj && posj  < posk )&& posk == n*l-1)
                    cout << "YES" << endl;
                else
                    cout <<"NO" << endl;
}
    return 0;
}
