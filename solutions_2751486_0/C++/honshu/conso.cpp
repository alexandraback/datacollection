#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int name_valid(string name,int a, int b, int N); 
int main(){
    int T;
    cin>>T;
    int k; 
    for( k=0;k<T;k++){
        string name;
        int N;
        cin>>name;
        cin>>N;
        int gcount=0;
        for(int i=0;i<name.length();i++){
            int count=0;
            for(int j=i;j<name.length();j++){
                count += name_valid(name,i,j,N);
                if(count >= N){
                    count+=name.length()-1-j;
                    break;
                }
            }            
            gcount += count;
        }
       cout<<"Case #"<<k+1<<": "<<gcount<<endl;  
    }     
}

int name_valid(string name,int a, int b,int N){
    int gcount =0;int count=0;
    for(int i= a;i<=b;i++){
        if(name[i] == 'a' || name[i] == 'e' || name[i] == 'i' || name[i] == 'o' || name[i] == 'u' ){
            count =0;   
        }
        else{
            count++;
        }
        
        if(count >= N){
          break; 
        }    
    }
    if(count >= N){
        return 1;
    }
    else{
        return 0;
    }        
             
}                    
         
