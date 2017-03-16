#include <cstdio>
#include <cstring>
#include <memory.h>

#define MV 100000

using namespace std;

char c[4006];

struct node
{
    node* ch[32];
    char val;
};

node* root;

int dp[4008][5];

int rec(node *curr, int ind, int mustPut, int lastPut, int justCame)
{    
    int best = MV,newMust,newLast,cand;
    
    if ( curr->ch[26] != NULL && !justCame )
    {        
        best = dp[ind + 1][0];
        for ( int i=4; i+lastPut >= 5; i-- )
            if ( best > dp[ind + 1][i] ) best = dp[ind + 1][i];
    }
    
    if ( ind == -1 ) return best;
    
    newMust = 0;
    if ( mustPut ) newMust = mustPut - 1;
    
    if ( curr->ch[ (int)c[ind] - 'a' ] != NULL && mustPut != 1 )
    {
    
        newLast = lastPut + 1;
        if ( newLast > 4 ) newLast = 0;
        if ( lastPut == 0 ) newLast = 0;
     
        cand = rec(curr->ch[ (int)c[ind] - 'a' ], ind - 1, newMust, newLast, 0 );
        if ( cand < best ) best = cand;
    }

    if ( !lastPut && mustPut <= 1 )
    {
        for ( int i=0; i<26; i++ )
        {
            if ( i == (int)c[ind] - 'a' ) continue;
            if ( curr->ch[i] == NULL ) continue;
            
            cand = rec( curr->ch[i], ind - 1, newMust, 1, 0 ); 
            
            if ( cand + 1 < best ) best = cand + 1;
        }
    }
    
    return best;
}

FILE *in;

int main()
{
    node* curr;
    
    in = fopen("dict.txt", "r");
    
    int i,j,k,d;
    root = new node;
    root->val = '^';
    for ( i=0; i<27; i++ ) root->ch[i] = NULL;
    
    for ( i=1; i<=521196; i++ )
    {
        fscanf (in,"%s",c);
        d = strlen(c);
    
        curr = root;
        for ( j=d-1; j>=0; j-- )
        {
            if ( curr->ch[ ( (int)c[j] - 'a' ) ] == NULL )
            {
                curr->ch[ ( (int)c[j] - 'a' ) ] = new node;
                curr = curr->ch[ ( (int)c[j] - 'a' ) ];
                curr->val = c[j];
                for ( k=0; k<27; k++ ) curr->ch[k] = NULL;
            }
            else curr = curr->ch[ ( (int)c[j] - 'a' ) ];
        }
        curr->ch[ 26 ] = new node;
        curr = curr->ch[26];
        curr->val = '$';
        for ( k=0; k<27; k++ ) curr->ch[k] = NULL;
    }
    
    int t,tt,best;
    scanf ("%d",&t);
    for ( tt=1; tt<=t; tt++ )
    {
        best = MV;
        scanf ("%s",c);
        d = strlen(c);
        memset(dp,5,sizeof(dp));
        dp[0][0] = 0;
        
        for ( i=0; i<d; i++ )
            for ( j=0; j<5; j++ )
                dp[i+1][j] = rec(root,i,j,0,1);
            
        best = dp[d][0];
        for ( j=1; j<5; j++ )
            if ( best > dp[d][j] ) best = dp[d][j];
            
        printf ("Case #%d: %d\n",tt,best);
    }
}