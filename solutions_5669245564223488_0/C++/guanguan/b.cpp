#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

using namespace std;

int present[31];
int occ[31];
int occ_s[31];
int occ_e[31];
int s[15];
int e[15];
vector<int> v;
int chosen[15];
int n;
int all_taken[31];

int dfs(int last,int num)
{
    //printf("DFS %d,%d\n",last,num);
    if (num==n)
    {
       /*for (int i=0; i<n; i++)
       {
           printf("%d ",chosen[i]);
       }
       printf("\n");
       printf("Yay!\n");*/
       return 1;
    }
    int ans=0;
    for (int i=0; i<n; i++)
    {
        if (!chosen[i])
        {
           //Try this
           chosen[i]=num+1;
           //See if possible
           if (last!=-1)
           {
              if (e[last]==s[i]) //This starts from previous end
              {
                 //legit
                 all_taken[s[i]]-=1;
                  all_taken[e[i]]-=1;
                  ans+=dfs(i,num+1);
                  all_taken[s[i]]+=1;
                  all_taken[e[i]]+=1;
              }
              else if (occ_s[e[last]]==0 && occ_e[s[i]]==0 && all_taken[e[last]]==0) //Previous end doesn't connect, new one doesn't connect with another end
              {
                   all_taken[s[i]]-=1;
                  all_taken[e[i]]-=1;
                  ans+=dfs(i,num+1);
                  all_taken[s[i]]+=1;
                  all_taken[e[i]]+=1;
              }
              else
              {
                  //printf("NOT LEGIT\n");
              }
           }
           else
           {
               //Start if nothing else ends with this
               if (s[i]==e[i] && occ_e[s[i]]==0)
               {
                  all_taken[s[i]]-=1;
                  all_taken[e[i]]-=1;
                  ans+=dfs(i,num+1);
                  all_taken[s[i]]+=1;
                  all_taken[e[i]]+=1;
               }
               else if (s[i]!=e[i] && occ_e[s[i]]==0 && all_taken[s[i]]==1)
               {
                    all_taken[s[i]]-=1;
                  all_taken[e[i]]-=1;
                  ans+=dfs(i,num+1);
                  all_taken[s[i]]+=1;
                  all_taken[e[i]]+=1;
               }
               
           }
           //Clean up
           chosen[i]=0;
        }
    }
    //printf("ans:%d\n",ans);
    return ans;
}


int main()
{
    freopen("b.txt","r",stdin);
    freopen("b_out.txt","w",stdout);
    int tc;
    scanf("%d",&tc);
    for (int a=0; a<tc; a++)
    {
        scanf("%d",&n);
        for (int j=0; j<31; j++)
        {
            occ[j]=0;
            occ_s[j]=0;
            occ_e[j]=0;
            present[j]=0;
            all_taken[j]=0;
        }
        bool su=true;
        for (int i=0; i<n; i++)
        {
            v.clear();
            string tmp;
            cin >> tmp;
            if (!su)
            {
               continue;
            }
            //cout << "tmp: " << tmp << endl;
            char c=tmp[0];
            for (int j=1; j<tmp.length(); j++)
            {
                if (c!=tmp[j])
                {
                   v.push_back(c-'a');
                   c=tmp[j];
                }
            }
            v.push_back(c-'a');
            s[i]=v[0];
            for (int j=1; j<v.size()-1; j++)
            {
                occ[v[j]]+=1;
                //printf("m: %c\n",'a'+v[j]);
                if (occ_s[v[j]]>=1 || occ_e[v[j]]>=1)
                {
                   su=false;
                  // printf("fail 1\n");
                }
            }
            e[i]=v[v.size()-1];
            //printf("s:%c,e:%c\n",s[i]+'a',e[i]+'a');
            if (s[i]!=e[i])
            {
               //Add to occurences
               occ[s[i]]+=1;
               occ[e[i]]+=1;
               occ_s[s[i]]+=1;
               occ_e[e[i]]+=1;
               if (occ_s[s[i]]>=2 || occ_e[e[i]]>=2)
               {
                  su=false;
                  //printf("fail 2\n");
               }
            }
            else
           {
                //printf("s[i]:%d\n",s[i]);
               present[s[i]]+=1;
           }
           all_taken[s[i]]+=1;
           all_taken[e[i]]+=1;
        }
        if (!su)
        {
           //Not possible to attach
           //printf("Cannot attach\n");
           printf("Case #%d: 0\n",a+1);
        }
        else
        {
             //Do DFS
             printf("Case #%d: %d\n",a+1,dfs(-1,0));
        }
    }
}
