#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
  int t;
  cin >> t;

  for(int ti=1;ti<=t;++ti)
  {
      int n,m;
      cin >> n >> m;
      int A[n];
      double a[n];
      for(int i=0;i<n;++i)
        cin >> a[i] >> A[i];

      int B[m];
      double b[m];
      for (int j=0;j<m;++j)
        cin >> b[j] >> B[j];

      double R[n+1];
      double *Q=R;
      for(int i=0;i<=n;++i)
        Q[i]=0;
      ++Q;

      for(int j=0;j<m;++j)
      {
        for(int i=0;i<n;++i)
        {
          Q[i]=max(Q[i],Q[i-1]);

          if(A[i]==B[j])
          {
            double off=min(a[i],b[j]);
            a[i]-=off;
            b[j]-=off;
            Q[i]+=off;
          }
        }
      }
      cout << "Case #"<<ti<<": "<< setprecision(50) << Q[n-1] << endl;
  }
}

    


