#include<iostream>
#include<fstream>
#include<algorithm>
#include<queue>
using namespace std;

struct level{
    int stars;
    int diff;
    int num;
};

struct alevel{
    int stars;
    int diff;
    int num;
};

bool operator<(level a, level b){
    if (a.stars!= b.stars) return a.stars < b.stars;
    return a.diff < b.diff;
}

bool operator<(alevel a, alevel b){
    return a.diff > b.diff;
}



int main(){
    ifstream in("R2.in"); ofstream out("R2.out");
    int T;
    in>>T;
    for (int t=0;t<T;t++){
        int N;
        in>>N;
        priority_queue<level> cansolve;
        priority_queue<alevel> toohard;
        int skill=0;
        int done = 0;
        int second[N];
        for (int i=0;i<N;i++){
            alevel tmp;
            tmp.num = i;
            tmp.stars = 1;
            in>>tmp.diff;
            toohard.push(tmp);
            tmp.stars = 2;
            in>>second[i];
            tmp.diff = second[i];
            toohard.push(tmp);
        }
        bool solved1[N], solved2[N], full[N],r[N];
        for (int i=0;i<N;i++) solved1[i]=solved2[i]=full[i]=r[i]= false;
        int numsolved = 0;
        while(!toohard.empty() && toohard.top().diff<=skill){
            alevel tmp = toohard.top();
            toohard.pop();
            if (tmp.stars == 1){
                level blah;
                blah.stars = 1;
                blah.diff = second[tmp.num];
                blah.num = tmp.num;
                cansolve.push(blah);
            }
            else{
                level blah;
                blah.stars = 2;
                blah.diff = tmp.diff;
                blah.num = tmp.num;
                cansolve.push(blah);
                solved1[tmp.num]=true;
            }
        }
        while(!cansolve.empty()){
            level tmp = cansolve.top();
            cansolve.pop();
            if (tmp.stars == 1){
                if (!solved1[tmp.num]){
                    skill ++;
                    solved2[tmp.num]=true;
                    done++;
                }
            }
            else{
                skill += 2-solved2[tmp.num];
                done++;
                numsolved++;
            }
            while(!toohard.empty() && toohard.top().diff<=skill){
                alevel tmp = toohard.top();
                toohard.pop();
                if (tmp.stars == 1){
                    level blah;
                    blah.stars = 1;
                    blah.diff = second[tmp.num];
                    blah.num = tmp.num;
                    cansolve.push(blah);
                }
                else{
                    level blah;
                    blah.stars = 2;
                    blah.diff = tmp.diff;
                    blah.num = tmp.num;
                    cansolve.push(blah);
                    solved1[tmp.num]=true;
                }
            }
        }
        if (numsolved==N){
            out<<"Case #"<<t+1<<": "<<done<<"\n";
        }
        else{
            out<<"Case #"<<t+1<<": Too Bad\n";
        }
    }

}
