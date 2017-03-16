
s = 0

def func(n):
    return 2 * n * n - 2 * n + n * s
    
def search(a, b, num):
    if b - a < 2:
        return a
    mid = int((a + b) / 2)
#    print "%s %s mid = %s" % (a, b, mid)
#    print func(mid)
    if func(mid) < num:
        return search(mid, b, num)
    elif func(mid) > num:
        return search(a, mid, num)
    else:
        return mid

if __name__ == "__main__":
    input = raw_input()
    num = int(input.split()[0])
    for i in range(num):
        input = raw_input()
        raw = [item for item in input.split()]
        r, t = int(raw[0]), int(raw[1])
        s = 2 * r + 1
        res = search(1, 1e18, t)
        print "Case #%d: %d" % (i + 1, res)

