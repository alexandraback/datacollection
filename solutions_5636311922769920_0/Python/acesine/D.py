# solve small dataset. since S==K, there's always an answer
def solve_small():
    T = int(raw_input())
    for t in range(1, T+1):
        [K, C, S] = [int(x) for x in raw_input().rstrip().split(" ")]
        if K > 1:
            ans = [0]*S
            for i in range(S):
                ans[i] = i * (K**C-1)/(K-1) + 1
        else:
            ans = [1]
        print("Case #%d: %s" % (t, " ".join([str(x) for x in ans])))

if __name__ == '__main__':
    solve_small()
