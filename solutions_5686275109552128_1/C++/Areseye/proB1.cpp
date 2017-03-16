#include"iostream"
#include"vector"
#include"string"
#include"cmath"
#include"fstream"

using namespace std;

#define PMAX 1009

int main(){

    freopen("d:B-large.in","r",stdin);
    freopen("d:outB.txt","w",stdout);

    int T;
    cin>>T;
    int casenum=0;
    while(casenum++<T){

        int D;
        cin>>D;
        vector<int>P;
        int p_num[PMAX];
        memset(p_num,0,sizeof(p_num));

        int vmax=0;

        for(int i=0;i<D;i++){
            int temp;
            cin>>temp;
            P.push_back(temp);
            if(temp>vmax){vmax=temp;}
            p_num[temp]++;
        }
        int ans=vmax;
        int cur_ans=vmax;


        int high_thres=vmax;

        for(int i=(int)sqrt((double)vmax/p_num[vmax])+1;i>0;i--){
            high_thres=vmax/i;//hight after split
            if(vmax%i>0){
                high_thres++;
            }
            cur_ans=p_num[vmax]*(i-1);

            for(int j=vmax-1;j>0;j--){
                //j pies in a plate
                if(p_num[j]<=0)continue;
                int partnum=(int)sqrt((double)j/p_num[j])+1;
                int temp_cost=(partnum-1)*p_num[j];
                int half_h=j/partnum;
                if(j%partnum>0){half_h++;}
                int rem_thres=high_thres;
                int rem_partnum=partnum;
                if(half_h>high_thres){temp_cost+=half_h-high_thres;rem_thres=half_h;}
                rem_thres=high_thres;

                for(int k=partnum;k>0;k--){
                    //greedy
                    int cur_temp_cost=(k-1)*p_num[j];
                    half_h=j/k;
                    if(j%k>0){half_h++;}
                    if(half_h>high_thres){cur_temp_cost+=half_h-high_thres;}

                    if(cur_temp_cost<temp_cost){
                        temp_cost=cur_temp_cost;
                        rem_thres=half_h>high_thres?half_h:high_thres;
                        rem_partnum=k;
                    }
                }
                high_thres=rem_thres;
                cur_ans+=p_num[j]*(rem_partnum-1);
            }
            cur_ans+=high_thres;
            if(cur_ans<ans){
                    //printf("i=%dhigh thres=%d\n",i,high_thres);
                    ans=cur_ans;}
        }




        printf("Case #%d: %d\n",casenum,ans);
    }


return 0;}
