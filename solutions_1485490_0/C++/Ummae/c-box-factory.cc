#include <iostream>
#include <vector>
#include <cstdio>
#include <map>
#include <sstream>
using namespace std;

char buf[1024*1024];
int main()
{
    int T;
    gets(buf);
    sscanf(buf, "%d", &T);
    for(int tcase=1; tcase<=T; ++tcase)
    {
        int n,m;
        gets(buf);
        sscanf(buf,"%d %d", &n, &m);
        vector<pair<long long, long long> > box;
        map<long long, vector<long long> > box_pos;
        gets(buf);
        istringstream is(buf);
        for(int i=0; i < n; ++i){
            long long cnt,type;
            is >> cnt >> type;
            box.push_back( make_pair(type, cnt) );
            box_pos[type].push_back(i);
        }

        gets(buf);
        istringstream is2(buf);
        vector<pair<long long, long long> > toy;
        map<long long, vector<long long> > toy_pos;
        for(int i=0; i < m; ++i){
            long long cnt, type;
            is2 >> cnt >> type;
            toy.push_back( make_pair(type, cnt) );
            toy_pos[type].push_back(i);
        }

        long long ans=0;

        for(int i=0; i < n; ++i){
            long long h=0ll;
            long long remain = box[i].second;
            for(size_t j=0; j < toy_pos[ box[i].first ].size(); ++i){
                long long tmp = min( toy_pos[box[i].first][j], remain );
                h += tmp;
                remain = max(0ll, remain-tmp);
            }
        }

        for(size_t i=0; i < toy_pos[ box[0].first ].size(); ++i){
            long long how=0ll;
            int p1 = toy_pos[ box[0].first ][i];
            for(size_t j=0; j < toy_pos[ box[1].first ].size(); ++j){
                int p2 = toy_pos[ box[1].first ][j];
                for(size_t k=0; k < toy_pos[ box[2].first ].size(); ++k){
                    int p3 = toy_pos[ box[2].first ][k];
                    if( p1<=p2 && p2<=p3){
                        long long h=0ll;
                        map<long long, long long> remain;
                        remain[p1] += toy[p1].second;
                        remain[p2] += toy[p2].second;
                        remain[p3] += toy[p3].second;

                        h += min(remain[p1], box[0].second);
                        remain[p1] = max(remain[p1]-box[0].second, 0ll);

                        h += min(remain[p2], box[1].second);
                        remain[p2] = max(remain[p2]-box[1].second, 0ll);

                        h += min(remain[p3], box[2].second);
                        remain[p3] = max(remain[p3]-box[2].second, 0ll);

                        ans = max(h,ans);
                    }
                }
                if(p1<=p2){
                    long long h=0ll;
                    map<long long, long long> remain;
                    remain[p1] += toy[p1].second;
                    remain[p2] += toy[p2].second;
                    h += min(remain[p1], box[0].second);
                    remain[p1] = max(remain[p1]-box[0].second, 0ll);
                    h += min(remain[p2], box[1].second);
                    remain[p2] = max(remain[p2]-box[1].second, 0ll);
                    ans = max(h,ans);
                }
            }
        }

        for(size_t i=0; i < toy_pos[ box[0].first ].size(); ++i){
            long long how=0ll;
            int p1 = toy_pos[ box[0].first ][i];
            for(size_t j=i+1; j < toy_pos[ box[0].first ].size(); ++j){
                int p2 = toy_pos[ box[0].first ][j];
                for(size_t k=j+1; k < toy_pos[ box[0].first ].size(); ++k){
                    int p3 = toy_pos[ box[0].first ][k];
                    if( p1<=p2 && p2<=p3){
                        long long h=0ll;
                        map<long long, long long> remain;
                        remain[p1] += toy[p1].second;
                        remain[p2] += toy[p2].second;
                        remain[p3] += toy[p3].second;

                        long long bbb = box[0].second;
                        h += min(remain[p1], bbb);
                        remain[p1] = max(remain[p1]-bbb, 0ll);
                        bbb -= (min(remain[p1], bbb));

                        h += min(remain[p2], bbb);
                        remain[p2] = max(remain[p2]-bbb, 0ll);
                        bbb -= (min(remain[p2], bbb));

                        h += min(remain[p3], bbb);
                        remain[p3] = max(remain[p3]-bbb, 0ll);
                        bbb -= (min(remain[p3], bbb));

                        ans = max(h,ans);
                    }
                }
                if(p1<=p2){
                    long long h=0ll;
                    map<long long, long long> remain;
                    long long bbb = box[0].second;
                    remain[p1] += toy[p1].second;
                    remain[p2] += toy[p2].second;

                    h += min(remain[p1], bbb);
                    remain[p1] = max(remain[p1]-bbb, 0ll);
                    bbb -= (min(remain[p1], bbb));

                    h += min(remain[p2], bbb);
                    remain[p2] = max(remain[p2]-bbb, 0ll);
                    bbb -= (min(remain[p2], bbb));
                    ans = max(h,ans);
                }
            }
        }


        for(size_t i=0; i < toy_pos[ box[0].first ].size(); ++i){
            long long how=0ll;
            int p1 = toy_pos[ box[0].first ][i];
            for(size_t j=0; j < toy_pos[ box[2].first ].size(); ++j){
                int p3 = toy_pos[ box[2].first ][j];
                if(p1<=p3){
                    long long h=0ll;
                    map<long long, long long> remain;
                    remain[p1] += toy[p1].second;
                    remain[p3] += toy[p3].second;
                    h += min(remain[p1], box[0].second);
                    remain[p1] = max(remain[p1]-box[0].second, 0ll);
                    h += min(remain[p3], box[2].second);
                    remain[p3] = max(remain[p3]-box[2].second, 0ll);
                    ans = max(h,ans);
                }
            }
        }

        for(size_t i=0; i < toy_pos[ box[1].first ].size(); ++i){
            long long how=0ll;
            int p2 = toy_pos[ box[1].first ][i];
            for(size_t j=0; j < toy_pos[ box[2].first ].size(); ++j){
                int p3 = toy_pos[ box[2].first ][j];
                if(p2<=p3){
                    long long h=0ll;
                    map<long long, long long> remain;
                    remain[p2] += toy[p2].second;
                    remain[p3] += toy[p3].second;
                    h += min(remain[p2], box[1].second);
                    remain[p2] = max(remain[p2]-box[1].second, 0ll);
                    h += min(remain[p3], box[2].second);
                    remain[p3] = max(remain[p3]-box[2].second, 0ll);
                    ans = max(h,ans);
                }
            }
        }

        for(size_t i=0; i < toy_pos[ box[1].first ].size(); ++i){
            long long how=0ll;
            int p2 = toy_pos[ box[1].first ][i];
            for(size_t j=0; j < toy_pos[ box[1].first ].size(); ++j){
                int p3 = toy_pos[ box[1].first ][j];
                if(p2<=p3){
                    long long h=0ll;
                    map<long long, long long> remain;
                    remain[p2] += toy[p2].second;
                    remain[p3] += toy[p3].second;

                    long long bbb=box[1].second;

                    h += min(remain[p2], bbb);
                    remain[p2] = max(remain[p2]-bbb, 0ll);
                    bbb -= (min(remain[p2], bbb));

                    h += min(remain[p3], bbb);
                    remain[p3] = max(remain[p3]-bbb, 0ll);
                    bbb -= (min(remain[p2], bbb));
                    ans = max(h,ans);
                }
            }
        }

        for(size_t i=0; i < toy_pos[ box[2].first ].size(); ++i){
            long long how=0ll;
            int p2 = toy_pos[ box[2].first ][i];
            for(size_t j=0; j < toy_pos[ box[2].first ].size(); ++j){
                int p3 = toy_pos[ box[2].first ][j];
                if(p2<=p3){
                    long long h=0ll;
                    map<long long, long long> remain;
                    remain[p2] += toy[p2].second;
                    remain[p3] += toy[p3].second;

                    long long bbb=box[2].second;

                    h += min(remain[p2], bbb);
                    remain[p2] = max(remain[p2]-bbb, 0ll);
                    bbb -= (min(remain[p2], bbb));

                    h += min(remain[p3], bbb);
                    remain[p3] = max(remain[p3]-bbb, 0ll);
                    bbb -= (min(remain[p2], bbb));
                    ans = max(h,ans);
                }
            }
        }
        fprintf(stderr, "case %d\n", tcase);
        printf("Case #%d: %lld\n", tcase, ans);
    }
    return 0;
}


