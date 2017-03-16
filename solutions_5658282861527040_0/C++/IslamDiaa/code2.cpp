#include<iostream>
using namespace std;

int T,A,B,K;

int main()
{
    freopen("in1.in","r",stdin);
    freopen("out.out","w",stdout);
    cin >> T;
    int t = 1;
    while(T--)
    {
              cin >> A >> B >> K;
              int res = 0;
              for(int i = 0; i < A; i++)
                      for(int j = 0; j < B; j++)
                              if((i&j) < K)
                                     res++;
                         
              cout << "Case #"<<t++<<": " << res << endl;          
              
    }   
}
