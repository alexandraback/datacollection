def read_int_list():
    l = raw_input().strip().split()
    return map(int, l)

def solve():
    checked = [True] * 2501
    n = input()
    for i in xrange(2*n-1):
        row = read_int_list()
        for h in row:
            if checked[h]: checked[h] = False
            else: checked[h] = True
    missing = list()
    for i in xrange(len(checked)):
        if not checked[i]: missing.append(i)
    return missing

def main():
    i = input()
    for i in xrange(1,i+1):
        l = solve()
        l = map(str,l)
        print "Case #%d: %s" % (i, " ".join(l))

if __name__ == "__main__":
    main()
