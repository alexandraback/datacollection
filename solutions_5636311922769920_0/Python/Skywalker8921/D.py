import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def main(K,C,S):
    return list(range(1,K+1))
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        K,C,S = [int(i) for i in input().split()]
        
        ## Processing
        res = main(K,C,S)

        ## Output
        print("Case #{}: {}".format(c+1," ".join([str(i) for i in res])))


