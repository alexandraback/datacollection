

def solve(Bs, Ts):
    r = 0
    while Bs and Ts:
        if Bs[1] == Ts[1]:
            d = min(Bs[0], Ts[0])
            r += d
            Bs[0] -= d
            Ts[0] -= d
        else:
            return r + max(
                solve(Bs[2:], Ts[:]),
                solve(Bs[:], Ts[2:])
            )
        if Bs[0] == 0:
            Bs = Bs[2:]
        if Ts[0] == 0:
            Ts = Ts[2:]
    return r



if __name__ == '__main__':
    for i in range(input()):
        raw_input()
        Ts = map(int, raw_input().split())
        Bs = map(int, raw_input().split())
        print 'Case #%s:' % (i+1), solve(Bs, Ts)
    
