#include<iostream>
#include<fstream>
using namespace std;
int main(){
    int t;
    int n;
    int i,j,k,x;
    int huge[2600];
    ofstream out("Q2.out");
    cin>>t;
    for (i=0;i<t;i++){
        for (k=0;k<2600;k++) huge[k]=0;
        cin>>n;
        for (j=0;j<2*n-1;j++){
            for (k=0;k<n;k++){
                cin>>x;
                huge[x]++;
            }
        }
        //for (k=0;k<t;k++){
        out<<"Case #"<<i+1<<": ";
        for (x=0;x<2600;x++){
            if (huge[x]%2==1){
               out<<x;
               break;
            }
        }
        for (j=x+1;j<2600;j++) 
            if (huge[j]%2==1) out<<" "<<j;
        out<<endl;
    }
    //while (1);
}
