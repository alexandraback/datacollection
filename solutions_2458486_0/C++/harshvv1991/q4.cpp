#include<iostream>

using namespace std;

class node
{
public:
    int data;
    node* next;

    node(int k)
    {
        data = k;
        next = NULL;
    }
};

class chest
{

public:
    int unlockKey;
    node *containedKeys;
    bool isOpened;

    chest()
    {
        containedKeys=NULL;
        isOpened = false;
    }

    void addKey(int k)
    {
        node* t = new node(k);
        t->next = containedKeys;
        containedKeys = t;
    }
};

node* st = NULL;
node* e = NULL;
void addState(int k)
{
    node* t = new node(k);

    if(st==NULL)
    {
        st = t;
        e = t;
    }
    else
    {
        e->next = t;
        e = t;
    }
}

bool isSafe(int N, chest ch[], int keys[])
{
    int copy[200];
    bool fin[N];

    for(int i=0; i<N; i++)
    {
        fin[i]=ch[i].isOpened;
    }

    for(int i=0; i<200; i++)
    {
        copy[i]=keys[i];
    }

    for(int i=0; i<N; i++)
    {
        if((fin[i] == false)&&(copy[ch[i].unlockKey-1] > 0))
        {
            fin[i] = true;
            for(node* s=ch[i].containedKeys; s!=NULL; s=s->next)
                copy[(s->data)-1]++;

            i=-1;
        }
    }

    for(int i=0; i<N; i++)
    {
        if(fin[i] == false)
            return false;
    }

    return true;
}

int main()
{
    int t;
    cin>>t;

    int K, N;
    int Ki;
    int temp;

    for(int cas=1; cas<=t; cas++)
    {
        st=e=NULL;

        int keys[200]= {};

        cin>>K>>N;
        for(int i=0; i<K; i++)
        {
            temp;
            cin>>temp;
            keys[temp-1]++;
        }

        chest ch[N];

        for(int i=0; i<N; i++)
        {
            cin>>ch[i].unlockKey;
            cin>>Ki;

            for(int j=0; j<Ki; j++)
            {
                cin>>temp;
                ch[i].addKey(temp);
            }
        }

        for(int i=0; i<N; i++)
        {
            if((ch[i].isOpened == false)&&(keys[ch[i].unlockKey-1] > 0))
            {
                ch[i].isOpened = true;
                for(node* s=ch[i].containedKeys; s!=NULL; s=s->next)
                    keys[(s->data)-1]++;

                keys[ch[i].unlockKey-1]--;

                if(!isSafe(N, ch, keys))
                {
                    ch[i].isOpened = false;
                    for(node* s=ch[i].containedKeys; s!=NULL; s=s->next)
                        keys[(s->data)-1]--;

                    keys[ch[i].unlockKey-1]++;
                }
                else
                {
                    addState(i+1);
                    i=-1;
                }
            }
        }

        bool status = true;
        for(int i=0; i<N; i++)
        {
            if(ch[i].isOpened == false)
            {
                status=false;
                break;
            }
        }

        if(status)
        {
            cout<<"Case #"<<cas<<":";
            for(node* s = st; s!=NULL; s=s->next)
                cout<<" "<<s->data;

            cout<<endl;
        }
        else
            cout<<"Case #"<<cas<<":"<<" IMPOSSIBLE"<<endl;
    }
    return 0;
}

