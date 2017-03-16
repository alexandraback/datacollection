def pairs(num, lo, hi):
    if num < lo or num > hi:
        return []

    strnum = str(num)
    ndigit = len(strnum)
    result = set()
    for i in range(ndigit):
        new = int(strnum[i:] + strnum[:i])
        if num >= new: continue
        if new < lo or new > hi: continue
        if len(str(new)) == ndigit:
            result.add( (num, new))
    return result

def all_pairs(lo, hi):
    result = set()
    for i in range(lo, hi+1):
        for pair in pairs(i, lo, hi):
            result.add(pair)
    return result

def answer(a, b):
    return len(all_pairs(a, b))

def main():
    import sys
    data = open(sys.argv[1]+'.in').readlines()
    out = open(sys.argv[1]+'.out', 'w')
    for i, line in enumerate(data[1:]):
        a,b = map(int, line.strip().split())
        response = "Case #%i: %s" % (i+1, answer(a,b))
        print response
        out.write(response + '\n')
    out.close()

main()
