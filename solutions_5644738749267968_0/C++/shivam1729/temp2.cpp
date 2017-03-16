#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define si(x) scanf("%d",&x)
#define pi(x) printf("%d\n",x)
#define sll(x) scanf("%I64d",&x)
#define pll(x) printf("%I64d\n",x)
#define sc(x) scanf("%c",&x)
#define pc(x) printf("%c",x)
#define sf(x) scanf("%f",&x)
#define pf(x) printf("%f",x)
#define sd(x) scanf("%lf",&x)
#define pd(x) printf("%lf",x)
#define sld(x) scanf("%Lf",&x)
#define pld(x) printf("%Lf",x)
#define clr(a) memset(a,0,sizeof(a))
#define MOD 1000000009
using namespace std;
set<double> A;
set<double> B;
int main(void){
    std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int xx=0;
	while(t--){
        A.clear();
        B.clear();
        int ans1=0,ans2=0;
        int n;
        cin>>n;
        double a[n],b[n];
        for(int i=0;i<n;i++){
            cin>>a[i];
            A.insert(a[i]);
        }
        for(int i=0;i<n;i++){
            cin>>b[i];
            B.insert(b[i]);
        }
        //both play war
        set<double>::iterator it,it2,mm;
        for(it=A.begin();it!=A.end();it++){
            double num1=*it;
            it2=B.upper_bound(num1);
            if(it2==B.end()){
                ans2++;
                it2=B.upper_bound(0.0);
                B.erase(it2);
            }
            else{
                B.erase(it2);
            }
        }
        //deceitful war
        set<double>::reverse_iterator it3;
        B.clear();
        for(int i=0;i<n;i++){
            B.insert(b[i]);
        }
        for(int i=n;i>0;i--){
            it=A.begin();
            it2=B.begin();
            //cout<<*it<<" "<<*it2<<endl;
            if(*it<*it2){
                //cout<<"erasing:"<<*it<<endl;
                A.erase(it);
                it3=B.rbegin();
                it=B.lower_bound(*it3);
                //cout<<"erasing:"<<*it<<endl;
                B.erase(it);
            }
            else{
                ans1++;
//                for(it2=B.begin();*it2<*it;it2++);
//                it2--;
                A.erase(it);
                B.erase(it2);
            }
        }
        xx++;
        printf("Case #%d: %d %d\n",xx,ans1,ans2);
        //cout<<ans1<<" "<<ans2<<endl;
	}
	return 0;
}
