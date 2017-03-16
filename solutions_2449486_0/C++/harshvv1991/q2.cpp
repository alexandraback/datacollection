#include<iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    int N,M;
    int mat[10][10];
    int matCopy[10][10];

    int inp;

for(int cas=1; cas<=t; cas++)
        {
            char hash[2]= {};
            cin>>N>>M;

            int max=-1;

            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                {
                    cin>>inp;
                    mat[i][j] = inp;
                    hash[(inp - 1)] = 1;

                    if(max < inp)
                        max = inp;
                }

            for(int i=0; i<N; i++)
                for(int j=0; j<M; j++)
                {
                    matCopy[i][j] = max;
                }

            int r,c;
            bool flag = true;

            for(int h=(max-1); (h>0)&&(flag); h--)
            {
                if(hash[h-1] == 1)
                {
                    for(int i=0; (i<N)&&(flag); i++)
                        for(int j=0; (j<M)&&(flag); j++)
                        {
                            if((mat[i][j] == h)&&(matCopy[i][j] > h))
                            {
                                for(r=0; r<M; r++)
                                {
                                    if(mat[i][r] > h)
                                        break;
                                }

                                if(r < M)
                                {
                                    for(c=0; c<N; c++)
                                    {
                                        if(mat[c][j] > h)
                                            break;
                                    }

                                    if(c < N)
                                    {
                                        flag = false;
                                        break;
                                    }
                                    else
                                    {
                                        for(c=0; c<N; c++)
                                            matCopy[c][j] = h;
                                    }
                                }
                                else
                                {
                                    for(r=0; r<M; r++)
                                        matCopy[i][r] = h;
                                }
                            }
                        }
                }
            }

            cout<<"Case #"<<cas<<": ";

            if(flag)
                cout<<"YES"<<endl;
            else
                cout<<"NO"<<endl;

        }

    return 0;
}

