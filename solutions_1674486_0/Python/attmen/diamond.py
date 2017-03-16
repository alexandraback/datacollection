
def is_diamond(class_links):
    n_class = len(class_links)

    n_path_vec = [0 for i in range(n_class)]

    ##check each node in class
    p_list = []

    for k in range(n_class):
        p_list = parent_list(k, class_links)

        for j in p_list:
            if j > 1:
                return 'Yes'            
        
    return 'No'

def parent_list(node_num, class_links):
    n_path_vec = [0 for i in range(len(class_links))]    
    if (len(class_links[node_num]) == 1):
        return n_path_vec
    else:
        for k in range(1,class_links[node_num][0]+1):
            n_path_vec[class_links[node_num][k]] += 1
            n_path_vec = add_vecs(parent_list(class_links[node_num][k],class_links), n_path_vec)

    return n_path_vec
            
        

def add_vecs(a, b):
    c = [0 for i in range(len(a))]
    for k in range(len(c)):
        c[k] = a[k] + b[k]
    return c
    

f = open('C:\\A-small-attempt0.in')
f_out = open('C:\\res.txt','r+')
j = 0
n = 0
is_full = False
class_links = []
case = 0

for line in f:
    if (j == 0):
        n = int(line)
        j = j + 1
        continue
    if (j == 1):
        n_class = int(line)
        j = j + 1
        continue

    if (is_full):
        n_class = int(line)
            
        class_links = []
        is_full = False
    else:
        class_links.append(line.split())
        if len(class_links) == n_class:
            is_full = True
        
    
    if (is_full):
        case = case + 1
        int_class_links = []
        for k in class_links:
            entry = []
            for m in k:
                if (int(m)!=0):
                    entry.append(int(m)-1)
                else:
                    entry.append(int(m))
            entry[0] += 1
            int_class_links.append(entry)
        print int_class_links, n_class
        out = is_diamond(int_class_links)
        f_out.write("Case #"+str(case)+": "+out+'\n')        

    

##    f_out.write("Case #"+str(j)+": "+str_out+'\n')

    j = j + 1
    print j

f.close()
f_out.close()
