T = int(raw_input())

for case in range(T):
    A, B = [int(i) for i in raw_input().split()]
    p_i = [float(i) for i in raw_input().split()]
    prob = []
    for i in range(2**A):
        p = 1
        for j in range(A-1, -1, -1):
            #print i, j
            p *= i & (1 << j) and p_i[A-j-1] or 1 - p_i[A-j-1]
        prob.append(p)
        #print i, j, p
    #print prob
    ex = []
    keep_typing = [2*B+2-A]*(2**A-1) + [B-A+1]
    ex.append(sum([prob[i] * keep_typing[i] for i in range(2**A)]))
    ex.append(sum([prob[i] * ([B+2]*2**A)[i] for i in range(2**A)]))
    for i in range(1, A+1):
        bk = 0
        for j in range(2**A):
            bk += (((j >> i) == 2**(A-i)-1) and i+i+B+1-A or i+i+B+B+1+1-A) * prob[j]
        ex.append(bk)
    #print ex
    print "Case #{0}: {1:.6f}".format(case+1, round(min(ex), 6))
    #print A, B, p_i
