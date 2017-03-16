consonants = [c for c in 'abcdefghijklmnopqrstuvwxyz' if c not in 'aeiou']

def f(name, n):
    mem = {}
    count = 0
    for start in range(len(name)):
        for end in range(start+n, len(name)+1):
            chain = 0
            try:
                count += mem[name[start:end]]
            except KeyError:
                added = 0
                for c in name[start:end]:
                    if c in consonants:
                        chain += 1
                    else:
                        chain = 0
                    if chain >= n:
                        added += 1
                        break
                mem[name[start:end]] = added
                count += added
    return count

N = int(raw_input())
for case in range(1,N+1):
    name, n = raw_input().split()
    print "Case #{}: {}".format(case, f(name, int(n)))