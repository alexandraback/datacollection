#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
int GetnoDigits(int n)
{
    int count=0;
    while ( n != 0)
    {
        count++;
        n/=10;
    }
    return count-1;

}
void TryRecycle(int &n, int NumDigits)
{
   // int NumDigits=GetnoDigits(n);
    int a =0;

            a =n%10;
            n/=10;
            n = n + a*pow(10,NumDigits);

      //  return n;

}
vector <int > TryRecycle(vector<int> & V,int x)
{
    rotate(V.begin(),V.begin()+1,V.end());

}
int convertTOint(vector<int> & V)
{
    int x=0;
    //1 2 3 4 5
    for ( int i=V.size() -1   ; i >= 0 ; i--)
    {
        x= x + V[i]*pow(10,-i+V.size() -1) ;


    }
    return x;

}
void GetArray(int n,vector<int> & V)
{
    int x= n;
    while ( n != 0)
    {

        V.push_back(n%10);
        n/=10;

    }
    reverse(V.begin(),V.end());
//    for ( int i=0 ; i <V.size() ; i++)
//    cout<< V[i]<<" ";
//    cout<<endl;

}
void run(int t,int A,int B)
{
    uint64_t count=0;

    for ( int i=A ; i <= B ; i++)
    {
        map<int,bool> Mp;
     //   cout<<"START "<<i<<endl;
       //         vector<int > V;
     // GetArray(i,V);
     int n=i;
     int Dig=GetnoDigits(n);
  //    cout<<endl;
      for ( int j =0 ; j <= Dig ; j++)
      {
     //     vector<int> Z = V;
          //TryRecycle(Z,j);

          TryRecycle(n,Dig) ;//convertTOint(Z);
          //cout<<p<<endl;

          if (n >= i+1 && n<=B && Mp.find(n) == Mp.end() )
          {
              Mp[n] = true;
              count++;
          }
//          for ( int m =i+1 ; m <=B ; m++ )
//          {
//              ;
//              if (n == m)
//              {
//                  h.first=n;
//                  h.second=m;
//                  if ( Mp.find(h) == Mp.end() &&  Mp.find(h) == Mp.end() )
//                  {
//                      count++;
//                      Mp[h]= true;
//                  }
//                  //cout<<count<<"  "<<i<<"   "<<p<<endl;
//
//
//              }
//          }


      }
    }

cout<< "Case #"<<t+1<<": "<<count<<endl;

}
int main()
{

//    int n= 123456;


    freopen("C-large.in","r",stdin);
    freopen("OUT2.TXT","w",stdout);

    int T;
    cin>>T;
    for ( int I=0 ; I < T; I ++)
    {
        int A, B;
        cin>>A>>B;
        run(I,A,B);
    }

}
