from collections import defaultdict
import itertools
P = 1000000007

def fact(n):
    r = 1
    for i in range(n):
        r = r * (i +1) % P
    return r
    
def reduce(s):
    if len(set(s)) == 1:
        return s[0]
    else:
        return s
        
def valid(s1, s2):
    c = s1[-1]
    if s2[0] != c:
        return None
    s = s1.rstrip(c) + s2.lstrip(c)
    if c in s:
        return None
    else:
        return s1.rstrip(c) + c + s2.lstrip(c)
           
def valid1(s):
    return valid(s, s[-1])
    
def bruteforce(t, strings):
    ways = 0
    for x in itertools.permutations(strings):
        s = ''.join(x)
        seen = set()
        bad = False
        while s:
            c = s[0]
            if c in seen:
                bad = True
                break
            seen.add(c)
            s = s.lstrip(c)
        if not bad:
            ways += 1
    print 'Case #{0}: {1}'.format(t, ways)
        
       
def small(t, strings):
    ways = 1
    changed = True
    while changed:
        strings = map(reduce, strings)
        #print strings, ways
        changed = False
        freq = defaultdict(int)
        dup_char = None
        for s in strings:
            for c in set(s):
                freq[c] += 1
                if freq[c] > 1:
                    dup_char = c
                    break
        if dup_char:
            changed = True
            connected = []
            mid_count = 0
            rest = []
            for s in strings:
                if s.find(dup_char) != -1:
                    if len(s) == 1:
                        mid_count += 1
                    else:
                        connected.append(s)                    
                else:
                    rest.append(s)
            if len(connected) == 0:
                rest.append(dup_char)
                ways = ways * fact(mid_count) % P
            elif len(connected) == 1:
                rest.append(connected[0])
                ways = ways * fact(mid_count) % P
            elif len(connected) == 2:
                new = valid(connected[0], connected[1])
                if new:
                    rest.append(new)
                else:
                    new = valid(connected[1], connected[0])
                    if new:
                        rest.append(new)
                    else:
                        ways = 0
                        break
                ways = ways * fact(mid_count) % P
            else:
                ways = 0
                break
            strings = rest
    if all(map(valid1, strings)):
        ways = ways * fact(len(strings)) % P
    else:
        ways = 0
    print 'Case #{0}: {1}'.format(t, ways)
 
 
def main():
    T = int(raw_input())
    for t in xrange(1, T + 1):
        _ = int(raw_input())
        strings = raw_input().split()
        #print strings
        small(t, strings)
        #bruteforce(t, strings)
 
 
if __name__ == '__main__':
    main()
