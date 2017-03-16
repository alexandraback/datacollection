#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <map>
using namespace std;
vector <int > TryRecycle(vector<int> & V,int x)
{
    rotate(V.begin(),V.begin()+x,V.end());

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
    int count=0;

    for ( int i=A ; i <= B ; i++)
    {
        map<pair<int,int>,bool> Mp;
     //   cout<<"START "<<i<<endl;
                vector<int > V;
      GetArray(i,V);
  //    cout<<endl;
      for ( int j =0 ; j < V.size() ; j++)
      {
          vector<int> Z = V;
          TryRecycle(Z,j);

          int p = convertTOint(Z);
          //cout<<p<<endl;
          for ( int m =i+1 ; m <=B ; m++ )
          {
              pair<int,int> h;
              if (p == m)
              {
                  h.first=p;
                  h.second=m;
                  if ( Mp.find(h) == Mp.end() &&  Mp.find(h) == Mp.end() )
                  {
                      count++;
                      Mp[h]= true;
                  }
                  //cout<<count<<"  "<<i<<"   "<<p<<endl;


              }
          }


      }
    }
cout<< "Case #"<<t+1<<": "<<count<<endl;

}
int main()
{
    freopen("C-small-attempt0.in","r",stdin);
    freopen("out2.txt","w",stdout);

    int T;
    cin>>T;
    for ( int i=0 ; i < T; i ++)
    {
        int a, b;
        cin>>a>>b;
        run(i,a,b);
    }

}
