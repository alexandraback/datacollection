def ans(sum1, sum2, ns):
    if len(ns) == 0:
        if sum1 == sum2:
            return ([], [], 0)
        else:
            return ([], [], -1)
    a = ans(sum1+ns[0], sum2, ns[1:])
    if a[2] != -1:
        return (a[0]+[ns[0]], a[1], 0)
    a = ans(sum1, sum2+ns[0], ns[1:])
    if a[2] != -1:
        return (a[0], a[1]+[ns[0]], 0)
    a = ans(sum1, sum2, ns[1:])
    if a[2] != -1:
        return (a[0], a[1], 0)
    return ([], [], -1)

if __name__ == "__main__":
    T = int(raw_input())
    for t in range(1, T+1):
        vals = map(int, raw_input().split())
        N, nums = vals[0], vals[1:]
        print "Case #"+str(t)+":" 
        a = ans(0, 0, nums) 
        if a[2] == -1:
            print "Impossible"
        else:
            for j in a[0]:
                print j,
            print
            for j in a[1]:
                print j,
            print
