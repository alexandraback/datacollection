#include"cstdio"
#include"iostream"
#include"map"
#include"string"
#include"cstring"
#include"vector"
#include"utility"
#include"algorithm"
#include"cmath"
#include"queue"
#include"stack"
#include"set"

using namespace std;

string Keys;
string Tar;
int tar_len;
int tL;

int max_ba;
int sum_ba;

int compute(const string &str,const string &tar){
    int sum=0;
    for(int i=0;i<=tar_len-tL;i++){
        bool ok=true;
        for(int j=0;j<tL;j++){
            if(str[j+i]!=tar[j]){
                ok=false;
                break;
            }
        }
        if(ok){sum++;}
    }
    return sum;
}
int dfs(int depth,int *arr){
    if(depth==tar_len){
        string tt="";
        for(int i=0;i<tar_len;i++){tt.push_back(arr[i]);}
        //cout<<tt<<endl;
        int tmp=compute(tt,Tar);
        if(tmp>max_ba){max_ba=tmp;}
        sum_ba+=tmp;
        return 1;
    }

    for(int i=0;i<Keys.size();i++){
        arr[depth]=Keys[i];
        dfs(depth+1,arr);
    }
}
int main(){
    freopen("d:B-small-attempt0.in","r",stdin);
    freopen("d:B.out","w",stdout);

	int T;
	int casenum=0;
	cin>>T;
	while(casenum++<T){
        sum_ba=max_ba=0;
        int K,L,S;
        cin>>K>>L>>S;
        tar_len=S;
        tL=L;

        cin>>Keys;
        string target;
        cin>>target;
        Tar=target;

        int ty[10];
        for(int i=0;i<Keys.size();i++){
            ty[i]=Keys[i];
        }

        dfs(0,ty);
        double Br=max_ba;
        double Bc=sum_ba;
        //printf("sum=%d\n",sum_ba);

        Bc/=(double)pow((double)K,(double)S);
        printf("Case #%d: %lf\n",casenum,Br-Bc);

	}


return 0;}
