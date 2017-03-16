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
      cin >> t;
      while(t--){

                int x , r , c;
                cin >> x >> r >> c;
                cout <<"Case #"<<tt++<<": ";
            int flag = 0;
         if(x == 1 )
            {
             cout << "GABRIEL"<<endl;
             flag = 1;
         }
            else
                if(x== 2)
            {
                  if(!(r*c & 1))
                  {
                      cout << "GABRIEL"<<endl;
                       flag = 1;
                  }
            }
               else
                if(x == 3)
               {
                   if( (r*c)%3 == 0 && (r > 1 && c > 1))
                   {
                       cout << "GABRIEL"<<endl;
                        flag = 1;
                   }
               }
                else {
                     if((r == 4 && c == 4) || (r == 3 && c == 4) || (r == 4 && c == 3 ))
                     {
                         cout << "GABRIEL"<<endl;
                        flag = 1;
                     }
                }
                   if(flag == 0 )
                    cout << "RICHARD" << endl;
}
    return 0;
}
