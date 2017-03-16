import sys,math

def printerr(*a,**b):
    print(*a,file=sys.stderr,**b)

def main(N):
    if (N == 0):
        return "INSOMNIA"
    else:
        seen = set({})
        val = 0
        while len(seen) < 10:
            val += N
            new = set("{}".format(val))
            seen.update(new)
            printerr(val,seen)
        return val

if __name__ == "__main__":
    T = int(input())
    for c in range(T):
        ## Input
        N = int(input())

        ## Processing
        res = main(N)

        ## Output
        print("Case #{}: {}".format(c+1,res))


