#include<iostream>
#include<stack>

#define N 1001
using namespace std;

int matrix[N][N];
int visited[N+1];
bool loop = false;
void dfs(int v, int n)
{
    //cout<<"v="<<v<<endl;
   /* stack<int> q;
    q.push(v);
    int temp;
    while(!q.empty())
    {
        temp = q.top();
        //cout<<temp <<" ";
        if(visited[temp] == 1)
        {
            return true;
        }
        visited[temp] = 1;
        for(int i=1;i<=n;i++)
        {
            if(matrix[temp][i] == 1)
            {
                q.push(i);
            }
        }
        q.pop();
    }
    return false;
    */
    if(visited[v] == 1)
    loop = true;

    visited[v] = 1;
    for(int i=1;i<=n;i++)
    {
        if(matrix[v][i] == 1)
        dfs(i,n);
    }


}
int main()
{
    int t,n;
    int k;
    int l;
    //bool loop =false;

    //queue<int> q;
    //int total_visited = 0;
    cin>>t;
    for(int i=1;i<=t;i++)
    {
       // total_visited = 0;
        cin>>n;
        //matrix = new int [n+1][n+1];
        //visited = new int[n+1];
        for(int row=1;row<=n;row++)
        {
            for(int col=1;col<=n;col++)
                matrix[row][col] = 0;
        }
        //prepare matrix
        for(int j=1;j<=n;j++)
        {
            cin>>k;
            while(k--)
            {
                cin>>l;
                //cout<<l<<" ";
                matrix[j][l] = 1;
            }
            visited[j] = 0;
        }

        for(int row = 1; row<=n; row++ )
        {
            for(int j=1;j<=n;j++)
            {
                visited[j] = 0;
            }

            dfs(row,n);

            if(loop == true)
            {
                cout<<"Case #"<<i<<": Yes"<<endl;

                break;

            }


        }

        if(!loop)
            {
                cout<<"Case #"<<i<<": No"<<endl;
                //loop = false;
            }
            loop = false;
       // delete[] matrix;
        //delete[] visited;
    }

    return 0;
}
