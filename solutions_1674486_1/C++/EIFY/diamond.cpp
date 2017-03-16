#include <iostream>
#include <sstream>

#include <algorithm>
#include <string>
#include <iomanip>

#include <vector>
#include <set>


using namespace std;

bool diamond;

vector<set<int> > inherit;

bool traverse(set<int>& in, set<int>& ancestors)
{
    for (set<int>::iterator it = in.begin(); it != in.end(); ++it)
    {
        if(ancestors.find(*it) != ancestors.end())
            return true;
        else
        {ancestors.insert(*it);}
        
        
        if(traverse(inherit[*it - 1], ancestors)) return true;
        
    }
    
    return false;

}

int main()
{
    int T, N;
    
    cin>>T;
    
    for(int i=0; i<T; ++i)
    {
        
        diamond = false;
    
        cin>>N;
        
        //vector<vector<int> > inherit(N);
        
        inherit.clear();
        inherit.resize(N);


        for(int j=0; j<N; ++j)
        {
            
            int num_parent;
            
            cin>>num_parent;
            
            for (int k=0; k<num_parent; ++k) {
                
                int parent;
                cin>>parent;
                //inherit[j].push_back(parent);
                
                inherit[j].insert(parent);
                
            }
        
        }
        
        
        
        for(int j=0; j<N; ++j)
        {
            set<int> ancestors;// = inherit[j];
            
            if(traverse(inherit[j], ancestors))
            {
                diamond = true;
                break;
            }
            
        }
        
        /*
        vector<set<int> > flat(N);// = inherit;
        
        
        for(int j=0; j<N; ++j)
        {
            for(int k=0; k<N; ++k)
            {
                
                cout<<k<<": ";
                
                for (set<int>::iterator it = inherit[k].begin(); it != inherit[k].end(); ++it) {
                    
                    if(flat[k].find(*it) != flat[k].end())
                    {diamond = true; goto done;}
                    else
                    {flat[k].insert(*it);}
                    
                    
                    int parent = *it - 1;
                    
                    cout<<parent<<' ';
                    
                    for (set<int>::iterator it2 = inherit[parent].begin(); it2 != inherit[parent].end(); ++it2) {
                        
                        cout<<"grandparent: "<<*it2<<endl;
                    
                        if(flat[k].find(*it2) != flat[k].end())
                        {diamond = true; goto done;}
                        else
                        {flat[k].insert(*it2);}
                    
                    }
                    
                    
                }
                
                cout<<endl;
                
                
            }
            
            inherit = flat;
            
            for(int k=0; k<N; ++k)
                flat[k].clear();
            
            
        }
        */
    //done:
    
        if(diamond)
        
            cout<<"Case #"<<i+1<<": Yes"<<endl;
        
        else
            
            cout<<"Case #"<<i+1<<": No"<<endl;
        
        
    }
	return 0;
}
