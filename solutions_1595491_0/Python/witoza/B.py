def can_be_surprising(s):
    return s >= 2 and s <= 28

def max_surprising(s):
    return 1 + ((s + 1) / 3)

def max_not_surprising(s):
    if s == 0: return 0
    return 1 + ((s - 1) / 3)

def solve_case(N, S, p, t):

    CACHE = {}
    def solve(i, S):
        if i == N: return 0
        
        key = str(i) + "|" + str(S)
        if key in CACHE: return CACHE[key]
        
        P1 = 0
        if can_be_surprising(t[i]) and S > 0:
            P1 = solve(i + 1, S - 1)
            if max_surprising(t[i]) >= p:
                P1 = P1 + 1 
    
        P2 = solve(i + 1, S)
        if max_not_surprising(t[i]) >= p:
            P2 = P2 + 1
        
        CACHE[key] = max(P1, P2)
        return CACHE[key]
    
    return solve(0, S)

IN = open("c:/cj/B-small-attempt0.in", 'r')
OUT = open("c:/cj/B.out", 'w')

T = int(IN.readline().strip())

for case_nbr in xrange(1, T + 1):
    buff = IN.readline().strip().split();
    N = int(buff[0])
    S = int(buff[1])
    p = int(buff[2])
    t = [int(i) for i in buff[3:]]
    res = solve_case(N, S, p, t);
    OUT.write("Case #" + str(case_nbr) + ": " + str(res) + "\n")

IN.close()
OUT.close()

print "done"
    


#def gen_with_sum(s):
#    for a in range(0, 11):
#        for b in range(a, 11):
#            for c in range(b, 11):
#                
#                if abs(a - b) > 2: continue
#                if abs(a - c) > 2: continue
#                if abs(b - c) > 2: continue
#                
#                if a + b + c == s:
#                    print a, b, c
#
#for S in range(0, 31):
#    print "------------- S =", S
#    if can_be_surprising(S):
#        print "max_surprising =", max_surprising(S)
#    print "max_not_surprising =", max_not_surprising(S)
#    
#    gen_with_sum(S)
#    


    


        
