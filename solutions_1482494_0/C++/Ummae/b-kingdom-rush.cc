#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(const pair<int,int>& p1, const pair<int,int>& p2)
{
    return p1.second > p2.second;
}

int main()
{
    int T;
    scanf("%d", &T);
    for(int tcase=1; tcase<=T; ++tcase)
    {
        int N;
        scanf("%d", &N);
        vector<pair<int,int> > levels;
        vector<pair<bool,bool> > clear;
        for(int i=0; i < N; ++i){
            pair<int,int> p;
            scanf("%d %d", &p.first, &p.second);
            levels.push_back(p);
            clear.push_back(make_pair(false,false));
        }

        int rating=0;
        sort(levels.begin(), levels.end(),cmp);
        int step=0;
        bool pass=true;
        while(true)
        {
            pass=true;
            for(int i=0; i < N; ++i){
                if(!clear[i].second){
                    pass=false;
                    break;
                }
            }
            if(pass) break;

            int l=-1, r=-1;
            for(int i=0; i < N; ++i){
                if(!clear[i].second && !clear[i].first && rating >= levels[i].second){
                    l=i;
                    r=2;
                    break;
                }
            }

            for(int i=0; l==-1 && i < N; ++i){
                if(clear[i].first && !clear[i].second && rating >= levels[i].second){
                    l=i;
                    r=2;
                    break;
                }
            }

            for(int i=0; l==-1 && i < N; ++i){
                if(!clear[i].first && !clear[i].second && rating >= levels[i].first){
                    l=i;
                    r=1;
                    break;
                }
            }

            if(l==-1) 
                break;
            step+=1;

            if(r==1){
                if(!clear[l].second)
                    rating += 1;
                clear[l].first=true;
            }else{
                rating += 2;
                clear[l].second=true;
                if(clear[l].first)
                    rating -= 1;
            }
        }

        if(pass)
            printf("Case #%d: %d\n", tcase, step);
        else
            printf("Case #%d: Too Bad\n", tcase);
    }
    return 0;
}
