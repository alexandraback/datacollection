#include<fstream>
#include<cstring>
using namespace std;

   
int main(){

    bool note[2000001];
    
    ifstream infile("file.in");
    ofstream outfile("file.out");

    int T;
    int A,B;
    infile>>T;

    for(int t=1;t<=T;t++){
        infile>>A>>B;
        memset(note,0,sizeof(note));
        long long ans=0;
        for(int i=A;i<=B;i++){
            if(note[i]==0){
                int group=1;
                note[i]=1;

                int x=i;
                int ten=1;
                int count=0;
                while(x>0){
                    count++;
                    ten*=10;
                    x/=10;
                }
                ten/=10;
                count--;

                x=i;        
                for(int j=0;j<count;j++){
                    int a=x%10;
                    x=x/10+a*ten;
                    if(a!=0 && x>=A && x<=B && note[x]==0){
                        note[x]=1;
                        group++;
                    }
                }                
                ans+=(group*(group-1))/2;
            }
        }

        outfile<<"Case #"<<t<<": "<<ans<<endl;
    }
}
                    
                    

                    

    
