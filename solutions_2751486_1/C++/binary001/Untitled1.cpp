#include<fstream>
#include<cstring>
//#include<iostream>
using namespace std;

char a[1000007];


int main(){
    int t,x;

ofstream cout("out.txt");
ifstream cin("in.txt");
    
    cin>>t;
    for(int ww=1;ww<=t;ww++){

               cin>>a>>x;
long long  int ans=0;


int n=strlen(a);

int cnt=0;
int strt=-1;

                for(int w=0;w<n;w++){
                      if( a[w]!='a'  && a[w]!='e'  &&a[w]!='i'  &&a[w]!='o'  &&a[w]!='u' )
                          cnt++;
                          else
                          cnt=0;
                          
                          if(cnt==x){
                             ans+= ((w+1-x)-strt)* (n-w); 
                             strt=     (w+1-x);
                             cnt--;
                                     }




}






cout<<"Case #"<<ww<<": "<<ans<<"\n";

}
    return 0;
    }
