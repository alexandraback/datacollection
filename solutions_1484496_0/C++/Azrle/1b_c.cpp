#include<fstream>
using namespace std;
ifstream cin("C-small-attempt1.in");
ofstream cout("C-small-attempt1.out");

    int n=20;
    int t,c;
    int i,j,k,s1,s2;
    int a[20];
    int used[20];
    int sum,cur,goal;
    int s[2][20];
    bool ok;
void find(int ss,int x) {
    int i;
    if (ok) return;
    if (ss == 0) {
        if (s1==0){
            s1=cur;
            cur=0;
            k=1;
            ss = goal;
            x=0;
        } else {
            s2=cur;
            ok = true;
        }
    }
    for (i=x; i<n-1; ++i){
        if (used[i]) continue;
        if (ss-a[i]<0) {
            return;
        }else {
            used[i]=true;
            s[k][cur++] = a[i];
            find(ss-a[i],i+1);
        }
        if (ok) return;
        cur--;
        used[i]=false;
    }
}
int main() {
    cin>>t;
    for (c=0;c<t;++c) {
        cin>>n;
        sum = 0;
        for (i=0;i<n;++i) {
            cin>>a[i];
            sum+=a[i];
        }

        for (i=0;i<n;++i) {
            for (j=i+1;j<n;++j)
            if (a[j]<a[i]) {
                s1= a[i]; a[i]=a[j]; a[j]=s1;
            }
        }

        for (i=0;i<sum;++i) {
            ok = false; k=0; cur=0; s1=0; s2=0; goal = i;
            for (j=0;j<n;++j) used[j] = false;
            find(goal,0);
            if (ok) break;
        }
        cout<<"Case #"<<c+1<<":"<<endl;
        if (ok) {
            cout<<s[0][0];
            for (i=1;i<s1;++i){
                cout<<" "<<s[0][i];
            }

            cout<<endl;
            cout<<s[1][0];
            for (i=1;i<s2;++i){
                cout<<" "<<s[1][i];
            }
            cout<<endl;
        } else {
            cout<<"Impossible"<<endl;
        }
    }
}
