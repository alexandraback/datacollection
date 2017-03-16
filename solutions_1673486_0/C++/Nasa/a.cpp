#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

double p[1000],left1[1000];//,rightcorrect[1000],rightall[1000];

int main(){
    int u,t,i,j,k,a,b;
    cin>>t;
    for (u=0; u<t; u++){
        cin>>a>>b;
        for (i=1; i<=a; i++) cin>>p[i];
        double mn=1+b+1; //give up
        left1[0]=1;
        for (i=1; i<=a; i++){
            left1[i]=left1[i-1]*p[i];
//            cout<<i<<" "<<left1[i]<<endl;
        }
        /*rightcorrect[a+1]=1;
        rightall[a+1]=0;
        for (i=a; i>=1; i--){
            rightall[i]=rightall[i+1]+rightcorrect[i+1]*(1-p[i]);
            rightcorrect[i]=rightcorrect[i+1]*p[i];
        }*/
        for (i=0; i<=a; i++){
            double now=i/*bksp*/+(b-a+i+1)/*type in*/+(left1[a-i]*(0)+((1-left1[a-i])*(b+1)/*wrong*/));
            mn=min(mn,now);
//            cout<<i<<": "<<now<<","<<mn<<endl;
        }
        cout<<"Case #"<<(u+1)<<": "<<mn<<endl;
    }
	return 0;
}

