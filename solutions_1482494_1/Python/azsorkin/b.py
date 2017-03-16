#! /usr/bin/env python3

##########
## Adam Sorkin
## google codejam round one-a. 
## 27 Apr 2012
##########

bound = float('inf')  

def main():
    "             "

    T = int(input()) # number of test cases
    for i in range(1, T+1):
        N = int(input() )
        AB = [ list(map(int, input().split() ) ) for _ in range(N) ]
        result = foo(AB,N)

        print("Case #{0}: {1}".format(i, result) )
        
    return


def foo(AB,N):
    A = [ AB[j][0] for j in range(N )]
    B = [ AB[j][1] for j in range(N )]
    stars = levels = 0
    while A or B:
        if stars >= min(B):
            #print("doing a b-type level")
            levels += 1
            i = B.index(min(B))
            if A[i] == bound:
                stars += 1
            else:
                stars += 2
            A.pop(i)
            B.pop(i)
        elif stars >= min(A):
            #print("doing an a-type level")
            indices = [ j for j,k in enumerate(A) if k <=stars ]
            choice = max( [ (B[j], j) for j in indices ] )
            #print("Index",choice[1],"with A,B values",A[choice[1]], B[choice[1]])
            A[choice[1]] = bound
            stars += 1
            levels += 1
        else:
            return "Too Bad"

    return levels

if __name__ == "__main__":
    main()
