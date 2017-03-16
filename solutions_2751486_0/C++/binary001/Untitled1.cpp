#include<fstream>
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
for(int i=0;i<n;i++){
        for(int j=i+1;j<=n;j++){
                int flg=0;
                int main_flg=0;
                
                for(int w=i;w<j;w++){
                      if( a[w]!='a'  &&a[w]!='e'  &&a[w]!='i'  &&a[w]!='o'  &&a[w]!='u' )
                      flg++;
                      else 
                      flg=0;
                      if(flg>=x)
                        main_flg=1;
                        
                        }
                        if(main_flg==1)
                        ans++;
                
                }
        
        }

cout<<"Case #"<<ww<<": "<<ans<<"\n";

}
    return 0;
    }
