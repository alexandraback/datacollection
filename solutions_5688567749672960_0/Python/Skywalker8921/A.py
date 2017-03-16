import sys,math

def swap(N):
    if N % 10 == 0:
        return None
    else:
        l = list(str(N))
        l.reverse()
        sr = ''.join(l)
        Nr = int(sr)
        return Nr

def main_small(N):
    res = 1
    v = N
    while v != 1:
        print(v,file=sys.stderr)
        v1 = swap(v)
        v2 = v-1
        if v1 is None or v2 < v1:
            v = v2
        else:
            v = v1
        res += 1
    return res
        
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        N = int(input())
        ## Processing
        res = main_small(N)
        ## Output
        print("Case #{}: {}".format(c+1,res))


