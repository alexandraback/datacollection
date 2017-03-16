#include<bits/stdc++.h>

using namespace std;

int main() {

    freopen("C:\\Users\\Saurabh\\Desktop\\in.txt","r",stdin);
    freopen("C:\\Users\\Saurabh\\Desktop\\out.txt","w",stdout);

    int t,cas=1;
    cin>>t;
    srand(time(NULL));
    while(t--) {
        int j,p,s,k,x,y,z,days=0,c=0;
        map <string,int> m;
        set <string> s1;
        vector <int> v1,v2,v3;
        cin>>j>>p>>s>>k;
        while(c<100000) {
            x=rand()%j;
            y=rand()%p;
            z=rand()%s;
            string temp4="J";
            temp4+=char(x+'0');
            temp4+="P";
            temp4+=char(y+'0');
            temp4+="S";
            temp4+=char(z+'0');
            if(s1.find(temp4)!=s1.end()) {
                c++;
                continue;
            }
            string temp1="J";
            temp1+=char(x+'0');
            temp1+="P";
            temp1+=char(y+'0');
            string temp2="J";
            temp2+=char(x+'0');
            temp2+="S";
            temp2+=char(z+'0');
            string temp3="P";
            temp3+=char(y+'0');
            temp3+="S";
            temp3+=char(z+'0');

            m[temp1]++,m[temp2]++,m[temp3]++;
            if(m[temp1]<=k && m[temp2]<=k && m[temp3]<=k) {
                v1.push_back(x+1),v2.push_back(y+1),v3.push_back(z+1);
                days++;
                c=0;
                s1.insert(temp4);
            }
            else
                m[temp1]--,m[temp2]--,m[temp3]--,c++;
        }
        cout<<"Case #"<<cas++<<": "<<days<<endl;
        for(int i=0;i<days;i++)
            cout<<v1[i]<<" "<<v2[i]<<" "<<v3[i]<<endl;
    }

    return 0;
}

