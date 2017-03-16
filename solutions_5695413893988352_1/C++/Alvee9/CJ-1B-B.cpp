#include <bits/stdc++.h>

using namespace std;

int main(){
     freopen("B-small-attempt0.in","r",stdin); freopen("00_output.txt","w",stdout);
    int t;
    cin>>t;
    for(int tc=1;tc<=t;tc++){
        string cod,jam;
        cin>>cod>>jam;
        string s;
        int len=cod.length();
        if (len==1){
            cod="00"+cod;
            jam="00"+jam;
        }
        else if (len==2){
            cod="0"+cod;
            jam="0"+jam;
        }
        int dif=10000;
        int cleast=1000, jleast=1000;
        vector<int> cvals,jvals;
        int istart=0,iend=9;
        s=cod;
        if (s[0]!='?'){
            istart=s[0]-'0'; iend=s[0]-'0';
        }
        for(int i=istart;i<=iend;i++){
            int jstart=0, jend=9;

            if (s[1]!='?'){
                jstart=s[1]-'0'; jend=s[1]-'0';
            }
            for(int j=jstart;j<=jend;j++){
                int kstart=0, kend=9;

                if (s[2]!='?'){
                    kstart=s[2]-'0'; kend=s[2]-'0';
                }
                for(int k=kstart; k<=kend;k++){

                    int ctmp=k+j*10+i*100;

                    cvals.push_back(ctmp);


                }
            }

        }
        s=jam;
        istart=0,iend=9;

        if (s[0]!='?'){
            istart=s[0]-'0'; iend=s[0]-'0';
        }
        for(int i=istart;i<=iend;i++){
            int jstart=0, jend=9;

            if (s[1]!='?'){
                jstart=s[1]-'0'; jend=s[1]-'0';
            }
            for(int j=jstart;j<=jend;j++){
                int kstart=0, kend=9;

                if (s[2]!='?'){
                    kstart=s[2]-'0'; kend=s[2]-'0';
                }
                for(int k=kstart; k<=kend;k++){

                    int jtmp=k+j*10+i*100;

                    jvals.push_back(jtmp);


                }
            }

        }


        for(int i=0;i<cvals.size();i++){
            for(int j=0;j<jvals.size();j++){
                int tmpdif=abs(cvals[i]-jvals[j]);
                if (tmpdif<dif){
                    cleast=cvals[i]; jleast=jvals[j];
                    dif=tmpdif;
                }
                else if (tmpdif==dif){
                    if (cvals[i]+jvals[j]<cleast+jleast){
                          cleast=cvals[i]; jleast=jvals[j];
                          dif=tmpdif;
                    }
                    else if (cvals[i]+jvals[j]==cleast+jleast){
                        if (cvals[i]<cleast){
                              cleast=cvals[i]; jleast=jvals[j];
                              dif=tmpdif;
                        }
                    }
                }
            }
        }

        int cdigits=log10(cleast)+1;
        if (cleast==0)
            cdigits=1;
        int jdigits=log10(jleast)+1;
        if (jleast==0)
            jdigits=1;


        cout<<"Case #"<<tc<<": ";

        for(int i=0;i<len-cdigits;i++){
            cout<<0;
        }

        cout<<cleast<<" ";

        for(int i=0;i<len-jdigits;i++){
            cout<<0;
        }


        cout<<jleast<<endl;


    }
}
