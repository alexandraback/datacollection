#include<iostream>
#include<vector>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<cstdio>
#include<algorithm>

using namespace std;

int T;

int j,p,s;
int k;

int ac[1000][3];

int kjs[10][10];
int kjp[10][10];
int kps[10][10];

int main() {
    freopen("c.in","r",stdin);
    freopen("c.out","w",stdout);

    cin>>T;
    for(int C=0;C<T;C++) {
        cin>>j>>p>>s>>k;
        int ans=0;
        if(k>=3) {
            for(int i=0;i<j;i++) {
                for(int i2=0;i2<p;i2++){
                    for(int i3=0;i3<s;i3++) {
                        ac[ans][0]=i+1;
                        ac[ans][1]=i2+1;
                        ac[ans][2]=i3+1;
                        ans++;
                    }
                }
            }
        } else {
            for(int i=0;i<j;i++) {
                for(int i2=0;i2<s;i2++) kjs[i][i2]=k;
                for(int i2=0;i2<p;i2++) kjp[i][i2]=k;
            }for(int i=0;i<p;i++) {
                for(int i2=0;i2<s;i2++) kps[i][i2]=k;
            }
            for(int i=0;i<j;i++) {
                for(int i2=0;i2<p;i2++){
                    for(int i3=0;i3<s;i3++) {
                        if(kjp[i][i2]>0&&kjs[i][i3]>0&&kps[i2][i3]>0) {
                            ac[ans][0]=i+1;
                            ac[ans][1]=i2+1;
                            ac[ans][2]=i3+1;
                            kjp[i][i2]--;
                            kjs[i][i3]--;
                            kps[i2][i3]--;
                            ans++;
                        }
                    }
                }
            }
        }
        cout<<"Case #"<<C+1<<": "<<ans<<endl;
        for(int i=0;i<ans;i++) {
            cout<<ac[i][0]<<" "<<ac[i][1]<<" "<<ac[i][2]<<endl;
        }

    }
}
