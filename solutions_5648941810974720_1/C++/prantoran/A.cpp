#include<bits/stdc++.h>
#define ll long long
using namespace std;

int a[30];

int b[15][30];

int t,len;
char s[2222];

string num[15];
vector<pair<char,int> > det[5];
int cnt[30];

int main(){
    freopen("A-large.in","r",stdin);
    freopen("out.txt","w",stdout);

    num[0]="EORZ";
    num[1]="EON";
    num[2]="OTW";
    num[3]="EEHRT";
    num[4]="FORU";
    num[5]="EFIV";
    num[6]="ISX";
    num[7]="EENSV";
    num[8]="EIGHT";
    num[9]="EINN";

    for(int i = 0 ; i < 10;i++){
        int lb = num[i].length();
        for(int j = 0 ,id; j < lb;j++){
            id = num[i][j]-'A';
            b[i][id]++;
        }
    }

    det[0].push_back({'G',8});
    det[0].push_back({'U',4});
    det[0].push_back({'W',2});
    det[0].push_back({'X',6});
    det[0].push_back({'Z',0});

    det[1].push_back({'F',5});
    det[1].push_back({'S',7});
    det[1].push_back({'T',3});
    det[1].push_back({'O',1});

    det[2].push_back({'I',9});


    scanf("%d ",&t);
    for(int ca=1;ca<=t;ca++){
        scanf("%s",&s);
        len = strlen(s);
        memset(a,0,sizeof(a));
        for(int i = 0,id ; i < len;i++){
            id = s[i]-'A';
            a[id]++;

        }
        memset(cnt,0,sizeof(cnt));

        for(int i = 0 ; i < 3;i++){
            for(auto e:det[i]){
                int id = e.first-'A';
                if(a[id]>0){
                    cnt[e.second]+=a[id];
                    int buff = a[id];
                    for(int i = 0 ; i< 28;i++){
                        a[i]-=b[e.second][i]*buff;
                    }
                }
            }
        }

        printf("Case #%d: ",ca);
        for(int i = 0 ; i < 10;i++){
            while(cnt[i]){
                printf("%d",i);
                cnt[i]--;
            }
        }printf("\n");


    }


    return 0;
}
