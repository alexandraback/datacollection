#include <vector>
#include <string>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <fstream>
#include <algorithm>
#include <sstream>
#include <map>
#include <ctime>
#include <cassert>

using namespace std;

ofstream fout("../../../output.txt");
ifstream fin("../../../input.txt");


bool isadj[50][50];

int state[50];
int n;

//0 unused, 1 in stack, 2 dead, 3 temporarily dead


bool seen[50];
int numseen = 0;

int dfs(int x)
{
    if(seen[x] || state[x]>=2)
        return 0;
    seen[x]=true;
    int ret = 1;
    
    for(int  i=0; i<n; i++)
    {
        if(isadj[x][i] && !seen[i] && state[i]<=2)
        {
            ret+=dfs(i);
        }
    }
    return ret;
}

bool testok(int root)
{
    memset(seen,0,sizeof(seen));
    
    int val = dfs(root);
    for(int i=0; i<n; i++)
    {
        if(state[i]<=1)
            val--;
    }
    if(val<0)
        return false;
    return true;
}


int main(void)
{
	int ttt;
	fin >> ttt;
	int ct = 0;
	string s;
	
	cout.precision(9);
	fout.precision(9);
    
    cout << "HELLO" <<  " " << ttt << endl;
    
    
	
	while(ttt>0)
	{
		ct++;
		ttt--;
        
		double c,f,x;

        
        int m;
        
        string ret;
        
        vector<string> lis;
        
        int i,j,k;
        
        fin >> n >> m;
        
        for(i=0; i<n; i++)
        {
            string s;
            fin >> s;
            lis.push_back(s);
        }

        
        
        memset(isadj,0,sizeof(isadj));
        
        for(i=0; i<m; i++)
        {
            fin >> j >> k;
            j--;
            k--;
            isadj[j][k]=isadj[k][j]=true;
        }
        
        memset(state,0,sizeof(state));
        
        int best = 0;
        string bv = lis[0];
        
        for(i=1; i<n; i++)
        {
            if(lis[i] < bv)
            {
                bv=lis[i];
                best=i;
            }
        }
        
        vector<int> stack;
        stack.push_back(best);
        state[best]=1;
        
        ret+=bv;
        
        int done = 1;
        
        while(done < n)
        {
            best = -1;
            
            int maxok = stack.size()-1;
            
            while(maxok > 0)
            {
                state[stack[maxok]]=3;
                
//                for(i=0; i<n; i++)
//                {
//                    cout << state[i] << " ";
//                }
//                cout << endl;
                
                if(testok(stack[0]))
                {
                    maxok--;
                }
                else
                {
                    break;
                }
            }
            for(i=0; i<n; i++)
            {
                if(state[i]==3)
                    state[i]=1;
            }
            
//            for(i=0; i<stack.size(); i++)
//            {
//                cout << stack[i]+1 << " ";
//            }
//            cout << " MAX " << maxok << endl;
            
            
            for(i=0; i<n; i++)
            {
                if(state[i]!=0)
                    continue;
                
                if(best!=-1 && lis[best]<lis[i])
                    continue;
                
                for(j=stack.size()-1; j>=maxok; j--)
                {
                    if(!isadj[i][stack[j]])
                        continue;
                    
                    best=i;
                    break;
                    
                }
                
            }
            
            done++;
            ret+=lis[best];
            k = stack.size()-1;
            while(!isadj[stack[k]][best])
            {
                state[stack[k]]=2;
                stack.pop_back();
                k--;
                
            }
            stack.push_back(best);
            state[best]=1;
            
        }
        
		
		cout << "Case #" << ct << ": ";
		fout << "Case #" << ct << ": ";
		
        
        cout << ret;
        fout << ret;
        
        
		
		
		
		fout << endl;
		cout << endl;
		
	}
	
	
	return 0;
}

