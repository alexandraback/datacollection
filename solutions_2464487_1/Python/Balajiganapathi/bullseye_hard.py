def main():
    __t = int(raw_input())
    _t = 1
    while _t <= __t:
        inp = raw_input().split()
        r = int(inp[0])
        t = int(inp[1])
        
        lo = 0
        hi = t
        while lo < hi:
            m = (lo + hi + 1) / 2
            if 2 * m * m + (2 * r - 1) * m <= t:
                lo = m
            else:
                hi = m - 1
        
        print "Case #" + str(_t) + ": " + str(lo)
        _t = _t + 1

if __name__ == '__main__':
	main()

