import sys

def minus(a):
    if a[0] == "-":
        return a[1:]
    else:
        return "-" + a;

def prod(a,b):
    if a[0] == "-":
        return minus(prod(minus(a),b))
    elif a == "1":
        return b
    elif a == b:
        return "-1"
    elif a > b:
        return minus(prod(b,a))
    elif a == "i":
        if b == "j":
            return "k"
        else: # b == "k":
            return "-j"
    else: # a == "j" and b == "k"
        return "i"

def repeat(l,n):
    res=""
    for _ in range(n):
        res += l
    return res
    
def main_small(L,X,str):
    lstr = repeat(str,X)
    targets = ["i","j","k"]
    curtgt = 0
    tmpprod = "1"
    idx = [0,0,0]
    for i in range(L*X):
        tmpprod = prod(tmpprod,lstr[i])
        if curtgt < 3 and tmpprod == targets[curtgt]:
            print("Found {} : take chars up to {}".format(targets[curtgt],i),
                  file=sys.stderr)
            idx[curtgt] = i
            curtgt += 1
            tmpprod = "1"
    return (curtgt == 3 and tmpprod == "1"), idx
            
def main_large(L,X,str):
    if X <= 8:
        return main_small(L,X,str)
    else:
        _,idx = main_small(L,4,str)
        n = (idx[0] // L) +1
        r = (X - n) % 4
        return main_small(L,n+r+4,str)
    
if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        L,X = [int(i) for i in input().split()]
        str = input()
        #res,_ = main_small(L,X,str)
        res,_ = main_large(L,X,str)
        if res:
            resprt = "YES"
        else:
            resprt = "NO"
        print("Case #{}: {}".format(c+1,resprt))
