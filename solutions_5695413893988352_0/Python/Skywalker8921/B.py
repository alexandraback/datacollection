import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def is_better_than(s1,s2):
    c1,j1 = map(int,s1)
    c2,j2 = map(int,s2)
    d1 = abs(c1-j1)
    d2 = abs(c2-j2)
    return (d1 < d2
            or ((d1 == d2)
                and ((c1 < c2)
                     or ((c1 == c2) and (j1 < j2)))))
    
def main_small(C,J):
    n1 = C.count("?")
    n2 = J.count("?")
    if n1 + n2 == 0 :
        return C,J
    else:
        s = None
        for v in "0123456789":
            if n1 > 0:
                CC = C.replace("?",v,1)
                JJ = J
            else:
                CC = C
                JJ = J.replace("?",v,1)
            ss = main_small(CC,JJ)
            if s is None or is_better_than(ss,s):
                s = ss
    return s

    
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        C,J = input().split()
        ## Processing
        resC,resJ = main_small(C,J)
        
        ## Output
        print("Case #{}: {} {}".format(c+1,resC,resJ))


