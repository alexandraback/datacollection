#include <fstream>
#include <iostream>
#include <cstring>
#include <string>
using namespace std;

int T, p, i, n, m, a;
int bff[1001];
int per[1001];

ifstream fin("in.in");
ofstream fout("out.out");

int search(int pos, int start, bool seen[])
{
     int posi, j, next_toput;
     per[pos] = start; seen[start] = true; j = pos+1; next_toput = bff[per[pos]];
     while(!seen[next_toput]) // && !checked[next_toput])
     {
         //if(p == 3) cout <<"PUT " <<next_toput <<"INTO circle " <<endl;
         per[j] = next_toput;
         seen[next_toput] = true;
         next_toput = bff[per[j]];
         j++; 
     }
     //if(checked[next_toput]) continue;
     j--;
     //cout <<"TMP LEN " <<j <<endl <<per[j-1] <<' ' <<per[j] <<endl;
     if(per[j-1]==bff[per[j]]) 
     {
         bool tmp[1001];
         int result = j+1;
         for(posi = 1; posi <= n; posi++)
             if(!seen[posi]) 
             {
                 memcpy(tmp, seen, sizeof(seen));
                 result = max(result, search(j+1, posi, tmp));
             } 
         return result;
     }
     else if(per[0]==bff[per[j]]) return j+1;
          else return 0;
    
}

int main()
{   
    fin >>T;
    for(p = 1; p <= T; p++)
    {
        //bool checked[1001]  = {0};
        m = 0;
        fin >>n;
        for(i = 1; i <= n; i++) fin >>bff[i];
        for(i = 1; i <= n; i++)
        {
            bool seen[1001] = {0};
            memset(seen, 0, sizeof(seen));
            //if(p == 4) cout <<"start " <<i <<endl;
            //if(p == 4) 
              //for(a = 0; a < cur; a++) cout <<per[a] <<' ';
            //if(p == 4)
              //cout <<endl;
            m = max(m, search(0, i, seen));
            /*per[0] = i; seen[i] = true; j = 1; next_toput = bff[per[0]];
            while(!seen[next_toput]) // && !checked[next_toput])
            {
                //if(p == 3) cout <<"PUT " <<next_toput <<"INTO circle " <<endl;
                per[j] = next_toput;
                seen[next_toput] = true;
                next_toput = bff[per[j]];
                j++; 
            }
            //if(checked[next_toput]) continue;
            j--;
            //cout <<"TMP LEN " <<j <<endl <<per[j-1] <<' ' <<per[j] <<endl;
            if(per[j-1]!=bff[per[j]] && per[0]!=bff[per[j]]) j = 0;
            else j++;
            if(p == 2) cout <<"FINISH WITH LEN " <<j <<endl;
            cout <<endl; 
            m = max(m, j);
            //checked[i] = true;*/
        } 
        fout <<"Case #" <<p <<": " <<m <<endl;
    }
    //cin >>a;
    return 0;
} 
