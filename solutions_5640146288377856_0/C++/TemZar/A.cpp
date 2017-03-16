#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{int T,i,R,C,W,D,d;
 freopen("A-small2.in","r",stdin);
 freopen("A-small.out","w",stdout);
 cin>>T;
 for(i=1;i<=T;i++)
 {cin>>R>>C>>W;
  d=0;
  if(2*W>=C){d=W+1;if(d>C)d=C;}
  else
  {while(2*W<C){C-=W;d++;}
   d+=W+1;
  }
  cout<<"Case #"<<i<<": "<<d;
  cout<<endl;
//  cout<<' '<<R<<' '<<C<<' '<<W<<endl;
 }
 
//    system("PAUSE");
    return EXIT_SUCCESS;
}
