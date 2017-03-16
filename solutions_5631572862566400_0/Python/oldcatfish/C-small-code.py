
# coding: utf-8

# In[29]:

def bffs(s):
    n = len(s);
    visited = [0] * n;
    tmp = [x-1 for x in s];
    s = tmp;
    max_circle = 0;
    for i in range(n):
        if visited[i]:
            continue;
        cur_set = set();
        while i not in cur_set:
            cur_set.add(i);
            visited[i] = 1;
            i = s[i];
        target = i;
        cnt = 1;
        while s[i] != target:
            cnt += 1;
            i = s[i];
        max_circle = max(max_circle, cnt);
    # reverse 
    s_rev = dict();
    for i in range(n):
        s_rev[i] = [];
    for i in range(n):
        s_rev[s[i]] += [i];
    
    # find all the pairs
    pairs = [];
    for i in range(n):
        if s[s[i]] == i:
            pairs.append((i, s[i]));
    #print(pairs)
    
    for pair in pairs:
        cur_set = set();
        i = pair[0];
        cur_set.add(s[i]);
        
        cnt_1 = get_longest_chain(s_rev, i, cur_set);
        
        i = pair[1];
        cur_set = set();
        cur_set.add(s[i]);
        
        cnt_2 = get_longest_chain(s_rev, i, cur_set);
        
        cnt = cnt_1 + cnt_2;
        #print(cnt)
        max_circle = max(max_circle, cnt);
    return(max_circle);
        
def get_longest_chain(s, cur_node, the_set):
    # get the longest chain
    if cur_node in the_set:
        return(0);
    max_len = 0;
    new_set = set(the_set);
    new_set.add(cur_node);
    if not s[cur_node]:
        return(1);
    for node in s[cur_node]:
        max_len = max(max_len, 1 + get_longest_chain(s, node, new_set));
    # the_set.remove(cur_node);
    return(max_len)

        
    
    
    
            

fin_name = 'C-small-attempt0.in';
fout_name = 'C-small-attempt0.out';

fout = open(fout_name, 'w');
with open(fin_name, 'r') as fin:
    T = int(next(fin));
    for case in range(1, 1+T):
        N = int(next(fin));
        s = list(map(int, next(fin).strip().split()));
        out = bffs(s);
        line = 'Case #{0}: {1}\n'.format(str(case), str(out));
        fout.write(line);
fout.close();
            


# In[ ]:



