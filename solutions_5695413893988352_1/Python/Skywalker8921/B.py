import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def is_better_than(s1,s2):
    if s1 is None:
        return False
    if s2 is None:
        return True
    c1,j1 = map(int,s1)
    c2,j2 = map(int,s2)
    d1 = abs(c1-j1)
    d2 = abs(c2-j2)
    return (d1 < d2
            or ((d1 == d2)
                and ((c1 < c2)
                     or ((c1 == c2) and (j1 < j2)))))
    
def main_small(C,J,tests= "0123456789"):
    #printerr(C,J,tests)
    n1 = C.count("?")
    n2 = J.count("?")
    if n1 + n2 == 0 :
        s = C,J
    else:
        s = None
        for v in tests:
            if n1 > 0:
                CC = C.replace("?",v,1)
                JJ = J
            else:
                CC = C
                JJ = J.replace("?",v,1)
            ss = main_small(CC,JJ,tests=tests)
            if s is None or is_better_than(ss,s):
                s = ss
    #printerr("->",s)
    return s

def main_large_aux(C,J,i,cmp):
    # i is the number of determined previous digits
    # cmp is 1 if the i first digits make C > J, -1 if C < J, 0 if C = J
    printerr(C,J,i,cmp)
    if i == len(C):
        return C,J
    else:
        c,j = C[i],J[i]
        if cmp > 0:
            #printerr("1")
            if c == "?":
                C = C.replace("?","0",1)
            if j == "?":
                J = J.replace("?","9",1)
            return main_large_aux(C,J,i+1,cmp)
        elif cmp < 0:
            #printerr("2")
            if c == "?":
                C = C.replace("?","9",1)
            if j == "?":
                J = J.replace("?","0",1)
            return main_large_aux(C,J,i+1,cmp)
        else:# cmp == 0:
            CC0 = C.replace("?","0",1)
            CC1 = C.replace("?","1",1)
            JJ0 = J.replace("?","0",1)
            JJ1 = J.replace("?","1",1)
            s01 = s10 = s00 = None
            if c == j == "?":
                CC0 = C.replace("?","0",1)
                CC1 = C.replace("?","1",1)
                JJ0 = J.replace("?","0",1)
                JJ1 = J.replace("?","1",1)
                s01 = main_large_aux(CC0,JJ1,i+1,-1)
                s10 = main_large_aux(CC1,JJ0,i+1,1)
                s00 = main_large_aux(CC0,JJ0,i+1,0)
            elif c == "?":
                ji = int(j)
                CC0 = C.replace("?",j,1)
                s00 = main_large_aux(CC0,J,i+1,0)
                if ji < 9:
                    CC1 = C.replace("?",str(ji+1),1)
                    s10 = main_large_aux(CC1,J,i+1,1)
                else:
                    s10 = None
                if ji > 0:
                    CC1 = C.replace("?",str(ji-1),1)
                    s01 = main_large_aux(CC1,J,i+1,-1)
                else:
                    s01 = None
            elif j == "?":
                ci = int(c)
                JJ0 = J.replace("?",c,1)
                s00 = main_large_aux(C,JJ0,i+1,0)
                if ci < 9:
                    JJ1 = J.replace("?",str(ci+1),1)
                    s10 = main_large_aux(C,JJ1,i+1,-1)
                else:
                    s10 = None
                if ci > 0:
                    JJ1 = J.replace("?",str(ci-1),1)
                    s01 = main_large_aux(C,JJ1,i+1,1)
                else:
                    s01 = None
            else:
                if c < j:
                    s00 = main_large_aux(C,J,i+1,-1)
                elif c > j:
                    s00 = main_large_aux(C,J,i+1,1)
                else:
                    s00 = main_large_aux(C,J,i+1,0)
            if is_better_than(s01,s10) :
                if is_better_than(s01,s00):
                    return s01
                else:
                    return s00
            elif is_better_than(s10,s00):
                return s10
            else:
                return s00

def main_large(C,J):
    return main_large_aux(C,J,0,0)
    
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        C,J = input().split()
        ## Processing
        resC,resJ = main_large(C,J)
        
        ## Output
        print("Case #{}: {} {}".format(c+1,resC,resJ))


