#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

long long X;
long long Y;
long long limit=500;
bool done;

void find(){
  long long xPos=0;
  long long yPos=0;
  while(xPos!=X || yPos!=Y){
    if(xPos<X){
      xPos+=1;
      cout << "WE";
    }else if(xPos>X){
      xPos-=1;
      cout << "EW";
    }else if(yPos<Y){
      yPos+=1;
      cout << "SN";
    }else if(yPos>Y){
      yPos-=1;
      cout << "NS";
    }
  }
}

// NSEW
int main(){
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;++t){
    printf("Case #%d: ",t);
    scanf("%lld %lld",&X,&Y);
    find();//reverse path
    printf("\n");
  }
}
