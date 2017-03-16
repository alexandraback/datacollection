#include<vector>
#include <utility>
#include<iostream>
#include <algorithm>



char vect[20];
long invert(long in){
int ind=0;
while(in!=0){
vect[ind]=in%10;
ind++;
in/=10;

}
int i;
long ret=0;
for(i=0;i<ind;i++){
ret*=10;
ret+=vect[i];
}

return ret;

}

int din[1000005];

using namespace std;

int main(void){
long T,ii;
long long N;




din[1]=1;
for(ii=2;ii<=1000000;ii++){
din[ii]=din[ii-1]+1;
long inv=invert(ii);
if(inv<ii && invert(inv)==ii && (din[inv]+1)<din[ii])din[ii]=din[inv]+1;
}


/*for(ii=0;ii<25;ii++){
cout<<din[ii]<<endl;
}*/

cin>>T;
for(ii=0;ii<T;ii++){
cin>>N;
cout<<"Case #"<<(ii+1)<<": "<<din[N]<<endl;


}


return 0;
}
