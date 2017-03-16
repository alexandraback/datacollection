import sys

def main_small(smax,si):
    st = 0
    res = 0
    for i in range(smax+1):
        ns = int(si[i])
        if st < i:
            res += i - st
            st = i
        print("Shyness {}, {} people standing, {} new friends".format(i,st,res),
              file=sys.stderr)
        st += ns
    return res

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        smaxraw, si = input().split()
        smax = int(smaxraw)
        res = main_small(smax,si)
        #res = main_large(smax,si)
        print("Case #{}: {}".format(c+1,res))


