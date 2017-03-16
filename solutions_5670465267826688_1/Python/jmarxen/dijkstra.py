#dijkstra
    
#map: 1->1, i->2, j->3, k->4
mult_table = [[1,2,3,4],
              [2,-1,4,-3],
              [3,-4,-1,2],
              [4,3,-2,-1]]

def m(x,y):
    s = 1
    if x < 0:
        x = -x
        s = -s
    if y < 0:
        y = -y
        s = -s
    
    return s*mult_table[x-1][y-1]

def sub_prod(s,i,j):
    cur_prod = 1
    for x in s[i:j]:
        cur_prod = m(cur_prod,x)
    return cur_prod

def pow(base, exp):
    #exp = exp%4
    exp = exp & 3
    rv = 1
    for x in range(exp):
        rv = m(rv,base)
    return rv

def prod(s, s_prod, s_per, s_len, i, j):
    
    inst1 = i/s_len
    inst2 = j/s_len
    
    #print "inst1 is "+str(inst1)
    #print "inst2 is "+str(inst2)
    
    between = inst2-inst1-1
    
    #print "between is "+str(between)
    
    if between < 0:
        return sub_prod(s,i%s_len,j%s_len)

    l_val = sub_prod(s,i%s_len,s_len)
    m_val = pow(s_prod,between)
    r_val = sub_prod(s,0,j%s_len)
    return m(m(l_val, m_val), r_val)
    
def can_be_divided(test_case):
    S_len = test_case[0]
    X = test_case[1]
    S = test_case[2]
    tot_len = X*S_len
    
    S_prod = sub_prod(S,0,S_len)

    if pow(S_prod,X) != -1: #product must end up as -1
        return False
    
    S_per = 4
    if S_prod == -1:
        S_per = 2
    
    analysis = S*S_per
    a_len = S_len*S_per
    i_indices = []
    cur_prod = 1
    cur_ind = 0
    while cur_ind < a_len:
        
        cur_prod = m(cur_prod,analysis[cur_ind])
        if cur_prod == 2: #product is i
            i_indices.append(cur_ind+1)
        
        cur_ind+=1
        
    k_indices = []
    cur_prod = 1
    cur_ind = -1
    while cur_ind >= -a_len:
        
        cur_prod = m(analysis[cur_ind],cur_prod)
        if cur_prod == 4: #product is k
            k_indices.append(cur_ind)
        
        cur_ind -= 1
    
    for i_ind in i_indices:
        for k_ind in k_indices:
            if i_ind >= tot_len + k_ind:
                continue
            if prod(S,S_prod,S_per,S_len,i_ind,tot_len + k_ind) == 3: #product is j
                return True
    
    return False

def main():
    num_test_cases = int(raw_input().strip())
    
    test_cases = []
    rnt = range(num_test_cases)
    for n in rnt:
        line = raw_input().strip().split(" ")
        l = int(line[0])
        X = int(line[1])
        
        s = [int(x) for x in raw_input().replace("i","2").replace("j","3").replace("k","4")]
        test_cases.append((l,X,s))
        
    case = 0
    output = []
    while case < num_test_cases:
        co = "Case #"+str(case+1)+": "
        if can_be_divided(test_cases[case]):
            co+="YES"
        else:
            co+="NO"
        output.append(co)
        case+=1
    
    print "\n".join(output)
    
if __name__ == '__main__':
    main()