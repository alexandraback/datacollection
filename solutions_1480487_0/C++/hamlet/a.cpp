#include<cstdio>
#include<cctype>
#include<cstdlib>
#include<cmath>
#include<string>
#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#include<set>
using namespace std;

int main(){
    
   // cout<<24+75*0.34666666666<<" "<<30+75*0.26666666666<<" "<<21+75*0.38666666666666666<<endl;
    
   	int tc;cin>>tc;
	for(int caso=1;caso<=tc;caso++){
        int n;
        cin>>n;
        int c[n];
        int sum=0;
        vector<bool>participa(n,1);
        for(int i=0;i<n;i++){   
            cin>>c[i];
            sum+=c[i];
        }
        
        for(int i=0;i<n;i++){   
            if(c[i]*n>=sum*2 )participa[i]=0;
        }
        
        int val=0;
        int cont=0;
        for(int i=0;i<n;i++){   
            if(participa[i] ){
                val+=c[i];
                cont++;
            }
        }
        
        int aux=sum;
        sum=sum+val;
        
        cout<<"Case #"<<caso<<":";
        for(int i=0;i<n;i++){
            if(!participa[i]){
                printf(" %.10lf", 0.0);        
            }else{
                printf(" %.10lf", 100.0*(((double)sum)/cont-c[i] )/aux );    
            }
        }
        cout<<endl;
    }
	
	return 0;
}
