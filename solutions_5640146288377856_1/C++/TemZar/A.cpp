#include <cstdlib>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{int T,i,R,C,W,D,d;
 freopen("A-large.in","r",stdin);
 freopen("A-large.out","w",stdout);
 cin>>T;
 for(i=1;i<=T;i++)
 {cin>>R>>C>>W;
  d=0;
  D=C/W;
  d+=D*R;
  if(C%W==0)d+=W-1;
  else d+=W;
  cout<<"Case #"<<i<<": "<<d;
  cout<<endl;
//  cout<<' '<<R<<' '<<C<<' '<<W<<endl;
 }
 
//    system("PAUSE");
    return EXIT_SUCCESS;
}
