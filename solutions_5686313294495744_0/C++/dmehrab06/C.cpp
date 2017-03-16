#include <bits/stdc++.h>
#define MIN(X,Y) X<Y?X:Y
#define MAX(X,Y) X>Y?X:Y
#define ISNUM(a) ('0'<=(a) && (a)<='9')
#define ISCAP(a) ('A'<=(a) && (a)<='Z')
#define ISSML(a) ('a'<=(a) && (a)<='z')
#define ISALP(a) (ISCAP(a) || ISSML(a))


using namespace std;

int GCD(int a,int b){
    return a==0?b:GCD(b%a,a);
}

string ntoa(int b){
    string a="";
    while(b){
        a+=(b%10+'0');
        b/=10;
    }
    reverse(a.begin(),a.end());
    return a;

}

struct myitem{
    int h;
    int w;
    myitem(int a, int b){
        h=a;
        w=b;
        if(h>w){
            int t=h;
            h=w;
            w=t;
        }
    }
};


int main(){
    int t;
    scanf("%d",&t);
    int cs=1;
    while(t--){
        int n;
        vector<string>wordf;
        vector<string>words;
        map<string, vector<int> >firstwords;
        map<string,vector<int> >secondwords;
        scanf("%d",&n);
        string f,s;
        for(int i=0;i<n;++i){
            cin>>f>>s;
            wordf.push_back(f);
            words.push_back(s);
            firstwords[f].push_back(i);
            secondwords[s].push_back(i);
        }
        int msk=1;
        msk<<=n;
        msk-=1;
        int mxfaked=-1;
        for(int i=0;i<=msk;++i){
            int allvalid=1;
            int nowassumel=0;
            int mask=1;
            while(mask){
                if(mask&i){
                    nowassumel++;
                }
                mask<<=1;
            }
            mask=1;
            int jj=0;
            while(mask){
                if(mask&i){
                    string nowfirst=wordf[jj];
                    string nowsecond=words[jj];
                    int lfirst=firstwords[nowfirst].size();
                    int lsecond=secondwords[nowsecond].size();
                    bool firstcheck=false;
                    for(int k=0;k<lfirst;++k){
                        if(firstwords[nowfirst][k]!=jj){
                            firstcheck=true;
                            break;
                        }
                    }
                    bool secondcheck=false;
                    for(int k=0;k<lsecond;++k){
                        if(secondwords[nowsecond][k]!=jj){
                            secondcheck=true;
                            break;
                        }
                    }
                    if(!firstcheck || !secondcheck){
                        allvalid=0;
                        break;
                    }
                }
                mask<<=1;
                jj++;
            }
            if(allvalid==1){
                if(nowassumel>mxfaked){
                    mxfaked=nowassumel;
                }
            }
        }
        printf("Case #%d: %d\n",cs++,mxfaked);


    }
}
