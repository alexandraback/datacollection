#include <iostream>

using namespace std;

long long T,C,L,X;
const int MAX_L=10010;

int q_m[4][4]={
    {0,1,2,3},
    {1,0,3,2},
    {2,3,0,1},
    {3,2,1,0}
};

int q_m_sign[4][4]={
    {1,1,1,1},
    {1,-1,1,-1},
    {1,-1,-1,1},
    {1,1,-1,-1}
};

int INPUT[MAX_L];

int main(int argc, char const *argv[])
{
    cin>>T;
    for(C=1;C<=T;++C){
        cin>>L;
        cin>>X;
        int num=0;
        int p;
        int sign=1;
        bool goon=false;
        string ans="NO";
        bool type[3]={0,0,0};
        for(int i=0;i<L;++i){
            char inp;
            cin>>inp;
            p=inp-'i'+1;
            INPUT[i]=p;
            type[p-1]=true;
            sign=q_m_sign[num][p]*sign;
            num=q_m[num][p];
        }
        int type_num=0;
        for(int i=0;i<3;++i) type_num+=(type[i]?1:0);
        if(type_num>1){
            int nX=X%4;
            int nnum=0;
            int nsign=1;
            for(int i=0;i<nX;++i){
                nsign=q_m_sign[nnum][num]*sign*nsign;
                nnum=q_m[nnum][num];
            }
            if(nsign==-1 && nnum==0){
                goon=true;
            }
            int lli=0;
            if(goon){
                goon=false;
                int num=0;
                int p;
                int sign=1;
                for(int i=0;i<L*4;++i){
                    p=INPUT[i%L];
                    sign=q_m_sign[num][p]*sign;
                    num=q_m[num][p];
                    if(num==1 && sign==1){
                        lli=i;
                        goon=true;
                        break;
                    }
                }
            }
            if(goon){
                int nnum=0;
                int nsign=1;
                for(int j=0;j<L*4;++j){
                    p=INPUT[L-1-j%L];
                    nsign=q_m_sign[p][nnum]*nsign;
                    nnum=q_m[p][nnum];
                    if(nnum==3 && nsign==1){
                        if(lli+1+j+1<L*X) ans="YES";
                        break;
                    }
                }
            }
        }
        cout<<"Case #"<<C<<": "<<ans<<endl;
    }
    return 0;
}
