#include <iostream>
#include <vector>
#include <map>
#include <set>

using namespace std;



int main()
{
    std::ios::sync_with_stdio(false);
    int t,T;
    cin >> T;
    for (t=0; t<T; t++)
    {
        int J,P,S,K;
        cin>>J>>P>>S>>K;
        
        map<pair<int,int>,int > msp={},msj={},mpj={};
        set<vector<int> > svi={};
        while (true) {
            int i,j,k;
            bool update = false;
            for (i=1; i<=S; i++) {
                for (j=1; j<=P; j++) {
                    for (k=1; k<=J; k++) {
                        vector<int> vi(3);
                        vi[0]=k;
                        vi[1]=j;
                        vi[2]=i;
                        if (svi.count(vi)!=0) {
                            continue;
                        }
                        auto sp = make_pair(i,j);
                        auto sj = make_pair(i,k);
                        auto pj = make_pair(j,k);
                        if (msp.count(sp)!=0) {
                            if (msp[sp] >= K) {
                                continue;
                            }
                        }
                        if (msj.count(sj)!=0) {
                            if (msj[sj] >= K) {
                                continue;
                            }
                        }
                        
                        if (mpj.count(pj)!=0) {
                            //cout<<"::"<<mpj[pj]<<endl;
                            if (mpj[pj] >= K) {
                                continue;
                            }
                        }
                        update = true;
                        svi.insert(vi);
                        if (msp.count(sp)==0) {
                            msp[sp] = 0;
                        }
                        if (msj.count(sj)==0) {
                            msj[sj] = 0;
                        }
                        if (mpj.count(pj)==0) {
                            mpj[pj] = 0;
                        }
                        msp[sp]++;
                        msj[sj]++;
                        mpj[pj]++;
                        
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        int ans = svi.size();
        
        map<pair<int,int>,int > msp1={},msj1={},mpj1={};
        set<vector<int> > svi1={};
        while (true) {
            int i,j,k;
            bool update = false;
            for (j=1; j<=P; j++) {
                for (i=1; i<=S; i++){
                    for (k=1; k<=J; k++) {
                        vector<int> vi(3);
                        vi[0]=k;
                        vi[1]=j;
                        vi[2]=i;
                        if (svi1.count(vi)!=0) {
                            continue;
                        }
                        auto sp = make_pair(i,j);
                        auto sj = make_pair(i,k);
                        auto pj = make_pair(j,k);
                        if (msp1.count(sp)!=0) {
                            if (msp1[sp] >= K) {
                                continue;
                            }
                        }
                        if (msj1.count(sj)!=0) {
                            if (msj1[sj] >= K) {
                                continue;
                            }
                        }
                        
                        if (mpj1.count(pj)!=0) {
                            //cout<<"::"<<mpj1[pj]<<endl;
                            if (mpj1[pj] >= K) {
                                continue;
                            }
                        }
                        update = true;
                        svi1.insert(vi);
                        if (msp1.count(sp)==0) {
                            msp1[sp] = 0;
                        }
                        if (msj1.count(sj)==0) {
                            msj1[sj] = 0;
                        }
                        if (mpj1.count(pj)==0) {
                            mpj1[pj] = 0;
                        }
                        msp1[sp]++;
                        msj1[sj]++;
                        mpj1[pj]++;
                        
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        int ans1 = svi1.size();
        
        
        map<pair<int,int>,int > msp2={},msj2={},mpj2={};
        set<vector<int> > svi2={};
        while (true) {
            int i,j,k;
            bool update = false;
            for (i=1; i<=S; i++) {
                for (k=1; k<=J; k++) {
                    for (j=1; j<=P; j++) {
                        vector<int> vi(3);
                        vi[0]=k;
                        vi[1]=j;
                        vi[2]=i;
                        if (svi2.count(vi)!=0) {
                            continue;
                        }
                        auto sp = make_pair(i,j);
                        auto sj = make_pair(i,k);
                        auto pj = make_pair(j,k);
                        if (msp2.count(sp)!=0) {
                            if (msp2[sp] >= K) {
                                continue;
                            }
                        }
                        if (msj2.count(sj)!=0) {
                            if (msj2[sj] >= K) {
                                continue;
                            }
                        }
                        
                        if (mpj2.count(pj)!=0) {
                            //cout<<"::"<<mpj2[pj]<<endl;
                            if (mpj2[pj] >= K) {
                                continue;
                            }
                        }
                        update = true;
                        svi2.insert(vi);
                        if (msp2.count(sp)==0) {
                            msp2[sp] = 0;
                        }
                        if (msj2.count(sj)==0) {
                            msj2[sj] = 0;
                        }
                        if (mpj2.count(pj)==0) {
                            mpj2[pj] = 0;
                        }
                        msp2[sp]++;
                        msj2[sj]++;
                        mpj2[pj]++;
                        
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        int ans2 = svi2.size();
        
        map<pair<int,int>,int > msp3={},msj3={},mpj3={};
        set<vector<int> > svi3={};
        while (true) {
            int i,j,k;
            bool update = false;
            for (k=1; k<=J; k++) {
                for (i=1; i<=S; i++) {
                    for (j=1; j<=P; j++) {
                        vector<int> vi(3);
                        vi[0]=k;
                        vi[1]=j;
                        vi[2]=i;
                        if (svi3.count(vi)!=0) {
                            continue;
                        }
                        auto sp = make_pair(i,j);
                        auto sj = make_pair(i,k);
                        auto pj = make_pair(j,k);
                        if (msp3.count(sp)!=0) {
                            if (msp3[sp] >= K) {
                                continue;
                            }
                        }
                        if (msj3.count(sj)!=0) {
                            if (msj3[sj] >= K) {
                                continue;
                            }
                        }
                        
                        if (mpj3.count(pj)!=0) {
                            //cout<<"::"<<mpj3[pj]<<endl;
                            if (mpj3[pj] >= K) {
                                continue;
                            }
                        }
                        update = true;
                        svi3.insert(vi);
                        if (msp3.count(sp)==0) {
                            msp3[sp] = 0;
                        }
                        if (msj3.count(sj)==0) {
                            msj3[sj] = 0;
                        }
                        if (mpj3.count(pj)==0) {
                            mpj3[pj] = 0;
                        }
                        msp3[sp]++;
                        msj3[sj]++;
                        mpj3[pj]++;
                        
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        int ans3 = svi3.size();
        
        map<pair<int,int>,int > msp4={},msj4={},mpj4={};
        set<vector<int> > svi4={};
        while (true) {
            int i,j,k;
            bool update = false;
            for (k=1; k<=J; k++) {
                for (j=1; j<=P; j++) {
                    for (i=1; i<=S; i++) {
                        vector<int> vi(3);
                        vi[0]=k;
                        vi[1]=j;
                        vi[2]=i;
                        if (svi4.count(vi)!=0) {
                            continue;
                        }
                        auto sp = make_pair(i,j);
                        auto sj = make_pair(i,k);
                        auto pj = make_pair(j,k);
                        if (msp4.count(sp)!=0) {
                            if (msp4[sp] >= K) {
                                continue;
                            }
                        }
                        if (msj4.count(sj)!=0) {
                            if (msj4[sj] >= K) {
                                continue;
                            }
                        }
                        
                        if (mpj4.count(pj)!=0) {
                            //cout<<"::"<<mpj4[pj]<<endl;
                            if (mpj4[pj] >= K) {
                                continue;
                            }
                        }
                        update = true;
                        svi4.insert(vi);
                        if (msp4.count(sp)==0) {
                            msp4[sp] = 0;
                        }
                        if (msj4.count(sj)==0) {
                            msj4[sj] = 0;
                        }
                        if (mpj4.count(pj)==0) {
                            mpj4[pj] = 0;
                        }
                        msp4[sp]++;
                        msj4[sj]++;
                        mpj4[pj]++;
                        
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        int ans4 = svi4.size();
        
        map<pair<int,int>,int > msp5={},msj5={},mpj5={};
        set<vector<int> > svi5={};
        while (true) {
            int i,j,k;
            bool update = false;
            for (k=1; k<=J; k++) {
                for (j=1; j<=P; j++) {
                    for (i=1; i<=S; i++) {
                        vector<int> vi(3);
                        vi[0]=k;
                        vi[1]=j;
                        vi[2]=i;
                        if (svi5.count(vi)!=0) {
                            continue;
                        }
                        auto sp = make_pair(i,j);
                        auto sj = make_pair(i,k);
                        auto pj = make_pair(j,k);
                        if (msp5.count(sp)!=0) {
                            if (msp5[sp] >= K) {
                                continue;
                            }
                        }
                        if (msj5.count(sj)!=0) {
                            if (msj5[sj] >= K) {
                                continue;
                            }
                        }
                        
                        if (mpj4.count(pj)!=0) {
                            //cout<<"::"<<mpj4[pj]<<endl;
                            if (mpj4[pj] >= K) {
                                continue;
                            }
                        }
                        update = true;
                        svi5.insert(vi);
                        if (msp5.count(sp)==0) {
                            msp5[sp] = 0;
                        }
                        if (msj5.count(sj)==0) {
                            msj5[sj] = 0;
                        }
                        if (mpj4.count(pj)==0) {
                            mpj4[pj] = 0;
                        }
                        msp5[sp]++;
                        msj5[sj]++;
                        mpj4[pj]++;
                        
                    }
                }
            }
            if (!update) {
                break;
            }
        }
        int ans5 = svi5.size();
        
        if (ans1 > ans) {
            ans = ans1;
            svi=svi1;
        }
        if (ans2>ans) {
            ans = ans2;
            svi = svi2;
        }
        if (ans3>ans) {
            ans = ans3;
            svi=svi3;
        }
        if (ans4>ans) {
            ans = ans4;
            svi = svi4;
        }
        if (ans5>ans) {
            ans = ans5;
            svi = svi5;
        }
        
        cout <<"Case #"<<t+1<<": "<<ans  <<endl;
        for (auto vi:svi) {
            cout<<vi[0]<<' '<<vi[1]<<' '<<vi[2]<<endl;
        }
    }
    return 0;
}

