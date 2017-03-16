#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vii;

int main(void){
    freopen("B-large.in","r",stdin);
    freopen("out.txt","w",stdout);
    int tc,casecounter = 1;
    scanf("%d",&tc);
    vii AdjList;
    while(tc--){
        int r, c, num;
        scanf("%d %d",&r,&c);
        AdjList.clear();
        AdjList.assign(r,vi());
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                scanf("%d",&num);
                AdjList[i].push_back(num);
            }
        }
        while(true){
            int k = 0;
            while(k<(int)AdjList.size()){
                if((int)AdjList[k].size() == 0){
                    AdjList.erase(AdjList.begin()+k);
                    continue;
                }
                k++;
            }
            if((int)AdjList.size() == 0)
                break;
            int min = 1e9;
            int minc,minr;
            minr = minc = 0;
            for(int i=0;i<(int)AdjList.size();i++){
                for(int j=0;j<(int)AdjList[0].size();j++){
                    if(min>AdjList[i][j]){
                        minr = i;
                        minc = j;
                        min = AdjList[i][j];
                    }
                }
            }
            int numc = 0, numr = 0;
            bool rb = true, cb = true;
            // check the whole row
            for(int j = 0; j < (int)AdjList[minr].size(); j++)
                if (AdjList[minr][j]== min)
                    numr++;

            if (numr != (int)AdjList[minr].size())
                rb = false;

            // check the whole column
            for(int j = 0; j < (int)AdjList.size(); j++)
                if (AdjList[j][minc] == min)
                    numc++;
            if (numc != (int)AdjList.size())
                cb = false;

            // NO case
            if((cb == false) && (rb == false)){
                printf("Case #%d: NO\n",casecounter++);
                break;
            }

            // clean the the column that is good
            if (cb){
//		        		System.out.println("remove the whole col "+minc);
                for(int j = 0; j < (int)AdjList.size(); j++)
                    AdjList[j].erase(AdjList[j].begin()+minc);
                continue;
            }
            // clean the the row that is good
            else if(rb){
//		        		System.out.println("remove the whole row "+minr);
                AdjList.erase(AdjList.begin()+minr);
                continue;
            }
        }
        if((int)AdjList.size() !=0)	continue;
	        	printf("Case #%d: YES\n",casecounter++);
    }


    return 0;
}
