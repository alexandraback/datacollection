#include"cstdio"
#include"cstdlib"

main ()
{
    FILE *fpr,*fpw;
    fpr = fopen("B-small-attempt5.in","r+");
    fpw = fopen("B-small-attempt5.out","w+");
    int TEST;
    fscanf(fpr,"%d ",&TEST);
    int n;
    for (n=1;n<=TEST;n++)
    {
        fprintf(fpw,"Case #%d: ",n);
        printf("Case #%d: ",n);
        
        int num;
        int i,j,k,l;
        fscanf(fpr,"%d ",&num);
        printf("--%d--\n",num);
        char sLine[100][101];
        int length[100];
        for (i=0,j=0;true;)
        {
            char temp;
            fscanf(fpr,"%c",&temp);
            if (feof(fpr)) {length[i]=j; break;}
            if (temp=='\n'||temp=='\0') {length[i]=j; break;}
            else if (temp==' ') { sLine[i][j]='\0'; length[i]=j; j=0; i++; continue; }
            sLine[i][j]=temp;
            j++;
        }
        long long ans[100]={0};
        bool cantDoIt=false;
        for (i=0;i<num;i++)
        {
            int a,b;
            for (a=0;sLine[i][a]!='\0';a++) if(sLine[i][0]!=sLine[i][a]) break;
            for (b=length[i]-1;b>0;b--) if(sLine[i][length[i]-1]!=sLine[i][b]) break;
            for (j=a;j<=b;j++)
            {
                for (k=0;k<num;k++)
                {
                    if (k==i) continue;
                    for (l=0;sLine[k][l]!='\0';l++)
                    {
                        if (sLine[k][l]==sLine[i][j]) cantDoIt=true;
                        if (cantDoIt) break;
                    }
                    if (cantDoIt) break;
                }
                if (cantDoIt) break;
            }
            if (cantDoIt) break;
        }
        if (cantDoIt) { printf("CANT!!!\n"); fprintf(fpw,"0\n"); continue; }
        int SET=0;
        int check[100]={0};
        int countSet[100]={0};
        int set[100][100];
        for (i=0;i<num;i++) sLine[i][1]=sLine[i][length[i]-1];
        if (true||n==10)
        {
            for (i=0;i<num;i++) printf("%c:%c\n",sLine[i][0],sLine[i][1]);
        }
        int count=0;
        while (true)
        {
            int ch[26]={0};
            for (i=0,j=0;i<num;i++)
            {
                if (check[i]==1);
                else if (j==0 || (ch[sLine[i][0]-'a']==1||ch[sLine[i][1]-'a']==1)) 
                {
                    ch[sLine[i][0]-'a']=1;
                    ch[sLine[i][1]-'a']=1;  
                    check[i]=1; 
                    set[SET][j]=i;
                    i=-1;
                    j++;
                }
            }
            countSet[SET]=j;
            count+=countSet[SET];
            printf("SET %d --> %d\n",SET+1,countSet[SET]);
            if (count==num) break;
            SET++;
        }
        SET++;
        long long anss[100]={0};
        bool impossible=false;
        for (i=0;i<SET;i++)
        {
            char currentHead=sLine[set[i][0]][0];
            char currentTail=sLine[set[i][0]][1];
            anss[i]=1;
            int check[100]={0};
            check[0]=1;
            int count=1;
            while (true)
            {
                for (j=1,k=countSet[i]-count;j<countSet[i];j++)
                {
                    if (check[j]==1) continue;
                    int choice=0;
                    bool atHead=false, atTail=false;
                    if (sLine[set[i][j]][0]==currentTail) { choice++; atTail=true; }
                    if (sLine[set[i][j]][1]==currentHead) { choice++; atHead=true; }
                    if (n==99) printf("%c:%c %c:%c %d\n",currentHead,currentTail,sLine[set[i][j]][0],sLine[set[i][j]][1],choice);
                    if (choice==0) 
                    {
                        k--;
                        if (k==0) { impossible=true; break; }
                        continue;
                    }
                    if (sLine[set[i][j]][0]==currentTail&&sLine[set[i][j]][1]==currentHead&&sLine[set[i][j]][0]!=sLine[set[i][j]][1]) choice=0;
                    anss[i]*=choice;
                    anss[i]%=1000000007;
                    count++;
                    check[j]=1;
                    if (choice>0)
                    {
                        if (atHead) currentHead=sLine[set[i][j]][0];
                        else if (atTail) currentTail=sLine[set[i][j]][1];
                    }
                    break;
                }
                //printf("%d --> %llu\n",count,anss[i]);
                if (impossible) { printf("IMpossibru\n");break;}
                if (count==countSet[i]) break;
            }
            if (impossible) break;
        }
        if (impossible) anss[0]=0;
        long long realAns=anss[0];
        for (i=1;i<SET;i++)
        {
            realAns *= anss[i];
            realAns%=1000000007;
        }
        for (i=1;i<=SET;i++)
        {
            realAns *= i;
            realAns%=1000000007;
        }
        fprintf(fpw,"%llu",realAns);
        
        
        fprintf(fpw,"\n");
    }
    
    printf("YAY!");
    
    scanf(" ");
}
