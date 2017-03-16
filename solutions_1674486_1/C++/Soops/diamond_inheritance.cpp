
#include<iostream>
#include<map>

using namespace std;
void calculate(int node);

int np[1000];
int paths[1000][1000];

map<int,int> mymap;
int moby,parent,found,num;

int main()
{
    int t,tt,i,j,temp;

    freopen("C.in","r",stdin);
	freopen("C.out","w",stdout);

    cin>>t;

    for(tt=1;tt<=t;tt++)
    {
        cin>>num;
        memset (paths,0,sizeof(paths));
        found=0;
        for(i=0;i<num;i++)
        {
            cin>>np[i];
            for(j=0;j<np[i];j++)
            {
                cin>>temp;
                paths[i][temp-1]=1;
            }
        }
        for(i=0;i<num && !found;i++)
        {
            mymap.clear();
            if(np[i]>1)
            {
                for(j=0;j<num &&!found;j++)
                {
                    if(paths[i][j])
                    {
                        parent = j+1;
                        if(mymap[j])
                        {
                            found=1;
                            break;
                        }
                        else
                        {
                            mymap[j]=parent;
                        }
                        calculate(j);
                    }
                }

            }
        }
        if(found) cout<<"Case #"<<tt<<": Yes\n";
        else cout<<"Case #"<<tt<<": No\n";

        }

    return 0;
    }

    void calculate(int node)
    {
        int i,j,k;
        for(j=0;j<num && !found;j++)
        {
            if(paths[node][j])
            {
                if(!mymap[j])
                {
                     mymap[j]=parent;
                     calculate(j);
                }
                else if(mymap[j]!=parent)
                {
                     found=1;
                     return;
                }
            }
        }
    }

