def farcitiles(k, c, s):
    if s < k / c:
        return []
        
    tiles = list(range(0,k))
    parts = part(tiles, c)
    locs = [find_loc(l, k) for l in parts]
    assert max(locs) < k ** c, "out of bounds"
    return locs
    
def part(L, size):
    r = 1 if len(L) % size else 0
    par = len(L) // size + r
    
    par_L = [L[k*size:(k+1)*size] for k in range(par)]
    par_L[-1] = (par_L[-1]*size)[:size]
    return par_L
    
def find_loc(L, k):
    loc = 0
    for c,l in enumerate(L):
        loc += int((k ** c) * l)
    return loc
    
def main():
    T = int(input())
    for t in range(1,T + 1):
        K, C, S = [int(x) for x in input().split(" ")]
        res = farcitiles(K, C, S)
        printable_res = "IMPOSSIBLE" if not res else " ".join([str(x+1) for x in res])
        print("Case #%d: %s" % (t, printable_res))
    
if __name__ == "__main__":
    main()