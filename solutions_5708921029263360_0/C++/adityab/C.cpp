#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //Solve
    int T, J, P, S, K;
    cin >> T;
    for(int i=0; i<T; i++)
    {
        //Solve
        cin >> J >> P >> S >> K;
        int num = 0;
        if(K>=S)
        {
            num = J*P*S;
            cout << "Case #" << i+1 << ": " << num << endl;
            for(int j=0; j<J; j++)
            {
                for(int p=0; p<P; p++)
                {
                    for(int s=0; s<S; s++)
                    {
                        cout << j+1 << " " << p+1 << " " << s+1 << endl;
                    }
                }
            }

        }

        else if(K == S-1)
        {
            num = J*K + J*(P-1)*(S-2);
            cout << "Case #" << i+1 << ": " << num << endl;

            int done = 0;
            for(int j=0; j<J; j++)
            {
                for(int p=0; p<P; p++)
                {
                    for(int s=0; s<S; s++)
                    {
                        if(s!=j && s!=p && done < num)
                        {
                            cout << j+1 << " " << p+1 << " " <<  s+1 << endl;
                            done++;
                        }
                    }
                }
            }
        }

        else
        {
            num = J*K + J*(P-1)*K;
            cout << "Case #" << i+1 << ": " << num << endl;

            int done = 0;
            for(int j=0; j<J; j++)
            {
                for(int p=0; p<P; p++)
                {
                    for(int s=0; s<S; s++)
                    {
                        if(s!=j && s!=p && done < num)
                        {
                            cout << j+1 << " " << p+1 << " " <<  s+1 << endl;
                            done++;
                        }
                    }
                }
            }

        }
   }
}

