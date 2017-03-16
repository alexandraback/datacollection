pii maxv[MAX<<2];
int a[MAX];
int b[MAX];
LL len[MAX];
LL num[MAX];

void build(int l,int r,int rt){
    if(l==r){
        maxv[rt]=mk(0,0);
        return;
    }
    middle;
    build(lson);
    build(rson);
    maxv[rt]=mk(0,0);
}

pii query(int l,int r,int rt,int L,int R){
    if(R<L) return mk(0,0);
    if(L<=l&&r<=R) return maxv[rt];
    middle;
    if(R<=m) return query(lson,L,R);
    if(L>m) return query(rson,L,R);
    pii p1=query(lson,L,R);
    pii p2=query(rson,L,R);
    if(p1.first==p2.first) return mk(p1.first,(p1.second+p2.second)%mod);
    return max(p1,p2);
}

void update(int l,int r,int rt,int pos,LL len,LL num){
    if(r==l){
        if(maxv[rt].first==len) maxv[rt].second=(maxv[rt].second+num)%mod;
        else maxv[rt]=mk(len,num);
        return ;
    }
    middle;
    if(pos<=m) update(lson,pos,len,num);
    else update(rson,pos,len,num);
    if(maxv[lrt].first==maxv[rrt].first) maxv[rt].second=(maxv[lrt].second+maxv[rrt].second)%mod;
    else maxv[rt]=max(maxv[lrt],maxv[rrt]);
}

int main(){
    //freopen("in.txt","r",stdin);
    int n;
    while(~scanf("%d",&n)){
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
            b[i]=a[i];
        }
        sort(a+1,a+n+1);
        int tot=unique(a+1,a+n+1)-a-1;
        build(1,50000,1);
        LL ans=0;
        for(int i=1;i<=n;i++){
            int pos=lower_bound(a+1,a+tot+1,b[i])-a-1;
            pii p=query(1,50000,1,1,pos);
            len[i]=p.first+1;
            num[i]=p.second==0?1:p.second;
            ans=max(ans,len[i]);
            update(1,50000,1,pos+1,len[i],num[i]);
        }
        LL tmp=0;
        for(int i=1;i<=n;i++){
            if(len[i]==ans) tmp=(tmp+num[i])%mod;
        }
        cout<<tmp<<endl;
    }
    return 0;
}