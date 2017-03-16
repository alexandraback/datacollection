#include<bits/stdc++.h>
using namespace std;

int a[][5]={{0,1,2,3,4},{0,1,2,3,4},{0,2,-1,4,-3},{0,3,-4,-1,2},{0,4,3,-2,-1}};
map<char,int> mean;
int cypos[][5]={{1,0,0,0,0},{1,1,1,1,1},{1,2,-1,-2,1},{1,3,-1,-3,1},{1,4,-1,-4,1}};
int cyneg[][5]={{1,0,0,0,0},{1,-1,1,-1,1},{1,-2,-1,2,1},{1,-3,-1,3,1},{1,-4,-1,4,1}};
int arr[100010];
int main(){
    int t,d;
    //ifstream cin("C-large.in");
    //ofstream cout("large.txt");
    mean['i']=2,mean['j']=3,mean['k']=4;
    cin>>t;
    long long l,X;
    string s;
    for(int tt=1;tt<=t;tt++){

        cin>>l>>X;
        cin>>s;
        long long fr=0,ba=0,fi=0,fj=0;
        for(int i=0;i<l;i++){
            if(fr>=0){
                fr=a[fr][mean[s[i]]];
            }
            else{
                fr=-a[(-fr)][mean[s[i]]];
            }
            if(fr==2&&fi==0){
                fi=i+1;
            }
            if(fr==(4)&&fi>0){
                fj=i+1;
            }
            arr[i]=fr;
        }
        if(fi==0){
            fi=X*l+1;
        }
        for(int i=1;i<=4&&(i<X);i++){
            int j=0,x,v;
            if(fr>0)v=cypos[fr][i];
            else v=cyneg[(-fr)][i];
            for(j=0;j<l;j++){
                if(v>0){
                    if(arr[j]>0){
                        x=a[v][arr[j]];
                    }
                    else x=-a[v][(-arr[j])];
                }
                else {
                     if(arr[j]>0){
                        x=-a[(-v)][arr[j]];
                    }
                    else x=a[(-v)][(-arr[j])];
                }
                if(x==2){
                    break;
                }
            }
            if(x==2){
                fi=min(fi,(i*l+j+1LL));
            }
            for(j=0;j<l;j++){
                if(v>0){
                    if(arr[j]>0){
                        x=a[v][arr[j]];
                    }
                    else x=-a[v][(-arr[j])];
                }
                else {
                     if(arr[j]>0){
                        x=-a[(-v)][arr[j]];
                    }
                    else x=a[(-v)][(-arr[j])];
                }
                if(x==4){
                    int cl=4;
                    if(fr==1)cl=1;
                    if(fr==-1)cl=2;
                    long long y=X/cl;
                    if((X%cl)>=i){
                        y=y*cl*l+(i*l)+j+1LL;
                        if(y>=(X*l)){
                            y-=(cl*l);
                        }
                    }
                    else {
                            y=(y-1)*cl*l+(i*l)+j+1LL;
                            if(y>=(X*l)){
                            y-=(cl*l);
                            }
                    }
                    fj=max(fj,y);
                }
            }
        }
        //cout<<fi<<".."<<fj<<endl;
        if(fr>0)
            fr=cypos[fr][(X%4)];
        else fr=cyneg[(-fr)][(X%4)];
        if(fr==-1&&fi>0&&fi<fj&&fj<=(X*1LL*l))
            cout<<"Case #"<<tt<<": YES"<<endl;
        else cout<<"Case #"<<tt<<": NO"<<endl;

    }
    return 0;
}
