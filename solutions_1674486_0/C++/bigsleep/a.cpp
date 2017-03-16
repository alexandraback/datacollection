#include <iostream>
#include <vector>
#include <algorithm>

struct node
{
    int n;
    std::vector<node*> base;
};

void disp(std::vector<node*> const& a)
{
    for(int i = 0, sz = a.size(); i < sz; ++i){
        std::cout << a[i]->n << " ";
    }
    std::cout << std::endl;
}

int main()
{
    int T = 0, N = 0;
    std::cin >> T;
    
    for(int i = 0; i < T; ++i){
        std::cin >> N;
        
        std::vector<node> classes(N);
        
        for(int j = 0; j < N; ++j){
            classes[j].n = j;
            int M = 0;
            std::cin >> M;
            
            for(int k = 0; k < M; ++k){
                int C = 0;
                std::cin >> C;
                classes[j].base.push_back(&classes[C - 1]);
            }
        }
        
        std::vector<bool> used(N, false);
        
        std::vector<node*> nodes, q;
        nodes.reserve(1000);
        q.reserve(1000);
        
        bool found = false;
        for(int j = 0; j < N; ++j){
            if(!used[j]){
                q.clear();
                q.push_back(&classes[j]);
                nodes.clear();
                nodes.push_back(&classes[j]);
                while(!q.empty()){
                    node* x = q.back();
                    q.pop_back();
                    used[x->n] = true;
                    
                    q.insert(q.end(), x->base.begin(), x->base.end());
                    nodes.insert(nodes.end(), x->base.begin(), x->base.end());
                }
                //disp(nodes);
                std::sort(nodes.begin(), nodes.end());
                auto nend = std::unique(nodes.begin(), nodes.end());
                
                if(nend != nodes.end()){
                    std::cout << "Case #" << i + 1 << ": Yes" << std::endl;
                    found = true;
                    break;
                }
            }
        }
        if(!found) std::cout << "Case #" << i + 1 << ": No" << std::endl;
    }
}
















