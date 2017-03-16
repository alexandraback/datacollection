#include <iostream>

using namespace std;

int main()
{
    int t,r,c,m;
    int avaBlock;
    char moc[60][60];
    cin>>t;

    for (int ii = 0; ii < t; ++ii)
    {
        cout<<"Case #"<<ii + 1<<":"<<endl;
        cin>>c>>r>>m;
        avaBlock = r * c - m;

        if (avaBlock == 1) {
            cout<<'c';
            for (int i = 0; i < r-1; ++i)
            {
                cout<<"*";
            }
            cout<<endl;
            for (int i = 0; i < c-1; ++i)
            {
                for (int j = 0; j < r; ++j)
                {
                    cout<<"*";
                }
                cout<<endl;
            }
            continue;
        }
        if (avaBlock < 1) {cout<<"Impossible"<<endl;continue;}

        if (c == 1){
            cout<<"c";
            for (int i = 0; i < avaBlock - 1; ++i) cout<<".";
            for (int i = 0; i < m; ++i) cout<<"*";
            cout<<endl;
            continue;
        }

        if (r == 1){
            cout<<"c"<<endl;
            for (int i = 0; i < avaBlock - 1; ++i) cout<<"."<<endl;
            for (int i = 0; i < m; ++i) cout<<"*"<<endl;
            continue;
        }

        if (avaBlock < 4) {cout<<"Impossible"<<endl;continue;}

        if (c == 2){
            if (avaBlock % 2 == 1) {cout<<"Impossible"<<endl;continue;}
            cout<<"c";
            for (int i = 0; i < avaBlock/2 - 1; ++i) cout<<".";
            for (int i = 0; i < m/2; ++i) cout<<"*";
            cout<<endl;
            for (int i = 0; i < avaBlock/2; ++i) cout<<".";
            for (int i = 0; i < m/2; ++i) cout<<"*";
            cout<<endl;
            continue;
        }

        if (r == 2){
            if (avaBlock % 2 == 1) {cout<<"Impossible"<<endl;continue;}
            cout<<"c."<<endl;
            for (int i = 0; i < avaBlock/2 - 1; ++i) cout<<".."<<endl;
            for (int i = 0; i < m/2; ++i) cout<<"**"<<endl;
            continue;
        }

        if (avaBlock == 5 || avaBlock == 7) {cout<<"Impossible"<<endl;continue;}

        for (int i = 0; i < c; ++i)
            for (int j = 0; j < r; ++j)
                moc[i][j] = '*';

        if (avaBlock >= 2 * (r + c) - 4)
        {
            int temp = avaBlock - (2 * (r + c) - 4);
            int tempC = 3;
            for (int i = 0; i < r; ++i)
            {
                moc[0][i] = '.';
                moc[1][i] = '.';
            }
            for (int i = 0; i < c; ++i){
                moc[i][0] = '.';
                moc[i][1] = '.';
            }
            for (int i = 0; i < temp; ++i)
            {
                moc[(i / (r - 2)) + 2][(i % (r - 2)) + 2] = '.';
            }
            moc[0][0] = 'c';
        }else{
            if (avaBlock % 2 == 0)
            {
                if (avaBlock <= r * 2)
                {
                    for (int i = 0; i < avaBlock / 2; ++i)
                    {
                        moc[0][i] = '.';
                        moc[1][i] = '.';
                    }
                    moc[0][0] = 'c';
                }else{
                    for (int i = 0; i < r; ++i)
                    {
                        moc[0][i] = '.';
                        moc[1][i] = '.';
                    }
                    for (int i = 0; i < (avaBlock - 2 * r) / 2; ++i)
                    {
                        moc[i + 2][0] = '.';
                        moc[i + 2][1] = '.';
                    }
                    moc[0][0] = 'c';
                }
            }else{
                if (avaBlock - 3 <= r * 2){
                    for (int i = 0; i < (avaBlock - 3) / 2; ++i)
                    {
                        moc[0][i] = '.';
                        moc[1][i] = '.';
                    }
                    moc[0][0] = 'c';
                    moc[2][0] = '.';
                    moc[2][1] = '.';
                    moc[2][2] = '.';
                }else{
                    for (int i = 0; i < r; ++i)
                    {
                        moc[0][i] = '.';
                        moc[1][i] = '.';
                    }
                    for (int i = 0; i < (avaBlock - 2 * r - 1) / 2; ++i)
                    {
                        moc[i+2][0] = '.';
                        moc[i+2][1] = '.';
                    }
                    moc[0][0] = 'c';
                    moc[2][2] = '.';
                }
            }
        }
        for (int i = 0; i < c; ++i){
            for (int j = 0; j < r; ++j)
            {
                cout<<moc[i][j];
            }
            cout<<endl;
        }
    }
    return 0;
}
