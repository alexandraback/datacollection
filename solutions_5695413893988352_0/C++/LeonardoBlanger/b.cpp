#include <cstdio>
#include <vector>
#include <string>
#include <cstdlib>

using namespace std;

#define INF (1 << 30)

char C[20], J[20];
vector<string> vc, vj;

void bkt(int pos, char sc[], vector<string> &v){
    if(sc[pos] == '\0'){
        v.push_back(sc);
        return;
    }
    
    if(sc[pos] == '?'){
        for(char d='0'; d<='9'; d++){
            sc[pos] = d;
            bkt(pos+1, sc, v);
        }
        
        sc[pos] = '?';
        return;
    }
    
    bkt(pos+1, sc, v);
}

long long abs(long long num){
    if(num < 0) num *= -1;
    return num;
}

int main(){
    int T, tc = 0;
    scanf("%d", &T);
    
    while(T--){
        scanf("%s%s", C, J);
        
        vc.clear();
        vj.clear();
        bkt(0, C, vc);
        bkt(0, J, vj);
        
        string c = "99999999", j = "0";
        
        for(int i=0; i<vc.size(); i++){
            for(int k=0; k<vj.size(); k++){
                if(abs(atoi(vc[i].c_str())-atoi(vj[k].c_str())) < abs(atoi(c.c_str())-atoi(j.c_str()))){
                    c = vc[i];
                    j = vj[k];
                    
                } else if(abs(atoi(vc[i].c_str())-atoi(vj[k].c_str())) == abs(atoi(c.c_str())-atoi(j.c_str()))){
                    if(atoi(vc[i].c_str()) < atoi(c.c_str())){
                        c = vc[i];
                        j = vj[k];
                    } else if(atoi(vc[i].c_str()) == atoi(c.c_str()) and atoi(vj[k].c_str()) < atoi(j.c_str())){
                        c = vc[i];
                        j = vj[k];
                    }
                }
            }
        }
        
        printf("Case #%d: %s %s\n", ++tc, c.c_str(), j.c_str());
    }
}
