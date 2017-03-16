//Google codeJam 2013 Round 1C Problem C
//Abdurrahman Akkas
//recursive fonksiyon yazmayacagima yemin ederim
#include<iostream>
using namespace std;
int main(){
    long long T,i,N;
    cin >> T;
    long long saldiri[100][5];//ok,gun,s,w,e
    long long sn,total;
    long long d,n,w,e,s,dd,dp,ds;
    for(i=1;i<=T;i++)
    {
        total=0;
        sn=0;
        long long duvar[10002]={0};
        long long days[10000]={0};
        long long daysn=0;
        cin>>N;
        long long ii;
        for(ii=0;ii<N;ii++){
            cin>>d>>n>>w>>e>>s>>dd>>dp>>ds;
            long long iii;
            for(iii=0;iii<n;iii++){
                saldiri[sn][1]=d+dd*iii;
                saldiri[sn][2]=s+ds*iii;
                saldiri[sn][3]=(w+dp*iii)*2;
                saldiri[sn][4]=(e+dp*iii)*2;
                days[daysn]=d+dd*iii;
                daysn++;
                sn++; 
            }            
        }
        sort(days+0,days+daysn);
        for(ii=0;ii<daysn;ii++){
            if(ii>0&&days[ii]==days[ii-1])
                continue;
                long long iii;
                for(iii=0;iii<sn;iii++){
                    if(saldiri[iii][1]==days[ii]){
                        long long i4;
                        for(i4=saldiri[iii][3];i4<=saldiri[iii][4];i4++){
                            if(duvar[i4+200]<saldiri[iii][2]){
                                total++;
                                break;
                            }
                        }
                    }
                }
                for(iii=0;iii<sn;iii++){
                    if(saldiri[iii][1]==days[ii]){
                        long long i4;
                        for(i4=saldiri[iii][3];i4<=saldiri[iii][4];i4++){
                            if(duvar[i4+200]<saldiri[iii][2]){
                                duvar[i4+200]=saldiri[iii][2];
                            }
                        }
                    }
                }            
        }
        cout<<"Case #"<<i<<": "<<total<<"\n";
    }
    cin>>T;
    return 0;
}
