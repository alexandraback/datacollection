#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<sstream>
#include<vector>
#include<cstdlib>
#include<iomanip>
#include<algorithm>
#include<cstdio>
#include<ctime>

using namespace std;

const double PI=3.14159265358979323846264338327950288;
ifstream fin;
ofstream fout;

int compare (const void * a, const void * b)
{
  double result = ( *(double*)a - *(double*)b );
  if(result>0) return 1;
  else if(result<0) return -1;
  else return 0;
}

void _main(){
    int N;
    int i,j,k;
    double Nao[1001], Ken[1001];
    int pt1, pt2;
    fin>>N;
    for(i=0;i<N;i++) fin>>Nao[i];
    for(i=0;i<N;i++) fin>>Ken[i];
    qsort(Nao,N,sizeof(double),compare);
    qsort(Ken,N,sizeof(double),compare);
    //for(i=0;i<N;i++) cout<<Nao[i]<<endl;
    //for(i=0;i<N;i++) cout<<Ken[i]<<endl;

    pt1 = 0;
    int minIn=0, maxIn=N-1;
    for(i=0;i<N;i++){
        if(Nao[i]<Ken[minIn]){
            maxIn--;
        }
        else if(Nao[i]>Ken[minIn]){
            minIn++;
            pt1++;
        }
        else cout<<"ERROR\n";
    }
    pt2 = 0;
    int index=0;
    for(i=0;i<N;i++){
        while(index<N && Nao[i]>Ken[index]) index++;
        //cout<<i<<" "<<index<<endl;
        //cout<<Nao[i]<<" "<<Ken[index]<<endl;
        if(index<N) index++;
        else{
            pt2 = N-i;
            break;
        }
        //cout<<i<<" "<<index<<endl;
    }
    fout<<pt1<<" "<<pt2;
}

int main(){
    fin.open("sample.in");
    fout.open("result.out");
    int T;
    fin>>T;
    for(int i=0;i<T;i++){
            fout<<"Case #"<<i+1<<": ";
            cout<<"Case #"<<i+1<<" is runing"<<endl;
            _main();
            fout<<endl;
    }
}
